#include<iostream>
using namespace std ;

int main(){
	int A[50],n,startid=-1,endid=-1 ;
	cout<<"size";
	cin>>n ;
	for(int i=0 ; i<n ;++i){
		cin>>A[i];
	}
	for(int i=1 ; i<n-1 ;++i){
		if(!(A[i]>A[i-1]&&A[i]<A[i+1]))
		  { if(A[i]<A[i-1]) startid=i-1;
		  	if(A[i]>A[i+1]) startid=i;
		  }
		  if(startid!=-1)break ;
	}
	for(int i=n-2 ;i>startid;--i){
	if(A[i]<A[i-1])endid=i ;
	if(A[i]>A[i+1])endid=i+1 ;
	if(endid!=-1)break ;
	}
	cout<<startid <<"to "<<endid ;
	
	return 0 ;
}
