#include <bits/stdc++.h>
using namespace std;

bool isInteger(string s)
{
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;

   char * p ;
   strtol(s.c_str(), &p, 10) ;

   return (*p == 0) ;
}

/*int main(){

	string numb ="-345";
	bool i = isInteger(numb);

	cout<< i;
}*/
