#include<iostream>
using namespace std ;
struct stack{
	int size ;
	int top;
	int element[50];
};
void push(struct stack &S ,int x){
	if(S.top==S.size-1)
	 cout<<"stack full ";
	else{
		S.element[++S.top]=x ;	
		//cout<<S.element[S.top];	
	}
}
int pop(struct stack &S){
	if(S.top==-1){
		cout<<"stack is empty " ;
		//return ;
	}
	else 
	{   return (S.element[S.top--]);
		}	
}

int main(){
	int n ;
	cout<<"enter number ";
	cin>>n ;
	struct stack S ;
	cout<<"enter stack size";
	cin>>S.size ;
	S.top=-1 ;
	while(n>0){
		int rem=n%10 ;
		push(S,rem);
		n=n/10 ;
	}
	  while(S.top!=-1)
		cout<<pop(S);
	
	return 0 ;
}
