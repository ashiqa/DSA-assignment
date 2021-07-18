#include<iostream>
#include<vector>
using namespace std ;
int main(){
    int t ,target ,N ;
    cin>>t ;
    while(t--){
        cin>>N>>target;
        vector<int>dp(target+1,0);
        int arr[N];
        for(int i=0 ; i<N;++i){
            cin>>arr[i];
        }
        for(int i=0 ; i<=target ;++i){
            for(int j=0 ; j<N ; ++j){
                if(i>=arr[j]){
                    dp[i]=max(dp[i],dp[i-arr[j]]+arr[j]);
                }
            }
        }
        cout<<dp[target]<<endl ;
    }
    return 0 ;
}

//reference knapsack unbounded hackerank 
