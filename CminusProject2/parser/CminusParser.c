/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         Cminus_parse
#define yylex           Cminus_lex
#define yyerror         Cminus_error
#define yydebug         Cminus_debug
#define yynerrs         Cminus_nerrs

#define yylval          Cminus_lval
#define yychar          Cminus_char

/* Copy the first part of user declarations.  */
#line 12 "CminusParser.y" /* yacc.c:339  */

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
#define SYMTAB_VALUE_FIELD     "value"
#define SYMTAB_OFFSET_FIELD    "offset"
#define SYMTAB_INDEX_FIELD           "index"

/*********************EXTERNAL DECLARATIONS***********************/

  EXTERN(void,Cminus_error,(const char*));

  EXTERN(int,Cminus_lex,(void));

  char *fileName;

  SymTable symtab;

  extern int Cminus_lineno;

  extern FILE *Cminus_in;

  struct Regs{ //structure that contains each regs 32 and 64 names as well as a flag for if its in use
    int regInUse;
    char* Reg64;
    char* Reg32;
  };

  struct Regs Registers[14]; //create stucts for holding regs
  static int totalRegNum = 14; //the number of register names
  static char* names64[] = {"%r8", "%r9", "%r10", "%r11", "%r12", "%r13", "%r14", "%r15", "%rax", "%rbx", "%rcx", "%rdx", "%rsi", "%rdi"}; //stores the register names of all 64 bit regs (except the ones we save for specific calcs)
  static char* names32[] = {"%r8d", "%r9d", "%r10d", "%r11d", "%r12d", "%r13d", "%r14d", "%r15d", "%eax", "%ebx", "%ecx", "%edx", "%esi", "%edi"}; //stores the register names of all 32 bit regs


  int numWords = 0; //stores the number of string counstants used (needed for printing)
  int offset = 0; //store global offset value

  char* decBuf[2000]; //used to hold declarations near top that change (strings)
  char* buf[8000]; //usd to store the string of instructions
  char* temp[2000]; //used to hold current instruction to be appended to buffer

  
  /**FUCtion declarations**/
  int getReg(); //get index of free re
  int get32Reg(SymTable symtab); //get index of 64 reg, put if not exist
  int get64Reg(SymTable symtab); //same as above but 32
  void freeReg(int reg); //set boolean flag of inuse to false for regester being freed
  void initRegs(); //set up regs for use in main
  void finalPrint(); //output the assembly code

  

#line 135 "CminusParser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "CminusParser.h".  */
#ifndef YY_CMINUS_CMINUSPARSER_H_INCLUDED
# define YY_CMINUS_CMINUSPARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int Cminus_debug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AND = 258,
    ELSE = 259,
    EXIT = 260,
    FOR = 261,
    IF = 262,
    INTEGER = 263,
    NOT = 264,
    OR = 265,
    READ = 266,
    WHILE = 267,
    WRITE = 268,
    LBRACE = 269,
    RBRACE = 270,
    LE = 271,
    LT = 272,
    GE = 273,
    GT = 274,
    EQ = 275,
    NE = 276,
    ASSIGN = 277,
    COMMA = 278,
    SEMICOLON = 279,
    LBRACKET = 280,
    RBRACKET = 281,
    LPAREN = 282,
    RPAREN = 283,
    PLUS = 284,
    TIMES = 285,
    IDENTIFIER = 286,
    DIVIDE = 287,
    RETURN = 288,
    STRING = 289,
    INTCON = 290,
    MINUS = 291,
    DIVDE = 292
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE Cminus_lval;

int Cminus_parse (void);

#endif /* !YY_CMINUS_CMINUSPARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 224 "CminusParser.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   146

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  130

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   121,   121,   126,   133,   138,   143,   149,   153,   159,
     165,   172,   177,   184,   188,   194,   202,   208,   214,   218,
     222,   226,   230,   234,   238,   244,   260,   264,   271,   277,
     284,   290,   296,   303,   319,   335,   355,   361,   367,   373,
     377,   383,   388,   402,   415,   427,   432,   461,   489,   517,
     545,   573,   603,   608,   622,   638,   644,   657,   683,   704,
     711,   717,   725,   741,   749,   757
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AND", "ELSE", "EXIT", "FOR", "IF",
  "INTEGER", "NOT", "OR", "READ", "WHILE", "WRITE", "LBRACE", "RBRACE",
  "LE", "LT", "GE", "GT", "EQ", "NE", "ASSIGN", "COMMA", "SEMICOLON",
  "LBRACKET", "RBRACKET", "LPAREN", "RPAREN", "PLUS", "TIMES",
  "IDENTIFIER", "DIVIDE", "RETURN", "STRING", "INTCON", "MINUS", "DIVDE",
  "$accept", "Program", "Procedures", "ProcedureDecl", "ProcedureHead",
  "FunctionDecl", "ProcedureBody", "DeclList", "IdentifierList", "VarDecl",
  "Type", "Statement", "Assignment", "IfStatement", "TestAndThen", "Test",
  "WhileStatement", "WhileExpr", "WhileToken", "IOStatement",
  "ReturnStatement", "ExitStatement", "CompoundStatement", "StatementList",
  "Expr", "SimpleExpr", "AddExpr", "MulExpr", "Factor", "Variable",
  "StringConstant", "Constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292
};
# endif

