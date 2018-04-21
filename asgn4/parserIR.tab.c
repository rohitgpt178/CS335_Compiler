/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "src/parserIR.y" /* yacc.c:339  */

#include <bits/stdc++.h>
//#include<stdlib.h>

//#include "src/node.h"
//#include "src/html.h"
#include "src/symtab.h"
#include "parserIR.tab.h"
using namespace std;

int yylex(void);
//void yyerror(char *s,...);
void yyerror (const char *s) {fprintf (stderr, "%s\n", s);} 

//string typeName="";
extern FILE *yyin;
extern int yylineno;
//extern typedef struct node;

vector <string> lhs;
vector <string> rhs;

vector <string> prog;
int lineno = 1;
int tempno = 0;
int temp_str_no = 0;
int labelno = 0;
string get_tempvar(){
	string str_t = "t";
	string ans =  str_t.append(to_string(tempno));
	tempno++;
	return ans;
}


string get_temp_strvar(){
	string str_t = "t_str";
	string ans =  str_t.append(to_string(temp_str_no));
	temp_str_no++;
	return ans;
}

string get_label(){
	string str_l = "label";
	string ans =  str_l.append(to_string(labelno));
	labelno++;
	return ans;
}

stack <string> if_endlabels;
stack <string> if_bwlabels;

stack <string> for_initlabels;
stack <string> for_endlabels;
stack <string> for_blocklabels;
stack <string> for_postlabels;
stack <string> for_breaklabels;	//not used
stack <string> for_continuelabels;
//string used for argumentlist
string argumentlist_str;
stack <int > is_argument_list_empty;

//splitting strings separated by comma
vector<string> split(const string &s, char delim) {
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}

//string used for expressionlist
string expressionlist_str;

//global symbol table variables
//symboltable sym1;
//symboltable sym2;
symboltable* sym1_pt = new symboltable;//=&sym1;
symboltable* sym2_pt = new symboltable;//&sym2;

table *curr_root = new_root_table(sym1_pt);
table *curr = new_table(sym2_pt,curr_root);
//curr->type=NULL;

//inserting print in symboltable
//insert("print",curr,"function");
//insert("fmt.Println",curr,"function");

#line 157 "parserIR.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parserIR.tab.h".  */
#ifndef YY_YY_PARSERIR_TAB_H_INCLUDED
# define YY_YY_PARSERIR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 96 "src/parserIR.y" /* yacc.c:355  */

#include "src/node.h"

#line 191 "parserIR.tab.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PACKAGE = 258,
    IMPORT = 259,
    FUNC = 260,
    BREAK = 261,
    CASE = 262,
    CONST = 263,
    CONTINUE = 264,
    DEFAULT = 265,
    ELSE = 266,
    FOR = 267,
    GO = 268,
    IF = 269,
    RANGE = 270,
    RETURN = 271,
    STRUCT = 272,
    SWITCH = 273,
    TYPE = 274,
    VAR = 275,
    VAR_TYPE = 276,
    BOOL_CONST = 277,
    NIL_VAL = 278,
    IDENTIFIER = 279,
    BYTE = 280,
    STRING = 281,
    ELLIPSIS = 282,
    SHL = 283,
    SHR = 284,
    INC = 285,
    DEC = 286,
    INTEGER = 287,
    FLOAT = 288,
    ADD = 289,
    SUB = 290,
    MUL = 291,
    QUO = 292,
    REM = 293,
    ASSIGN = 294,
    AND = 295,
    NOT = 296,
    DEFINE = 297,
    AND_NOT = 298,
    OR = 299,
    XOR = 300,
    ARROW = 301,
    ADD_ASSIGN = 302,
    SUB_ASSIGN = 303,
    MUL_ASSIGN = 304,
    QUO_ASSIGN = 305,
    REM_ASSIGN = 306,
    AND_ASSIGN = 307,
    OR_ASSIGN = 308,
    XOR_ASSIGN = 309,
    SHL_ASSIGN = 310,
    SHR_ASSIGN = 311,
    AND_NOT_ASSIGN = 312,
    COLON = 313,
    LAND = 314,
    LOR = 315,
    EQL = 316,
    NEQ = 317,
    LEQ = 318,
    GEQ = 319,
    SEMICOLON = 320,
    GTR = 321,
    LSS = 322,
    LPAREN = 323,
    RPAREN = 324,
    LBRACE = 325,
    RBRACE = 326,
    LBRACK = 327,
    RBRACK = 328,
    COMMA = 329,
    PERIOD = 330
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 100 "src/parserIR.y" /* yacc.c:355  */

     
     //char *nt;
     char *sval;
     node* nt;

#line 286 "parserIR.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSERIR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 301 "parserIR.tab.c" /* yacc.c:358  */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   354

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  218
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  339

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   330

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   153,   153,   160,   181,   190,   197,   201,   207,   208,
     211,   214,   217,   218,   219,   222,   225,   228,   231,   236,
     237,   238,   243,   252,   254,   262,   278,   297,   369,   375,
     407,   448,   451,   454,   458,   465,   468,   486,   490,   495,
     512,   531,   592,   600,   603,   608,   609,   615,   618,   625,
     629,   635,   639,   652,   658,   661,   672,   682,   685,   691,
     694,   702,   707,   714,   721,   734,   735,   739,   742,   743,
     748,   752,   756,   762,   765,   768,   769,   776,   777,   781,
     786,   790,   796,   806,   815,   825,   828,   838,   841,   852,
     855,   856,   857,   858,   859,   862,   889,   904,   918,   930,
     940,   955,   956,   959,   962,   965,   967,   975,   989,  1034,
    1055,  1067,  1078,  1104,  1116,  1131,  1144,  1155,  1162,  1174,
    1185,  1191,  1192,  1196,  1197,  1201,  1202,  1206,  1213,  1223,
    1227,  1233,  1240,  1254,  1263,  1272,  1279,  1280,  1283,  1284,
    1287,  1288,  1291,  1295,  1302,  1310,  1319,  1326,  1334,  1335,
    1350,  1358,  1362,  1368,  1375,  1378,  1385,  1389,  1390,  1391,
    1396,  1405,  1414,  1420,  1427,  1445,  1452,  1470,  1477,  1495,
    1502,  1520,  1527,  1545,  1554,  1558,  1585,  1589,  1593,  1597,
    1601,  1605,  1610,  1614,  1618,  1622,  1627,  1631,  1635,  1639,
    1643,  1649,  1655,  1663,  1669,  1675,  1681,  1687,  1693,  1703,
    1708,  1713,  1718,  1723,  1727,  1735,  1748,  1758,  1759,  1763,
    1771,  1772,  1776,  1777,  1780,  1781,  1782,  1786,  1791
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PACKAGE", "IMPORT", "FUNC", "BREAK",
  "CASE", "CONST", "CONTINUE", "DEFAULT", "ELSE", "FOR", "GO", "IF",
  "RANGE", "RETURN", "STRUCT", "SWITCH", "TYPE", "VAR", "VAR_TYPE",
  "BOOL_CONST", "NIL_VAL", "IDENTIFIER", "BYTE", "STRING", "ELLIPSIS",
  "SHL", "SHR", "INC", "DEC", "INTEGER", "FLOAT", "ADD", "SUB", "MUL",
  "QUO", "REM", "ASSIGN", "AND", "NOT", "DEFINE", "AND_NOT", "OR", "XOR",
  "ARROW", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "QUO_ASSIGN",
  "REM_ASSIGN", "AND_ASSIGN", "OR_ASSIGN", "XOR_ASSIGN", "SHL_ASSIGN",
  "SHR_ASSIGN", "AND_NOT_ASSIGN", "COLON", "LAND", "LOR", "EQL", "NEQ",
  "LEQ", "GEQ", "SEMICOLON", "GTR", "LSS", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "LBRACK", "RBRACK", "COMMA", "PERIOD", "$accept", "StartFile",
  "Block", "OPENB", "CLOSEB", "StatementList", "Statement", "SimpleStmt",
  "EmptyStmt", "LabeledStmt", "Label", "IncDecStmt", "Assignment",
  "VarDecl", "VarSpec", "Declaration", "FunctionDecl", "FunctionName",
  "Function", "FunctionBody", "FunctionStmt", "FunctionCall",
  "ArgumentList", "Arguments", "Signature", "Result", "Parameters",
  "ParameterList", "ParameterDecl", "TypeList", "IdentifierList",
  "IdentifierLIST", "MethodDecl", "Receiver", "TopLevelDeclList",
  "TopLevelDecl", "TypeLit", "Type", "Operand", "OperandName",
  "ReturnStmt", "BreakStmt", "ContinueStmt", "IfStmt", "if_mark1",
  "if_mark2", "if_markend1", "if_mark22", "if_markend2", "if_markend",
  "ForStmt", "Condition", "ForClause", "InitStmt", "PostStmt",
  "for_clause_mark1", "for_clause_mark2", "for_clause_mark3", "for_mark22",
  "for_initmark", "for_mark1", "for_mark2", "for_markend1", "int_lit",
  "float_lit", "TypeName", "ArrayType", "ArrayLength", "StructType",
  "FieldDeclList", "FieldDecl", "Tag", "PointerType", "BaseType",
  "FunctionType", "ConstDecl", "ConstSpec", "ExpressionList", "TypeDecl",
  "TypeSpecList", "TypeSpec", "AliasDecl", "TypeDef", "Literal",
  "string_lit", "byte_lit", "BasicLit", "PrimaryExpr", "StructLiteral",
  "KeyValList", "Selector", "Index", "TypeAssertion", "Expression",
  "Expression1", "Expression2", "Expression3", "Expression4",
  "Expression5", "UnaryExpr", "rel_op", "add_op", "mul_op", "unary_op",
  "assign_op", "PackageClause", "PackageName", "ImportDeclList",
  "ImportDecl", "ImportSpecList", "ImportSpec", "ImportPath",
  "PackageName2", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330
};
# endif

#define YYPACT_NINF -247

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-247)))

