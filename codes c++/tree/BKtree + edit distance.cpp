#include<iostream>
#include<vector>
#include <cstdlib> 
using namespace std ;
struct BKnode{
    string word;
    struct BKnode *ptr[11];
};
typedef struct BKnode *BKptr ;
int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        
        vector<vector<int>>D(m+1,vector<int>(n+1,0)); 
         for(int i=0;i<=n;++i){
             D[0][i]=i;
         }
        for(int i=0;i<=m;++i){
             D[i][0]=i;
         }
        for(int r=1;r<=m;++r){
            for(int c=1;c<=n;++c){
                if(word1[r-1]!=word2[c-1]){
                    D[r][c]=min(D[r][c-1],min(D[r-1][c],D[r-1][c-1]))+1;
                }
                else{
                    D[r][c]=D[r-1][c-1];
                }
            }
        }
       
        return D[m][n];
    }
void insertBK(BKptr &BK,string s){
    if(BK==NULL){
        BK=new(BKnode);
        BK->word=s ;
        for(int i=0;i<=10;++i)BK->ptr[i]=NULL;
        return ;
    }
    int ED=minDistance(s,BK->word);
    insertBK(BK->ptr[ED],s);
}    
void correctionsuggest(BKptr BK,string N,int k,vector<pair<int,string>> &res){
    if(BK==NULL)return ;
    int ED=minDistance(N,BK->word);
    if(ED<=k)res.push_back({ED,BK->word});
    int start=abs(ED-k);
    int end=ED+k;
    for(int i=start;i<=end;++i){
        correctionsuggest(BK->ptr[i],N,k,res);
    }
}
int main(){
    BKptr BKT ;
    BKT=NULL ;
    string ip,str;
    int k;
    cin>>ip;
    while(ip!="#"){
        insertBK(BKT,ip);
        cin>>ip;
    }
    vector<pair<int,string>>res ;
    cin>>str;
    cin>>k;
    correctionsuggest(BKT,str,k,res);
    for(int i=0;i<res.size();++i){
        cout<<res[i].first<<" "<<res[i].second<<" ";
    }
    return 0;
}
