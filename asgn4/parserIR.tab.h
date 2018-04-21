/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 96 "src/parserIR.y" /* yacc.c:1909  */

#include "src/node.h"

#line 48 "parserIR.tab.h" /* yacc.c:1909  */

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
#line 100 "src/parserIR.y" /* yacc.c:1909  */

     
     //char *nt;
     char *sval;
     node* nt;

#line 143 "parserIR.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSERIR_TAB_H_INCLUDED  */
