#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int Array[10000];
    int NumbersInArray;
    int Input;

    NumbersInArray=0;
    while(cin>>Input)
    {
        Array[NumbersInArray]=Input;
        NumbersInArray++;   
        sort(Array,Array+NumbersInArray);
            
        
        if(NumbersInArray%2!=0) //numbers are odd
        {
            cout<<Array[NumbersInArray/2]<<endl;
        }
        else //numbers are even
        {
            int Index1=NumbersInArray/2;
            int Index2=NumbersInArray/2-1;
            int Result=(Array[Index1]+Array[Index2])/2;

            cout<<Result<<endl;
        }
    }
    return 0;
}