#define YYPACT_NINF -65

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-65)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      30,   -65,    11,   -65,    30,    49,    30,    30,   -14,   -65,
     -65,    36,   -21,    20,    60,   -65,    64,    49,   100,    37,
     -65,   -65,   -65,   -65,   -65,    72,   -65,   -65,   -65,   -65,
       9,   104,    30,    76,   -65,   -14,    32,    52,   -65,   101,
     -65,    37,   123,   115,    99,    39,    38,    37,    66,    37,
      54,   -65,    85,    95,   -23,    68,   -65,   -65,   -65,    37,
      49,   -65,   -65,    37,    76,   106,    82,    97,   105,    76,
     -65,    16,   115,   -65,   107,   -65,    55,   108,   -65,     5,
      95,    74,   109,    66,    66,   -65,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    75,   -65,    86,   -65,
     112,   120,   -65,   -65,   -65,   116,   117,   118,   -65,   -65,
     -65,    95,    95,   -23,   -23,   -23,   -23,   -23,   -23,    68,
      68,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    17,     0,     2,     5,     0,     8,     5,     0,     1,
       4,     0,     0,     0,     0,    32,     0,     0,    62,     0,
       6,    39,    18,    19,    20,     0,    21,    22,    23,    24,
       0,     0,     7,     0,     3,     0,    15,     0,    13,     0,
      37,     0,    27,     0,     0,     0,     0,     0,     0,     0,
      62,    65,     0,    41,    45,    52,    55,    58,    59,     0,
       0,    10,    40,     0,     0,    15,     0,     0,     0,     0,
      11,     0,     0,    28,     0,    64,     0,     0,    38,     0,
      44,     0,     0,     0,     0,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    30,     0,    12,
       0,     0,    14,    29,    26,     0,     0,     0,    63,    61,
      60,    43,    42,    48,    49,    50,    51,    46,    47,    53,
      54,    56,    57,    31,    25,    16,     9,    33,    34,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -65,   -65,    23,   -65,   -65,   -65,   -65,   133,   -31,    77,
       3,   -28,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -38,   126,    45,   -47,    31,   -64,    29,    -5,
     -65,   -65
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,     5,     6,    20,     7,    37,    38,
       8,    21,    22,    23,    42,    43,    24,    60,    25,    26,
      27,    28,    29,    30,    52,    53,    54,    55,    56,    57,
      77,    58
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      31,    80,    62,    40,    66,    73,    92,    11,    83,    33,
      35,     9,    31,    93,    12,    84,    13,    36,    62,    83,
      14,    15,    16,    17,    61,    31,    84,    10,   119,   120,
      34,   108,    97,    66,   104,    64,   111,   112,     1,    74,
      18,    31,    19,    12,   103,    13,    48,    41,    48,    14,
      15,    16,    17,    78,    12,    31,    13,    67,    83,    68,
      14,    15,    16,    17,    49,    84,    49,    39,    50,    18,
      50,    19,    51,    75,    51,    69,    70,    83,    83,    47,
      18,    82,    19,   106,    84,    84,    71,    44,    83,    83,
      76,    45,    79,    49,    81,    84,    84,    50,    94,    59,
      95,    51,   109,   123,    96,    69,    99,    65,    98,    85,
     124,    86,    87,    88,    89,    90,    91,   113,   114,   115,
     116,   117,   118,   121,   122,    47,    63,    72,    68,    17,
      18,    67,   100,   101,   126,   105,   107,   110,   125,    32,
     127,   128,   129,    46,     0,     0,   102
};

