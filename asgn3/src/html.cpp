#include<bits/stdc++.h>
using namespace std;



void generate_html(){
	//cout << "checkpoint 0" << endl;
	fstream infile;
	fstream outfile;
	fstream out_html;
	string word;

	int yes = 0;
   
   //cout << "checkpoint 1" << endl;
   
   infile.open("temp.txt",ios_base::in);
   outfile.open("ir.txt",ios_base::out);
   out_html.open("prog.html",ios_base::out);
   
   //cout << "checkpoint 2" << endl;
   
   out_html<<"<!DOCTYPE html>\n";
   out_html<<"<html>\n";
   out_html<<"<body>\n";
   out_html<<"<body bgcolor=\"#40403b\">\n";
   out_html<<"<center>\n";
   out_html<<"<h1><font face = \"Palatino\" style=\"color:#fafaf5;\"> RIGHT DERIVATION OF THE PROGRAM</font><h1>\n";

   //cout << "checkpoint 3" << endl;	

   vector<int> colour;

   vector<string> previous_line;
   string pre;
   pre =  "StartFile";
   outfile<<pre<<" $\n";
   previous_line.push_back(pre);
   int n = 1;
   int l = 1;
   int catch_;
   
   //cout << "checkpoint 4" << endl;
   
   while(infile>>word)   
   {
    //cout << "checkpoint 5" << endl;
    for(int i=n-1;i>=0;i--)
    {
    	//cout << "checkpoint 6" << endl;
        if(word == previous_line[i])
        {
           //cout << "checkpoint 7" << endl;	
            catch_ = i;
            colour.push_back(catch_);
            break;
        }
        //cout << "checkpoint 8" << endl;
    }
    l++;

    vector<string> new_line;
    int count_ = 0;
    
    //cout << "checkpoint 9" << endl;
    
    for(int j=0;j<n;j++)
    {
        //cout << "checkpoint 10" << endl;
        if(j!=catch_)
        {

        new_line.push_back(previous_line[j]);
        outfile<<previous_line[j]<<" ";
        count_++;
        }
        else
        {
            while(1)
            {
            infile>>word;
            if(word == "->")
            continue;
            if(word[word.length()-1]=='$')
            {
            new_line.push_back(word.substr(0,word.length()-1));
            outfile<<word.substr(0,word.length()-1)<<" ";
            count_++;
            break;
            }
            else
            {
            new_line.push_back(word);
            outfile<<word<<" ";
            count_++;
            }
            }
        }

    }
    n = count_;
    outfile<<"$\n";
    previous_line = new_line;
   }
   //cout << "checkpoint 11" << endl;
   infile.close();
   outfile.close();
   //cout << "checkpoint 12" << endl;
   infile.open("ir.txt",ios_base::in);
   //cout << "checkpoint 13" << endl;
   int i = 0;
   while(infile>>word)
   {
       //cout << "checkpoint 14" << endl;	
       if(colour[i] == 0)
       {
	   //cout << "checkpoint 15 --- 0" << endl;	
           out_html<<"<font size = \"2\" face = \"Times\"";
           out_html<<"style=\"color:#ec0808;\">";
           out_html<<word<<"&nbsp";
           out_html<<"</font>";

           while(1)
           {

               infile>>word;
               if(word == "$")
               {
                out_html<<"<br>\n";
                break;
               }
               else
               {
               out_html<<"<font size = \"2\" face = \"Times\"";
               out_html<<"style=\"color:#33FF55;\">";
               out_html<<word<<"&nbsp";
               out_html<<"</font>";
               }

           }
           i++;
           //cout << "checkpoint 15 --- 1" << endl;
           continue;

       }
       else
       {
           int toggle = 0;
             while(1)
           {
               if(toggle != colour[i])
               {
               if(word=="$")
                {
                out_html<<"<br>\n";
                break;
                }
               else
               {
               out_html<<"<font size = \"2\" face = \"Times\"";
               out_html<<"style=\"color:#33FF55;\">";
               out_html<<word<<"&nbsp";
               out_html<<"</font>";
               }
               toggle++;
               infile>>word;
               continue;
               }
               else
               {
                if(word=="$")
                {
                    out_html<<"<br>\n";
                    break;
                }
               else
               {
               out_html<<"<font size = \"2\" face = \"Times\"";
               out_html<<"style=\"color:#ec0808;\">";
               out_html<<word<<"&nbsp";
               out_html<<"</font>";
               }
               toggle++;
               infile>>word;
               }


           }
           i++;
           //cout << "checkpoint 15 --- 2" << endl;
       }


   }
   //cout << "To Infinty & Beyond!" << endl;
   if(yes == 1)
   {
       fstream file;
       file.open("errors.txt",ios_base::in);
       string wor;
       string final_ ="";
       out_html<<"<font size = \"4\" face = \"Times\"";
       out_html<<"style=\"color:red;\">";
       while(file>>wor)
       {
           out_html<<wor<<"&nbsp";
       }
       out_html<<"</font>\n";
   }
   out_html<<"</center>\n";
   out_html<<"</body>";
   infile.close();
   out_html.close();
   cout<<"HTML file created.\n";
   //return 0;
}


