#include<iostream>
using namespace std ;
int buildSegTree(int S[],int A[],int i,int l, int r){
	if(l==r){
		S[i]=A[l];
		return S[i];
	}
	int mid=(l+r)/2;
	S[i]=min(buildSegTree(S,A,2*i+1,l,mid),buildSegTree(S,A,2*i+2,mid+1,r));
	return S[i];
}
int rangeMinQuery(int S[],int i ,int l,int r,int sl,int sr){
	if(sl<=l && sr>=r)return S[i];
	if(sr<l||sl>r)return INT_MAX ;
	else{
		int mid=(l+r)/2;
		return min(rangeMinQuery(S,2*i+1,l,mid,sl,sr),rangeMinQuery(S,2*i+2,mid+1,r,sl,sr));
	}
}
int main(){
	int A[6]={1,2,5,6,7,9};
	int S[13];
	buildSegTree(S,A,0,0,5);
	for(int i=0;i<13;++i){
		cout<<S[i]<<" ";
	}
	cout<<endl;
	int minn=rangeMinQuery(S,0,0,5,1,4);
	cout<<minn;
	return 0 ;
}
