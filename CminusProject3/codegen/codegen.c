#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <util/string_utils.h>
#include <util/symtab.h>
#include <util/dlink.h>
#include "reg.h"
#include "codegen.h"
#include "symfields.h"
#include "types.h"

extern int globalOffset;

/**
 * Print a data declaration to stdout. This function is called by dlinkApply only.
 *
 * @param decl a DNode containing a data declaration
 */
static void printDataDeclaration(DNode decl) {
	printf("%s\n",(char*)dlinkNodeAtom(decl));
}

/**
 * Emit the assembly prologue for a procedure
 */
void emitProcedurePrologue(DList instList,SymTable symtab, int index) {

	char *name = (char*)SymGetFieldByIndex(symtab,index,SYM_NAME_FIELD); 

	char* inst = nssave(2,"\t.globl ",name);
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	inst = nssave(3,"\t.type ",name,",@function");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	inst = nssave(2,name,":\tnop");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	inst = ssave("\tpushq %rbp");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	inst = ssave("\tmovq %rsp, %rbp");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
}

/**
 * Print the assembly prologue that includes the data section, a declaration of main and an allocation of stack space
 * for the main routine.
 *
 * @param dataList a list of data declarations (strings and floats)
 * @param frameSize The number of bytes need for local variables declared in main
 */
void emitDataPrologue(DList dataList) {

	printf("\t.section\t.rodata\n");
	printf("\t.int_wformat: .string \"%%d\\n\"\n");
	printf("\t.str_wformat: .string \"%%s\\n\"\n");
	printf("\t.int_rformat: .string \"%%d\"\n");
	if (globalOffset != 0)
		printf("\t.comm _gp, %d, 4\n",globalOffset);  // extra bytes to avoid 0 offset
		                                                // offset < 0 local, >= 0 global
	dlinkApply(dataList,(DLinkApplyFunc)printDataDeclaration);
	printf("\t.text\n");
}

/**
 * Print an assembly instruction to stdout. This function is only called by dlinkApply.
 *
 * @param inst a DNode containing an assembly instruction.
 */
static void printInstruction(DNode inst) {
	printf("%s\n",(char*)dlinkNodeAtom(inst));
}

/**
 * Print all of the assembly instructions for the main routine to stdout.
 *
 * @param instList a DList of assembly instructions.
 */
void emitInstructions(DList instList) {

	dlinkApply(instList,(DLinkApplyFunc)printInstruction);
}


void emitExit(DList instList) {

  /*char *inst = ssave("\tmov dword ptr [%esp], 0");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	inst = ssave("\tcall exit");
	dlinkAppend(instList,dlinkNodeAlloc(inst));*/

  char *inst = ssave("\tleave");
  dlinkAppend(instList,dlinkNodeAlloc(inst));
  inst = ssave("\tret");
  dlinkAppend(instList,dlinkNodeAlloc(inst));
}

/**
 * Add an instruction that performance an assignment.
 *
 * @param instList a DList of assembly instructions
 * @param symtab a symbol table
 * @param lhsRegIndex the symbol table index of the register for the l-value address
 * @param rhsRegIndex the symbol table index of the register for the r-value
 */
void emitAssignment(DList instList,SymTable symtab,int lhsRegIndex, int rhsRegIndex) {
	char *inst;
	
	 inst = nssave(5,  "\tmovl ", (char*)SymGetFieldByIndex(symtab,rhsRegIndex,SYM_NAME_FIELD),
			", (", get64bitIntegerRegisterName(symtab, lhsRegIndex), ")");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	freeIntegerRegister((int)SymGetFieldByIndex(symtab,rhsRegIndex,SYMTAB_REGISTER_INDEX_FIELD));
	freeIntegerRegister((int)SymGetFieldByIndex(symtab,lhsRegIndex,SYMTAB_REGISTER_INDEX_FIELD));
}

/**
 * Add the instructions needed to read a variable using the read system call.
 *
 * @param instList a DList of instructions
 * @param symtab a symbol table
 * @param addrIndex the symbol table index of the register holding the address that is to be read into
 */
