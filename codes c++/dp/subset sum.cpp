#include<iostream>
#include<vector>
using namespace std ;
int main(){
	int n , target ;
	cin>>n>>target ;
	int arr[n];
	for(int i=0 ; i<n ;++i){
		cin>>arr[i];
	}
	vector<vector<bool> >dp(n+1,vector<bool>(target+1,false));
	for(int i=0 ; i<=n ;++i){
		dp[i][0]=true ;
	}
	
	for(int i=1 ; i<=n ;++i){
		for(int j=1 ; j<=target ;++j){
			if(arr[i-1]<=j){
				dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]]	;
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	if(dp[n][target])cout<<"subset exists";
	else cout<<"doesnt" ;
	return 0 ;
}
