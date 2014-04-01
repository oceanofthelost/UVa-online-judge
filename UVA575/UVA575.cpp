#include<iostream>
#include<string>
using namespace std;

unsigned long skew_to_decimal(string);

int main()
{
    string input;
    string exit_case("0");
     
    cin>>input;
    while(input!=exit_case)
    {
       cout<<skew_to_decimal(input)<<endl;;
        
        cin>>input;
    }

    return 0;
}

unsigned long skew_to_decimal(string passed)
{
    unsigned long power_of_2=2;
    unsigned long result=0;
    unsigned i;
    
    for(i=passed.size();i!=0;--i)
    {
        result+=((unsigned long)passed[i-1]-'0')*(power_of_2-1);
        power_of_2*=2;
    }
    return result;
}









