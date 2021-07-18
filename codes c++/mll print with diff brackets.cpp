#include<iostream>
using namespace std ;
struct node{
	int tag ;
	union{
		char c;
		struct node* dlink ;
	}data;
	struct node* next ;
};
typedef struct node* mllptr ;
char ch ;
char arr[][2]={{'{','}'},
         {'[',']'},
		 {'(',')'},
		 {'<','>'}
};

void MLLinsert(mllptr prev,int i){
	mllptr T ;
	T=new(node);
	cin>>ch ;
	if(ch=='#')return ;
	if(ch=='}'){
		return ;
	}
	else if(ch>='A'&&ch<='Z'){
		T->tag=1 ;
		T->data.c=ch ;
		T->next=NULL;
	}
	else if(ch=='{'){
		T->tag=1 ;  	//tag 1 for A-Z and {
		T->data.c=arr[++i][0] ;
		T->next=NULL ;   //if prev is { then start sub list 
		prev->next=T ;
		prev=T ;
		T=new(node);
		T->tag=2 ;       //tag2 for ptr to node
		mllptr S;
		S=new(node);
		MLLinsert(S,i);
		T->data.dlink=S ;
		T->next=NULL;
		prev->next=T;
		prev=T;
		T=new(node);
		T->tag=1 ;
		T->data.c=arr[i][1];
		T->next=NULL;
	}
	
	if(prev!=NULL){
		prev->next=T;
	}
	 prev=T ;
	MLLinsert(prev,i);
}
void print(mllptr P){
	if(P==NULL)return ;
	if(P->tag==1){
		cout<<P->data.c<<" " ;	
	}
	else {
		print(P->data.dlink->next);
	}
	print(P->next);
}
int main(){
	mllptr ML ;
	ML=new(node);
	MLLinsert(ML,-1);
	print(ML->next);
	return 0 ;
}
