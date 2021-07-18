#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
#define N 7 
void insertG(int G[N][N],int x,int y,int wt){
	G[x][y]=wt ;
	G[y][x]=wt ;
}
void primMST(int G[N][N],bool visited[N],int dist[N],int PV[N]){
    dist[0]=0 ;PV[0]=0 ;
    for(int i=0; i<N ;++i){
        int curr= i ;
        while(!visited[curr]){
            visited[curr]=true ;
            int minV=99,minD=99; 
            for(int j=1 ; j<N;++j){
                if(G[curr][j]!=0 && !visited[j] && G[curr][j]<dist[j]){
                    PV[j]=curr ;
                    dist[j]=G[curr][j];
                }
                if(!visited[j]){minD=min(minD,dist[j]); if(minD==dist[j])minV=j ;} 
            }
            curr=minV ;
        }
    }
}
int main(){
	int u,v,wt,res=0 ;
	int G[N][N]={{0}};  //graph 
	int PV[N]={-1,-1,-1,-1,-1,-1,-1};   //union set 
    int dist[N]={99,99,99,99,99,99,99};
    bool visited[N]={false} ;
	cin>>u ;
	while(u!=-1){
		cin>>v>>wt;
		insertG(G,u-1,v-1,wt);
		cin>>u;
	}
	primMST(G,visited,dist,PV);
	for(int i=1 ;i<N;++i){
	    cout<<PV[i]+1<<"-"<<i+1<<endl ;
	    res+=dist[i];
	}
	cout<<res;
	return 0 ;
}
