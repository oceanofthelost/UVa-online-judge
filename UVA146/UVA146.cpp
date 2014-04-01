#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void valid_or_permutation(string); 

int main()
{
    string input;

    cin>>input;

    while(input!="#")
    {
        valid_or_permutation(input); 
        cin>>input;
    }

    return 0;
}

void valid_or_permutation(string passed)
{
    if(next_permutation(passed.begin(),passed.end()))
    {
        cout<<passed<<endl;
    }
    else
    {
        cout<<"No Successor"<<endl;
    }
}
