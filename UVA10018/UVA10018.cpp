#include<iostream>
using namespace std;

void reverse_add(unsigned long);
unsigned long reverse_number(unsigned long);
bool is_palindrome(unsigned long);

int main()
{
    unsigned long input;
    unsigned long limit;

    cin>>limit;
    while(limit!=0)
    {
        cin>>input;
        reverse_add(input);
        limit-=1;
    }

    return 0;
}

void reverse_add(unsigned long passed)
{
    unsigned long chain_length=0;
    
    while(!is_palindrome(passed))
    {
        passed+=reverse_number(passed);
        chain_length+=1;
    }
    cout<<chain_length<<" "<<passed<<endl;
}

unsigned long reverse_number(unsigned long passed)
{
    unsigned long passed_reversed=0;
    
    while(passed!=0)
    {
        passed_reversed*=10;
        passed_reversed+=passed%10;
        passed/=10;
    }
    return passed_reversed;
}
bool is_palindrome(unsigned long passed)
{
    bool valid = false;
    unsigned long passed_reversed=reverse_number(passed);

    if(passed==passed_reversed)
    {
        valid=true;
    }
    return valid;
}
