#include<iostream>
using namespace std ;
void bracket(int n , int open , int close , string s){
	if(close==n&& close==open){
		cout<<s<<"," ;
		return;
	}
	if(open<n){
		bracket(n,open+1,close,s+"(");
	}
	if(close<open){
		bracket(n,open,close+1,s+")");
	}
	
}
int main(){
	int n ;
	string s="";
	cin>>n ;
	bracket(n,0,0,s);
	return 0;
}
