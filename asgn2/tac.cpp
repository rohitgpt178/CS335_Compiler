#include<bits/stdc++.h>
#include "tac.h"
using namespace std;

vector <tac> prog;		//the whole ir code
int n_lines;
	
vector <int> leaders;		//block leaders if i is in leaders then prog[i] = leader

int n_block;
vector <int> start_block;
vector <int> end_block;

vector < vector <tuple <string,bool,int> > > updates;	//updates[i][0,1,or 2] gives one of 3 updates on symtab

unordered_map <string,string> addrdesc;			//done
unordered_map <string,string> regdesc;			


void enter_variables(unordered_map <string,details*> symtab[]){		//fills variables in sym_tabs
	//cout << n_lines << '\t' << n_block << endl;
	for(int i=0;i<n_block;i++){				//symtab[i] denotes ith (0 to n_block-1) block's symtable 
		/*int start_block = leaders[i];
		int end_block;
		if(i==n_block-1) end_block = n_lines;
		else end_block = leaders[i+1]-1;*/
		for(int j=start_block[i];j<=end_block[i];j++){
			//prog[j-1] = tac on jth line on ith block	
			//get only new variables from this tac
			if(prog[j-1].in1!=""){
				if(isInteger(prog[j-1].in1)!=1){
					string var_name = prog[j-1].in1;
					
					if(symtab[i].find(var_name)==symtab[i].end()){
						details * var_details = new details();
						symtab[i].insert(make_pair(var_name, var_details));						
					}
				}	
			}
			if(prog[j-1].in2!=""){
				if(isInteger(prog[j-1].in2)!=1){
					string var_name = prog[j-1].in2;
					if(symtab[i].find(var_name)==symtab[i].end()){
						details * var_details = new details();
						symtab[i].insert(make_pair(var_name, var_details));						
					}
				}	
			}
			if(prog[j-1].out!=""){
				if(isInteger(prog[j-1].out)!=1){
					string var_name = prog[j-1].out;
					if(symtab[i].find(var_name)==symtab[i].end()){
						details * var_details = new details();
						symtab[i].insert(make_pair(var_name, var_details));						
					}
				}	
			}
		}
		//cout << start_block << '\t' << end_block << endl;
	}
}

void fill_nextuse( unordered_map <string,details*> symtab,int start_block,int end_block){		
	//for one block only
	for(int i=end_block;i>=start_block;i--){	//i = line no.
		//copying from symtab to updates[i-1]	//for line i
		//prog[i-1] = ith line
		//cout << "here for from line " << start_block << " to " << end_block << " at line " << i << endl;
		string in_1 = prog[i-1].in1;
		string in_2 = prog[i-1].in2;
		string out_1 = prog[i-1].out;
		//cout << "variables " << in_1 << "&" << in_2 << "&" << out_1 << endl;
		if(out_1!="" && isInteger(out_1)!=1){
			//copying
			updates[i-1].push_back(make_tuple(out_1,symtab[out_1]->status,symtab[out_1]->nextuse));
			//updating
			symtab[out_1]->status = false;
			symtab[out_1]->nextuse = 0;
		}
		if(in_1!="" && isInteger(in_1)!=1){
			updates[i-1].push_back(make_tuple(in_1,symtab[in_1]->status,symtab[in_1]->nextuse));
			symtab[in_1]->status = true;
			symtab[in_1]->nextuse = i;
		}
		if(in_2!="" && isInteger(in_2)!=1){
			updates[i-1].push_back(make_tuple(in_2,symtab[in_2]->status,symtab[in_2]->nextuse));
			symtab[in_2]->status = true;
			symtab[in_2]->nextuse = i;
		}
	}
}

