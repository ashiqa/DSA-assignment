#include<iostream>
using namespace std;

int main(){
	int n ,A[50],freq[50],max=0,B[50];
	cin>>n ;
	for(int i=0 ; i<n ;++i){
		cin>>A[i];
		if(A[i]>max)max=A[i];
	}
	for(int i=0 ; i<=max;++i){  //initalising freq array 
		freq[i]=0;
	}
	for(int i=0 ; i<n;++i){  //count array
		++freq[A[i]];
	
	}
	for(int i=1;i<=max;++i){ //cummulative count 
		freq[i]+=freq[i-1];
	}
	for(int i=0; i<n;++i){
		B[freq[A[i]]-1]=A[i];
		--freq[A[i]];
	}
	for(int i=0 ; i<n ;++i){
		A[i]=B[i];
	}	
	for(int i=0 ; i<n ;++i){
		cout<<A[i]<<" ";
	}	
	return 0;
	}	
