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
int main(){
