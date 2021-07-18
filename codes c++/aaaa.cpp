#include<iostream>
using namespace std ;
struct mlnode{
	int tag ;
	union{
		char mldata ;
		struct mlnode *dlink ;
	}data;
	struct mlnode *next ;
};
typedef struct mlnode* mlptr ;
char n ;
void multilevelinsert(mlptr prev){
	mlptr mptr ;
	mptr=new(mlnode);
	cin>>n ;
	if(n=='}'){ cout<<"}";}
	if(n=='}'||n=='#')return ;
	
	else if(n=='{'){
	    cout<<"{"<<" ";
		mptr->tag=1 ;
		mlptr S;
		S=new(mlnode);
		multilevelinsert(S);
		mptr->data.dlink=S ;
		mptr->next=NULL ;
	}
	else{
		mptr->tag=0 ;
		mptr->data.mldata=n ;
		mptr->next=NULL ;
		cout<<mptr->data.mldata<<" ";
	}
	
	if(prev!=NULL){
		prev->next=mptr ;
	}
	 prev=mptr ;
	multilevelinsert(prev);
}
// void print(mlptr P){
// 	if(P==NULL){cout<<"}"<<" ";return ;}
// 	if(P->tag==0){
// 		cout<<P->data.mldata<<" " ;	
// 	}
// 	else {
// 	    cout<<"{"<<" ";
// 		print(P->data.dlink->next);
// 	}
// 	print(P->next);
// }
int main(){
	mlptr ML ;int x ;
	cin>>x;
	cout<<"{"<<" ";
	multilevelinsert(ML);
	//print(ML->next);
	cout<<"}";
	return 0;
}

