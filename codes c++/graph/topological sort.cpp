#include<iostream>
#include<vector>
#include<queue>
using namespace std ;

void insertG(vector<int> G[7],int u,int v){
	G[u].push_back(v);
}
void topsort(vector<int> G[7],int u,vector<int> &indegree,vector<bool> &visited){
	visited[u]=true;
	cout<<u<<" ";
	for(int i=0;i<G[u].size();++i){
		int v=G[u][i];
		indegree[v]--;
		if(indegree[v]==0&& visited[v]==false)topsort(G,v,indegree,visited);
}
}
int main(){
	int N=7,u,v ;
	vector<int>G[N];
	vector<int> indegree(N,0);
	cin>>u ;
	while(u!=-1){
		cin>>v;
		insertG(G,u,v);
		indegree[v]++ ;
		cin>>u;
	}
	vector<bool> visited(N,false);
	topsort(G,0,indegree,visited);
	return 0 ;
}