void print_symtab(unordered_map <string,details*> symtab[],int n_block){				//prints symbol_table
	for(int i=0;i<n_block;i++){
		cout << "----------Block " << i << "---------------" << endl;
		for (itr = symtab[i].begin(); itr != symtab[i].end(); itr++)
	    	{
			cout << itr->first << "\t" << itr->second->status << "\t" << itr->second->nextuse << endl;
	     	}
     	}
}

void fill_addrdesc(unordered_map <string,details*> symtab[],int n_block){
	for(int i=0;i<n_block;i++){
		for (itr = symtab[i].begin(); itr != symtab[i].end(); itr++)
		    	{
				if(addrdesc.find(itr->first)==addrdesc.end()){
					addrdesc.insert(make_pair(itr->first,"mem"));
					cout << "inserted " << itr->first << endl;
				}	
		     	}
	}
}

void print_addrdesc(){
	for (itr2 = addrdesc.begin(); itr2 != addrdesc.end(); itr2++)
	    	{
			cout << itr2->first << "\t" << itr2->second << endl;
	     	}
}

string getlocation(string var_name){
	return addrdesc[var_name];
} 

void setlocation(string var_name,string reg_name){
	addrdesc[var_name] = reg_name;
} 

void setregister(string reg_name,string var_name){
	regdesc[reg_name] = var_name;
}

/*string getreg(tac instr){			returns register for tac.out
	//x = y op z
	string y = instr.in1;	//y
	string z = instr.in2;	//z
	string x = instr.out;	//x
	
	if(){
	
	}
}*/

