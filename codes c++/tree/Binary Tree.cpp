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
	cout<<"enter left child of "<<k;
	cin>>ch ;
	if(ch!='.')insert(T->lc,ch);
	cout<<"enter right child of "<<k;
	cin>>ch;
	if(ch!='.')insert(T->rc,ch);
}
void serialiseTree(btptr T){
	if(T==NULL){
		cout<<"."; return ;
	}
	cout<<(T->data);
	serialiseTree(T->lc);
	serialiseTree(T->rc);
}

void preorderiterate(btptr T){
	stack<btptr> s;
	s.push(T);
	while(!s.empty()){
		T=s.top();
		s.pop();
		cout<<T->data ;
		if(T->rc!=NULL)s.push(T->rc);
		if(T->lc!=NULL)s.push(T->lc);
	}
}
void levelorderQ(btptr T){
	queue<btptr> q ;
	btptr hsh ;
	hsh=new(btnode);
	hsh->data='#';
	hsh->lc=hsh->rc=NULL;
	q.push(T);
	q.push(hsh);
	while(q.size()!=1){  //termination condition is when only one element # remains
		T=q.front();
		q.pop();
		 if(T->data=='#'){
			cout<<endl ;
			q.push(T) ;  }
		else{
			cout<<T->data ;
			if(T->lc!=NULL)q.push(T->lc);
			if(T->rc!=NULL)q.push(T->rc);
		}	
	}
}
int main(){
	btptr T ;
	T=NULL;
	char k ;
	cin>>k;
	insert(T,k);
	serialiseTree(T);
	preorderiterate(T);
	levelorderQ(T);
	return 0 ;
}
