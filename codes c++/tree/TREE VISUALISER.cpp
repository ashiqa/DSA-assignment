#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
struct btnode{
	struct btnode* lc ;
	char data ;
	int space ;
	struct btnode* rc;
};
typedef struct btnode* btptr ;
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
int i=0 ;
void inorderSpaceCalc(btptr &T){
	if(T==NULL)return ;
	inorderSpaceCalc(T->lc);
	T->space=(++i);
	inorderSpaceCalc(T->rc);
}
void levelOrder(btptr T){
	queue<btptr> q ;
	queue<char> q1 ;
	btptr nl,P ;char R;
	vector<int> prevSpc ;
	prevSpc.push_back(0);
	nl=new(btnode);
	nl->data='#';
	nl->space=0 ;
	nl->rc=NULL;
	nl->lc=NULL ;
	q.push(T);
	q.push(nl);
    while(q.size()!=1){
    	P=q.front();
 		q.pop();
		if(P->data == '#'){
		    int j=0 ;
			q.push(P)  ;
			cout<<endl ;
			while(!q1.empty()){
			    R=q1.front();
			    q1.pop();
			    j++ ;
			    for(int i=1 ; i<prevSpc[j]-prevSpc[j-1];++i)cout<<" "; cout<<R ;
			    R=q1.front();
			    q1.pop();
			    cout<<" "; cout<<R ; 
			}
			cout<<endl ;
			prevSpc.clear() ;
			prevSpc.push_back(0) ; }
		else{
			int gg=(P->space);
			for(int j=0 ; j<(gg-(prevSpc[prevSpc.size()-1]));++j)cout<<" ";
			cout<<(P->data);
			prevSpc.push_back(P->space) ;
			if(P->lc!=NULL){q.push(P->lc);q1.push('/');}
			else q1.push(' ');
			if(P->rc!=NULL){q.push(P->rc);q1.push('\\');}
			else q1.push(' ');
		}
	}
}
int main(){
	btptr T ;char k ; cin>>k ;
	insert(T,k);
	inorderSpaceCalc(T);
	levelOrder(T);
	return 0 ;
}
