#include "stdafx.h"
#include<conio.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//string input[1000];
int lookUp(string temp),k;
string temp="";
int index=0;
int lin=0;
int sf=0;
int lexIndex=0;
int errorIndex=0; 
int newindex=0;
int pt=0;
size_t found=0;size_t r1;
string * input=new string[1000];
string * newstr=new string[1000];
int syni=0;
int e=0;
//int sf=0;

struct error
{
string err;
string msg;
int linenumber;
int errnum;
};
error * e1=new error[1000];


struct lex
{
	string token;
	string lexeme;
	string type;
	string size;
	int level;
	int ref;
};
lex * l1=new lex[1000];
//lex l1[1000];

void inserterror(string e,string m,size_t l)
{
e1[errorIndex].err=e;
e1[errorIndex].msg=m;
e1[errorIndex].linenumber=int(l);
errorIndex++;
}

void Displayerr()
{
if(errorIndex==0)
{
cout<<"\n 0 ERRORS\n";
}
cout<<endl<<"ERROR#        message\n";
	for(int i=0;i<errorIndex;i++)
	{
	cout<<e1[i].err<<"          "<<e1[i].msg<<"              "<<endl<<endl;
	
	}
}

int findlinenum(string s)
{
	
int length=0;
int i=0;//char str1[10];
//string::size_type a=s.length();
while(i<newindex)
{
	string::size_type position=newstr[i].find(s);
	if(	position!=string::npos)
	{

	  break;
	}
		
	else
	{
		i++;
}
}

	return i;
}

void insert(string t, string l, int lev,string tp,string s,int r)
{
l1[lexIndex].token=t;
l1[lexIndex].lexeme=l;
l1[lexIndex].level=lev;
l1[lexIndex].type=tp;
l1[lexIndex].size=s;
l1[lexIndex].ref=r;
lexIndex++;
	
}

int lookUp(string temp)
{
	int i=0 , flag=0;
	while(i<lexIndex)
	{
		if(l1[i].lexeme==temp)
		{
	        flag=1;
			break;
		}
		else
		{
		i++;
		}
	}
	if(flag==1)
		return i;
	else
	return flag;
}




void Display()
{
	cout<<endl<<"LEXEME     TOKEN     LEVEL     TYPE     SIZE"<<endl<<endl;
	for(int i=0;i<lexIndex;i++)
	{
cout<<l1[i].lexeme<<l1[i].ref<<"     "<<l1[i].token<<"     "<<l1[i].level<<l1[i].type<<"     "<<l1[i].size<<endl<<endl;

	}
}


