#include<iostream>
using namespace std ;
struct tnode{
	bool wrd ;
	struct tnode *ptr[36] ;
};
typedef struct tnode *tptr ;
void trie_insert(tptr &T,string word , int l){
	if(T==NULL){
		T=new(tnode);
		T->wrd=false ;
		for(int i=0;i<36 ;++i)T->ptr[i]=NULL ;
	}
	if(l==word.size()){
		T->wrd=true ;
		return ;
	}
	int x;
	if(int(word[l])>96)x=word[l]-'a';
	else if(int(word[l])>=48)x=26+word[l]-'0';
	trie_insert(T->ptr[x],word,++l);
}
void traversal(tptr T, string res){
    if(T->wrd==true){
        cout<<res<<" ";
        return ;}
    for(int i=0;i<36;++i){
        if(T->ptr[i]!=NULL){
            string prevs=res;
            if(i<26)res+=char('a'+i);
            else {
                res+=int(48+i-26);
            }
            traversal(T->ptr[i],res);
            res=prevs;
        }
    }
}
bool search(tptr T,string word){
	for(int i=0;i<word.size();++i){
	    int x;
	    if(int(word[i])>=97)x=word[i]-'a';
	    else if(int(word[i])>=48)x=(word[i]-'0')+26;
		if(T->ptr[x]==NULL)return false ;
		T=T->ptr[x];
	}
	return true ;
}
int main(){
	tptr T ;
	T=NULL;
	string res="";
	trie_insert(T,"abd5c2",0);
	trie_insert(T,"ac8b9",0);
	trie_insert(T,"cdd294a1",0);
	trie_insert(T,"da5b4c63",0);
	trie_insert(T,"bd367",0);
    traversal(T,res);
	return 0;
}
