#include<bits/stdc++.h>
using namespace std;

class tac{			//program will be scanned into a list(or map etc.) of objects of this class
	
	public:
	int lineno = 1;
	/*InstrType*/ string type = "";		//maybe define as enum type or mapping to types
	
	string in1 = "";				//SymTabEntry *in1;
	string in2 = "";				//SymTabEntry *in2;
	string out = "";				//SymTabEntry *out;		
		
	int target  = -1;
	string op = "";			//maybe define as enum type
	
	void get_details(){
		cout << "line = " << lineno << " type = " << type << " in1 = " << in1 << " in2 = " << in2 << " out = " << out << " target = " << target << " op = " << op << endl; 
	}
					//methods should be public
	/*void init_ir(string x,int y){	//this method will be called for each 3addr instruction
		type = x;
		target = y;
	}
	
	string getType(){
		return type;
	}
	
	int getTarget(){
		return target;
	}*/
};
extern vector <tac> prog;
extern vector <int> leaders;		//block leaders if i is in leaders then prog[i] = leader
