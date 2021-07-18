#include<iostream>
using namespace std ;
struct queue{
	int size ;
	int f;
	int r ;
	string element[50];
};
void enqueue(struct queue &Q, string x){
	if(Q.size==Q.r+1)
	return ;
	else{
		if(Q.f==-1){
			Q.f=0 ; Q.r=0 ;
		}
		else{
			Q.r=Q.r+1 ;
		}
		Q.element[Q.r]= x;
	}
}
string dequeue(struct queue &Q){
	string t ;
	if(Q.f==-1)
	cout<<"empty";
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
	int n ;
	cin>>n ;
	struct queue Q ;
	Q.size=n ;Q.f=-1 ;Q.r=-1 ;
	enqueue(Q,"1");
	for(int i=1 ; i<=n;++i){
		enqueue(Q,Q.element[Q.f]+'0');
		enqueue(Q,Q.element[Q.f]+'1');
		cout<<Q.element[Q.f]<<" ";
		dequeue(Q);
	}
	return 0 ;	
}
