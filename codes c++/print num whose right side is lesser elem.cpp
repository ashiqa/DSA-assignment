//OWN to be WON
#include<iostream>
using namespace std ;
struct stack{
    int top ;
    int size ;
    int element[50];
};
void push(struct stack &S,int x){
    if(S.size-1==S.top)
    cout<<"full";
    else
    S.element[++S.top]=x ;
}
int pop(struct stack &S){
    if(S.top==-1)
    cout<<"empty";
    else
    return S.element[S.top--] ;
}
int main(){
    int A[10],n ;
    struct stack S ;
    cin>>n ;
    S.top=-1 ;
    S.size=10 ;
    for(int i =0 ; i<n;++i){
        cin>>A[i];
    }
    push(S,A[n-1]);
    for(int i =n-2 ; i>=0;--i){
        if(A[i]>S.element[S.top])
            push(S,A[i]);
    }
    while(S.top!=-1){
            int g=pop(S);
            cout<<g<<" ";
    }
    return 0 ;
}
