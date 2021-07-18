
#include<iostream>
using namespace std ;
struct node{
    int data ;
    struct node *next ;
};
typedef struct node * lptr ;

lptr insert(int stud){
    int n ,pass=2;
    lptr P,L ,T ;
    L=new(node);
    P=new(node);
    (L->data)=1;
    L->next=NULL ;
    P=L ;
    while(pass<=stud){
        T=new(node);
        T->data=pass ;
        T->next=NULL ;
        P->next=T ;
        P=T ;
        ++pass ;
    }
    P->next=L ;
    return L ;
}
int main(){
    int n ,cnt;
    lptr L,trav,duck,goose1,goose2 ;
    cin>>n ;
    L=insert(n);
    trav=L ;
    while(trav->data!=trav->next->data){
        cnt=1 ;
        while(cnt!=3){
            if(cnt==1){duck=trav ; trav=trav->next ; }
            else{
                duck->next=trav->next ;
                trav=duck->next ;
            }
            ++cnt ;  
        }
        goose2=trav ;
        duck->next=trav->next ;
        trav=duck->next ;
    }
    int x=trav->data ;
   cout<<x ;
    return 0 ;
}
