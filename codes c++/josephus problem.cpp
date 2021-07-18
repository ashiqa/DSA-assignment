#include<iostream>
using namespace std ;
struct node{
    int data ;
    struct node *next ;
};
typedef struct node * lptr ;

lptr insert(int men){
    int n ,pass=1;
    lptr P,L ,T ;
    L=new(node);
    P=new(node);
    cin>>(L->data);
    L->next=NULL ;
    P=L ;
    while(pass<men){
        cin>>n ;
        T=new(node);
        T->data=n ;
        T->next=NULL ;
        P->next=T ;
        P=T ;
        ++pass ;
    }
    P->next=L ;
    return L ;
}
int main(){
    int n ,m ,cnt;
    lptr L,trav,prev ;
    cin>>n ;
    L=insert(n);
    cin>>m ;
    trav=L ;
    while(trav->data!=trav->next->data){
        cnt=1 ;
        while(cnt!=m){
            prev=trav ;
            trav=trav->next ;
            ++cnt ;  
        }
        lptr T=trav->next ;
        int x=trav->data;
        cout<<x<<" " ;
        prev->next=trav->next ;
        trav=T ;
    }
   
    return 0 ;
}
