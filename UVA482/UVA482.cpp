#include<iostream>
#include<vector>
#include<string>
using namespace std;

void display(const vector<string>&);

int main()
{
    vector<unsigned> index;
    string input_values;
    unsigned input_index;
    unsigned cases;
    unsigned i;
    unsigned j;
 
    cin>>cases;
    for(i=0;i<cases;i++)
    {
        //these two lines take care of the neline
        //character after each input set. 
        getline(cin,input_values);
        cin.ignore();
        
        if(i!=0)
        {
            cout<<endl;
        }
        do
        {
            cin>>input_index;
            index.push_back(input_index);
        }while(cin.get()!='\n');
        vector<string> values(index.size(),"0");

        for(j=0;j<index.size();j++)
        {
            cin>>input_values;
            values[index[j]-1]=input_values;
        }
        display(values);
        index.clear();
        values.clear();
    }

    return 0;
}


void display(const vector<string>& passed)
{
   for(vector<string>::const_iterator it=passed.begin();it!=passed.end();it++)
    {
        cout<<*it<<endl;
    }
}
