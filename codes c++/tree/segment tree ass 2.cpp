#include<iostream>
using namespace std ;
struct Snode{
	int sum ;
	int min ;
	int max ;
};
struct Snode buildSegTree(struct Snode S[],int A[],int i, int l, int r){
    if(l==r){
        S[i].min=A[l];
        S[i].sum=A[l];
        S[i].max=A[l];
        return S[i];
    }
    int mid=(l+r)/2;
    S[i].sum=buildSegTree(S,A,2*i+1,l,mid).sum+buildSegTree(S,A,2*i+2,mid+1,r).sum;
    S[i].min=min(buildSegTree(S,A,2*i+1,l,mid).min,buildSegTree(S,A,2*i+2,mid+1,r).min);
    S[i].max=max(buildSegTree(S,A,2*i+1,l,mid).max,buildSegTree(S,A,2*i+2,mid+1,r).max);
    return S[i];
}
int rangeSumQuery(struct Snode S[],int i ,int l,int r,int sl,int sr){
	if(sl<=l && sr>=r)return S[i].sum;
	if(sr<l||sl>r)return 0 ;
	else{
		int mid=(l+r)/2;
		return rangeSumQuery(S,2*i+1,l,mid,sl,sr)+rangeSumQuery(S,2*i+2,mid+1,r,sl,sr);
	}
}
int rangeMinQuery(struct Snode S[],int i ,int l,int r,int sl,int sr){
	if(sl<=l && sr>=r)return S[i].min;
	if(sr<l||sl>r)return 9999 ;
	else{
		int mid=(l+r)/2;
		return min(rangeMinQuery(S,2*i+1,l,mid,sl,sr),rangeMinQuery(S,2*i+2,mid+1,r,sl,sr));
	}
}
int rangeMaxQuery(struct Snode S[],int i ,int l,int r,int sl,int sr){
	if(sl<=l && sr>=r)return S[i].max;
	if(sr<l||sl>r)return 0 ;
	else{
		int mid=(l+r)/2;
		return max(rangeMaxQuery(S,2*i+1,l,mid,sl,sr),rangeMaxQuery(S,2*i+2,mid+1,r,sl,sr));
	}
}
void updateSumSeg(struct Snode S[],int i,int l,int r,int diff,int index){
    if(l>index||index>r)return ;
    S[i].sum+=diff;
    if(l==r)return ;
    updateSumSeg(S,2*i+1,l,(l+r)/2,diff,index);
    updateSumSeg(S,2*i+2,((l+r)/2)+1,r,diff,index);
}
int updateMinSeg(struct Snode S[],int i,int l,int r,int newn,int index){
    if(l>index||index>r)return S[i].min ;
    if(l==r&&r==index){S[i].min=newn;return newn;}
    S[i].min=min(updateMinSeg(S,2*i+1,l,(l+r)/2,newn,index),updateMinSeg(S,2*i+2,((l+r)/2)+1,r,newn,index));
    return S[i].min;
}
int updateMaxSeg(struct Snode S[],int i,int l,int r,int newn,int index){
    if(l>index||index>r)return S[i].max ;
    if(l==r&&r==index){S[i].max=newn;return newn;}
    S[i].max=max(updateMaxSeg(S,2*i+1,l,(l+r)/2,newn,index),updateMaxSeg(S,2*i+2,((l+r)/2)+1,r,newn,index));
    return S[i].max;
}
int main(){
    int N=10,Q=12;
    int arr[N]={1,2,3,4,5,6,7,8,9,10};
    int query[Q][3]={
        {1,2,7},
        {2,3,9},
        {3,2,6},
        {4,0,5},
        {0,6,13},
        {0,2,7},
        {0,9,12},
        {0,0,17},
        {1,0,4},
        {2,5,9},
        {3,2,7},
        {4,6,9} 
    };
    struct Snode S[19];
	int sum;
    struct Snode x=buildSegTree(S,arr,0,0,9);
    for(int i=0 ; i<Q;++i){
        if(query[i][0]==0){
            updateSumSeg(S,0,0,9,query[i][2]-arr[query[i][1]],query[i][1]);
            updateMinSeg(S,0,0,9,query[i][2],query[i][1]);
            updateMaxSeg(S,0,0,9,query[i][2],query[i][1]);
        }
         if(query[i][0]==1){
            int minn=rangeMinQuery(S,0,0,9,query[i][1],query[i][2]);
            cout<<minn<<endl;
        } 
        else if(query[i][0]==2){
            int maxx=rangeMaxQuery(S,0,0,9,query[i][1],query[i][2]);
            cout<<maxx<<endl;
        } 
        else if(query[i][0]==3){
        sum=rangeSumQuery(S,0,0,9,query[i][1],query[i][2]);
        cout<<sum<<endl ;
        }
        else if(query[i][0]==4){
            int sum=rangeSumQuery(S,0,0,9,query[i][1],query[i][2]);
            cout<<(sum/float(query[i][2]-query[i][1]+1))<<endl; }
    }
    return 0 ;
}



