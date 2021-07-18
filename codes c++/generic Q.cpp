#include<iostream>
using namespace std ;
union U{
	int i;
	float fl ;
	char c ;
}; 
struct queue{
	int size ;
	int f;
	int r ;
	union U element[50];
};
void enqueue(struct queue &Q, int cho){
	int x ;
	char z ;
	float y ;
	if(Q.f==(Q.r+1)%Q.size)
	cout<<"full";
	else{
		if(Q.f==-1){
			Q.f=0 ; Q.r=0 ;
		}
		else{
			Q.r=(Q.r+1)%Q.size;
		}
		if(cho==1){
			cout<<"enter number ";
			cin>>x ;
			Q.element[Q.r].i=x ;
		}
		else if(cho==2){
			cout<<"enter float no ";
			cin>>y;
			Q.element[Q.r].fl=y ;
		}
		else{
			cout<<"enter char ";
			cin>>z ;
			Q.element[Q.r].c=z;	
		}
	
	}
}
void dequeue(struct queue &Q,int cho){
	//int t ; char ch ; float fl ;
	if(Q.f==-1)
	cout<<"emtpy";
	else{
		if(Q.f==Q.r){
			if(cho==1)
			cout<<Q.element[Q.f].i;
			else if (cho==2 )
			cout<<Q.element[Q.f].fl ;
			else cout<<Q.element[Q.f].c ;
			Q.f=-1 ; Q.r=-1 ;
		}
		else{
			if(cho==1)
			cout<<Q.element[Q.f].i;
			else if (cho==2 )
			cout<<Q.element[Q.f].fl ;
			else cout<<Q.element[Q.f].c ;
			Q.f=(Q.f+1)%Q.size;	
		}
		
	}
}
int main(){
	int n ,tag[25];
	//union U x ;
	struct queue Q ;
	cin>>n ;
	Q.size=n ;
	Q.f=-1 ; Q.r=-1 ;
	cout<<"input  for generic queue";
	
	for(int i=0; i<n;++i){
		cout<<"enter input (1-no , 2- float , 3-char)";
		cin>>tag[i];
		enqueue(Q,tag[i]);
	}	
	cout<<"output for genric queue";
	for(int i=0; i<n;++i){
		dequeue(Q,tag[i]);
	}	
	return 0 ;
}
