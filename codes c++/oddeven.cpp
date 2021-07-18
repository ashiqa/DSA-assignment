#include <iostream>

using namespace std;
void swap(int &a,int &b){
    int t ;
    t=a ;
    a=b ;
    b=t ;
}
int main()
{   int arr[9] ;
    for(int g=0 ; g<9 ;++g){ //input array
        cin>>arr[g];
    }
    //variation in bubble sort for odd even
    for(int i=0;i<8;++i){
        for(int j=0 ; j<9-i;++j){
            if((arr[j]%2==1)&&(arr[j+1]%2==0)){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    for(int g=0 ; g<9 ;++g) //output array
        cout<<arr[g]<<" ";
    return 0;
}



