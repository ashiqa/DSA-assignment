#include<iostream>
using namespace std ;
void insert(int A[],int num , int i,int &pos){ 
	if(i==0){
		if(num<A[0]){
			pos=0 ;
			A[i+1]=A[i];
		}
		return ;
	}
	if(num<A[i]){
		pos=i ;A[i+1]=A[i]; 
	}
	insert(A,num,i-1,pos);
}
void insertionSort(int A[],int n){
	int pos=n ,cpy=A[n];
	if(n==0)return ;
	insertionSort(A,n-1);
	insert(A,A[n],n-1,pos);
	A[pos]=cpy;	
}
int main(){
	int A[7];
	cout<<"enter unsorted array";
	for(int i=0 ;i<7 ;++i)
		cin>>A[i];
	insertionSort(A,6);
	for(int i=0 ;i<7 ;++i)
		cout<<A[i]<<" ";	
	return 0 ;
}
