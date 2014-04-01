#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    double n,p;
   
    cout.precision(0);
    while(cin>>n>>p)
    {
        if(n>=1 && p >=1)
        {
            cout<<fixed<<pow(p,1/n)<<endl;
        }
    }

       return 0;
}
