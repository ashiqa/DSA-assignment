#include<iostream>
using namespace std ;
int bin(int[],int,int);
int el ;
int main(){
	int size , a[30],pos;
	cout<<"enter size";
	cin>>size ;
	for(int i=0;i<size;++i)
cin>>a[i];
cout<<"element to be searched" ;
cin>>el;
	pos=bin(a,0,size-1);
	cout<<"pos is "<<pos ;
	return 0 ;
}
int bin(int b[30],int beg,int end){
	int mid=(beg+end)/2;
	if(b[mid]==el)
	return mid ;
	else if(b[mid]>el){
	beg=mid+1 ;
	return bin(b,beg,end);
}
	else if(b[mid]<el){
	end=mid-1 ;
	return bin(b,beg,end);
}
}
