#include<iostream>
using namespace std ;
#define N 7
void insertG(int G[N][N],int u,int v){
	G[u][v]=1 ;
}
int time=-1 ;
void DFS(int v,int G[N][N],int num[N],int low[N],int parent[N],bool cv[N]){
	num[v]=++time ;
	low[v]=num[v]  ;  //rule 1 
	int dfsc=0 ;
	for(int w=0;w<N;++w){
		if(G[v][w]==1){ //if edge exists
			
			++dfsc ;
			if(num[w]!=-1){ //visited
				low[v]=min(num[w],low[v]) ; //rule 2 backedge
			}
			else { //unvisited
				parent[w]=v ;
				DFS(w,G,num,low,parent,cv);
				low[v]=min(low[v],low[w]); //rule 3 tree-edge
				if(parent[v]!=-1 && num[v]<=low[w]){ //non root cut vertex condition
					cv[v]=true;
				}
				if(parent[v]==-1 &&dfsc>=2)cv[v]=true; //for root with 2 child
			}
		}
	}
}
int main(){
	int G[N][N] ,u,v,num[N],low[N],parent[N] ;
	bool cv[N];
	for(int i=0;i<N;++i){ //initialising
		num[i]=-1 ;
		low[i]=-1 ;
		parent[i]=-1;
		cv[i]=false ;
		for(int j=0;j<N;++j){
			G[i][j]=-1 ;
		}
	}
	cin>>u ;
	while(u!=-1){  //input graph
		cin>>v ;
		insertG(G,u,v);
		cin>>u ;
	}
	DFS(0,G,num,low,parent,cv);
	cout<<"cut vertices are : \n";
	for(int i=0;i<N;++i)if(cv[i])cout<<i<<endl ;
	return 0 ;
}
