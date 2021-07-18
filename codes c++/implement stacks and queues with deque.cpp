#include<iostream>
using namespace std ;
struct dequeue{
	int size ;
	int front ; 
	int rear ;
	int element[50];
};
struct stack{
	int size ;
	int top ;
};
struct queue{
	int f ;
	int r ;
	 int size ;
};
 void  insertfront(struct dequeue &D,int x){
 	 if (D.front==0)
    { 
        cout << "full" ; 
        return; 
    } 
    if (D.front == -1) 
    { 
        D.front = 0; 
        D.rear = 0; 
    } 
    else 
        D.front = D.front-1; 
  
    D.element[D.front] = x ; 
} 
 } 
void  insertrear(struct dequeue &D, int x){
	if(D.rear==D.size-1){
		cout<<"full";
		return ;
	}
	else {
		D.rear=D.rear+1 ;
	}
	D.element[D.rear]=x ;
} 
void  deletefront(struct dequeue &D){
	if(D.front==-1){
		cout<<"empty";
		return ;
	}
	else if(D.front==D.rear){
		D.front=-1 ; D.rear=-1 ;
	}
	else 
	   D.front=D.front+1 ;
} 
void  deleterear(struct dequeue &D){
   if(D.rear==-1){
   	cout<<"empty"; return ;
   }
   if(D.rear==D.front){
   	D.front=0 ; D.rear=0 ;
   }
   else D.rear=D.rear-1 ;	
}
void pop(struct dequeue&D ){
	deleterear(D);
}
void push(struct dequeue&D,int x){
	insertrear(D,x);
}
void enqueue(struct dequeue&D,int x){
	insertrear(D,x);
}
void  dequeue(struct dequeue&D){
	deletefront(D);
}
int main(){
	struct stack S ;
	struct queue Q ;
	struct dequeue D ;
	push(D,5);
	pop(D);
	enqueue(D,6);
	dequeue(D);
	return 0 ;
}