static const yytype_int8 yycheck[] =
{
       5,    48,    30,    24,    35,    43,    29,     4,     3,     6,
       7,     0,    17,    36,     5,    10,     7,    31,    46,     3,
      11,    12,    13,    14,    15,    30,    10,     4,    92,    93,
       7,    26,    60,    64,    72,    32,    83,    84,     8,    44,
      31,    46,    33,     5,    28,     7,     9,    27,     9,    11,
      12,    13,    14,    15,     5,    60,     7,    25,     3,    27,
      11,    12,    13,    14,    27,    10,    27,    31,    31,    31,
      31,    33,    35,    34,    35,    23,    24,     3,     3,    25,
      31,    27,    33,    28,    10,    10,    41,    27,     3,     3,
      45,    27,    47,    27,    49,    10,    10,    31,    30,    27,
      32,    35,    28,    28,    59,    23,    24,    31,    63,    24,
      24,    16,    17,    18,    19,    20,    21,    86,    87,    88,
      89,    90,    91,    94,    95,    25,    22,     4,    27,    14,
      31,    25,    35,    28,    14,    28,    28,    28,    26,     6,
      24,    24,    24,    17,    -1,    -1,    69
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    39,    40,    41,    42,    43,    45,    48,     0,
      40,    48,     5,     7,    11,    12,    13,    14,    31,    33,
      44,    49,    50,    51,    54,    56,    57,    58,    59,    60,
      61,    67,    45,    48,    40,    48,    31,    46,    47,    31,
      24,    27,    52,    53,    27,    27,    61,    25,     9,    27,
      31,    35,    62,    63,    64,    65,    66,    67,    69,    27,
      55,    15,    49,    22,    48,    31,    46,    25,    27,    23,
      24,    62,     4,    60,    67,    34,    62,    68,    15,    62,
      63,    62,    27,     3,    10,    24,    16,    17,    18,    19,
      20,    21,    29,    36,    30,    32,    62,    49,    62,    24,
      35,    28,    47,    28,    60,    28,    28,    28,    26,    28,
      28,    63,    63,    64,    64,    64,    64,    64,    64,    65,
      65,    66,    66,    28,    24,    26,    14,    24,    24,    24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    39,    40,    40,    41,    42,    42,    43,
      44,    45,    45,    46,    46,    47,    47,    48,    49,    49,
      49,    49,    49,    49,    49,    50,    51,    51,    52,    53,
      54,    55,    56,    57,    57,    57,    58,    59,    60,    61,
      61,    62,    62,    62,    62,    63,    63,    63,    63,    63,
      63,    63,    64,    64,    64,    65,    65,    65,    66,    66,
      66,    66,    67,    67,    68,    69
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     0,     2,     2,     1,     5,
       2,     3,     4,     1,     3,     1,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     2,     2,     3,
       3,     3,     1,     5,     5,     5,     3,     2,     3,     1,
       2,     1,     3,     3,     2,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     1,
       3,     3,     1,     4,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 122 "CminusParser.y" /* yacc.c:1646  */
    {
	    finalPrint();
	    //printf("<Program> -> <Procedures>\n");
	  }
#line 1397 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 127 "CminusParser.y" /* yacc.c:1646  */
    {
	    finalPrint();
	    //printf("<Program> -> <DeclList> <Procedures>\n");
	  }
#line 1406 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 134 "CminusParser.y" /* yacc.c:1646  */
    {
	     //printf("<Procedures> -> <ProcedureDecl> <Procedures>\n");
	   }
#line 1414 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 138 "CminusParser.y" /* yacc.c:1646  */
    {
	     //printf("<Procedures> -> epsilon\n");
	   }
#line 1422 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 144 "CminusParser.y" /* yacc.c:1646  */
    {
		//printf("<ProcedureDecl> -> <ProcedureHead> <ProcedureBody>\n");
	      }
#line 1430 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 150 "CminusParser.y" /* yacc.c:1646  */
    {
		//printf("<ProcedureHead> -> <FunctionDecl> <DeclList>\n");
	      }
#line 1438 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 154 "CminusParser.y" /* yacc.c:1646  */
    {
		//printf("<ProcedureHead> -> <FunctionDecl>\n");
	      }
#line 1446 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 160 "CminusParser.y" /* yacc.c:1646  */
    {
	       //printf("<FunctionDecl> ->  <Type> <IDENTIFIER> <LP> <RP> <LBR>\n"); 
	     }
#line 1454 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 166 "CminusParser.y" /* yacc.c:1646  */
    {
		//printf("<ProcedureBody> -> <StatementList> <RBR>\n");
	      }
#line 1462 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 173 "CminusParser.y" /* yacc.c:1646  */
    { 
	   (yyval) = offset;
	   //printf("<DeclList> -> <Type> <IdentifierList> <SC>\n");
	 }
#line 1471 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 178 "CminusParser.y" /* yacc.c:1646  */
    {
	   //printf("<DeclList> -> <DeclList> <Type> <IdentifierList> <SC>\n");
	 }
#line 1479 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 185 "CminusParser.y" /* yacc.c:1646  */
    {
		 //printf("<IdentifierList> -> <VarDecl>\n");
	       }
#line 1487 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 189 "CminusParser.y" /* yacc.c:1646  */
    {
		 //printf("<IdentifierList> -> <IdentifierList> <CM> <VarDecl>\n");
	       }
#line 1495 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 195 "CminusParser.y" /* yacc.c:1646  */
    {
	  SymPutFieldByIndex(symtab, (yyvsp[0]), SYMTAB_OFFSET_FIELD, (Generic)offset); //insert the declared variables offset into the symtab
	  offset += 4; //increment by 4 because we just inserted a int (4 bytes)
	  (yyval) = (yyvsp[0]);

	  //printf("<VarDecl> -> <IDENTIFIER\n");
	}
#line 1507 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 203 "CminusParser.y" /* yacc.c:1646  */
    {
	  //printf("<VarDecl> -> <IDENTIFIER> <LBK> <INTCON> <RBK>\n");
	}
#line 1515 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 209 "CminusParser.y" /* yacc.c:1646  */
    { 
	   //printf("<Type> -> <INTEGER>\n");
	 }
#line 1523 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 215 "CminusParser.y" /* yacc.c:1646  */
    { 
	    //printf("<Statement> -> <Assignment>\n");
	  }
#line 1531 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 219 "CminusParser.y" /* yacc.c:1646  */
    { 
	    //printf("<Statement> -> <IfStatement>\n");
	  }
#line 1539 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 223 "CminusParser.y" /* yacc.c:1646  */
    { 
	    //printf("<Statement> -> <WhileStatement>\n");
	  }
#line 1547 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 227 "CminusParser.y" /* yacc.c:1646  */
    { 
	    //printf("<Statement> -> <IOStatement>\n");
	  }
#line 1555 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 231 "CminusParser.y" /* yacc.c:1646  */
    { 
	    //printf("<Statement> -> <ReturnStatement>\n");
	  }
#line 1563 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 235 "CminusParser.y" /* yacc.c:1646  */
    { 
	    //printf("<Statement> -> <ExitStatement>\n");
	  }
#line 1571 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 239 "CminusParser.y" /* yacc.c:1646  */
    { 
	    //printf("<Statement> -> <CompoundStatement>\n");
	  }
#line 1579 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 245 "CminusParser.y" /* yacc.c:1646  */
    {		  
		  //assigns an expression to a variable
		  char* regName = (char*)SymGetFieldByIndex(symtab, (yyvsp[-1]), SYM_NAME_FIELD);
		  int regindex = (int)SymGetFieldByIndex(symtab, (yyvsp[-3]), SYMTAB_INDEX_FIELD);
		  char* regDestName = names64[regindex];
		  
		  sprintf(temp, "\tmovl %s, (%s)\n", regName, regDestName);
		  strcat(buf, temp);
		  
		  freeReg((int)SymGetFieldByIndex(symtab, (yyvsp[-1]), SYMTAB_INDEX_FIELD));
		  
		  //printf("<Assignment> -> <Variable> <ASSIGN> <Expr> <SC>\n");
		}
#line 1597 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 261 "CminusParser.y" /* yacc.c:1646  */
    {
	     //printf("<IfStatement> -> <IF> <TestAndThen> <ELSE> <CompoundStatement>\n");
           }
#line 1605 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 265 "CminusParser.y" /* yacc.c:1646  */
    {
	     //printf("<IfStatement> -> <IF> <TestAndThen>\n");
	   }
#line 1613 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 272 "CminusParser.y" /* yacc.c:1646  */
    {
		//printf("<TestAndThen> -> <Test> <CompoundStatement>\n");
	      }
#line 1621 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 278 "CminusParser.y" /* yacc.c:1646  */
    {
		//printf("<Test> -> <LP> <Expr> <RP>\n");
	      }
#line 1629 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 285 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<WhileStatement> -> <WhileToken> <WhileExpr> <Statement>\n");
		}
