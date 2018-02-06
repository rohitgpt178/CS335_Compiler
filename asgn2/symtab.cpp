#include<bits/stdc++.h>
#include "symtab.h"
//#include "tac.h"
using namespace std;

/*typedef struct details{
	public:
		bool status;
		int nextuse;
		string addr_desc = "";	 
}details;*/


int main(){
	
	unordered_map <string*,details*> symtab;				//this denotes one sym table
	
	//testing
	string * var1_name = new string();
	*var1_name = "x";
	
	details * var1 = new details();
	var1->status = false;
	var1->nextuse = 5;
	
	symtab.insert(make_pair(var1_name, var1));
	
	unordered_map<string*, details*>:: iterator itr;
	
	for (itr = symtab.begin(); itr != symtab.end(); itr++)
    	{
        	// itr works as a pointer to pair<string, double>
        	// type itr->first stores the key part  and
        	// itr->second stroes the value part
        	cout << *(itr->first) << "\t" << itr->second->status << "\t" << itr->second->nextuse << endl;
     	}
     	
     	vector <tac> prog;				//suppose it contains all the instructions
     	
     	cout << prog.size() << endl;
     	
     	//main code to be contd.
     	//next use implementation
     	
     	
     		
     	
     	
	return 0;
}
