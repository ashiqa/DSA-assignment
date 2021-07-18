#include<iostream>
#include<cstring>
using namespace std ;

struct cricket{
	char name[10];
	char team[30];
	int batavg ;
};
int main(){
	cricket player[5];
	char t[10][30];
	int c=0;
	for(int i=0 ;i<5;++i){
		cout<<"enter name";
		cin>>player[i].name ;
		cout<<"enter team name";
		cin>>player[i].team;
		cout<<"batting average";
		cin>>player[i].batavg ;
	}
 strcpy(t[0],player[0].team) ;
	
	for(int j=0 ; j<5 ;++j){
	if(strcmp(player[j].team,t[0])==0)
	{cout<<player[j].team ;
		cout<<player[j].name ;
		cout<<"batting average";
		cout<<player[j].batavg ;
	}
	else 
	strcpy(t[++c],player[j].team)	;
	for(;c>0;--c)
	{ cout<<t[c]<<"\n";
		for(int i=0 ;i<5 ;++i){
			if(strcmp(t[c],player[i].team)==0)
				cout<<player[i].name<<"\n" ;
				}
	}
	}
	
	return 0 ;
}
