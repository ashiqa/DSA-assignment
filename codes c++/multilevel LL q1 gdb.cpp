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
int n ;
void multilevelinsert(mlptr prev){
	mlptr mptr ;
	mptr=new(mlnode);
	cout<<"enter value : ";
	cin>>n ;
	if(n==-2||n==-1)return ;
	if(n>1){
		mptr->tag=0 ;
		mptr->data.mldata=n ;	
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
void print(mlptr P){
	if(P==NULL)return ;
	if(P->tag==0){
	if(P->data.mldata!=0)
		cout<<P->data.mldata ;	
	}
	else {
		print(P->data.dlink->next);
	}
	print(P->next);
}
int main(){
	mlptr ML ;
	ML=new(mlnode);
	multilevelinsert(ML);
	print(ML->next);
	return 0;
}
