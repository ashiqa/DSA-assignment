#include<iostream>
using namespace std ;
struct node{
	int val ;
	int cnt ;
	struct node * next[3];
};
struct nnode{
	int val ;
	struct nnode * nex ;
};
typedef struct node* mlptr ;
struct stack {
	int size ;
	int top ;
	mlptr element[50];
};
void push(struct stack &S , mlptr x ){
	if(S.top==S.size-1)
		cout<<"stack full";
	else
		S.element[++S.top]=x ;
}
mlptr  pop(struct stack &S){
	if(S.top==-1)
		cout<<"stack empty";
	else
		return(S.element[S.top--] );
}
void mll_insertsearch(mlptr prev, struct stack &S,int v[],int c[],int s,int t){
	int i=0 ;
	while(S.top!=-1){
		prev=S.element[S.top];
	while(prev->cnt!=0){
		mlptr T ;
		T=new(node);
	 T->val=v[i] ;
	 T->cnt=c[i] ;
	 i++ ;
	 T->next[0]=NULL ;T->next[1]=NULL ;T->next[2]=NULL ;
	 
	 prev->next[prev->cnt-1]=T ;
	 prev=T ;
	 push(S,prev);
	}
	int siz=S.top,siz2,op[18];
	int siz1=siz ;
	
	mlptr pp=pop(S);
    if(pp->val==t){
    	op[siz]=pp->val ;
    	while(S.top!=-1){
    		pp=pop(S);
    		op[--siz]=pp->val ; 
    		
    		if(pp->val==s){
    			cout<<pp->val<<" ";
    			siz2=siz+1 ;
    			break ;
			}
	}  
	for(int i=siz2 ; i<=siz1;++i)cout<<op[i]<<" ";
	cout<<endl;
	}
	else{
		while((--S.element[S.top]->cnt)==0){
		pp=pop(S);
		}	
}	}
}

int main(){
	int x ,y ;
	struct stack S,S1 ;
	S.size=50 ;
	S.top=-1 ;
	mlptr ML ;
	ML=new(node);
	cin>>x ;
	ML->val=x ;
	cin>>y;
	ML->cnt=y ;
	ML->next[0]=NULL ;	ML->next[1]=NULL ;	ML->next[2]=NULL ;
	push(S,ML) ;
	int c[34],v[34],s,t,s1,t1 ;
	for(int i=0 ; i <16 ;i++){
		cin>>v[i];
		cin>>c[i];
	}
	cin>>s>>t ;
	cin>>s1>>t1 ;
	mll_insertsearch(ML,S,v,c,s,t);
		AL=new(node);
		AL->val=x ;
		AL->cnt=y ;
		AL->next[0]=NULL ;	AL->next[1]=NULL ;	AL->next[2]=NULL ;
		S1.top=-1;
		S1.size=-1 ;
		push(S1,AL);
		mll_insertsearch(AL,S1,v,c,s1,t1);	
	return 0 ;
}
