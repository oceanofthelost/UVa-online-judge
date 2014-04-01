#include<iostream>
#include<string>
using namespace std;

struct record
{
    string maker;
    unsigned lowPrice;
    unsigned highPrice;
};


unsigned buildDatabase(record* Database)
{
    unsigned databaseSize;
    unsigned lowPrice;
    unsigned highPrice;
    string maker;
    record temp;

    cin>>databaseSize;
    for(unsigned i = 0; i<databaseSize;i++)
    {
        cin>>maker>>lowPrice>>highPrice;
        temp.maker      = maker;
        temp.lowPrice   = lowPrice;
        temp.highPrice  = highPrice;
        Database[i]=temp;
    }

    return databaseSize;
}

void startQuery(record* Database, unsigned databaseSize)
{
    unsigned numberofQuery=0;
    unsigned Query;
    unsigned i;
    unsigned j;
    unsigned count;
    string maker;
    cin>>numberofQuery;

    for(i = 0;i < numberofQuery; i++)
    {
        cin>>Query;
        count=0;
        for(j = 0;j<databaseSize;j++)
        {
            if(Database[j].lowPrice <= Query && Query <= Database[j].highPrice)
            {
                count++;
                maker=Database[j].maker;
            }
        }
        if(count==1)
        {
            cout<<maker<<endl;
        }
        else
        {
            cout<<"UNDETERMINED"<<endl;
        }
    }
}

int main()
{
    unsigned testCases = 0;
    unsigned databaseSize=0;
    record* Database = new record[10000];
    cin>>testCases;

    for(unsigned i = 0; i<testCases;i++)
    {
       databaseSize = buildDatabase(Database);
       startQuery(Database,databaseSize);
       if(i!=testCases-1)
       {
            cout<<endl;
       }
    }
    
    delete[] Database;
    return 0;
}
