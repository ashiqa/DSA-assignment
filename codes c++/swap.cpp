#include <iostream>

using namespace std;
void swap(int a,int b){
    int t;
    t=a ;
    a=b ;
    b=t ;
    cout<<a<<" "<<b<<endl;
}
void swapref(int &a,int &b){
    int t;
    t=a ;
    a=b ;
    b=t ;
    cout<<a<<" "<<b<<endl;
}
void swapptr(int *a,int *b){
    int *t;
    t=a ;
    a=b ;
    b=t ;
    cout<<*a<<" "<<*b<<endl;
}
int main()
{
    int q1,q2 ;
    cout<<"enter 2 numbers";
    cin>>q1>>q2 ;
    swap(q1,q2);
    swapref(q1,q2);
    swapptr(&q1,&q2);
    
    return 0;
}
