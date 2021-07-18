#include<bits/stdc++.h>
using namespace std;
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
void bottomview(bstptr T ,int level , int hd , map <int,pair<int,int > > &res){
	if(T==NULL)return ;
	if(res.find(hd)==res.end())
	{	res[hd].first=T->data ;
		res[hd].second=level ;
	}
	else{
		if(level>=res[hd].second){
			res[hd].first=T->data ;
			res[hd].second=level ;	
		}
	}
	bottomview(T->lc,level+1,hd-1,res);
	bottomview(T->rc,level+1,hd+1,res);
}
int main(){
	bstptr T ;
	T=NULL;
	map< int, pair<int,int> > res ;
	map< int, pair<int,int> > :: iterator it ;
	int A[9]={5 , 3, 7 ,2 ,4, 6 ,9 ,1,8};
	int k=0;
	while(k<9 ){
		insert(T,A[k]);
		++k;
	}
	bottomview(T,0,0,res);
	for(it=res.begin();it!=res.end();++it)cout<<(it->second).first<<" " ;
	return 0 ;
}
