#include<iostream>
#include<vector>
using namespace std ;
int main(){
	int S ,N ;
	cin>>S>>N ;
	int weight[N],val[N];
	vector<vector<int> >dp(N,vector<int>(S+1,0));
	
	for(int i=0 ; i<N ; ++i){
		cin>>weight[i]>>val[i];
	}
	for(int i=0 ; i<=S;++i){
	dp[N-1][i]=(weight[N-1] > i ? 0: (val[N-1]*(i/weight[N-1])));
    }
    for(int i=N-2 ; i>=0 ; --i){
    	for(int j=0 ; j<=S;++j){
    		if(j>=weight[i]){
    			dp[i][j]=max(dp[i+1][j],dp[i][j-weight[i]]+val[i]);
			}
			else{
				dp[i][j]=dp[i+1][j];
			}
		}
	}
	cout<<dp[0][S];
	return 0 ;
}
