#include<iostream>
#include<vector>
using namespace std ;

void recurse(int a[100],int l,int r ,int lvl ,vector<int> &vd){
	if(l==r){
		vd[l]=lvl ;
		return ;
	}
	int pos,maxx=INT_MIN ; 
	for(int i=l ; i<=r;++i){
		if(maxx<a[i]){
			maxx=a[i];
			pos=i ;
		}
	}
	vd[pos]=lvl ;
	cout<<pos<<" "<<vd[pos]<<endl ;
	recurse(a,l,pos-1,lvl+1,vd);
	recurse(a,pos+1,r,lvl+1,vd);
}
int main(){
	int t ;
    cin>>  t ;
    while(t--){
    	int n ;
    	cin>>n ;
    	int a[n];
    	vector<int>vd(n,0);
    	for(int i=0 ; i<n ;++i){
    		cin>>a[i];
		}
		recurse(a,0,n-1,0,vd);
//		for(int i=0 ; i<n ;++i){
//    		cout<<vd[i]<<" ";
//		}
	}
	return 0 ;
}
