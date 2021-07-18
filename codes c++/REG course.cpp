#include<iostream>
#include<vector>
using namespace std ;

struct stdnode{
   int rno ;
   char cname ;
   struct stdnode* cfp ;
   struct stdnode* sfp ;
   struct stdnode* next ;
};
typedef struct stdnode* sptr ;
void insert(){
  sptr stdIdtab[5]={NULL} ;
    sptr courseIdtab[4]={NULL};
    sptr R,L,T ;
    R=new(stdnode);
    L=new(stdnode);
    cin>>R->rno ;
    cin>>R->cname;
    R->cfp=NULL ;
    R->sfp=NULL ;
    R->next=NULL;
    char xx=R->cname ;
    int x=R->rno ;
    courseIdtab[int(xx)-65]=R ;
    stdIdtab[x-1]=R;
    L=R ;
    int r ;
    char c ;
    cin>>r ;
    cin>>c ;
    while(r!=-1 && c!='#'){
        T=new(stdnode) ;
        T->rno=r ;
        T->cname=c ;
        T->next=NULL ;
        T->cfp=NULL ;
        T->sfp=NULL ;
        L->next=T ;
        L=T ;
        if(stdIdtab[r-1]==NULL){
            stdIdtab[r-1]=L ;
        }
        else{
            sptr s=stdIdtab[r-1] ;
           while(s->sfp!=NULL){
               s=s->sfp ;
           } 
           s->sfp=L ;
        }
        if(courseIdtab[int(c)-65]==NULL){
            courseIdtab[int(c)-65]=L ;
        }
        else{
            sptr c1=courseIdtab[int(c)-65] ;
           while(c1->cfp!=NULL){
               c1=c1->cfp ;
           } 
           c1->cfp=L ;
        }
        cin>>r ;
        cin>>c ;
    } 
    int student_rno ;
    cin>>student_rno ;
	sptr s=stdIdtab[student_rno-1];
    while(s!=NULL){
   		cout<<(s->cname)<<" " ;
   		s=s->sfp;
   }
   cout<<endl ;
   char course_name ;
    cin>>course_name ;
    s=courseIdtab[int(course_name)-65];
    while(s!=NULL){
   		cout<<s->rno<<" " ;
   s=s->cfp; }
   cout<<endl ;
   int i ;
    i=0 ; 
	vector<int>ss[2];
    while(i<2){
    cin>>course_name ;
	sptr s=courseIdtab[(int)course_name-65];
    while(s!=NULL){
   		ss[i].push_back(s->rno) ;
   		s=s->cfp;
   }
   ++i ;
   }
   for(int i=ss[0].size();i>=0; --i){
   	for(int j=0 ; j<ss[1].size();++j){
   		if(ss[0][i]==ss[1][j])cout<<ss[0][i]<<" ";
	   }
   }
   cout<<endl ;
    i=0 ; 
	vector<char>cc[2];
   while(i<2){
    cin>>student_rno ;
	sptr s=stdIdtab[student_rno-1];
    while(s!=NULL){
   		cc[i].push_back(s->cname) ;
   		s=s->sfp;
   }
   ++i ;
   }
   for(int i=0 ; i<cc[0].size(); ++i){
   	for(int j=0 ; j<cc[1].size();++j){
   		if(cc[0][i]==cc[1][j]) cout<<cc[0][i]<<" ";
	   }
   }
   cout<<endl;
   while(R!=NULL){
   	cout<<R->rno<<" "<<R->cname<<" ";
   	R=R->next ;
   }
}
int main(){
    sptr R ;
    insert() ;
    return 0 ;
}
