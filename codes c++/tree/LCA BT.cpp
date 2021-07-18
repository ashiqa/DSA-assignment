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
	cin>>ch ;
	if(ch!='.')insert(T->lc,ch);
	cin>>ch;
	if(ch!='.')insert(T->rc,ch);
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
void allRootToLeaf(bstptr T,vector<int> res, btptr lca){
    if(T==NULL)return ;
    if(T->data==lca->data){
        res.push_back(T->data);
        for(int i=0 ; i<res.size();++i)
        cout<<res[i]<<" "; cout<<endl ;
        return ;
    }
    res.push_back(T->data);
    allRootToLeaf(T->lchild,res);
    allRootToLeaf(T->rchild,res);
    res.pop_back();
}    
int main(){
    btptr T,L ;
    char k,a,b;cin>>k ;
    vector<int> res;
    insert(T,k);
    cin>>a>>b ;
    L=lowestCommonAncestor(T,a,b);
    allRootToLeaf(T,res,L);
    return 0 ;
}

