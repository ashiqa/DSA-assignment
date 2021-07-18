#include<iostream>
using namespace std ;
union U {
	int no ;
	char c ;
	float fno ;
};
struct stack {
	int size ;
	int top ;
	union U element[50];
};
void push(struct stack&S,union U x,int tag){
	if(S.top==S.size-1)
	cout<<"stack is full";
	else if(tag==1)
		S.element[++S.top].no=x.no ;
	else if(tag==2)
		S.element[++S.top].c=x.c ;
	else if(tag==3)
		S.element[++S.top].fno=x.fno ;		
}

void pop(struct stack &S,int tag[]){
	if(S.top==-1)
	cout<<"stack is empty" ;
	else {
		if(tag[S.top]==1)cout<<S.element[S.top].no;
    	else if(tag[S.top]==2)cout<<S.element[S.top].c;
    	else if(tag[S.top]==3)cout<<S.element[S.top].fno;
    	--S.top ;
	}
}
int main(){
	struct stack S ;
	cout<<"enter size of stack";
	cin>>S.size ;
	int tag[S.size];
	union U x ;
    S.top=-1 ;
    cout<<"generic stack input";
    for(int i=0 ; i<S.size;++i){
    	cout<<"enter input (1-number ,2-char , 3-float) ";
    	cin>>tag[i];
    	if(tag[i]==1){ cin>>x.no ;
		push(S,x,tag[i]); }
    	else if(tag[i]==2){cin>>x.c ;
		push(S,x,tag[i]);}
    	else if(tag[i]==3){cin>>x.fno;
    		push(S,x,tag[i]);
		}
	}
	cout<<"result of 1 pop";
	pop(S,tag);
	return 0 ;
}
