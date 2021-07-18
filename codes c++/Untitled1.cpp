#include<iostream>
using namespace std;
int main(){
	int N,k, arr[50],idno,idno[50] ;
	cout<<"enter no. of gfs ";
	cin>>N;
	cout<<"enter gf who found out ";
	cin>>k ;
	cout<<"enter array of gfs";
	for(int i=1 ;i<=N;++i)     //creating array of gfs
	cin>>arr[i];
	
	for(int i=1 ; i<=N ;++i)     //id number of angrygf 
	{ if (arr[i]==k)
	idno=i ;
	break ;
	}
	for(int j=1 ;j<=N;++j){  //creating idno array
		idno[j]=j;
	}
	
	return 0;
}
