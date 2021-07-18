#include<iostream>
using namespace std ;
struct stack {
	int size ;
	int top ;
	char element[50];
};
void push(struct stack &S , char x ){
	if(S.top==S.size-1)
		cout<<"stack full";
	else
		S.element[++S.top]=x ;
}
char pop(struct stack &S){
	if(S.top==-1)
		cout<<"stack empty";
	else
		return(S.element[S.top--] );
}
char peek(struct stack &S){
	if(S.top==-1)
		cout<<"stack empty";
	else
		return(S.element[S.top] );
}

int main(){
	struct stack S ;
	cout<<"enter size of stack ";
	cin>>S.size ;
	S.top=-1 ;
	char g ;
    string brktstr ;
    int flag=0;
    cout<<"enter bracket string of one type : ( ) ";
    cin>>brktstr;
   	
    for(int i=0 ; i<brktstr.size();++i){
    	if(brktstr[i]=='(')
    		push(S,'(');
    	else if(brktstr[i]==')'){
    		if(peek(S)=='(') 
    		{ g=pop(S);
    		  push(S,'1');
			}
		
		 	else {
			char k=pop(S) ; pop(S);
			int ans=2*(k-'0') ;
			if(g==')'|| g=='(')
			push(S,ans);	
			else{
				char x1=pop(S);
				push(S,x1+'0'+ans);
				}
			}
			
		}	
	}
	char res ;
	res=pop(S);
	cout<<res ;
	
	return 0 ; 	
}
