#include<iostream>
using namespace std ;
typedef struct snode* sptr;
typedef struct cnode* cptr ;
typedef struct rnode* rptr ;
union US{
	rptr r ;
	sptr s ;
};
union UC{
	rptr r ;
	cptr c ;
};
struct snode{
	int rno;
	rptr reg ;
};
struct cnode{
	char cno;
	rptr reg ;
};
struct rnode{
	int tagS ;
	int tagC ;
	union US Sinfo ;
	union UC Cinfo ;
};
int main(){
	int n,flag1=0,flag2=0,i=0 ;
	char c ;
	sptr S[5]={NULL};
	cptr C[5]={NULL};
	rptr cend ;
	int y=c-'A'+0 ;
		while(i<5){
		S[i]->rno=i+1 ;
		S[i]->reg=NULL ; }
		i=0 ;
		while(i<5){
		C[i]->cno=char('A'+i) ;
		C[i]->reg=NULL ; }
		
	cin>>n; cin>>c ;
	while(n!=-1){
		rptr R,send,cend ;
		send=new(rnode);
		cend=new(rnode);
		R=new(rnode);
		
		if(S[n-1]->reg!=NULL){
		send=S[n-1]->reg ;
		cend=C[y]->reg ;
		while(send->Sinfo.r!=NULL){
			send=send->Sinfo.r ;
		} }
		
		if(C[y]->reg!=NULL){
			cend
		}
		while(cend->Cinfo.r!=NULL){
			cend=cend->Cinfo.r ;
		}  }
		R->Sinfo.r=NULL ;
		R->Cinfo.r=NULL ;
		send->reg=R ;
		
		cend->reg=R ;
		
		else{
			cend=new(rnode);
			cend=C[y]->reg;
			while(cend->tagC!=1){
				cend=cend->Cinfo.r ;
			}
		}
		
		if(flag1==1&&flag2==1){
		R->tagC=1   ;
		R->Cinfo.c=C[y]  ;
		R->tagS=1   ;
		R->Sinfo.s=S[n-1] ;
		S[n-1]->reg=R ;
		C[y]->reg=R ;
		flag1=0 ; flag2=0 ;
		}
		else if(flag1==1){
			R->tagS=1;
			R->Sinfo.s=S[n-1];
			S[n-1]->reg=R;
			R->tagC=0 ;
			R->Cinfo.c=C[y];
			cend->Cinfo.r=R ;
		}
		cin>>n ; cin>>c ;	
	}
	return 0;
}