#define YYTABLE_NINF -104

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      18,     5,   123,    28,  -247,  -247,  -247,   137,    -6,   161,
    -247,  -247,    -4,   117,  -247,    83,   117,     7,   151,    27,
     153,  -247,  -247,  -247,  -247,    92,  -247,  -247,  -247,  -247,
      13,   119,  -247,  -247,  -247,  -247,  -247,    -9,  -247,  -247,
     176,    49,  -247,    11,   179,  -247,  -247,  -247,   130,  -247,
      49,   177,  -247,   140,  -247,    49,  -247,   -31,  -247,    31,
     139,   139,   139,   138,  -247,  -247,    49,    74,  -247,   172,
    -247,  -247,  -247,  -247,  -247,    49,  -247,    -5,   147,   190,
     141,   178,  -247,  -247,  -247,  -247,    10,    49,  -247,  -247,
     150,     6,  -247,   150,  -247,   -10,  -247,  -247,  -247,  -247,
    -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,    74,  -247,
     154,  -247,  -247,   148,  -247,  -247,  -247,  -247,    50,  -247,
     173,   185,   164,    94,   251,  -247,   121,    74,  -247,  -247,
     167,  -247,  -247,   211,    74,  -247,  -247,  -247,  -247,  -247,
    -247,  -247,  -247,    49,  -247,  -247,  -247,    49,    16,   171,
     181,    74,  -247,    49,    74,    29,  -247,  -247,  -247,    74,
      74,  -247,  -247,  -247,  -247,  -247,  -247,    74,  -247,  -247,
    -247,  -247,    74,  -247,  -247,  -247,  -247,  -247,  -247,  -247,
     121,    50,  -247,  -247,  -247,   174,  -247,   284,    81,  -247,
     221,  -247,   187,  -247,  -247,    93,   196,  -247,   182,  -247,
      49,   185,   164,    94,   251,    50,    74,   234,   234,  -247,
    -247,    74,    -1,  -247,   237,   194,  -247,  -247,  -247,   202,
    -247,  -247,   222,  -247,  -247,  -247,  -247,  -247,  -247,  -247,
    -247,   112,    58,   168,  -247,    49,  -247,  -247,  -247,  -247,
      74,    74,  -247,   197,  -247,  -247,  -247,  -247,  -247,    74,
    -247,   121,   203,   200,  -247,   284,   121,  -247,  -247,  -247,
    -247,  -247,  -247,    74,   121,  -247,  -247,  -247,   209,  -247,
    -247,    74,   210,    82,  -247,    58,  -247,  -247,  -247,  -247,
     174,  -247,   114,  -247,    58,    74,  -247,  -247,   150,  -247,
      86,    74,   150,  -247,   121,  -247,   150,  -247,   216,  -247,
     257,  -247,  -247,  -247,    74,   150,  -247,   265,  -247,  -247,
    -247,  -247,   257,  -247,  -247,  -247,  -247,   218,  -247,   273,
      -2,  -247,    74,    -2,  -247,  -247,  -247,  -247,  -247,  -247,
    -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,   206,   205,     1,   209,     0,     0,
     208,   145,     0,     0,   218,     0,   216,     0,     0,     0,
       0,    33,    70,    71,    72,     2,    69,    31,    32,   207,
       0,     0,   217,   214,   210,   215,    36,     0,     4,    67,
       0,     0,   131,     0,     0,   136,   140,   141,    62,    28,
       0,     0,   211,     0,   213,     0,    51,     0,    54,     0,
       0,     0,     0,     0,   118,   117,     0,     0,    78,   133,
      77,    73,    74,    75,    76,     0,   143,     0,     0,     0,
      61,    30,    68,   212,    58,    52,     0,     0,    56,     5,
       5,    47,    65,    66,   130,     0,   129,   128,    82,   146,
     115,   116,   193,   194,   197,   198,   195,   196,     0,   151,
      80,   147,   148,     0,    79,   149,   150,   144,   174,   120,
     163,   165,   167,   169,   171,   173,     0,     0,   142,   137,
       0,   139,    64,     0,     0,    53,    55,    57,    34,     4,
      38,    35,    37,     0,    48,    50,   122,     0,     0,     0,
       0,   157,   155,     0,     0,     0,   152,   153,   154,     0,
       0,   176,   177,   179,   181,   180,   178,     0,   182,   183,
     184,   185,     0,   189,   190,   186,   187,   188,   191,   192,
       0,   175,   132,   138,    63,    29,   135,    22,     0,    60,
     125,   121,     0,   123,    81,     0,     0,   119,     0,   160,
       0,   164,   166,   168,   170,   172,     0,    86,    88,     4,
       4,    84,    82,    14,     5,     0,    10,    19,     9,     0,
      20,    21,    33,     8,    18,    17,    11,    12,    13,    15,
      16,     0,   174,   135,    49,     0,   127,   126,   124,   156,
       0,     0,   161,     0,   134,    24,    85,    87,   111,    22,
      83,     0,     0,     0,     7,    22,     0,   199,   200,   201,
     202,   203,   204,     0,    43,    25,    26,    59,     0,   158,
     162,    22,     0,   135,    40,     0,     3,     6,    23,    39,
      27,    46,     0,    44,    45,     0,   105,   112,     0,   107,
     135,     0,     0,    41,     0,   159,     0,   110,     0,    95,
      96,    42,   113,     5,     0,     0,     5,     0,     5,   114,
     108,   103,     5,    89,    98,   114,   102,     0,    90,     0,
       0,   101,    22,     0,    99,    99,   106,   109,     5,     5,
       5,     5,   104,    92,    91,   100,   100,    94,    93
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -247,  -247,   -86,  -129,   -90,  -247,  -137,  -246,  -247,  -247,
     -16,  -247,  -247,    35,  -247,    85,  -247,  -247,   224,  -247,
    -247,  -160,  -247,    -8,   133,  -247,   278,  -247,   213,  -247,
     -11,  -247,  -247,  -247,  -247,   246,  -247,   -42,  -247,  -247,
    -247,  -247,  -247,  -149,     2,  -247,     0,  -247,   -19,   -25,
    -247,     9,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,
    -247,  -247,     8,  -247,  -247,  -247,  -247,  -247,  -247,  -247,
     166,  -247,  -247,  -247,  -247,  -247,  -247,  -128,  -247,  -247,
     -18,  -247,  -247,  -247,   160,  -247,  -247,  -124,  -247,  -247,
    -247,  -247,  -247,   -62,  -247,   156,   162,   159,   149,  -247,
    -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,   318,  -247,
      90,   312,  -247
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,   213,    60,   138,   214,   215,   216,   217,   218,
     219,   220,   221,   222,    49,   223,    23,    38,    89,   142,
     224,   225,   282,   283,    90,   144,    91,    57,    58,   188,
      59,    80,    24,    40,    25,    26,    68,    69,   109,   110,
     226,   227,   228,   229,   292,   306,   307,   320,   330,   337,
     230,   287,   288,   289,   327,   298,   317,   332,   303,   271,
     296,   308,   316,   111,   112,    70,    71,   113,    72,   148,
     149,   237,    73,    97,    74,    27,    42,   231,    28,    77,
      45,    46,    47,   114,   115,   116,   117,   118,   152,   195,
     156,   157,   158,   233,   120,   121,   122,   123,   124,   125,
     167,   172,   180,   126,   263,     3,     5,     9,    10,    30,
      15,    33,    16
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     141,    76,   181,   272,   140,   119,   185,   140,    81,    50,
     187,    62,   210,    84,    48,    48,    62,    88,    55,    43,
      11,     1,    11,    63,    96,   286,    78,    64,    63,     4,
      65,    36,    64,   128,    48,    65,    62,    55,    85,    11,
      48,   251,    66,    86,    21,   137,   150,    66,    63,   145,
      75,    43,    64,   199,    62,    65,   205,   -24,    87,   130,
      56,   146,    12,   232,   129,   182,    63,    66,   139,    13,
      64,    13,   186,    65,   143,    37,   326,   253,    67,   135,
     248,   249,    52,    67,   147,    66,    21,   191,    13,   196,
     232,   274,   198,     7,    22,    44,   279,   200,    98,    99,
      11,   189,    31,    67,   281,   190,   100,   101,   102,   103,
     104,   197,   265,   266,   105,   106,   265,   266,   278,   107,
      53,    67,   154,     6,   252,   155,   264,   275,   168,   169,
     154,   232,   275,   155,   281,   280,    22,   147,   170,   171,
     284,     8,   108,    11,   244,    98,    99,    11,    34,   250,
     234,   257,   -95,   100,   101,   235,  -103,    51,   243,   258,
     259,   260,   261,   262,   239,     8,    17,   240,    14,    18,
     284,   325,    14,    32,   329,    41,    32,    48,   268,   269,
      19,    20,    17,   293,    54,    18,   206,   273,   294,   108,
      14,   246,   247,   267,    93,    94,    19,    20,   265,   266,
      61,   186,   297,    43,    79,    83,   300,    37,    95,   290,
     302,   127,   131,   309,   132,   133,   313,   134,   315,   312,
     139,   153,   318,   295,   151,   161,   162,   163,   164,   299,
     165,   166,   183,   159,   324,   184,   193,   328,   333,   334,
     335,   336,   311,   207,   160,    18,   208,   236,   206,   209,
     194,   210,   238,   211,   241,   242,    19,    20,   245,   254,
     255,   212,    99,    11,   256,   277,   270,   285,   -97,   100,
     101,   102,   103,   104,   276,   291,   314,   105,   106,   173,
     174,   304,   107,   322,   323,    92,   301,   175,   176,   177,
     207,   178,    18,   208,   179,    39,   209,    82,   210,   136,
     211,   305,   -22,    19,    20,   108,   331,   139,   212,    99,
      11,   338,   319,   310,   192,   201,   100,   101,   102,   103,
     104,   204,   202,   321,   105,   106,   203,    29,    35,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   108,     0,   139
};

