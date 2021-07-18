#include<iostream>
#include<vector>
using namespace std ;
struct hctnode{
	char c ;
	int f ;
	struct hctnode* lc ;
	struct hctnode* rc;
};
typedef struct hctnode* hctptr ;
void swap(hctptr &xp, hctptr &yp)  
{  	hctptr temp ;
     temp = xp;  
    xp = yp;  
    yp = temp;  
}
void Vsort(vector <hctptr> &v){
	int i, j,n; 
	n=v.size(); 
    for (i = 0; i < n-1; i++){
    for (j = 0; j < n-i-1; j++)  
        if ((v[j]->f) > (v[j+1]->f))  
            swap(v[j], v[j+1]);  
   }
}
void printHCTree(hctptr tree){
	if(tree==NULL)return ;
	if((tree->c)!='.')cout<<tree->c<<" " ;
	printHCTree(tree->lc);
	printHCTree(tree->rc);
}
hctptr construct_HCT(vector <hctptr> &v){
	hctptr a ,b,parent ,root;
	while(v.size()!=1){      //construct tree in the vector itself
		a=v[0]; b=v[1];
		v.erase(v.begin());
		v.erase(v.begin());
		parent=new(hctnode);
		parent->c='.';
		parent->f=(a->f)+(b->f);
		if((a->f)<(b->f)){
			parent->rc=a ;
			parent->lc=b ;
		}
		else{
			parent->rc=b ;
			parent->lc=a ;
		}
		v.push_back(parent);
		Vsort(v);
		root=parent ;
	}
	return root ;
}
void insert_vector(vector <hctptr> &v){
	hctptr T ;
	int freq ;
	char alp ;
	cout<<"Enter alphabet and freq"; //filling vector with hsctnode pointers of freq and letters
	cin>>alp ;
	cin>>freq ;
	while(alp!='#'){
		T=new(hctnode);
		T->c=alp ;
		T->f=freq ;
		T->lc=NULL ;
		T->rc=NULL ;
		v.push_back(T);	
		cout<<"Enter alphabet & freq";
		cin>>alp ;
		cin>>freq ;	
	}
	Vsort(v) ;
}
int main(){
	hctptr root ;
	vector < hctptr > v ;
	insert_vector(v);
	root=construct_HCT(v);
	printHCTree(root) ;  //printing the constructed tree
	return 0 ;
}
