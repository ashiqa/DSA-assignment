#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
struct bstnode{
	struct bstnode* lc ;
	int data ;
	int min ;
	int max ;
	struct bstnode* rc ;
};
typedef struct bstnode* bstptr ;
void nodeInit(bstptr &I ,int data ,int min ,int max,queue <bstptr> &q){
    I=new(bstnode);
	I->data=data;
	I->min=min;
	I->max=max ;
	I->lc=NULL ;
	I->rc=NULL ;
	q.push(I);
}
void createByLevOrder(bstptr &T){
	bstptr P; 
	int c,i=-1;	vector<int> val ;cin>>c ;
	while(c!=-1){
	val.push_back(c);	
	cin>>c ;  }
	queue<bstptr> q ;
	nodeInit(T,val[++i],-999,999,q);
	while(!q.empty()){
		P=q.front();
		q.pop();
		if(val[i+1]<P->data && val[i+1]>P->min){
			nodeInit(P->lc,val[++i],P->min,P->data,q);
		}
		if(val[i+1]>P->data && val[i+1]<P->max){
			nodeInit(P->rc,val[++i],P->data,P->max,q);
		}
	}
}
void preorder(bstptr T){
	if(T==NULL)return ;
	cout<<T->data ;
	preorder(T->lc);
	preorder(T->rc);
}
int main(){
	bstptr T ;
	createByLevOrder(T);
	preorder(T);
	return 0 ;
}