static const yytype_int16 yycheck[] =
{
      90,    43,   126,   249,    90,    67,   134,    93,    50,    20,
     139,     5,    14,    55,    24,    24,     5,    59,    27,    24,
      26,     3,    26,    17,    66,   271,    44,    21,    17,    24,
      24,    24,    21,    75,    24,    24,     5,    27,    69,    26,
      24,    42,    36,    74,     9,    87,   108,    36,    17,    91,
      39,    24,    21,    24,     5,    24,   180,    58,    27,    77,
      69,    71,    68,   187,    69,   127,    17,    36,    70,    75,
      21,    75,   134,    24,    68,    68,   322,   214,    72,    69,
     209,   210,    69,    72,    95,    36,    51,    71,    75,   151,
     214,   251,   154,    65,     9,    68,   256,    68,    24,    25,
      26,   143,    12,    72,   264,   147,    32,    33,    34,    35,
      36,   153,    30,    31,    40,    41,    30,    31,   255,    45,
      30,    72,    72,     0,   214,    75,    68,   251,    34,    35,
      72,   255,   256,    75,   294,   263,    51,   148,    44,    45,
     264,     4,    68,    26,   206,    24,    25,    26,    65,   211,
      69,    39,    70,    32,    33,    74,    70,    65,   200,    47,
      48,    49,    50,    51,    71,     4,     5,    74,     8,     8,
     294,   320,    12,    13,   323,    24,    16,    24,   240,   241,
      19,    20,     5,    69,    65,     8,    74,   249,    74,    68,
      30,   207,   208,   235,    61,    62,    19,    20,    30,    31,
      24,   263,   288,    24,    74,    65,   292,    68,    70,   271,
     296,    39,    65,   303,    24,    74,   306,    39,   308,   305,
      70,    73,   312,   285,    70,    61,    62,    63,    64,   291,
      66,    67,    65,    60,   320,    24,    65,   323,   328,   329,
     330,   331,   304,     6,    59,     8,     9,    26,    74,    12,
      69,    14,    65,    16,    58,    73,    19,    20,    24,    65,
      58,    24,    25,    26,    42,    65,    69,    58,    11,    32,
      33,    34,    35,    36,    71,    65,    11,    40,    41,    28,
      29,    65,    45,    65,    11,    61,   294,    36,    37,    38,
       6,    40,     8,     9,    43,    17,    12,    51,    14,    86,
      16,   299,    65,    19,    20,    68,   325,    70,    24,    25,
      26,   336,   312,   304,   148,   159,    32,    33,    34,    35,
      36,   172,   160,   315,    40,    41,   167,     9,    16,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    70
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    77,   181,    24,   182,     0,    65,     4,   183,
     184,    26,    68,    75,   160,   186,   188,     5,     8,    19,
      20,    89,    91,    92,   108,   110,   111,   151,   154,   184,
     185,   186,   160,   187,    65,   187,    24,    68,    93,   102,
     109,    24,   152,    24,    68,   156,   157,   158,    24,    90,
     106,    65,    69,   186,    65,    27,    69,   103,   104,   106,
      79,    24,     5,    17,    21,    24,    36,    72,   112,   113,
     141,   142,   144,   148,   150,    39,   113,   155,   156,    74,
     107,   113,   111,    65,   113,    69,    74,    27,   113,    94,
     100,   102,    94,   100,   100,    70,   113,   149,    24,    25,
      32,    33,    34,    35,    36,    40,    41,    45,    68,   114,
     115,   139,   140,   143,   159,   160,   161,   162,   163,   169,
     170,   171,   172,   173,   174,   175,   179,    39,   113,    69,
     156,    65,    24,    74,    39,    69,   104,   113,    80,    70,
      78,    80,    95,    68,   101,   113,    71,   106,   145,   146,
     169,    70,   164,    73,    72,    75,   166,   167,   168,    60,
      59,    61,    62,    63,    64,    66,    67,   176,    34,    35,
      44,    45,   177,    28,    29,    36,    37,    38,    40,    43,
     178,   163,   169,    65,    24,   153,   169,    79,   105,   113,
     113,    71,   146,    65,    69,   165,   169,   113,   169,    24,
      68,   171,   172,   173,   174,   163,    74,     6,     9,    12,
      14,    16,    24,    78,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    91,    96,    97,   116,   117,   118,   119,
     126,   153,   163,   169,    69,    74,    26,   147,    65,    71,
      74,    58,    73,   113,   169,    24,    86,    86,    79,    79,
     169,    42,    80,    82,    65,    58,    42,    39,    47,    48,
      49,    50,    51,   180,    68,    30,    31,   113,   169,   169,
      69,   135,    83,   169,    97,   163,    71,    65,    82,    97,
     153,    97,    98,    99,   163,    58,    83,   127,   128,   129,
     169,    65,   120,    69,    74,   169,   136,    78,   131,   169,
      78,    99,    78,   134,    65,   120,   121,   122,   137,    80,
     127,   169,    78,    80,    11,    80,   138,   132,    80,   122,
     123,   138,    65,    11,    78,   119,    83,   130,    78,   119,
     124,   124,   133,    80,    80,    80,    80,   125,   125
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    76,    77,    78,    79,    80,    81,    81,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    83,
      83,    83,    84,    85,    86,    87,    87,    88,    89,    90,
      90,    91,    91,    91,    92,    92,    93,    94,    95,    96,
      96,    97,    98,    98,    98,    99,    99,   100,   100,   101,
     101,   102,   102,   102,   103,   103,   104,   104,   104,   105,
     105,   106,   106,   107,   107,   108,   108,   109,   110,   110,
     111,   111,   111,   112,   112,   112,   112,   113,   113,   114,
     114,   114,   115,   116,   116,   117,   117,   118,   118,   119,
     119,   119,   119,   119,   119,   120,   121,   122,   123,   124,
     125,   126,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   141,   142,
     143,   144,   144,   145,   145,   146,   146,   147,   148,   149,
     150,   151,   152,   152,   153,   153,   154,   154,   155,   155,
     156,   156,   157,   158,   159,   160,   161,   162,   162,   162,
     162,   163,   163,   163,   163,   163,   164,   165,   165,   165,
     166,   167,   168,   169,   170,   170,   171,   171,   172,   172,
     173,   173,   174,   174,   175,   175,   176,   176,   176,   176,
     176,   176,   177,   177,   177,   177,   178,   178,   178,   178,
     178,   178,   178,   179,   179,   179,   179,   179,   179,   180,
     180,   180,   180,   180,   180,   181,   182,   183,   183,   183,
     184,   184,   185,   185,   186,   186,   186,   187,   188
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     5,     0,     0,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     3,     1,     2,     2,     3,     2,     4,
       2,     1,     1,     1,     5,     5,     1,     2,     1,     3,
       3,     4,     3,     0,     1,     1,     1,     1,     2,     3,
       1,     2,     3,     4,     1,     3,     2,     3,     2,     3,
       1,     2,     1,     3,     2,     4,     4,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     2,     1,     2,     1,     2,     1,     7,
       8,    11,    11,    12,    12,     0,     0,     0,     0,     0,
       0,     9,     8,     1,     8,     1,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     1,     1,     1,     4,
       1,     4,     3,     2,     3,     2,     3,     1,     2,     1,
       2,     2,     4,     2,     3,     1,     2,     4,     3,     2,
       1,     1,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     3,     0,     3,     5,
       2,     3,     4,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     2,     1,     0,
       3,     4,     3,     2,     2,     2,     1,     1,     1
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
#line 153 "src/parserIR.y" /* yacc.c:1646  */
    {
    	lhs.push_back("StartFile");rhs.push_back("PackageClause SEMICOLON ImportDeclList TopLevelDeclList");
    	//cout << "---" << $1- << endl;// << "---" << $3 << "---";
    }
#line 1671 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 160 "src/parserIR.y" /* yacc.c:1646  */
    {
	lhs.push_back("Block");rhs.push_back("LBRACE OPENB StatementList CLOSEB RBRACE");
	(yyval.nt)=(yyvsp[-2].nt);
	}
#line 1680 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 181 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("OPENB");rhs.push_back("/*empty*/");
	symboltable* sym_ptr = new_symboltable();
	table * t1 = new_table(sym_ptr,curr);
	curr = t1;
	
	}
#line 1691 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 190 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("CLOSEB");rhs.push_back("/*empty*/");
	//$$->value=NULL;
	curr = curr->parent;
	}
#line 1700 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 197 "src/parserIR.y" /* yacc.c:1646  */
    {
    lhs.push_back("StatementList");rhs.push_back("StatementList Statement SEMICOLON");
    
    }
#line 1709 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 201 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("StatementList");rhs.push_back("Statement SEMICOLON");/*;printf("got a statement");*/
      (yyval.nt)=(yyvsp[-1].nt); 	
    }
#line 1717 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 207 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("Statement");rhs.push_back("Declaration");}
#line 1723 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 208 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("Statement");rhs.push_back("LabeledStmt");
	 	 //unimplemented - no need
	}
#line 1731 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 211 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("Statement");rhs.push_back("SimpleStmt");
	 	 (yyval.nt)=(yyvsp[0].nt);
	 }
#line 1739 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 214 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("Statement");rhs.push_back("ReturnStmt");
		 (yyval.nt)=(yyvsp[0].nt);	
	}
#line 1747 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 217 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("Statement");rhs.push_back("BreakStmt");}
#line 1753 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 218 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("Statement");rhs.push_back("ContinueStmt");}
#line 1759 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 219 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("Statement");rhs.push_back("Block");
	 	(yyval.nt)=(yyvsp[0].nt);
	}
#line 1767 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 222 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("Statement");rhs.push_back("IfStmt");
	 	(yyval.nt)=(yyvsp[0].nt);
	}
#line 1775 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 225 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("Statement");rhs.push_back("ForStmt");
	 	(yyval.nt)=(yyvsp[0].nt);
	}
#line 1783 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 228 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("Statement");rhs.push_back("FunctionCall");
	 	(yyval.nt)=(yyvsp[0].nt);
	}
#line 1791 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 231 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("Statement");rhs.push_back("FunctionStmt");
	 //$$=$1;
	}
#line 1799 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 236 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("SimpleStmt");rhs.push_back("EmptyStmt");}
#line 1805 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 237 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("SimpleStmt");rhs.push_back("IncDecStmt");}
#line 1811 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 238 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("SimpleStmt");rhs.push_back("Assignment");
	  (yyval.nt)=(yyvsp[0].nt);}
#line 1818 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 243 "src/parserIR.y" /* yacc.c:1646  */
    {
	lhs.push_back("EmptyStmt");rhs.push_back("/*empty*/");
	//nothing
	}
