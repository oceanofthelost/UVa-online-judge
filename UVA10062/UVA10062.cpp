#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct Characters
{
    unsigned ASCII;
    unsigned frequency;
};

bool SortByFrequency(const Characters&, const Characters&);

int main()
{
    //since we know that we are stroing ASCII values
    //in the range of 32 to 127 we can use an offset of
    //32 in all our calculations. By using the offset
    //we create a smaller array.
    const unsigned Offset=32;
    Characters Solution[96];
    int Workaround=0;
    string Input;
    string::iterator it;



    while(getline(cin,Input))
    {
        if(Workaround!=0)
        {
            cout<<endl;
        }
        for(int j=0;j<96;j++)
        {
            Solution[j].frequency=0;
            Solution[j].ASCII=j+Offset;
        }

        for(it=Input.begin();it!=Input.end();++it)
        {
            if(*it>=(char)32 && *it<=(char)127)
            {
                Solution[(unsigned)*it-Offset].frequency++;
            }
        }

        sort(Solution,Solution+96,SortByFrequency);
        for(int i=0;i<96;++i)
        {
            if(Solution[i].frequency>0)
            {
                cout<<Solution[i].ASCII<<" "<<Solution[i].frequency<<endl;
            }
        }
        Workaround++;
    }
    return 0;
}

bool SortByFrequency(const Characters& lhs, const Characters& rhs)
{
    if(lhs.frequency == rhs.frequency)
    {
        return lhs.ASCII > rhs.ASCII;
    }
    else
    {
        return lhs.frequency < rhs.frequency;
    }
}