/////////////////////DECLARATION SYNTAX///////////////////////
void DECLARATION()
{

 sf=0;
 //////////////////////////////CHARACTER DECLARATION
	if(l1[syni].type=="Cchar" && l1[syni].token=="Identifier" && l1[syni].size=="" && l1[syni].ref==0)
	{
		
		syni++;
		
	    //////////////////////////////////////////
		if(l1[syni].lexeme==":") 
			{
				syni++;
	//			return sf;
			}
		
		    else if(l1[syni].lexeme=="==")
			{
				syni++;
				if(l1[syni].token=="Character Constant")
				{
						syni++;
						if(l1[syni].lexeme==":") 
						{
							syni++;
						}
						else
						{
							cout<<"\nERROR#1 Missing : after "<<l1[syni-1].token<<" "<< l1[syni-1].lexeme;
					cout<<"Not found";		}
				}
				else
				{
						cout<<"\nERROR#2 invalid declaration after"<<l1[syni-1].token<<" "<< l1[syni-1].lexeme;
				cout<<"Not found";	}
			}
			else
				{
					cout<<"\nERROR#1 Missing : after"<<l1[syni-1].token<<" "<< l1[syni-1].lexeme;
				cout<<"Not found";}
			
		}
	

	
	///////////INTEGER DECLARATION///////////////////			
else	if(l1[syni].type=="Cint" && l1[syni].token=="Identifier" && l1[syni].size=="" && l1[syni].ref==0 )
	{
		
		syni++;
		
	    //////////////////////////////////////////
		if(l1[syni].lexeme==":") 
			{
			
				syni++;
			//	return sf;
			}
		
		    else if(l1[syni].lexeme=="==")
			{
				syni++;
				if(l1[syni].token=="Integer Constant")
				{
						syni++;
						if(l1[syni].lexeme==":") 
						{
							syni++;
						}
						else
						{
								
							cout<<"\nERROR#1 Missing : after "<<l1[syni-1].token<<" "<< l1[syni-1].lexeme;
						cout<<"Not found";	}
				}
				else
				{
				
						cout<<"\nERROR#2 invalid declaration after "<<l1[syni-1].token<<" "<< l1[syni-1].lexeme;
					cout<<"Not found";}
			}
			else
				{
					
					cout<<"\nERROR#1 Missing : after "<<l1[syni-1].token<<" "<< l1[syni-1].lexeme;
				cout<<"Not found";	}
			
		}
	/////////////////////ARRAY DECLARATION/////////
			
else	if(l1[syni].type=="Cchar" && l1[syni].token=="Identifier" && l1[syni].size=="integer Constant" && l1[syni].ref==0 )
	{
		
		syni++;
		
	    //////////////////////////////////////////
		if(l1[syni].lexeme==":") 
			{
			
				syni++;
			
			//	return sf;
			}
		
		    else if(l1[syni].lexeme=="==")
			{
				syni++;
				   
			
				
				   if(l1[syni].token=="Character Constant")
				{
						syni++;
			
					while(l1[syni].token=="Character Constant")
						{
							syni++;
						}
						if(l1[syni].lexeme==":") 
						{
							syni++;
						
						}
				   
						else
						{
								
							cout<<"\nERROR#1 Missing : after "<<l1[syni-1].token<<" "<< l1[syni-1].lexeme;
					cout<<"Not found";	}
				}
				
				else
				{
				
						cout<<"\nERROR#2 invalid declaration after "<<l1[syni-1].token<<" "<< l1[syni-1].lexeme;
			cout<<"Not found";	}
				
			}
			else 
				{
					
					cout<<"\nERROR#1 Missing : after "<<l1[syni-1].token<<" "<< l1[syni-1].lexeme;
				cout<<"Not found";	}
			
			
		}
	////////////////bool declaration///////
	else	if(l1[syni].type=="Cbool" && l1[syni].token=="Identifier" && l1[syni].size=="" && l1[syni].ref==0)
	{
		
		syni++;
		
	    //////////////////////////////////////////
		if(l1[syni].lexeme==":") 
			{
			
				syni++;
			//	return sf;
			}
		
		    else if(l1[syni].lexeme=="==")
			{
				syni++;
				if(l1[syni].lexeme=="TT" || l1[syni].lexeme=="FF")
				{
						syni++;
						if(l1[syni].lexeme==":") 
						{
							syni++;
						}
						else
						{
								
							cout<<"\nERROR#1 Missing : after "<<l1[syni-1].token<<" "<< l1[syni-1].lexeme;
					cout<<"Not found";	}
				}
				else
				{
				
						cout<<"\nERROR#2 invalid declaration after "<<l1[syni-1].token<<" "<< l1[syni-1].lexeme;
				cout<<"Not found";}
			}
			else
				{
					
					cout<<"\nERROR#1 Missing : after "<<l1[syni-1].token<<" "<< l1[syni-1].lexeme;
				cout<<"Not found";	}
			
		}

	
}
void AArray()
{
	if(l1[syni].token=="Identifier"&& l1[syni].type=="Cchar" && l1[syni].size=="integer Constant" && l1[syni].ref==1)
	{
		syni++;
		if(l1[syni].token=="Identifier"&& l1[syni].size=="")
		{
			if(l1[syni].type=="Cint")
			{
			syni++;
			if(l1[syni].lexeme=="==")
			{
			syni++;
			if(l1[syni].token=="Character Constant")
			{
			syni++;
			if(l1[syni].lexeme==":")
			{
			syni++;
			}
			else
			{
			cout<<"\n ERROR IN ARRAY INITILIZATION missing : after "<<l1[syni-1].lexeme;
			cout<<"Not found";
			}
			}
			else
			{
			cout<<"\n ERROR IN ARRAY INITILIZATION after "<<l1[syni-1].lexeme;
			cout<<"Not found";
			}
			}
			else
			{
			cout<<"\n ERROR IN ARRAY INITILIZATION missing == AFTER "<<l1[syni-1].lexeme;
			cout<<"Not found";
			}
			}
			else
			{
			cout<<"\n TYPE ERROR IN ARRAY INITILIZATION AFTER "<<l1[syni-1].lexeme;
			cout<<"Not found";
			}
		}
	else if(l1[syni].token=="Integer Constant")
	{
		syni++;
			if(l1[syni].lexeme=="==")
			{
			syni++;
			if(l1[syni].token=="Character Constant")
			{
			syni++;
			if(l1[syni].lexeme==":")
			{
			syni++;
			}
			else
			{
			cout<<"\n ERROR IN ARRAY INITILIZATION missing : after "<<l1[syni-1].lexeme;
			cout<<"Not found";
			}
			}
			else
			{
			cout<<"\n ERROR IN ARRAY INITILIZATION after "<<l1[syni-1].lexeme;
			cout<<"Not found";
			}
			}
			else
			{
			cout<<"\n ERROR IN ARRAY INITILIZATION missing == AFTER "<<l1[syni-1].lexeme;
			cout<<"Not found";
			}
		}
	else
	{
	cout<<"\n INVALID ARRAY INITALITION AFTER ";
	cout<<"Not found";
	}
	}
	else
	{
	cout<<"\n INVALID ARRAY INITALITION AFTER ";
	cout<<"Not found";
	}
}

