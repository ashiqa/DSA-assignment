#include<iostream>
using namespace std ;
struct stack{
	int top ;
	int size ;
	int element[50];
};
void push(struct stack &S,int x){
	if(S.top==S.size-1){
		cout<<"full";
	}
	else{
		S.element[++S.top]=x ;
	}	
}
int pop(struct stack &S){
	if(S.top==-1)
	cout<<"empty";
	else{
	   return S.element[S.top--] ;
	}
}
int peek(struct stack &S){
	if(S.top==-1)
	cout<<"empty";
	else{
	   return S.element[S.top] ;
	}
}
int main(){
	int n,x ;
	cout<<"enter size of stack to sorted : " ;cin>>n ;
	struct stack S , tempS ;
	S.top=-1;tempS.top=-1 ; S.size=n ;tempS.size=n ;
	for(int i=0 ; i<n;++i){   //input main stack S 
		cin>>x ; push(S,x);
	}
	while(S.top!=-1){   
		if(tempS.top==-1){ int in=pop(S); 
		push(tempS,in);}
		
		else if(peek(S)<=peek(tempS)){
			int val3=pop(S);
			push(tempS,val3);
		}
		else{
			int val1=pop(S);
			while(val1>peek(tempS)){
			int val=pop(tempS); 
			push(S,val);
			}
			push(tempS,val1); 
		}	
	}
	for(int i=0 ; i<n;++i){   //input main stack S 
		x=pop(tempS);
		cout<<x ;
	}
	return 0 ;
}
