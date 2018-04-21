%{
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
	string str_t = "t_temporary_string";
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
%}

//%error-verbose
%define parse.error verbose

//define node in node.h
%code requires{
#include "src/node.h"
}

%union {
     
     //char *nt;
     char *sval;
     node* nt;
}

%start StartFile 

%token <sval> PACKAGE IMPORT FUNC BREAK CASE CONST CONTINUE DEFAULT
%token <sval> ELSE FOR GO IF RANGE RETURN STRUCT SWITCH TYPE VAR VAR_TYPE
%token <sval> BOOL_CONST NIL_VAL IDENTIFIER BYTE STRING ELLIPSIS
%token <sval> SHL SHR INC DEC
%token <sval> INTEGER
%token <sval> FLOAT
%left <sval> ADD SUB MUL QUO REM 
%token <sval> ASSIGN AND NOT DEFINE AND_NOT
%left <sval> OR XOR ARROW //Identifier
%right <sval> ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN QUO_ASSIGN REM_ASSIGN
%right <sval> AND_ASSIGN OR_ASSIGN XOR_ASSIGN
%right <sval> SHL_ASSIGN SHR_ASSIGN AND_NOT_ASSIGN COLON
%left <sval> LAND LOR EQL NEQ LEQ GEQ SEMICOLON
%left <sval> GTR LSS LPAREN RPAREN LBRACE RBRACE LBRACK RBRACK COMMA PERIOD


%type <nt> StartFile Expression Expression1 Expression2 Expression3 Expression4 Expression5 
%type <nt> Block StatementList Statement SimpleStmt int_lit
%type <nt> EmptyStmt /*ExpressionStmt*/ IncDecStmt OPENB CLOSEB 
%type <nt> Assignment Declaration ConstDecl VarSpec string_lit
%type <nt> Signature Result Parameters ParameterList ParameterDecl
%type <nt> ConstSpec MethodDecl Receiver TopLevelDecl TopLevelDeclList LabeledStmt
%type <nt> ReturnStmt BreakStmt ContinueStmt StructType
%type <nt> FunctionDecl FunctionName TypeList
%type <nt> Function FunctionBody FunctionCall ForStmt ForClause /*RangeClause*/ InitStmt ArgumentList Arguments
%type <nt> PostStmt Condition UnaryExpr PrimaryExpr
%type <nt> Selector Index /*Slice */TypeDecl TypeSpecList TypeSpec VarDecl
%type <nt> TypeAssertion ExpressionList ArrayType assign_op rel_op add_op mul_op unary_op Tag byte_lit float_lit Label
//%type <nt> ExprCaseClauseList ExprCaseClause
%type <nt> Operand Literal BasicLit OperandName ImportSpec IfStmt
%type <nt> ImportPath
%type <nt> PackageClause PackageName PackageName2 ImportDecl ImportDeclList ImportSpecList
%type <nt> FieldDeclList FieldDecl Type TypeLit ArrayLength
%type <nt> TypeName
%type <nt> /*QualifiedIdent*/ PointerType IdentifierList IdentifierLIST BaseType

//%%



%% 


StartFile:
    PackageClause SEMICOLON ImportDeclList TopLevelDeclList {
    	lhs.push_back("StartFile");rhs.push_back("PackageClause SEMICOLON ImportDeclList TopLevelDeclList");
    	//cout << "---" << $1- << endl;// << "---" << $3 << "---";
    }
    ;

Block:
	LBRACE /*block_mark1*/ OPENB  StatementList CLOSEB /*block_mark2*/ RBRACE{
	lhs.push_back("Block");rhs.push_back("LBRACE OPENB StatementList CLOSEB RBRACE");
	$$=$3;
	}
	//printf("I have a block -------");cout << $1 << endl;}
	; 
//block markers start here
/*
block_mark1:{
	symboltable* sym_ptr = new_symboltable();
	table * t1 = new_table(sym_ptr,curr);
	curr = t1;
};

block_mark2:{
	curr = curr->parent;
};*/

//block markers end here

OPENB:
	/*empty*/{lhs.push_back("OPENB");rhs.push_back("/*empty*/");
	symboltable* sym_ptr = new_symboltable();
	table * t1 = new_table(sym_ptr,curr);
	curr = t1;
	
	}
	;
	
CLOSEB:
	/*empty*/{lhs.push_back("CLOSEB");rhs.push_back("/*empty*/");
	//$$->value=NULL;
	curr = curr->parent;
	}
	;

StatementList:
    StatementList Statement SEMICOLON {
    lhs.push_back("StatementList");rhs.push_back("StatementList Statement SEMICOLON");
    
    }//printf("got a list");}
    | Statement SEMICOLON {lhs.push_back("StatementList");rhs.push_back("Statement SEMICOLON");/*;printf("got a statement");*/
      $$=$1; 	
    }
    ;

Statement:
	Declaration {lhs.push_back("Statement");rhs.push_back("Declaration");}
	| LabeledStmt {lhs.push_back("Statement");rhs.push_back("LabeledStmt");
	 	 //unimplemented - no need
	}
	| SimpleStmt {lhs.push_back("Statement");rhs.push_back("SimpleStmt");
	 	 $$=$1;
	 }
	|ReturnStmt {lhs.push_back("Statement");rhs.push_back("ReturnStmt");
		 $$=$1;	
	}
	| BreakStmt {lhs.push_back("Statement");rhs.push_back("BreakStmt");}
	| ContinueStmt {lhs.push_back("Statement");rhs.push_back("ContinueStmt");}
	|Block {lhs.push_back("Statement");rhs.push_back("Block");
	 	$$=$1;
	}
	| IfStmt {lhs.push_back("Statement");rhs.push_back("IfStmt");
	 	$$=$1;
	}
	|  ForStmt {lhs.push_back("Statement");rhs.push_back("ForStmt");
	 	$$=$1;
	} 
	| FunctionCall {lhs.push_back("Statement");rhs.push_back("FunctionCall");
	 	$$=$1;
	} 
	| FunctionStmt {lhs.push_back("Statement");rhs.push_back("FunctionStmt");
	 //$$=$1;
	};

SimpleStmt:
	EmptyStmt {lhs.push_back("SimpleStmt");rhs.push_back("EmptyStmt");}
	|  IncDecStmt {lhs.push_back("SimpleStmt");rhs.push_back("IncDecStmt");}
	| Assignment {lhs.push_back("SimpleStmt");rhs.push_back("Assignment");
	  $$=$1;} 
;

EmptyStmt:
	/*empty*/{
	lhs.push_back("EmptyStmt");rhs.push_back("/*empty*/");
	//nothing
	}
	;



LabeledStmt:
	Label COLON Statement {lhs.push_back("LabeledStmt");rhs.push_back("Label COLON Statement");};
Label:
	IDENTIFIER {
	(*$$).value=strdup($1);
	$1=(*$$).value;
	lhs.push_back("Label");rhs.push_back("IDENTIFIER");};



