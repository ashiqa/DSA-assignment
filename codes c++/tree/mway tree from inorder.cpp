#include<bits/stdc++.h>
using namespace std ;
int m=3,ccc=0;
struct mstnode{
    int cnt ;
    int key[2];
    struct mstnode *cptr[3];
};
typedef struct mstnode * mstptr ;
void inorderBuild(mstptr &T,int arr[],int l,int r,int lvl){
    if(lvl==3){
        T=new(mstnode);
        T->cnt=2;
        T->key[0]=arr[l];
        T->key[1]=arr[r];
        for(int o=0;o<m;++o)T->cptr[o]=NULL;
        return ;
    }
    else{
        int index1=(((r-l+1)-2)/m) ;
        int index2=index1+index1+1;
        index1+=l;
        index2+=l;
        T=new(mstnode);
        T->cnt=2;
        T->key[0]=arr[index1];
        T->key[1]=arr[index2];
        for(int o=0;o<m;++o)T->cptr[o]=NULL;
        inorderBuild(T->cptr[0],arr,l,index1-1,lvl+1);
        inorderBuild(T->cptr[1],arr,index1+1,index2-1,lvl+1);
        inorderBuild(T->cptr[2],arr,index2+1,r,lvl+1);
    }
}
void levorder(mstptr MT){
    mstptr T;
    mstptr hsh;
    hsh=new(mstnode);
    hsh->cnt=2;
    hsh->key[0]=99;
    hsh->key[1]=99;
    for(int o=0;o<m;++o)hsh->cptr[o]=NULL;
    queue<mstptr>q ;
    q.push(MT);
    q.push(hsh);
    while(q.size()!=1){
        T=q.front();
        q.pop();
        if(T->key[0]==99){
            cout<<endl;
            q.push(T);
        }
        else{
        cout<<T->key[0]<<" "<<T->key[1]<<" ";
        for(int i=0;i<3;++i){if(T->cptr[i]!=NULL)q.push(T->cptr[i]);}
        }
    }
}
int main(){
    int m ,k,i=-1, arr[30];
    mstptr MT ;
    MT=NULL ;
    cin>>m;
    cin>>k;
    while(k!=-1){
        arr[++i]=k;
        cin>>k;
    }
    inorderBuild(MT,arr,0,25,1);
    levorder(MT);
    return 0 ;
}
