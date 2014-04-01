#include<iostream>
using namespace std;

void display(unsigned long,unsigned long);

int main()
{
    //user input
    unsigned long b1_b,b1_g,b1_c;
    unsigned long b2_b,b2_g,b2_c;
    unsigned long b3_b,b3_g,b3_c;
    unsigned long moves,i,display_result,small;
    
    while(cin>>b1_b>>b1_g>>b1_c>>b2_b>>b2_g>>b2_c>>b3_b>>b3_g>>b3_c)
    {
       //there are 6 combations
       //0:BCG, 1:BGC, 2:CBG, 3:CGB, 4:GBC, 5:GCB

        for(i=0;i<6;i++)
        {
            switch(i)
            {
                case 0://BCG
                    moves=b1_c+b1_g+b2_b+b2_g+b3_b+b3_c;
                    break;
                case 1://BGC
                    moves=b1_g+b1_c+b2_b+b2_c+b3_b+b3_g;
                    break;
                case 2://CBG
                    moves=b1_b+b1_g+b2_c+b2_g+b3_c+b3_b;
                    break;
                case 3://CGB
                    moves=b1_g+b1_b+b2_c+b2_b+b3_c+b3_g;
                    break;
                case 4: //GBC
                    moves=b1_b+b1_c+b2_g+b2_c+b3_g+b3_b;
                    break;
                case 5://GCB
                    moves=b1_c+b1_b+b2_g+b2_b+b3_g+b3_c;
                    break;
            }
            if(small > moves || i==0)
            {
                small=moves;
                display_result=i;
            }
        }
        display(display_result,small);
    }
    
        return 0;
}

void display(unsigned long passed,unsigned long small)
{
    switch(passed)
    {
        case 0://BCG
            cout<<"BCG "<<small<<endl;
            break;
        case 1://BGC
            cout<<"BGC "<<small<<endl;
            break;
        case 2://CBG
            cout<<"CBG "<<small<<endl;
            break;
        case 3://CGB
            cout<<"CGB "<<small<<endl;
            break;
        case 4: //GBC
            cout<<"GBC "<<small<<endl;
            break;
        case 5://GCB
            cout<<"GCB "<<small<<endl;
            break;
    }
}
