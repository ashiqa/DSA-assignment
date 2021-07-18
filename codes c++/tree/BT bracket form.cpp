#include<iostream>
#include <bits/stdc++.h>
using namespace std ;
struct btnode{
	struct btnode *lc ;
	char data ;
	struct btnode *rc ;
};
typedef struct btnode *btptr ;

void insert(btptr &T,char k){
	if(T==NULL){
		T=new(btnode);
		T->data=k ;
		T->lc=NULL;
		T->rc=NULL ;
	}
	char ch ;
	cout<<"enter left child of "<<k ;
	cin>>ch ;
	if(ch!='#')insert(T->lc,ch);
	cout<<"enter right child of "<<k ;
	cin>>ch;
	if(ch!='#')insert(T->rc,ch);
}
void preorder(btptr T ){
    if(T==NULL)return ;
    char t=T->data;
    cout<<t;
    if(T->lc!=NULL)cout<<"(";
    preorder(T->lc);
    preorder(T->rc);
    if(T->rc!=NULL)cout<<")";
}
int main(){
    btptr T ;
    char k ;cin>>k ;
    insert(T,k);
    preorder(T);
    return 0 ;
}
