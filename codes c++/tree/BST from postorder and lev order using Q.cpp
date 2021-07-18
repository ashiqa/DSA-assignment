#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std ;
struct bstnode{
	struct bstnode *lc ;
	int data ;
	struct bstnode *rc ;
};
int find(int c,vector<int> lrd,int l,int h){
	int j;
	for(j=l;j<=h;j++)if(lrd[j]>=c)return j;
}
typedef struct bstnode *bstptr ;
void constructTree(bstptr &T,vector<int> lrd,int l,int h){
	if(l>h)return;
		T=new(bstnode);
		T->data=lrd[h];
		T->lc=NULL;T->rc=NULL;
		int j=find(lrd[h],lrd,l,h);
		constructTree(T->rc,lrd,j,h-1);
		constructTree(T->lc,lrd,l,j-1);
}
void levelorderQ(bstptr T){
	queue<bstptr> q ;
	bstptr hsh ;
	hsh=new(bstnode);
	hsh->data=-1;
	hsh->lc=hsh->rc=NULL;
	q.push(T);
	q.push(hsh);
	while(!q.empty()){
		T=q.front();
		if(T->data!=-1)
		cout<<T->data<<" " ;
		q.pop();
		if(T->lc!=NULL)q.push(T->lc);
		if(T->rc!=NULL)q.push(T->rc);
		T=q.front();
		if(T->data==-1){
			cout<<endl ;
			q.push(T);
			q.pop(); }
	}
}
int main(){
    bstptr T ;
    T=NULL;
    vector<int> lrd;int k,i;
    cin>>k ;
    while(k!=-1){
        lrd.push_back(k);
        cin>>k ;  }
        i=lrd.size()-1;
    constructTree(T,lrd,0,i);
    levelorderQ(T);
    return 0 ;
}

