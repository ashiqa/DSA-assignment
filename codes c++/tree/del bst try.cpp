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
void inorder(bstptr T , vector<int > &arr,int val ){
	if(T==NULL)return ;
	inorder(T->lc);
	if(T->data!=val)
	arr.push_back(T->data);
	inorder(T->rc);
}
void deleteNode(bstptr &T, int val){
	if(T==NULL)return ; 
	if(T->data==val){
		vector <int> arr ;
		inorder(T,arr,val);
	}
	if(T->data>val)deleteNode(T->lc,val);
	if(T->data<val)deleteNode(T->rc,val);
}
int main(){
	bstptr T ;
	T=NULL;
	int A[9]={5 , 3, 7 ,2 ,4, 6 ,9 ,1,8};
	int k ;
	while(k<9 ){
		insert(T,A[k]);
		++k;
	}
	cout<<"enter node to delete";
	cin>>val ;
	deleteNode(T,val);
	return 0 ; 
}
