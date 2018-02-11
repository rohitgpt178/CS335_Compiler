#include <bits/stdc++.h>
#include "tac.h"
using namespace std;

//string blockcode="";

bool isInteger(string s)
{
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;

   char * p ;
   strtol(s.c_str(), &p, 10) ;

   return (*p == 0) ;
}

void codegen(tac instr,string &blockcode){

	string reg1, reg2, reg3, reg4, loc1, loc2, loc3;

	int i=0;

	//vector <tac> prog;

	//while (instr!=NULL){

		//int label_ret=0;

		if(instr.type=="assign2"){

			loc1=getlocation(instr.out);


			if(instr.op=="+"){

				if(loc1!="mem"){

					if(isInteger(instr.in1) && isInteger(instr.in2)){

						blockcode = blockcode + "addi " + loc1 + "," + instr.in1 + "," + instr.in2 + "\n";
					} else if(!isInteger(instr.in1) && isInteger(instr.in2)){
					
						loc2=getlocation(instr.in1);

						if(loc2!="mem"){
							blockcode = blockcode + "addi " + loc1 + "," + loc2 + "," + instr.in2 + "\n";
						}else{
							reg2=getReg(instr.in1, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in1 + "\n";
							blockcode = blockcode + "addi " + loc1 + ", " + reg2 + ", " + instr.in2 + "\n";
							setregister(reg2, instr.in1);
				        	setlocation(instr.in1, reg2);
						}
					} else if (!isInteger(instr.in1) && !isInteger(instr.in2)){

						loc2=getlocation(instr.in1);
						loc3=getlocation(instr.in2);

						if(loc2!="mem" && loc3!="mem"){
							blockcode = blockcode + "add " + loc1 + ", " + loc2 + ", " + loc3 + "\n";
						}else if(loc2=="mem" && loc3!="mem"){

							reg2=getReg(instr.in1, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in1 + "\n";
							blockcode = blockcode +  "add " + loc1 + ", " + reg2 + ", " + loc3;
							setregister(reg2, instr.in1);
				        	setlocation(instr.in1, reg2);

						}else if(loc2!="mem" && loc3=="mem"){

							reg2=getReg(instr.in2, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in2 + "\n";
							blockcode = blockcode +  "add " + loc1 + ", " + loc2 + ", " + reg2 + "\n";
							setregister(reg2, instr.in2);
				        	setlocation(instr.in2, reg2);

						}else if(loc2=="mem" && loc3=="mem"){

							reg2=getReg(instr.in1, instr, symtab);
							reg3=getReg(instr.in2, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in1 + "\n";
							blockcode = blockcode + "lw " + reg3 + ", " + instr.in2 + "\n";
							blockcode = blockcode +  "add " + loc1 + ", " + reg2 + ", " + reg3 + "\n";
							setregister(reg2, instr.in1);
				        	setlocation(instr.in1, reg2);

				        	setregister(reg3, instr.in2);
				        	setlocation(instr.in2, reg3);
						}
					}
				}else {

					reg1=getReg(instr.out, instr, symtab);

					if(isInteger(instr.in1) && isInteger(instr.in2)){

						blockcode = blockcode + "addi " + reg1 + "," + instr.in1 + "," + instr.in2 + "\n";
					} else if(!isInteger(instr.in1) && isInteger(instr.in2)){
					
						loc2=getlocation(instr.in1);

						if(loc2!="mem"){
							blockcode = blockcode + "addi " + reg1 + "," + loc2 + "," + instr.in2 + "\n";
						}else{
							reg2=getReg(instr.in1, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in1 + "\n";
							blockcode = blockcode + "addi " + reg1 + ", " + reg2 + ", " + instr.in2 + "\n";
							setregister(reg2, instr.in1);
				        	setlocation(instr.in1, reg2);
						}
					} else if (!isInteger(instr.in1) && !isInteger(instr.in2)){

						loc2=getlocation(instr.in1);
						loc3=getlocation(instr.in2);

						if(loc2!="mem" && loc3!="mem"){
							blockcode = blockcode + "add " + reg1 + ", " + loc2 + ", " + loc3 + "\n";
						}else if(loc2=="mem" && loc3!="mem"){

							reg2=getReg(instr.in1, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in1 + "\n";
							blockcode = blockcode +  "add " + reg1 + ", " + reg2 + ", " + loc3;
							setregister(reg2, instr.in1);
				        	setlocation(instr.in1, reg2);

						}else if(loc2!="mem" && loc3=="mem"){

							reg2=getReg(instr.in2, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in2 + "\n";
							blockcode = blockcode +  "add " + reg1 + ", " + loc2 + ", " + reg2 + "\n";
							setregister(reg2, instr.in2);
				        	setlocation(instr.in2, reg2);

						}else if(loc2=="mem" && loc3=="mem"){

							reg2=getReg(instr.in1, instr, symtab);
							reg3=getReg(instr.in2, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in1 + "\n";
							blockcode = blockcode + "lw " + reg3 + ", " + instr.in2 + "\n";
							blockcode = blockcode +  "add " + reg1 + ", " + reg2 + ", " + reg3 + "\n";
							setregister(reg2, instr.in1);
				        	setlocation(instr.in1, reg2);

				        	setregister(reg3, instr.in2);
				        	setlocation(instr.in2, reg3);
						}
					}

					setregister(reg1, instr.out);
				    setlocation(instr.out, reg1);
				}
			}

			if(instr.op=="-"){

				if(loc1!="mem"){

					if(isInteger(instr.in1) && isInteger(instr.in2)){

						blockcode = blockcode + "subi" + loc1 + "," + instr.in1 + "," + instr.in2 + "\n";
					} else if(!isInteger(instr.in1) && isInteger(instr.in2)){
					
						loc2=getlocation(instr.in1);

						if(loc2!="mem"){
							blockcode = blockcode + "subi" + loc1 + "," + loc2 + "," + instr.in2 + "\n";
						}else{
							reg2=getReg(instr.in1, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in1 + "\n";
							blockcode = blockcode + "subi " + loc1 + ", " + reg2 + ", " + instr.in2 + "\n";
							setregister(reg2, instr.in1);
				        	setlocation(instr.in1, reg2);
						}
					} else if (!isInteger(instr.in1) && !isInteger(instr.in2)){

						loc2=getlocation(instr.in1);
						loc3=getlocation(instr.in2);

						if(loc2!="mem" && loc3!="mem"){
							blockcode = blockcode + "sub " + loc1 + ", " + loc2 + ", " + loc3 + "\n";
						}else if(loc2=="mem" && loc3!="mem"){

							reg2=getReg(instr.in1, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in1 + "\n";
							blockcode = blockcode +  "sub " + loc1 + ", " + reg2 + ", " + loc3;
							setregister(reg2, instr.in1);
				        	setlocation(instr.in1, reg2);

						}else if(loc2!="mem" && loc3=="mem"){

							reg2=getReg(instr.in2, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in2 + "\n";
							blockcode = blockcode +  "sub " + loc1 + ", " + loc2 + ", " + reg2 + "\n";
							setregister(reg2, instr.in2);
				        	setlocation(instr.in2, reg2);

						}else if(loc2=="mem" && loc3=="mem"){

							reg2=getReg(instr.in1, instr, symtab);
							reg3=getReg(instr.in2, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in1 + "\n";
							blockcode = blockcode + "lw " + reg3 + ", " + instr.in2 + "\n";
							blockcode = blockcode +  "sub " + loc1 + ", " + reg2 + ", " + reg3 + "\n";
							setregister(reg2, instr.in1);
				        	setlocation(instr.in1, reg2);

				        	setregister(reg3, instr.in2);
				        	setlocation(instr.in2, reg3);
						}
					}
				}else {

					reg1=getReg(instr.out, instr, symtab);

					if(isInteger(instr.in1) && isInteger(instr.in2)){

						blockcode = blockcode + "subi" + reg1 + "," + instr.in1 + "," + instr.in2 + "\n";
					} else if(!isInteger(instr.in1) && isInteger(instr.in2)){
					
						loc2=getlocation(instr.in1);

						if(loc2!="mem"){
							blockcode = blockcode + "subi" + reg1 + "," + loc2 + "," + instr.in2 + "\n";
						}else{
							reg2=getReg(instr.in1, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in1 + "\n";
							blockcode = blockcode + "subi " + reg1 + ", " + reg2 + ", " + instr.in2 + "\n";
							setregister(reg2, instr.in1);
				        	setlocation(instr.in1, reg2);
						}
					} else if (!isInteger(instr.in1) && !isInteger(instr.in2)){

						loc2=getlocation(instr.in1);
						loc3=getlocation(instr.in2);

						if(loc2!="mem" && loc3!="mem"){
							blockcode = blockcode + "sub " + reg1 + ", " + loc2 + ", " + loc3 + "\n";
						}else if(loc2=="mem" && loc3!="mem"){

							reg2=getReg(instr.in1, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in1 + "\n";
							blockcode = blockcode +  "sub " + reg1 + ", " + reg2 + ", " + loc3;
							setregister(reg2, instr.in1);
				        	setlocation(instr.in1, reg2);

						}else if(loc2!="mem" && loc3=="mem"){

							reg2=getReg(instr.in2, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in2 + "\n";
							blockcode = blockcode +  "sub " + reg1 + ", " + loc2 + ", " + reg2 + "\n";
							setregister(reg2, instr.in2);
				        	setlocation(instr.in2, reg2);

						}else if(loc2=="mem" && loc3=="mem"){

							reg2=getReg(instr.in1, instr, symtab);
							reg3=getReg(instr.in2, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in1 + "\n";
							blockcode = blockcode + "lw " + reg3 + ", " + instr.in2 + "\n";
							blockcode = blockcode +  "sub " + reg1 + ", " + reg2 + ", " + reg3 + "\n";
							setregister(reg2, instr.in1);
				        	setlocation(instr.in1, reg2);

				        	setregister(reg3, instr.in2);
				        	setlocation(instr.in2, reg3);
						}
					}

					setregister(reg1, instr.out);
				    setlocation(instr.out, reg1);
				}
			}

			if(instr.op=="*"){

				if(loc1!="mem"){

					if(isInteger(instr.in1) && isInteger(instr.in2)){

						blockcode = blockcode + "mul " + loc1 + "," + instr.in1 + "," + instr.in2 + "\n";
					} else if(!isInteger(instr.in1) && isInteger(instr.in2)){
					
						loc2=getlocation(instr.in1);

						if(loc2!="mem"){
							blockcode = blockcode + "mul" + loc1 + "," + loc2 + "," + instr.in2 + "\n";
						}else{
							reg2=getReg(instr.in1, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in1 + "\n";
							blockcode = blockcode + "mul " + loc1 + ", " + reg2 + ", " + instr.in2 + "\n";
							setregister(reg2, instr.in1);
				        	setlocation(instr.in1, reg2);
						}
					} else if (!isInteger(instr.in1) && !isInteger(instr.in2)){

						loc2=getlocation(instr.in1);
						loc3=getlocation(instr.in2);

						if(loc2!="mem" && loc3!="mem"){
							blockcode = blockcode + "mul " + loc1 + ", " + loc2 + ", " + loc3 + "\n";
						}else if(loc2=="mem" && loc3!="mem"){

							reg2=getReg(instr.in1, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in1 + "\n";
							blockcode = blockcode +  "mul " + loc1 + ", " + reg2 + ", " + loc3;
							setregister(reg2, instr.in1);
				        	setlocation(instr.in1, reg2);

						}else if(loc2!="mem" && loc3=="mem"){

							reg2=getReg(instr.in2, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in2 + "\n";
							blockcode = blockcode +  "mul " + loc1 + ", " + loc2 + ", " + reg2 + "\n";
							setregister(reg2, instr.in2);
				        	setlocation(instr.in2, reg2);

						}else if(loc2=="mem" && loc3=="mem"){

							reg2=getReg(instr.in1, instr, symtab);
							reg3=getReg(instr.in2, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in1 + "\n";
							blockcode = blockcode + "lw " + reg3 + ", " + instr.in2 + "\n";
							blockcode = blockcode +  "mul " + loc1 + ", " + reg2 + ", " + reg3 + "\n";
							setregister(reg2, instr.in1);
				        	setlocation(instr.in1, reg2);

				        	setregister(reg3, instr.in2);
				        	setlocation(instr.in2, reg3);
						}
					}
				}else {

					reg1=getReg(instr.out, instr, symtab);

					if(isInteger(instr.in1) && isInteger(instr.in2)){

						blockcode = blockcode + "mul " + reg1 + "," + instr.in1 + "," + instr.in2 + "\n";
					} else if(!isInteger(instr.in1) && isInteger(instr.in2)){
					
						loc2=getlocation(instr.in1);

						if(loc2!="mem"){
							blockcode = blockcode + "mul " + reg1 + "," + loc2 + "," + instr.in2 + "\n";
						}else{
							reg2=getReg(instr.in1, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in1 + "\n";
							blockcode = blockcode + "mul " + reg1 + ", " + reg2 + ", " + instr.in2 + "\n";
							setregister(reg2, instr.in1);
				        	setlocation(instr.in1, reg2);
						}
					} else if (!isInteger(instr.in1) && !isInteger(instr.in2)){

						loc2=getlocation(instr.in1);
						loc3=getlocation(instr.in2);

						if(loc2!="mem" && loc3!="mem"){
							blockcode = blockcode + "mul " + reg1 + ", " + loc2 + ", " + loc3 + "\n";
						}else if(loc2=="mem" && loc3!="mem"){

							reg2=getReg(instr.in1, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in1 + "\n";
							blockcode = blockcode +  "mul " + reg1 + ", " + reg2 + ", " + loc3;
							setregister(reg2, instr.in1);
				        	setlocation(instr.in1, reg2);

						}else if(loc2!="mem" && loc3=="mem"){

							reg2=getReg(instr.in2, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in2 + "\n";
							blockcode = blockcode +  "mul " + reg1 + ", " + loc2 + ", " + reg2 + "\n";
							setregister(reg2, instr.in2);
				        	setlocation(instr.in2, reg2);

						}else if(loc2=="mem" && loc3=="mem"){

							reg2=getReg(instr.in1, instr, symtab);
							reg3=getReg(instr.in2, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in1 + "\n";
							blockcode = blockcode + "lw " + reg3 + ", " + instr.in2 + "\n";
							blockcode = blockcode +  "mul " + reg1 + ", " + reg2 + ", " + reg3 + "\n";
							setregister(reg2, instr.in1);
				        	setlocation(instr.in1, reg2);

				        	setregister(reg3, instr.in2);
				        	setlocation(instr.in2, reg3);
						}
					}

					setregister(reg1, instr.out);
				    setlocation(instr.out, reg1);
				}
			}

			if(instr.op=="/"){

				if(loc1!="mem"){

					if(isInteger(instr.in1) && isInteger(instr.in2)){

						blockcode = blockcode + "div " + loc1 + "," + instr.in1 + "," + instr.in2 + "\n";
					} else if(!isInteger(instr.in1) && isInteger(instr.in2)){
					
						loc2=getlocation(instr.in1);

						if(loc2!="mem"){
							blockcode = blockcode + "div " + loc1 + "," + loc2 + "," + instr.in2 + "\n";
						}else{
							reg2=getReg(instr.in1, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in1 + "\n";
							blockcode = blockcode + "div " + loc1 + ", " + reg2 + ", " + instr.in2 + "\n";
							setregister(reg2, instr.in1);
				        	setlocation(instr.in1, reg2);
						}
					} else if (!isInteger(instr.in1) && !isInteger(instr.in2)){

						loc2=getlocation(instr.in1);
						loc3=getlocation(instr.in2);

						if(loc2!="mem" && loc3!="mem"){
							blockcode = blockcode + "div " + loc1 + ", " + loc2 + ", " + loc3 + "\n";
						}else if(loc2=="mem" && loc3!="mem"){

							reg2=getReg(instr.in1, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in1 + "\n";
							blockcode = blockcode +  "div " + loc1 + ", " + reg2 + ", " + loc3;
							setregister(reg2, instr.in1);
				        	setlocation(instr.in1, reg2);

						}else if(loc2!="mem" && loc3=="mem"){

							reg2=getReg(instr.in2, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in2 + "\n";
							blockcode = blockcode +  "div " + loc1 + ", " + loc2 + ", " + reg2 + "\n";
							setregister(reg2, instr.in2);
				        	setlocation(instr.in2, reg2);

						}else if(loc2=="mem" && loc3=="mem"){

							reg2=getReg(instr.in1, instr, symtab);
							reg3=getReg(instr.in2, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in1 + "\n";
							blockcode = blockcode + "lw " + reg3 + ", " + instr.in2 + "\n";
							blockcode = blockcode +  "div " + loc1 + ", " + reg2 + ", " + reg3 + "\n";
							setregister(reg2, instr.in1);
				        	setlocation(instr.in1, reg2);

				        	setregister(reg3, instr.in2);
				        	setlocation(instr.in2, reg3);
						}
					}
				}else {

					reg1=getReg(instr.out, instr, symtab);

					if(isInteger(instr.in1) && isInteger(instr.in2)){

						blockcode = blockcode + "div " + reg1 + "," + instr.in1 + "," + instr.in2 + "\n";
					} else if(!isInteger(instr.in1) && isInteger(instr.in2)){
					
						loc2=getlocation(instr.in1);

						if(loc2!="mem"){
							blockcode = blockcode + "div " + reg1 + "," + loc2 + "," + instr.in2 + "\n";
						}else{
							reg2=getReg(instr.in1, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in1 + "\n";
							blockcode = blockcode + "div " + reg1 + ", " + reg2 + ", " + instr.in2 + "\n";
							setregister(reg2, instr.in1);
				        	setlocation(instr.in1, reg2);
						}
					} else if (!isInteger(instr.in1) && !isInteger(instr.in2)){

						loc2=getlocation(instr.in1);
						loc3=getlocation(instr.in2);

						if(loc2!="mem" && loc3!="mem"){
							blockcode = blockcode + "div " + reg1 + ", " + loc2 + ", " + loc3 + "\n";
						}else if(loc2=="mem" && loc3!="mem"){

							reg2=getReg(instr.in1, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in1 + "\n";
							blockcode = blockcode +  "div " + reg1 + ", " + reg2 + ", " + loc3;
							setregister(reg2, instr.in1);
				        	setlocation(instr.in1, reg2);

						}else if(loc2!="mem" && loc3=="mem"){

							reg2=getReg(instr.in2, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in2 + "\n";
							blockcode = blockcode +  "div " + reg1 + ", " + loc2 + ", " + reg2 + "\n";
							setregister(reg2, instr.in2);
				        	setlocation(instr.in2, reg2);

						}else if(loc2=="mem" && loc3=="mem"){

							reg2=getReg(instr.in1, instr, symtab);
							reg3=getReg(instr.in2, instr, symtab);
							blockcode = blockcode + "lw " + reg2 + ", " + instr.in1 + "\n";
							blockcode = blockcode + "lw " + reg3 + ", " + instr.in2 + "\n";
							blockcode = blockcode +  "div " + reg1 + ", " + reg2 + ", " + reg3 + "\n";
							setregister(reg2, instr.in1);
				        	setlocation(instr.in1, reg2);

				        	setregister(reg3, instr.in2);
				        	setlocation(instr.in2, reg3);
						}
					}

					setregister(reg1, instr.out);
				    setlocation(instr.out, reg1);
				}
			}
		}

		if(instr.type=="assign1"){

			loc1=getlocation(instr.out);
			if(instr.in1[0]=='*' && instr.out[0]!='*'){

				loc2=getlocation(instr.in1);
				if(loc2!="mem"){
					blockcode = blockcode + "lw " + loc1 + " 0(" + loc2 +")\n";
				}else{
					reg1=getReg(instr.in1, instr, symtab);
					//blockcode = blockcode + "lw " + reg1 + ", " + instr.in1;
					blockcode = blockcode + "lw " + loc1 + " 0(" + reg1 +")\n";
					setregister(reg1, instr.in1);
				    setlocation(instr.in1, reg1);
				}				
			}

			/*if(instr.in1[0]!='*' && instr.out[0]=='*'){

                if(isInteger(instr.in1)){

                	
                }         
            }*/        // cout << "i am pranav" << endl << loc1<< endl;

			//if(instr.in1[0]!='*' && instr.out[0]!='*'){
			if(loc1!="mem"){
				if(isInteger(instr.in1)){
				
				blockcode = blockcode + "li " + loc1 + ", " + instr.in1 + "\n";
				}else {

					loc2=getlocation(instr.in1);
					if(loc2!="mem"){
						blockcode = blockcode + "move " + loc1 + " " + loc2+ "\n";
					}else{
						reg1=getReg(instr.in1, instr, symtab);
						blockcode = blockcode + "lw " + reg1 + ", " + instr.in1+ "\n";
						blockcode = blockcode + "move " + loc1 + ", " + reg1+ "\n";
						setregister(reg1, instr.in1);
				        setlocation(instr.in1, reg1);
					}
					
				}
			}

			if(loc1=="mem"){

				reg1=getReg(instr.out,instr, symtab);
				
				//cout << loc1 << endl << reg1 << endl;
				if(isInteger(instr.in1)){
					
					//cout << isInteger(instr.in1) << endl;
					blockcode = blockcode + "li " + reg1 + ", " + instr.in1 + "\n";
				}else {

					loc2=getlocation(instr.in1);
					if(loc2!="mem"){
						blockcode = blockcode + "move " + reg1 + " " + loc2;
					}else{
						reg2=getReg(instr.in1, instr, symtab);
						blockcode = blockcode + "lw " + reg2 + ", " + instr.in1;
						blockcode = blockcode + "move " + reg1 + ", " + reg2;

						setregister(reg2, instr.in1);
				        	setlocation(instr.in1, reg2);
					}
					
				}
				setregister(reg1, instr.out);
				setlocation(instr.out, reg1);
			}
			
		}

		if(instr.type=="call"){

			blockcode = blockcode + "jal " + instr.in1 + "\n";
			//blockcode = blockcode + "addi\t$sp,$sp,-4\n\t";
			//blockcode = blockcode + "sw\t$t0, 0($sp)\n\t";
		}

		if(instr.type=="goto"){

			blockcode = blockcode + "j " + to_string(instr.target) + "\n";
		}

		if(instr.type=="ifgoto"){

			if(isInteger(instr.in1) && isInteger(instr.in2)){

				if(instr.op=="leq"){
					blockcode = blockcode+ "ble\t" + instr.in1 + "," + instr.in2 + "," + to_string(instr.target) + "\n";			
				}

				if(instr.op=="geq"){
					blockcode = blockcode+ "bge\t" + instr.in1 + "," + instr.in2 + "," + to_string(instr.target)+ "\n";			
				}

				if(instr.op=="le"){
					blockcode = blockcode+ "blt\t" + instr.in1 + "," + instr.in2 + "," + to_string(instr.target) + "\n";			
				}

				if(instr.op=="ge"){
					blockcode = blockcode+ "bgt\t" + instr.in1 + "," + instr.in2 + "," + to_string(instr.target) + "\n";			
				}

				if(instr.op=="eq"){
					blockcode = blockcode+ "beq\t" + instr.in1 + "," + instr.in2 + "," + to_string(instr.target) + "\n";			
				}

				if(instr.op=="neq"){
					blockcode = blockcode+ "bne\t" + instr.in1 + "," + instr.in2 + "," + to_string(instr.target) + "\n";			
				}
			}

			if(!isInteger(instr.in1) && isInteger(instr.in2)){

				if(instr.op=="leq"){

					loc2 = getlocation(instr.in1);

					if(loc2!="mem"){
						blockcode = blockcode+ "ble\t" + loc2 + "," + instr.in2 + "," + to_string(instr.target) + "\n";
					}else{
						reg2=getReg(instr.in1, instr, symtab);
						blockcode = blockcode + "li " + reg2 + ", " + instr.in1 +"\n"; 
						blockcode = blockcode+ "ble\t" + reg2 + "," + instr.in2 + "," + to_string(instr.target) + "\n";
						setregister(reg2, instr.in1);
				        setlocation(instr.in1, reg2);
					}
					
				}

				if(instr.op=="geq"){

					loc2 = getlocation(instr.in1);

					if(loc2!="mem"){
						blockcode = blockcode+ "bge\t" + loc2 + "," + instr.in2 + "," + to_string(instr.target) + "\n";
					}else{
						reg2=getReg(instr.in1, instr, symtab);
						blockcode = blockcode + "li " + reg2 + ", " + instr.in1 +"\n";
						blockcode = blockcode+ "bge\t" + reg2 + "," + instr.in2 + "," + to_string(instr.target) + "\n";
						setregister(reg2, instr.in1);
				        setlocation(instr.in1, reg2);
					}
					
				}

				if(instr.op=="le"){

					loc2 = getlocation(instr.in1);

					if(loc2!="mem"){
						blockcode = blockcode+ "blt\t" + loc2 + "," + instr.in2 + "," + to_string(instr.target)+ "\n";
					}else{
						reg2=getReg(instr.in1, instr, symtab);
						blockcode = blockcode + "li " + reg2 + ", " + instr.in1 +"\n";
						blockcode = blockcode+ "blt\t" + reg2 + "," + instr.in2 + "," + to_string(instr.target)+ "\n";
						setregister(reg2, instr.in1);
				        setlocation(instr.in1, reg2);
					}
				  
				}
				
				if(instr.op=="ge"){

					loc2 = getlocation(instr.in1);

					if(loc2!="mem"){
						blockcode = blockcode+ "bgt\t" + loc2 + "," + instr.in2 + "," + to_string(instr.target)+ "\n";
					}else{
						reg2=getReg(instr.in1, instr, symtab);
						blockcode = blockcode + "li " + reg2 + ", " + instr.in1 +"\n";
						blockcode = blockcode+ "bgt\t" + reg2 + "," + instr.in2 + "," + to_string(instr.target)+ "\n";
						setregister(reg2, instr.in1);
				        setlocation(instr.in1, reg2);
					}
				}
				
				if(instr.op=="eq"){

					loc2 = getlocation(instr.in1);

					if(loc2!="mem"){
						blockcode = blockcode+ "beq\t" + loc2 + "," + instr.in2 + "," + to_string(instr.target)+ "\n";
					}else{
						reg2=getReg(instr.in1, instr, symtab);
						blockcode = blockcode + "li " + reg2 + ", " + instr.in1 +"\n";
						blockcode = blockcode+ "beq\t" + reg2 + "," + instr.in2 + "," + to_string(instr.target)+ "\n";
						setregister(reg2, instr.in1);
				        setlocation(instr.in1, reg2);
					}
				}
				
				if(instr.op=="neq"){

					loc2 = getlocation(instr.in1);

					if(loc2!="mem"){
						blockcode = blockcode+ "bne\t" + loc2 + "," + instr.in2 + "," + to_string(instr.target)+ "\n";
					}else{
						reg2=getReg(instr.in1, instr, symtab);
						blockcode = blockcode + "li " + reg2 + ", " + instr.in1 +"\n";
						blockcode = blockcode+ "bne\t" + reg2 + "," + instr.in2 + "," + to_string(instr.target)+ "\n";
						setregister(reg2, instr.in1);
				        setlocation(instr.in1, reg2);
					}

				}

				
			}

			if(!isInteger(instr.in1) && !isInteger(instr.in2)){

				loc1 = getlocation(instr.in1);
				loc2 = getlocation(instr.in2);

				if(loc1 != "mem" && loc2 != "mem"){

					if (instr.op=="leq"){

						blockcode = blockcode+ "ble\t" + loc1 + "," + loc2 + "," + to_string(instr.target)+ "\n";
					}

					if (instr.op=="geq"){

						blockcode = blockcode+ "bge\t" + loc1 + "," + loc2 + "," + to_string(instr.target)+ "\n";
					}

					if (instr.op=="le"){

						blockcode = blockcode+ "blt\t" + loc1 + "," + loc2 + "," + to_string(instr.target)+ "\n";
					}

					if (instr.op=="ge"){

						blockcode = blockcode+ "bgt\t" + loc1 + "," + loc2 + "," + to_string(instr.target)+ "\n";
					}

					if (instr.op=="eq"){

						blockcode = blockcode+ "beq\t" + loc1 + "," + loc2 + "," + to_string(instr.target)+ "\n";
					}

					if (instr.op=="neq"){

						blockcode = blockcode+ "bne\t" + loc1 + "," + loc2 + "," + to_string(instr.target)+ "\n";
					}
				}

				if(loc1=="mem" && loc2 !="mem"){

 					reg1=getReg(instr.in1,instr, symtab);	

 					if (instr.op=="leq"){
 						blockcode = blockcode + "li " + reg1 + ", " + instr.in1 +"\n";
 						blockcode = blockcode+ "ble\t" + reg1 + "," + loc2 + "," + to_string(instr.target)+ "\n";
 					}

 					if (instr.op=="geq"){
 						blockcode = blockcode + "li " + reg1 + ", " + instr.in1 +"\n";
 						blockcode = blockcode+ "bge\t" + reg1 + "," + loc2 + "," + to_string(instr.target)+ "\n";
 					}

 					if (instr.op=="le"){

 						blockcode = blockcode + "li " + reg1 + ", " + instr.in1 +"\n";
 						blockcode = blockcode+ "blt\t" + reg1 + "," + loc2 + "," + to_string(instr.target)+ "\n";
 					}

 					if (instr.op=="ge"){

 						blockcode = blockcode + "li " + reg1 + ", " + instr.in1 +"\n";
 						blockcode = blockcode+ "bgt\t" + reg1 + "," + loc2 + "," + to_string(instr.target)+ "\n";
 					}

 					if (instr.op=="eq"){

 						blockcode = blockcode + "li " + reg1 + ", " + instr.in1 +"\n";
 						blockcode = blockcode+ "beq\t" + reg1 + "," + loc2 + "," + to_string(instr.target)+ "\n";
 					}

 					if (instr.op=="neq"){

 						blockcode = blockcode + "li " + reg1 + ", " + instr.in1 +"\n";
 						blockcode = blockcode+ "bne\t" + reg1 + "," + loc2 + "," + to_string(instr.target)+ "\n";
 					}
 					
 					setregister(reg1, instr.in1);
				    setlocation(instr.in1, reg1);				
				}

				if(loc1=="mem" && loc2=="mem"){

					reg1=getReg(instr.in1,instr, symtab);
					reg2=getReg(instr.in2,instr, symtab);

					blockcode = blockcode + "li " + reg1 + ", " + instr.in1 +"\n";
					blockcode = blockcode + "li " + reg2 + ", " + instr.in2 +"\n";

					if (instr.op=="leq"){

 						blockcode = blockcode+ "ble\t" + reg1 + "," + reg2 + "," + to_string(instr.target)+ "\n";
 					}

 					if (instr.op=="geq"){

 						blockcode = blockcode+ "bge\t" + reg1 + "," + reg2 + "," + to_string(instr.target)+ "\n";
 					}

 					if (instr.op=="le"){

 						blockcode = blockcode+ "blt\t" + reg1 + "," + reg2 + "," + to_string(instr.target)+ "\n";
 					}

 					if (instr.op=="ge"){

 						blockcode = blockcode+ "bgt\t" + reg1 + "," + reg2 + "," + to_string(instr.target)+ "\n";
 					}

 					if (instr.op=="eq"){

 						blockcode = blockcode+ "beq\t" + reg1 + "," + reg2 + "," + to_string(instr.target)+ "\n";
 					}

 					if (instr.op=="neq"){

 						blockcode = blockcode+ "bne\t" + reg1 + "," + reg2 + "," + to_string(instr.target)+ "\n";
 					}

					setregister(reg1, instr.in1);
				    setlocation(instr.in1, reg1);

				    setregister(reg2, instr.in2);
				    setlocation(instr.in2, reg2);
				}

			}
			
		}

		if(instr.type=="label"){

			label_ret=1;
			blockcode = blockcode + instr.in1 + ":\n\t";
			blockcode = blockcode + "addi\t$sp,$sp,-4\n\t";
			blockcode = blockcode + "sw\t$t0, 0($sp)\n\t";
		}

		if(instr.type=="return1"){

			if(label_ret==0){

				blockcode = blockcode+"li $v0, 10"  + "\n" + "syscall"  + "\n" ;     // \oad 10(exit) for syscall
			}

			if(label_ret==1){

				blockcode = blockcode + "lw $t0, 0($sp)\naddi $sp,$sp,4\njr $ra\n";
				label_ret=0; 
			}
		}

		if(instr.type=="return2"){

			if(isInteger(instr.in1)){
				blockcode = blockcode + "addi $v0, $0, "+ instr.in1 + "\nlw $t0, 0($sp)\naddi $sp,$sp,4\njr $ra\n ";
			}else{

				loc1=getlocation(instr.in1);
				if(loc1!="mem"){

					blockcode = blockcode + "add $v0, $0, " + loc1 + "\nlw $t0, 0($sp)\naddi $sp,$sp,4\njr $ra\n ";
				}else{

					reg1=getReg(instr.in1,instr, symtab);
					blockcode=blockcode+"lw "+reg1+", "+instr.in1 + "\nadd $v0, $0, "+reg1+"\nlw $t0, 0($sp)\naddi $sp,$sp,4\njr $ra\n ";
				}
			}
		}

		if(instr.type=="print"){

			blockcode = blockcode + "li $v0, 4\nla $a0, " + instr.in1 + "\n" + "syscall\n";
		}


			
	//}
		
		
		

	

}
