#include<iostream>
#include<vector>
#include<queue>
using namespace std ;

void insertG(vector<int> G[5],int u,int v){
	G[u].push_back(v);
	G[v].push_back(u);
}
void DFS(vector<int>G[5],int u,vector<bool> &visited){
	visited[u]=true ;
	cout<<u<<" ";
	for(int i=0;i<G[u].size();++i){
		int v=G[u][i];
		if(visited[v]==false)DFS(G,v,visited);
	}
}
void BFS(vector<int>G[5],int u){
	vector<bool>visited(5,false);
	queue<int>q;
	q.push(u);
	visited[u]=true;
	while(!q.empty()){
		u=q.front();
		cout<<u<<" ";
		q.pop();
		for(int i=0;i<G[u].size();++i){
			int v=G[u][i];
			if(visited[v]==false){
				q.push(v);
				visited[v]=true;
			}
		}
	}
}
int main(){
	int N=5,u,v ;
	vector<int>G[N];
	cin>>u ;
	while(u!=-1){
		cin>>v;
		insertG(G,u,v);
		cin>>u;
	}
	vector<bool> visited(5,false);
	DFS(G,0,visited);
	cout<<endl;
	BFS(G,0);
	return 0 ;
}
