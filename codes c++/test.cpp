#include<iostream>
#include<vector>
using namespace std ;
 int main(){
 	int n , amt ;
 	cout<<"enter ";
 	cin>>n >> amt ;
 	int coin[n];
 	for(int i=0 ; i<n ;++i){
 		cout<<"enter ";
 		cin>>coin[i];
 	}
 	vector<vector<int> >dp(n,vector<int>(amt+1,0));

 	for(int i=0 ; i<=amt ;++i){
 		dp[0][i]=(coin[0]<=i? i/coin[0]:0 );
 	}

 	for(int i=1 ; i<n ;++i){
 		for(int j=0 ; j<=amt ; ++j){
 			if(coin[i]<=j){
 				dp[i][j]=min(dp[i-1][j], 1+dp[i][j-coin[i]]) ;

 			}else{
 				dp[i][j]=dp[i-1][j];
 			}
 		}
 	}
 	cout<<"op ";
 	cout<<dp[n-1][amt];
 	return 0 ;
 }