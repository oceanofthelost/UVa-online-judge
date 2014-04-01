#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    priority_queue<int,vector<int>,greater<int> > MinQueue;
    unsigned NumberOfIntegers;
    unsigned InputNumber;
    unsigned Number1;
    unsigned Number2;
    unsigned Cost=0;

    cin>>NumberOfIntegers;
    while(NumberOfIntegers!=0)
    {
        for(unsigned i=0;i<NumberOfIntegers;++i)
        {
            cin>>InputNumber;
            MinQueue.push(InputNumber);
        }
        while(!MinQueue.empty())
        {
            Number1=MinQueue.top();
            MinQueue.pop();
            if(MinQueue.size()>=1)
            {
                Number2=MinQueue.top();
                MinQueue.pop();
                Cost=Cost+Number1+Number2;
                MinQueue.push(Number1+Number2);
            }
        }
        cout<<Cost<<endl;
        cin>>NumberOfIntegers;
        Cost=0;
    }

    return 0;
}