////////////////////EXPRESSION syntax////////////////////
void expression()
{
if(l1[syni].token=="Identifier" && l1[syni].type=="Cint" ||l1[syni].token=="Integer Constant")
	 {
	 syni++;
	   if(l1[syni].lexeme=="++" || l1[syni].lexeme=="--" || l1[syni].lexeme=="%%"|| l1[syni].lexeme=="//"|| l1[syni].lexeme=="**")
	   {
	 syni++;
	 

        if(l1[syni].token=="Identifier" && l1[syni].type=="Cint" ||l1[syni].token=="Integer Constant")
		{
	      syni++;
 
         if(l1[syni].lexeme=="==")
		 {
	       syni++;
	 
          if(l1[syni].token=="Identifier")
		  {
			  if(l1[syni].type=="Cint")
			  {
	         syni++;
	// cout<<syni;

                if(l1[syni].lexeme==":")
				{
	        	syni++;
				}
               else	
			   {
		cout<<"\nERROE#1 error in expression missing : after "<<l1[syni-1].lexeme;
		cout<<"Not found";
			   }
			  }
			  else
			  {
			  cout<<"\n TYPE ERROR IN EXPRESSION after "<<l1[syni].lexeme;
			  cout<<"Not found";
			  }
		  }
		  else
	{
		cout<<"\nERROR#3 INVALID EXPRESSION after "<<l1[syni-1].lexeme;
		cout<<"Not found";
	}
		 }
		 else
	{
		cout<<"\nERROR#3 INVALID EXPRESSION after "<<l1[syni-1].lexeme;
		cout<<"Not found";
	}
		}
		else
	{
		cout<<"\nERROR#3 INVALID EXPRESSION after "<<l1[syni-1].lexeme;
		cout<<"Not found";
	}
	   }
	   else
	{
		cout<<"\nERROR#3 INVALID EXPRESSION after "<<l1[syni-1].lexeme;
		cout<<"Not found";
	}
  }
	else
	{
		cout<<"\nERROR#3 INVALID EXPRESSION after "<<l1[syni-1].lexeme;
		cout<<"Not found";
	}
}

