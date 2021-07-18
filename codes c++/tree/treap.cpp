#include<iostream>
using namespace std ;
struct trpnode{
	char data ;
	int pri ;
	struct trpnode* lc ;
	struct trpnode* rc ;
};
typedef struct trpnode *trptr ;
trptr r_rotate(trptr T){
	trptr tlc ;
	tlc=T->lc ;
	T->lc=tlc->rc ;
	tlc->rc=T ;
	return tlc;
}
trptr l_rotate(trptr T){
	trptr trc ;
	trc=T->rc ;
	T->rc=trc->lc ;
	trc->lc=T ;
	return trc ;
}
void insert(trptr &T,char val,int prio){
	if(T==NULL){
		T=new(trpnode);
		T->data=val ;
		T->pri=prio ;
		T->lc=NULL ;
		T->rc=NULL;
		return ;
	}
	if(val<T->data){
		insert(T->lc,val,prio);
		if(T->pri<T->lc->pri)T=r_rotate(T);
	}
	else if(val>T->data){
		insert(T->rc,val,prio);
		if(T->pri<T->rc->pri)T=l_rotate(T);
	}
}
void preorder(trptr T){
	if(T==NULL)return ;
	cout<<T->data<<" ";
	preorder(T->lc);
	preorder(T->rc);
}
int main(){
	trptr T ;
	T=NULL ;
	char k ; int pr ;
	cin>>k ;
	while(k!='#'){
		cin>>pr ;
		insert(T,k,pr);
		cin>>k ;
	}
	preorder(T);
	return 0 ;
}
