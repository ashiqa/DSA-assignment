#include<iostream>
using namespace std ;
int main(){
    int N , S  ;
    cin>>N>>S ;
    int wt[N], val[N] ;
    for(int i=0 ; i<N ; ++i){
        cin>>wt[i]>>val[i] ;
    }
    vector<vector<int>>dp(N, vector<int>(S+1,0)); // stores max value for item i till size S
    for(int s=0 ; s<=S ; ++s){ //for first item 0
        if(wt[0]<=s){
            dp[0][s]=val[0];
        }
    }
    for(int i=1 ; i<N ; ++i){ // 1 to N items
        for(int j=0 ; j<=S ; ++j){
            if(wt[i]<=j){
                dp[i][j]=max(dp[i-1][j],val[i]+dp[i-1][j-wt[i]]) ;  //include item 
            }else{
                dp[i][j]=max(dp[i][j], dp[i-1][j]); //exclude item
            }
        }
    }
    cout<<dp[N-1][S] ;
    return 0 ; 
}
