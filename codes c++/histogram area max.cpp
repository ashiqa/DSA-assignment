#include<iostream>
using namespace std ;
int main(){
	int A[10],n, area[10],maxx;
	cout<<"enter size";
	cin>>n;
	cout<<"enter array";
	for(int i=0; i<n;++i)
		cin>>A[i];
	for(int i=0 ; i<n ;++i){
		int j=i ,k=i,count=1 ;
		while(j+1<n && A[i]<A[j+1]){
			++count ; ++j ;
		}
		while(k-1>=0 && A[i]<A[k-1]){
			++count ; ++k ;
		}
		area[i]=A[i]*count ;
	}
	cout<<"max area of rectangle ";
	for(int i=0; i<n;++i)
		maxx=max(area[i],maxx);
	cout<<maxx ;	
	return 0 ;	
}
