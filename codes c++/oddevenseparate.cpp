#include <iostream>

using namespace std;
void sortOddEven(int arr[100],int n){
    int i=0,j=n-1;
    int *start, *end ; //2 pointer to start and end
    start=&arr[0];
    end=&arr[n-1];
    
    while(i<n/2 && j>n/2){
        while((*start)%2==0){  //if even on leftside increment start ptr till u find odd which require swap
            i=i+1;
            start=&arr[i] ;
        }
        while((*end)%2==1){    //if odd on rightside decrement end ptr till u find even(requires swap)
            --j ;
            end=&arr[j];
        }
        swap( *start,*end);   //swap even to left and odd to right 
        ++i ; ++start;--end ; --j ;
      
    }
      for(int g=0;g<n ; ++g)  //output array
    {
        cout<<arr[g]<<" ";
    }
}
int main()
{   int arr[100] ;
    int n ;
    cout<<"size of input ";
    cin>>n;
    
    cout<<"input array:";
    for(int g=0 ; g<n ;++g){
        cin>>arr[g];
    }
    sortOddEven(arr,n);
    return 0;
}
