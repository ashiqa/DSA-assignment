#include<iostream>
using namespace std ;

int main(){
	int n ,j,k;
	cout<<"size";
	cin>>n ;
	int A[50];
	cout<<"enter array";
	for(int i=0 ; i<n ;++i){
		cin>>A[i];
	}
	for(int i=1 ; i<n-1 ; ++i){
		j=i-1 ,k=i+1 ;
		int first , third,f1=0,f2=0 ;
		while(j>=0){
			if(A[j]<A[i]){
				first=A[j];
				f1=1 ;
				break ;
			}
			--j ;
		}
		while(k<n){
			if(A[k]>A[i]){
				third=A[k];
				f2=1 ;
				break ;
			}
			++k ;
		}
		if(f1&&f2){
			cout<<first<<" "<<A[i]<<" "<<third;
			break;
		}
	}
	return 0 ;
}
