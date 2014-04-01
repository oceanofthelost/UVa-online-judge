#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct Letters
{
    char letter;
    int frequency;
};

void CalculateFrequency(Letters*,string);
void PrintFrequency(Letters*);
bool SortByFrequency(const Letters&, const Letters&);

int main()
{
    unsigned lines;
    string input;
    Letters solution[26];
    Letters* ptrsolution=solution;

    for(int i=0;i<26;i++)
    {
        solution[i].letter=(char)(i+'A');
        solution[i].frequency=0;
    }

    cin>>lines;
    //ignores the end line. sets up the input
    //for the next cases. 
    cin.get();

    while(getline(cin,input))
    {
        CalculateFrequency(ptrsolution,input);
    }
    
    PrintFrequency(ptrsolution);
}

void CalculateFrequency(Letters* PassedArray,string PassedString)
{
    for(unsigned i=0;i<PassedString.size()-1;i++)
    {
        if(PassedString[i]>='A' && PassedString[i]<='Z')
        {
            PassedArray[PassedString[i]-'A'].frequency+=1;
        }
        else if(PassedString[i]>='a' && PassedString[i]<='z')
        {
            PassedArray[PassedString[i]-'a'].frequency+=1;
        }
    }
}

void PrintFrequency(Letters* PassedArray)
{
    sort(PassedArray, PassedArray+26,SortByFrequency);
    
    int i=0;
    while(PassedArray[i].frequency!=0)
    {
        cout<<PassedArray[i].letter<<" "<<PassedArray[i].frequency<<endl;
        i+=1;
    }
}

bool SortByFrequency(const Letters& lhs, const Letters& rhs)
{
    bool result;
    if(lhs.frequency==rhs.frequency)
    {
        return (unsigned)lhs.letter < (unsigned)rhs.letter;
    }
    else
    {
        result=lhs.frequency > rhs.frequency;
    }
    return result; 
}
