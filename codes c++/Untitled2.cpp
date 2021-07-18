#include<iostream>
using namespace std ;

 int main(){
 	int a[50], n ,i,j,size, cnt ,b[50] ;
 	cout<<"enter n ";
 	for(int i=1 ;i<=n;++i)
 	a[i-1]=i ;
 	cout<<"enter no of times you want the process to repeat ";
 	cin>>cnt ;
 	for(int c=1 ;c<=cnt ;++c){
	 
 	for( j=0,i=0 ;i<n;i=i+c+1,++j)
	 b[j]=a[i];
 	a=b ;
 	
 }
size=j--;
for(int k=0 ;k<size ;++k)
	cout<<a[k]<<" , ";
	return 0 ;
	
}






