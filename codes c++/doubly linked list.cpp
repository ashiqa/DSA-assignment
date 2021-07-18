#include<iostream>
#include <bits/stdc++.h> 
using namespace std ;
struct dnode{
	int data ;
	struct dnode* next ;
	struct dnode* prev ;
};
typedef struct dnode* dptr ;
void addfront(dptr &P,int x){
		dptr t ;
		t=new(dnode);
		t->data=x ;
		t->next=P;
		t->prev=NULL;
		P->prev=t;
		P=t;
}
void addend(dptr P,int x){
		dptr T ;
		T=new(dnode);
		T->data=x ;
		T->next=NULL ;
		T->prev=NULL;
		if(P==NULL){
			P=T ;
		}
		else{
		while(P->next!=NULL){
			P=P->next ;
		}
 			T->prev=P;
			P->next=T ;
		}
		}
		
void deletefront(dptr &P){
	if(P==NULL)cout<<"empty";
	else if(P->next==NULL){
		P=NULL ;
	}
	else{
		P=P->next ;	
		P->prev=NULL ;
	}
}
void deleteend(dptr P){
	if(P==NULL)cout<<"empty";
	while(P->next!=NULL){
			P=P->next ;
		}
	
		P=P->prev ;
		P->next=NULL ;
	}

void print(dptr P){
	while(P!=NULL){
		cout<<P->data<<" ";
		P=P->next;
	}
	return ;
}
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
    while(n>=0){
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
dptr find(dptr D,int y){
	while(D!=NULL){
		if(D->data==y)return D ;
		D=D->next;
	}
}
void addbefore(dptr &D,int x ,int y){
	dptr F ,T;
	F=find(D,y);
	T=new(dnode);
	T->data=x ;
	T->next=F ;
	T->prev=F->prev ;
	F->prev->next=T ;
	F->prev=T ;
}
void addafter(dptr D,int x ,int y){
	dptr F ,T;
	F=find(D,y);
	T=new(dnode);
	T->data=x ;
	T->prev=F ;
	T->next=F->next;
	F->next->prev=T ;
	F->next=T ;
}
void del(dptr D , int x){
	dptr F ;
	F=find(D,x);
	F->prev->next=F->next ;
	F->next->prev=F->prev ;
}
dptr partition(dptr l,dptr h,int l1,int h1,int &j){
	dptr index=l ;
	int X=l->data;
	l=l->next ;
	l1=l1+1;
	while(l1<=h1){
		if(l->data<=X){
		l++;l=l->next ;}
		if(h->data>=X){
		h=h->prev ;h1--;}
		if(l->data>=X&&h->data<=X){
			swap(l->data,h->data);
			l=l->next ;l1++;
			h=h->prev ;h1--;
		}
	}
	swap(index->data ,h->data);
	j=h1;
	return h ;
}
void quicksort(dptr l ,dptr h,int l1,int h1){

	int j;
	while(l1<h1){   
		dptr P;
		P=partition(l,h,l1,h1,j);
		quicksort(l,P->prev,l1,j-1);
		quicksort(P->next ,h,j+1 ,h1 );
	}
}
int main(){
	int ch,k ,x,y;
	char cont ;
	dptr D ;
	D=new(dnode);
	D=create();
    print(D);
    cin>>k ;
    addfront(D,k);
    print(D);
    cin>>k ;
    addend(D,k);
    print(D);
    cin>>x>>y ;
    addbefore(D,x,y);
    print(D);
   cin>>x>>y ;
    addafter(D,x,y);
    print(D);
    deletefront(D);
    print(D);
    deleteend(D);
    print(D);
    cin>>k ;
    del(D,k);
    print(D);
    dptr L;
	L=D ;
	int cnt=0 ;
    while(L->next!=NULL){
    	L=L->next;
    	++cnt ;
	}
    quicksort(D,L,0,cnt);
    print(D);
	return 0 ;
}