#line 1637 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 291 "CminusParser.y" /* yacc.c:1646  */
    {
	   //printf("<WhileExpr> -> <LP> <Expr> <RP>\n");
	 }
#line 1645 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 297 "CminusParser.y" /* yacc.c:1646  */
    {
	    //printf("<WhileToken> -> <WHILE>\n");
	  }
#line 1653 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 304 "CminusParser.y" /* yacc.c:1646  */
    { 
		  //read in a variable
		  sprintf(temp, "\tmovl $.int_rformat, %%edi\n", (char*)SymGetFieldByIndex(symtab, (yyvsp[-2]), SYM_NAME_FIELD));
		  strcat(buf, temp);

		  sprintf(temp, "\tmovq %s, %%rsi\n");
                  strcat(buf, temp);

		  sprintf(temp, "\tmovl $0, %%eax\n\tcall scanf\n");
		  strcat(buf, temp);

		  freeReg((int)SymGetFieldByIndex(symtab, (yyvsp[-2]), SYMTAB_INDEX_FIELD));
		   
		  //printf("<IOStatement> -> <READ> <LP> <Variable> <RP> <SC>\n");
		}
#line 1673 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 320 "CminusParser.y" /* yacc.c:1646  */
    {
		  //write out an expression
		  sprintf(temp, "\tmovl %s, %%esi\n\tmovl $.int_wformat, %%edi\n", (char*)SymGetFieldByIndex(symtab, (yyvsp[-2]), SYM_NAME_FIELD));
		  strcat(buf, temp);

		  sprintf(temp, "\tmovl $0, %%eax\n");
                  strcat(buf, temp);

		  sprintf(temp, "\tcall printf\n");
                  strcat(buf, temp);

		  freeReg((int)SymGetFieldByIndex(symtab, (yyvsp[-2]), SYMTAB_INDEX_FIELD));
		    
		  //printf("<IOStatement> -> <WRITE> <LP> <Expr> <RP> <SC>\n");
		}
#line 1693 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 336 "CminusParser.y" /* yacc.c:1646  */
    {
		  //write out a string constant
		  sprintf(temp, "\t.string_const%d: .string \"%s\"\n", numWords, SymGetFieldByIndex(symtab, (yyvsp[-2]), SYM_NAME_FIELD));
		  strcat(decBuf, temp);

		  sprintf(temp, "\tmovl $.string_const%d, %%esi\n\tmovl $.str_wformat, %%edi\n", numWords, (char*)SymGetFieldByIndex(symtab, (yyvsp[-2]), SYM_NAME_FIELD)); //num words used here to output each string constant
		  strcat(buf, temp);

		  sprintf(temp, "\tmovl $0, %%eax\n\tcall printf\n");
                  strcat(buf, temp);

		  numWords++; //we added a new word so increment for next one

		  freeReg((int)SymGetFieldByIndex(symtab, (yyvsp[-2]), SYMTAB_INDEX_FIELD));

		  //printf("<IOStatement> -> <WRITE> <LP> <StringConstant> <RP> <SC>\n");
		}
#line 1715 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 356 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<ReturnStatement> -> <RETURN> <Expr> <SC>\n");
		}
#line 1723 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 362 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<ExitStatement> -> <EXIT> <SC>\n");
		}
#line 1731 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 368 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<CompoundStatement> -> <LBR> <StatementList> <RBR>\n");
		}
#line 1739 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 374 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<StatementList> -> <Statement>\n");
		}
#line 1747 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 378 "CminusParser.y" /* yacc.c:1646  */
    {
		  //printf("<StatementList> -> <StatementList> <Statement>\n");
		}
#line 1755 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 384 "CminusParser.y" /* yacc.c:1646  */
    {
		  (yyval) = (yyvsp[0]);
		  //printf("<Expr> -> <SimpleExpr>\n");
		}
