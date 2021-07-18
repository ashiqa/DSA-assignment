#include<iostream>
using namespace std ;

int main(){
int A[10],n ,startid=0 , endid,f1=0,f2=0;
cin>>n ;
endid=n-1 ;
cout<<"input array";
for(int i=0 ; i<n;++i){
	cin>>A[i];
}	
for(int i=1 ; i<n-1;++i){
	if(A[i]>A[i-1]&&A[i]>A[i+1]){
		startid =i ;
		break ; }
}
for(int i=n-2;i>startid;--i){
	if(A[i]<A[i-1]&&A[i]<A[i+1]){
		endid=i ;
		break ; }	
}
swap(A[startid],A[endid]);
for(int i=0 ; i<n;++i){
	cout<<A[i];
}	
return 0 ;
}
