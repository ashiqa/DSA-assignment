#include<iostream>;
#include<fstream>;
using namespace std ;

int main(){
	int nc=0;
	char ch,word[40];
	ifstream fin ;
	ofstream fout ;
	
	fin.open("in.txt",ios::in);
	fout.open("out.txt",ios::out);
   
		while(!fin.eof())
    {
    	fin.get(ch);
		if(ch>='A'&&ch<='Z')
		++nc ;
	}
	cout<<nc ;
	fout<<"no of char"<<nc ;
	
	fin.close();
	fout.close();

	return 0 ;
} 
