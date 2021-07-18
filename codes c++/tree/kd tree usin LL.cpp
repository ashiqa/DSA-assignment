#include<iostream>
using namespace std ;
struct lnode{
    int data ;
    struct lnode *next ;
};
typedef struct lnode* lptr ;
struct bstnode{
    struct bstnode *lc ;
    lptr data=NULL ;
    struct bstnode *rc ;
};
typedef bstnode *bstptr ;
void insert(bstptr &T, int k[],int d,int i){
    if(T==NULL){
        T=new(bstnode);
        T->lc=NULL;
        T->rc=NULL;
        bstptr root ;
        root =T ;
        rootLP=T->data ;
        for(int j=0;j<d;++j){
            lptr tmp=new(lnode);
            tmp->data=k[j];
            tmp->next=NULL;
            if(T->data==NULL){
                T->data=tmp ;
            }
            else{
                T->data->next=tmp ;
                T->data=tmp ;
            }
        }
        T=root ;
        T->data=rootLP ;
    }
    else{
        int x,h=0;
        bstptr P ;P=T;
        while(h<i){
            P->data=P->data->next ;
            ++h ;
        }
        x=P->data->data ;
        if(k[i]<x){
            insert(T->lc,k,d,++i);
        }
        else{
            insert(T->rc,k,d,++i);
        }
    }
}
void inorder(bstptr T){
    if(T==NULL)return ;
    inorder(T->lc);
    while(T->data!=NULL){
        cout<<T->data->data<<" " ;
        T->data=T->data->next ;
    }
    cout<<endl;
    inorder(T->rc);
}
int main(){
    bstptr T=NULL ;
    int k[5],d;
    cin>>d ;
    while(1){
        for(int i=0 ; i<d;++i){
            cin>>k[i] ;
            if(k[0]==-1)break ;
        }
         if(k[0]==-1)break ;
        insert(T,k,d,0);
    }
    inorder(T);
    return 0 ;
}