#line 1827 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 252 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("LabeledStmt");rhs.push_back("Label COLON Statement");}
#line 1833 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 254 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("Label");rhs.push_back("IDENTIFIER");}
#line 1842 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 262 "src/parserIR.y" /* yacc.c:1646  */
    {
	lhs.push_back("IncDecStmt");rhs.push_back("Expression INC");
	string tac;
	tac.append(to_string(lineno));
	tac.append(",");
	tac.append("+");
	tac.append(",");
	tac.append((yyvsp[-1].nt)->value);
	tac.append(",");
	tac.append((yyvsp[-1].nt)->value);
	tac.append(",");
	tac.append("1");
	tac.append("\n");
	prog.push_back(tac);
	lineno++;
	}
#line 1863 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 278 "src/parserIR.y" /* yacc.c:1646  */
    {
	string tac;
	tac.append(to_string(lineno));
	tac.append(",");
	tac.append("-");
	tac.append(",");
	tac.append((yyvsp[-1].nt)->value);
	tac.append(",");
	tac.append((yyvsp[-1].nt)->value);
	tac.append(",");
	tac.append("1");
	tac.append("\n");
	prog.push_back(tac);
	lineno++;
	lhs.push_back("IncDecStmt");rhs.push_back("Expression DEC");
	
	}
#line 1885 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 297 "src/parserIR.y" /* yacc.c:1646  */
    {
		lhs.push_back("Assignment");rhs.push_back("ExpressionList assign_op ExpressionList");
		//$$=$1; 
		string temp_str = (yyvsp[-2].nt)->value;
		vector <string> vec_expr_list1 = split(temp_str, ',');
		string temp_str2 = (yyvsp[0].nt)->value;
		vector <string> vec_expr_list2 = split(temp_str2, ',');
		if(vec_expr_list1.size()!= vec_expr_list2.size()){
		//pass as yyerror
		cout<<"ERROR : Unequal # of expressions on LHS "<<vec_expr_list1.size()<<" & RHS "<<vec_expr_list2.size()<<endl;
		}
		else{
			//TODO array checking - use lindex and rindex - use some global function
			
			//checking operator
			string op_used = (yyvsp[-1].nt)->value;
			if(op_used=="="){
				op_used = (yyvsp[-1].nt)->value;
				for(int i=0;i<vec_expr_list1.size();i++){
					string tac;
					tac.append(to_string(lineno));
					tac.append(",");
					tac.append(op_used);
					tac.append(",");
					tac.append(vec_expr_list1[i]);
					tac.append(",");
					tac.append(vec_expr_list2[i]);
					tac.append("\n");
					prog.push_back(tac);
					lineno++;
				}
			}
			else {
				if(op_used=="+="){
					op_used = "+";
				}
				else if(op_used=="*="){
					op_used = "*";
				}
				else if(op_used=="-="){
					op_used = "-";
				}
				else if(op_used=="/="){
					op_used = "/";
				}
				else if(op_used=="%="){
					op_used = "%";
				}
				
				for(int i=0;i<vec_expr_list1.size();i++){
					string tac;
					tac.append(to_string(lineno));
					tac.append(",");
					tac.append(op_used);
					tac.append(",");
					tac.append(vec_expr_list1[i]);
					tac.append(",");
					tac.append(vec_expr_list1[i]);
					tac.append(",");
					tac.append(vec_expr_list2[i]);
					tac.append("\n");
					prog.push_back(tac);
					lineno++;
				}
			}
		
			//till here
		}
	}
#line 1959 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 369 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("VarDecl");rhs.push_back("VAR VarSpec");
			//symbol table
			(yyval.nt)=(yyvsp[0].nt);
		}
#line 1968 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 375 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("VarSpec");rhs.push_back("IdentifierList Type ASSIGN ExpressionList");
			//symbol table (also lookup if already exist) + insructions
			//update symtable using $2
			//check arrays - no arrays with assign allowed
			//loc1
			string temp_str = (yyvsp[-3].nt)->value;
			vector <string> vec_identifier_list = split(temp_str, ',');
			string temp_str2 = (yyvsp[0].nt)->value;
			vector <string> vec_expr_list = split(temp_str2, ',');
			if(vec_identifier_list.size()!= vec_expr_list.size()){
			cout<<"ERROR : Unequal # of expressions on LHS "<<vec_identifier_list.size()<<" & RHS "<<vec_expr_list.size()<<endl;
			}
			else{
				for(int i=0;i<vec_identifier_list.size();i++){
					string tac;
					tac.append(to_string(lineno));
					tac.append(",");
					tac.append((yyvsp[-1].sval));
					tac.append(",");
					tac.append(vec_identifier_list[i]);
					tac.append(",");
					tac.append(vec_expr_list[i]);
					tac.append("\n");
					prog.push_back(tac);
					lineno++;
				}
				//insert in symbol table
				for(int i=0;i<vec_identifier_list.size();i++){
					insert(vec_identifier_list[i],curr,(yyvsp[-2].nt)->value);
				}
			}
		}
#line 2005 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 407 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("VarSpec");rhs.push_back("IdentifierList Type");
			//symbol table			
			//array declaration
			//varspec contains variable names
			string temp_str1 = (yyvsp[-1].nt)->value;
			string temp_str2 = (yyvsp[0].nt)->value;
			
			//if array
			char temp_char = temp_str2[0];
			if(temp_char=='['){
				int i_temp=1;
				while(temp_str2[i_temp]!=']'){
					i_temp=i_temp+1;
				}	
				string length_temp = temp_str2.substr(1,i_temp-1);
				string tac = to_string(lineno);
				tac.append(",array,");
				tac.append((yyvsp[-1].nt)->value);
				tac.append(",");
				tac.append(length_temp);
				tac.append("\n");
				prog.push_back(tac);
				lineno++;
				insert((yyvsp[-1].nt)->value,curr,(yyvsp[0].nt)->value);	//TODO array
				//curr->symtab[vec_identifier_list[i]].type = $2->value;
			}
			else{
				string temp_str = (yyvsp[-1].nt)->value;
				vector <string> vec_identifier_list = split(temp_str, ',');
				for(int i=0;i<vec_identifier_list.size();i++){
					insert(vec_identifier_list[i],curr,(yyvsp[0].nt)->value);
				}
			}
			
			//insert in symbol table
			//propagating upwards
		}
#line 2047 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 448 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("Declaration");rhs.push_back("ConstDecl");(yyval.nt)=(yyvsp[0].nt);
		//unimplemented
	}
#line 2055 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 451 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("Declaration");rhs.push_back("TypeDecl");
		//unimplemented for now - OOPS - to do afterwards
	}
#line 2063 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 454 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("Declaration");rhs.push_back("VarDecl");(yyval.nt)=(yyvsp[0].nt);}
#line 2069 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 458 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("FunctionDecl");rhs.push_back("FUNC FunctionName OPENB Function CLOSEB");
			//TODO
			//symbol table
			prog.push_back(to_string(lineno)+",exit\n");
			lineno++;
			(yyval.nt)=(yyvsp[-3].nt);	//for now
		}
#line 2081 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 465 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("FunctionDecl");rhs.push_back("FUNC FunctionName OPENB Signature CLOSEB");
		}
#line 2088 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 468 "src/parserIR.y" /* yacc.c:1646  */
    {
		    	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
		    	(yyvsp[0].sval)=(*(yyval.nt)).value;
		    	string temp_str = (yyvsp[0].sval);
		    	lhs.push_back("FunctionName");rhs.push_back("IDENTIFIER");
		    	string tac = to_string(lineno);
			tac.append(",function,");
			tac.append((yyvsp[0].sval));
			tac.append("\n");
			prog.push_back(tac);
			lineno++;
			//insert in symbol table
			//$1=(*$$).value;
			
			string type_temp = "function";
			insert(temp_str,curr,type_temp);
		}
#line 2110 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 486 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("Function");rhs.push_back("Signature FunctionBody");
		(yyval.nt)=(yyvsp[0].nt);
		}
#line 2118 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 490 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("FunctionBody");rhs.push_back("Block");
		(yyval.nt)=(yyvsp[0].nt);}
#line 2125 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 495 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("FunctionStmt");rhs.push_back("VarDecl DEFINE FunctionCall");
			
			//symbol table updation & typecheck
			//multiple return values not implemented - only a := f(a,b,c)
			//TODO function inside arguments
			string tac;
			tac.append(to_string(lineno));
			tac.append(",");
			tac = tac + "getreturn,"; 
			tac.append((yyvsp[-2].nt)->value);
			tac.append("\n");
			prog.push_back(tac);
			lineno++;
			//pass to $$

		}
#line 2146 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 512 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("FunctionStmt");rhs.push_back("IDENTIFIER DEFINE FunctionCall");
			
			//check
			check_entry((yyvsp[-2].sval),curr);
			
			string tac;
			tac.append(to_string(lineno));
			tac.append(",");
			tac = tac + "getreturn,"; 
			tac.append((yyvsp[-2].sval));
			tac.append("\n");
			prog.push_back(tac);
			lineno++;
		}
#line 2165 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 531 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("FunctionCall");rhs.push_back("PrimaryExpr LPAREN ArgumentList RPAREN");
		//PrimaryExpr contains name of function
		string str1 = strdup((yyvsp[-3].nt)->value);
		string str2 = "print";
		string str3 = "fmt.Println";
		if(is_argument_list_empty.top()!=1){
			string temp_str = (yyvsp[-1].nt)->value;
			vector <string> vec_arguments = split(temp_str, ',');
			if(str1!= str2 && str1!=str3){
				//param here
				for(int i=0;i<vec_arguments.size();i++){
					string tac;
					tac.append(to_string(lineno));
					tac.append(",");
					tac = tac + "param,"; 
					tac.append(vec_arguments[i]);
					tac.append("\n");
					prog.push_back(tac);
					lineno++;
				}
				string tac;
				tac.append(to_string(lineno));
				tac.append(",");
				tac = tac + "call,"; 
				tac.append((yyvsp[-3].nt)->value);
				tac.append(",");
				tac.append(to_string(vec_arguments.size()));
				tac.append("\n");
				prog.push_back(tac);
				lineno++;
			} else {
				//printing part
				for(int i=0;i<vec_arguments.size();i++){
					string tac;
					tac.append(to_string(lineno));
					tac.append(",");
					tac = tac + "print,"; 
					tac.append(vec_arguments[i]);
					tac.append("\n");
					prog.push_back(tac);
					lineno++;
				}
			}	
		} else{
			is_argument_list_empty.pop();
			string tac;
			tac.append(to_string(lineno));
			tac.append(",");
			tac = tac + "call,"; 
			tac.append((yyvsp[-3].nt)->value);
			tac.append(",");
			tac.append("0");
			tac.append("\n");
			prog.push_back(tac);
			lineno++;
		
		}
}
#line 2228 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 592 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ArgumentList");rhs.push_back("ArgumentList COMMA Arguments");
			argumentlist_str = (yyvsp[-2].nt)->value;
			argumentlist_str.append(",");
			argumentlist_str.append((yyvsp[0].nt)->value);
			(*(yyval.nt)).value = strdup(argumentlist_str.c_str());
			//only identifiers or variables allowed - no expressions
			
		}
