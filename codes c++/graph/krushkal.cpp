#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
void insertG(int G[7][7],int x,int y,int wt){
	G[x][y]=wt ;
	G[y][x]=wt ;
}
int find(int S[],int x){
	if(S[x]==-1)return x ;
	return find(S,S[x]);
}
void unionSet(int S[7],int u,int v){
	if(S[v]==-1){
		S[v]=u ;
	}
	else if (S[u]==-1)S[u]=v ;
	else {
		if(find(S,v)!=find(S,u))
		S[find(S,v) ]=find(S,u) ;
	}
}
void kruskalMST(int S[7],vector<pair<int,int> >sortWT[11],int MST[7][7]){
    for(int i=0 ; i<11;++i){
        for(int j=0;j<sortWT[i].size();++j){
            int x=sortWT[i][j].first ;
            int y=sortWT[i][j].second ;
            if(find(S,x)!=find(S,y)){
                unionSet(S,x,y);
                MST[x][y]=i;
            }
        }
    }
}
int main(){
	int N=7,u,v,wt ;
	int G[7][7]={{0}};  //graph 
	int S[7]={-1,-1,-1,-1,-1,-1,-1};   //union set 
	int MST[7][7]={0};	//min spanning tree result
	cin>>u ;
	while(u!=-1){
		cin>>v>>wt;
		insertG(G,u-1,v-1,wt);
		cin>>u;
	}
	vector<pair<int,int> >sortWT[11];
	for(int i=0 ; i<7;++i){
	   for(int j=0 ;j<7;++j){
	        if(G[i][j]!=0){
	            int wt=G[i][j];
	            sortWT[wt].push_back({i,j});
	            G[i][j]=0;
	            G[j][i]=0;
	        }
	   }
	}
  kruskalMST(S,sortWT,MST);
 int res =0 ;
	for(int i=0 ; i<7 ;++i){
	    for(int j=0 ;j<7;++j){
	        if(MST[i][j]!=0){
	            res+=MST[i][j];
	            cout<<"edge : "<<i+1<<" "<<j+1<<endl ;
	    }}
	}
 	cout<<"least sum of weights of min spanning tree is "<<res;
	return 0 ;
}
