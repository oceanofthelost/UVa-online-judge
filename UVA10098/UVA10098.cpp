#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string input;
    unsigned cases;

    cin>>cases;
    for(unsigned i=0; i<cases;i++)
    {
        cin>>input;
        sort(input.begin(),input.end());
        
        do
        {
            cout<<input<<endl;
        }while(next_permutation(input.begin(),input.end()));
        cout<<endl;
    }
    return 0;
}