#line 2241 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 600 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ArgumentList");rhs.push_back("/*empty*/");
			is_argument_list_empty.push(1);
		}
#line 2249 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 603 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ArgumentList");rhs.push_back("Arguments");
			(yyval.nt)=(yyvsp[0].nt);
		}
#line 2257 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 608 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("Arguments");rhs.push_back("PrimaryExpr");}
#line 2263 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 609 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("Arguments");rhs.push_back("FunctionCall");}
#line 2269 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 615 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("Signature");rhs.push_back("Parameters");
		(yyval.nt)=(yyvsp[0].nt);
	}
#line 2277 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 618 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("Signature");rhs.push_back("Parameters Result");
		//loc2
		//symbol table here
	}
#line 2286 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 625 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("Result");rhs.push_back("LPAREN TypeList RPAREN");
		//unimplemented
		//one return to return them all
	}
#line 2295 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 629 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("Result");rhs.push_back("Type");
		//set symbol table 
		(yyval.nt)=(yyvsp[0].nt);	
	}
#line 2304 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 635 "src/parserIR.y" /* yacc.c:1646  */
    { 
	lhs.push_back("Parameters");rhs.push_back("LPAREN RPAREN");
		(yyval.nt)->value = strdup("");
	}
#line 2313 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 639 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("Parameters");rhs.push_back("LPAREN ParameterList RPAREN");
		string temp_str = (yyvsp[-1].nt)->value;
		vector <string> vec_params = split(temp_str, ',');
		for(int i= vec_params.size()-1;i>=0;i--){
			string tac = to_string(lineno);
			tac.append(",pop,");
			tac.append(vec_params[i]);
			tac.append("\n");
			prog.push_back(tac);
			lineno++;
		}
		
	}
#line 2331 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 652 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("Parameters");rhs.push_back("LPAREN ParameterList COMMA RPAREN");
		//why???
		//unimplemented
	}
#line 2340 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 658 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ParameterList");rhs.push_back("ParameterDecl");
		(yyval.nt)=(yyvsp[0].nt);
	}
#line 2348 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 661 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ParameterList");rhs.push_back("ParameterList COMMA ParameterDecl");
		string temp_str = (yyvsp[-2].nt)->value;
		temp_str.append(",");
		temp_str.append((yyvsp[0].nt)->value);
		(*(yyval.nt)).value = strdup(temp_str.c_str());
	}
#line 2359 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 672 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ParameterDecl");rhs.push_back("IdentifierList Type");
		//symbol table
		(yyval.nt)=(yyvsp[-1].nt);
		string temp_str = (yyvsp[-1].nt)->value;
		vector <string> vec_param_list = split(temp_str, ',');
		for(int i=0;i<vec_param_list.size();i++){
			insert(vec_param_list[i],curr,(yyvsp[0].nt)->value);
		}
		
	}
#line 2374 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 682 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ParameterDecl");rhs.push_back("IdentifierList ELLIPSIS  Type");
		//unimplemented
	}
#line 2382 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 685 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ParameterDecl");rhs.push_back("ELLIPSIS Type");
		//unimplemented
	}
#line 2390 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 691 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("TypeList");rhs.push_back("TypeList COMMA Type");
    		//TODO
    }
#line 2398 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 694 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("TypeList");rhs.push_back("Type");
    		(yyval.nt)=(yyvsp[0].nt);
    }
#line 2406 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 702 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("IdentifierList");rhs.push_back("IDENTIFIER IdentifierLIST");
			string temp_str = (yyvsp[-1].sval);
			temp_str.append((yyvsp[0].nt)->value);
			(*(yyval.nt)).value = strdup(temp_str.c_str());
		}
#line 2416 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 707 "src/parserIR.y" /* yacc.c:1646  */
    {
			//check	NOT
			(*(yyval.nt)).value=strdup((yyvsp[0].sval));
			(yyvsp[0].sval)=(*(yyval.nt)).value;
			lhs.push_back("IdentifierList");rhs.push_back("IDENTIFIER");}
#line 2426 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 714 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("IdentifierLIST");rhs.push_back("IdentifierLIST COMMA IDENTIFIER");
			string temp_str = (yyvsp[-2].nt)->value;
			temp_str.append(",");
			temp_str.append((yyvsp[0].sval));
			(*(yyval.nt)).value = strdup(temp_str.c_str());
		
		}
#line 2438 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 721 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("IdentifierLIST");rhs.push_back("COMMA IDENTIFIER");
			string temp_str = ",";
			temp_str.append((yyvsp[0].sval));
			(*(yyval.nt)).value = strdup(temp_str.c_str());
		
		}
#line 2449 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 734 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("MethodDecl");rhs.push_back("FUNC Receiver IDENTIFIER Function");}
#line 2455 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 735 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("MethodDecl");rhs.push_back("FUNC Receiver IDENTIFIER Signature");}
#line 2461 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 739 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("Receiver");rhs.push_back("Parameters");}
#line 2467 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 742 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("TopLevelDeclList");rhs.push_back("TopLevelDeclList SEMICOLON  TopLevelDecl");}
#line 2473 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 743 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("TopLevelDeclList");rhs.push_back("TopLevelDecl");
      (yyval.nt)=(yyvsp[0].nt);}
#line 2480 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 748 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("TopLevelDecl");rhs.push_back("Declaration");
		//normal declaration for global variables
		(yyval.nt)=(yyvsp[0].nt);
	}
#line 2489 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 752 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("TopLevelDecl");rhs.push_back("FunctionDecl");
	  	(yyval.nt)=(yyvsp[0].nt);
	  
	  }
#line 2498 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 756 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("TopLevelDecl");rhs.push_back("MethodDecl");
		//unimplemented for now
	}
#line 2506 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 762 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("TypeLit");rhs.push_back("ArrayType");
		(yyval.nt)=(yyvsp[0].nt);
	}
#line 2514 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 765 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("TypeLit");rhs.push_back("StructType");
		//unimplemented for now TODO
	}
#line 2522 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 768 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("TypeLit");rhs.push_back("PointerType");}
#line 2528 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 769 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("TypeLit");rhs.push_back("FunctionType");}
#line 2534 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 776 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("Type");rhs.push_back("TypeName");}
#line 2540 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 777 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("Type");rhs.push_back("TypeLit");}
#line 2546 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 781 "src/parserIR.y" /* yacc.c:1646  */
    {
	lhs.push_back("Operand");rhs.push_back("Literal");
	//cout << "here\n";
	(yyval.nt)=(yyvsp[0].nt);
	}
#line 2556 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 786 "src/parserIR.y" /* yacc.c:1646  */
    {
	lhs.push_back("Operand");rhs.push_back("OperandName");
	(yyval.nt)=(yyvsp[0].nt);
	}
#line 2565 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 790 "src/parserIR.y" /* yacc.c:1646  */
    {
	lhs.push_back("Operand");rhs.push_back("LPAREN Expression RPAREN");
	(yyval.nt)=(yyvsp[-1].nt);
	}
#line 2574 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 796 "src/parserIR.y" /* yacc.c:1646  */
    {
	lhs.push_back("OperandName");rhs.push_back("IDENTIFIER");
	//check
	check_entry((yyvsp[0].sval),curr);
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	}
#line 2586 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 806 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ReturnStmt");rhs.push_back("RETURN Expression");
		string tac = to_string(lineno);
		tac.append(",return,");
		tac.append((yyvsp[0].nt)->value);
		tac.append("\n");
		prog.push_back(tac);
		lineno++;
		(yyval.nt)=(yyvsp[0].nt);
	}
#line 2600 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 815 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ReturnStmt");rhs.push_back("RETURN");
		//TODO
		string tac = to_string(lineno);
		tac.append(",exit\n");
		prog.push_back(tac);
		lineno++;
		(yyval.nt)->value = strdup("");
	}
#line 2613 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 825 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("BreakStmt");rhs.push_back("BREAK Label");
		//unimplemented
	}
#line 2621 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 828 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("BreakStmt");rhs.push_back("BREAK");
		string tac = to_string(lineno);
		tac.append(",goto,");
		tac.append(for_endlabels.top());
		tac.append("\n");
		prog.push_back(tac);
		lineno++;
	}
#line 2634 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 838 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ContinueStmt");rhs.push_back("CONTINUE Label");
		//unimplemented
	}
#line 2642 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 841 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ContinueStmt");rhs.push_back("CONTINUE");
		string tac = to_string(lineno);
		tac.append(",goto,");
		tac.append(for_continuelabels.top());
		tac.append("\n");
		prog.push_back(tac);
		lineno++;
	}
#line 2655 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 852 "src/parserIR.y" /* yacc.c:1646  */
    {
	lhs.push_back("IfStmt");rhs.push_back("IF OPENB Expression Block CLOSEB");
	}
