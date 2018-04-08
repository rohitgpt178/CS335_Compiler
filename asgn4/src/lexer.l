%{
	#include<stdio.h>
	#include "parserIR.tab.h"
	
%}
%option nounput yylineno
UNICODE_LETTER			[a-zA-Z]
LETTER				[a-zA-Z_]
DIGIT				[0-9]
UNICODE_CHAR			[^\n]
NEW_LINE			[\n]
VAR_TYPE			"bool"|"byte"|"error"|"float32"|"float64"|"int"|"int8"|"int16"|"int32"|"int64"|"rune"|"string"|"uint"|"uint8 "|"uint16"|"uint32"|"uint64"|"uintptr"
BOOL_CONST			"true"|"false"
NIL_VAL				"nil"
%%
	
"="				{yylval.sval = strdup(yytext); return ASSIGN;}
"+"				{yylval.sval = strdup(yytext); return ADD;}
"-"				{yylval.sval = strdup(yytext); return SUB;}
"*"				{yylval.sval = strdup(yytext); return MUL;}
"/"				{yylval.sval = strdup(yytext); return QUO;}
"%"				{yylval.sval = strdup(yytext); return REM;}

"&"				{yylval.sval = strdup(yytext); return AND;}
"|"				{yylval.sval = strdup(yytext); return OR;}
"^"				{yylval.sval = strdup(yytext); return XOR;}
"<<"				{yylval.sval = strdup(yytext); return SHL;}
">>"				{yylval.sval = strdup(yytext); return SHR;}
"&^"				{yylval.sval = strdup(yytext); return AND_NOT;}

"+="				{yylval.sval = strdup(yytext); return ADD_ASSIGN;}
"-="				{yylval.sval = strdup(yytext); return SUB_ASSIGN;}
"*="				{yylval.sval = strdup(yytext); return MUL_ASSIGN;}
"/="				{yylval.sval = strdup(yytext); return QUO_ASSIGN;}
"%="				{yylval.sval = strdup(yytext); return REM_ASSIGN;}

"&="				{yylval.sval = strdup(yytext); return AND_ASSIGN;}
"|="				{yylval.sval = strdup(yytext); return OR_ASSIGN;}
"^="				{yylval.sval = strdup(yytext); return XOR_ASSIGN;}
"<<="				{yylval.sval = strdup(yytext); return SHL_ASSIGN;}
">>="				{yylval.sval = strdup(yytext); return SHR_ASSIGN;}
"&^="				{yylval.sval = strdup(yytext); return AND_NOT_ASSIGN;}

"&&"				{yylval.sval = strdup(yytext); return LAND;}
"||"				{yylval.sval = strdup(yytext); return LOR;}
"->"				{yylval.sval = strdup(yytext); return ARROW;}
"++"				{yylval.sval = strdup(yytext); return INC;}
"--"				{yylval.sval = strdup(yytext); return DEC;}

"=="				{yylval.sval = strdup(yytext); return EQL;}
">"				{yylval.sval = strdup(yytext); return GTR;}
"<"				{yylval.sval = strdup(yytext); return LSS;}
"!"				{yylval.sval = strdup(yytext); return NOT;}

"!="				{yylval.sval = strdup(yytext); return NEQ;}
"<="				{yylval.sval = strdup(yytext); return LEQ;}
">="				{yylval.sval = strdup(yytext); return GEQ;}
":="				{yylval.sval = strdup(yytext); return DEFINE;}
"..."				{yylval.sval = strdup(yytext); return ELLIPSIS;}

"("				{yylval.sval = strdup(yytext); return LPAREN;}
")"				{yylval.sval = strdup(yytext); return RPAREN;}
"{"				{yylval.sval = strdup(yytext); return LBRACE;}
"}"				{yylval.sval = strdup(yytext); return RBRACE;}
"["				{yylval.sval = strdup(yytext); return LBRACK;}
"]"				{yylval.sval = strdup(yytext); return RBRACK;}
","				{yylval.sval = strdup(yytext); return COMMA;}
";"				{yylval.sval = strdup(yytext); return SEMICOLON;}
":"				{yylval.sval = strdup(yytext); return COLON;}
"."				{yylval.sval = strdup(yytext); return PERIOD;}

"package"			{yylval.sval = strdup(yytext); return PACKAGE;}
"import"			{yylval.sval = strdup(yytext); return IMPORT;}
"func"				{yylval.sval = strdup(yytext); return FUNC;}
"break"				{yylval.sval = strdup(yytext); return BREAK;}
"case"				{yylval.sval = strdup(yytext); return CASE;}
"const"				{yylval.sval = strdup(yytext); return CONST;}
"continue"        		{yylval.sval = strdup(yytext); return CONTINUE;}
"default"        		{yylval.sval = strdup(yytext); return DEFAULT;}
"else"				{yylval.sval = strdup(yytext); return ELSE;}
"for"				{yylval.sval = strdup(yytext); return FOR;}
"go"        			{yylval.sval = strdup(yytext); return GO;}
"if"				{yylval.sval = strdup(yytext); return IF;}
"range"				{yylval.sval = strdup(yytext); return RANGE;}
"return"        		{yylval.sval = strdup(yytext); return RETURN;}
"struct"        		{yylval.sval = strdup(yytext); return STRUCT;}
"switch"        		{yylval.sval = strdup(yytext); return SWITCH;}
"type"       			{yylval.sval = strdup(yytext); return TYPE;}
"var"        			{yylval.sval = strdup(yytext); return VAR;}
{VAR_TYPE}			{yylval.sval = strdup(yytext); return VAR_TYPE;}
{BOOL_CONST}			{yylval.sval = strdup(yytext); return BOOL_CONST;}
{NIL_VAL}			{yylval.sval = strdup(yytext); return NIL_VAL;}

{LETTER}({LETTER}|{DIGIT})*	{yylval.sval = strdup(yytext); return IDENTIFIER;}
{DIGIT}+			{yylval.sval = strdup(yytext); return INTEGER;}
{DIGIT}+"."{DIGIT}+		{yylval.sval = strdup(yytext); return FLOAT;}
\'{UNICODE_CHAR}\'  		{yylval.sval = strdup(yytext); return BYTE;}

\"([^\\\n\"]|(\\.))*\"	{yylval.sval = strdup(yytext); return STRING;}
\/\/{UNICODE_CHAR}*\n		;
"\n"				;
"\t"				;
" "				;
.				printf("ERROR : unexpected character in line %d\n",yylineno);

%%
int yywrap(void)
{
	return 1;
}
