#include<iostream>
using namespace std ;

int step=0,n,amount;
struct j{
	int nu ;
	int cap;
}l,m,s;
int jug(j ,j,j);
int main(){

	cout<<"enter n ";
	cin>>n ;
	cout<<"enter amount ";
	cin>>amount ;
	l.nu=4*n+4 ;
    s.nu=2*n+1 ;
    m.nu=2*n+3   ;
    l.cap=l.nu ;
	jug(l,m,s);
	cout<<"no. of steps "<<step ;
	return 0 ;
	
}
int jug( j larg , j mid , j smol){

	if(larg.cap==amount||smol.cap==amount||mid.cap==amount)
	return 0 ;
	else{
		++step ;
			cout<<"transfer from "<<larg.nu<<" to "<<smol.nu<<endl ;
			if(larg.nu>smol.nu)
			smol.cap=smol.nu ;
			else
			smol.cap=larg.cap ;
			larg.cap=larg.cap-smol.cap ;
return jug(smol,larg,mid)+jug(larg, mid,smol)+jug(mid,larg,smol);
}
	
	
}
