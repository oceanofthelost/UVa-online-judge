#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<string>
using namespace std;

struct Contestant
{
    unsigned ContestantNumber;
    vector<bool> Problems;
    vector<unsigned> Penalty;
    unsigned Time; 
    unsigned ProblemsSolved;
};

bool SortByContestant(const Contestant&, const Contestant&);


int main()
{
    unsigned TestCases;
    unsigned ContestantNumber;
    unsigned Problem;
    unsigned Time;
    char L;
    //using the 11th spot to check if they submitted a problem
    const vector<bool> FalseArray(11,false);
    const vector<unsigned> PenaltyArray(11,0);
    bool newline=false;
    string Input;
    Contestant Solution[100];

    cin>>TestCases;
    cin.get();
    cin.get();
    for(unsigned i=0;i<TestCases;++i)
    {
        for(unsigned j=0;j<100;++j)
        {
            Solution[j].ContestantNumber=j+1;
            Solution[j].Problems=FalseArray;
            Solution[j].Penalty=PenaltyArray;
            Solution[j].Time=0;
            Solution[j].ProblemsSolved=0;
        }
        if(newline==true)
        {
            cout<<endl;
        }
        while(getline(cin,Input))
        {
            if(Input.empty())
            {
                break;
            }
            stringstream tempstream(Input);
            tempstream>>ContestantNumber>>Problem>>Time>>L;
            ContestantNumber-=1;
            Solution[ContestantNumber].Problems[10]=true;
            switch(L)
            {
                case 'C':
                    if(!Solution[ContestantNumber].Problems[Problem])
                    {
                        Solution[ContestantNumber].Problems[Problem]=true;
                        Solution[ContestantNumber].Time+=Time+20*Solution[ContestantNumber].Penalty[Problem];
                        Solution[ContestantNumber].ProblemsSolved+=1;
                    }
                    break;
                case 'I':
                    if(!Solution[ContestantNumber].Problems[Problem])
                    {
                        Solution[ContestantNumber].Penalty[Problem]+=1;  
                    }
                     break;                    
            }
        }
        sort(Solution,Solution+100,SortByContestant);
        for(unsigned j=0;j<100;j++)
        {
            if(Solution[j].Problems[10]==1)
            {
                cout<<Solution[j].ContestantNumber<<" ";
                cout<<Solution[j].ProblemsSolved<<" ";
                cout<<Solution[j].Time<<endl;
            }
        }
        newline=true;
    }   
    return 0;
}

bool SortByContestant(const Contestant& lhs, const Contestant& rhs)
{
    if(lhs.ProblemsSolved==rhs.ProblemsSolved)
    {
        if(lhs.Time==rhs.Time)
        {
            return lhs.ContestantNumber < rhs.ContestantNumber;   
        }
        else
        {
            return lhs.Time<rhs.Time;
        }
    }
    else
    {
        return lhs.ProblemsSolved>rhs.ProblemsSolved;
    }
}
