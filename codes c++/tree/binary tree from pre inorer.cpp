#include<iostream>
using namespace std ;
struct btnode{
	struct btnode *lc ;
	char data ;
	struct btnode *rc ;
};
typedef struct btnode *btptr ;

int find(char c,string ldr,int l,int h){
	int j;
	for(j=l;j<=h;j++)if(ldr[j]==c)return j;
}
void constructTree(btptr &T,string dlr,string ldr,int l,int h,int &i){
	if(l>h||i==dlr.length())return;
		T=new(btnode);
		T->data=dlr[i];
		T->lc=NULL;T->rc=NULL;
		int j=find(dlr[i],ldr,l,h);
		i++;
		constructTree(T->lc,dlr,ldr,l,j-1,i);
		constructTree(T->rc,dlr,ldr,j+1,h,i);
}
void inorder(btptr T){
	if(T==NULL){
	return ;
	}
	inorder(T->lc);
	cout<<(T->data);
	inorder(T->rc);
}
int main(){
	string ldr , dlr ; 
    int i=0;
	cin>>dlr ;
	cin>>ldr ;
	btptr T ;
	T=NULL ;
	constructTree(T,dlr,ldr,0,dlr.length()-1,i);
	inorder(T);
	return 0 ;
}
