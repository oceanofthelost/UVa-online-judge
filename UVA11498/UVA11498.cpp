#include<iostream>
using namespace std;


int main()
{
    unsigned queries;
    int N,M;
    int X,Y;
    
    while(cin>>queries)
    {
        if(queries==0)
        {
            break;
        }
        else
        {
            cin>>N>>M;
            for(unsigned i=0;i<queries;++i)
            {
                cin>>X>>Y;
                if(X==N || M==Y)
                {
                    cout<<"divisa"<<endl;
                }
                else if(X<N && Y>M)
                {
                    cout<<"NO"<<endl;
                }
                else if(X>N && Y>M)
                {
                    cout<<"NE"<<endl;
                }
                else if(X>N && Y<M)
                {
                    cout<<"SE"<<endl;
                }
                else if(X<N && Y<M)
                {
                    cout<<"SO"<<endl;
                }
            }
        }
    }
    return 0;
}