IncDecStmt:
	Expression INC {
	lhs.push_back("IncDecStmt");rhs.push_back("Expression INC");
	string tac;
	tac.append(to_string(lineno));
	tac.append(",");
	tac.append("+");
	tac.append(",");
	tac.append($1->value);
	tac.append(",");
	tac.append($1->value);
	tac.append(",");
	tac.append("1");
	tac.append("\n");
	prog.push_back(tac);
	lineno++;
	}
	|Expression DEC {
	string tac;
	tac.append(to_string(lineno));
	tac.append(",");
	tac.append("-");
	tac.append(",");
	tac.append($1->value);
	tac.append(",");
	tac.append($1->value);
	tac.append(",");
	tac.append("1");
	tac.append("\n");
	prog.push_back(tac);
	lineno++;
	lhs.push_back("IncDecStmt");rhs.push_back("Expression DEC");
	
	};

Assignment:
	ExpressionList assign_op ExpressionList {
		lhs.push_back("Assignment");rhs.push_back("ExpressionList assign_op ExpressionList");
		//$$=$1; 
		string temp_str = $1->value;
		vector <string> vec_expr_list1 = split(temp_str, ',');
		string temp_str2 = $3->value;
		vector <string> vec_expr_list2 = split(temp_str2, ',');
		if(vec_expr_list1.size()!= vec_expr_list2.size()){
		//pass as yyerror
		cout<<"ERROR : Unequal # of expressions on LHS "<<vec_expr_list1.size()<<" & RHS "<<vec_expr_list2.size()<<endl;
		}
		else{
			//TODO array checking - use lindex and rindex - use some global function
			
			//checking operator
			string op_used = $2->value;
			if(op_used=="="){
				op_used = $2->value;
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
	;

VarDecl:
		VAR VarSpec {lhs.push_back("VarDecl");rhs.push_back("VAR VarSpec");
			//symbol table
			$$=$2;
		}
		;
VarSpec:
		IdentifierList Type ASSIGN ExpressionList {lhs.push_back("VarSpec");rhs.push_back("IdentifierList Type ASSIGN ExpressionList");
			//symbol table (also lookup if already exist) + insructions
			//update symtable using $2
			//check arrays - no arrays with assign allowed
			//loc1
			string temp_str = $1->value;
			vector <string> vec_identifier_list = split(temp_str, ',');
			string temp_str2 = $4->value;
			vector <string> vec_expr_list = split(temp_str2, ',');
			if(vec_identifier_list.size()!= vec_expr_list.size()){
			cout<<"ERROR : Unequal # of expressions on LHS "<<vec_identifier_list.size()<<" & RHS "<<vec_expr_list.size()<<endl;
			}
			else{
				for(int i=0;i<vec_identifier_list.size();i++){
					string tac;
					tac.append(to_string(lineno));
					tac.append(",");
					tac.append($3);
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
					insert(vec_identifier_list[i],curr,$2->value);
				}
			}
		}
		| IdentifierList Type {lhs.push_back("VarSpec");rhs.push_back("IdentifierList Type");
			//symbol table			
			//array declaration
			//varspec contains variable names
			string temp_str1 = $1->value;
			string temp_str2 = $2->value;
			
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
				tac.append($1->value);
				tac.append(",");
				tac.append(length_temp);
				tac.append("\n");
				prog.push_back(tac);
				lineno++;
				insert($1->value,curr,$2->value);	//TODO array
				//curr->symtab[vec_identifier_list[i]].type = $2->value;
			}
			else{
				string temp_str = $1->value;
				vector <string> vec_identifier_list = split(temp_str, ',');
				for(int i=0;i<vec_identifier_list.size();i++){
					insert(vec_identifier_list[i],curr,$2->value);
				}
			}
			
			//insert in symbol table
			//propagating upwards
		}
		;


Declaration:
	ConstDecl {lhs.push_back("Declaration");rhs.push_back("ConstDecl");$$=$1;
		//unimplemented
	}
	| TypeDecl {lhs.push_back("Declaration");rhs.push_back("TypeDecl");
		//unimplemented for now - OOPS - to do afterwards
	}
	| VarDecl {lhs.push_back("Declaration");rhs.push_back("VarDecl");$$=$1;};


FunctionDecl:
		FUNC FunctionName OPENB Function CLOSEB {lhs.push_back("FunctionDecl");rhs.push_back("FUNC FunctionName OPENB Function CLOSEB");
			//TODO
			//symbol table
			
			//new
			//cout << "functionname " << strdup($2->value) << endl;
			//string temp_name = "main";
			//if(strdup($2->value)!=temp_name){
				prog.push_back(to_string(lineno)+",exit\n");
				lineno++;
				$$=$2;	//for now
			//}
		}
		|FUNC FunctionName OPENB Signature CLOSEB {lhs.push_back("FunctionDecl");rhs.push_back("FUNC FunctionName OPENB Signature CLOSEB");
		};
FunctionName:
		IDENTIFIER {
		    	(*$$).value=strdup($1);
		    	$1=(*$$).value;
		    	string temp_str = $1;
		    	lhs.push_back("FunctionName");rhs.push_back("IDENTIFIER");
		    	
		    	//new
			if(temp_str!="main"){
				string tac = to_string(lineno);
				tac.append(",function,");
				tac.append($1);
				tac.append("\n");
				prog.push_back(tac);
				lineno++;
				//insert in symbol table
				//$1=(*$$).value;
			
				string type_temp = "function";
				insert(temp_str,curr,type_temp);
			}
			else{
				string tac = to_string(lineno);
				tac.append(",label,");
				tac.append($1);
				tac.append("_prog");
				tac.append("\n");
				prog.push_back(tac);
				lineno++;
				//insert in symbol table
				//$1=(*$$).value;
			
				string type_temp = "function";
				insert(temp_str,curr,type_temp);
			}
		};
Function:
		Signature FunctionBody {lhs.push_back("Function");rhs.push_back("Signature FunctionBody");
		$$=$2;
		};
FunctionBody:		
		Block {lhs.push_back("FunctionBody");rhs.push_back("Block");
		$$=$1;};
//-----------------------------------------------------------------------------------------------start
//function call starts here
FunctionStmt:
		VarDecl DEFINE FunctionCall{lhs.push_back("FunctionStmt");rhs.push_back("VarDecl DEFINE FunctionCall");
			
			//symbol table updation & typecheck
			//multiple return values not implemented - only a := f(a,b,c)
			//TODO function inside arguments
			string tac;
			tac.append(to_string(lineno));
			tac.append(",");
			tac = tac + "getreturn,"; 
			tac.append($1->value);
			tac.append("\n");
			prog.push_back(tac);
			lineno++;
			//pass to $$

		}
		//new changes
		| IDENTIFIER DEFINE FunctionCall{lhs.push_back("FunctionStmt");rhs.push_back("IDENTIFIER DEFINE FunctionCall");
			
			//check
			check_entry($1,curr);
			
			string tac;
			tac.append(to_string(lineno));
			tac.append(",");
			tac = tac + "getreturn,"; 
			tac.append($1);
			tac.append("\n");
			prog.push_back(tac);
			lineno++;
		}
		;




FunctionCall:	PrimaryExpr LPAREN ArgumentList RPAREN {lhs.push_back("FunctionCall");rhs.push_back("PrimaryExpr LPAREN ArgumentList RPAREN");
		//PrimaryExpr contains name of function
		string str1 = strdup($1->value);
		string str2 = "print";
		string str3 = "fmt.Println";
		string str4 = "fmt.Scanln";
		if(is_argument_list_empty.top()!=1){
			string temp_str = $3->value;
			vector <string> vec_arguments = split(temp_str, ',');
			if(str1!= str2 && str1!=str3 && str1!=str4){
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
				tac.append($1->value);
				tac.append(",");
				tac.append(to_string(vec_arguments.size()));
				tac.append("\n");
				prog.push_back(tac);
				lineno++;
			} else {
				//printing part
				if(str1== str2 || str1==str3){
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
				
				if(str1 == str4){
					for(int i=0;i<vec_arguments.size();i++){
						string tac;
						tac.append(to_string(lineno));
						tac.append(",");
						tac = tac + "scan,"; 
						tac.append(vec_arguments[i]);
						tac.append("\n");
						prog.push_back(tac);
						lineno++;
					}
				}
				//scanning part
			}	
		} else{
			is_argument_list_empty.pop();
			string tac;
			tac.append(to_string(lineno));
			tac.append(",");
			tac = tac + "call,"; 
			tac.append($1->value);
			tac.append(",");
			tac.append("0");
			tac.append("\n");
			prog.push_back(tac);
			lineno++;
		
		}
}
		;		

ArgumentList:	
		ArgumentList COMMA Arguments {lhs.push_back("ArgumentList");rhs.push_back("ArgumentList COMMA Arguments");
			argumentlist_str = $1->value;
			argumentlist_str.append(",");
			argumentlist_str.append($3->value);
			(*$$).value = strdup(argumentlist_str.c_str());
			//only identifiers or variables allowed - no expressions
			
		}
		| /*empty*/{lhs.push_back("ArgumentList");rhs.push_back("/*empty*/");
			is_argument_list_empty.push(1);
		}
		| Arguments {lhs.push_back("ArgumentList");rhs.push_back("Arguments");
			$$=$1;
		}
		;

Arguments:	PrimaryExpr {lhs.push_back("Arguments");rhs.push_back("PrimaryExpr");}
		| FunctionCall {lhs.push_back("Arguments");rhs.push_back("FunctionCall");}
		;
		
//function call till here 

Signature:
	Parameters {lhs.push_back("Signature");rhs.push_back("Parameters");
		$$=$1;
	}
	|Parameters Result {lhs.push_back("Signature");rhs.push_back("Parameters Result");
		//loc2
		//symbol table here
	};

//------------------------------------------------------------------------------------------------------end
Result:
	LPAREN TypeList RPAREN {lhs.push_back("Result");rhs.push_back("LPAREN TypeList RPAREN");
		//unimplemented
		//one return to return them all
	}
	| Type  {lhs.push_back("Result");rhs.push_back("Type");
		//set symbol table 
		$$=$1;	
	};

Parameters:
	LPAREN RPAREN { 
	lhs.push_back("Parameters");rhs.push_back("LPAREN RPAREN");
		$$->value = strdup("");
	}//printf("gor func with no arguments");}
	| LPAREN ParameterList RPAREN {lhs.push_back("Parameters");rhs.push_back("LPAREN ParameterList RPAREN");
		string temp_str = $2->value;
		vector <string> vec_params = split(temp_str, ',');
		//new
		string tac_args = to_string(lineno);
		tac_args.append(",args_num,");
		tac_args.append(to_string(vec_params.size()));
		tac_args.append("\n");
		prog.push_back(tac_args);
		lineno++;
		
		//new
		for(int i= vec_params.size()-1;i>=0;i--){	//new 
			string tac = to_string(lineno);
			tac.append(",pop,");
			tac.append(vec_params[i]);
			tac.append(",");
			tac.append(to_string(vec_params.size()-i));
			tac.append("\n");
			prog.push_back(tac);
			lineno++;
		}
		
	}
	|LPAREN ParameterList COMMA RPAREN {lhs.push_back("Parameters");rhs.push_back("LPAREN ParameterList COMMA RPAREN");
		//why???
		//unimplemented
	}
	; 
ParameterList:
	ParameterDecl {lhs.push_back("ParameterList");rhs.push_back("ParameterDecl");
		$$=$1;
	}
	|ParameterList COMMA ParameterDecl {lhs.push_back("ParameterList");rhs.push_back("ParameterList COMMA ParameterDecl");
		string temp_str = $1->value;
		temp_str.append(",");
		temp_str.append($3->value);
		(*$$).value = strdup(temp_str.c_str());
	}
	;

//change

ParameterDecl:
	IdentifierList Type {lhs.push_back("ParameterDecl");rhs.push_back("IdentifierList Type");
		//symbol table
		$$=$1;
		string temp_str = $1->value;
		vector <string> vec_param_list = split(temp_str, ',');
		for(int i=0;i<vec_param_list.size();i++){
			insert(vec_param_list[i],curr,$2->value);
		}
		
	}
	| IdentifierList ELLIPSIS  Type {lhs.push_back("ParameterDecl");rhs.push_back("IdentifierList ELLIPSIS  Type");
		//unimplemented
	}
	|ELLIPSIS Type {lhs.push_back("ParameterDecl");rhs.push_back("ELLIPSIS Type");
		//unimplemented
	}
	;

TypeList:
    TypeList COMMA Type {lhs.push_back("TypeList");rhs.push_back("TypeList COMMA Type");
    		//TODO
    }
    | Type {lhs.push_back("TypeList");rhs.push_back("Type");
    		$$=$1;
    }
    ;

//change
//--------------------------------------------------------------------------------------------------------------------------------start
IdentifierList:
		IDENTIFIER IdentifierLIST {lhs.push_back("IdentifierList");rhs.push_back("IDENTIFIER IdentifierLIST");
			string temp_str = $1;
			temp_str.append($2->value);
			(*$$).value = strdup(temp_str.c_str());
		}
		| IDENTIFIER {
			//check	NOT
			(*$$).value=strdup($1);
			$1=(*$$).value;
			lhs.push_back("IdentifierList");rhs.push_back("IDENTIFIER");}
		;
//-----------------------------------------------end		
IdentifierLIST:	IdentifierLIST COMMA IDENTIFIER {lhs.push_back("IdentifierLIST");rhs.push_back("IdentifierLIST COMMA IDENTIFIER");
			string temp_str = $1->value;
			temp_str.append(",");
			temp_str.append($3);
			(*$$).value = strdup(temp_str.c_str());
		
		}
		| COMMA IDENTIFIER {lhs.push_back("IdentifierLIST");rhs.push_back("COMMA IDENTIFIER");
			string temp_str = ",";
			temp_str.append($2);
			(*$$).value = strdup(temp_str.c_str());
		
		}
		;




//change
MethodDecl:
	FUNC Receiver IDENTIFIER Function {lhs.push_back("MethodDecl");rhs.push_back("FUNC Receiver IDENTIFIER Function");}
	| FUNC Receiver IDENTIFIER Signature {lhs.push_back("MethodDecl");rhs.push_back("FUNC Receiver IDENTIFIER Signature");}
	;

Receiver:
	Parameters {lhs.push_back("Receiver");rhs.push_back("Parameters");};

TopLevelDeclList:
    TopLevelDeclList SEMICOLON TopLevelDecl  {lhs.push_back("TopLevelDeclList");rhs.push_back("TopLevelDeclList SEMICOLON  TopLevelDecl");}
    | TopLevelDecl  {lhs.push_back("TopLevelDeclList");rhs.push_back("TopLevelDecl");
      $$=$1;}
    ;

TopLevelDecl:
	Declaration {lhs.push_back("TopLevelDecl");rhs.push_back("Declaration");
		//normal declaration for global variables
		$$=$1;
	}	
	| FunctionDecl {lhs.push_back("TopLevelDecl");rhs.push_back("FunctionDecl");
	  	$$=$1;
	  
	  }
	| MethodDecl {lhs.push_back("TopLevelDecl");rhs.push_back("MethodDecl");
		//unimplemented for now
	}
	;

TypeLit:
	ArrayType {lhs.push_back("TypeLit");rhs.push_back("ArrayType");
		$$=$1;
	}
	| StructType {lhs.push_back("TypeLit");rhs.push_back("StructType");
		//unimplemented for now TODO
	}
	| PointerType {lhs.push_back("TypeLit");rhs.push_back("PointerType");}
	| FunctionType {lhs.push_back("TypeLit");rhs.push_back("FunctionType");}
	;


//change

Type:
	TypeName {lhs.push_back("Type");rhs.push_back("TypeName");}
	| TypeLit {lhs.push_back("Type");rhs.push_back("TypeLit");}
	;

Operand:
	Literal {
	lhs.push_back("Operand");rhs.push_back("Literal");
	//cout << "here\n";
	$$=$1;
	}
	| OperandName {
	lhs.push_back("Operand");rhs.push_back("OperandName");
	$$=$1;
	}
	| LPAREN Expression RPAREN {
	lhs.push_back("Operand");rhs.push_back("LPAREN Expression RPAREN");
	$$=$2;
	};

OperandName:
	IDENTIFIER {
	lhs.push_back("OperandName");rhs.push_back("IDENTIFIER");
	//check
	check_entry($1,curr);
	(*$$).value=strdup($1);
	$1=(*$$).value;
	}
;

ReturnStmt:
	RETURN Expression {lhs.push_back("ReturnStmt");rhs.push_back("RETURN Expression");
		string tac = to_string(lineno);
		tac.append(",return,");
		tac.append($2->value);
		tac.append("\n");
		prog.push_back(tac);
		lineno++;
		$$=$2;
	}
	|RETURN {lhs.push_back("ReturnStmt");rhs.push_back("RETURN");
		//TODO
		string tac = to_string(lineno);
		tac.append(",exit\n");
		prog.push_back(tac);
		lineno++;
		$$->value = strdup("");
	};

BreakStmt:
	BREAK Label {lhs.push_back("BreakStmt");rhs.push_back("BREAK Label");
		//unimplemented
	}
	| BREAK {lhs.push_back("BreakStmt");rhs.push_back("BREAK");
		string tac = to_string(lineno);
		tac.append(",goto,");
		tac.append(for_endlabels.top());
		tac.append("\n");
		prog.push_back(tac);
		lineno++;
	};

ContinueStmt:
	CONTINUE Label {lhs.push_back("ContinueStmt");rhs.push_back("CONTINUE Label");
		//unimplemented
	}
	|CONTINUE {lhs.push_back("ContinueStmt");rhs.push_back("CONTINUE");
		string tac = to_string(lineno);
		tac.append(",goto,");
		tac.append(for_continuelabels.top());
		tac.append("\n");
		prog.push_back(tac);
		lineno++;
	}
	;

IfStmt:
	IF OPENB Expression if_mark1 Block if_mark2 CLOSEB{
	lhs.push_back("IfStmt");rhs.push_back("IF OPENB Expression Block CLOSEB");
	}//{printf("IF case 1");}
	|IF OPENB SimpleStmt SEMICOLON Expression if_mark1 Block CLOSEB {lhs.push_back("IfStmt");rhs.push_back("IF OPENB SimpleStmt SEMICOLON Expression Block CLOSEB");}//{printf("IF case 2");}
	|IF OPENB SimpleStmt SEMICOLON Expression if_mark1 Block if_markend1 ELSE IfStmt CLOSEB  {lhs.push_back("IfStmt");rhs.push_back("IF OPENB SimpleStmt SEMICOLON Expression Block ELSE IfStmt CLOSEB");}//{printf("IF case 3");}
	|IF OPENB SimpleStmt SEMICOLON Expression if_mark1 Block if_markend1 ELSE  Block CLOSEB {lhs.push_back("IfStmt");rhs.push_back("IF OPENB SimpleStmt SEMICOLON Expression Block ELSE  Block CLOSEB");}//{printf("IF case 4");}
	|IF OPENB Expression if_mark1 Block if_markend1 ELSE if_mark22 IfStmt if_markend2 CLOSEB if_markend {lhs.push_back("IfStmt");rhs.push_back("IF OPENB Expression Block ELSE IfStmt CLOSEB");}//{printf("IF case 5");}
	|IF OPENB Expression if_mark1 Block if_markend1 ELSE if_mark22 Block if_markend2 CLOSEB if_markend {lhs.push_back("IfStmt");rhs.push_back("IF OPENB Expression Block ELSE  Block CLOSEB");}//{printf("IF case 6");}
	;

if_mark1: {
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
	};

if_mark2: {	//
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
	};

//from here for if else

if_markend1: {
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
	};	

if_mark22: {
		string tac;
		tac=to_string(lineno);
		tac.append(",");
		tac.append("label,");
		string toget_label = if_bwlabels.top();
		if_bwlabels.pop();
		tac.append(toget_label+"\n");//TO correct
		prog.push_back(tac);
		lineno++;
	};

if_markend2: {
		string tac;
		tac=to_string(lineno);
		tac.append(",");
		tac.append("goto,");
		string toget_label = if_endlabels.top();
		tac.append(toget_label+"\n");//TO correct
		prog.push_back(tac);
		lineno++;
	};
if_markend: {
		string tac;
		tac=to_string(lineno);
		tac.append(",");
		tac.append("label,");
		string togo_label = if_endlabels.top();	//top of second stack
		if_endlabels.pop();				//pop here
		tac.append(togo_label+"\n");//TO correct
		prog.push_back(tac);
		lineno++;
	};				
//till here for if else


ForStmt:
	FOR OPENB for_initmark Condition for_mark1 Block for_mark2 CLOSEB for_markend1 {lhs.push_back("ForStmt");rhs.push_back("FOR OPENB Condition Block CLOSEB");}
	|FOR OPENB for_initmark ForClause Block for_mark22 CLOSEB for_markend1 {lhs.push_back("ForStmt");rhs.push_back("FOR OPENB ForClause Block CLOSEB");}
	;
Condition:
	Expression {lhs.push_back("Condition");rhs.push_back("Expression");};

ForClause:
	InitStmt for_clause_mark1 SEMICOLON Condition for_clause_mark2 SEMICOLON PostStmt for_clause_mark3 {lhs.push_back("ForClause");rhs.push_back("InitStmt SEMICOLON Condition SEMICOLON PostStmt");}
	;
InitStmt:
	SimpleStmt {lhs.push_back("InitStmt");rhs.push_back("SimpleStmt");};
PostStmt:
	SimpleStmt {lhs.push_back("PostStmt");rhs.push_back("SimpleStmt");
	
	//can't end with identifier -- end with +0
	};

//for markers start here
//for - 2

for_clause_mark1:{
		for_initlabels.pop();
		for_continuelabels.pop();
		string tac;
		tac = to_string(lineno);
		string for_initlabel = get_label();
		tac.append(",label,"+for_initlabel+"\n");
		for_initlabels.push(for_initlabel);
		//newfor_continuelabels.push(for_initlabel);
		prog.push_back(tac);
		lineno++;

	};

for_clause_mark2: {	
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
		//new
		for_continuelabels.push(for_postlabel);
		prog.push_back(tac);
		lineno++;
		
	};	
	
for_clause_mark3:
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
	};

for_mark22: {
		string tac;
		tac=to_string(lineno);
		tac.append(",goto,");
		string togo_postlabel = for_postlabels.top();
		for_postlabels.pop();
		tac.append(togo_postlabel+"\n");
		prog.push_back(tac);
		lineno++;
	};			

//for - 1 
for_initmark:{
		string tac;
		tac = to_string(lineno);
		string for_initlabel = get_label();
		tac.append(",label,"+for_initlabel+"\n");
		for_initlabels.push(for_initlabel);
		for_continuelabels.push(for_initlabel);
		prog.push_back(tac);
		lineno++;
	};

for_mark1: {	
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
	};

for_mark2: {
		string tac;
		tac=to_string(lineno);
		tac.append(",goto,");
		string togo_label = for_initlabels.top();
		for_initlabels.pop();
		//for_continuelabels.pop();
		tac.append(togo_label+"\n");
		prog.push_back(tac);
		lineno++;
	};

for_markend1: {
		string tac;
		tac=to_string(lineno);
		tac.append(",label,");
		string for_endlabel = for_endlabels.top();
		for_endlabels.pop();
		for_continuelabels.pop();
		tac.append(for_endlabel+"\n");
		prog.push_back(tac);
		lineno++;
	};	

//for markers end here

int_lit:
	INTEGER{
	//cout << $1 << endl;
	(*$$).value=strdup($1);
	//cout << "here integer\n";
	//cout << (*$$).value << endl;
	$1=(*$$).value;
	//cout << $1 << endl;
	//cout << (*$$).value << endl;
	lhs.push_back("int_lit");rhs.push_back("INTEGER");
	
	}
	;
float_lit:
	  FLOAT{
	  (*$$).value=strdup($1);
	  //cout << "here integer\n";
	  //cout << (*$$).value << endl;
	  $1=(*$$).value;
	  lhs.push_back("float_lit");rhs.push_back("FLOAT");}
	  ;



TypeName:
	IDENTIFIER {
	(*$$).value=strdup($1);
	//cout << "here integer\n";
	//cout << (*$$).value << endl;
	$1=(*$$).value;
	lhs.push_back("TypeName");rhs.push_back("IDENTIFIER");
	}
	| VAR_TYPE {
	(*$$).value=strdup($1);
	//cout << "here integer\n";
	//cout << (*$$).value << endl;
	$1=(*$$).value;
	lhs.push_back("TypeName");rhs.push_back("VAR_TYPE");
	}
	;



ArrayType:
	LBRACK ArrayLength RBRACK Type{lhs.push_back("ArrayType");rhs.push_back("LBRACK ArrayLength RBRACK Type");
		string temp_str = "";
		temp_str.append($1);
		temp_str.append($2->value);
		temp_str.append($3);
		temp_str.append($4->value);
		$$->value = strdup(temp_str.c_str());
	}
	;

ArrayLength:
	Expression{lhs.push_back("ArrayLength");rhs.push_back("Expression");
		$$=$1;
	}
	;

StructType:
    STRUCT LBRACE FieldDeclList RBRACE {lhs.push_back("StructType");rhs.push_back("STRUCT LBRACE FieldDeclList RBRACE");}
    | STRUCT LBRACE RBRACE {lhs.push_back("StructType");rhs.push_back("STRUCT LBRACE RBRACE");}
    ;

FieldDeclList:
    FieldDecl SEMICOLON {lhs.push_back("FieldDeclList");rhs.push_back("FieldDecl SEMICOLON");}
    | FieldDeclList FieldDecl SEMICOLON {lhs.push_back("FieldDeclList");rhs.push_back("FieldDeclList FieldDecl SEMICOLON");}
    ;

FieldDecl:
	IdentifierList Type {lhs.push_back("FieldDecl");rhs.push_back("IdentifierList Type");}
	| IdentifierList Type Tag {lhs.push_back("FieldDecl");rhs.push_back("IdentifierList Type Tag");}
	;

Tag:
	STRING {
	(*$$).value=strdup($1);
	$1=(*$$).value;
	lhs.push_back("Tag");rhs.push_back("STRING");}
	;

PointerType:
	MUL BaseType {lhs.push_back("PointerType");rhs.push_back("MUL BaseType");
		//TODO
		//symbol table
		string temp_str = "";
		temp_str.append($1);
		temp_str.append($2->value);
		$$->value = strdup(temp_str.c_str());
	}
	;
BaseType:
	Type {lhs.push_back("BaseType");rhs.push_back("Type");}
	;

FunctionType:
	FUNC Signature {lhs.push_back("FunctionType");rhs.push_back("FUNC Signature");
		//unimplemented
	}
	;

ConstDecl:
		CONST ConstSpec {lhs.push_back("ConstDecl");rhs.push_back("CONST ConstSpec");
			///symbol table - put is_constant = 1 in symtab
			$$=$2;
		}
		;

ConstSpec:
		IDENTIFIER Type ASSIGN Expression {lhs.push_back("ConstSpec");rhs.push_back("IDENTIFIER Type ASSIGN Expression");
			(*$$).value=strdup($1);
			$1=(*$$).value;
			//update type in symbol table here and isconstant in constdecl
			string tac = to_string(lineno);
			tac.append(",=,");
			tac.append($1);
			tac.append(",");
			tac.append($4->value);
			tac.append("\n");
			prog.push_back(tac);
			lineno++;
			insert($1,curr,$2->value);
		}
		| IDENTIFIER Type {lhs.push_back("ConstSpec");rhs.push_back("IDENTIFIER Type");
			(*$$).value=strdup($1);
			$1=(*$$).value;
			insert($1,curr,$2->value);
			//update type in symbol table here and isconstant in constdecl
		}
		;

ExpressionList:
		ExpressionList COMMA Expression {
		lhs.push_back("ExpressionList");rhs.push_back("ExpressionList COMMA Expression");
		//TODO
			expressionlist_str = $1->value;
			expressionlist_str.append(",");
			expressionlist_str.append($3->value);
			(*$$).value = strdup(expressionlist_str.c_str());
		
		}
		| Expression {
		lhs.push_back("ExpressionList");rhs.push_back("Expression");
		$$=$1;
		}
		;

TypeDecl:
		TYPE  TypeSpec {lhs.push_back("TypeDecl");rhs.push_back("TYPE  TypeSpec");}
		| TYPE LPAREN TypeSpecList RPAREN {lhs.push_back("TypeDecl");rhs.push_back("TYPE LPAREN TypeSpecList RPAREN");};

TypeSpecList:
		TypeSpecList TypeSpec SEMICOLON {lhs.push_back("TypeSpecList");rhs.push_back("TypeSpecList TypeSpec SEMICOLON");}
		| TypeSpec SEMICOLON {lhs.push_back("TypeSpecList");rhs.push_back("TypeSpec SEMICOLON");}
		;
TypeSpec:
		AliasDecl {lhs.push_back("TypeSpec");rhs.push_back("AliasDecl");}
		| TypeDef {lhs.push_back("TypeSpec");rhs.push_back("TypeDef");};

AliasDecl:
		IDENTIFIER ASSIGN Type {lhs.push_back("AliasDecl");rhs.push_back("IDENTIFIER ASSIGN Type");}
		;

TypeDef:
		IDENTIFIER Type {lhs.push_back("TypeDef");rhs.push_back("IDENTIFIER Type");}
		;




Literal:
	BasicLit {
	lhs.push_back("Literal");rhs.push_back("BasicLit");
	$$=$1;
	}
	//| FunctionLit {lhs.push_back("Literal");rhs.push_back("FunctionLit");} //unimplemented
	;

string_lit:
	STRING {
	(*$$).value=strdup($1);
	$1=(*$$).value;
	lhs.push_back("string_lit");rhs.push_back("STRING");
	}
	;

//added later
byte_lit:
	BYTE {
	(*$$).value=strdup($1);
	$1=(*$$).value;
	lhs.push_back("byte_lit");rhs.push_back("BYTE");}
	;
	
BasicLit:
	int_lit {
	lhs.push_back("BasicLit");rhs.push_back("int_lit");
	$$=$1;
	//cout << "at basic lit" << endl;
	//cout << $1->value << endl;
	//cout << $$->value << endl;
	//printf("%s\n",(char*)$1);
	}
	| float_lit {lhs.push_back("BasicLit");rhs.push_back("float_lit");}
	| string_lit {lhs.push_back("BasicLit");rhs.push_back("string_lit");
		//symbol table
		string temp_str = $1->value;
		string temp_var = get_temp_strvar();
		string tac = to_string(lineno);
		tac.append(",string,");
		tac.append(temp_var);
		tac.append(",");
		tac.append(temp_str);
		tac.append("\n");
		prog.push_back(tac);
		lineno++;
		(*$$).value = strdup(temp_var.c_str());
		
	}
	| byte_lit {lhs.push_back("BasicLit");rhs.push_back("byte_lit");}	//added later
	;


/*FunctionLit:
	FUNC Function {lhs.push_back("FunctionLit");rhs.push_back("FUNC Function");};*/	//unimplemented
//-----------------------------------------------------------------------------start
PrimaryExpr:
	Operand {
	lhs.push_back("PrimaryExpr");rhs.push_back("Operand");
	$$=$1;
	}|
	PrimaryExpr Selector {lhs.push_back("PrimaryExpr");rhs.push_back("PrimaryExpr Selector");
		string temp_str = "";
		temp_str.append($1->value);
		temp_str.append($2->value);
		(*$$).value = strdup(temp_str.c_str());
	}|
	PrimaryExpr Index {lhs.push_back("PrimaryExpr");rhs.push_back("PrimaryExpr Index");
		//take care of array index here
		string temp_str = "";
		temp_str.append($1->value);
		temp_str.append($2->value);
		(*$$).value = strdup(temp_str.c_str());
	}|
	PrimaryExpr TypeAssertion {lhs.push_back("PrimaryExpr");rhs.push_back("PrimaryExpr TypeAssertion");
		//unimplemented
	}|
	OperandName StructLiteral {lhs.push_back("PrimaryExpr");rhs.push_back("OperandName StructLiteral");
		//unimplemented for now
	}
	;
//------------------------------------------------------------------------------end
//here struct literal //TODO
StructLiteral:
    LBRACE KeyValList RBRACE {lhs.push_back("StructLiteral");rhs.push_back("LBRACE KeyValList RBRACE");}
    ;

KeyValList:
    	/* empty */  {lhs.push_back("KeyValList");rhs.push_back("/* empty */");}
 	| Expression COLON Expression {lhs.push_back("KeyValList");rhs.push_back("Expression COLON Expression");}
	| KeyValList COMMA Expression COLON Expression  {lhs.push_back("KeyValList");rhs.push_back("KeyValList COMMA Expression COLON Expression");}
	;
//till here struct literal

Selector:
	PERIOD IDENTIFIER {lhs.push_back("Selector");rhs.push_back("PERIOD IDENTIFIER");
	//check 
	//not implemeted for now
	string temp_str = "";
	temp_str.append($1);
	temp_str.append($2);
	(*$$).value = strdup(temp_str.c_str());
	};
Index:	
	LBRACK Expression RBRACK {lhs.push_back("Index");rhs.push_back("LBRACK Expression RBRACK");
		string temp_str = "[";
		temp_str.append($2->value);
		temp_str.append("]");
		(*$$).value = strdup(temp_str.c_str());
	};


TypeAssertion:
	PERIOD LPAREN Type RPAREN {lhs.push_back("TypeAssertion");rhs.push_back("PERIOD LPAREN Type RPAREN");
		//unimplemented
	}
	;

Expression:
    Expression1 {
    lhs.push_back("Expression");rhs.push_back("Expression1");
    $$=$1;
    }
    ;

Expression1:
    Expression1 LOR Expression2 {	//typecheck LOR
    lhs.push_back("Expression1");rhs.push_back("Expression1 LOR Expression2");
    string temp_var = get_tempvar();
    string tac;
    tac.append(to_string(lineno));
    tac.append(",");
    tac.append($2);
    tac.append(",");
    tac.append(temp_var);
    tac.append(",");
    tac.append($1->value);
    tac.append(",");
    tac.append($3->value);
    tac.append("\n");
    prog.push_back(tac);
    lineno++;
    strcpy((*$$).value,temp_var.c_str());
    }//{cout << "expr21";}
    | Expression2 {
    lhs.push_back("Expression1");rhs.push_back("Expression2");
    $$=$1;
    }
    ;

Expression2:
    Expression2 LAND Expression3 {	//typecheck LAND
    lhs.push_back("Expression2");rhs.push_back("Expression2 LAND Expression3");
    string temp_var = get_tempvar();
    string tac;
    tac.append(to_string(lineno));
    tac.append(",");
    tac.append($2);
    tac.append(",");
    tac.append(temp_var);
    tac.append(",");
    tac.append($1->value);
    tac.append(",");
    tac.append($3->value);
    tac.append("\n");
    prog.push_back(tac);
    lineno++;
    strcpy((*$$).value,temp_var.c_str());
    }
    | Expression3 {
    lhs.push_back("Expression2");rhs.push_back("Expression3");
    $$=$1;
    }
    ;

Expression3:
    Expression3 rel_op Expression4 {
    lhs.push_back("Expression3");rhs.push_back("Expression3 rel_op Expression4");
    string temp_var = get_tempvar();
    string tac;
    tac.append(to_string(lineno));
    tac.append(",");
    tac.append($2->value);
    tac.append(",");
    tac.append(temp_var);
    tac.append(",");
    tac.append($1->value);
    tac.append(",");
    tac.append($3->value);
    tac.append("\n");
    prog.push_back(tac);
    lineno++;
    strcpy((*$$).value,temp_var.c_str());
    }
    | Expression4 {
    lhs.push_back("Expression3");rhs.push_back("Expression4");
    $$=$1;
    }
    ;

Expression4:
    Expression4 add_op Expression5 {
    lhs.push_back("Expression4");rhs.push_back("Expression4 add_op Expression5");
    string temp_var = get_tempvar();
    string tac;
    tac.append(to_string(lineno));
    tac.append(",");
    tac.append($2->value);
    tac.append(",");
    tac.append(temp_var);
    tac.append(",");
    tac.append($1->value);
    tac.append(",");
    tac.append($3->value);
    tac.append("\n");
    prog.push_back(tac);
    lineno++;
    strcpy((*$$).value,temp_var.c_str());
    }
    | Expression5 {
    lhs.push_back("Expression4");rhs.push_back("Expression5");
    $$=$1;
    }
    ;

Expression5:
    Expression5 mul_op PrimaryExpr {
    lhs.push_back("Expression5");rhs.push_back("Expression5 mul_op PrimaryExpr");
    string temp_var = get_tempvar();
    string tac;
    tac.append(to_string(lineno));
    tac.append(",");
    tac.append($2->value);
    tac.append(",");
    tac.append(temp_var);
    tac.append(",");
    tac.append($1->value);
    tac.append(",");
    tac.append($3->value);
    tac.append("\n");
    prog.push_back(tac);
    lineno++;
    strcpy((*$$).value,temp_var.c_str());
    }
    | UnaryExpr {
    lhs.push_back("Expression5");rhs.push_back("UnaryExpr");
    $$=$1;
    }
    ;
    
//till here*/	

UnaryExpr:
	PrimaryExpr {
	lhs.push_back("UnaryExpr");rhs.push_back("PrimaryExpr");
	$$=$1;
	}
	| unary_op PrimaryExpr {
	lhs.push_back("UnaryExpr");rhs.push_back("unary_op PrimaryExpr");
	//TODO	
		string temp_str = "";
		temp_str.append($1->value);
		temp_str.append($2->value);
		(*$$).value=strdup(temp_str.c_str());
		//for now its pushing -5, *6 sort of things
	}
	//UnaryExpr {lhs.push_back("UnaryExpr");rhs.push_back("UnaryExpr");}
	;

//ops using tokens
/*
binary_op:
	LOR {
	(*$$).value=strdup($1);
	$1=(*$$).value;
	lhs.push_back("binary_op");rhs.push_back("LOR");}
	| LAND {
	(*$$).value=strdup($1);
	$1=(*$$).value;
	lhs.push_back("binary_op");rhs.push_back("LAND");}
	| rel_op {lhs.push_back("binary_op");rhs.push_back("rel_op");}
	| add_op {lhs.push_back("binary_op");rhs.push_back("add_op");}
	| mul_op {lhs.push_back("binary_op");rhs.push_back("mul_op");};*/
rel_op:
	EQL {
	(*$$).value=strdup($1);
	$1=(*$$).value;
	lhs.push_back("rel_op");rhs.push_back("EQL");}
	| NEQ {
	(*$$).value=strdup($1);
	$1=(*$$).value;
	lhs.push_back("rel_op");rhs.push_back("NEQ");}
	| LSS {
	(*$$).value=strdup($1);
	$1=(*$$).value;
	lhs.push_back("rel_op");rhs.push_back("LSS");}
	| LEQ {
	(*$$).value=strdup($1);
	$1=(*$$).value;
	lhs.push_back("rel_op");rhs.push_back("LEQ");}
	| GTR {
	(*$$).value=strdup($1);
	$1=(*$$).value;
	lhs.push_back("rel_op");rhs.push_back("GTR");}
	| GEQ {
	(*$$).value=strdup($1);
	$1=(*$$).value;
	lhs.push_back("rel_op");rhs.push_back("GEQ");};
add_op:
	ADD {
	(*$$).value=strdup($1);
	$1=(*$$).value;
	lhs.push_back("add_op");rhs.push_back("ADD");}
	| SUB {
	(*$$).value=strdup($1);
	$1=(*$$).value;
	lhs.push_back("add_op");rhs.push_back("SUB");}
	| OR {
	(*$$).value=strdup($1);
	$1=(*$$).value;
	lhs.push_back("add_op");rhs.push_back("OR");}
	| XOR {
	(*$$).value=strdup($1);
	$1=(*$$).value;
	lhs.push_back("add_op");rhs.push_back("XOR");};
mul_op:
	MUL {
	(*$$).value=strdup($1);
	$1=(*$$).value;
	lhs.push_back("mul_op");rhs.push_back("MUL");}
	| QUO {
	(*$$).value=strdup($1);
	$1=(*$$).value;
	lhs.push_back("mul_op");rhs.push_back("QUO");}
	| REM {
	(*$$).value=strdup($1);
	$1=(*$$).value;
	lhs.push_back("mul_op");rhs.push_back("REM");}
	| SHL {
	(*$$).value=strdup($1);
	$1=(*$$).value;
	lhs.push_back("mul_op");rhs.push_back("SHL");}
	| SHR {
	(*$$).value=strdup($1);
	//cout << "here integer\n";
	//cout << (*$$).value << endl;
	$1=(*$$).value;
	lhs.push_back("mul_op");rhs.push_back("SHR");}
	| AND {
	(*$$).value=strdup($1);
	//cout << "here integer\n";
	//cout << (*$$).value << endl;
	$1=(*$$).value;
	lhs.push_back("mul_op");rhs.push_back("AND");}
	| AND_NOT {
	(*$$).value=strdup($1);
	//cout << "here integer\n";
	//cout << (*$$).value << endl;
	$1=(*$$).value;
	lhs.push_back("mul_op");rhs.push_back("AND_NOT");};
//-------------------------------------------------------------------------------------------start
unary_op:
	ADD {
	(*$$).value=strdup($1);
	//cout << "here integer\n";
	//cout << (*$$).value << endl;
	$1=(*$$).value;
	lhs.push_back("unary_op");rhs.push_back("ADD");}
	| SUB {
	(*$$).value=strdup($1);
	//cout << "here integer\n";
	//cout << (*$$).value << endl;
	$1=(*$$).value;
	lhs.push_back("unary_op");rhs.push_back("SUB");}
	| NOT {
	(*$$).value=strdup($1);
	//cout << "here integer\n";
	//cout << (*$$).value << endl;
	$1=(*$$).value;
	lhs.push_back("unary_op");rhs.push_back("NOT");}
	| XOR {
	(*$$).value=strdup($1);
	//cout << "here integer\n";
	//cout << (*$$).value << endl;
	$1=(*$$).value;
	lhs.push_back("unary_op");rhs.push_back("XOR");}
	| MUL {
	(*$$).value=strdup($1);
	//cout << "here integer\n";
	//cout << (*$$).value << endl;
	$1=(*$$).value;
	lhs.push_back("unary_op");rhs.push_back("MUL");}
	| AND {
	(*$$).value=strdup($1);
	//cout << "here integer\n";
	//cout << (*$$).value << endl;
	$1=(*$$).value;
	lhs.push_back("unary_op");rhs.push_back("AND");}
	;
//----------------------------------------------------------------------------------------------------------------end

assign_op:
	  ASSIGN {
	  lhs.push_back("assign_op");rhs.push_back("ASSIGN");
	  (*$$).value=strdup($1);
	  $1 = (*$$).value;
	  }
	| ADD_ASSIGN {
	(*$$).value=strdup($1);
	$1=(*$$).value;
	lhs.push_back("assign_op");rhs.push_back("ADD_ASSIGN");
	}
	| SUB_ASSIGN {
	(*$$).value=strdup($1);
	$1=(*$$).value;
	lhs.push_back("assign_op");rhs.push_back("SUB_ASSIGN");
	}
	| MUL_ASSIGN {
	(*$$).value=strdup($1);
	$1=(*$$).value;
	lhs.push_back("assign_op");rhs.push_back("MUL_ASSIGN");
	}
	| QUO_ASSIGN {lhs.push_back("assign_op");rhs.push_back("QUO_ASSIGN");
	(*$$).value=strdup($1);
	$1=(*$$).value;
	}
	| REM_ASSIGN {lhs.push_back("assign_op");rhs.push_back("REM_ASSIGN");
	  (*$$).value=strdup($1);
	  $1=(*$$).value;
	  }
	;
/*IfStmt shift/reduce conflict*/

PackageClause:
	/*PACKAGE*/PACKAGE PackageName {lhs.push_back("PackageClause");rhs.push_back("PACKAGE PackageName");
		//new
		/*string tac = to_string(lineno) + ",call," + $2->value;
		tac.append(",0\n");
		prog.push_back(tac);
		lineno++;
		tac = to_string(lineno) + ",exit\n";
		prog.push_back(tac);
		lineno++;*/
		//new
		string tac = to_string(lineno) + ",goto," + $2->value + "_prog\n";
		//tac.append(",0\n");
		prog.push_back(tac);
		lineno++;
		insert("print",curr,"function");
		insert("fmt.Println",curr,"function");
		insert("fmt.Scanln",curr,"function");
	}//{printf("here i get package");}
	;
PackageName:
	IDENTIFIER {lhs.push_back("PackageName");rhs.push_back("IDENTIFIER");
	(*$$).value=strdup($1);
	//cout << "here integer\n";
	//cout << (*$$).value << endl;
	$1=(*$$).value;
	}//{printf("-----************package1--------");
	;
	
ImportDeclList:
    //* empty */ {  }    |
      ImportDeclList ImportDecl  {lhs.push_back("ImportDeclList");rhs.push_back("ImportDeclList ImportDecl");}//{ printf("got import list 1");}
    | ImportDecl  {lhs.push_back("ImportDeclList");rhs.push_back("ImportDecl");
      //cout << "at start of import list\n";
      $$=$1;
      }//{ printf("got import list 2"); }
    | /*empty*/ {lhs.push_back("ImportDeclList");rhs.push_back("/*empty*/");
      //cout << "at start empty of import list\n";
      //$$->value=NULL;
      //cout << "at start empty end of import list\n";
      }//{ printf("got import list 3");}
    ;

ImportDecl:
	IMPORT ImportSpec SEMICOLON {lhs.push_back("ImportDecl");rhs.push_back("IMPORT ImportSpec SEMICOLON");}//{printf("got imports 1");}
	| IMPORT LPAREN ImportSpecList  RPAREN {lhs.push_back("ImportDecl");rhs.push_back("IMPORT LPAREN ImportSpecList  RPAREN");}//{printf("got imports 2");}
	;

ImportSpecList:
	ImportSpecList ImportSpec SEMICOLON {lhs.push_back("ImportSpecList");rhs.push_back("ImportSpecList ImportSpec SEMICOLON");}
	| ImportSpec SEMICOLON {lhs.push_back("ImportSpecList");rhs.push_back("ImportSpec SEMICOLON");}
	;
ImportSpec:
	 PERIOD ImportPath {lhs.push_back("ImportSpec");rhs.push_back("PERIOD ImportPath");}
	| PackageName2 ImportPath {lhs.push_back("ImportSpec");rhs.push_back("PackageName2 ImportPath");}
	| PackageName2 {lhs.push_back("ImportSpec");rhs.push_back("PackageName2");
	  $$=$1;
	  };
ImportPath:
	string_lit {lhs.push_back("ImportPath");rhs.push_back("string_lit");
	$$=$1;
	}
	;
PackageName2:
	string_lit {lhs.push_back("PackageName2");rhs.push_back("string_lit");
	$$=$1;
	insert("fmt",curr,"package");
	}//{printf("-----package2----");}	
	;

%%


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
	//new
	fstream temp_stream;
	temp_stream.open("temporary.ir",ios_base::out);
	for(int i=0;i<prog.size();i++){
		temp_stream << prog[i];
	}
}












