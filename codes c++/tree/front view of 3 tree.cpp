#include<iostream>
#include <bits/stdc++.h>
using namespace std ;
struct btnode{
	struct btnode *lc ;
	int data ;
	struct btnode *rc ;
};
typedef struct btnode *btptr ;

void insert(btptr &T,int k){
		T=new(btnode);
		T->data=k ;
		T->lc=NULL;
		T->rc=NULL ;
	int ch ;
	cin>>ch;
	if(ch!=0)insert(T->lc,ch);
	cin>>ch ;
	if(ch!=0)insert(T->rc,ch);
}
void frontview(btptr T,int level , int hd , map<vector<int>, int> &res,int dn){
    if(T==NULL)return ;
    vector<int> data_1{};
    data_1.push_back(level);
    data_1.push_back(hd);
     data_1.push_back(dn);
    res[data_1]=T->data;
    frontview(T->lc,level+1,hd-1,res,1);
    frontview(T->rc,level+1,hd+1,res,0);
}
int main(){
    btptr T1,T2,T3;
    T1=NULL;T2=NULL;T3=NULL;
    int y;
    cin>>y;
    insert(T1,y);
    cin>>y ;
    insert(T2,y);
    cin>>y ;
    insert(T3,y);
    map<vector<int>, int> res ;
    map<vector<int>, int> :: iterator it ; 
    frontview(T1,0,0,res,-1);
    frontview(T2,0,0,res,-1);
    frontview(T3,0,0,res,-1);
    for(it=res.begin();it!=res.end();++it){
        cout<<it->second<<" ";
    }
    return 0 ;
}