//////////////////////////////////////////////////////////
void condition()
{

if(l1[syni].token=="Identifier" && l1[syni].type=="Cint" || l1[syni].token=="Integer Constant")
	 {
	 syni++;
	
      if(l1[syni].lexeme==">>" || l1[syni].lexeme=="<<" || l1[syni].lexeme=="=")
	  {
   	        syni++;
	  
 
           if(l1[syni].token=="Identifier"&& l1[syni].type=="Cint" || l1[syni].token=="Integer Constant")
		   {
             syni++;
		   }
		   else 
		   {
             	cout<<"\nERROR5!Illegal condition after "<<l1[syni-1].lexeme;
				cout<<"Not found";
		   }
	  }
	  else 
	  {
   	        cout<<"\nERROR5!Illegal condition after "<<l1[syni-1].lexeme;
			cout<<"Not found";
	  }
  }
//////////////////////////////////////////////// 
else if(l1[syni].token=="Identifier" && l1[syni].type=="Cchar" && l1[syni].size=="" && l1[syni].ref==1)
{
syni++;
if(l1[syni].lexeme=="=")
{
syni++;
if(l1[syni].token=="Character Constant")
{
syni++;
}
else
{
cout<<"\n ERROR ILLEGAL CONDITION missing char constant";
}
}

else
{
cout<<"\n ERROR ILLEGAL CONDITION missing =";
}
}
////////////////////////////////////////
else if(l1[syni].token=="Identifier" && l1[syni].type=="Cchar" && l1[syni].size=="integer Constant" && l1[syni].ref==1)
{
syni++;
if(l1[syni].token=="Identifier" && l1[syni].size=="")
{
	if(l1[syni].type=="Cint")
	{
	syni++;
	if(l1[syni].lexeme=="=")
	{
	syni++;
	if(l1[syni].token=="Character Constant")
	{
	syni++;
	}
	else
	{
	cout<<"\n MISSING CHARACTER CONSTANT IN CONDITION after "<<l1[syni-1].token;
	}
	}
	else
	{
	cout<<"\n MISSING = in condition after "<<l1[syni-1].token;
	}
	}
	else
	{
	cout<<"\nType error in condition after "<<l1[syni-1].token;
	}
}
else if(l1[syni].token=="Integer Constant")
{
syni++;
if(l1[syni].lexeme=="=")
	{
	syni++;
	if(l1[syni].token=="Character Constant")
	{
	syni++;
	}
	else
	{
	cout<<"\n MISSING CHARACTER CONSTANT IN CONDITION after "<<l1[syni-1].token;
	}
	}
	else
	{
	cout<<"\n MISSING = in condition after "<<l1[syni-1].token;
	}
	}
	else
	{
	cout<<"\nType error in condition after "<<l1[syni-1].token;
	}
}



/////////////////////////////////////////////
  else if(l1[syni].token=="Identifier" && l1[syni].type=="Cbool")
  {
 syni++;
 if(l1[syni].lexeme=="=")
 {
 syni++;
 
 if(l1[syni].lexeme=="TT" || l1[syni].lexeme=="FF")
 {
 syni++;
 
 }
 else
 {
 cout<<"TYPE ERROR!INVALID CONDITIONAL STAEMENT after "<<l1[syni-1].lexeme;
 	cout<<"Not found";
 }
 }
 else
 {
 cout<<"MISSING = in conditional statement after "<<l1[syni-1].lexeme;
 	cout<<"Not found";
 }
  }
  else
  {
	  cout<<"ILLEGAL CONDITION AFTER "<<l1[syni].lexeme;
	 	cout<<"Not found";
  }

}
//////////////////////Loop if Else///////////////
void statements()
	 {
	 if(l1[syni].token=="Keyword")
	 {
	 syni++;
	
	  if(l1[syni].lexeme=="!")
	  {
    	 syni++;
	  condition();
			
	    if(l1[syni].lexeme=="!!")
		{
		  syni++;
	
	       if(l1[syni].lexeme=="[")
		   {
		     syni++;
		   
	          while(l1[syni].token=="Identifier" && l1[syni].type=="Cint" && l1[syni].size==""|| l1[syni].token=="Integer Constant")
			  {
    
	           expression();
			  }
	while(l1[syni].token=="Identifier" && l1[syni].type=="Cchar" && l1[syni].ref==1 && l1[syni].size=="integer Constant")
	{
	AArray();
	}

	           if(l1[syni].lexeme=="]")
			   {
		          syni++;
			   }
			    else
				{
                cout<<"\nERROR#4 illegal conditional statement after "<<l1[syni-1].token<<" "<< l1[syni-1].lexeme;
				cout<<"Not found";
				}
		   }
		    else
			{
         cout<<"\nERROR#4 illegal conditional statement after "<<l1[syni-1].token<<" "<< l1[syni-1].lexeme;
			
				cout<<"Not found";}
		}
		 else
		 {
        cout<<"\nERROR#4 illegal conditional statement after "<<l1[syni-1].token<<" "<< l1[syni-1].lexeme;
			cout<<"Not found";}
	  }
	   else
	   {
       cout<<"\nERROR#4 illegal conditional statement after "<<l1[syni-1].token<<" "<< l1[syni-1].lexeme;
	  	cout<<"Not found"; }
	 }
	 else
	 {
       cout<<"\nERROR#4 illegal conditional statement after "<<l1[syni-1].token<<" "<< l1[syni-1].lexeme;
	cout<<"Not found"; }
	
}
///////////////////SYNTAX ANALAZYER///////////////////////////////////////
void syntax_analyzer()
{

	if(syni<lexIndex)
	{
		
if(l1[syni].lexeme=="{")
{
	syni++;
	
	while(l1[syni].token=="Identifier" && l1[syni].ref==0&&(l1[syni].type=="Cint" || l1[syni].type=="Cchar" ||l1[syni].type=="Cbool" ))	
	{
	
		DECLARATION();

	}
	
	
	while(l1[syni].token=="Identifier" && l1[syni].type=="Cchar" && l1[syni].ref==1 && l1[syni].size=="integer Constant")
	{
	AArray();
	}


	while(l1[syni].token=="Integer Constant" || (l1[syni].token=="Identifier"  && l1[syni].ref==1))
	{
		expression();

	}
	while(l1[syni].token=="Keyword")
	  {
		 
	     statements();
	  }
}
else
{
	cout<<"\nError PROGRAM START SYMBOL not found";
		cout<<"Not found";
}
if(l1[syni].lexeme=="}")
{
syni++;

}

if(l1[syni-1].lexeme=="}")
{
	
	cout<<"\nPROGRAM COMPILED";
//	cout<<"\n 0 ERRORS";
}
else
{
	if(l1[syni].lexeme=="++" ||l1[syni].lexeme=="=" ||l1[syni].lexeme=="==" ||l1[syni].lexeme=="!!" ||l1[syni].token=="Character Constant" ||l1[syni].lexeme=="%%" ||l1[syni].lexeme=="//" ||l1[syni].lexeme=="**" ||l1[syni].lexeme=="--" || l1[syni].token=="Character Constant")
	{
	cout<<"\nCOMPILATION STOPS";
	cout<<"\nILLEGAL USE OF OPERATORS/SYMBOLS/CONSTANTS";

	}
	if(l1[lexIndex-1].lexeme!="}")
	{
		cout<<"\nPROGRAM END SYMBOL NOT FOUND";
			
	}
	if(l1[syni].token=="Identifier" && l1[syni].type=="Cbool")
	{
	cout<<"\nERROR Cbool can only be used in declarations and conditions";
	}


}
	}
}
	
