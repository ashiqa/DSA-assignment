#include<iostream>
using namespace std ;
struct queue{
	int size ;
	int f;
	int r ;
	int element[50];
};
struct stack {
	int size ;
	int top ;
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
int main(){
	struct stack S ;
	struct queue Q ;
	int n , x ;
	cin>>n ;
	S.size=n ;Q.size=n ; S.top=-1 ;Q.f=-1 ; Q.r=-1 ;
	for(int i=0 ; i<n ;++i)
	{
		cin>>x ;
		enqueque(Q,x);
	}
	for(int i=0 ; i<n ;++i)
	{  
	   x=dequeue(Q);
	   push(S,x);
	}
	for(int i=0 ; i<n ;++i)
	{  int x=pop(S);
	   enqueque(Q,x); 
	}
	cout<<"reverse Q";
	for(int i=0 ; i<n ;++i)
	{ x=dequeue(Q);
		cout<<x;
		
	}
	return 0 ;
}
