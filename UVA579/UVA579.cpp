#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

//we can use a simple formula. Description is found here 
//http://en.wikipedia.org/wiki/Clock_angle_problem
//
//minute hand travels at 6 degrees per minute (360 degrees / 60 minutes)
//hour hand travels at 0.5 degrees per minute (360 degrees / 12 hours) = (360 degrees / 720 minutes);


int main()
{
    unsigned Hour;
    unsigned Minute;
    char Colon;
    double ThetaHour;
    double ThetaMinute;
    double Solution;
    
    while(cin>>Hour>>Colon>>Minute)
    {
        if(Hour!=0 || Minute!=0)
        {
            //implementing algo on wikipedia
            ThetaHour=0.5*(60*Hour+Minute);
            ThetaMinute=6*Minute;
            Solution=abs(ThetaHour-ThetaMinute);
            //we want our degrees in the range of 0 to 180. the algo 
            //calculates degrees in the range 0 - 360. so we need to 
            //to subract solution from 360 if its over 180 to get the 
            //correct range of degrees. 
            Solution=Solution>=180?360-Solution:Solution;
            cout<<fixed<<setprecision(3)<<showpoint<<Solution<<endl;
        }
    }
    return 0;
}
