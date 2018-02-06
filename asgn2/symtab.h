#include<bits/stdc++.h>
#include "tac.h"
using namespace std;

typedef struct details{
	public:
		bool status;
		int nextuse;
		string addr_desc = "";	 
}details;

extern unordered_map <string*,details*> symtab;

