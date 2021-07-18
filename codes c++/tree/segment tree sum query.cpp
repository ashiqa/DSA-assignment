#include <iostream>
using namespace std;
int buildTree(int S[], int arr[], int i, int l, int r)
{
    if (l > r)
        return 0;
    if (l == r)
    {
        S[i] = arr[l];
        return S[i];
    }
    int mid = (l + r) / 2;
    S[i]= buildTree(S, arr, 2 * i + 1, l, mid) + buildTree(S, arr, 2 * i + 2, mid + 1, r);
    return S[i];
}
int querySum(int S[],int i ,int ql,int qr ,int l,int r){
    if(ql>r || qr<l){  //non overlapping 
        return 0 ;
    }
    if(ql<=l && qr>=r)return S[i]; //fully overlap 
    //partial overlap 
    int mid=(l+r)/2 ;
    return querySum(S,2*i+1,ql,qr,l,mid)+querySum(S,2*i+2,ql,qr,mid+1,r) ;
}
void updateQuery(int S[],int i , int l , int r , int pos ,int diff){
    if(pos<l || pos>r)return ;
    //if(l<=pos && pos<=r){
        S[i]+=diff ;
    //}
    if(l==r)return ;
    int mid=(l+r)/2 ;
    updateQuery(S,2*i+1 , l , mid ,pos ,diff);
    updateQuery(S,2*i+2 ,mid+1 , r,pos ,diff );
}
int main()
{
    int n ;
    cout << "enter n" ;
    cin >> n ;
    int arr[n] ;
    int S[2 * n-1] = {0} ;
    cout << "enter array";
    for (int i = 0; i < n; ++i)cin >> arr[i];

    buildTree(S, arr, 0, 0, n - 1);
    int ans=querySum(S,0,1,3,0,n-1);
    	cout<<ans ;
     updateQuery(S,0,0,n-1 ,3,1);
     ans=querySum(S,0,1,3,0,n-1);
    cout<<ans ;
    return 0;
}
