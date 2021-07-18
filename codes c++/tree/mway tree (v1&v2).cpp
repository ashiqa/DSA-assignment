// Life leads to many ways
// Love lightens always
#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
int m=4 ;
struct mstnode{
    int cnt ;
    int keys[3];
    struct mstnode* cptr[4];
};
typedef struct mstnode *mstptr ;

void insert_v1(mstptr &MT,int val){
    if(MT==NULL){
        MT=new(mstnode);
        MT->cnt=1;
        MT->keys[0]=val;
        for(int o=0;o<m;++o)MT->cptr[o]=NULL;
        return ;
    }
    if((MT->cnt)!=m-1 && MT->keys[(MT->cnt)-1]<val ){
        MT->cnt=MT->cnt+1;
        MT->keys[(MT->cnt)-1]=val;}
    else if(MT->keys[(MT->cnt)-1]<val && (MT->cnt)==m-1)insert_v1(MT->cptr[(MT->cnt)],val);
    else if(MT->keys[0]>val)insert_v1(MT->cptr[0],val);
    else{
        for(int i=0;i<((MT->cnt)-1);++i){
            if(MT->keys[i]<val&&val<MT->keys[i+1])
                insert_v1(MT->cptr[i+1],val);
        }
    }
}
void insert_v2(mstptr &MT2,int val){
    if(MT2==NULL){
        MT2=new(mstnode);
        MT2->cnt=1;
        MT2->keys[0]=val;
        for(int o=0;o<m;++o)MT2->cptr[o]=NULL;
        return ;
    }
    if((MT2->cnt)!=m-1 ){
        MT2->cnt=MT2->cnt+1;
        MT2->keys[(MT2->cnt)-1]=val;
        sort(MT2->keys,MT2->keys+MT2->cnt);
    }
    else if(MT2->keys[(MT2->cnt)-1]<val && (MT2->cnt)==m-1)insert_v2(MT2->cptr[(MT2->cnt)],val);
    else if(MT2->keys[0]>val)insert_v2(MT2->cptr[0],val);
    else{
        for(int i=0;i<((MT2->cnt)-1);++i){
            if(MT2->keys[i]<val&&val<MT2->keys[i+1])
                insert_v2(MT2->cptr[i+1],val);
        }
    }
}
void inorder(mstptr MT){
    if(MT==NULL)return ;
    for(int i=0;i<MT->cnt;++i){
        inorder(MT->cptr[i]);
        cout<<MT->keys[i]<<" ";
    }
    inorder(MT->cptr[MT->cnt]);
}
int main(){
    mstptr MT ;
    mstptr MT2 ;
    MT=NULL;
    MT2=NULL;
    int k,m;
    cin>>m;
    cin>>k;
    while(k!=0){
        insert_v1(MT,k);
        cin>>k;
    }
    inorder(MT);
    cout<<endl;
    cin>>m;
    cin>>k;
    while(k!=0){
        insert_v2(MT2,k);
        cin>>k;
    }
    inorder(MT2);
    return 0 ;
}
