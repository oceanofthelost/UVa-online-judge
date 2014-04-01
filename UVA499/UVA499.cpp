#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct Letters
{
    char letter;
    unsigned frequency;
};

void CalculateFrequency(Letters*,string);
void PrintFrequency(Letters*);
bool SortByFrequency(const Letters&, const Letters&);

int main()
{
    string Input;
    Letters Solution[52];

    while(getline(cin,Input))
    {
        CalculateFrequency(Solution,Input);
        PrintFrequency(Solution);
    }

    return 0;
}

void CalculateFrequency(Letters* PassedArray,string PassedString)
{
    string::iterator it;

    for(unsigned i=0;i<52;++i)
    {
        if(i<26)
        {
            PassedArray[i].letter=(char)(i+'a');
        }
        else
        {
            //39 is the offset from i to get the upper case in the array
            PassedArray[i].letter=(char)(i+39);
        }
        PassedArray[i].frequency=0;
    }
    for(it=PassedString.begin();it!=PassedString.end();++it)
    {
        if(*it>='A' && *it<='Z')
        {
            PassedArray[(unsigned)*it-39].frequency++;
        }
        else if(*it>='a' && *it<='z')
        {
            PassedArray[(unsigned)*it-'a'].frequency++;
        }
    }
}

void PrintFrequency(Letters* PassedArray)
{
    sort(PassedArray, PassedArray+52,SortByFrequency);
    unsigned max=PassedArray[0].frequency;

    for(unsigned i=0;i<52;++i)
    {
        if(PassedArray[i].frequency==max)
        {
            cout<<PassedArray[i].letter;
        }
        else
        {
            break;
        }
    }
    cout<<" "<<max<<endl;
}

bool SortByFrequency(const Letters& lhs, const Letters& rhs)
{
    if(lhs.frequency==rhs.frequency)
    {
        return (unsigned)lhs.letter < (unsigned)rhs.letter;
    }
    else
    {
        return lhs.frequency > rhs.frequency;
    }
}
