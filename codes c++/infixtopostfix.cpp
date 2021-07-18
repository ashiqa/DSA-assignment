#include<iostream>
using namespace std ;
union U {
	int opnd ;
	char optr ;
};
struct stack {
	int size ;
	int top ;
	char element[50];
};
void push(struct stack&S,char x){
	if(S.top==S.size-1)
	cout<<"stack is full";
	else 
		S.element[++S.top]=x ;
}
char pop(struct stack &S){
	if(S.top==-1)
	cout<<"stack is empty" ;
	else 
	return S.element[S.top--];
}
int value(struct stack &S,char optr){
	if((optr=='*'||optr=='/')&&(S.element[S.top]=='+' ||S.element[S.top]=='-'))
		return 1;
	if(optr=='(')return 1 ;
	if(optr==')') return 2 ;	
	else return 0;
}
int main(){
	int n ,j=0,tag[10],ch,ifpush;
	cout<<"enter size";
	cin>>n ;
	union U A[10],B[10] ;
	struct stack S ;
	S.top=-1 ;
	S.size=n ;
	for(int i=0 ; i<n ;++i )
	{   cout<<"press 1 for operand and 0 for operator";
	 	cin>>ch ;
	 	if(ch==1){
            cout<<"enter operand";
	 		cin>>A[i].opnd ;
			B[j].opnd=(A[i].opnd);tag[j]=1 ;++j; }
	 	else{
	 		cout<<"enter operator";
	 		cin>>A[i].optr ;
	 		ifpush=value(S , A[i].optr);
	 		if(ifpush==1){
	 			push(S,A[i].optr);
			 }
			else if(ifpush==0){
				while(S.top!=-1){
					B[j].optr=pop(S);tag[j]=0 ;++j ;
				}
				push(S,A[i].optr);
			} 
			else if(ifpush==2){
				while(S.element[S.top]!=')'){
					B[j].optr=pop(S);tag[j]=0 ;++j ;
				}	
				int g=pop(S);
			}
	 	}
	}
	if(S.top!=-1){
	B[j].optr=pop(S);tag[j]=0 ;}
	
	for(int i=0 ; i<n ;++i )
	{ if(tag[i]==1)
		cout<<B[i].opnd ;
	  else 
	  	cout<<B[i].optr ;	
	}
	return 0 ;
}
