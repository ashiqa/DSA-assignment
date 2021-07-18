#include <iostream>

using namespace std;
enum month{January,February,March,April,May,June,July,August,September,October,November,December};
enum day{Mon,Tue,Wed,Thu,Fri,Sat,Sun};
int main()
{
    int startweek=2,days ;
    for(int i=January ; i<=December ;++i){
        switch(i){
            case 0:cout<<"January"<<endl ;days=31 ;break ;
            case 1:cout<<"February"<<endl;days=29 ;break ;
            case 2:cout<<"March"<<endl;days=31 ;break ;
            case 3:cout<<"April"<<endl;days=30 ;break ;
            case 4:cout<<"May"<<endl;days=31 ;break ;
            case 5:cout<<"June"<<endl;days=30 ;break ;
            case 6:cout<<"July"<<endl;days=31 ;break;
            case 7:cout<<"August"<<endl;days=31 ;break ;
            case 8:cout<<"September"<<endl;days=30 ;break ;
            case 9:cout<<"October"<<endl;days=31 ;break ;
            case 10:cout<<"November"<<endl;days=30 ;break ;
            case 11:cout<<"December"<<endl;days=31 ;break ;
        } 
        
        int d ,key=1;
        for(int i=Mon ; i<=Sun;++i){
           switch(i){
               case 0 : cout<<"Mon "; break ;
               case 1 : cout<<"Tue "; break ;
               case 2 : cout<<"Wed "; break ;
               case 3 : cout<<"Thu "; break ;
               case 4 : cout<<"Fri "; break ;
               case 5 : cout<<"Sat "; break ;
               case 6 : cout<<"Sun "; break ;
           }
           if(i<startweek){
               cout<<"  ";
               d=7-startweek+i+1 ;
               while(d<=days){cout<<d<<" ";
			    if(d==days){
			    	if(i==6)startweek=0 ;
				}
				else startweek=i+1;
				d+=7;
           }}
           else{
               
               d=key ;
               while(d<=days){cout<<d<<" ";
                  if(d==days){
			    	if(i==6)startweek=0 ;
				}
				else startweek=i+1;
				d+=7;
               }
               ++key;
           }
           cout<<endl ;
        }
        cout<<endl ;
    }

    return 0;
}