void main()
{
	string STRING;
	string space="";
	for(int o=0;o<1000;o++)
	{
		input[o]="";

	}
	temp="";int linenum=0; int level=1; int bracket_count=0;
//////////////FILING////////////////////////////////
ifstream infile;
infile.open("Myfil.txt");
if(!infile.good())
{
cout<<"ERROR READING FILE";
cout<<"Not found";
}
while(!infile.eof())
{
infile>>temp;
input[index]=temp;
index++;
infile.ignore();
}
infile.close();

//prints the number of lines in a file
ifstream infile1;
infile1.open("Myfil.txt");
if(!infile1.good())
{
cout<<"ERROR READING FILE";
cout<<"Not found";
}
while(!infile1.eof())
{
//infile1>>temp;


while(getline(infile1,newstr[newindex],'\n'))
{	
	++linenum;
	++newindex;
}

//cout << "The number of lines in the file is " <<
//linenum << endl;
//cout<<"number of words in source code are"<<index<<endl;

infile1.ignore();
}
infile.close();

int a=0;


///////////////////////checks/////////////////////////
for(int i=0;i<index;i++)
{

int o=0;
	int rslt=0;
	char strng[20]="";
     int f=0 , m=0, f1=0, m1=0, f2=0, m2=0 ;
	int len=input[i].length();
	for(int k=0;k<len;k++)
	{
		strng[k]=input[i].at(k);
	}
	k=0;
//////////////////KeyWords///////////////////////////////
////////////////////iff
	if(strng[0]=='i' && strng[1]=='f' && strng[2]=='f')
	{ int m=3;
	while(m<len){
		if((static_cast<int> (strng[m]))!='\0'){
			m=0;
				break;
		}
		else m++;
	}
	if(m==0)
	{
		 r1=findlinenum(input[i]);
		inserterror("ILLEGAL KEYWORD",input[i],r1);
	}
	else{
	insert("Keyword",input[i],level,"void","",0);
	}
	}
	/////////////////////////////////els
	if(strng[0]=='e' && strng[1]=='l' && strng[2]=='s')
	{ int m=3;
	while(m<len){
		if((static_cast<int> (strng[m]))!='\0'){
			m=0;
				break;
		}
		else m++;
	}
	if(m==0)
	{
		 r1=findlinenum(input[i]);
		inserterror("ILLEGAL KEYWORD",input[i],r1);
	}
	else
	{
	insert("Keyword",input[i],level,"void","",0);
	o=1;
	}}
	///////////////////////////////till
	if(strng[0]=='t' && strng[1]=='i' && strng[2]=='l' && strng[3]=='l')
	{ int m=4;
	while(m<len){
		if((static_cast<int> (strng[m]))!='\0'){
			m=0;
				break;
		}
		else m++;
	}
	if(m==0)
	{
		 r1=findlinenum(input[i]);
		inserterror("ILLEGAL KEYWORD",input[i],r1);
	}
	else{
	insert("Keyword",input[i],level,"void","",0);
	o=2;
	}}
	//////////////////////////////// untill
	if(strng[0]=='u' && strng[1]=='n' && strng[2]=='t' && strng[3]=='i' && strng[4]=='l' && strng[5]=='l')
	{ int m=6;
	while(m<len){
		if((static_cast<int> (strng[m]))!='\0'){
			m=0;
				break;
		}
		else m++;
	}
	if(m==0)
	{
		 r1=findlinenum(input[i]);
		inserterror("ILLEGAL KEYWORD",input[i],r1);
	}
	else{
	insert("Keyword",input[i],level,"void","",0);
	o=3;
	}
	}
	/////////////////////////////// :
	else if(input[i]=="=")
	{
	insert("comparision operator",input[i],level,"void","",0);
	}
	else if(input[i]==":")
	{
	insert("Ending Symbol",input[i],level,"void","",0);
	}
	else if(input[i]=="[")
	{
	insert("Opening Square Bracket",input[i], level,"void","",0);
	 level=level+1;
	}
	else if(input[i]=="]")
	{
		level=level-1;
	
	insert("Closing Square Bracket",input[i], level,"void","",0);
	
	}
	else if(input[i]=="!")
	{
		
	insert("Condition starting Symbol",input[i],level,"void","",0);
	level=level+1;
	}
		else if(input[i]=="!!")
	{
			level=level-1;
	
	insert("Condition ending Symbol",input[i],level,"void","",0);
	}
		else if(input[i]=="{")
	{
	insert("Program Start Symbol",input[i],level,"void","",0);
	}
	else if(input[i]=="}")
	{
	insert("Program Ending Symbol",input[i],level,"void","",0);
	}
	else if(input[i] =="show")
					{
					insert("Keyword",input[i],level,"void","",0);
	}
		////////////////////////Cint
	else if(input[i]=="Cint")
	{
		i++;
	len=input[i].length();
	for(int k=0;k<len;k++)
	{
		strng[k]=input[i].at(k);
	}
	k=0;
		if(strng[0]=='$')
		{

					insert("Identifier",input[i],level,"Cint","",0);
		}
		else	if(strng[0]!='$')
		{
                         r1=findlinenum(input[i]);
						inserterror("ILLEGAL USE OF Cint",input[i],r1);
		}
	}
////////////////////////Ccha////////////////////	
	else if(input[i]=="Cchar")
	{
	i++;
	len=input[i].length();
	for(int k=0;k<len;k++)
	{
		strng[k]=input[i].at(k);
	}
	k=0;
		if(strng[0]=='$')
		{
			i++;
     len=input[i].length();
	for(int k=0;k<len;k++)
	{
		strng[k]=input[i].at(k);
	}
	k=0;
 if((static_cast<int> (strng[0])>=48) && (static_cast<int> (strng[0])<=57))
		{
			while(m<len)
			{
				if((static_cast<int> (strng[m])>=48) && (static_cast<int> (strng[m])<=57))
				{
					f1++;m++;
				}

			}
	
			if(f1==len)
			{
			insert("Identifier",input[i-1],level,"Cchar","integer Constant",0);
			}
			else
			{
				r1=findlinenum(input[i]);
		    inserterror("ILLEGAL INPUT SYMBOL",input[i],r1);

			}
		}
 else
 {
                     i--;
					insert("Identifier",input[i],level,"Cchar","",0);
 }
		}
		else if(strng[0]!='$')
		{
                         r1=findlinenum(input[i]);
						inserterror("ILLEGAL USE OF Cchar",input[i],r1);
		}
	}
	
	///////////////////CBool/////////////////
	else if(input[i]=="Cbool")
	{
	i++;
	len=input[i].length();
	for(int k=0;k<len;k++)
	{
		strng[k]=input[i].at(k);
	}
	k=0;
		if(strng[0]=='$')
		{
		
	insert("Identifier",input[i],level,"Cbool","",0);
		}
		else if(strng[0]!='$')
		{
                         r1=findlinenum(input[i]);
						inserterror("ILLEGAL USE OF Cbool",input[i],r1);
		}
	}
/////////////////////////////////////////////////////////////	
	
	/////////////////illegal operators////////////////////////
					else	if(strng[k]=='+' && strng[k+1]!='+')
						{
						r1=findlinenum(input[i]);
						inserterror("ILLEGAL OPERATOR",input[i],r1);
						}
					else	if(strng[k]=='*' && strng[k+1]!='*')
						{
						r1=findlinenum(input[i]);
						inserterror("ILLEGAL OPERATOR",input[i],r1);
						}
					else	if(strng[k]=='/' && strng[k+1]!='/')
						{
						r1=findlinenum(input[i]);
						inserterror("ILLEGAL OPERATOR",input[i],r1);
						}
					else	if(strng[k]=='%' && strng[k+1]!='%')
						{
						r1=findlinenum(input[i]);
						inserterror("ILLEGAL OPERATOR",input[i],r1);
						}
					else	if(strng[k]=='-' && strng[k+1]!='-')
						{
						r1=findlinenum(input[i]);
						inserterror("ILLEGAL OPERATOR",input[i],r1);
						}
				
					else	if(strng[k]=='=' && strng[k+1]!='=')
						{
						r1=findlinenum(input[i]);
						inserterror("ILLEGAL OPERATOR",input[i],r1);
						}
					else	if(strng[k]=='<' && strng[k+1]!='<')
						{
						r1=findlinenum(input[i]);
						inserterror("ILLEGAL OPERATOR",input[i],r1);
						}
					else	if(strng[k]=='>' && strng[k+1]!='>')
						{
						r1=findlinenum(input[i]);
						inserterror("ILLEGAL OPERATOR",input[i],r1);
						}

	
	//////////////// Operators//////////
	else if(input[i]=="++")
	{
	insert("Addition Operator",input[i],level,"void","",0);
	}
	else if(input[i]=="--")
	{
		//rslt=lookUp(input[i]);
	//if(rslt==0){
	insert("Subtraction Operator",input[i],level,"void","",0);
	//}
	}
	else if(input[i]=="**")
	{
		//rslt=lookUp(input[i]);
	//if(rslt==0){
	insert("Multiplication Operator",input[i],level,"void","",0);
	//}
	}
		else if(input[i]=="//")
	{
			//rslt=lookUp(input[i]);
	//if(rslt==0){
	insert("Division Operator",input[i],level,"void","",0);
		//}
	}
			else if(input[i]=="%%")
	{
				//rslt=lookUp(input[i]);
	//if(rslt==0){
	insert("Modulus Operator",input[i],level,"void","",0);
			//}
	}
				else if(input[i]=="==")
	{
					//rslt=lookUp(input[i]);
	//if(rslt==0)
	//{
	insert("Assingment Operator",input[i],level,"void","",0);
				//}
	}
				else if(input[i]=="=")
	{
					//rslt=lookUp(input[i]);
	//if(rslt==0){
	insert("Comparison Operator",input[i],level,"void","",0);
				//}
	}
					else if(input[i]==">>")
	{
						//rslt=lookUp(input[i]);
	//if(rslt==0){
	insert("Logical Operator",input[i],level,"void","",0);
					//}
	}
						else if(input[i]=="<<")
	{
							//rslt=lookUp(input[i]);
	//if(rslt==0)
	//{
	insert("Logical Operator",input[i],level,"void","",0);
						//}
	}
				///////////illegal comments/////////////////
							else if(strng[0]=='*' && strng[1]!='@')
	{
							r1=findlinenum(input[i]);
	
	inserterror("ILLEGAL Comment Symbol",input[i],r1);
						}
								else if(strng[0]!='*' && strng[1]=='@')
	{
							r1=findlinenum(input[i]);
	
	inserterror("ILLEGAL Comment Symbol",input[i],r1);
						}
						////////////////Comments/////////////
						else if(input[i]=="*@")
	{
							//rslt=lookUp(input[i]);
	//if(rslt==0)
	//{
	insert("Comment Symbol",input[i],level,"void","",0);
					//	}
	}
	
				
						

	else if(input[i]=="")
	{
		space="Space";
	
	}

	/////////////////////////////////NUMERIC CONSTANTS/////////////////////////////////////
else if((static_cast<int> (strng[0])>=48) && (static_cast<int> (strng[0])<=57))
		{
			while(m<len)
			{
				if((static_cast<int> (strng[m])>=48) && (static_cast<int> (strng[m])<=57))
				{
					f1++;m++;
				}

			}
	
			if(f1==len)
			{
			insert("Integer Constant",input[i],level,"void","",0);
			}
			else
			{
				r1=findlinenum(input[i]);
		    inserterror("ILLEGAL INPUT SYMBOL",input[i],r1);

			}
		}
	
		
   //////////////////////////////////////////////CHARACTER CONSTANTS//////////////////////////
	else if(((static_cast<int> (strng[0])>=65) && (static_cast<int> (strng[0])<=90)) || ((static_cast<int> (strng[0])>=97) && (static_cast<int> (strng[0])<=122)) )
	{
	while(m2<len)
	{
	if(((static_cast<int> (strng[m2])>=65) && (static_cast<int> (strng[m2])<=90)) || ((static_cast<int> (strng[m2])>=97) && (static_cast<int> (strng[m2])<=122)))	
		{
		f2++;m2++;
		}
	}
    if(f2==len)
	{
	//	if(input[i]!="till" || input[i]!="untill" || input[i]!="els" ||input[i]!="iff"){
		if(o==0)
		{
			insert("Character Constant",input[i],level,"void","",0);//}
		}
	}
	else
	{
		r1=findlinenum(input[i]);
	 inserterror("ILLEGAL INPUT SYMBOL",input[i],r1);

	}
	}
						////////////////////////ILLEGAL IDENTIFIER/////////////////////
	
//////////////////Identifiers//////////////////
					
else if(strng[0]=='$')
	{
		rslt=lookUp(input[i]);
		if(rslt==0)
		{
	r1=findlinenum(input[i]);
	inserterror("Undeclared Identifier",input[i],r1);
		}
		else
		{
		insert("Identifier",input[i],level,l1[rslt].type,l1[rslt].size,1);
		}
	}
	////////////////////////ILLEGAL INPUT SYMBOL Errors////////////////////
	
	else 
	{
		r1=findlinenum(input[i]);
		inserterror("ILLEGAL INPUT SYMBOL",input[i],r1);
	}
	
}
//cout<<endl<<"\n\t\t***************LEXEME AND TOKEN PAIR*****************"<<endl;
        Display();
cout<<endl<<"\n\t\t************ERRORS***********\n"<<endl;



	cout<<"\n\n\n****************SYNTAX ANALYZER C--*************************\n\n\n";
	cout<<"ERROR DESCRIPTION";
	cout<<"\nERROE#1 STATEMENT TERMINATING SYMBOL(:) NOT FOUND";
	cout<<"\nERROR#2 INVALID DECLARATION";
	cout<<"\nERROR#3 INVALID EXPRESSION";
	cout<<"\nERROR#4 INVALID STATEMENTS(conditional,loop)";
	cout<<"\nERROR#5 INVALID CONDITION";
	cout<<"\nERROR#6 PROGRAM START SYMBOL ERROR";
	cout<<"\nERROR#7 PROGRAM END SYMBOL ERROR";
cout<<"\n\n\n**************ERRORS FOUND*******************************\n\n\n";
if(errorIndex==0)
{
syntax_analyzer();
}
else
{	
Displayerr();
}
 delete[] input;
 delete[] newstr;
 delete[] l1;
 delete[] e1;
// getch();
 int azz;
 cin>>azz;
}
