#include<iostream>
using namespace std ;
union U{
	int n ;
	char c ;
};
struct dequeue{
	int size ;
	int front ; 
	int rear ;
	union U element[50];
};
void  insertfront(struct dequeue &D,union U x,int ch){
 	 if (D.front==(D.rear+1)%D.size)
    {  cout << "full" ; return; 
    } 
    if (D.front == -1) 
    { D.front = 0; D.rear = 0; 
    } 
    else 
        D.front = (D.front-1)%D.size; 
  if(ch==1)      
     D.element[D.front] = x.n ; 
   else
     D.element[D.front] = x.c ; 
} 
 } 
void  insertrear(struct dequeue &D, union U x,int ch){
	if((D.rear+1)%D.size==D.front){
		cout<<"full";
		return ;
	}
	else if(D.front==-1){
		D.front=0 ;D.rear=0;
	}
	else D.rear=(D.rear+1)%D.size;
	if(ch==1)
	D.element[D.rear]=x.n ;
	else
	D.element[D.rear]=x.c ;
} 
int  deletefront(struct dequeue &D,int ch){

	if(D.front==-1){
		cout<<"empty";
		return ;
	}
	else if(D.front==D.rear){
		if(ch==1)
		cout<<D.element[D.front].n;
		else 
		cout<<D.element[D.front].c ;
		D.front=-1 ; D.rear=-1 ;
	}
	else {
		if(ch==1)
		cout<<D.element[D.front].n;
		else 
		cout<<D.element[D.front].c ;
	   D.front=(D.front+1)%D.size ;	
	}
} 
int deleterear(struct dequeue &D,int ch){

   if(D.rear==-1){
   	cout<<"empty"; return ;
   }
   if(D.rear==D.front){
   	if(ch==1)
		cout<<D.element[D.rear].n;
		else 
		cout<<D.element[D.rear].c ;
   	D.front=-1 ; D.rear=-1 ;
   }
   else{
   	if(ch==1)
		cout<<D.element[D.rear].n;
		else 
		cout<<D.element[D.rear].c ;
   	 D.rear=D.rear-1 ;	
   }

}
struct queue{
	int size ;
	int f;
	int r ;
	union U element[50];
};
void enqueue(struct queue &Q, union U x,int ch ){
	if(Q.size==Q.r+1)
	cout<<"full";
	else{
		if(Q.f==-1){
			Q.f=0 ; Q.r=0 ;
		}
		else{
			Q.r=Q.r+1 ;
		}
		if(ch==1)
		Q.element[Q.r]=x.n ;
		else
		Q.element[Q.r]=x.c ;
	}
}
void dequeue(struct queue &Q,int ch){
	
	if(Q.f==-1)
	cout<<"emtpy";
	else{
		if(Q.f==Q.r){
			if(ch==1)
			cout<<Q.element[Q.f].n;
			else
			cout<<Q.element[Q.f].c;
			Q.f=-1 ; Q.r=-1 ;
		}
		else{
			if(ch==1)
			cout<<Q.element[Q.f].n;
			else
			cout<<Q.element[Q.f].c;
			Q.f=Q.f+1 ;	
		}
		
	}
}

int main(){
	union U A[]={'N', 'I' , 17 , 'T' , 9 , 20 , 'C' , 'S' , 21 , 'E'};
	int tag[10]={0,0,1,0,1,1,0,0,1,0};
	struct dequeue D ;
	D.size=10 ;
	D.front=-1 ;
	D.rear=-1 ;
	for(int i=0 ; i<10;++i){
		if(tag[i]==1){
			insertfront(D,A[i],tag[i]);
		}
		else{
			insertrear(D,A[i],tag[i]);
		}
	}
	struct queue Q1 ,Q2 ;
	for(int i=0 ; )
	Q.size=10 ;
	Q.f=-1 ;
	Q.r=-1 ;
	for(int i=0 ; i<6; ++i){
		enqueue(Q1,deletefront(D,tag[i]));
	}
	for(int i=6;i<10;++i){
		enqueue(Q2,deleterear(D,tag[i]));
	}
	for(int i=0;i<4;++i){
		dequeue(Q2);
	}
	for(int i=0 ; i<6; ++i){
		dequeue(Q1);
	}
	
	return 0;
}

