#include<bits/stdc++.h>
using namespace std ;
int m=3;
struct bdnode{
    int cnt ;
    int keys[2];
    struct bdnode *cptr[3];
};
struct ovnode{
    int cnt;
    int keys[3];
    struct bdnode *cptr[4];
};
typedef struct bdnode *bdptr ;
pair<bdptr,bdptr> search(bdptr B,int k,bdptr parent){
    for(int i=0;i<B->cnt ;++i){
        //less than key vals cptr[0] and cptr[1] covered
        if(k<B->keys[i]){
           if(B->cptr[i]==NULL)return {B,parent};
           else{
           return search(B->cptr[i],k,B);  }
        }
    }
        //greater than last key cptr[2] covered
        if(k>B->keys[B->cnt-1]){
            if(B->cptr[B->cnt]==NULL)return {B,parent};
            else
            return search(B->cptr[B->cnt],k,B);
            }
}
bool check4overflow(bdptr curr){
    if(curr->cnt==m-1)return true ;
    else return false ;
}
void fitting(bdptr &B,int k,bdptr &curr,bdptr left,bdptr right,bdptr &parent){
    bool ans=check4overflow(curr);
    /*START OF INSERT AND SORT*/
    if(!ans){  //no overflow : insert and sort 
        if(k>curr->keys[0]){ //k is greater than key so simply put in pos
            curr->keys[1]=k;
            curr->cnt=curr->cnt+1;
           // curr->cptr[]
        }
        
        else{//k is lesser so shift keys and insert
            curr->keys[1]=curr->keys[0];
            curr->keys[0]=k;
            curr->cnt=curr->cnt+1;
            curr->cptr[2]=curr->cptr[1]; //shifting of ptrs right
            curr->cptr[1]=curr->cptr[0];
            curr->cptr[1]=right;
            curr->cptr[0]=left;
        }
    }
    /*END OF INSERT AND SORT*/
    
    /*START  OF  NODE  SPLIT*/
    else if(ans){//overflow 
        struct ovnode *ovptr ;
        ovptr=new(ovnode);
        ovptr->cnt=3;
        for(int i=0;i<4;++i)ovptr->cptr[i]=NULL;
        
        if(k<curr->keys[0]){
            ovptr->keys[0]=k;
            for(int i=1;i<3;++i)ovptr->keys[i]=curr->keys[i-1];
            for(int i=1;i<4;++i)ovptr->cptr[i]=curr->cptr[i-1];
            ovptr->cptr[0]=left;
            ovptr->cptr[1]=right;
        }
        /*EDIT*/
        else if(k>curr->keys[1]){
            for(int i=0;i<2; ++i)ovptr->keys[i]=curr->keys[i];
            for(int i=0;i<3;++i)ovptr->cptr[i]=curr->cptr[i];
            ovptr->keys[2]=k;
            ovptr->cptr[3]=NULL;//wrong
        }
        else{//incomplete
            ovptr->keys[0]=curr->keys[0];
            ovptr->cptr[0]=curr->cptr[0];
            ovptr->keys[1]=k;
            ovptr->keys[2]=curr->keys[1];
        }
        /*EDIT*/
        //splitting  
        curr->cnt=1 ;
        curr->keys[0]=ovptr->keys[0]  ;
        curr->keys[1]=0 ;
        for(int i=0;i<m;++i)curr->cptr[i]=NULL;
        curr->cptr[0]=ovptr->cptr[0];
        curr->cptr[1]=ovptr->cptr[1];
        bdptr newn;
        newn=new(bdnode);
        newn->cnt=1;
        newn->keys[0]=ovptr->keys[2];
        for(int i=0;i<m;++i)newn->cptr[i]=NULL;
        newn->cptr[0]=ovptr->cptr[2];
        newn->cptr[1]=ovptr->cptr[3];
        //adding middle elem to parent
        if(curr==B){ //if its root then create new node
            bdptr tmp ;
            tmp=new(bdnode);
            tmp->cnt=1; 
            tmp->keys[0]=ovptr->keys[1];
            for(int i=0;i<m;++i)tmp->cptr[i]=NULL;
            tmp->cptr[0]=curr;
            tmp->cptr[1]=newn;
            B=tmp;
            parent=B;
        }
    
        else{ // else  add to immediate parent
            
            fitting(B,ovptr->keys[1],parent,curr,newn,B);
        }
    }
    /*END OF NODE SPLIT*/
}
void Add(bdptr &B,int k){
    if(B==NULL){
        B=new(bdnode);
        B->cnt=1;
        B->keys[0]=k;
        for(int i=0;i<m;++i)B->cptr[i]=NULL;
        return ;
    }
    bdptr curr,parent=B;
    pair<bdptr , bdptr> p =search(B,k,parent); //search for correct pos of value
    curr=p.first;
    parent=p.second;
    fitting(B,k,curr,NULL,NULL,parent);
}
void inorder(bdptr B){
    if(B==NULL)return ;
    for(int i=0;i<B->cnt;++i){
        inorder(B->cptr[i]);
        cout<<B->keys[i]<<" " ;
    }
    inorder(B->cptr[B->cnt]);
}
int main(){
    bdptr B ;
    B=NULL ;
    int i=10;
    while(i!=0){
    Add(B,i);
    --i;
    }
    inorder(B);
    return 0 ;
}

