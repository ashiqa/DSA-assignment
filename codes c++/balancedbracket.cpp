#include<iostream>
using namespace std ;
struct stack {
	int size ;
	int top ;
	char element[50];
};
void push(struct stack &S , int x ){
	if(S.top==S.size-1)
		cout<<"stack full";
	else
		S.element[++S.top]=x ;
}
int  pop(struct stack &S){
	if(S.top==-1)
		cout<<"stack empty";
	else
		return(S.element[S.top--] );
}
int main(){
	struct stack S ;
	cout<<"enter size of stack ";
	cin>>S.size ;
	S.top=-1 ;
    string brktstr ;
    cout<<"enter bracket string of one type : { } ";
    cin>>brktstr;
   	
    for(int i=0 ; i<brktstr.size();++i){
    	if(brktstr[i]=='{')
    		push(S,1);
    	else if(brktstr[i]=='}')	
    	 int g=pop(S);
	}
	if(S.top==-1)
		cout<<"bracket balanced";
	else
		cout<<"not balanced brackets ";	
	return 0 ; 	
}