#line 1764 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 389 "CminusParser.y" /* yacc.c:1646  */
    {
		  char* lOp = (char*)SymGetFieldByIndex(symtab, (yyvsp[-2]), SYM_NAME_FIELD);
		  char* rOp = (char*)SymGetFieldByIndex(symtab, (yyvsp[0]), SYM_NAME_FIELD);

		  sprintf(temp, "\torl %s, %s\n", rOp, lOp);
		  strcat(buf, temp);

		  freeReg((int)SymGetFieldByIndex(symtab, (yyvsp[0]), SYMTAB_INDEX_FIELD));

		  (yyval) = (yyvsp[-2]);

		  //printf("<Expr> -> <Expr> <OR> <SimpleExpr> \n");
		}
#line 1782 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 403 "CminusParser.y" /* yacc.c:1646  */
    {
		  char* lOp = (char*)SymGetFieldByIndex(symtab, (yyvsp[-2]), SYM_NAME_FIELD);
                  char* rOp = (char*)SymGetFieldByIndex(symtab, (yyvsp[0]), SYM_NAME_FIELD);

                  sprintf(temp, "\tandl %s, %s\n", rOp, lOp);
                  strcat(buf, temp);

                  freeReg((int)SymGetFieldByIndex(symtab, (yyvsp[0]), SYMTAB_INDEX_FIELD));

                  (yyval) = (yyvsp[-2]);
		  //printf("<Expr> -> <Expr> <AND> <SimpleExpr> \n");
		}
#line 1799 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 416 "CminusParser.y" /* yacc.c:1646  */
    {
		  char* name = (char*)SymGetFieldByIndex(symtab, (yyvsp[0]), SYM_NAME_FIELD);

		  sprintf(temp, "\txorl $1, %s\n", name);
		  strcat(buf, temp);

		  (yyval) = (yyvsp[0]);
		  //printf("<Expr> -> <NOT> <SimpleExpr> \n");
		}
#line 1813 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 428 "CminusParser.y" /* yacc.c:1646  */
    {
		  (yyval) = (yyvsp[0]);
		  //printf("<SimpleExpr> -> <AddExpr>\n");
		}
#line 1822 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 433 "CminusParser.y" /* yacc.c:1646  */
    {
		//All simple expressions are about the same however with a different command
		  char* lOp = (char*)SymGetFieldByIndex(symtab, (yyvsp[-2]), SYM_NAME_FIELD);
		  char* rOp = (char*)SymGetFieldByIndex(symtab, (yyvsp[0]), SYM_NAME_FIELD);

		  sprintf(temp, "\tcmpl %s, %s\n", rOp, lOp);
		  strcat(buf, temp);

		  freeReg((int)SymGetFieldByIndex(symtab, (yyvsp[0]), SYMTAB_INDEX_FIELD));

		  sprintf(temp, "\tmovl $0, %s\n", lOp);
		  strcat(buf, temp);

		  int newIndex = get32Reg(symtab);
		  char * newName = (char*)SymGetFieldByIndex(symtab, newIndex, SYM_NAME_FIELD);

		  sprintf(temp, "\tmovl $1, %s\n", newName);
		  strcat(buf, temp);

		  sprintf(temp, "\tcmove %s, %s\n", newName, lOp);
		  strcat(buf, temp);

		  freeReg((int)SymGetFieldByIndex(symtab, newIndex, SYMTAB_INDEX_FIELD));

		  (yyval) = (yyvsp[-2]);
		    
		  //printf("<SimpleExpr> -> <SimpleExpr> <EQ> <AddExpr> \n");
		}
#line 1855 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 462 "CminusParser.y" /* yacc.c:1646  */
    {
		  char* lOp = (char*)SymGetFieldByIndex(symtab, (yyvsp[-2]), SYM_NAME_FIELD);
                  char* rOp = (char*)SymGetFieldByIndex(symtab, (yyvsp[0]), SYM_NAME_FIELD);

                  sprintf(temp, "\tcmpl %s, %s\n", rOp, lOp);
                  strcat(buf, temp);

                  freeReg((int)SymGetFieldByIndex(symtab, (yyvsp[0]), SYMTAB_INDEX_FIELD));

                  sprintf(temp, "\tmovl $0, %s\n", lOp);
                  strcat(buf, temp);

                  int newIndex = get32Reg(symtab);
                  char * newName = (char*)SymGetFieldByIndex(symtab, newIndex, SYM_NAME_FIELD);

                  sprintf(temp, "\tmovl $1, %s\n", newName);
                  strcat(buf, temp);

                  sprintf(temp, "\tcmovne %s, %s\n", newName, lOp);
                  strcat(buf, temp);

                  freeReg((int)SymGetFieldByIndex(symtab, newIndex, SYMTAB_INDEX_FIELD));

                  (yyval) = (yyvsp[-2]);

		  //printf("<SimpleExpr> -> <SimpleExpr> <NE> <AddExpr> \n");
		}
