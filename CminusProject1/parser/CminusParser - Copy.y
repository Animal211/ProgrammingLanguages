/*******************************************************/
/*                     Cminus Parser                   */
/*                                                     */
/*******************************************************/

/*********************DEFINITIONS***********************/
%{
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <util/general.h>
#include <util/symtab.h>
#include <util/symtab_stack.h>
#include <util/dlink.h>
#include <util/string_utils.h>

#define SYMTABLE_SIZE 100

/*********************EXTERNAL DECLARATIONS***********************/

EXTERN(void,Cminus_error,(const char*));

EXTERN(int,Cminus_lex,(void));

//create a symbol table
SymTable symtab;

#define SYMTAB_VALUE_FIELD "value" //The next line gives a name to the "value" field

char *fileName;

extern int Cminus_lineno;

extern FILE *Cminus_in;
%}

%name-prefix="Cminus_"
%defines

%start Program

%token AND
%token ELSE
%token EXIT
%token FOR
%token IF 		
%token INTEGER 
%token NOT 		
%token OR 		
%token READ
%token WHILE
%token WRITE
%token LBRACE
%token RBRACE
%token LE
%token LT
%token GE
%token GT
%token EQ
%token NE
%token ASSIGN
%token COMMA
%token SEMICOLON
%token LBRACKET
%token RBRACKET
%token LPAREN
%token RPAREN
%token PLUS
%token TIMES
%token IDENTIFIER
%token DIVIDE
%token RETURN
%token STRING	
%token INTCON
%token MINUS

%left OR
%left AND
%left NOT
%left LT LE GT GE NE EQ
%left PLUS MINUS
%left TIMES DIVDE

%type <index> Variable
%type <name> IDENTIFIER
%type <numbers> StringConstant STRING
%type <characters> INTCON Expr SimpleExpr AddExpr MulExpr Constant Factor ReturnStatement

   //Create union with the name, index for systab, and value, seen in examples
%union {
  char * name; //id
  int index; //for symbol table
  int numbers; //for storing a number value
  int characters; //for storing a string value
}

/***********************PRODUCTIONS****************************/
%%
Program		: Procedures 
		{
		  //			printf("<Program> -> <Procedures>\n");
		}
	  	| DeclList Procedures
		{
		  //	printf("<Program> -> <DeclList> <Procedures>\n");
		}
          ;

Procedures 	: ProcedureDecl Procedures
		{
		  //	printf("<Procedures> -> <ProcedureDecl> <Procedures>\n");
		}
	   	|
		{
		  //	printf("<Procedures> -> epsilon\n");
		}
	   	;

ProcedureDecl : ProcedureHead ProcedureBody
		{
		  //	printf("<ProcedureDecl> -> <ProcedureHead> <ProcedureBody>\n");
		}
              ;

ProcedureHead : FunctionDecl DeclList 
		{
		  //	printf("<ProcedureHead> -> <FunctionDecl> <DeclList>\n");
		}
	      | FunctionDecl
		{
		  //	printf("<ProcedureHead> -> <FunctionDecl>\n");
		}
              ;

FunctionDecl :  Type IDENTIFIER LPAREN RPAREN LBRACE 
		{
		  //	printf("<FunctionDecl> ->  <Type> <IDENTIFIER> <LP> <RP> <LBR>\n"); 
		}
	      	;

ProcedureBody : StatementList RBRACE
		{
		  //	printf("<ProcedureBody> -> <StatementList> <RBR>\n");
		}
	      ;


DeclList 	: Type IdentifierList  SEMICOLON 
		{
		  //printf("<DeclList> -> <Type> <IdentifierList> <SC>\n");
		}		
	   	| DeclList Type IdentifierList SEMICOLON
	 	{
		  //printf("<DeclList> -> <DeclList> <Type> <IdentifierList> <SC>\n");
	 	}
          	;


