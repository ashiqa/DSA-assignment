#include<iostream>
using namespace std ;
int main(){
	int n ,A[10],k,max,C[10];
	cout<<"enter size of array" ;
	cin>>n ;
	cout<<"enter window size : ";
	cin>>k ;
	cout<<"enter array";
	for(int i=0; i<n ;++i){
		cin>>A[i];
	}
	for(int i=0 ; i<n-2 ; ++i){
		max=A[i];
		for(int j=i ; j<i+k-1;++j){
			if(A[j+1]>A[j])max=A[j+1];
		}
		C[i]=max ;
	}
	cout<<"array of max values";
	for(int i=0; i<n-2 ;++i){
		cout<<C[i]<<" ";
	}
	return 0 ;
}
