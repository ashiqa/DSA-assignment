#include<iostream>
using namespace std;
int main(){
	int N,girl, arr[50],ino,curr=0,flag=1;
	int idno[50];
	cout<<"enter no. of gfs ";
	cin>>N;
	cout<<"enter gf who found out ";
	cin>>girl ;
	cout<<"enter array of gfs";
	for(int i=1 ;i<=N;++i)     //creating array of gfs
	{cin>>arr[i];
	if(arr[i]==girl) //idno of bustedgf
	ino=i;
	}
	
	for(int j=1 ;j<=N;++j){  //creating idno array
	   if(j==ino)
	   arr[j]=0 ;
	   else 
		idno[j]=j;
	}
	
	while(flag==1 )
    { flag=0;
	
		for(int i=1 ;i<=N;++i)
		{ 
		  if(idno[i]!=0 && ino&idno[i]!=0) //checking ifthey are friends 
		   {ino=i;
		   flag=1;
		   break ;}
		}
			for(int k=1 ; k<=N ;++k ) //removing girls who got to know from gflist
		{ if(ino==idno[k])
          idno[k]=0 ;		
		}
    }
    for(int i=1;i<=N;++i)
{if(idno[i]!=0)
	++curr ;}
	cout<<"no of gf left"<<(curr) ;
	
	return 0;
}