void emitReadVariable(DList instList, SymTable symtab, int addrIndex) {
        char *inst;

	inst = nssave(3,"\tmovq ", get64bitIntegerRegisterName(symtab, addrIndex), ", %rsi");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	inst = nssave(3,"\tmovl $", READ_INTEGER_FMT, ", %edi");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	inst = ssave("\tmovl $0, %eax");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	inst = ssave("\tcall scanf");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	freeIntegerRegister((int)SymGetFieldByIndex(symtab,addrIndex,SYMTAB_REGISTER_INDEX_FIELD));
}


/**
 * Add the instructions needed to write a value using the print system call.
 *
 * @param instList a Dlist of instructions
 * @param symtab a symbol table
 * @param regIndex the symbol table index of the register to be printed (must be addres if string)
 * @param syscallService the system call print service to use (format string for x86)
 */
void emitWriteExpression(DList instList,SymTable symtab, int regIndex, char *syscallService) {
	char *inst;
	
	inst = nssave(3,"\tmovl ", (char*)SymGetFieldByIndex(symtab,regIndex,SYM_NAME_FIELD), ", %esi");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	freeIntegerRegister((int)SymGetFieldByIndex(symtab,regIndex,SYMTAB_REGISTER_INDEX_FIELD));
	inst = nssave(3, "\tmovl $",syscallService, ", %edi");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	inst = ssave("\tmovl $0, %eax");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	inst = ssave("\tcall printf");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
}

/**
 * Add an instruction that performs a binary computation.
 *
 * @param instList a DList of instructions
 * @param symtab a symbol table
 * @param leftOperand the symbol table index of the register holding the left operand
 * @param rightOperand the symbol table index of the register holding the right operand
 * @param opcode the opcode of the mips assembly instruction
 * @return
 */
