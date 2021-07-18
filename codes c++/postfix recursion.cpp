#include<iostream>
using namespace std ;
int n ;
union U{
	int opnd ;
	char optr ;
};
int eval(int op1 , int op2 , char optr){
	switch(optr){
		case '+' : return op1+op2 ;
					break ;
		case '*' : return op1*op2 ;
					break ;
		case '-' : return op1-op2 ;
					break ;
		case '/' : return op1/op2 ;
					break ;									
	}
}
void postfix(union U A[], int tag[],int id,int B[],int bid){
	if(id==n)return ;
	if(tag[id]==0){
		int arith=eval(B[bid-2],B[bid-1],A[id].optr) ;
		bid=bid-2 ;
		B[bid]=arith ;
		postfix(A,tag,id+1,B,bid+1);
	}
	if(tag[id]==1){
		B[bid]=A[id].opnd ;
		postfix(A,tag,id+1,B,bid+1) ;
	}	
}
int main(){
	union U A[10];
	int tag[10],res,B[10] ;
	cout<<"enter size of expression";
	cin>>n;
	for(int i=0 ; i<n ;++i )
	{   cout<<"press 1 for operand and 0 for operator";
	 	cin>>tag[i];
	 	if(tag[i]==1){
            cout<<"enter operand";
	 		cin>>A[i].opnd ;
		    }
	 	else{
	 		cout<<"enter operator";
	 		cin>>A[i].optr ;
	 	}
	}
	postfix(A,tag, 0 ,B,0);
	cout<<"result is :";
	cout<<B[0]; 
   return 0 ;	
}

