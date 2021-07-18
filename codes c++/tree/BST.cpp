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
void inorder(bstptr T){
	if(T==NULL)return ; 
	inorder(T->lchild);
	cout<<(T->data)<<" " ;
	inorder(T->rchild);
}
void preorder(bstptr T){
	if(T==NULL)return ;
	cout<<(T->data)<<" " ; 
	preorder(T->lchild);
	preorder(T->rchild);
}
void postorder(bstptr T){
	if(T==NULL)return ;
	postorder(T->lchild);
	postorder(T->rchild);
	cout<<(T->data)<<" " ; 
}
void levelorder(bstptr T,int level,vector<vector<int> > &res){
	if(T==NULL)return ;
	if(res.size()==level)
	res.push_back({});
	res[level].push_back(T->data);
	levelorder(T->lchild,level+1,res);
	levelorder(T->rchild,level+1,res);
}
void revrevlevorder(bstptr T ){
	vector<vector<int> >resrev;
	levelorder(T,0,resrev);
	for(int i=resrev.size()-1;i>=0;--i){
		for(int j=resrev[i].size()-1;j>=0;--j){
			cout<<resrev[i][j]<<" ";
		}
	}
	cout<<endl ;
}
void revlevorder(bstptr T ){
	vector<vector<int> >resrev;
	levelorder(T,0,resrev);
	for(int i=resrev.size()-1;i>=0;--i){
		for(int j=0;j<resrev[i].size();++j){
			cout<<resrev[i][j]<<" ";
		}
	}
		cout<<endl ;
}
void squirrelclock(bstptr T,int level,vector<vector<int> > &res){
	if(T==NULL)return ;
	if(res.size()==level)
	res.push_back({});
	if(level%2==0)
	res[level].push_back(T->data);
	else res[level].insert(res[level].begin(),T->data);
	squirrelclock(T->lchild,level+1,res);
	squirrelclock(T->rchild,level+1,res); 
}
void squirrelanticlock(bstptr T,int level,vector<vector<int> > &res){
	if(T==NULL)return ;
	if(res.size()==level)
	res.push_back({});
	if(level%2==1)
	res[level].push_back(T->data);
	else res[level].insert(res[level].begin(),T->data);
	squirrelanticlock(T->lchild,level+1,res);
	squirrelanticlock(T->rchild,level+1,res); 
}
void print(vector<vector<int> >res){
	for(int i=0 ; i<res.size();++i){
		for(int j=0 ; j<res[i].size();++j){
			cout<<res[i][j]<<" ";
		}
	}
	cout<<endl ;
}
int main(){
	bstptr T ;
	T=NULL ;
	int k ; 
	vector<vector<int> > res ;
	cin>>k;
	while(k!=-1 ){
		insert(T,k);
		cin>>k ;
	}
	//inorder(T);
	levelorder(T,0,res);
	//printing for levelorder
	print(res);
	revrevlevorder(T);
	res.clear();
	squirrelclock(T,0,res);
	print(res);
	res.clear();
	squirrelanticlock(T,0,res);
	print(res);
	res.clear();
	squirrelclock(T,0,res);
	print(res);
	res.clear();
	squirrelanticlock(T,0,res);
	print(res);
	return 0 ;
}
