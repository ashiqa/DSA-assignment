#include <iostream>
using namespace std;

int partition(int a[],int l,int h)
{
	int i=(l);
	l+=1;
	while(l<=h)
	{
//		if(a[l]<=a[i]&&a[i]<=a[h])
//		{
//			l++;
//			h--;
//		}
		if(a[h]>=a[i])
		h--;
		else if(a[l]<=a[i])
		l++;
		else if(a[l]>=a[i]&&a[i]>=a[h])
		{
			swap(a[l],a[h]);
			l++;
			h--;
		}
		
	}
	swap(a[i],a[h]);
	return h;
}
static int j;
void quicksort(int a[],int l,int h)
{
	if(l<h)
	{
	j=partition(a,l,h);
	quicksort(a,l,j-1);
	quicksort(a,j+1,h);
    }
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	quicksort(a,0,n-1);
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
}
