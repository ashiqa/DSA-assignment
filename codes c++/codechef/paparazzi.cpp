#include <iostream>
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
	    long long int starht=0,starpos,maxB=0 ,maxB2=0;
	    long long int starht2=0 , starpos2 ;
	    float maxA=0.0,maxA2=0.0;
	    for(long long intj=0; j<n;++j){
	        if(h[j]>starht){
	            starht=h[j];
	            starpos=j ;
	        }
	        else if(h[j]<starht){
	            float angle=(j-starpos)/(starht-h[j]);
	            maxA=max(maxA,angle);
	            if(maxA==angle)maxB=max(maxB,(j-starpos));
	        }
	        if(h[n-1-j]>starht2){
	            starht2=h[n-1-j];
	            starpos2=n-1-j ;
	        }
	        else if(h[n-1-j]<starht2){
	            float angle=(starpos2-(n-1-j))/(starht2-h[n-1-j]);
	            maxA2=max(maxA2,angle);
	            if(maxA2==angle)maxB2=max(maxB2,(starpos2-(n-1-j)));
	        }
	    }
	    cout<<max(maxB,maxB2)<<endl;
	}
	return 0;
}

