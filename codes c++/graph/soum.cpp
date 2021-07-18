#include<iostream>
 using namespace std;
 #define v 7
 int Find(int k,int parent[])
    {
        if (parent[k]==k)
            return k;
        return Find(parent[k],parent);
    }
void Union(int a,int b,int parent[])
    {
        int x = Find(a,parent);
        int y = Find(b,parent);
 
        parent[x] = y;
    }
void kruskal(int ap[],int newr[8][8],int cost[10][4],int p){
    if(p==12) return;
    int x=cost[p][1];
    int y=cost[p][2];
    if(Find(x,ap)!=Find(y,ap)){
        Union(x,y,ap);
        cout<<x<<" "<<y<<endl;
        newr[x][y]=cost[p][3];
        newr[y][x]=cost[p][3];
        kruskal(ap,newr,cost,p+1);
    }
    else{
        kruskal(ap,newr,cost,p+1);
    }
}
void print(int a[8][8]){
    int s=0;
    for(int i=1;i<=7;i++){
        for(int j=1;j<=7;j++){
            if(a[i][j]!=0&&i<j){
                s+=a[i][j];
            }
        }
    }
    cout<<s;
}
int main(){
   int parent[8]={0,1,2,3,4,5,6,7};
   int newr[8][8]={0};
   int cost[13][4],e;
   int p=0;
    int adj[v+1][v+1]={0};
    e=12;
    adj[1][2]=2;
    adj[2][1]=2;
    adj[2][5]=10;
    adj[5][2]=10;
    adj[5][7]=6;
    adj[7][5]=6;
    adj[7][6]=1;
    adj[6][7]=1;
    adj[3][6]=5;
    adj[6][3]=5;
    adj[3][1]=4;
    adj[1][3]=4;
    adj[1][4]=1;
    adj[4][1]=1;
    adj[2][4]=3;
    adj[4][2]=3;
    adj[4][7]=4;
    adj[7][4]=4;
    adj[4][6]=8;
    adj[6][4]=8;
    adj[4][5]=7;
    adj[5][4]=7;
    adj[4][3]=2;
    adj[3][4]=2;
    for(int i=1;i<=7;i++){
        for(int j=1;j<=7;j++){
            if(adj[i][j]!=0&&i<j){
                cost[p][1]=i;
                cost[p][2]=j;
                cost[p][3]=adj[i][j];
                p++;
            }
        }
    }
    for(int i=0;i<p;i++){
        for(int j=i+1;j<p;j++){
            if(cost[i][3]>cost[j][3]){
                swap(cost[i],cost[j]);
            }
        }
    }
    kruskal(parent,newr,cost,0);
    print(newr);
    
}