int main(int argc, char **argv){

	leaders.push_back(1);
	
	string line;
	ifstream mycode(argv[1]);
	
	int is_prev = 0;		//1 if is_prev is goto - for leader
	
	while(getline(mycode,line)){
		//cout << line << endl;
		//cout << typeid(line).name() << endl;
		//line.ignore(' ');
		istringstream str(line);
		//cout << "-------------" << endl;
		string token;
		int i = 1;
		
		tac ins_temp;
		while(getline(str,token,',')){
			//cout << token << '\t' << typeid(token).name() << '\n';
			
			if(i==1){			//getting line no.
				ins_temp.lineno = stoi(token);
			}
			else if(i==2){				
				if(token=="="){
					ins_temp.type = "assign1";					//handles x = 3, x = y[i] , x = *y
				}	
				else if(token=="+"||token=="-"||token=="*"||token=="/"||token=="%"){	//x = y op z check for x = op y
					ins_temp.type = "assign2";
					ins_temp.op = "token";
				}//add more operators
				else if(token=="ifgoto"){
					ins_temp.type = "ifgoto";
				}
				else if(token=="goto"){
					ins_temp.type = "goto";
				}
				/*else if(token=="param"){
					ins_temp.type = "param";
				}*/
				else if(token=="call"){
					ins_temp.type = "call";
				}
				else if(token=="label"){
					ins_temp.type = "label";
				}
				else if(token=="ret"){
					ins_temp.type = "return1";					//no further tokens
				}
				else if(token=="return"){
					ins_temp.type = "return2";
				}
				else if(token=="print"){
					ins_temp.type = "print";
				}
				//label??
			}
			else{
				if(ins_temp.type == "assign1"){						//ptr and index assignments??
					if(i==3)ins_temp.out = token;
					if(i==4)ins_temp.in1 = token;
				}
				else if(ins_temp.type == "assign2"){
					if(i==3)ins_temp.out = token;
					if(i==4)ins_temp.in1 = token;
					if(i==5)ins_temp.in2 = token;
				}
				else if(ins_temp.type == "ifgoto"){
					if(i==3)ins_temp.op = token;
					if(i==4)ins_temp.in1 = token;
					if(i==5)ins_temp.in2 = token;
					if(i==6)ins_temp.target = stoi(token);
				}
				else if(ins_temp.type == "goto"){
					if(i==3)ins_temp.target = stoi(token);
				}
				/*else if(ins_temp.type == "param"){
					if(i==3)ins_temp.in1 = token;
				}*/
				else if(ins_temp.type == "call"){
					if(i==3)ins_temp.in1 = token;
					//if(i==4)ins_temp.in2 = token;
				}
				else if(ins_temp.type == "label"){
					if(i==3)ins_temp.in1 = token;
				}
				else if(ins_temp.type == "return"){
					if(i==3)ins_temp.in1 = token;
				}
				else if(ins_temp.type == "print"){
					if(i==3)ins_temp.in1 = token;
				}
			}
			i++;
		}
		if(is_prev==1){
			leaders.push_back(ins_temp.lineno);
			//printf("HERE\n");
			is_prev = 0;
		}
		if(ins_temp.type == "ifgoto" || ins_temp.type == "goto"){
			leaders.push_back(ins_temp.target);
			//printf("HERE\n");
			is_prev = 1;
		}	
		prog.push_back(ins_temp);
		//printf("\n");		
	}
	
	n_lines = prog.size();
	sort(leaders.begin(),leaders.end());			//blocks in order- check for uniqeness?
	n_block = leaders.size();
	start_block = leaders;
	for(int i=0;i<leaders.size()-1;i++){
		end_block.push_back(leaders[i+1]-1);
	}
	end_block.push_back(n_lines);
	
	//symbol table
	unordered_map <string,details*> symtab[n_block];		//this denotes entire symtable 
	/*
	//<testing>
	string var1_name = "x";
	
	details * var1 = new details();
	var1->status = false;
	var1->nextuse = 5;
	
	symtab[0].insert(make_pair(var1_name, var1));
	
	for (itr = symtab[0].begin(); itr != symtab[0].end(); itr++)
    	{
        	// itr works as a pointer to pair<string, double>
        	// type itr->first stores the key part  and
        	// itr->second stroes the value part
        	cout << itr->first << "\t" << itr->second->status << "\t" << itr->second->nextuse << endl;
     	}
     	//</testing>
	*/
	enter_variables(symtab);
	fill_addrdesc(symtab,n_block);
	//<testing>
	/*for (itr = symtab[1].begin(); itr != symtab[1].end(); itr++)
    	{
        	// itr works as a pointer to pair<string, double>
        	// type itr->first stores the key part  and
        	// itr->second stroes the value part
        	cout << itr->first << "\t" << itr->second->status << "\t" << itr->second->nextuse << endl;
     	}*/
     	/*string key_temp = "cfds";
     	if(symtab[1].find(key_temp)==symtab[1].end()){
     		cout << "a is here!" << endl;
     	}*/
     	print_symtab(symtab,n_block);
     	print_addrdesc();
     	//</testing>
     	
     	updates.resize(n_lines);
     	/*for(int i=0;i<updates.size();i++){
     		updates[i].resize(3);
     	}*/
     	
     	//<testing>
     	/*updates[0].push_back(make_tuple("a",true,5));
     	for(int i=0;i<updates[0].size();i++){
     		cout << get<0>(updates[0][i]) << '\t' << get<1>(updates[0][i]) << '\t' << get<2>(updates[0][i]) << endl;
     	}*/
     	//cout << symtab[0]["a"]->status << " should be 0 \n";
     	//</testing>
     	
     	//nextuse filling for each block
     	for(int i=0;i<n_block;i++){
     		fill_nextuse(symtab[i],start_block[i],end_block[i]);
     	}
     	
     	//<testing>
     	//print_symtab(symtab,n_block);
     	/*cout << "-----------------------" << endl;
     	
     	cout << "-----------------------" << endl;
     	for(int j=0;j<updates.size();j++){
	     	for(int i=0;i<updates[j].size();i++){
	     		cout << j+1 << " : " <<get<0>(updates[j][i]) << '\t' << get<1>(updates[j][i]) << '\t' << get<2>(updates[j][i]) << endl;
	     	}
     	}*/
     	//</testing>
	
	
	
	
	return 0;
}
