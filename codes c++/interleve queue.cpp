#include<iostream>
using namespace std ;
struct queue{
	int size ;
	int f;
	int r ;
	int element[50];
};
void enqueue(struct queue &Q, int x){
	if(Q.size==Q.r+1)
	cout<<"full";
	else{
		if(Q.f==-1){
			Q.f=0 ; Q.r=0 ;
		}
		else{
			Q.r=Q.r+1 ;
		}
		Q.element[Q.r]=x ;
	}
}
int dequeue(struct queue &Q){
	int t ;
	if(Q.f==-1)
	cout<<"emtpy";
	else{
		if(Q.f==Q.r){
			t=Q.element[Q.f];
			Q.f=-1 ; Q.r=-1 ;
		}
		else{
			t=Q.element[Q.f];
			Q.f=Q.f+1 ;	
		}
		return t ;
	}
}
int main(){
	int n ,x,y;
	cin>>n ;
	struct queue Q , Q1,Q2 ;
	Q.f=-1 ;Q.r=-1 ;Q1.f=-1 ;Q1.r=-1 ;Q2.f=-1 ;Q2.r=-1 ;
	Q.size=10 ; Q1.size=10 ; Q2.size=10 ;
	for(int i=0 ; i<n ;++i){
		cin>>x ;
		enqueue(Q,x);
	}
	for(int i=0 ; i<n/2 ;++i){
		x=dequeue(Q);
		enqueue(Q1,x);
	}
	for(int i=0 ; i<n/2 ;++i){
		x=dequeue(Q);
		enqueue(Q2,x);
	}
	for(int i=0 ; i<n ;++i){
		if(i%2==0){
			x=dequeue(Q1);
			enqueue(Q,x);
		}
		else{
			x=dequeue(Q2);
			enqueue(Q,x);
		}
	}
	for(int i=0 ; i<n ;++i){
		x=dequeue(Q);
		cout<<x<<" ";
	}
	return 0 ;
}
