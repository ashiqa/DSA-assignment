#include<iostream>
using namespace std ;
int buildSumSegTree(int S[],int A[],int i, int l, int r){
    if(l==r){
        S[i]=A[l];
        return S[i];
    }
    int mid=(l+r)/2;
    S[i]=buildSumSegTree(S,A,2*i+1,l,mid)+buildSumSegTree(S,A,2*i+2,mid+1,r);
    return S[i];
}
int buildMinSegTree(int S[],int A[],int i,int l, int r){
	if(l==r){
		S[i]=A[l];
		return S[i];
	}
	int mid=(l+r)/2;
	S[i]=min(buildMinSegTree(S,A,2*i+1,l,mid),buildMinSegTree(S,A,2*i+2,mid+1,r));
	return S[i];
}
int rangeSumQuery(int S[],int i ,int l,int r,int sl,int sr){
	if(sl<=l && sr>=r)return S[i];
	if(sr<l||sl>r)return 0 ;
	else{
		int mid=(l+r)/2;
		return rangeSumQuery(S,2*i+1,l,mid,sl,sr)+rangeSumQuery(S,2*i+2,mid+1,r,sl,sr);
	}
}
int rangeMinQuery(int S[],int i ,int l,int r,int sl,int sr){
	if(sl<=l && sr>=r)return S[i];
	if(sr<l||sl>r)return 9999 ;
	else{
		int mid=(l+r)/2;
		return min(rangeMinQuery(S,2*i+1,l,mid,sl,sr),rangeMinQuery(S,2*i+2,mid+1,r,sl,sr));
	}
}
void updateSumSeg(int S[],int i,int l,int r,int diff,int index){
    if(l>index||index>r)return ;
    S[i]+=diff;
    if(l==r)return ;
    updateSumSeg(S,2*i+1,l,(l+r)/2,diff,index);
    updateSumSeg(S,2*i+2,((l+r)/2)+1,r,diff,index);
}
void updateMinSeg(int S[],int i,int l,int r,int newn,int index){
    if(l>index||index>r)return ;
    S[i]=min(S[i],newn) ;
    if(l==r)return ;
    updateMinSeg(S,2*i+1,l,(l+r)/2,newn,index);
    updateMinSeg(S,2*i+2,((l+r)/2)+1,r,newn,index);
}
int main(){
    int N=9,Q=7;
    int arr[N]={9,3,7,2,5,4,3,1,2};
    int query[10][3]={
        {1,2,7},
        {2,2,7},
        {3,4,8},
        {0,7,99},
        {1,6,7},
        {2,6,8},
        {3,7,8}
    };
    int Ssum[17]={0},Smin[17],Savg[17],sum;
    int x=buildSumSegTree(Ssum,arr,0,0,8);
     x=buildMinSegTree(Smin,arr,0,0,8);
    for(int i=0 ; i<Q;++i){
        if(query[i][0]==0){
            updateSumSeg(Ssum,0,0,8,query[i][2]-arr[query[i][1]-1],query[i][1]-1);
            updateMinSeg(Smin,0,0,8,query[i][2],query[i][1]);
        }
        if(query[i][0]==1){
        sum=rangeSumQuery(Ssum,0,0,8,query[i][1]-1,query[i][2]-1);
        cout<<sum<<endl ;
        }
        else if(query[i][0]==2){
            int minn=rangeMinQuery(Smin,0,0,8,query[i][1]-1,query[i][2]-1);
            cout<<minn<<endl;
        }
        else if(query[i][0]==3){
            int sum=rangeSumQuery(Ssum,0,0,8,query[i][1]-1,query[i][2]-1);
            cout<<(sum/(query[i][2]-query[i][1]+1))<<endl; }
    }
    return 0 ;
}

