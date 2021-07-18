// “Imagination has a great deal to 'do' with winning.”
// “Winning isn’t everything, it’s the only thing.”
#include<iostream>
#include<bits/stdc++.h> 
using namespace std ;
struct node{
    int data ;
    struct node *next ;
};
typedef struct node *lptr ;
lptr insert(){
    int n ;
    lptr L ,T,P ;
    L=new(node);
    P=new(node);
    cin>>(L->data);
    L->next=NULL ;
    P=L ;
    cin>>n ;
    while(n>=0){
        T=new(node);
        T->data=n ;
        T->next=NULL ;
        P->next=T ;
        P=T ;
       cin>>n ;
    }
    return L ;
}
int deletefront(lptr &P){
    int dt=P->data ;
    if(P->next==NULL)P=NULL ;
    else
    P=P->next ;
    return dt; 
}
char winningstrategy(lptr P1,lptr P2){
    int sumA=0,sumB=0,curr, chance=0 ;
    while(P1!=NULL && P2!=NULL){ 
        while(P1!=NULL){
        curr=deletefront(P1);
        sumA+=curr ;
        ++chance ;
        if(P1!=NULL){
            --chance ;
        curr=deletefront(P1); //could be issue use break ;
        sumB+=curr ; }
        }
        while(P2!=NULL){
            if (chance==0){
                curr=deletefront(P2);
                sumA+=curr ;
                ++chance ;
                if(P2!=NULL){
                    --chance ;
                curr=deletefront(P2); //could be issue use break ;
                sumB+=curr ; }
            }
            else{
                curr=deletefront(P2);
                sumB+=curr ;
                --chance ;
                if(P2!=NULL){
                    ++chance ;
                curr=deletefront(P2); //could be issue use break ;
                sumA+=curr ;
                }
            }
    }    }
    if(sumA<sumB)return 'B';
    else return 'A';    
}
void winner(lptr L1 , lptr L2){
    char win1 ,win2;
    win1=winningstrategy(L1,L2);
    win2=winningstrategy(L2,L1);
    if(win1==win2)cout<<win1 ;
    else 
        cout<<"no winning strat";
} 
int main(){
    lptr L1 , L2 ;
    L1=insert();
    L2=insert();
    winner(L1,L2);
    return 0 ;
}

