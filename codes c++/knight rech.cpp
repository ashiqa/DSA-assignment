//OWN to be the King to ride the Knight to WON 
#include<iostream>

using namespace std ;
struct queue{
	int size ;
	int f;
	int r ;
	int element[100][3];
};
void enqueue(struct queue& Q, int x,int y,int &d){
	if(Q.size==Q.r+1)
	return ;
	else{
		if(Q.f==-1){
			Q.f=0 ; Q.r=0 ;
		}
		else{
			Q.r=Q.r+1 ;
		}
		Q.element[Q.r][0]=x ;
		Q.element[Q.r][1]=y ;
		Q.element[Q.r][2]=d ;
	}
}
void dequeue(struct queue& Q,int &x , int &y,int &d){
	
	if(Q.f==-1)
	cout<<"emtpy";
	else{
		if(Q.f==Q.r){
			x=Q.element[Q.f][0];
			y=Q.element[Q.f][1];
			d=Q.element[Q.f][2];
			Q.f=-1 ; Q.r=-1 ;
		}
		else{
			x=Q.element[Q.f][0];
			y=Q.element[Q.f][1];
			d=Q.element[Q.f][2];
			Q.f=Q.f+1 ;	
		}
		
	}
}
void knight(int visited[8][8],int x ,int y,struct queue &Q ){
	int d=0 ;
	enqueue(Q,x,y,d);
    visited[x][y]=1 ;
    while(Q.f!=-1){
    	
        dequeue(Q,x,y,d);
        if(x==0&&y==7){
		cout<<d ;break;}
        d=d+1;
        if(x-1>=0 &&y-2>=0&& visited[x-1][y-2]==0){enqueue(Q,x-1,y-2,d);}
        if(x+1<8 && y-2>=0&&visited[x+1][y-2]==0){enqueue(Q,x+1,y-2,d);}
        if(x+1<8 &&y+2<8 && visited[x+1][y+2]==0){enqueue(Q,x+1,y+2,d);}
        if(x-2>=0 &&y+1<8&&visited[x-2][y+1]==0){enqueue(Q,x-2,y+1,d);}
        if(y+2<8&&x-1>=0 &&visited[x-1][y+2]==0){enqueue(Q,x-1,y+2,d);}
        
        if(y-1>=0&&x+2<8 && visited[x+2][y-1]==1){enqueue(Q,x+2,y-1,d);}
        
        if(x-2>=0 &&y-1>=0 && visited[x-2][y-1]==1){enqueue(Q,x-2,y-1,d);}
        if(x+2<8&&y+1<8 && visited[x+2][y+1]==1){enqueue(Q,x+2,y+1,d);
		
		}
        
}
    return ;
}
int main(){
    
    struct queue Q ;
     Q.size=100 ;Q.f=-1 ;Q.r=-1 ;
   int visited[8][8]={0};
    knight(visited , 7,0 , Q);
    return 0 ;
}
