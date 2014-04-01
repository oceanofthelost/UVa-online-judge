#include<iostream>
#include<string>
using namespace std;

int main()
{
    string input;
    bool found_beg_quote=false;
    unsigned i;


    while(getline(cin,input))
    {
        for(i=0;i<input.size();i++)
        {
            if(input[i]=='"' and found_beg_quote==false)
            {
                found_beg_quote=true;
                cout<<"``";
            }
            else if(input[i]=='"' and found_beg_quote==true)
            {
                found_beg_quote=false;
                cout<<"''";
            }
            else
            {
                cout<<input[i];
            }
        }
        cout<<endl;
    }

    return 0;
}
