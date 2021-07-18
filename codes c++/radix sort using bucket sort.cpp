#include<iostream>
#include <vector> 
#include<algorithm>
using namespace std;
void bucketsort(int A[],int n,int div){
	vector<int>bucket[10] ;
	
	for(int i=0 ; i<n;++i){  //count array
		bucket[(A[i]/div)%10].push_back(A[i]);
	}
	for(int i=0 ; i<10;++i){
		sort(bucket[i].begin(),bucket[i].end());
	int id=0;
	for(int i=0 ; i<=9 ;++i){
		for(int j=0 ; j<bucket[i].size();++j)
	 	{	A[id]=bucket[i][j];
	 		++id ;
			}			
	}
}}
int main(){
	int n ,A[50],max=0;   //max to find max no of digit from max number
	cin>>n ;
	for(int i=0 ; i<n ;++i){
		cin>>A[i];
		if(A[i]>max)max=A[i];
	}
	for(int i=1;max/i!=0 ;i=i*10)
		bucketsort(A,n,i);
		
	for(int i=0 ; i<n ;++i){
		cout<<A[i]<<" ";
	}	
	return 0;
}