#line 2663 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 855 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("IfStmt");rhs.push_back("IF OPENB SimpleStmt SEMICOLON Expression Block CLOSEB");}
#line 2669 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 856 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("IfStmt");rhs.push_back("IF OPENB SimpleStmt SEMICOLON Expression Block ELSE IfStmt CLOSEB");}
#line 2675 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 857 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("IfStmt");rhs.push_back("IF OPENB SimpleStmt SEMICOLON Expression Block ELSE  Block CLOSEB");}
#line 2681 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 858 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("IfStmt");rhs.push_back("IF OPENB Expression Block ELSE IfStmt CLOSEB");}
#line 2687 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 859 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("IfStmt");rhs.push_back("IF OPENB Expression Block ELSE  Block CLOSEB");}
#line 2693 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 862 "src/parserIR.y" /* yacc.c:1646  */
    {
		string tac;
		tac.append(to_string(lineno));
		tac.append(",");
		tac.append("ifgoto,=,");
		string togo_label = get_label();
		tac.append("t"+to_string(tempno-1)+",1,"+togo_label+"\n");
		prog.push_back(tac);
		lineno++;
		//
		tac=to_string(lineno);
		tac.append(",");
		tac.append("goto,");
		string topush_label = get_label();
		if_bwlabels.push(topush_label);
		tac.append(topush_label+"\n");//TO correct
		prog.push_back(tac);
		lineno++;
		//
		tac=to_string(lineno);
		tac.append(",");
		tac.append("label,");
		tac.append(togo_label+"\n");//TO correct
		prog.push_back(tac);
		lineno++;
	}
#line 2724 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 889 "src/parserIR.y" /* yacc.c:1646  */
    {	//
		//
		string tac;
		tac=to_string(lineno);
		tac.append(",");
		tac.append("label,");
		string toget_label = if_bwlabels.top();
		if_bwlabels.pop();
		tac.append(toget_label+"\n");//TO correct
		prog.push_back(tac);
		lineno++;		
	}
#line 2741 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 904 "src/parserIR.y" /* yacc.c:1646  */
    {
		string tac;
		//
		tac=to_string(lineno);
		tac.append(",");
		tac.append("goto,");
		string topush_label = get_label();
		if_endlabels.push(topush_label);
		tac.append(topush_label+"\n");//TO correct
		prog.push_back(tac);
		lineno++;
		//
	}
#line 2759 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 918 "src/parserIR.y" /* yacc.c:1646  */
    {
		string tac;
		tac=to_string(lineno);
		tac.append(",");
		tac.append("label,");
		string toget_label = if_bwlabels.top();
		if_bwlabels.pop();
		tac.append(toget_label+"\n");//TO correct
		prog.push_back(tac);
		lineno++;
	}
#line 2775 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 930 "src/parserIR.y" /* yacc.c:1646  */
    {
		string tac;
		tac=to_string(lineno);
		tac.append(",");
		tac.append("goto,");
		string toget_label = if_endlabels.top();
		tac.append(toget_label+"\n");//TO correct
		prog.push_back(tac);
		lineno++;
	}
#line 2790 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 940 "src/parserIR.y" /* yacc.c:1646  */
    {
		string tac;
		tac=to_string(lineno);
		tac.append(",");
		tac.append("label,");
		string togo_label = if_endlabels.top();	//top of second stack
		if_endlabels.pop();				//pop here
		tac.append(togo_label+"\n");//TO correct
		prog.push_back(tac);
		lineno++;
	}
#line 2806 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 955 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ForStmt");rhs.push_back("FOR OPENB Condition Block CLOSEB");}
#line 2812 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 956 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ForStmt");rhs.push_back("FOR OPENB ForClause Block CLOSEB");}
#line 2818 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 959 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("Condition");rhs.push_back("Expression");}
#line 2824 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 962 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ForClause");rhs.push_back("InitStmt SEMICOLON Condition SEMICOLON PostStmt");}
#line 2830 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 965 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("InitStmt");rhs.push_back("SimpleStmt");}
#line 2836 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 967 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("PostStmt");rhs.push_back("SimpleStmt");
	
	//can't end with identifier -- end with +0
	}
#line 2845 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 975 "src/parserIR.y" /* yacc.c:1646  */
    {
		for_initlabels.pop();
		for_continuelabels.pop();
		string tac;
		tac = to_string(lineno);
		string for_initlabel = get_label();
		tac.append(",label,"+for_initlabel+"\n");
		for_initlabels.push(for_initlabel);
		for_continuelabels.push(for_initlabel);
		prog.push_back(tac);
		lineno++;

	}
#line 2863 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 989 "src/parserIR.y" /* yacc.c:1646  */
    {	
		//
		string tac;
		tac=to_string(lineno);
		tac.append(",");
		tac.append("ifgoto,=,");
		string togo_label = get_label();
		tac.append("t"+to_string(tempno-1)+",1,"+togo_label+"\n");
		prog.push_back(tac);
		lineno++;
		//
		tac=to_string(lineno);
		tac.append(",goto,");
		string for_endlabel = get_label();
		tac.append(for_endlabel+"\n");
		for_endlabels.push(for_endlabel);
		prog.push_back(tac);
		lineno++;
		//
		tac=to_string(lineno);
		tac.append(",label,");
		tac.append(togo_label+"\n");
		prog.push_back(tac);
		lineno++;
		//
		//
		tac=to_string(lineno);
		tac.append(",goto,");
		string for_blocklabel = get_label();
		tac.append(for_blocklabel+"\n");
		for_blocklabels.push(for_blocklabel);
		prog.push_back(tac);
		lineno++;
		//
		tac=to_string(lineno);
		tac.append(",label,");
		string for_postlabel = get_label();
		tac.append(for_postlabel+"\n");
		for_postlabels.push(for_postlabel);
		prog.push_back(tac);
		lineno++;
		
	}
#line 2911 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1034 "src/parserIR.y" /* yacc.c:1646  */
    {
		//
		string tac;
		tac=to_string(lineno);
		tac.append(",goto,");
		string togo_label = for_initlabels.top();
		for_initlabels.pop();
		//for_continuelabels.pop();
		tac.append(togo_label+"\n");
		prog.push_back(tac);
		lineno++;
		//
		tac=to_string(lineno);
		tac.append(",label,");
		string for_blocklabel = for_blocklabels.top();
		tac.append(for_blocklabel+"\n");
		for_blocklabels.pop();
		prog.push_back(tac);
		lineno++;
	}
#line 2936 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1055 "src/parserIR.y" /* yacc.c:1646  */
    {
		string tac;
		tac=to_string(lineno);
		tac.append(",goto,");
		string togo_postlabel = for_postlabels.top();
		for_postlabels.pop();
		tac.append(togo_postlabel+"\n");
		prog.push_back(tac);
		lineno++;
	}
#line 2951 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1067 "src/parserIR.y" /* yacc.c:1646  */
    {
		string tac;
		tac = to_string(lineno);
		string for_initlabel = get_label();
		tac.append(",label,"+for_initlabel+"\n");
		for_initlabels.push(for_initlabel);
		for_continuelabels.push(for_initlabel);
		prog.push_back(tac);
		lineno++;
	}
#line 2966 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1078 "src/parserIR.y" /* yacc.c:1646  */
    {	
		//
		string tac;
		tac=to_string(lineno);
		tac.append(",");
		tac.append("ifgoto,=,");
		string togo_label = get_label();
		tac.append("t"+to_string(tempno-1)+",1,"+togo_label+"\n");
		prog.push_back(tac);
		lineno++;
		//
		tac=to_string(lineno);
		tac.append(",goto,");
		string for_endlabel = get_label();
		tac.append(for_endlabel+"\n");
		for_endlabels.push(for_endlabel);
		prog.push_back(tac);
		lineno++;
		//
		tac=to_string(lineno);
		tac.append(",label,");
		tac.append(togo_label+"\n");
		prog.push_back(tac);
		lineno++;
	}
#line 2996 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1104 "src/parserIR.y" /* yacc.c:1646  */
    {
		string tac;
		tac=to_string(lineno);
		tac.append(",goto,");
		string togo_label = for_initlabels.top();
		for_initlabels.pop();
		//for_continuelabels.pop();
		tac.append(togo_label+"\n");
		prog.push_back(tac);
		lineno++;
	}
#line 3012 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1116 "src/parserIR.y" /* yacc.c:1646  */
    {
		string tac;
		tac=to_string(lineno);
		tac.append(",label,");
		string for_endlabel = for_endlabels.top();
		for_endlabels.pop();
		for_continuelabels.pop();
		tac.append(for_endlabel+"\n");
		prog.push_back(tac);
		lineno++;
	}
#line 3028 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1131 "src/parserIR.y" /* yacc.c:1646  */
    {
	//cout << $1 << endl;
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	//cout << "here integer\n";
	//cout << (*$$).value << endl;
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	//cout << $1 << endl;
	//cout << (*$$).value << endl;
	lhs.push_back("int_lit");rhs.push_back("INTEGER");
	
	}
#line 3044 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1144 "src/parserIR.y" /* yacc.c:1646  */
    {
	  (*(yyval.nt)).value=strdup((yyvsp[0].sval));
	  //cout << "here integer\n";
	  //cout << (*$$).value << endl;
	  (yyvsp[0].sval)=(*(yyval.nt)).value;
	  lhs.push_back("float_lit");rhs.push_back("FLOAT");}
#line 3055 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1155 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	//cout << "here integer\n";
	//cout << (*$$).value << endl;
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("TypeName");rhs.push_back("IDENTIFIER");
	}
#line 3067 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1162 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	//cout << "here integer\n";
	//cout << (*$$).value << endl;
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("TypeName");rhs.push_back("VAR_TYPE");
	}
#line 3079 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1174 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ArrayType");rhs.push_back("LBRACK ArrayLength RBRACK Type");
		string temp_str = "";
		temp_str.append((yyvsp[-3].sval));
		temp_str.append((yyvsp[-2].nt)->value);
		temp_str.append((yyvsp[-1].sval));
		temp_str.append((yyvsp[0].nt)->value);
		(yyval.nt)->value = strdup(temp_str.c_str());
	}
#line 3092 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1185 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ArrayLength");rhs.push_back("Expression");
		(yyval.nt)=(yyvsp[0].nt);
	}
