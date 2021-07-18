#include<bits/stdc++.h>
#include<float.h>
using namespace std;

int main() {
	// your code goes here
	long long int t ;
	cin>>t ; 
	for(int i=0 ; i<t ;++i){
	    long long int n ;
	    cin>>n ;
	    long long int h[n];
	    for(long long int j=0; j<n;++j){
	        cin>>h[j];
	    }
		long long int maxD=0 ;
		if(n==2){cout<<1<<endl; continue;}
	    for(long long int j=0 ; j<n;++j){
	    	double minslp=DBL_MAX ;
	    	for(long long int k=j+1 ; k<n;++k){ 
	    		double x=(double)((h[j]-h[k]))/((double)(k-j));
				minslp=min(minslp,x);
				if(minslp==x)maxD=max(maxD,k-j);
			}
		}
		cout<<maxD<<endl ;
	}
	return 0 ;
}
