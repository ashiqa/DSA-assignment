#include<iostream>
#include<vector>
#include<queue>
using namespace std ;

void insertG(vector<int> G[8],int u,int v){
	G[u].push_back(v);
}
int time=-1 ;
void travel(vector<int> G[8],int u, vector<int> &AT,vector<int> &DT,vector<bool> &visited){
	visited[u]=true ;
	for(int i=0;i<G[u].size();++i){
		int v=G[u][i];
		if(visited[v]==false){
		AT[v]=++time ;
		travel(G,v,AT,DT,visited);
		DT[v]=++time ;
	}
	}
}
int main(){
	int N=8,u,v ;
	vector<int>G[N];
	cin>>u ;
	while(u!=-1){
		cin>>v;
		insertG(G,u,v);
		cin>>u;
	}
	vector<bool> visited(8,false);
	vector<int> AT(N,0) ;
	vector<int> DT(N,0) ;
	
	for(int i=0 ;i<N;++i){
		if(visited[i]==false){
		 AT[i]=++time ;	
		 travel(G,i,AT,DT,visited);
		 DT[i]=++time ;}
	}
	cout<<"arrival time";
	for(int i=0;i<N;++i)cout<<AT[i]<<" ";
	cout<<endl;
    cout<<"departure time";
	for(int i=0;i<N;++i)cout<<DT[i]<<" ";
	
	return 0 ;
}
