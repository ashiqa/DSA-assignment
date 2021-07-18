#include<iostream>
using namespace std ;
struct kstack{
	int size ;
	int top;
	int elements[50];
};
void push(struct kstack S[],int x , int kth){
	if(S[kth].size-1==S[kth].top){
		cout<<"stack full";
	}
	else{
		S[kth].elements[++S[kth].top]=x ;
	}
}
int pop(struct kstack S[], int kth){
	if(-1==S[kth].top){
		cout<<"stack empty";
	}
	else{
		return S[kth].elements[S[kth].top--] ;
	}
}
int main(){
	int k ,top[30],num,s;
	cout<<"enter k (no.of stacks) : ";
	cin>>k ;
	struct kstack S[k] ;
	cout<<"enter size of stack";
	cin>>s ;
	for(int i=0 ,j=-1; i<k;++i,j=j+s/k){
	 	S[i].size=s/k ;
		S[i].top=j ;
	}
	for(int j=0 ; j<k ;++j){
	cout<<"input stack "<<j+1;
	for(int i=0; i<s/k;++i){
		cout<<"enter num ";
		cin>>num ;
		
		push(S,num,j);
		
	} }
	cout<<"pop of each k stack" ;
	for(int j=0 ; j<k ;++j){
	cout<<pop(S,j)<<" ";
}
	return 0 ;
}