IdentifierList 	: VarDecl  
		{
		  //printf("<IdentifierList> -> <VarDecl>\n");
		}
						
                | IdentifierList COMMA VarDecl
		{
		  //printf("<IdentifierList> -> <IdentifierList> <CM> <VarDecl>\n");
		}
                ;

VarDecl 	: IDENTIFIER
		{ 
		  //printf("<VarDecl> -> <IDENTIFIER\n");
		}
		| IDENTIFIER LBRACKET INTCON RBRACKET
                {
		  //printf("<VarDecl> -> <IDENTIFIER> <LBK> <INTCON> <RBK>\n");
		}
		;

Type     	: INTEGER 
		{ 
		  //printf("<Type> -> <INTEGER>\n");
		}
                ;

Statement 	: Assignment
		{ 
		  //printf("<Statement> -> <Assignment>\n");
		}
                | IfStatement
		{ 
		  //printf("<Statement> -> <IfStatement>\n");
		}
		| WhileStatement
		{ 
		  //printf("<Statement> -> <WhileStatement>\n");
		}
                | IOStatement 
		{ 
		  //printf("<Statement> -> <IOStatement>\n");
		}
		| ReturnStatement
		{ 
		  //printf("<Statement> -> <ReturnStatement>\n");
		}
		| ExitStatement	
		{ 
		  //printf("<Statement> -> <ExitStatement>\n");
		}
		| CompoundStatement
		{ 
		  //printf("<Statement> -> <CompoundStatement>\n");
		}
                ;

Assignment      : Variable ASSIGN Expr SEMICOLON
		{
		  //printf("<Assignment> -> <Variable> <ASSIGN> <Expr> <SC>\n");
		  SymPutFieldByIndex(symtab, $1, SYMTAB_VALUE_FIELD, (Generic)$3); //Assign a expression to a index at variable in symbol table
	    }
                ;
				
IfStatement	: IF TestAndThen ELSE CompoundStatement
		{
		  //printf("<IfStatement> -> <IF> <TestAndThen> <ELSE> <CompoundStatement>\n");
		}
		| IF TestAndThen
		{
		  //printf("<IfStatement> -> <IF> <TestAndThen>\n");
		}
		;
		
				
TestAndThen	: Test CompoundStatement
		{
		  //printf("<TestAndThen> -> <Test> <CompoundStatement>\n");
		}
		;
				
Test		: LPAREN Expr RPAREN
		{
		  //printf("<Test> -> <LP> <Expr> <RP>\n");
		}
		;
	

WhileStatement  : WhileToken WhileExpr Statement
		{
		  //printf("<WhileStatement> -> <WhileToken> <WhileExpr> <Statement>\n");
		}
                ;
                
WhileExpr	: LPAREN Expr RPAREN
                {
                  //printf("<WhileExpr> -> <LP> <Expr> <RP>\n");
                }
		;
				
WhileToken	: WHILE
		{
		  //printf("<WhileToken> -> <WHILE>\n");
		}
		;


IOStatement     : READ LPAREN Variable RPAREN SEMICOLON
		{
		  //printf("<IOStatement> -> <READ> <LP> <Variable> <RP> <SC>\n");
          //Read in variable and store in symbol table
		  int tmp;
		  scanf("%d", &tmp);
		  SymPutFieldByIndex(symtab, $3, SYMTAB_VALUE_FIELD, (Generic)tmp);
		}
                | WRITE LPAREN Expr RPAREN SEMICOLON
		{
		  //printf("<IOStatement> -> <WRITE> <LP> <Expr> <RP> <SC>\n");
		  printf("%d\n", $3); //write out an number using %d
                }
                | WRITE LPAREN StringConstant RPAREN SEMICOLON         
		{
		  //printf("<IOStatement> -> <WRITE> <LP> <StringConstant> <RP> <SC>\n");
                  printf("%s\n", $3); //write out a string contastant using %s
		}
                ;

