#include<iostream>
using namespace std ;
struct lnode{
    int data ;
    struct lnode *next ;
};
typedef struct lnode *lptr ;
struct queue{
    lptr f =NULL;
    lptr r=NULL ;
};

void enqueue(struct queue Q[],int i,int x){
    lptr T ;
    T=new(lnode);
    T->data=x ;
    T->next=NULL;
    if(Q[i].r==NULL){
      Q[i].r=T ;
      Q[i].f=T;
    }
    else 
    {
        Q[i].r->next=T;
        Q[i].r=T;
    }
}
int dequeue(struct queue Q[],int i){
    int t ;
    if(Q[i].f==NULL)cout<<"empty";
    else if(Q[i].r==Q[i].f){
        Q[i].r=NULL;
        Q[i].f=NULL ;
    }
    else{
        t=Q[i].f->data;
        Q[i].f=Q[i].f->next ;
        return t ;
    }
}
int main(){
    int k=4 ;
    //cin>>k ;
    struct queue Q[k];
    enqueue(Q,0,1);
    enqueue(Q,2,2);
    enqueue(Q,1,5);
    enqueue(Q,2,5);
    enqueue(Q,0,8);
    enqueue(Q,1,14);
    enqueue(Q,0,11);
    enqueue(Q,3,12);
    enqueue(Q,2,7);
    enqueue(Q,2,16);
    enqueue(Q,3,4);
    enqueue(Q,1,18);
    enqueue(Q,3,99);
    int g=dequeue(Q,1);
    g=dequeue(Q,2);
    for(int i=0 ;i<k ;++i){
        while(Q[i].f!=NULL){
            cout<<Q[i].f->data<<" ";
            Q[i].f=Q[i].f->next ;
        }    
        cout<<endl;
    }
    return 0 ;
}

