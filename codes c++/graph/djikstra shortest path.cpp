#include<iostream>
#include<vector>
using namespace std ;

void insertG(vector<pair<int,int> > G[7],int u,int v,int wt){
	G[u].push_back({v,wt});
}
//find min dist vertex in table , visit it and update dist of adjacent vertex of min dist vertex repeat
void djishortpath(vector<pair<int,int> >G[7],vector<bool> & visited,vector<int> &dist,vector<int> &pv){
	int u=0,flag=0;
	dist[u]=0;
	pv[u]=u;
	while(!flag){
		flag=1 ;
		int minD=INT_MAX,minV;
		for(int i=0;i<7;++i){
			if(dist[i]<minD&&visited[i]==false){
				minD=dist[i];
				minV=i;
			}
		}
		visited[minV]=true ;
		for(int i=0 ; i<G[minV].size();++i){
			int v=G[minV][i].first;
			int w=G[minV][i].second ;
			int d=dist[minV]+w;
			if(d<dist[v]){
				dist[v]=d;
				pv[v]=minV;
			}
		}
		for(int i=0;i<7;++i)if(visited[i]==false)flag=0;
	}
}
int main(){
	int N=7,u,v ,wt;
	vector<pair<int,int> >G[N];
	cin>>u ;
	while(u!=-1){
		cin>>v>>wt;
		insertG(G,u,v,wt);
		cin>>u;
	}
	vector<bool> visited(N,false);
	vector <int> pv(N,1);
	vector<int> dist(N,INT_MAX);
	djishortpath(G,visited,dist,pv);
	cout<<"shortest dist length from 1 to 6"<<dist[5];
	return 0;
}
