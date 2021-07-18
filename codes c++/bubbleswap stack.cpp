#include <stdio.h>
#include<iostream>
using namespace std ;
struct stack{
	int size ;
	int top ;
	int elements[50];
};
void push(struct stack &S,int x){
	if(S.size-1==S.top)
	cout<<"stack full";
	else{
	    
		S.elements[++S.top]=x;
	}
}
int pop(struct stack &S){
	if(S.top==-1){
		cout<<"stack empty";
	}
	else{
		return S.elements[S.top--];
	}
}
int main(){
	struct stack S1 ,S2 ;
	S1.top=-1 ;S2.top=-1 ;
	int n ,x ,A[20];
	cout<<"enter size of stack 1";
	cin>>S1.size ;
	cout<<"enter size of stack 2";
	cin>>S2.size ;
	n=S1.size+S2.size ;
	cout<<"input stack 1";
	for(int i=0; i<S1.size;++i){
		cout<<"enter num : ";
		cin>>x ;
		push(S1,x);
	}
	cout<<"input stack 2 : ";
	for(int i=0; i<S2.size;++i){
		cout<<"enter num : ";
		cin>>x ;
		push(S2,x);
	}
	for(int i=0; i<S1.size;++i){
		A[i]=pop(S1);
	}
	for(int i=0; i<S2.size;++i){
		A[i+S1.size]=pop(S2);
	}
	
	for(int i=0 ; i<n-1;++i){
	    for(int j=0 ; j<n-i-1;++j)
	    {
	        if(A[j]>A[j+1])swap(A[j],A[j+1]);
	    }
	}
	for(int i=0 ; i< n; ++i){
		cout<<A[i]<<" ";
	}
return 0 ;	
}
