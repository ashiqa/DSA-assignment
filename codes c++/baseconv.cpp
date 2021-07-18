#include<iostream>
using namespace std ;

void bconv(int n,int b){
	if(n==0)cout<<0 ;
	else{
		bconv(n/b,b);
		if(n%b>9)
			cout<<char('A'+n%b-10) ;
		else
		cout<<n%b ;
	}
}
int main(){
   
    int g,b ;
    cout<<"enter number";
    cin>>g ;
    cout<<"enter base (2,8,16) ";
    cin>>b ;
    bconv(g,b);
    return 0 ;
}
