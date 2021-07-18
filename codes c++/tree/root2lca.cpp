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
   btptr lowestCommonAncestor(btptr root, char p, char q) {
       if(root==NULL)return NULL ; 
       if(root->data==p || root->data==q )return root ;
       btptr l=lowestCommonAncestor(root->lc,p,q);
       btptr r=lowestCommonAncestor(root->rc,p,q);
       if(l!=NULL&&r!=NULL)return root ;
         if(l!=NULL)return l ;
         if(r!=NULL)return r ;
         return NULL ;
     }

void printarr(char res[],int len){
    for(int i=0 ; i<len ;++i){
        cout<<res[i]<<" ";
    }
}  
btptr L;
void RootToNode(btptr T,char res[], int len){
    if(T==NULL)return ;
    res[len]=T->data ;
    ++len ;
    if(T->data==L->data){
        printarr(res,len);
    }
    else{
    RootToNode(T->lc,res,len);
    RootToNode(T->rc,res,len); }
}  
int main(){
    btptr T ;
    char k,a,b;
    cin>>k ;
    char res[1000000];
    insert(T,k);
    cin>>a>>b ;
    L=lowestCommonAncestor(T,a,b);
    RootToNode(T,res,0);
    return 0 ;
}}
