#include<iostream>
#include<vector>
using namespace std ;
int main(){
	int A[7]={10,15,18,12,13,14,11};
	vector <int> H ;
	int size=7,i=0,j;
	while(i<size){
		H.push_back(A[i]);
		j=H.size()-1 ;
		while(j!=0 && H[j]<H[(j-1)/3]){
			swap(H[j],H[(j-1)/3]);
			j=(j-1)/3;
		}
		++i ;
	}
	for(int i=0 ; i<H.size();++i){
		cout<<H[i]<<" ";
	}
	return 0 ;
}
