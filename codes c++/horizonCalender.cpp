#include <iostream>

using namespace std;
enum month{January,February,March,April,May,June,July,August,September,October,November,December};
int main()
{
    int startday=2,days ;
    for(int i=January ; i<December ;++i){
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
        cout<<"Mon Tue Wed Thu Fri Sat Sun"<<endl ;
        for(int j=0;j<startday;++j)
        {
            cout<<"    ";
        }
        for(int i=1 ; i<=days;++i){
            if(startday<7)
            {cout<<i<<"   ";++startday;}
            else{
                startday=0 ;
                cout<<endl ;
                cout<<i<<"   ";++startday;;
            }
        }
        cout<<endl ;
    }

    return 0;
}
