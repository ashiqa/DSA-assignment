//The path to success is to take massive, determined action.
#include<iostream>
#include<vector>
using namespace std ;
struct bstnode{
	struct bstnode *lchild ;
	int data ;
	struct bstnode *rchild ;
};
typedef struct bstnode *bstptr ;
void insert(bstptr &T ,int k){
	if(T==NULL){
		T=new(bstnode);
		T->lchild=NULL;
		T->data=k ;
		T->rchild=NULL ;
		return ;	
	}
	else{
		if(k<T->data)
		insert(T->lchild,k);
		else
		insert(T->rchild,k);
	}
}
void allRootToLeaf(bstptr T,vector<int> res){
    if(T==NULL)return ;
    if(T->rchild==NULL&&T->lchild==NULL){
        res.push_back(T->data);
        for(int i=0 ; i<res.size();++i)
        cout<<res[i]<<" "; cout<<endl ;
        return ;
    }
    res.push_back(T->data);
    allRootToLeaf(T->lchild,res);
    allRootToLeaf(T->rchild,res);
    res.pop_back();
}
void leftPath(bstptr T){
    if(T==NULL){cout<<endl;return ;}
    cout<<T->data<<" ";
    leftPath(T->lchild);
}
void rightPath(bstptr T){
    if(T==NULL){cout<<endl;return ;}
    cout<<T->data<<" ";
    rightPath(T->rchild);
}
void maxSumPath(bstptr T ,vector<int>curr,vector<int>&res, int currsum , int &maxsum){
    if(T==NULL)return ;
    if(T->rchild==NULL&&T->lchild==NULL){
        curr.push_back(T->data);
        currsum+=T->data ;
     if (currsum>maxsum){
         maxsum=currsum ;
         res=curr ;
     }
     return ;
    }
    currsum+=T->data ;
     curr.push_back(T->data);               
    maxSumPath(T->lchild,curr,res,currsum,maxsum);
    maxSumPath(T->rchild,curr,res,currsum,maxsum);
    curr.pop_back();
    currsum-=T->data ;
}
void minSumPath(bstptr T ,vector<int>curr,vector<int>&res, int currsum , int &minsum){
    if(T==NULL)return ;
    if(T->rchild==NULL&&T->lchild==NULL){
        curr.push_back(T->data);
        currsum+=T->data ;
     if (currsum<minsum){
         minsum=currsum ;
         res=curr ;
     }
     return ;
    }
    currsum+=T->data ;
     curr.push_back(T->data);               
    minSumPath(T->lchild,curr,res,currsum,minsum);
    minSumPath(T->rchild,curr,res,currsum,minsum);
    curr.pop_back();
    currsum-=T->data ;
}
void print(vector<int>res){
    for(int i=0 ; i<res.size();++i)cout<<res[i]<<" ";
    cout<<endl ;
}
int main(){
    bstptr T ;
    T=NULL ;
	int k ; 
	vector<int> res ;
	vector<int>curr;
	cin>>k;
	while(k!=-1 ){
		insert(T,k);
		cin>>k ;
	}
	allRootToLeaf(T,res);
	leftPath(T);
	rightPath(T);
	res.clear();
	int maxsum=0,minsum=9999 ;
	maxSumPath(T,curr ,res,0,maxsum);
	print(res);
	res.clear(); curr.clear();
	minSumPath(T,curr ,res,0,minsum);
	print(res);
	res.clear();
	return 0 ;
}
