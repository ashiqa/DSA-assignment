#include<iostream>
#include<vector>
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
		cout<<Q.element[Q.r];
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
void sort(struct queue &Q){
	vector<int> y ;
	if(Q.f==-1)return ;
	else{
		int x=dequeue(Q);
		sort(Q);
		if(Q.f==-1)enqueue(Q,x);
		else if(x>Q.element[Q.r]){
		
			enqueue(Q,x);
		}
		else if(x<Q.element[Q.f]){
			int j=0;
			while(Q.f!=-1 && x<Q.element[Q.f]){
				y[j]=dequeue(Q) ; 
				++j; 
			}
			enqueue(Q,x);
			int k=0 ;
			while(k<j){
				enqueue(Q,y[j]);
				++k;
			}
		}
		else{
			int j=0;
			while(Q.f!=-1 && x<Q.element[Q.f]){
				y[j]=dequeue(Q) ; 
				++j; 
			}
		}
	}
}
int main(){
	struct queue Q ;
	int n,x ;
	cin>>n ;
	Q.size=n;Q.f=-1 ;Q.r=-1 ;
	for(int i=0 ; i<n;++i){
		cin>>x ;
		enqueue(Q,x);
	}
	sort(Q);
	for(int i=0 ; i<n;++i){
		x=dequeue(Q);
		cout<<x<<" " ;
	}
	return 0 ;
}
