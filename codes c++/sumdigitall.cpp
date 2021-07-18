#include<iostream>
using namespace std ;

void recurse(int pos ,int n,int currsum,int targetsum,vector<vector<int>>& res){
	if(targetsum<currsum){
		return ; ++pos;
	}
	else{
		res[pos].push_back(currrsum);
		recurse(pos ,n-currsum,currsum,targetsum-currsum,res);
		int x=res[pos].pop_back();
		cout<<x ;
	}
}
void currsum(int n,int currsum ){
	
	vector<vector<int>>res ;
	if(currsum==n){
		return ;
	}
	recurse(0 ,n,currsum+1,n-currsum-1,res);
	for(int i=)
	currsum(n,currsum+1);
}
int main(){
	int n;
	cin>>n;
	currsum(n,0);
	return 0 ;
}
