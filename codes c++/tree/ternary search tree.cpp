#include<iostream>
using namespace std ;
struct tnode{
    int flag ;
    char data;
    struct tnode *lc;
    struct tnode *rc;
    struct tnode *eq;
};
typedef struct tnode *tptr ;
void insert(tptr &T,string s,int i){
    if(T==NULL){
        T=new(tnode);
        T->data=s[i];
        if(s.size()-1!=i)T->flag=0 ; 
        else T->flag=1;
        T->lc=NULL;
        T->rc=NULL;
        T->eq=NULL;
        if(T->flag!=1)insert(T->eq,s,++i);
        return ;
    }
    else{
        if(s[i]==T->data){
            if(i==s.size()-1)T->flag=1;
            else insert(T->eq,s,++i);
        }
        if(s[i]<T->data){
            insert(T->lc,s,i);
        }
        if(s[i]>T->data){
            insert(T->rc,s,i);
        }
    }
}
int traversal(tptr T,string ss,int i){
    if(T==NULL)return 0;
    if(ss[i]==T->data){
        if(i==ss.size()-1&&T->flag==1){
            return 1;
        }
        return traversal(T->eq,ss,++i);
    }
    else{
        if(ss[i]<T->data)return traversal(T->lc,ss,i);
        if(ss[i]>T->data)return traversal(T->rc,ss,i);
    }
}

int main(){
    tptr T ;
    T=NULL;
    insert(T,"indiana",0);
    insert(T,"india",0);
    insert(T,"jakarta",0);
    insert(T,"japan",0);
    int exists=traversal(T,"india",0);
    cout<<exists<<" ";
    exists=traversal(T,"jap",0);
    cout<<exists;
    return 0;
}


