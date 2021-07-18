#include<iostream>;
using namespace std ;

int main(){
	int m,n,p[10][10],p2[10][10],p3[10][10];
	
	cout<<"ente r dime of first matrix";
	cin>>m>>n;
	int **P =new int *[m];
	cout<<"enter array\n";
	
	for(int i=0 ;i<m;++i)
	p[i]=new int [n];
	
	for(int i=0;i<m;++i)
	for(int j=0 ;j<n;++j)
	cin>>*(*(p+i)+j);
	
	
		int **P2 =new int *[m];
	cout<<"enter array 2\n";
		for(int i=0 ;i<m;++i)
	p2[i]=new int [n];
	
	for(int i=0;i<m;++i)
	for(int j=0 ;j<n;++j)
	cin>>*(*(p2+i)+j);
	
	int **p3=new int *[m];
		cout<<"sum array \n";
		for(int i=0 ;i<m;++i)
	p3[i]=new int [n];
	
	for(int i=0;i<m;++i){
	cout<<endl ;
	for(int j=0 ;j<n;++j){
	*(*(p3+i)+j)=*(*(p+i)+j) +*(*(p2+i)+j) ;
	cout<<	*(*(p3+i)+j) <<" ";}
}
for(int i=0 ;i<m;++i)
delete[] p[i];
delete[] p;
for(int i=0 ;i<m;++i)
delete[] p2[i];
delete[] p2;
for(int i=0 ;i<m;++i)
delete[] p3[i];
delete[] p3;
return 0 ;	
}
