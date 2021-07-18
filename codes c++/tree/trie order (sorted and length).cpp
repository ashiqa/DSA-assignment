#include<iostream>
using namespace std ;
struct tnode{
	bool wrd ;
	struct tnode *ptr[26] ;
};
typedef struct tnode *tptr ;
void trie_insert(tptr &T,string word , int l){
	if(T==NULL){
		T=new(tnode);
		T->wrd=false ;
		for(int i=0;i<26 ;++i)T->ptr[i]=NULL ;
	}
	if(l==word.size()){
		T->wrd=true ;
		return ;
	}
	int x=word[l]-'A';
	trie_insert(T->ptr[x],word,++l);
}
bool search(tptr T,string word){
	for(int i=0;i<word.size();++i){
		int x=word[i]-'A';
		if(T->ptr[x]==NULL)return false ;
		T=T->ptr[x];
	}
	return true ;
}
void traversal(tptr T, string res){
    if(T==NULL)return ;
    for(int i=0;i<26;++i){
        if(T->ptr[i]!=NULL){
            string prevs=res;
            res+=char('A'+i);
            traversal(T->ptr[i],res);
            if(T->ptr[i]->wrd)cout<<res<<" ";
            res=prevs;
        }
    }
}
int main(){
	tptr T ;
	T=NULL;
	string res="";
	string s;
	cin>>s;
	while(s!="#"){
	trie_insert(T,s,0);
	cin>>s ;
	}
	traversal(T,res);
	cout<<endl;
	trie_insert(T,"A",0);
	traversal(T,res);
	cout<<endl;
	trie_insert(T,"ABB",0);
	traversal(T,res);
	cout<<endl;
	return 0;
}