#line 1887 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 490 "CminusParser.y" /* yacc.c:1646  */
    {
		  char* lOp = (char*)SymGetFieldByIndex(symtab, (yyvsp[-2]), SYM_NAME_FIELD);
                  char* rOp = (char*)SymGetFieldByIndex(symtab, (yyvsp[0]), SYM_NAME_FIELD);

                  sprintf(temp, "\tcmpl %s, %s\n", rOp, lOp);
                  strcat(buf, temp);

                  freeReg((int)SymGetFieldByIndex(symtab, (yyvsp[0]), SYMTAB_INDEX_FIELD));

                  sprintf(temp, "\tmovl $0, %s\n", lOp);
                  strcat(buf, temp);

                  int newIndex = get32Reg(symtab);
                  char * newName = (char*)SymGetFieldByIndex(symtab, newIndex, SYM_NAME_FIELD);

                  sprintf(temp, "\tmovl $1, %s\n", newName);
                  strcat(buf, temp);

                  sprintf(temp, "\tcmovle %s, %s\n", newName, lOp);
                  strcat(buf, temp);

                  freeReg((int)SymGetFieldByIndex(symtab, newIndex, SYMTAB_INDEX_FIELD));

                  (yyval) = (yyvsp[-2]);

		  //printf("<SimpleExpr> -> <SimpleExpr> <LE> <AddExpr> \n");
		}
#line 1919 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 518 "CminusParser.y" /* yacc.c:1646  */
    {
		  char* lOp = (char*)SymGetFieldByIndex(symtab, (yyvsp[-2]), SYM_NAME_FIELD);
                  char* rOp = (char*)SymGetFieldByIndex(symtab, (yyvsp[0]), SYM_NAME_FIELD);

                  sprintf(temp, "\tcmpl %s, %s\n", rOp, lOp);
                  strcat(buf, temp);

                  freeReg((int)SymGetFieldByIndex(symtab, (yyvsp[0]), SYMTAB_INDEX_FIELD));

                  sprintf(temp, "\tmovl $0, %s\n", lOp);
                  strcat(buf, temp);

                  int newIndex = get32Reg(symtab);
                  char * newName = (char*)SymGetFieldByIndex(symtab, newIndex, SYM_NAME_FIELD);

                  sprintf(temp, "\tmovl $1, %s\n", newName);
                  strcat(buf, temp);

                  sprintf(temp, "\tcmovl %s, %s\n", newName, lOp);
                  strcat(buf, temp);

                  freeReg((int)SymGetFieldByIndex(symtab, newIndex, SYMTAB_INDEX_FIELD));

                  (yyval) = (yyvsp[-2]);

		  //printf("<SimpleExpr> -> <SimpleExpr> <LT> <AddExpr> \n");
		}
#line 1951 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 546 "CminusParser.y" /* yacc.c:1646  */
    {
		  char* lOp = (char*)SymGetFieldByIndex(symtab, (yyvsp[-2]), SYM_NAME_FIELD);
                  char* rOp = (char*)SymGetFieldByIndex(symtab, (yyvsp[0]), SYM_NAME_FIELD);

                  sprintf(temp, "\tcmpl %s, %s\n", rOp, lOp);
                  strcat(buf, temp);

                  freeReg((int)SymGetFieldByIndex(symtab, (yyvsp[0]), SYMTAB_INDEX_FIELD));

                  sprintf(temp, "\tmovl $0, %s\n", lOp);
                  strcat(buf, temp);

                  int newIndex = get32Reg(symtab);
                  char * newName = (char*)SymGetFieldByIndex(symtab, newIndex, SYM_NAME_FIELD);

                  sprintf(temp, "\tmovl $1, %s\n", newName);
                  strcat(buf, temp);

                  sprintf(temp, "\tcmovge %s, %s\n", newName, lOp);
                  strcat(buf, temp);

                  freeReg((int)SymGetFieldByIndex(symtab, newIndex, SYMTAB_INDEX_FIELD));

                  (yyval) = (yyvsp[-2]);

		  //printf("<SimpleExpr> -> <SimpleExpr> <GE> <AddExpr> \n");
		}
#line 1983 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 574 "CminusParser.y" /* yacc.c:1646  */
    {
		  char* lOp = (char*)SymGetFieldByIndex(symtab, (yyvsp[-2]), SYM_NAME_FIELD);
                  char* rOp = (char*)SymGetFieldByIndex(symtab, (yyvsp[0]), SYM_NAME_FIELD);

                  sprintf(temp, "\tcmpl %s, %s\n", rOp, lOp);
                  strcat(buf, temp);

                  freeReg((int)SymGetFieldByIndex(symtab, (yyvsp[0]), SYMTAB_INDEX_FIELD));

                  sprintf(temp, "\tmovl $0, %s\n", lOp);
                  strcat(buf, temp);

                  int newIndex = get32Reg(symtab);
                  char * newName = (char*)SymGetFieldByIndex(symtab, newIndex, SYM_NAME_FIELD);

                  sprintf(temp, "\tmovl $1, %s\n", newName);
                  strcat(buf, temp);

                  sprintf(temp, "\tcmovg %s, %s\n", newName, lOp);
                  strcat(buf, temp);

                  freeReg((int)SymGetFieldByIndex(symtab, newIndex, SYMTAB_INDEX_FIELD));

                  (yyval) = (yyvsp[-2]);

		  //printf("<SimpleExpr> -> <SimpleExpr> <GT> <AddExpr> \n");
		}
#line 2015 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 604 "CminusParser.y" /* yacc.c:1646  */
    {
		  (yyval) = (yyvsp[0]);
		  //printf("<AddExpr> -> <MulExpr>\n");
		}
#line 2024 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 609 "CminusParser.y" /* yacc.c:1646  */
    {
		  char* lOp = (char*)SymGetFieldByIndex(symtab, (yyvsp[-2]), SYM_NAME_FIELD);
		  char* rOp = (char*)SymGetFieldByIndex(symtab, (yyvsp[0]), SYM_NAME_FIELD);

		  sprintf(temp, "\taddl %s, %s\n", rOp, lOp);
		  strcat(buf, temp);

		  freeReg((int)SymGetFieldByIndex(symtab, (yyvsp[0]), SYMTAB_INDEX_FIELD));

		  (yyval) = (yyvsp[-2]);
		    
		  //printf("<AddExpr> -> <AddExpr> <PLUS> <MulExpr> \n");
		}
