#include<iostream>
using namespace std;

int main()
{
    unsigned long long hashmat_army=0;
    unsigned long long other_army=0;
    
    while(cin>>hashmat_army>>other_army)
    {
        if(hashmat_army < other_army)
        {
            cout<<other_army-hashmat_army<<endl;
        }
        else
        {
            cout<<hashmat_army-other_army<<endl;
        }
    }

    return 0;
}
