#include<iostream>
#include<cstdlib>
#include<stdio.h>
int robo (int m ,int n);
int step=0 ;
using namespace std ;
int main(){
	int m ,n ;
	cout<<"enter the dimension" ;
	cin>>m>>n ;
	robo(m,n);
	cout<<"no of steps"<<step ;
	return 0 ;
}
int robo(int m ,int n){
	int ch ;
if(m==1||n==1)
return 1 ;

ch=rand()%(2);
if(ch==0 ){
	++step;
cout<<"robo moves left" ;
 return robo(m,n-1);
}

else if(ch==1){
	++step ;
	cout<<"robo moves top";
return robo(m-1,n);	
}

else if(ch==2){
++step ;
cout<<"robo moves diagonal";
return robo(m-1,n-1);
}


}
