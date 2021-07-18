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
void width(bstptr T , int level , int hd ,vector<vector<int> > &res){
	if(T==NULL)return ;
	if(res.size()==level){
		res.push_back({ });
	}
	res[level].push_back(hd);
	width(T->lc,level+1,hd-1,res);
	width(T->rc,level+1,hd+1,res);
}
int main(){
	bstptr T ;
	T=NULL;
	int A[9]={5 , 3, 7 ,2 ,4, 6 ,9 ,1,8};
	vector<vector<int> > res ;
	int k=0,maxwidth=0 ,lvlwidth, minHD=999 ,maxHD=-99; 
	while(k<9 ){
		insert(T,A[k]);
		++k;
	}
	width(T,0,0,res);
	for(int i=0 ; i<res.size();++i){
		lvlwidth=0,minHD=0,maxHD=0 ;
		for(int j=0 ; j<res[i].size();++j){
			minHD=min(minHD,res[i][j]);
			maxHD=max(maxHD,res[i][j]);
		}
		lvlwidth=maxHD-minHD ;
		cout<<"level : "<<i<<endl ;
		cout<<"min HD "<<minHD<<endl;
		cout<<"maxHD "<<maxHD<<endl;
		cout<<"curr width of lvl "<<lvlwidth<<endl ;
		maxwidth=max(maxwidth,lvlwidth);
	}
	cout<<maxwidth ;
	return 0 ;
}