#line 2042 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 623 "CminusParser.y" /* yacc.c:1646  */
    {
		  char* lOp = (char*)SymGetFieldByIndex(symtab, (yyvsp[-2]), SYM_NAME_FIELD);
                  char* rOp = (char*)SymGetFieldByIndex(symtab, (yyvsp[0]), SYM_NAME_FIELD);

		  sprintf(temp, "\tsubl %s, %s\n", rOp, lOp);
		  strcat(buf, temp);

		  freeReg((int)SymGetFieldByIndex(symtab, (yyvsp[0]), SYMTAB_INDEX_FIELD));

		  (yyval) = (yyvsp[-2]);
                  
		  //printf("<AddExpr> -> <AddExpr> <MINUS> <MulExpr> \n");
		}
#line 2060 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 639 "CminusParser.y" /* yacc.c:1646  */
    {
		  (yyval) = (yyvsp[0]);
		  
		  //printf("<MulExpr> -> <Factor>\n");
		}
#line 2070 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 645 "CminusParser.y" /* yacc.c:1646  */
    {
		  char* lOp = (char*)SymGetFieldByIndex(symtab, (yyvsp[-2]), SYM_NAME_FIELD);
		  char * rOp = (char*)SymGetFieldByIndex(symtab, (yyvsp[0]), SYM_NAME_FIELD);

		  sprintf(temp, "\timull %s, %s\n", rOp, lOp);
                  strcat(buf, temp);
		    
		  freeReg((int)SymGetFieldByIndex(symtab, (yyvsp[0]), SYMTAB_INDEX_FIELD));
		  (yyval) = (yyvsp[-2]);
		  
		  //printf("<MulExpr> -> <MulExpr> <TIMES> <Factor> \n");
		}
#line 2087 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 658 "CminusParser.y" /* yacc.c:1646  */
    {
		  char* lOp = (char*)SymGetFieldByIndex(symtab, (yyvsp[-2]), SYM_NAME_FIELD);
		  char* rOp = (char*)SymGetFieldByIndex(symtab, (yyvsp[0]), SYM_NAME_FIELD);

		  sprintf(temp, "\tmovl %s, %%eax\n", lOp);
		  strcat(buf, temp);
		  
		  sprintf(temp, "\tcdq\n");
		  strcat(buf, temp);

		  sprintf(temp, "\tidivl %s\n", rOp);
                  strcat(buf, temp);

		  sprintf(temp, "\tmovl %%eax, %s\n", lOp);
                  strcat(buf, temp);


		  freeReg((int)SymGetFieldByIndex(symtab, (yyvsp[0]), SYMTAB_INDEX_FIELD));

		  (yyval) = (yyvsp[-2]);
		    
		  //printf("<MulExpr> -> <MulExpr> <DIVIDE> <Factor> \n");
		}
#line 2115 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 684 "CminusParser.y" /* yacc.c:1646  */
    { 
		  int newIndex = get32Reg(symtab);
		  char* newName = (char*)SymGetFieldByIndex(symtab, newIndex, SYM_NAME_FIELD);

		  int index = (int)SymGetFieldByIndex(symtab, (yyvsp[0]), SYMTAB_INDEX_FIELD);
		  char* name = names64[index];
		  
		  if (name == NULL){
		      name = names64[(yyvsp[0])];
		  }
    
		  sprintf(temp, "\tmovl (%s), %s\n", name, newName);
       		  strcat(buf, temp);

		  freeReg((int)SymGetFieldByIndex(symtab, (yyvsp[0]), SYMTAB_INDEX_FIELD));

		  (yyval) = newIndex;

		  //printf("<Factor> -> <Variable>\n");
		}
#line 2140 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 705 "CminusParser.y" /* yacc.c:1646  */
    { 
		    
		  (yyval) = (yyvsp[0]);

		  //printf("<Factor> -> <Constant>\n");
		}
#line 2151 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 712 "CminusParser.y" /* yacc.c:1646  */
    {
		  (yyval) = SYM_INVALID_INDEX;

		  //printf("<Factor> -> <IDENTIFIER> <LP> <RP>\n");
		}
#line 2161 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 718 "CminusParser.y" /* yacc.c:1646  */
    {
		  (yyval) = (yyvsp[-1]);

		  //printf("<Factor> -> <LP> <Expr> <RP>\n");
		}
#line 2171 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 726 "CminusParser.y" /* yacc.c:1646  */
    {
		  int index = get64Reg(symtab);
		  char* name = (char*)SymGetFieldByIndex(symtab, index, SYM_NAME_FIELD);
		  int off = (int)SymGetFieldByIndex(symtab, (yyvsp[0]), SYMTAB_OFFSET_FIELD);
		  char offStr[10];

		  snprintf(offStr, 9, "%d", off);

		  sprintf(temp, "\tmovq $_gp, %s\n\taddq $%s, %s\n", name, offStr, name);
		  strcat(buf, temp);

		  (yyval) = index;

		  //printf("<Variable> -> <IDENTIFIER>\n");
		}
