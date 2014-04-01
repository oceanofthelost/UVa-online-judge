#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct Letters
{
    char letter;
    unsigned frequency;
};

bool SortByFrequency(const Letters&, const Letters&);
void PrintFrequency(Letters*);

int main()
{
    Letters Solution[26];
    int TestCases;
    string Input;
    string::iterator it;

    cin>>TestCases;
    cin.get();
    for(int i=0;i<TestCases;++i)
    {
        getline(cin,Input);
        
        for(int i=0;i<26;++i)
        {
            Solution[i].letter=(char)(i+'a');
            Solution[i].frequency=0;
        }

        for(it=Input.begin();it!=Input.end();++it)
        {
            if(*it>='a' && *it<='z')
            {
                Solution[(unsigned)(*it-'a')].frequency++;       
            }
            else if(*it>='A' && *it<='Z')
            {
                Solution[(unsigned)(*it-'A')].frequency++;
            }
        }
        PrintFrequency(Solution);
    }
    
    return 0;
}

void PrintFrequency(Letters* Passed)
{
    sort(Passed,Passed+26,SortByFrequency);
    unsigned max=Passed[0].frequency;

    for(int i=0;i<26;++i)
    {
       // cout<<Passed[i].letter<<"\t"<<Passed[i].frequency<<endl;
        if(Passed[i].frequency!=max)
        {
            break;
        }
        else
        {
            cout<<Passed[i].letter;
        }
    }
    cout<<endl;
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
