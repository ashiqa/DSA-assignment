#include<iostream>
using namespace std ;
struct stack{
	int size ;
	int top ;
	int element[50];
};
void push(struct stack &S ,int x){
	if(S.top==S.size-1)
	cout<<"full";
	else 
		S.element[++S.top]=x ;
}
int pop(struct stack &S){
	if(S.top==-1){
		cout<<"empty";
	}
	else{
		return S.element[S.top--];
	}
}
int partition(int a[],int l,int h)
{
	int i=(l);
	l+=1;
	while(l<=h)
	{
		if(a[l]<=a[i] && a[h]>=a[i])
		{
			l++;
			h--;
		}
		else if(a[h]>=a[i])
		h--;
		else if(a[l]<=a[i])
		l++;
		else if(a[l]>=a[i] && a[h]<=a[i])
		{
			swap(a[l],a[h]);
			l++;
			h--;
		}
		
	}
	swap(a[i],a[h]);
	return h;
}

int main(){
	struct stack S ;
	int n=5,l=0,h ;
	h=n-1 ;
	int A[5];
	for(int i=0 ;i<5;++i)cin>>A[i];
	S.top=-1 ;
	S.size=5 ;
	push(S,l);
	push(S,h);
	while(S.top!=-1){
		int p=partition(A,l,h);
		pop(S);
		pop(S);
		if(p-1>l){
			h=p-1 ;
			push(S,l);
			push(S,h);
		}
		if(p+1<h){
			l=p-1 ;
			push(S,l);
			push(S,h);
		}
	}
	
	for(int i=0 ;i<5;++i)cout<<A[i]<<" ";
	return 0 ;
}

