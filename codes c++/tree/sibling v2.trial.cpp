#include<bits/stdc++.h>
using namespace std ;
int m=5;
struct bdnode{
    int cnt ;
    int keys[4];
    struct bdnode *cptr[5];
};
struct ovnode{
    int cnt;
    int keys[5];
    struct bdnode *cptr[6];
};
struct opnode{
    int cnt;
    int keys[50];
    struct bdnode *cptr[51];
};
typedef struct bdnode *bdptr ;
/*searches for correct node to insert k and also calcs parent*/
pair<bdptr,bdptr> search(bdptr B,int k,bdptr parent){
    for(int i=0;i<B->cnt ;++i){
        //less than key vals; cptr[0...cnt-1] covered
        if(k<=B->keys[i]){
        	if(k==B->keys[i])return {B,parent};
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
        //adding middle elem to parent
        if(curr==B){ //if its root then create new node
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
        //splitting  of overload node into curr and newn
        curr->cnt=(m-1)/2 ;
        for(int i=0;i<m;++i)curr->cptr[i]=NULL;
        for(int i=0;i<curr->cnt;++i){
            curr->keys[i]=ovptr->keys[i]  ;
            curr->cptr[i]=ovptr->cptr[i];
        }
        curr->cptr[curr->cnt]=ovptr->cptr[curr->cnt];
        bdptr newn;
        newn=new(bdnode);
        newn->cnt=(m-1)/2;
        for(int i=0;i<m;++i)newn->cptr[i]=NULL;
         for(int i=0;i<curr->cnt;++i){
             newn->keys[i]=ovptr->keys[curr->cnt+1+i];
             newn->cptr[i]=ovptr->cptr[curr->cnt+1+i];
         }
        newn->cptr[curr->cnt]=ovptr->cptr[2*curr->cnt+1];
            bdptr tmp ;
            tmp=new(bdnode);
            tmp->cnt=1; 
            tmp->keys[0]=ovptr->keys[(m-1)/2];
            for(int i=0;i<m;++i)tmp->cptr[i]=NULL;
            tmp->cptr[0]=curr;
            tmp->cptr[1]=newn;
            B=tmp;
            parent=B;
        }
    
        else{ // else  key distribute
           struct opnode *opptr ;
        opptr=new(opnode);
        int sibcnt=parent->cnt+1; //2
        //filling overload node with parent and sibling s to be distrubeted
        opptr->cnt=(m-1)*sibcnt +parent->cnt; //8+1=9
        for(int i=0;i<51;++i)opptr->cptr[i]=NULL;
        int l=-1;
        for(int i=0;i<=parent->cnt;++i){
            for(int j=0;j<parent->cptr[i]->cnt;++j){
                opptr->keys[++l]=parent->cptr[i]->keys[j];
                opptr->cptr[l]=parent->cptr[i]->cptr[j];
            }
            if(i!=parent->cnt)opptr->keys[++l]=parent->keys[i];
        }
        //adding k to voerload node
        int poss;
        for(int i=0;i<opptr->cnt;++i){
            if(k<opptr->keys[i]){
                poss=i;
                break ;
            }
        }
        ++opptr->cnt; //10
        for(int i=opptr->cnt-1;i!=poss;--i){
            opptr->keys[i]=opptr->keys[i-1];
            opptr->cptr[i]=opptr->cptr[i-1];
        }
        opptr->cptr[opptr->cnt]=NULL;
        opptr->keys[poss]=k;
         //overload node filling ends
        //splitting  of overload node into curr and newn
        int cnttill=-1;
        for(int h=0;h<=parent->cnt;++h){
        	parent->cptr[h]->cnt=opptr->cnt/(sibcnt+1);
	        for(int i=0;i<parent->cptr[h]->cnt;++i){
	            parent->cptr[h]->keys[i]=opptr->keys[++cnttill];
	            parent->cptr[h]->cptr[i]=opptr->cptr[cnttill];
	        }
	        parent->keys[h]=opptr->keys[++cnttill];
		}
        parent->cnt++;
        bdptr newn;
        newn=new(bdnode);
        newn->cnt=opptr->cnt-cnttill-1;
        for(int i=0;i<m;++i)newn->cptr[i]=NULL;
         for(int i=0;i<newn->cnt;++i){
             newn->keys[i]=opptr->keys[cnttill+1+i];
         }
        parent->cptr[parent->cnt]=newn; 
        }
    }
    /*END OF NODE SPLIT*/
}
/*ADD func calls search func ,fitting func(for nodesplit or insertsort)*/
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
    int i;
    cin>>i;
    while(i!=0){
    Add(B,i);
    cin>>i;
    }
    inorder(B);
    return 0 ;
}
