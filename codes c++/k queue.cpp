#include<iostream>
using namespace std ;
struct queue{
	int size ;
	int f;
	int r ;
	static int element[];
};
int queue::element[10];
void enqueue(struct queue Q[], int x,int i){
	if(Q[i].f==(Q[i].r+1)%Q[i].size)
	cout<<"full";
	else{
		if(Q[i].f==2*i-1){
			Q[i].f=2*i ; Q[i].r=2*i ;
		}
		else{
			Q[i].r=(Q[i].r+1)%Q[i].size ;
		}
		Q[i].element[Q[i].r]=x ;
		cout<<i<<Q[i].element[Q[i].r];
	}}
int dequeue(struct queue Q[],int i){
	int t ;
	if(Q[i].f==2*i-1){
	cout<<"empty ";	}
	else{
		if(Q[i].f==Q[i].r){
			t=Q[i].element[Q[i].f];
			Q[i].f=2*i-1; Q[i].r=2*i-1 ;
		}
		else{
			t=Q[i].element[Q[i].f];
			Q[i].f=(Q[i].f+1)%Q[i].size ;	
		}
		return t ;
	}}
int main(){
	int k , s ,num;
	cout<<"enter k " ;cin>>k ;
	struct queue Q[k] ;
	cout<<"enter size of queue" ;
	cin>>s ;
	for(int i=0,j=-1 ;i<k ;++i,j=j+(s/k)){
		Q[i].size=s/k ;
		Q[i].f=j ;
		Q[i].r=j;}
	for(int j=0 ; j<k ;++j){
	cout<<"input queue "<<j+1;
	for(int i=0; i<(s/k);++i){
		cout<<"enter num ";
		cin>>num ;
		enqueue(Q,num,j);
	} }
	cout<<"dequeue each k queue " ;
	for(int j=0 ; j<k ;++j){
	for(int i=0 ; i<s/k;++i)	
	{ int g=dequeue(Q,j);
		cout<<g<<" ";
	}
}
	return 0 ;
}
