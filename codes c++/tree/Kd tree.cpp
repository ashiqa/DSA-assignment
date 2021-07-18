#include<iostream>
#include<vector>
using namespace std ;
struct bstnode{
	struct bstnode *lchild ;
	int data[3] ;
	struct bstnode *rchild ;
};
typedef struct bstnode *bstptr ;
void insert(bstptr &T ,int k[3],int i){
	if(T==NULL){
		T=new(bstnode);
		T->lchild=NULL;
		for(int j=0 ; j<3 ;++j)T->data[j]=k[j] ;
		T->rchild=NULL ;
		return ;	
	}
	else{
		if(k[i]<T->data[i])
		insert(T->lchild,k,++i);
		else
		insert(T->rchild,k,++i);
	}
}
void preorder(bstptr T){
	if(T==NULL)return ;
	for(int l=0 ; l<3;++l)cout<<(T->data[l])<<" " ; 
	cout<<endl;
	preorder(T->lchild);
	preorder(T->rchild);
}
int main(){
	bstptr T ;
	T=NULL ;
	int k[3] ;
	for(int h=0; h<3;++h)cin>>k[h];
	while(k[0]!=-1 ){
		insert(T,k,0);
		for(int h=0; h<3;++h)cin>>k[h];
	} 
	preorder(T);
	return 0 ;
}
