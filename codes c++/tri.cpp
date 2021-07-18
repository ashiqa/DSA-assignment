#include <iostream>
#include <algorithm> 
  
using namespace std;
void sortOddEven(int arr[9]){
    int i=0,j=8;
    while(i<4&&j>4){
        while(arr[i]%2==0){  //if even on leftside increment start ptr till u find odd which require swap
            ++i;
        }
        while(arr[j]%2==1){    //if odd on rightside decrement end ptr till u find even(requires swap)
            --j ;
        }
        swap( arr[i],arr[j]);   //swap even to left and odd to right 
        ++i ;  --j ;
      for(int g=0;g<9 ; ++g)  //output array
    {
        cout<<arr[g]<<" ";
    }
    }
     
}
int main()
{   int arr[9] ;
    cout<<"input array";
    for(int g=0 ; g<9 ;++g){
        cin>>arr[g];
    }
    sortOddEven(arr);
    return 0;
}
