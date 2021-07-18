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
	int x=word[l]-'a';
	trie_insert(T->ptr[x],word,++l);
}
bool search(tptr T,string word){
	for(int i=0;i<word.size();++i){
		int x=word[i]-'a';
		if(T->ptr[x]==NULL)return false ;
		T=T->ptr[x];
	}
	return true ;
}
int main(){
	tptr T ;
	T=NULL;
	trie_insert(T,"abc",0);
	bool ans=search(T,"abc");
	if(ans)cout<<"found";
	return 0;
}
