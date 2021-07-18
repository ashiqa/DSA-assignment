#include<iostream>
#include<vector>
typedef long long ll ;
using namespace std ;
int main(){
    int n , m ;
     cin>>n>> m ;
     int c[m];
     for(int i= 0 ; i<m ;++i){
         cin>>c[i];
     }
     vector<vector<ll> >dp(m,vector<ll>(n+1,0));
     
     for(int j=0 ; j<=n; ++j){
         dp[0][j]=(c[0]<=j?(j%c[0]==0)? 1:0 :0);
     }
     for(int i=0  ; i<m;++i){
         dp[i][0]=1 ;
     }
     for(int i=1 ; i<m ; ++i){
         for(int j=0 ; j<=n ; ++j){
             if(c[i]<=j){
                 dp[i][j]=dp[i-1][j]+dp[i][j-c[i]];
             }
             else{
                 dp[i][j]=dp[i-1][j];
             }
         }
     }
     cout<<dp[m-1][n];
    return 0 ;
}
//reference coin change hackerrank 
