// Celebration  of Life is
// Distribution of Love
#include<bits/stdc++.h>
using namespace std ;
int m=3;
struct bdnode{
    int cnt ;
    int keys[2];
    struct bdnode *cptr[3];
    struct bdnode *next ;
    struct bdnode *prev;
};
struct ovnode{
    int cnt;
    int keys[3];
    struct bdnode *cptr[4];
};
typedef struct bdnode *bdptr;
void levorderlink(bdptr B, int level,vector<vector<bdptr>>&res){
    if(B==NULL)return ;
    if(res.size()==level){
        res.push_back({});
    }
    res[level].push_back(B);
    for(int i=0;i<m;++i){
        levorderlink(B->cptr[i],level+1,res);
    }
}
pair<bdptr,bdptr> search(bdptr B,int k,bdptr parent){
    for(int i=0;i<B->cnt ;++i){
        //less than key vals; cptr[0...cnt-1] covered
        if(k<B->keys[i]){
           if(B->cptr[i]==NULL)return {B,parent};
           else{
           return search(B->cptr[i],k,B);  }
        }
    }
        //greater than last key; cptr[cnt] covered
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
    /*NO OVERFLOW : START OF INSERT AND SORT*/
    if(!ans){  
        if(k>curr->keys[curr->cnt-1]){ //k is greater than LAST key simply put in pos
            curr->keys[curr->cnt]=k;
            if(left!=NULL)curr->cptr[curr->cnt]=left;
            curr->cptr[curr->cnt+1]=right;
            curr->cnt=curr->cnt+1;
        }  
        else{//k is lesser so shift keys and insert
        int pos;
         for(int i=curr->cnt-1;i>=0;--i){
            if(k<curr->keys[i])
                pos=i;
        }
        curr->cnt=curr->cnt+1;
            for(int i=curr->cnt-1;i!=pos;--i){
                curr->keys[i]=curr->keys[i-1]; 
                curr->cptr[i+1]=curr->cptr[i]; 
            }
            curr->keys[pos]=k;
            curr->cptr[pos+1]=right;
            curr->cptr[pos]=left;
        }
    }
    /*END OF INSERT AND SORT*/
    
    /*START  OF  NODE  SPLIT : OVERFLOW*/
    else if(ans){ 
    int pos ;
    
        struct ovnode *ovptr ;
        ovptr=new(ovnode);
        ovptr->cnt=m;
        for(int i=0;i<(m+1);++i)ovptr->cptr[i]=NULL;
        
        for(int i=curr->cnt-1;i!=-1;--i){
            if(k<curr->keys[i])pos=i;
        }
        if(k>curr->keys[curr->cnt-1])pos=curr->cnt ;
        for(int i=0;i<pos;++i){
            ovptr->keys[i]=curr->keys[i];
            ovptr->cptr[i]=curr->cptr[i];
        }
        ovptr->cptr[pos]=curr->cptr[pos];
        for(int i=m-1;i!=pos;--i){
            ovptr->keys[i]=curr->keys[i-1];
            ovptr->cptr[i]=curr->cptr[i-1];
        }
        ovptr->cptr[m]=curr->cptr[m-1];
        ovptr->keys[pos]=k;
        ovptr->cptr[pos]=left;
        ovptr->cptr[pos+1]=right ; //overload node filling ends
        
        //left sibling empty check and execution
        
        if(curr->prev!=NULL&&curr->prev->cnt<(m-1)){
            curr->prev->keys[curr->prev->cnt]=parent->keys[0];
            for(int i=0;i<parent->cnt-1;++i)parent->keys[i]=parent->keys[i+1];
            curr->prev->cnt=curr->prev->cnt+1;
            curr->prev->cptr[curr->prev->cnt]=NULL;
            parent->keys[parent->cnt-1]=ovptr->keys[0];
            for(int i=0;i<m-1;++i)
            {curr->keys[i]=ovptr->keys[i+1];
            curr->cptr[i]=ovptr->cptr[i+1];}
            curr->cptr[m-1]=ovptr->cptr[m];
        }
        //right sibling empty check and execution
        else if(curr->next!=NULL && curr->next->cnt<(m-1)){
            for(int i=curr->next->cnt;i>0;--i){
                curr->next->keys[i]=curr->next->keys[i-1];
                curr->next->cptr[i+1]=curr->next->cptr[i];
            }
            ++curr->next->cnt;
            curr->next->cptr[1]=curr->next->cptr[0];
            curr->next->keys[0]=parent->keys[parent->cnt-1] ;
            curr->next->cptr[0]=NULL;
            for(int i=parent->cnt-1;i!=0;--i)parent->keys[i]=parent->keys[i-1];
            parent->keys[0]=ovptr->keys[ovptr->cnt-1];
            for(int i=0;i<m-1;++i)
            {curr->keys[i]=ovptr->keys[i];
            curr->cptr[i]=ovptr->cptr[i];}
            curr->cptr[m-1]=ovptr->cptr[m-1];
        }
        else{
        //splitting  of overload node into curr and newn
        curr->cnt=(m-1)/2 ;
        for(int i=0;i<m;++i)curr->cptr[i]=NULL;
        curr->prev=NULL;
        curr->next=NULL;
        for(int i=0;i<curr->cnt;++i){
            curr->keys[i]=ovptr->keys[i]  ;
            curr->cptr[i]=ovptr->cptr[i];
        }
        curr->cptr[curr->cnt]=ovptr->cptr[curr->cnt];
        bdptr newn;
        newn=new(bdnode);
        newn->cnt=(m-1)/2;
        for(int i=0;i<m;++i)newn->cptr[i]=NULL;
        newn->prev=NULL;
        newn->next=NULL;
         for(int i=0;i<curr->cnt;++i){
             newn->keys[i]=ovptr->keys[curr->cnt+1+i];
             newn->cptr[i]=ovptr->cptr[curr->cnt+1+i];
         }
        newn->cptr[curr->cnt]=ovptr->cptr[2*curr->cnt+1];
        //adding middle elem to parent
        if(curr==B){ //if its root then create new node
            bdptr tmp ;
            tmp=new(bdnode);
            tmp->cnt=1; 
            tmp->keys[0]=ovptr->keys[(m-1)/2];
            for(int i=0;i<m;++i)tmp->cptr[i]=NULL;
            tmp->next=NULL;
            tmp->prev=NULL;
            tmp->cptr[0]=curr;
            tmp->cptr[1]=newn;
            B=tmp;
            parent=B;
        }
    
        else{ // else  add to immediate parent
            bdptr proot=B;
            pair<bdptr , bdptr> p=search(B,parent->keys[0],proot);
            fitting(B,ovptr->keys[(m-1)/2],parent,curr,newn,p.second);
        }
    }
    }/*END OF NODE SPLIT*/
}
/*ADD func calls search func ,fitting func(for nodesplit or insertsort)*/
void Add(bdptr &B,int k){
    if(B==NULL){
        B=new(bdnode);
        B->cnt=1;
        B->keys[0]=k;
        B->prev=NULL;
        B->next=NULL;
        for(int i=0;i<m;++i)B->cptr[i]=NULL;
        return ;
    }
    bdptr curr,parent=B;
    pair<bdptr , bdptr> p =search(B,k,parent); //search for correct pos of value
    curr=p.first;
    parent=p.second;
    fitting(B,k,curr,NULL,NULL,parent);
}
int main(){
    bdptr B ;
    B=NULL ;
    int i;
    cin>>i;
    while(i!=0){
    Add(B,i);
    vector<vector<bdptr>>res ;
    levorderlink(B,0,res);
    //linking of siblings
    for(int i=0;i<res.size();++i){
        for(int j=0;j<res[i].size()-1;++j){
            res[i][j]->next=res[i][j+1];
            res[i][j+1]->prev=res[i][j];
        }
        res[i][0]->prev=NULL;
        int x=res[i].size()-1;
        res[i][x]->next=NULL;
    }
    cin>>i;
    }
    vector<vector<bdptr>>res ;
    levorderlink(B,0,res);
    for(int i=0;i<res.size();++i){
        for(int j=0;j<res[i].size();++j){
            for(int k=0;k<res[i][j]->cnt;++k)cout<<res[i][j]->keys[k]<<" ";
        }
        cout<<endl;
    }
    return 0 ;
}