static int emitBinaryExpression(DList instList, SymTable symtab, int leftOperand, int rightOperand, char* opcode) {
	char* leftName = (char*)SymGetFieldByIndex(symtab,leftOperand,SYM_NAME_FIELD);
	char* rightName = (char*)SymGetFieldByIndex(symtab,rightOperand,SYM_NAME_FIELD);

	char* inst = nssave(6,"\t",opcode," ", rightName,", ",leftName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	freeIntegerRegister((int)SymGetFieldByIndex(symtab,rightOperand,SYMTAB_REGISTER_INDEX_FIELD));
	return leftOperand;
}

/**
 * Add an or instruction.
 *
 * @param instList a DList of instructions
 * @param symtab a symbol table
 * @param leftOperand the symbol table index of the register holding the left operand
 * @param rightOperand the symbol table index of the register holding the right operand
 * @return the symbol table index for the result register
 */
int emitOrExpression(DList instList, SymTable symtab, int leftOperand, int rightOperand) {
	return emitBinaryExpression(instList,symtab,leftOperand,rightOperand,"orl");
}

/**
 * Add an and instruction.
 *
 * @param instList a DList of instructions
 * @param symtab a symbol table
 * @param leftOperand the symbol table index of the register holding the left operand
 * @param rightOperand the symbol table index of the register holding the right operand
 * @return the symbol table index for the result register
 */
int emitAndExpression(DList instList, SymTable symtab, int leftOperand, int rightOperand) {
	return emitBinaryExpression(instList,symtab,leftOperand,rightOperand,"andl");
}

/**
 * Add a not instruction.
 *
 * @param instList a DList of instructions
 * @param symtab a symbol table
 * @param operand the symbol table index of the register holding the operand
 * @return the symbol table index for the result register
 */
int emitNotExpression(DList instList, SymTable symtab, int operand) {
	char* opName = (char*)SymGetFieldByIndex(symtab,operand,SYM_NAME_FIELD);

	char* inst = nssave(2, "\txorl $1, ", opName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	return operand;
}

static int emitBinaryCompareExpression(DList instList, SymTable symtab, int leftOperand, int rightOperand,
				       char *opcode) {

	leftOperand = emitBinaryExpression(instList,symtab,leftOperand,rightOperand,"cmpl");
	freeIntegerRegister((int)SymGetFieldByIndex(symtab,rightOperand,SYMTAB_REGISTER_INDEX_FIELD));

	char *inst = nssave(2,"\tmovl $0, ", (char*)SymGetFieldByIndex(symtab,leftOperand,SYM_NAME_FIELD));
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	int tregIndex = getFreeIntegerRegisterIndex(symtab);

	inst = nssave(2,"\tmovl $1, ",(char*)SymGetFieldByIndex(symtab,tregIndex,SYM_NAME_FIELD));
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	return emitBinaryExpression(instList,symtab,leftOperand,tregIndex,opcode);
}

/**
 * Add an equal instruction.
 *
 * @param instList a DList of instructions
 * @param symtab a symbol table
 * @param leftOperand the symbol table index of the register holding the left operand
 * @param rightOperand the symbol table index of the register holding the right operand
 * @return the symbol table index for the result register
 */
int emitEqualExpression(DList instList, SymTable symtab, int leftOperand, int rightOperand) {
    return emitBinaryCompareExpression(instList,symtab,leftOperand,rightOperand,"cmove");
}
/**
 * Add a not-equal instruction.
 *
 * @param instList a DList of instructions
 * @param symtab a symbol table
 * @param leftOperand the symbol table index of the register holding the left operand
 * @param rightOperand the symbol table index of the register holding the right operand
 * @return the symbol table index for the result register
 */

int emitNotEqualExpression(DList instList, SymTable symtab, int leftOperand, int rightOperand) {
  return emitBinaryCompareExpression(instList,symtab,leftOperand,rightOperand,"cmovne");
}

/**
 * Add an less-or-equal instruction.
 *
 * @param instList a DList of instructions
 * @param symtab a symbol table
 * @param leftOperand the symbol table index of the register holding the left operand
 * @param rightOperand the symbol table index of the register holding the right operand
 * @return the symbol table index for the result register
 */
int emitLessEqualExpression(DList instList, SymTable symtab, int leftOperand, int rightOperand) {
  return emitBinaryCompareExpression(instList,symtab,leftOperand,rightOperand,"cmovle");
}

/**
 * Add a less-than instruction.
 *
 * @param instList a DList of instructions
 * @param symtab a symbol table
 * @param leftOperand the symbol table index of the register holding the left operand
 * @param rightOperand the symbol table index of the register holding the right operand
 * @return the symbol table index for the result register
 */
int emitLessThanExpression(DList instList, SymTable symtab, int leftOperand, int rightOperand) {
  return emitBinaryCompareExpression(instList,symtab,leftOperand,rightOperand,"cmovl");
}

/**
 * Add a greater-equal instruction.
 *
 * @param instList a DList of instructions
 * @param symtab a symbol table
 * @param leftOperand the symbol table index of the register holding the left operand
 * @param rightOperand the symbol table index of the register holding the right operand
 * @return the symbol table index for the result register
 */
int emitGreaterEqualExpression(DList instList, SymTable symtab, int leftOperand, int rightOperand) {
  return emitBinaryCompareExpression(instList,symtab,leftOperand,rightOperand,"cmovge");
}

/**
 * Add a greater-than instruction.
 *
 * @param instList a DList of instructions
 * @param symtab a symbol table
 * @param leftOperand the symbol table index of the register holding the left operand
 * @param rightOperand the symbol table index of the register holding the right operand
 * @return the symbol table index for the result register
 */
int emitGreaterThanExpression(DList instList, SymTable symtab, int leftOperand, int rightOperand) {
  return emitBinaryCompareExpression(instList,symtab,leftOperand,rightOperand,"cmovg");
}


/**
 * Add an add instruction.
 *
 * @param instList a DList of instructions
 * @param symtab a symbol table
 * @param leftOperand the symbol table index of the register holding the left operand
 * @param rightOperand the symbol table index of the register holding the right operand
 * @return the symbol table index for the result register
 */
int emitAddExpression(DList instList, SymTable symtab, int leftOperand, int rightOperand) {
	return emitBinaryExpression(instList,symtab,leftOperand,rightOperand,"addl");
}

/**
 * Add a subtract instruction.
 *
 * @param instList a DList of instructions
 * @param symtab a symbol table
 * @param leftOperand the symbol table index of the register holding the left operand
 * @param rightOperand the symbol table index of the register holding the right operand
 * @return the symbol table index for the result register
 */
int emitSubtractExpression(DList instList, SymTable symtab, int leftOperand, int rightOperand) {
	return emitBinaryExpression(instList,symtab,leftOperand,rightOperand,"subl");
}

/**
 * Add a multiply instruction.
 *
 * @param instList a DList of instructions
 * @param symtab a symbol table
 * @param leftOperand the symbol table index of the register holding the left operand
 * @param rightOperand the symbol table index of the register holding the right operand
 * @return the symbol table index for the result register
 */
int emitMultiplyExpression(DList instList, SymTable symtab, int leftOperand, int rightOperand) {
	return emitBinaryExpression(instList,symtab,leftOperand,rightOperand,"imull");
}

/**
 * Add a divide instruction.
 *
 * @param instList a DList of instructions
 * @param symtab a symbol table
 * @param leftOperand the symbol table index of the register holding the left operand
 * @param rightOperand the symbol table index of the register holding the right operand
 * @return the symbol table index for the result register
 */
int emitDivideExpression(DList instList, SymTable symtab, int leftOperand, int rightOperand) {
		int leftReg = (int)SymGetFieldByIndex(symtab,leftOperand,SYMTAB_REGISTER_INDEX_FIELD);
		int rightReg = (int)SymGetFieldByIndex(symtab,rightOperand,SYMTAB_REGISTER_INDEX_FIELD);
		char *inst;
	
	        inst = nssave(3,"\tmovl ",(char*)SymGetFieldByIndex(symtab,leftOperand,SYM_NAME_FIELD), ", %eax");
	        dlinkAppend(instList,dlinkNodeAlloc(inst));


		inst = ssave("\tcdq");
		dlinkAppend(instList,dlinkNodeAlloc(inst));

		inst = nssave(2,"\tidivl ",(char*)SymGetFieldByIndex(symtab,rightOperand,SYM_NAME_FIELD));
		dlinkAppend(instList,dlinkNodeAlloc(inst));

	        inst = nssave(2,"\tmovl %eax, ", (char *)SymGetFieldByIndex(symtab, leftOperand, SYM_NAME_FIELD)); 
		dlinkAppend(instList,dlinkNodeAlloc(inst));


	        freeIntegerRegister(rightReg);

		return leftOperand;
}

/**
 * Add an instruction to compute the address of a variable.
 *
 * @param instList a Dlist of instructions
 * @param symtab a symbol table
 * @param varIndex the symbol table index for a variable
 * @return the symbol table index of the result register
 */
int emitComputeVariableAddress(DList instList, SymTable symtab, int varIndex) {
	

	int regIndex = getFreeIntegerRegisterIndex(symtab);
	
	char* regName = (char*)get64bitIntegerRegisterName(symtab, regIndex);

	int offset = (int)SymGetFieldByIndex(symtab,varIndex,SYMTAB_OFFSET_FIELD);
	char offsetStr[10];
	char *inst; 

	snprintf(offsetStr,9,"%d",offset);

        inst = nssave(2,"\tmovq $_gp,", regName);

	dlinkAppend(instList,dlinkNodeAlloc(inst));
	inst = nssave(4,"\taddq $", offsetStr, ", ", regName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	return regIndex;

}

/**
 * Add an instruction to load a variable from memory.
 *
 * @param instList a Dlist of instructions
 * @param symtab a symbol table
 * @param regIndex the symbol table index for the address of a variable
 * @return the symbol table index of the result register
 */
int emitLoadVariable(DList instList, SymTable symtab, int regIndex) {

	int newRegIndex = getFreeIntegerRegisterIndex(symtab);

	char* newRegName = (char*)SymGetFieldByIndex(symtab,newRegIndex,SYM_NAME_FIELD);

	char* regName = (char*) get64bitIntegerRegisterName(symtab, regIndex);

	char *inst;
	
	inst = nssave(4,"\tmovl (",regName,"), ", newRegName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	freeIntegerRegister((int)SymGetFieldByIndex(symtab,regIndex,SYMTAB_REGISTER_INDEX_FIELD));

	return newRegIndex;

}

/**
 * Add an instruction to load an integer constant
 *
 * @param instList a Dlist of instructions
 * @param symtab a symbol table
 * @param intIndex the symbol table index for an integer constant
 * @return the symbol table index of the result register
 */
int emitLoadIntegerConstant(DList instList, SymTable symtab, int intIndex) {
	int regIndex = getFreeIntegerRegisterIndex(symtab);
	char* regName = (char*)SymGetFieldByIndex(symtab,regIndex,SYM_NAME_FIELD);
	
	char *intName = SymGetFieldByIndex(symtab,intIndex,SYM_NAME_FIELD);

	char *inst = nssave(4,"\tmovl $", intName, ", ", regName);

	dlinkAppend(instList,dlinkNodeAlloc(inst));

	return regIndex;

}

/**
 * Add a .asciiz declaration for a string constant.
 *
 * @param dataList a DList of data declarations
 * @param symtab a symbol table
 * @param stringIndex the symbol table index of a string constant
 * @return
 */
static char* makeDataDeclaration(DList dataList, SymTable symtab, int stringIndex) {
	static int stringNum = 0;
	char* string = (char*)SymGetFieldByIndex(symtab,stringIndex,SYM_NAME_FIELD);
	char* strLabel = (char*)malloc(sizeof(char)*15);

	snprintf(strLabel,15,".string_const%d",stringNum++);

	char* strChars = substr(string,1,strlen(string)-2); /**< the string constant w/o quotes */
	char* decl = nssave(4,strLabel,": .string \"",strChars,"\"");
	dlinkAppend(dataList,dlinkNodeAlloc(decl));

	free(strChars);

	return strLabel;
}

/**
 * Add an instruction to load the address of a string constant
 *
 * @param instList a Dlist of instructions
 * @param dataList a Dlist of data declarations
 * @param symtab a symbol table
 * @param stringIndex the symbol table index for a string constant
 * @return the symbol table index of the result register
 */
int emitLoadStringConstantAddress(DList instList, DList dataList, SymTable symtab, int stringIndex) {
	char *strLabel = makeDataDeclaration(dataList,symtab,stringIndex);

	int regIndex = getFreeIntegerRegisterIndex(symtab);
	char* regName = (char*)SymGetFieldByIndex(symtab,regIndex,SYM_NAME_FIELD);

	char* inst = nssave(4,"\tmovl $", strLabel, ", ", regName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	free(strLabel);

	return regIndex;
}

/**
 * Add an identifier to the symbol table and store its offset 
 * This function is called by dlinkApply1.
 *
 * @param node a node on a linked list containing the symbol table index of a variable
 * 		  delcared in a program
 * @param data a structure containing the symbol table index of the type of the variable,
 * 		  the symbol table, and the current offset in the activation record.
 */
void addIdToSymtab(DNode node, AddIdStructPtr data) {

	int symIndex = (int)dlinkNodeAtom(node);
	int size = 4;

        SymPutFieldByIndex(data->symtab,symIndex,SYMTAB_OFFSET_FIELD,(Generic)(data->offset));
        //data->offset += size;
	data->offset += (int)SymGetFieldByIndex(data->symtab, symIndex, SYMTAB_SIZE_FIELD); //need to get actual size not just assume int 4
}

