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
	int A[5]={4,5,2,1,3},n=5,x,y;
	struct queue Q ;
	Q.size=50 ;
	Q.f=-1 ;
	Q.r=-1 ;
	for(int i=0 ; i<5;++i){
		enqueue(Q,A[i]);
	}
	for(int i=0 ;i<4 ; i++){
		x=dequeue(Q);
		y=dequeue(Q);
		for(int j=0 ; j<=4-i;++j){
			if(x<y){
				enqueue(Q,x);
				x=dequeue(Q);
			}
			else{
				enqueue(Q,y);
			    y=dequeue(Q);
			}
		}
		if(x>y){
			enqueue(Q,y);
			enqueue(Q,x);
			}
		else{
			enqueue(Q,x);
			enqueue(Q,y);
			}
	}
	for(int i =0 ; i<5 ; ++i){
		cout<<dequeue(Q)<<" ";
	}
	return 0;
}
