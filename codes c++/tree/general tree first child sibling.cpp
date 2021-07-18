#include<iostream>
#include <bits/stdc++.h>
using namespace std ;
struct gtnode{
	struct gtnode *fc ;
	char data ;
	struct gtnode *sb ;
};
typedef struct gtnode *gtptr ;

void insert(gtptr &T,char k){
	if(T==NULL){
		T=new(gtnode);
		T->data=k ;
		T->fc=NULL;
		T->sb=NULL ;
	}
	char ch ;
	cin>>ch ;
	if(ch!='.')insert(T->fc,ch);
	cin>>ch;
	if(ch!='.')insert(T->sb,ch);
}
void print(vector<vector<char> >res){
	for(int i=0 ; i<res.size();++i){
		for(int j=0 ; j<res[i].size();++j){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl ;
}
void levelorder(gtptr T,int level,vector<vector<char> > &res){
	if(T==NULL)return ;
	if(res.size()==level)
	res.push_back({});
	res[level].push_back(T->data);
	levelorder(T->fc,level+1,res);
	levelorder(T->sb,level+1,res);
}
int main(){
    char cha;
    gtptr GT;
    GT=NULL ;
    cin>>cha;
    insert(GT,cha);
    vector<vector<char>> res ;
    levelorder(GT,0,res);
	print(res);
    return 0 ;
}
