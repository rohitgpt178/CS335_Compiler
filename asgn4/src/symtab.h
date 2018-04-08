#include<bits/stdc++.h>
#include<unordered_map>
#include<map>
#include<string>

bool error_status = 0;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef struct s_entry{
	string type="NULL";
}s_entry;

typedef unordered_map <string,s_entry> symboltable;	//string = identifier or temporary variable

symboltable* new_symboltable(){
	symboltable* sym_pt = new symboltable;
	return sym_pt;
}

/*symboltable new_symboltable(){
	symboltable sym_temp;
	//cout << "CALLED newsymboltable**********\n";
	sym_temp["GROUP-47"].type = "DEFAULT";
	//symboltable* sym_pt = &sym_temp;
	//cout << "*****sizr of retunrd " << sym_temp.size() << endl;
	return sym_temp;
}*/

typedef struct table{
	symboltable* symtab;
	table *parent;//=NULL;
	int table_type=0;
	//table *child=NULL;
}table;

table * new_table(symboltable *map1,table *parent1/*,table *child1*/){
	//cout << "\n-1-";
	table *t1= (table*)malloc(sizeof(table));
	//cout << "-2-";
	t1->symtab = map1;
	//cout << "-3-";
	t1->parent = parent1;
	//cout << "-4-";
	t1->table_type = 0;
	//cout << "-5-\n";
	//t1->child = child1;
	return t1;
}

table * new_root_table(symboltable *map1/*,table *parent1/*,table *child1*/){
	table *t1= (table*)malloc(sizeof(table));
	t1->symtab = map1;
	t1->parent = NULL;
	t1->table_type = 1;
	//t1->child = child1;
	return t1;
}

s_entry * get_sentry(string type){
	s_entry *s1= (s_entry*)malloc(sizeof(s_entry));
	//s1->type = type;
	return s1;
}

bool look_in_map(string ident,symboltable *symtab1){
	int check = 0;
	
	symboltable &symtab = *symtab1;
	//cout << "SIze in look in map -----" << symtab.size() << endl;
	unordered_map<string, s_entry>:: iterator itr;
	if(symtab.size()==0){
		check=0;
	}
	else{
	for(itr=symtab.begin();itr!=symtab.end();itr++){
		//cout << "LOOKING FOR " << ident << " iiiiinnnnnn maaaaaap" << endl;
		if(itr->first==ident){
			check = 1;
			break;
		}
	}
	}
	return check;
}

bool lookup(string ident,table * t1){
	int check = 0;
	//while(t1!=NULL){
	table * temp1 = t1;
	//cout << "LOOKING FOR " << ident << endl;
	while(temp1->table_type!=1){
		if(look_in_map(ident,temp1->symtab)==1){
			check=1;
			break;
		}
		temp1=temp1->parent;		
	}
	return check;	
}

void check_entry(string ident,table *t){
	if(!lookup(ident,t)){
		cout << "ERROR: variable " << ident << " NOT declared.\n";
		error_status = 1;
	}
}

void insert_in_table(table *child,table * par){
	child->parent = par;
}

void insert(string ident,table *curr,string type){
	//cout << "inserting " << ident << " with type " << type << endl;
	//cout << "TPYE " << curr->table_type << endl;
	symboltable smt;
	symboltable *sm = &smt;
	if(!lookup(ident,curr)){
		//cout << "inside if\n";
		//cout << "TPYE of parent inside if " << curr->parent->table_type << endl;
		//cout << "size of symtab " << (*curr->symtab).size() << endl;
		(*curr->symtab)[ident].type = type;
		//cout << "size of symtab NOW " << (*curr->symtab).size() << endl;
		//cout << "outside if\n";
	}
	else{
		cout << "ERROR: variable " << ident << " ALREADY declared.\n";
		error_status = 1;
	}
}
//lookup
//addinsymtab
