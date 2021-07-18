#include<iostream>
#include<vector>
using namespace std ;
int main(){
	int A[9]={5,9,3,6,2,4,8,1,7};
	vector <int> H ;
	int size=9,i=0,j;
	while(i<size){
		H.push_back(A[i]);
		j=H.size()-1 ;
		while(j!=0 && H[j]>H[(j-1)/2]){
			swap(H[j],H[(j-1)/2]);
			j=(j-1)/2;
		}
		++i ;
	}
	for(int i=0 ; i<H.size();++i){
		cout<<H[i]<<" ";
	}
	return 0 ;
}