#line 3100 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1191 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("StructType");rhs.push_back("STRUCT LBRACE FieldDeclList RBRACE");}
#line 3106 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1192 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("StructType");rhs.push_back("STRUCT LBRACE RBRACE");}
#line 3112 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1196 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("FieldDeclList");rhs.push_back("FieldDecl SEMICOLON");}
#line 3118 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1197 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("FieldDeclList");rhs.push_back("FieldDeclList FieldDecl SEMICOLON");}
#line 3124 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1201 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("FieldDecl");rhs.push_back("IdentifierList Type");}
#line 3130 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1202 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("FieldDecl");rhs.push_back("IdentifierList Type Tag");}
#line 3136 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1206 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("Tag");rhs.push_back("STRING");}
#line 3145 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1213 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("PointerType");rhs.push_back("MUL BaseType");
		//TODO
		//symbol table
		string temp_str = "";
		temp_str.append((yyvsp[-1].sval));
		temp_str.append((yyvsp[0].nt)->value);
		(yyval.nt)->value = strdup(temp_str.c_str());
	}
#line 3158 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1223 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("BaseType");rhs.push_back("Type");}
#line 3164 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1227 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("FunctionType");rhs.push_back("FUNC Signature");
		//unimplemented
	}
#line 3172 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1233 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ConstDecl");rhs.push_back("CONST ConstSpec");
			///symbol table - put is_constant = 1 in symtab
			(yyval.nt)=(yyvsp[0].nt);
		}
#line 3181 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1240 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ConstSpec");rhs.push_back("IDENTIFIER Type ASSIGN Expression");
			(*(yyval.nt)).value=strdup((yyvsp[-3].sval));
			(yyvsp[-3].sval)=(*(yyval.nt)).value;
			//update type in symbol table here and isconstant in constdecl
			string tac = to_string(lineno);
			tac.append(",=,");
			tac.append((yyvsp[-3].sval));
			tac.append(",");
			tac.append((yyvsp[0].nt)->value);
			tac.append("\n");
			prog.push_back(tac);
			lineno++;
			insert((yyvsp[-3].sval),curr,(yyvsp[-2].nt)->value);
		}
#line 3200 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1254 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ConstSpec");rhs.push_back("IDENTIFIER Type");
			(*(yyval.nt)).value=strdup((yyvsp[-1].sval));
			(yyvsp[-1].sval)=(*(yyval.nt)).value;
			insert((yyvsp[-1].sval),curr,(yyvsp[0].nt)->value);
			//update type in symbol table here and isconstant in constdecl
		}
#line 3211 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1263 "src/parserIR.y" /* yacc.c:1646  */
    {
		lhs.push_back("ExpressionList");rhs.push_back("ExpressionList COMMA Expression");
		//TODO
			expressionlist_str = (yyvsp[-2].nt)->value;
			expressionlist_str.append(",");
			expressionlist_str.append((yyvsp[0].nt)->value);
			(*(yyval.nt)).value = strdup(expressionlist_str.c_str());
		
		}
#line 3225 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1272 "src/parserIR.y" /* yacc.c:1646  */
    {
		lhs.push_back("ExpressionList");rhs.push_back("Expression");
		(yyval.nt)=(yyvsp[0].nt);
		}
#line 3234 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1279 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("TypeDecl");rhs.push_back("TYPE  TypeSpec");}
#line 3240 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1280 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("TypeDecl");rhs.push_back("TYPE LPAREN TypeSpecList RPAREN");}
#line 3246 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1283 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("TypeSpecList");rhs.push_back("TypeSpecList TypeSpec SEMICOLON");}
#line 3252 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1284 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("TypeSpecList");rhs.push_back("TypeSpec SEMICOLON");}
#line 3258 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1287 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("TypeSpec");rhs.push_back("AliasDecl");}
#line 3264 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1288 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("TypeSpec");rhs.push_back("TypeDef");}
#line 3270 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1291 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("AliasDecl");rhs.push_back("IDENTIFIER ASSIGN Type");}
#line 3276 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1295 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("TypeDef");rhs.push_back("IDENTIFIER Type");}
#line 3282 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1302 "src/parserIR.y" /* yacc.c:1646  */
    {
	lhs.push_back("Literal");rhs.push_back("BasicLit");
	(yyval.nt)=(yyvsp[0].nt);
	}
#line 3291 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1310 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("string_lit");rhs.push_back("STRING");
	}
#line 3301 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1319 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("byte_lit");rhs.push_back("BYTE");}
#line 3310 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1326 "src/parserIR.y" /* yacc.c:1646  */
    {
	lhs.push_back("BasicLit");rhs.push_back("int_lit");
	(yyval.nt)=(yyvsp[0].nt);
	//cout << "at basic lit" << endl;
	//cout << $1->value << endl;
	//cout << $$->value << endl;
	//printf("%s\n",(char*)$1);
	}
#line 3323 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1334 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("BasicLit");rhs.push_back("float_lit");}
#line 3329 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1335 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("BasicLit");rhs.push_back("string_lit");
		//symbol table
		string temp_str = (yyvsp[0].nt)->value;
		string temp_var = get_temp_strvar();
		string tac = to_string(lineno);
		tac.append(",string,");
		tac.append(temp_var);
		tac.append(",");
		tac.append(temp_str);
		tac.append("\n");
		prog.push_back(tac);
		lineno++;
		(*(yyval.nt)).value = strdup(temp_var.c_str());
		
	}
#line 3349 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1350 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("BasicLit");rhs.push_back("byte_lit");}
#line 3355 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1358 "src/parserIR.y" /* yacc.c:1646  */
    {
	lhs.push_back("PrimaryExpr");rhs.push_back("Operand");
	(yyval.nt)=(yyvsp[0].nt);
	}
#line 3364 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1362 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("PrimaryExpr");rhs.push_back("PrimaryExpr Selector");
		string temp_str = "";
		temp_str.append((yyvsp[-1].nt)->value);
		temp_str.append((yyvsp[0].nt)->value);
		(*(yyval.nt)).value = strdup(temp_str.c_str());
	}
#line 3375 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1368 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("PrimaryExpr");rhs.push_back("PrimaryExpr Index");
		//take care of array index here
		string temp_str = "";
		temp_str.append((yyvsp[-1].nt)->value);
		temp_str.append((yyvsp[0].nt)->value);
		(*(yyval.nt)).value = strdup(temp_str.c_str());
	}
#line 3387 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1375 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("PrimaryExpr");rhs.push_back("PrimaryExpr TypeAssertion");
		//unimplemented
	}
#line 3395 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1378 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("PrimaryExpr");rhs.push_back("OperandName StructLiteral");
		//unimplemented for now
	}
#line 3403 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1385 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("StructLiteral");rhs.push_back("LBRACE KeyValList RBRACE");}
#line 3409 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1389 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("KeyValList");rhs.push_back("/* empty */");}
#line 3415 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1390 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("KeyValList");rhs.push_back("Expression COLON Expression");}
#line 3421 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1391 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("KeyValList");rhs.push_back("KeyValList COMMA Expression COLON Expression");}
#line 3427 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1396 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("Selector");rhs.push_back("PERIOD IDENTIFIER");
	//check 
	//not implemeted for now
	string temp_str = "";
	temp_str.append((yyvsp[-1].sval));
	temp_str.append((yyvsp[0].sval));
	(*(yyval.nt)).value = strdup(temp_str.c_str());
	}
#line 3440 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1405 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("Index");rhs.push_back("LBRACK Expression RBRACK");
		string temp_str = "[";
		temp_str.append((yyvsp[-1].nt)->value);
		temp_str.append("]");
		(*(yyval.nt)).value = strdup(temp_str.c_str());
	}
#line 3451 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1414 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("TypeAssertion");rhs.push_back("PERIOD LPAREN Type RPAREN");
		//unimplemented
	}
#line 3459 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1420 "src/parserIR.y" /* yacc.c:1646  */
    {
    lhs.push_back("Expression");rhs.push_back("Expression1");
    (yyval.nt)=(yyvsp[0].nt);
    }
#line 3468 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1427 "src/parserIR.y" /* yacc.c:1646  */
    {	//typecheck LOR
    lhs.push_back("Expression1");rhs.push_back("Expression1 LOR Expression2");
    string temp_var = get_tempvar();
    string tac;
    tac.append(to_string(lineno));
    tac.append(",");
    tac.append((yyvsp[-1].sval));
    tac.append(",");
    tac.append(temp_var);
    tac.append(",");
    tac.append((yyvsp[-2].nt)->value);
    tac.append(",");
    tac.append((yyvsp[0].nt)->value);
    tac.append("\n");
    prog.push_back(tac);
    lineno++;
    strcpy((*(yyval.nt)).value,temp_var.c_str());
    }
#line 3491 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1445 "src/parserIR.y" /* yacc.c:1646  */
    {
    lhs.push_back("Expression1");rhs.push_back("Expression2");
    (yyval.nt)=(yyvsp[0].nt);
    }
#line 3500 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1452 "src/parserIR.y" /* yacc.c:1646  */
    {	//typecheck LAND
    lhs.push_back("Expression2");rhs.push_back("Expression2 LAND Expression3");
    string temp_var = get_tempvar();
    string tac;
    tac.append(to_string(lineno));
    tac.append(",");
    tac.append((yyvsp[-1].sval));
    tac.append(",");
    tac.append(temp_var);
    tac.append(",");
    tac.append((yyvsp[-2].nt)->value);
    tac.append(",");
    tac.append((yyvsp[0].nt)->value);
    tac.append("\n");
    prog.push_back(tac);
    lineno++;
    strcpy((*(yyval.nt)).value,temp_var.c_str());
    }
#line 3523 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1470 "src/parserIR.y" /* yacc.c:1646  */
    {
    lhs.push_back("Expression2");rhs.push_back("Expression3");
    (yyval.nt)=(yyvsp[0].nt);
    }
#line 3532 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1477 "src/parserIR.y" /* yacc.c:1646  */
    {
    lhs.push_back("Expression3");rhs.push_back("Expression3 rel_op Expression4");
    string temp_var = get_tempvar();
    string tac;
    tac.append(to_string(lineno));
    tac.append(",");
    tac.append((yyvsp[-1].nt)->value);
    tac.append(",");
    tac.append(temp_var);
    tac.append(",");
    tac.append((yyvsp[-2].nt)->value);
    tac.append(",");
    tac.append((yyvsp[0].nt)->value);
    tac.append("\n");
    prog.push_back(tac);
    lineno++;
    strcpy((*(yyval.nt)).value,temp_var.c_str());
    }
