#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void reverse_string(string);

int main()
{
   string input;

    while(getline(cin,input))
    {
        reverse_string(input);        
    }
}

void reverse_string(string passed)
{
    string::iterator lower_it=passed.begin();//start of a word
    string::iterator upper_it=find(passed.begin(),passed.end(),' ');//end of a word

    while(upper_it!=passed.end())
    {
        reverse(lower_it,upper_it);
        lower_it=upper_it+1;
        upper_it=find(lower_it+1,passed.end(),' ');
    }
    reverse(lower_it,upper_it);
    cout<<passed<<endl;
}
