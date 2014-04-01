#include<iostream>
using namespace std;

int chain(int);

int main()
{
    int lower_bound,lower_bound_bkp,upper_bound,upper_bound_bkp,max,chain_length,i;
    
    
    while(cin>>lower_bound>>upper_bound)
    {
        max=0;

        if(lower_bound > upper_bound)
        {
            lower_bound_bkp=lower_bound;
            upper_bound_bkp=upper_bound;

            lower_bound=upper_bound_bkp;
            upper_bound=lower_bound_bkp
            
        }
        else
        {
            lower_bound_bkp=lower_bound;
            upper_bound_bkp=upper_bound;
        }
        for(i = lower_bound;i<=upper_bound;i++)
        {
            chain_length=chain(i);
            if(max<chain_length)
            {
                max=chain_length;
            }
        }

       cout<<lower_bound_bkp<<" "<<upper_bound_bkp<<" "<<max<<endl;
    }
}

int chain(int passed)
{
    int chain_length=1;
    while(passed != 1)
    {
        if(passed%2==0)
        {
            passed/=2;
        }
        else
        {
            passed=3*passed+1;
        }
        chain_length++;
    }
    return chain_length;
}
