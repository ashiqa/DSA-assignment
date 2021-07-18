#include<iostream>
using namespace std;
void countsort(int A[],int n,int div){
	int freq[10],B[50];
	for(int i=0 ; i<=9;++i){  //initalising freq array 
		freq[i]=0;
	}
	for(int i=0 ; i<n;++i){  //count array
		++freq[(A[i]/div)%10];
	
	}
	for(int i=1 ; i<=9;++i){ //cummulative count 
		freq[i]+=freq[i-1];
	}
	for(int i=n - 1;i>=0;--i){
		B[freq[(A[i]/div)%10]-1]=A[i];
		--freq[(A[i]/div)%10];
	}
	for(int i=0 ; i<n ;++i){
		A[i]=B[i];
	}
}
int main(){
	int n ,A[50],max=0;
	cin>>n ;
	for(int i=0 ; i<n ;++i){
		cin>>A[i];
		if(A[i]>max)max=A[i];
	}
	for(int i=1;max/i!=0 ;i=i*10)
		countsort(A,n,i);
		
	for(int i=0 ; i<n ;++i){
		cout<<A[i]<<" ";
	}	
	return 0;
}
