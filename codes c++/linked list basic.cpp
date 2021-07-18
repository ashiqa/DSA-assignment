#include<iostream>
#include<bits/stdc++.h> 
using namespace std ;
struct node{
    int data ;
    struct node *next ;
};
typedef struct node *lptr ;
void print (lptr P){
    while(P!=NULL){
        cout<<P->data<<" ";
        P=P->next ;
    }
}
void printrev(lptr P){
    if(P==NULL)return ;
    printrev(P->next);
    cout<<P->data<<" ";
}
void countnodes(lptr P){
    int cnt=0 ;
    while(P!=NULL){
        ++cnt ;
        P=P->next ;
    }
    cout<<cnt ;
}
void minval(lptr P){
    int minn=INT_MAX;
    while(P!=NULL){
        if(P->data<minn)minn=P->data ;
        P=P->next ;
    }
    cout<<minn ;
}
void maxval(lptr P){
    int maxx=INT_MIN;
    while(P!=NULL){
        if(P->data>maxx)maxx=P->data ;
        P=P->next ;
    }
    cout<<maxx ;
}
void midval(lptr P){
    lptr SP,FP ;SP=P ;FP=P ;
    while(FP->next!=NULL){
        FP=FP->next ;
        FP=FP->next ;
        SP=SP->next ;
    }
    cout<<SP->data ;
}
void countodd(lptr P){
    int cnt=0 ;
    while(P!=NULL){
       if(P->data%2==1)++cnt ;
       P=P->next ;
    }
    cout<<cnt ;
}
void counteven(lptr P){
    int cnt=0 ;
    while(P!=NULL){
       if(P->data%2==0)++cnt ;
       P=P->next ;
    }
    cout<<cnt ;
}
void find(lptr P){
    int f=0,k ;
    cin>>k ;
    while(P!=NULL){
        if(k==P->data){cout<<1 ;f=1 ;}
        P=P->next;
    }
    if(f==0)
    cout<<0 ;
}
int main(){
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
    print(L);
    cout<<endl ;
    printrev(L);
    cout<<endl ;
    countnodes(L);
    cout<<endl ;
    minval(L);
    cout<<endl ;
    maxval(L);
    cout<<endl ; 
    midval(L);
    cout<<endl ;
    countodd(L);
    cout<<endl ;
    counteven(L);
    cout<<endl ;
    find(L);
    cout<<endl ;
    return 0 ;
}



