#include<iostream>
using namespace std ;
struct node{
    int data ;
    struct node *next ;
};
typedef struct node * lptr ;
lptr P; 
lptr insert(){
    int n ;
    lptr L ,T ;
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
    P->next=L ;
    return L ;
}
void print (lptr P, lptr Q){
    while(P!=Q){
        cout<<P->data<<" ";
        P=P->next ;
    }
    cout<<Q->data ;
    cout<<endl;
}
int main(){
    lptr L,head,J,I,prev ;
    L=insert();
    head=L;
    int visited[10]={0};
    while(head!=P){
        int x=head->data ;
       if(visited[x]==0)visited[x]++ ;
       else 
            continue ;
       I=head ;
       J=head->next ;
        prev=head->next ;
    while(prev!=head){   
       
    while(J->data!=I->data){
       J=J->next ;
    }
    if(I!=J){
        print(I,J);
    }
    I=J ;
    prev=J ;
    J=J->next ; }
    head=head->next ;
    }
    return 0 ;
}
