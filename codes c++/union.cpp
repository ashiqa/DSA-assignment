#include <iostream>
union U{
    int a ;
    char b ;
};
using namespace std;

int main()
{   union U A[6] ;
    int tag[6];
    for(int i=0 ; i<6 ;++i){
        cout<<"enter 0 for number and 1 for char";  
        cin>>tag[i];
        if(!tag[i]){
            cout<<"enter number";
            cin>>A[i].a;}
        else{
            cout<<"enter char";
            cin>>A[i].b; 
        }    
    }
    for(int i=0 ;i<6;++i){
        if(!tag[i])
            cout<<A[i].a<<" ";
        else
            cout<<A[i].b<<" "; 
    }
    
    return 0;
}
