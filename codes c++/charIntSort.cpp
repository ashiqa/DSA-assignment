#include<iostream>
using namespace std ;

union U {
	int a ;
	char b ;
};
int main(){
	union U A[6];
	int tag[6],chs,l=0,r=5;
	while(l<=r){
		cout<<"press 1 for char & 2 for int";
		cin>>chs ;
		if(chs==1){
			cout<<"enter char";
			cin>>A[l].b;
			tag[l]=1 ;l++ ;
		}
		else{
			cout<<"enter int ";
			cin>>A[r].a;
			tag[r]=2;r-- ;
		}
	} 
	for(int i=0;i<6;++i){
		if(tag[i]==1)
		cout<<A[i].b<<" ";
		else cout<<A[i].a<<" ";
		}
}
