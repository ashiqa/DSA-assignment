#include<iostream>
#include<vector>
#include<queue>
using namespace std ;

void insertG(vector<int> G[5],int u,int v){
	G[u].push_back(v);
}
void hascycle(vector<int>G[5],int u,vector<bool> &visited,int &cnt){
	visited[u]=true ;
	for(int i=0;i<G[u].size();++i){
		int v=G[u][i];
		if(visited[v]==false)hascycle(G,v,visited,cnt);
		else {
			cnt++;
		}
	}
}
int main(){
	int N=5,u,v ,cnt=0;
	vector<int>G[N];
	cin>>u ;
	while(u!=-1){
		cin>>v;
		insertG(G,u,v);
		cin>>u;
	}
	vector<bool> visited(5,false);
	hascycle(G,0,visited,cnt);
	return 0 ;
}
