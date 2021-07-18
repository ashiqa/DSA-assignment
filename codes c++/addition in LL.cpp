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

void add(lptr L1 , lptr L2 , lptr &L3, int &carry, int &call){
    int sum  ;
    if(L1==NULL)return ;
    ++call ;
    add(L1->next,L2->next,L3,carry,call);
    --call ;
    
    sum=(L1->data)+(L2->data)+carry ;
    if(L3==NULL){
      L3->data=sum%10 ;
      L3->next=NULL ;
    }
    else if(call!=1){lptr T ;
    T=new(node) ;
    T->data=sum%10 ;
    T->next=L3 ;
    L3=T ; }
    else{
    lptr T ;
    T=new(node) ;
    T->data=sum%10 ;
    T->next=L3 ;
    L3=T ;
	lptr G ;
    G=new(node) ;
    G->data=sum/10 ;
    G->next=L3 ;
    L3=G ;	}
    carry=sum/10 ;
}
int main(){
    lptr L1 , L2,L3 ;
    L3=new(node);
    int carry=0, call=1  ;
    L1=insert();
    L2=insert();
    add(L1,L2,L3 ,carry, call  );
    print(L3);
    return 0 ;
}

