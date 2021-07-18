#include<iostream>
using namespace std ;
struct stack{
	int top ;
	int size ;
	int element[50];
};
void push(struct stack &S,int x){
	if(S.top==S.size-1){
		cout<<"full";
	}
	else{
		S.element[++S.top]=x ;
	}	
}
int pop(struct stack &S){
	if(S.top==-1)
	cout<<"empty";
	else{
	   return S.element[S.top--] ;
	}
}
void push2(struct stack &S ,int y){
	if(S.top==-1)
	{
	   push(S,y);
	   return ;
	}
	else{
		int x= pop(S);
		push2(S,y);
		push(S,x);
	}
}
void recurse(struct stack &S){
	if(S.top==-1)
	return ;
	int x=pop(S);
	recurse(S) ;
	push2(S,x) ;
}

int main(){
 struct stack S ;
S.top=-1 ; int x ;
cout<<"enter stack size ";
cin>>S.size	;
cout<<"enter stack " ;
for(int i=0 ; i<S.size;++i)
    {cin>>x ;push(S,x);
	}
recurse(S) ;
for(int i=0 ; i<S.size;++i)
    {x=pop(S);cout<<x<<" ";
	}
 return 0 ;	
}
