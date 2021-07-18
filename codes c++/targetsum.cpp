#include<iostream>
#include<vector>
using namespace std ;
int size ;
void sumset(vector<int> A,int i, int target , vector<int> res ){ //finding all possible combination from fibnocci set to get sum 
	
	if(target==0){  //result
		for(int i=res.size()-1;i>0;--i){
			cout<<1;
			int s=res[i]-res[i-1]-1;
			while(s>0){
				cout<<0 ;
				--s ;
			} 
			}
			cout<<1;
			cout<<endl ; 
		return ; 
	}
	if(i==size)return ;   //base case 
	sumset(A,i+1,target,res );  //exclude first element
	
	res.push_back(i+2);      
	sumset(A,i+1,target-A[i],res);  //include first element
	res.pop_back();
}

int main(){
	vector<int> A ;
	string fitstring ;
	cout<<"enter fitstring";
	cin>>(fitstring);
	int n=fitstring.size(),sum=0,cha, t1 = 0, t2 = 1,nextTerm;
	 for (int i = 1; i <= n; ++i) {  //filling fibnocci array & converting fbit to bit
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        if(fitstring[n-i-1]=='1'){
        	sum=sum+nextTerm ;
		}
        A.push_back(nextTerm) ;
    }
	
	size=A.size();
	vector<int> res ;
	cout<<"press 1 for increment and 0 for decrement";
	cin>>cha ;
	cha==1?sumset(A ,0,sum+1,res ):sumset(A,0,sum-1,res);
		
	return 0 ;
}
