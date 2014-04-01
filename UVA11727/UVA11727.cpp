#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void display(unsigned case_number,unsigned salary);

int main()
{
    unsigned test_cases=0;
    unsigned i=0;
    vector<unsigned> salary(3,0);

    cin>>test_cases;

    while(test_cases!=i)
    {
        cin>>salary[0]>>salary[1]>>salary[2];
        sort(salary.begin(),salary.end());
        i+=1;
        display(i,salary[1]);
        
    }
}

void display(unsigned case_number, unsigned salary)
{
    cout<<"Case "<<case_number<<": "<<salary<<endl;
}
