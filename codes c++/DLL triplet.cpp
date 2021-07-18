#include<iostream>
#include <bits/stdc++.h> 
using namespace std ;
struct dnode{
	int data ;
	struct dnode* next ;
	struct dnode* prev ;
};
typedef struct dnode* dptr ;
dptr create(){
    int n ;
    dptr L ,T,P ;
    L=new(dnode);
    P=new(dnode);
    cin>>(L->data);
    L->next=NULL ;
    L->prev=NULL;
    P=L ;
    cin>>n ;
    while(n!=-1){
        T=new(dnode);
        T->data=n ;
        T->next=NULL ;
        T->prev=P ;
        P->next=T ;
        P=T ;
       cin>>n ;
    }
    return L ;
}

int main(){
	int s,dobsum ;
	dptr D,head,h,l,End ;
	D=create();
	cin>>s ;
	h=D ;
	while(h->next!=NULL){
		h=h->next ;
	}
	End=h ;
    for(head=D;head->next!=NULL;head=head->next){
		l=D;
		if(l==head)l=l->next ;
		h=End ;
		dobsum=s-(2*(head->data));
		while(l!=NULL&&h!=NULL&&l!=h && h->next!=l){
			if(l->data+h->data==dobsum){
			    int x=head->data;
			    int y=l->data ;
			    int z=h->data ;
				cout<<x<<" "<<y<<" "<<z ;
				cout<<endl ;
				l=l->next ;
				if(l==head)l=l->next ;     //if l is same as head go to next
				h=h->prev ;if(h==head)h=h->prev ;
			}
			else if((l->data+h->data)<dobsum){
				l=l->next ;
				if(l==head)l=l->next ;
			}
			else if((l->data+h->data)>dobsum){
				h=h->prev ;if(h==head)h=h->prev ;
			}
		}
	}
	return 0 ;
}







