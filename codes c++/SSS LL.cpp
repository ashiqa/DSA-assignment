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
void addnode(lptr L2 , lptr &P){
    lptr T ;
    T=new(node);
    T->data=L2->data ;
    T->next=NULL ;
    P->next=T ;
    P=T ;
}
lptr unionf(lptr L1 , lptr L2){
    lptr L3,P ;
    L3=new(node);
    if(L1->data<L2->data){L3->data=L1->data ;L1=L1->next ;}
    else {L3->data=L2->data;L2=L2->next ;}
    L3->next=NULL ;
    P=new(node);
    P=L3 ;
    while(L1!=NULL || L2!=NULL){
        if(L1==NULL){
            while(L2!=NULL){
            addnode(L2,P);
              L2=L2->next ;
            }
        }
        else if(L2==NULL){
            while(L1!=NULL){
              addnode(L1,P);
              L1=L1->next ;
            }
        }
        else if(L1->data<L2->data){
            addnode(L1,P);
            L1=L1->next ;   }
        else if(L1->data>L2->data){ addnode(L2,P);
              L2=L2->next ; }
        else { addnode(L1,P);
        L1=L1->next ;
        L2=L2->next ;}
        
    }
    return L3 ;
}
int find(lptr P,int k){
    while(P!=NULL){
        if(k==P->data){return 1 ;}
        P=P->next;
    }
    return 0 ;
}
lptr intersection(lptr L1 ,lptr L2){
    lptr L3,P,T ;L3=NULL ;
    while(L1!=NULL){
        if(find(L2,L1->data)){
            if(L3==NULL){
                L3=new(node);
                L3->data=L1->data ;
                L3->next=NULL ;
                P=new(node);
                P=L3 ;
            }    
            else
            {  addnode(L1,P);
                }
        }
        L1=L1->next ;
    }
    return L3 ;
}
lptr diff(lptr L1 ,lptr L2){
  lptr L3,P,T ;L3=NULL ;
    while(L1!=NULL){
        if(find(L2,L1->data)==0){
            if(L3==NULL){
                L3=new(node);
                L3->data=L1->data ;
                L3->next=NULL ;
                P=new(node);
                P=L3 ;
            }    
            else
            {  addnode(L1,P);
                }
        }
        L1=L1->next ;
    }
    return L3 ;
}
lptr u_union(lptr L1 , lptr L2){
    lptr L3,P, T ;
    L3 = new(node);
    P=new(node);
    L3->data=L1->data ;
    L3->next=NULL ;
    P=L3 ;
    L1=L1->next ;
    while(L1!=NULL){
        addnode(L1,P);
        L1=L1->next ;
    }
    while(L2!=NULL){
        if(find(L3,L2->data)!=1){
           addnode(L2,P);
        }
        L2=L2->next ;
    }
    return L3 ;
}
int main(){
    lptr L1 ,L2,L3,L4 ;
    L1=insert();
    L2=insert();
    L3=unionf(L1,L2);
    print(L3);cout<<endl ;
    L3=intersection(L1,L2);
    print(L3);cout<<endl ;
    L3=diff(L1,L2);
    print(L3); cout<<endl ;
    L1=insert();
    L2=insert();
    L3=u_union(L1,L2);
    print(L3);cout<<endl;
    L3=intersection(L1,L2);
    print(L3);cout<<endl ;
    L3=diff(L1,L2);
    print(L3);cout<<endl ;
    return 0 ;
}



