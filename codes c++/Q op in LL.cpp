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
void dequeue(lptr &P){
	if(P->next==NULL)P=NULL ;
	else P=P->next ;
}
void enqueue(lptr P){
	if(P==NULL){
		cout<<"enter value for node ";
		cin>>P->data;
		P->next=NULL ;
	}
	else{ lptr end=P, T=new(node) ;
		while(end->next!=NULL){
			end=end->next ;
		}
		cout<<"enter value for node ";
		cin>>T->data;
		T->next=NULL ;
		end->next=T ;
	}
}
int main(){
	lptr L1 ;
	cout<<"enter linked list values till -1";
	L1=insert();
	char ch ;
	int opt ;
	do{
		cout<<"Choose 1 for enqueue and 2 for dequeue";
		cin>>opt ;
		if(opt==1){
			enqueue(L1);
			print(L1);
		}
		else {
			dequeue(L1); print(L1);
		}
		cout<<"do you want to continue? ";
		cin>>ch ;
	}while(ch=='y');	
	return 0 ;
}
