#include<iostream>
using namespace std ;
int main(){
	int m ,n ,X[15],Y[15];
	cout<<"enter size";
	cin>>m>>n ;
	cout<<"enter array X ";
	for(int i=0 ; i<m ;i++)
		cin>>X[i];
		cout<<"enter array Y";
	for(int i=0 ; i<n ;++i)
		cin>>Y[i];
	
	int i;
	for(int j=0 ; j<n ;++j){
		i=j ;
		while(i<m-1){
		
		if(X[i]==0){
			swap(Y[j],X[i]);
			int k=i ;
			while(X[k]>X[k+1] || X[k+1]==0 ){
				swap(X[k],X[k+1]);
				if((k+1)<m)++k ;
				else break ;
			}
			break ; 
		}
		++i ;
	}
	}
	cout<<"sorted array X ";
	for(int i=0 ; i<m ;i++)
		cout<<X[i];	
	return 0;	
}
