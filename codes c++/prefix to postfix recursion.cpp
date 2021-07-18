#include<iostream>
#include <string.h>
using namespace std ;
struct stack{
	int top ; 
	int size ;
	string element[50];
};
void push(struct stack &S , string s ){
	if(S.size-1==S.top){
		cout<<"stack is full";
	}
	else{
		S.element[++S.top]=s;
	}
}
string pop(struct stack &S){
	if(S.top==-1){
	 cout<<"stack is empty";
	}
	else
	  return S.element[S.top--];
	
}
void pretopost(struct stack &S ,string prefix , int i ){
	
	if(i==-1){
	
	return ; }
	
	if(prefix[i]>=65&& prefix[i]<=90){
			push(S,string(1,prefix[i]));
			pretopost(S,prefix , i-1);
	}
	else {
			string s="" ;
			string op1=pop(S);string op2=pop(S);
			s=op1+op2+prefix[i];
			push(S,s);
			pretopost(S,prefix , i-1);
		}
	}
	

int main(){
	struct stack S ;
	string prefix  ;
	cout<<"enter prefix expression : ";
	cin>>prefix ;	  
	pretopost(S,prefix ,prefix.size()-1);
	cout<<"postfix expression";
	string res =pop(S);
	cout<<res;
	return 0 ;
}
