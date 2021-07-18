#include<iostream>

using namespace std ;
struct queue{
	int size ;
	int f;
	int r ;
	int element[100][2];
};
void enqueue(struct queue& Q, int x,int y){
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
	}
}
void dequeue(struct queue& Q,int &x , int &y){
	int t,u ;
	if(Q.f==-1)
	cout<<"emtpy";
	else{
		if(Q.f==Q.r){
			x=Q.element[Q.f][0];
			y=Q.element[Q.f][1];
			Q.f=-1 ; Q.r=-1 ;
		}
		else{
			x=Q.element[Q.f][0];
			y=Q.element[Q.f][1];
			Q.f=Q.f+1 ;	
		}
		
	}
}
int count=0 ;
void neg2pos(struct queue &Q,int mat[4][5] ){
	if(Q.r==-1){
	cout<<count-1 ; return ; }
	struct queue Q1 ;
	int x ,y ;
	Q1.f=-1;
	Q1.r=-1  ;
	Q1.size=20 ;
	while(Q.f!=-1){
		dequeue(Q,x,y);
		mat[x][y]=0 ;
		if(x+1<4&&mat[x+1][y]<0)enqueue(Q1,x+1,y);
		if(y+1<5&&mat[x][y+1]<0)enqueue(Q1,x,y+1);
		if(x-1>=0&&mat[x-1][y]<0)enqueue(Q1,x-1,y);
		if(y-1>=0&&mat[x][y-1]<0)enqueue(Q1,x,y-1);
	}
	++count ;
	neg2pos(Q1,mat) ;
}
int main(){
	struct queue Q ;
	Q.f=-1 ; Q.r=-1 ;
	Q.size=20 ;
	int mat[4][5] =
	{
		{ -1, -9,  0, -1,  0 },
		{ -8, -3, -2,  9, -7 },
		{  2,  0,  0, -6,  0 },
		{  0, -7, -3,  5, -4 }
	};
	for(int i=0 ; i <4;++i){
		for(int j=0 ; j<5 ;++j){
			if(mat[i][j]>=1){
				enqueue(Q,i,j);
			}
		}
	}
	neg2pos(Q,mat);
	return 0 ;
}
