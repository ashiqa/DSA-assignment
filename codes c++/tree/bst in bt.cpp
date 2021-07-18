#include<iostream>
#include <bits/stdc++.h>
#include<vector> 
using namespace std ;
struct btnode{
	struct btnode *lc ;
	int data ;
	struct btnode *rc ;
};
typedef struct btnode *btptr ;

void insert(btptr &T,int k){
	if(T==NULL){
		T=new(btnode);
		T->data=k ;
		T->lc=NULL;
		T->rc=NULL ;
	}
	int ch ;
	cin>>ch ;
	if(ch!=0)insert(T->lc,ch);
	cin>>ch;
	if(ch!=0)insert(T->rc,ch);
}
vector<int>in ;

void inorderT(btptr T){
	if(T==NULL){
	 return ;
	}
	inorderT(T->lc);
	in.push_back(T->data);
	inorderT(T->rc);
}

int main(){
    btptr T ;
    T=NULL ;
    int k,maxlen=1,len=1,start=0,sid,eid ;
    cin>>k ;
    insert(T,k);
    inorder(T);
    for(int i=1 ; i<in.size();++i){
        if(in[i]>in[i-1])len++ ;
        else{
            if(len>maxlen)maxlen=len ;
            if(maxlen==len){
                sid=start ;
                eid=i-1;
            }
            start=i ;
        }
    }
    for(int i=sid ; i<=eid;++i)cout<<in[i]<<" ";
    return 0;
}

