#include<iostream>
using namespace std ;

void permute(string str , int l ,int r){
	if(l==r)
		cout<<str<<endl ;
	else{
		for(int i=l ; i<=r;++i){
			swap(str[l],str[i]);
		   permute(str,l+1,r);
		   swap(str[l],str[i]);		
		}
	
	}	
}
int main(){
	int  r;
	string str="ABC" ;
	r=str.length();
	permute(str,0,r);
	
	return 0 ;
}