#line 3555 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1495 "src/parserIR.y" /* yacc.c:1646  */
    {
    lhs.push_back("Expression3");rhs.push_back("Expression4");
    (yyval.nt)=(yyvsp[0].nt);
    }
#line 3564 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1502 "src/parserIR.y" /* yacc.c:1646  */
    {
    lhs.push_back("Expression4");rhs.push_back("Expression4 add_op Expression5");
    string temp_var = get_tempvar();
    string tac;
    tac.append(to_string(lineno));
    tac.append(",");
    tac.append((yyvsp[-1].nt)->value);
    tac.append(",");
    tac.append(temp_var);
    tac.append(",");
    tac.append((yyvsp[-2].nt)->value);
    tac.append(",");
    tac.append((yyvsp[0].nt)->value);
    tac.append("\n");
    prog.push_back(tac);
    lineno++;
    strcpy((*(yyval.nt)).value,temp_var.c_str());
    }
#line 3587 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1520 "src/parserIR.y" /* yacc.c:1646  */
    {
    lhs.push_back("Expression4");rhs.push_back("Expression5");
    (yyval.nt)=(yyvsp[0].nt);
    }
#line 3596 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1527 "src/parserIR.y" /* yacc.c:1646  */
    {
    lhs.push_back("Expression5");rhs.push_back("Expression5 mul_op PrimaryExpr");
    string temp_var = get_tempvar();
    string tac;
    tac.append(to_string(lineno));
    tac.append(",");
    tac.append((yyvsp[-1].nt)->value);
    tac.append(",");
    tac.append(temp_var);
    tac.append(",");
    tac.append((yyvsp[-2].nt)->value);
    tac.append(",");
    tac.append((yyvsp[0].nt)->value);
    tac.append("\n");
    prog.push_back(tac);
    lineno++;
    strcpy((*(yyval.nt)).value,temp_var.c_str());
    }
#line 3619 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1545 "src/parserIR.y" /* yacc.c:1646  */
    {
    lhs.push_back("Expression5");rhs.push_back("UnaryExpr");
    (yyval.nt)=(yyvsp[0].nt);
    }
#line 3628 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1554 "src/parserIR.y" /* yacc.c:1646  */
    {
	lhs.push_back("UnaryExpr");rhs.push_back("PrimaryExpr");
	(yyval.nt)=(yyvsp[0].nt);
	}
#line 3637 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1558 "src/parserIR.y" /* yacc.c:1646  */
    {
	lhs.push_back("UnaryExpr");rhs.push_back("unary_op PrimaryExpr");
	//TODO	
		string temp_str = "";
		temp_str.append((yyvsp[-1].nt)->value);
		temp_str.append((yyvsp[0].nt)->value);
		(*(yyval.nt)).value=strdup(temp_str.c_str());
		//for now its pushing -5, *6 sort of things
	}
#line 3651 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1585 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("rel_op");rhs.push_back("EQL");}
#line 3660 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1589 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("rel_op");rhs.push_back("NEQ");}
#line 3669 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1593 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("rel_op");rhs.push_back("LSS");}
#line 3678 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1597 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("rel_op");rhs.push_back("LEQ");}
#line 3687 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1601 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("rel_op");rhs.push_back("GTR");}
#line 3696 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1605 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("rel_op");rhs.push_back("GEQ");}
#line 3705 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1610 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("add_op");rhs.push_back("ADD");}
#line 3714 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1614 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("add_op");rhs.push_back("SUB");}
#line 3723 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1618 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("add_op");rhs.push_back("OR");}
#line 3732 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1622 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("add_op");rhs.push_back("XOR");}
#line 3741 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1627 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("mul_op");rhs.push_back("MUL");}
#line 3750 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1631 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("mul_op");rhs.push_back("QUO");}
#line 3759 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1635 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("mul_op");rhs.push_back("REM");}
#line 3768 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1639 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("mul_op");rhs.push_back("SHL");}
#line 3777 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1643 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	//cout << "here integer\n";
	//cout << (*$$).value << endl;
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("mul_op");rhs.push_back("SHR");}
#line 3788 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1649 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	//cout << "here integer\n";
	//cout << (*$$).value << endl;
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("mul_op");rhs.push_back("AND");}
#line 3799 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1655 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	//cout << "here integer\n";
	//cout << (*$$).value << endl;
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("mul_op");rhs.push_back("AND_NOT");}
#line 3810 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1663 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	//cout << "here integer\n";
	//cout << (*$$).value << endl;
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("unary_op");rhs.push_back("ADD");}
#line 3821 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1669 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	//cout << "here integer\n";
	//cout << (*$$).value << endl;
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("unary_op");rhs.push_back("SUB");}
#line 3832 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1675 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	//cout << "here integer\n";
	//cout << (*$$).value << endl;
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("unary_op");rhs.push_back("NOT");}
#line 3843 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1681 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	//cout << "here integer\n";
	//cout << (*$$).value << endl;
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("unary_op");rhs.push_back("XOR");}
#line 3854 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1687 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	//cout << "here integer\n";
	//cout << (*$$).value << endl;
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("unary_op");rhs.push_back("MUL");}
#line 3865 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1693 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	//cout << "here integer\n";
	//cout << (*$$).value << endl;
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("unary_op");rhs.push_back("AND");}
#line 3876 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1703 "src/parserIR.y" /* yacc.c:1646  */
    {
	  lhs.push_back("assign_op");rhs.push_back("ASSIGN");
	  (*(yyval.nt)).value=strdup((yyvsp[0].sval));
	  (yyvsp[0].sval) = (*(yyval.nt)).value;
	  }
#line 3886 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1708 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("assign_op");rhs.push_back("ADD_ASSIGN");
	}
#line 3896 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1713 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("assign_op");rhs.push_back("SUB_ASSIGN");
	}
#line 3906 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1718 "src/parserIR.y" /* yacc.c:1646  */
    {
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	lhs.push_back("assign_op");rhs.push_back("MUL_ASSIGN");
	}
#line 3916 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1723 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("assign_op");rhs.push_back("QUO_ASSIGN");
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	}
#line 3925 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1727 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("assign_op");rhs.push_back("REM_ASSIGN");
	  (*(yyval.nt)).value=strdup((yyvsp[0].sval));
	  (yyvsp[0].sval)=(*(yyval.nt)).value;
	  }
#line 3934 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1735 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("PackageClause");rhs.push_back("PACKAGE PackageName");
		string tac = to_string(lineno) + ",call," + (yyvsp[0].nt)->value;
		tac.append(",0\n");
		prog.push_back(tac);
		lineno++;
		tac = to_string(lineno) + ",exit\n";
		prog.push_back(tac);
		lineno++;
		insert("print",curr,"function");
		insert("fmt.Println",curr,"function");
	}
#line 3950 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1748 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("PackageName");rhs.push_back("IDENTIFIER");
	(*(yyval.nt)).value=strdup((yyvsp[0].sval));
	//cout << "here integer\n";
	//cout << (*$$).value << endl;
	(yyvsp[0].sval)=(*(yyval.nt)).value;
	}
#line 3961 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1758 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ImportDeclList");rhs.push_back("ImportDeclList ImportDecl");}
#line 3967 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1759 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ImportDeclList");rhs.push_back("ImportDecl");
      //cout << "at start of import list\n";
      (yyval.nt)=(yyvsp[0].nt);
      }
#line 3976 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1763 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ImportDeclList");rhs.push_back("/*empty*/");
      //cout << "at start empty of import list\n";
      //$$->value=NULL;
      //cout << "at start empty end of import list\n";
      }
#line 3986 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1771 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ImportDecl");rhs.push_back("IMPORT ImportSpec SEMICOLON");}
#line 3992 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1772 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ImportDecl");rhs.push_back("IMPORT LPAREN ImportSpecList  RPAREN");}
#line 3998 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1776 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ImportSpecList");rhs.push_back("ImportSpecList ImportSpec SEMICOLON");}
#line 4004 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1777 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ImportSpecList");rhs.push_back("ImportSpec SEMICOLON");}
#line 4010 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1780 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ImportSpec");rhs.push_back("PERIOD ImportPath");}
#line 4016 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1781 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ImportSpec");rhs.push_back("PackageName2 ImportPath");}
#line 4022 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1782 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ImportSpec");rhs.push_back("PackageName2");
	  (yyval.nt)=(yyvsp[0].nt);
	  }
#line 4030 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1786 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("ImportPath");rhs.push_back("string_lit");
	(yyval.nt)=(yyvsp[0].nt);
	}
#line 4038 "parserIR.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1791 "src/parserIR.y" /* yacc.c:1646  */
    {lhs.push_back("PackageName2");rhs.push_back("string_lit");
	(yyval.nt)=(yyvsp[0].nt);
	insert("fmt",curr,"package");
	}
#line 4047 "parserIR.tab.c" /* yacc.c:1646  */
    break;


#line 4051 "parserIR.tab.c" /* yacc.c:1646  */
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
#line 1797 "src/parserIR.y" /* yacc.c:1906  */



int main (int argc, char **argv) {
	
	//handling global variables
	is_argument_list_empty.push(0);
	
	yyin = fopen(argv[1], "r");	//taking input as argument
	//cout << "SIZES = " << lhs.size() << ' ' << rhs.size() << endl;
	yyparse ( );
	//cout << "SIZES = " << lhs.size() << ' ' << rhs.size() << endl;
	
	//top down right derivation
	reverse(lhs.begin(),lhs.end());
	reverse(rhs.begin(),rhs.end());
	
	fstream temp;
	temp.open("temp.txt",ios_base::out);
	
	
	for(int i=0;i<lhs.size();i++){
		//if(i<rhs.size()){
			temp << lhs[i] << " -> "<< rhs[i] << "$" << endl;
		//	}
		//else cout << "NOTE HERE " << endl;
	}
	temp.close();
	//generate_html();
	//printting 3ac code ie. vector prog
	if(error_status==1){
		exit (EXIT_FAILURE);
	}
	for(int i=0;i<prog.size();i++){
		cout << prog[i];
	}
}












