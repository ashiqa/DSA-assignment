#include <iostream>
using namespace std;
void swap(int &a,int &b){
   int k;
   k=a;
   a=b;
   b=k; 
}
int part(int *a,int l,int h){
    int p=a[l],k=l;
    while(l<h){
       while(a[l]<=p)l++;
       while(a[h]>p)h--;
       if(l<h)swap(a[l],a[h]); 
    }
    swap(a[k],a[h]);
    return h;
}
int * quicksort(int *a,int l,int h){
  if(l>h)return a;
   else{
      int j=part(a,l,h);
      quicksort(a,l,j-1);
      quicksort(a,j+1,h);
      return a;
   }
}
int main() {
   int n,i;
   cin>>n;
   int a[n];
   for(i=0;i<n;i++)cin>>a[i];
   quicksort(a,0,n-1);
   for(i=0;i<n;i++)cout<<a[i]<<" ";
    return 0;
}
