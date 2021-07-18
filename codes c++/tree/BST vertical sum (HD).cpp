#include<bits/stdc++.h>
using namespace std ;
struct bstnode{
	struct bstnode* lc ;
	int data ;
	struct bstnode* rc ;
};
typedef struct bstnode* bstptr ;
void insert(bstptr &T,int k){
	if(T==NULL){
		T=new(bstnode);
		T->lc=NULL;
		T->rc=NULL;
		T->data=k ;
		return ;
	}
	else{
		if(k<T->data)
		insert(T->lc,k);
		else
		insert(T->rc,k);
	}	
}
void verticalSum(bstptr T,int hd,map<int,int> &vsum){
	if(T==NULL)return ;
	vsum[hd]+=T->data;
	verticalSum(T->lc,hd-1,vsum);
	verticalSum(T->rc,hd+1,vsum);
}
int main(){
	bstptr T ;
	T=NULL;
	int k ; 
	map< int, int > vsum;
	map< int, int > :: iterator it;
	cin>>k;
	while(k!=0 ){
		insert(T,k);
		cin>>k ;
	}
	verticalSum(T,0,vsum);
    for (it = vsum.begin(); it != vsum.end(); ++it) 
    {   cout << it->first<<" "<< it->second << endl; 
    } 
	return 0 ;
}

