#include<iostream>
using namespace std ;

struct mlnode{
	int tag ;
	union{
		int mldata ;
		struct mlnode *dlink ;
	}data;
	struct mlnode *next ;
};
typedef struct mlnode* mlptr ;
struct queue{
	int size ;
	int f;
	int r ;
	mlptr element[50];
};
int n ;
void multilevelinsert(mlptr prev){
	mlptr mptr ;
	mptr=new(mlnode);
	
	cin>>n ;
	if(n==-2||n==-1)return ;
	if(n>1){
		mptr->tag=0 ;
		mptr->data.mldata=n ;	
		cout<<mptr->data.mldata ;
	}
	else if(n==1){
		mptr->tag=1 ;
		mlptr S;
		S=new(mlnode);
		multilevelinsert(S);
		mptr->data.dlink=S ;
	}
	mptr->next=NULL ;
	if(prev!=NULL){
		prev->next=mptr ;
	}
	 prev=mptr ;
	multilevelinsert(prev);
}

void enqueue(struct queue &Q, mlptr x){
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
mlptr dequeue(struct queue &Q){
	mlptr t ;
	if(Q.f==-1)
	cout<<"empty ";
	else{
		if(Q.f==Q.r){
			t=Q.element[Q.f];
			Q.f=-1 ; Q.r=-1 ;
		}
		else{
			t=Q.element[Q.f];
			Q.f=Q.f+1 ;	
		}
	}
}
int flag=1 ;
void printlevel(mlptr P,struct queue &Q){
	while(Q.f!=-1||flag){
		if(P==NULL){
			flag=1 ;
			P=dequeue(Q);
		}
	if(P->tag==0){
	if(P->data.mldata!=0)
		cout<<P->data.mldata<<" ";
	}
	else {
		flag=0 ;
		enqueue(Q,P->data.dlink->next);
	}
	P=P->next ;
}
}
void printdepth(mlptr P){
	if(P==NULL)return ;
	if(P->tag==0){
	if(P->data.mldata!=0)
		cout<<P->data.mldata<<" " ;	
	}
	else {
		printdepth(P->data.dlink->next);
	}
	printdepth(P->next);
}
int main(){
	struct queue Q ;
	 Q.size=50 ;
	 Q.f=-1 ;
	 Q.r=-1 ;
	mlptr ML ;
	ML=new(mlnode);
	multilevelinsert(ML);
	printlevel(ML->next,Q);
	cout<<endl ;
	printdepth(ML->next);
	return 0;
}lk
