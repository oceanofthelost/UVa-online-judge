#include<iostream>
#include<array>
using namespace std;

int main()
{
    unsigned NumberOfAges;
    unsigned short PersonAge;
    array<short,100> Age;
    bool ProperOutput = false;

    cin>>NumberOfAges;
    //cout<<"we have this many ages: "<<NumberOfAges<<endl;
    while(NumberOfAges!=0)
    {
        Age.fill(0);
        for(unsigned i = 0; i<NumberOfAges;i++)
        {
            //cout<<i<<endl;
            cin>>PersonAge;
            Age[PersonAge]++;
        }
        for(unsigned j = 0;j<Age.size();j++)
        {
            while(Age[j]!=0)
            {
                if(!ProperOutput)
                {
                    cout<<j;
                    Age[j]--;
                    ProperOutput = true;
                }
                else
                {
                    cout<<" "<<j;
                    Age[j]--;
                }
            }
        }
        cout<<endl;
        ProperOutput = false;
        cin>>NumberOfAges;
    }

    return 0;
}
