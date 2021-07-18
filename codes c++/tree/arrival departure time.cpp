#include<bits/stdc++.h>
using namespace std ;
struct bstnode{
	struct bstnode* lc ;
	int data ;
	int AT ;
	int DT ;
	struct bstnode* rc ;
};
typedef struct bstnode* bstptr ;
void insert(bstptr &T,int k){
	if(T==NULL){
		T=new(bstnode);
		T->lc=NULL;
		T->rc=NULL;
		T->data=k ;
		T->AT=0;
		T->DT=0 ;
		return ;
	}
	else{
		if(k<T->data)
		insert(T->lc,k);
		else
		insert(T->rc,k);
	}	
}
void ATDTassign(bstptr &T,int &time){
	if(T==NULL){
		--time ; 
		return ;
	}
	T->AT=time ;
	++time ;    //arrival time increment for left child
	ATDTassign(T->lc,time);
	++time ;    //arrival time increment for right child
	ATDTassign(T->rc,time);
	++time ;    //departure time increment 
	T->DT=time ;
}
void preorder(bstptr T){
	if(T==NULL)return ;
	cout<<T->data<<" "<<T->AT<<" "<<T->DT<<endl ;
	preorder(T->lc);
	preorder(T->rc);
}
int main(){
	bstptr T ;
	T=NULL;
	int A[9]={5 , 3, 7 ,2 ,4, 6 ,9 ,1,8};
	int k ;
	while(k<9 ){
		insert(T,A[k]);
		++k;
	}
	int time=0 ;
	ATDTassign(T,time);
	preorder(T);
	return 0 ;
}