ReturnStatement : RETURN Expr SEMICOLON
		{
		  //printf("<ReturnStatement> -> <RETURN> <Expr> <SC>\n");
		  $$ = $2; //set the return equal to the expression;
                }
                ;

ExitStatement 	: EXIT SEMICOLON
		{
		  //printf("<ExitStatement> -> <EXIT> <SC>\n");
		}
		;

CompoundStatement : LBRACE StatementList RBRACE
		{
		  //printf("<CompoundStatement> -> <LBR> <StatementList> <RBR>\n");
		}
                ;

StatementList   : Statement
		{		
		  //printf("<StatementList> -> <Statement>\n");
		}
                | StatementList Statement
		{		
		  //printf("<StatementList> -> <StatementList> <Statement>\n");
		}
                ;

Expr            : SimpleExpr
		{
		  //printf("<Expr> -> <SimpleExpr>\n");
		  $$ = $1; //Set Expression based on simple expression
                }
                | Expr OR SimpleExpr 
		{
		  //printf("<Expr> -> <Expr> <OR> <SimpleExpr> \n");
		  $$ = ($1 | $3); //set expression if expression or simple expression
                }
                | Expr AND SimpleExpr 
		{
		  //printf("<Expr> -> <Expr> <AND> <SimpleExpr> \n");
		  $$ = ($1 && $3); //set expression if epression and simple expression
                }
                | NOT SimpleExpr 
		{
		  //printf("<Expr> -> <NOT> <SimpleExpr> \n");
		  $$ = !$2; //set to not simplepression
		}
                ;

SimpleExpr	: AddExpr
		{
		  //printf("<SimpleExpr> -> <AddExpr>\n");
		  $$ = $1; //Set simple expression to addexpressions value
                }
                | SimpleExpr EQ AddExpr
		{
		  //printf("<SimpleExpr> -> <SimpleExpr> <EQ> <AddExpr> \n");
		  $$ = ($1 == $3); //set simple expression true if simple expression is equal to sum of add expression
                }
                | SimpleExpr NE AddExpr
		{
		  //printf("<SimpleExpr> -> <SimpleExpr> <NE> <AddExpr> \n");
                  $$ = ($1 != $3); //set simple expression if simple expression isnt equal to sum of add expression
		}
                | SimpleExpr LE AddExpr
		{
		  //printf("<SimpleExpr> -> <SimpleExpr> <LE> <AddExpr> \n");
		  $$ = ($1 <= $3); //set simple expression if simple expression is less than or equal to the sum of add expression
                }
                | SimpleExpr LT AddExpr
		{
		  //printf("<SimpleExpr> -> <SimpleExpr> <LT> <AddExpr> \n");
		  $$ = ($1 < $3); //set simple expressio if simple expression is less than sum of add expression
                }
                | SimpleExpr GE AddExpr
		{
		  //printf("<SimpleExpr> -> <SimpleExpr> <GE> <AddExpr> \n");
		  $$ = ($1 >= $3); //set simple expression if simple expression is greater than or equal to 
                }
                | SimpleExpr GT AddExpr
		{
		  //printf("<SimpleExpr> -> <SimpleExpr> <GT> <AddExpr> \n");
		  $$ = ($1 > $3); //set simple expression if simple expression is greater than sum of add machine
                }
                ;

AddExpr		:  MulExpr            
		{
		  //printf("<AddExpr> -> <MulExpr>\n");
		  $$ = $1; //set the add expression to a multiplication expression 
                }
                |  AddExpr PLUS MulExpr
		{
		  //printf("<AddExpr> -> <AddExpr> <PLUS> <MulExpr> \n");
		  $$ = ($1 + $3); // set the add expression equal to the sum of the add expresion and product
                }
                |  AddExpr MINUS MulExpr
		{
		  //printf("<AddExpr> -> <AddExpr> <MINUS> <MulExpr> \n");
		  $$ = ($1 - $3); // set the add expression equal to the sum of the add expression and the multiplication expression 
                }
                ;

