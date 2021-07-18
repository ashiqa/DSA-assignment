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
	cout<<endl;
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
void sort(dptr head){
	dptr E=head ;
	dptr D=head ;
	while(E->next!=NULL){
		E=E->next;
	}
	while(D!=E){
		while(D->next!=E){
			if(D->data>D->next->data){
				swap(D->data,D->next->data);
			}
			D=D->next ;
		}
		if(D->data>E->data)swap(D->data,E->data);
		D=head ;
		E=E->prev ;
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
    sort(D);
    print(D);
	return 0 ;
}
