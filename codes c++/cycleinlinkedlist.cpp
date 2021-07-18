#include<iostream>
using namespace std ;
struct node{
    int data ;
    struct node *next ;
};
typedef struct node * lptr ;
lptr store ;
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
        if(n==3)
            T->next=store ;
        else T->next=NULL ;
        P->next=T ;
        P=T ;
        if(n==2)
            store=P ;
       cin>>n ;
    }
    return L ;
}
void loop(lptr L1){
    lptr slow=L1 , fast=L1,prev=slow;
    while(slow!=NULL || fast!=NULL ){
        prev=slow ;
        slow=slow->next ;
        fast=fast->next->next ;
        if(slow->data==fast->data){
            cout<<1<<endl ;
            cout<<prev->data<<endl ;
            return ;
        }
    }
    cout<<0 ;
}
int main(){
    lptr L1 ;
    L1=insert();
    loop(L1);
    return 0 ;
}

