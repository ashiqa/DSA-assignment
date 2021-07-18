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
    cout<<endl ;
}
void push(lptr &P ){
    int k ;
    cout<<"enter value to push : ";
    cin>>k ;
    lptr T ;
    T=new(node) ;
    T->data=k ;
    T->next=P ;
    P=T ;
}
void pop(lptr &P){
	if(P->next==NULL)P=NULL ;
	else P=P->next ;
}
int main(){
	lptr L1 ;
	cout<<"enter linked list values till -1";
	L1=insert();
	char ch ;
	int opt ;
	do{
		cout<<"Choose 1 for push and 2 for pop";
		cin>>opt ;
		if(opt==1){
			push(L1);
			print(L1);
		}
		else {
			pop(L1); print(L1);
		}
		cout<<"do you want to continue? ";
		cin>>ch ;
	}while(ch=='y');	
	return 0 ;
}
