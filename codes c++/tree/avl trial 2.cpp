#include<iostream>
using namespace std ;

struct avlnode
{	int data;
	struct avlnode *lc;
	struct avlnode *rc;
};
typedef struct avlnode *avptr ;
int h ;
int htcalc(avptr T)
{   if(T==NULL)return 0 ;
	 h =max(htcalc(T->lc), htcalc(T->rc))+ 1;
	return h;
}
int diff(avptr T)
{
	int lh = htcalc(T->lc);
	int rh = htcalc(T->rc);
	int hdiff = lh- rh;
	return hdiff;
}
avptr rr_rotation(avptr T)
{
	avptr trc;
	trc = T->rc;
	T->rc = trc->lc;
	trc->lc =T;
	return trc;
}
avptr ll_rotation(avptr T)
{
	avptr tlc;
	tlc = T->lc;
	T->lc = tlc->rc;
	tlc->rc = T;
	return tlc;
}
avptr lr_rotation( avptr T)
{
	avptr tlc;
	tlc = T->lc;
	T->lc = rr_rotation(tlc);
	return ll_rotation(T);
}
avptr rl_rotation(avptr T)
{
	avptr trc;
	trc = T->rc;
	T->rc = ll_rotation(trc);
	return rr_rotation(T);
}
void insert(avptr &T, int val)
{
	if(T == NULL)
	{   T = new(avlnode);
		T->data = val;
		T->lc = NULL;
		T->rc = NULL;
		return ;
	}
	else if (val < T->data)insert(T->lc, val);
	else if (val >= T->data)insert(T->rc, val);
	
	int hdiff=diff(T);
	if (hdiff>1)
	{	if (diff(T->lc)>0)T=ll_rotation(T);
		else T=lr_rotation(T);
	}
	else if (hdiff<-1)
	{   if (diff(T->rc)>0)T=rl_rotation(T);
		else T= rr_rotation(T);
	}
}
void inorder(avptr T){
	if(T==NULL)return ;
	cout<<T->data<<" " ;
	inorder(T->lc);
	inorder(T->rc);
}
int main(){
	avptr T ;
	T=NULL ;
	int k ;
	cin>>k ;
	while(k!=-1){
		insert(T,k);
		cin>>k;
	}
	inorder(T);
	return 0 ;
}
