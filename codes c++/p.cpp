#include<iostream>
using namespace std ;
struct node{
	int tag ;
	union{
		int num;
		char c ;
		struct node* dlink ;
	}data;
	struct node* next ;
};
typedef struct node* mllptr ;
int n ;
void MLLinsert(mllptr prev){
	mllptr T ;
	T=new(node);
	cin>>n;
	if(n==-2||n==-1){
		return ;
	}
	else if(n>1){
		if(prev->tag==3){
			
			T->tag=4 ; //tag4 for (
			T->data.c='(';
			T->next=NULL ;
			prev->next=T ;
			prev=T ;
		}
		T=new(node);
		T->tag=1 ;  //tag 1 for numbers
		T->data.num=n ;
		T->next=NULL;
	}
	else if(n==0){
		T->tag=3 ; // tag3 for )
		T->data.c=')';
		T->next=NULL ;
	}
	else if(n==1){
		T->tag=2 ;       //tag2 for ptr to node
		mllptr S;
		S=new(node);
		MLLinsert(S);
		T->data.dlink=S ;
		T->next=NULL;
		prev->next=T;
		prev=T;
		T=new(node);
		T->tag=3 ;  //tag3 for )
		T->data.c=')';
		T->next=NULL;
	}
	if(prev!=NULL){
		prev->next=T;
	}
	 prev=T ;
	MLLinsert(prev);
}
void print(mllptr P){
	if(P==NULL)return ;
	if(P->tag==3||P->tag==4){
		cout<<P->data.c<<" ";
	}
	if(P->tag==1){
		cout<<P->data.num<<" " ;	
	}
	else {
		print(P->data.dlink->next);
	}
	print(P->next);
}
int main(){
	mllptr ML ;
	ML=new(node);
	MLLinsert(ML);
	print(ML->next);
	return 0 ;
}
