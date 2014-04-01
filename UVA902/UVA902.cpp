#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

bool compare(const pair<string,int>&,const pair<string,int>&);

int main()
{
    int PasswordLength;
    string Text;
    string Password;
    map<string,int> Result;
    map<string,int>::iterator ptrMap;

    while(cin>>PasswordLength>>Text)
    {
        Result.clear();
        for(string::iterator ptrString=Text.begin();ptrString!=Text.end()-PasswordLength;++ptrString)
        {
            Password.assign(ptrString,ptrString+PasswordLength);
            if(Result.find(Password)!=Result.end())
            {
                Result[Password]++;
            }
            else
            {
                Result[Password]=1;
            }
        }
        
        ptrMap=max_element(Result.begin(),Result.end(),compare);
        cout<<ptrMap->first<<endl;
    }
    
    return 0;
}

bool compare(const pair<string,int>& lhs,const pair<string,int>& rhs)
{
    return lhs.second < rhs.second;
}