#line 2191 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 742 "CminusParser.y" /* yacc.c:1646  */
    {
		  (yyval) = SYM_INVALID_INDEX;

		  //printf("<Variable> -> <IDENTIFIER> <LBK> <Expr> <RBK>\n");
		}
#line 2201 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 750 "CminusParser.y" /* yacc.c:1646  */
    { 
		 (yyval) = (yyvsp[0]);

		 //printf("<StringConstant> -> <STRING>\n");
	       }
#line 2211 "CminusParser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 758 "CminusParser.y" /* yacc.c:1646  */
    { 
		 int index = get32Reg(symtab);
		 char* name = (char*)SymGetFieldByIndex(symtab, index, SYM_NAME_FIELD);

		 sprintf(temp, "\tmovl $%d, %s\n", (yyvsp[0]), name);
		 strcat(buf, temp);

		 (yyval) = index;

		 //printf("<Constant> -> <INTCON>\n");
	       }
#line 2227 "CminusParser.c" /* yacc.c:1646  */
    break;


#line 2231 "CminusParser.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 771 "CminusParser.y" /* yacc.c:1906  */



/********************C ROUTINES *********************************/
void initRegs(){
  int i;
  for (i = 0; i < totalRegNum; i++){ //For each register input its 32, 64 reg names and initialize to not in use
    Registers[i].Reg32 = names32[i];
    Registers[i].Reg64 = names64[i];
    Registers[i].regInUse = 0;
  }
}
 
int getReg(){ //returns the index of the first register availible
  int i;
  for (i = 0; i < totalRegNum; i++){
      if (Registers[i].regInUse == 0){
	  Registers[i].regInUse = 1;
	  return i;
	}
    }
  return -1;
}

int get32Reg(SymTable symtab){
  int reg = getReg();
  char* name = names32[reg];
  int index = SymQueryIndex(symtab, name);
  
  if(index == SYM_INVALID_INDEX){
    index = SymIndex(symtab, name);
    SymPutFieldByIndex(symtab, index, SYMTAB_INDEX_FIELD, (Generic)reg);
  }
  return index;
}

int get64Reg(SymTable symtab){
  int reg = getReg();
  char* name = names64[reg];
  int index = SymQueryIndex(symtab, name);
  
  if(index == SYM_INVALID_INDEX){
    index = SymIndex(symtab, name);
    SymPutFieldByIndex(symtab, index, SYMTAB_INDEX_FIELD, (Generic)reg);
  }
  return index;
}


void freeReg(int reg){
  Registers[reg].regInUse = 0;
}

void finalPrint(){
  //print nessessary header info
  printf("\t.section\t.rodata\n");
  printf(".int_wformat: .string \"%%d\\n\"\n");
  printf(".str_wformat: .string \"%%s\\n\"\n");
  printf(".int_rformat: .string \"%%d\"\n");
  
  //print out the global pointer and info for declarations
  if (offset != 0){ //if there is an offset there are variables, output global pointer info and declarations
    printf("\t.comm _gp, %d, 4\n", offset);
    printf("%s", decBuf);
  } else { //if no offset then just output string declarations
    printf("%s", decBuf);
  }
  
  //print the required first few instructions
  printf("\t.text\n");
  printf("\t.global main\n");
  printf("\t.type main,@function\n");
  printf("main:\tnop\n");
  printf("\tpushq %rbp\n");
  printf("\tmovq %rsp, %rbp\n");
  
  //print out all saved instructions
  printf("%s", buf);
  
   //print the final 2 instructions to quit
  printf("\tleave\n");
  printf("\tret\n");
}

void Cminus_error(const char *s){
  fprintf(stderr,"%s: line %d: %s\n",fileName,Cminus_lineno,s);
}

int Cminus_wrap(){
  return 1;
}

static void init(char* inputFileName){

  Cminus_in = fopen(inputFileName,"r");
  if (Cminus_in == NULL){
    fprintf(stderr,"Error: Could not open file %s\n",inputFileName);
    exit(-1);
  }

  char* dotChar = rindex(inputFileName,'.');
  int endIndex = strlen(inputFileName) - strlen(dotChar);
  char *outputFileName = nssave(2,substr(inputFileName,0,endIndex),".s");
  
  stdout = freopen(outputFileName,"w",stdout);
  if (stdout == NULL){
    fprintf(stderr,"Error: Could not open file %s\n",outputFileName);
    exit(-1);
  }

  symtab = SymInit(SYMTABLE_SIZE);
  SymInitField(symtab,SYMTAB_VALUE_FIELD,(Generic)-1,NULL);
  SymInitField(symtab,SYMTAB_OFFSET_FIELD,(Generic)-1,NULL);
  SymInitField(symtab,SYMTAB_INDEX_FIELD,(Generic)-1,NULL);
}

static void finish() {
  SymKillField(symtab,SYMTAB_VALUE_FIELD);
  SymKillField(symtab, SYMTAB_OFFSET_FIELD);
  SymKillField(symtab, SYMTAB_INDEX_FIELD);
  SymKill(symtab);
  fclose(Cminus_in);
  fclose(stdout);
}

int getValue(int index){
  return (int)SymGetFieldByIndex(symtab, index, SYMTAB_VALUE_FIELD); 
}

int setValue(int index, int value){
  SymPutFieldByIndex(symtab, index, SYMTAB_VALUE_FIELD, (Generic)value); 
}

int main(int argc, char** argv){
  fileName = argv[1];
  init(fileName);
  Cminus_parse();
  finish();
  return 0;
}


/******************END OF C ROUTINES**********************/
