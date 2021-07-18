#include<iostream>
using namespace std ;
struct node{
    int data ;
    struct node *next ;
};
typedef struct node * lptr ;
lptr insert(){
    int n ;
    lptr L ,T,P ;
    L=new(node);
    P=new(node);
    cin>>(L->data);
    L->next=NULL ;
    P=L ;
    cin>>n ;
    while(n>=0){
        T=new(node);
        T->data=n ;
        T->next=NULL ;
        P->next=T ;
        P=T ;
       cin>>n ;
    }
    return L ;
}
void print (lptr P){
    while(P!=NULL){
        cout<<P->data<<" ";
        P=P->next ;
    }
}
bool condition(int count,lptr AP, lptr end){
	if(count%2==0){
	 if(AP->next!=end)return true ;
	 else return false ; }
	 else{
	  if(AP!=end)return true ;
	 else return false ;   
	 }
}
int main(){
	lptr L1 ;
	int count=1;
	L1=insert();
	lptr AP=L1,end=L1,prev ;
	while(end->next!=NULL){
	    ++count ;
	    prev=end ;
		end=end->next ;
	}
	
	while(condition(count,AP,end)){
		end->next=AP->next ;
		AP->next=end ;
		prev->next=NULL;
		AP=AP->next->next ;
		end=L1 ;
		while(end->next!=NULL){prev=end ;end=end->next ;}
	 } 
	 print(L1);
    return 0 ;
}

