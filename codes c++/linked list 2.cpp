#include<iostream>
using namespace std ;
struct node{
    int data ;
    struct node *next ;
};
typedef struct node * lptr ;
void print (lptr P){
    while(P!=NULL){
        cout<<P->data<<" ";
        P=P->next ;
    }
}
void addfront(lptr &P ){
    int k ;
    cin>>k ;
    lptr T ;
    T=new(node) ;
    T->data=k ;
    T->next=P ;
    P=T ;
}
void addbefore(lptr P){
    int x ,y ;
    lptr T;
    cin>>x>>y ;
    if(P->data==y)addfront(P);
    while(P!=NULL){
        if((P->next)->data==y){
            T=new(node);
            T->data=x ;
            T->next=P->next ;
            P->next=T;
            break ;
        }
        else P=P->next ;
    }
}
void addafter(lptr P){
    int x ,y ;
    lptr T;
    cin>>x>>y ;
    while(P!=NULL){
        if(P->data==y){
            T=new(node);
            T->data=x ;
            T->next=P->next ;
            P->next=T;
            break ;
        }
        else P=P->next ;
    }
}
void deletek(lptr &L, int k){
    lptr P;
    P=L ;
    if(P->data==k)L=L->next ;
    while(P!=NULL){
        if(P->next->data==k){
            P->next=P->next->next ;
            break ;
        }
        P=P->next;
    }
}
int deletemin(lptr P){
    int minn=100000 ;
    while(P!=NULL){
        if(P->data<minn)minn=P->data ;
        P=P->next ;
    }
    return(minn);
}
int deletemax(lptr P){
 int maxx=0 ;
 while(P!=NULL){
     if(P->data>maxx)maxx=P->data ;
     P=P->next ;
 }
 return(maxx);
}
int main(){
    lptr L,P,T ;
    int n ;
    L=new(node);
    cin>>n ;
    L->data=n ;
    L->next=NULL;
    P=new(node);
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
    print(L);
    cout<<endl ;
    addfront(L);
    print(L);
    cout<<endl ;
    addbefore(L);
    print(L);
    cout<<endl ;
    addafter(L);
    print(L);
    cout<<endl ;
    int k ;
    cin>>k ;
    deletek(L,k);
    print(L);
    cout<<endl ;
    k=deletemin(L);
    deletek(L,k);
    print(L);
    cout<<endl ;
    k=deletemax(L);
    deletek(L,k);
    print(L);
    cout<<endl ;
    return 0 ;
}


