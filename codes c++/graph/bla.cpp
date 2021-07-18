#include <bits/stdc++.h>
typedef long long ll ;
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ll T ;
    cin>>T ;
    for(ll t=0 ; t<T;++t){
        string s , r ;
        cin>>s ;
        cin>>r ;
        bool found=false ;
        map<char,int> m;
        ll n=s.length();
        ll rn=r.length();
        for(int i=0 ; i<n;++i){
            if(m.find(s[i])==m.end())m.insert(char(s[i]),1) ;
            else m[s[i]]++ ;
        }
        
        for(ll i=0 ; i<=(rn-n); ++i){
            map<char,ll> mcpy=m ;
            for(ll j=i ; j<(i+n);++j){
                if(mcpy.find(r[j])!=mcpy.end() && mcpy[r[j]]!=0){
                    mcpy[r[j]]-- ;
                }
                else break ;
            }
            bool ans=true ;
            for(auto it=mcpy.begin();it!=mcpy.end();++it){
                if(it.second!=0)ans=false ;
            }
            if(ans==true){
                cout<<"YES"<<endl;
                found=true ;
                break ;
            }
        }
        if(found==false)cout<<"NO"<<endl;
    }
    return 0;
}
