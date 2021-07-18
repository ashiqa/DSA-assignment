#include<iostream>
using namespace std ;
int main(){
	int m,n ,X[10],Y[10];
	cout<<"enter size";
	cin>>m>>n ;
	cout<<"enter array X";
	for(int i=0 ; i<m;++i){
		cin>>X[i];
	}
	cout<<"enter array Y";
	for(int i=0 ; i<n;++i){
		cin>>Y[i];
	}
	int i=0 ;
	while(i<m){
		if(X[i]>Y[0]){
			swap(X[i],Y[0]);
			int j=0 ;
			while(j<(n-2)){
				if(Y[j]>Y[j+1])swap(Y[j],Y[j+1]);
				++j ;
			}
		}
		++i;	
	}
	if(Y[n-1]<Y[n-2])swap(Y[n-1],Y[n-2]);
	for(int i=0 ; i<m;++i){
		cout<<X[i];
	}
	cout<<endl ;
	for(int i=0 ; i<n;++i){
		cout<<Y[i];
	}
	cout<<endl ;
	return 0 ;
}
