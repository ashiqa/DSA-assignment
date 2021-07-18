#include<iostream>
#include<queue>
using namespace std ;
struct btnode{
	int data ;
	struct btnode *lc ;
	struct btnode *rc ;
};
typedef struct btnode * btptr ;
void levelorderQ(btptr T){
	queue<btptr> q ;
	btptr hsh ;
	hsh=new(btnode);
	hsh->data=-3;
	hsh->lc=hsh->rc=NULL;
	q.push(T);
	q.push(hsh);
	while(q.size()!=1){  //termination condition is when only one element # remains
		T=q.front();
		q.pop();
		 if(T->data==-3){
			cout<<endl ;
			q.push(T) ;  }
		else{
			cout<<T->data<<" " ;
			if(T->lc!=NULL)q.push(T->lc);
			if(T->rc!=NULL)q.push(T->rc);
		}	
	}
}
int main(){
	int x, num=1 ;  //change num
	cin>>x ;
	btptr T ;
	T=NULL ;
	T=new(btnode);
	T->data=1 ;
	T->lc=NULL ;
	T->rc=NULL ;
	queue<btptr> q ;
	q.push(T);
	btptr hsh ;
	hsh=new(btnode);
	hsh->data=-5 ;
	hsh->lc=NULL ;
	hsh->rc=NULL;
	int lvlcnt=0 ;
	q.push(hsh);
	while(q.size()!=1){  
		btptr tmp ;
		tmp=q.front();
		q.pop();
		if(tmp->data==-5){ //level counting by putting ptr -5 in Q
			++lvlcnt ;
		    q.push(tmp);
		}
		else if(lvlcnt<3){ //for insertion of normal tree from 1 to level 4
			tmp->lc=new(btnode);
			tmp->lc->data=++num ;
			tmp->lc->rc=NULL ;
			tmp->lc->lc=NULL;
			q.push(tmp->lc);
			tmp->rc=new(btnode);
			tmp->rc->data=++num ;
			tmp->rc->rc=NULL ;
			tmp->rc->lc=NULL;
			q.push(tmp->rc);
		}
		else if(q.size()==1)continue ; //skipping last element getting added  to -5
		else {    //condition for sum inverted tree
			btptr T2 ;
			T2=q.front();
			q.pop();
			int sum=tmp->data+T2->data ;
			btptr T3 ;
			T3=new(btnode);
			T3->data=sum ;
			T3->lc=NULL;
			T3->rc=NULL;
			tmp->rc=T3 ;
			q.push(T3);
		}		
	}
	levelorderQ(T);
	return 0 ;
}
