// Anyone who uses the global value must include the appropriate header.
#include "global.h"
#include<bits/stdc++.h>
using namespace std;
void SomeFunction()
{
    // Now you can access the variable.
    int temp = myglobalint;
	cout << temp << endl;
}

int main(){
	SomeFunction();
	return 0;
}
