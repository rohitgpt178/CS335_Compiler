#include<bits/stdc++.h>

using namespace std;

typedef struct details{
	public:
		bool status = false;	//true->live
		int nextuse = 0;
		//string addr_desc = "";	 
}details;

extern unordered_map <string,details*> symtab;

extern unordered_map <string,string> addrdesc;
extern unordered_map <string,string> regdesc;	//for now

unordered_map<string, details*>:: iterator itr;
unordered_map<string, string>:: iterator itr2;

