#include<iostream>
//errors down link only works from the third element 
using namespace std ;
struct mlnode{
	int tag ;
	union{
		char cdata ;
		struct mlnode *dlink ;
	}data;
	struct mlnode *next ;
};
typedef struct mlnode* mlptr ;

void multilevelinsert(mlptr mptr){
	mlptr T; char n ;
	T=new(mlnode);
	cout<<"enter tag";
	cin>>mptr->tag;
	cout<<"enter char";
	cin>>mptr->data.cdata ;
	mptr->next=NULL ;
	cout<<"enter tag";
	cin>>T->tag ;
	if(T->tag==0){
		cout<<"enter char ";cin>>n ;
		while(n!='}'){
		if(T->tag==0){
		 	T->data.cdata=n ;
		 	T->next=NULL ;
			mptr->next=T;
			mptr=T;
		}
		else{
			mlptr S;
			S=new(mlnode);
			multilevelinsert(S);
			T->data.dlink=S;
			T->next=NULL ;
			mptr->next=T;
			mptr=T;
		}
		T=new(mlnode);
		cout<<"enter tag";
		cin>>T->tag ;
		if(T->tag==0){
			cout<<"enter char";
			cin>>n ;
		}
		else n='z';
	} 
	if(n=='}')return ;
	}
	
}
void print(mlptr P){
	if(P==NULL)return ;

	if(P->tag==0){
		cout<<P->data.cdata ;	
	}
	else {
		print(P->data.dlink);
	}
	print(P->next);
}
int main(){
	mlptr ML ;
	ML=new(mlnode);
	multilevelinsert(ML);
	print(ML);
	return 0;
}
