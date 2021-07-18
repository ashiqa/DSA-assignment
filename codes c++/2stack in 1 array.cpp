#include<iostream>
using namespace std ;
struct twostacks{
	int size ;
	int top1 ;
	int top2 ;
	int element[50];
};
void push1(struct twostacks &S,int x){
	if(S.top2==S.top1+1)
	cout<<"stack is full";
	else{
	    S.element[++S.top1]=x ;	
	}
}

void push2(struct twostacks &S,int x){
	if(S.top2==S.top1+1)
	cout<<"stack is full";
	else{
		 S.element[--S.top2]=x ;
	}
}
int pop1(struct twostacks &S){
	if(S.top1==-1)
	cout<<"stack is empty";
	else{
	   return S.element[S.top1--] ;	
	}
}
int pop2(struct twostacks &S){
	if(S.top2==S.size+1)
	cout<<"stack is empty";
	else{
		 return S.element[S.top2++] ;	
	}	
}
int main(){
	struct twostacks S ;
	int x;
	cout<<"enter size of dual stack";
	cin>>S.size ;
	S.top1=-1 ;
	S.top2=S.size;
	cout<<"enter stack 1";
	for(int i=0 ; i<S.size/2;++i){
		cout<<"enter num";
		cin>>x ;
		push1(S,x);
	}
	for(int i=S.size/2;i<S.size;++i){
		cout<<"enter num";
		cin>>x ;
		push2(S,x);
	}
	cout<<pop1(S)<<endl;
	cout<<pop2(S);
	return 0 ;
}
