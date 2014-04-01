#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    unsigned TestCases;
    string Input;
    bool NewLine=false;

    cin>>TestCases;
    cin.get();

    for(unsigned i=0;i<TestCases;++i)
    {
        
        getline(cin,Input);
        if(NewLine)
        {
            cout<<endl;
        }

        while(!Input.empty())
        {
            replace(Input.begin(),Input.end(),'0','O');
            replace(Input.begin(),Input.end(),'1','I');
            replace(Input.begin(),Input.end(),'2','Z');
            replace(Input.begin(),Input.end(),'3','E');
            replace(Input.begin(),Input.end(),'4','A');
            replace(Input.begin(),Input.end(),'5','S');
            replace(Input.begin(),Input.end(),'6','G');
            replace(Input.begin(),Input.end(),'7','T');
            replace(Input.begin(),Input.end(),'8','B');
            replace(Input.begin(),Input.end(),'9','P');
            
            cout<<Input<<endl;
            NewLine=true;
            getline(cin,Input);
        }
    }
}
