#include<bits/stdc++.h>
using namespace std ;
#define N 10
void insertG(int G[N][N],int u,int v){
	G[u][v]=1 ;
}
void DFS(int v,int G[N][N],int num[N],int low[N],stack<int> &S,bool visited[N],int &time){
	num[v]=++time ;
	low[v]=num[v]  ;  //rule 1 
	S.push(v);
	visited[v]=true ;
	for(int w=0;w<N;++w){
		if(G[v][w]==1){ //if edge exists
			if(num[w]!=-1){ //visited
				if(visited[w])low[v]=min(num[w],low[v]) ; //rule 2 backedge
			}
			else{ //unvisited
				DFS(w,G,num,low,S,visited,time);
				low[v]=min(low[v],low[w]); //rule 3 tree-edge
			}
		}	
	}
	if(num[v]==low[v]){
		while(S.top()!=v){
			int x=S.top();
			cout<<x+1<<" " ;
			visited[x]=false ;
			S.pop();
		}
		int x=S.top();
			cout<<x+1<<" " ;
			visited[x]=false ;
			S.pop();
			cout<<endl ;
	}
}
int main(){
	int G[N][N] ,u,v,num[N],low[N],time=-1 ;
	stack<int> S ;
	bool visited[N];
	for(int i=0;i<N;++i){ //initialising
		num[i]=-1 ;
		low[i]=-1 ;
		visited[i]=false ;
		for(int j=0;j<N;++j){
			G[i][j]=-1 ;
		}
	}
	cin>>u;
	while(u!=-1){  //input graph
		cin>>v ;
		insertG(G,u-1,v-1);
		cin>>u ;
	}
	for(int i=0;i<N;++i)
	if(num[i]==-1)DFS(i,G,num,low,S,visited,time);

	return 0 ;
}
