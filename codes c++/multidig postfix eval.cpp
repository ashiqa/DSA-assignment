#include<iostream>
using namespace std ;
union U {
	int opnd ;
	char optr ;
};
struct stack {
	int size ;
	int top ;
	int element[50];
};
void push(struct stack&S,int x){
	if(S.top==S.size-1)
	cout<<"stack is full";
	else 
		S.element[++S.top]=x ;
}
int pop(struct stack &S){
	if(S.top==-1)
	cout<<"stack is empty" ;
	else 
	return S.element[S.top--];
}
int eval(int op1 , int op2 , char optr){
	switch(optr){
		case '+' : return op1+op2 ;
					break ;
		case '*' : return op1*op2 ;
					break ;
		case '-' : return op1-op2 ;
					break ;
		case '/' : return op1/op2 ;
					break ;									
	}
}
int main(){
	union U A[10] ;
	struct stack S ;
	int n ,ch,op1,op2,res;
	cout<<"enter size of expression";
	cin>>n;
	for(int i=0 ; i<n ;++i)
	{   if(i%2==1){
		A[i].optr=' ' ;
		continue ;
	}
	cout<<"press 1 for operand and 0 for operator";
	 	cin>>ch ;
	 	if(ch==1){
            cout<<"enter operand";
	 		cin>>A[i].opnd ;
			push(S,A[i].opnd ); 
			 }
	 	else{
	 		cout<<"enter operator";
	 		cin>>A[i].optr ;
	 		op2=pop(S);
	 		op1=pop(S);
	 		res=eval(op1,op2,A[i].optr);
	 		push(S,res);
	 	}
	}
	cout<<"result is :";
	cout<<res ; 
   return 0 ;	
}

