#include<iostream>
#include <bits/stdc++.h>
using namespace std ;
struct gtnode{
	char data ;
	struct gtnode * c[10] ;
};
typedef struct gtnode *gtptr ;

void insert(gtptr &T,char k){
	if(T==NULL){
		T=new(gtnode);
		T->data=k ;
		for(int i=0 ; i<10;++i)T->c[i]=NULL;
	}
	char ch ;
	for(int i=0;ch!='.';++i){
	cin>>ch ;
	if(ch!='.')insert(T->c[i],ch);
	}
}
void preorder(gtptr T){
    if(T==NULL)return ;
    cout<<T->data ;
    for(int i=0;i<10;++i)
    preorder(T->c[i]);
}
int main(){
    char cha;
    gtptr GT;
    GT=NULL ;
    cin>>cha;
    insert(GT,cha);
    preorder(GT);
    return 0 ;
}
