#include<iostream>
using namespace std ;
int buildSegTree(int S[],int A[],int i,int l, int r){
	if(l==r){
		S[i]=A[l];
		return S[i];
	}
	int mid=(l+r)/2;
	S[i]=buildSegTree(S,A,2*i+1,l,mid)+buildSegTree(S,A,2*i+2,mid+1,r);
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
	if(l==r)return S[i];
	if(sr<l||sl>r)return INT_MAX ;
	else{
		int mid=(l+r)/2;
		return min(rangeSumQuery(S,2*i+1,l,mid,sl,sr),rangeSumQuery(S,2*i+2,mid+1,r,sl,sr));
	}
}
int main(){
	int A[6]={1,2,5,6,7,9};
	int S[13]={0};
	buildSegTree(S,A,0,0,5);
	for(int i=0;i<13;++i){
		cout<<S[i]<<" ";
	}
	cout<<endl;
	int sum=rangeSumQuery(S,0,0,5,2,4);
	cout<<sum<<endl;
	int minn=rangeMinQuery(S,0,0,5,0,4);
	cout<<minn;
	return 0 ;
}
