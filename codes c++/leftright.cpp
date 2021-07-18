#include <iostream>
using namespace std ;
int main(){
	int A[6],n,i=0,j,chs,num ;
	cout<<"enter size";
	cin>>n ;
	j=n-1;
	while(i<=j){
		cout<<"press 1 for left and 2 for right ";
		cin>>chs;
		cout<<"enter number";
		cin>>num;
		if(chs==1){
			A[i]=num ;
			i++ ;
		}
		else 
		{
			A[j]=num ;
			j--;
		}
	}
	for(i=0 ; i<n;++i)cout<<A[i]<<" ";
	return 0;
}
