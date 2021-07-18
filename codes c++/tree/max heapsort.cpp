#include<iostream>
#include<vector>
using namespace std ;
void swap(int &a, int &b){
	int temp ;
	temp =a ;
	a=b ;
	b= temp ;
}
void heapify(vector<int> &H, int pos){

	if(2*pos+1<H.size() && H[pos]>H[2*pos+1]){
		swap(H[pos],H[2*pos+1]);
		heapify(H,2*pos+1); 
	}
	if(2*pos+2<H.size() && H[pos]>H[2*pos+2]){
		swap(H[pos],H[2*pos+2]);
		heapify(H,2*pos+2);
	}	
}

int main(){
	int A[9]={1,2,7,3,10,8,18,21,5};
	vector <int> H ;
	for(int i=0 ; i<9; ++i)H.push_back(A[i]);
	vector <int> sorted ;
	while(H.size()!=1){
		sorted.push_back(H[0]);
		H[0]=H[H.size()-1];
		H.pop_back() ;
		heapify(H,0);
	}
	sorted.push_back(H[0]);
	for(int i=0 ; i<sorted.size();++i)
		cout<<sorted[i]<<" ";
	return 0 ;
}
