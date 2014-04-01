#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;



class UnionFind
{
    private:
        vector<long> Sets;
    public:
        UnionFind(long NumElements)
        {
            Sets.assign(NumElements,-1);
        }

        long findSize(long X) const
        {
            if(Sets[X] < 0)
            {
                return -Sets[X];
            }
            else
            {
                return findSize(Sets[X]);
            }
        }
        long find(long X)
        {
            if(Sets[X] < 0)
            {
                return X;
            }
            else
            {
                return Sets[X]=find(Sets[X]);
            }
        }

        void Union(long Root1,long Root2)
        {
            long si=-Sets[Root1];
            long sj=-Sets[Root2];

            if(si<sj)
            {
                Sets[Root1] = Root2;
                Sets[Root2] = -(si+sj);
            }
            else
            {
                Sets[Root2] = Root1;
                Sets[Root1] = -(sj+si);
            }
        }
};

int main()
{
    unsigned TestCases;
    unsigned FriendshipsFormed;
    unsigned long Index;
    string Name1;
    string Name2;
    map<string,unsigned long> Parents;
    vector<long> Sets;

    FriendshipsFormed=0;
    cin>>TestCases;
    for(unsigned i=0;i<TestCases;i++)
    {
        cin>>FriendshipsFormed;
        UnionFind Solution(100000);
        Parents.clear();
        Index=0;

        for(unsigned j=0;j<FriendshipsFormed;j++)
        {
            cin>>Name1>>Name2;
            if(Parents.find(Name1)==Parents.end())
            {
                Parents[Name1]=Index;
                Index++;
            }
            if(Parents.find(Name2)==Parents.end())
            {
                Parents[Name2]=Index;
                Index++;
            }            
            unsigned long ParentName1 = Solution.find(Parents[Name1]);
            unsigned long ParentName2 = Solution.find(Parents[Name2]);
            
            if(ParentName1!=ParentName2)
            {
                Solution.Union(ParentName1,ParentName2);
            }
            cout<<Solution.findSize(ParentName1)<<endl;
        }
    }

    return 0;
}