MulExpr		:  Factor
		{
		  //printf("<MulExpr> -> <Factor>\n");
		  $$ = $1; //change the multiplication expression to a factor type
                }
                |  MulExpr TIMES Factor
		{
		  //printf("<MulExpr> -> <MulExpr> <TIMES> <Factor> \n");
		  $$ = ($1 * $3); //set the multiplication expression equal to the product of the multiplication expression and factor type
                }
                |  MulExpr DIVIDE Factor
		{
		  //printf("<MulExpr> -> <MulExpr> <DIVIDE> <Factor> \n");
		  $$ = ($1 / $3); //set the multiplication expression equal to the product of the mutiplication expression divided by factor type
                }		
                ;
				
Factor          : Variable
		{ 
		  //printf("<Factor> -> <Variable>\n");
		  $$ = (int)SymGetFieldByIndex(symtab, $1, SYMTAB_VALUE_FIELD); //set factor equal to variable
                }
                | Constant
		{ 
		  //printf("<Factor> -> <Constant>\n");
		  $$ = $1; //set factor to the value of the direct constant
                }
                | IDENTIFIER LPAREN RPAREN
       	{	
		  //printf("<Factor> -> <IDENTIFIER> <LP> <RP>\n");
		  //$$ = (); //
                }
         	| LPAREN Expr RPAREN
		{
	      //printf("<Factor> -> <LP> <Expr> <RP>\n");
		  $$ = $2; //set factor to value of expression
		}
                ;  

Variable        : IDENTIFIER
		{
			//printf("<Variable> -> <IDENTIFIER>\n");
			$$ = SymIndex(symtab, $1);
		}
                | IDENTIFIER LBRACKET Expr RBRACKET    
        {
			//printf("<Variable> -> <IDENTIFIER> <LBK> <Expr> <RBK>\n");
			//get value from array at given expression
       	}
                ;			       

StringConstant 	: STRING
		{ 
			//printf("<StringConstant> -> <STRING>\n");
			$$ = $1; //set string constant to value of string
		}
                ;

Constant        : INTCON
		{ 
			//printf("<Constant> -> <INTCON>\n");
			$$ = $1; //set constant equal to value of integer constant
		}
                ;

%%


/********************C ROUTINES *********************************/

void Cminus_error(const char *s)
{
  fprintf(stderr,"%s: line %d: %s\n",fileName,Cminus_lineno,s);
}

int Cminus_wrap() {
	return 1;
}

static void initialize(char* inputFileName) {

	Cminus_in = fopen(inputFileName,"r");
        if (Cminus_in == NULL) {
          fprintf(stderr,"Error: Could not open file %s\n",inputFileName);
          exit(-1);
        }

	char* dotChar = rindex(inputFileName,'.');
	int endIndex = strlen(inputFileName) - strlen(dotChar);
	char *outputFileName = nssave(2,substr(inputFileName,0,endIndex),".s");
	stdout = freopen(outputFileName,"w",stdout);
        if (stdout == NULL) {
          fprintf(stderr,"Error: Could not open file %s\n",outputFileName);
          exit(-1);
        }

	//At end of initialization initialize the symbol table
	symtab = SymInit(SYMTABLE_SIZE); //innitialize table to predefined size
	SymInitField(symtab, SYMTAB_VALUE_FIELD, (Generic)-1, NULL); //initialize the value field 

}

static void finalize() {

    fclose(Cminus_in);
    fclose(stdout);

	//Close symbol table
	SymKillField(symtab, SYMTAB_VALUE_FIELD);
	SymKill(symtab);
    

}

int main(int argc, char** argv)

{	
	fileName = argv[1];
	initialize(fileName);
	
        Cminus_parse();
  
  	finalize();
  
  	return 0;
}
/******************END OF C ROUTINES**********************/
