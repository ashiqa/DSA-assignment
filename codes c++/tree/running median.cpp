#include<iostream>
#include<vector>
using namespace std ;
void swap(int &a, int &b){
	int temp ;
	temp =a ;
	a=b ;
	b= temp ;
}
void minheapify(vector<int> &minH){
	int j ;
		j=minH.size()-1 ;
		while(j!=0 && minH[j]<minH[(j-1)/2]){
			swap(minH[j],minH[(j-1)/2]);
			j=(j-1)/2;
		}
}
void maxheapify(vector<int> &maxH){
		int j=maxH.size()-1 ;
		while(j!=0 && maxH[j]>maxH[(j-1)/2]){
			swap(maxH[j],maxH[(j-1)/2]);
			j=(j-1)/2;
	}
}
int main(){
	int num ;
	vector <int> minH ;
	vector <int> maxH ;
	cout<<"enter number : ";
	cin>>num ;
	maxH.push_back(num);
    cin>>num ;
	while(num!=-1){
		if(maxH.size()>minH.size()){
			int g=maxH[0];
			if(g<num){
				maxH[0]=g ;minH.push_back(num);
				minheapify(minH);
			}
			else {maxH[0]=num ; minH.push_back(g);
			minheapify(minH);
			}
		}
		else if(maxH.size()<minH.size()){
			int g=minH[0];
			if(g<num){
				minH[0]=num ;maxH.push_back(g);
				maxheapify(maxH);
			}
			else {minH[0]=g ;maxH.push_back(num);
				maxheapify(maxH);
			}
		}
		else if(maxH.size()==minH.size()){
			if(num>minH[0]){
				minH.push_back(num);
				minheapify(minH);
			}
			else{
				maxH.push_back(num);
				maxheapify(maxH);
			}
		}
		if(minH.size()>maxH.size()){
			cout<<"median is : "<<minH[0]<<endl;
		}
		if(minH.size()<maxH.size()){
			cout<<"median is : "<<maxH[0]<<endl;
		}
		if(minH.size()==maxH.size()){
			cout<<"median is : "<<(maxH[0]+minH[0])/2<<endl;
		}
		cout<<"enter number : ";
		cin>>num;
	}
	return 0 ;
}
