#include<iostream>
#include<stdint.h>
using namespace std;

int main()
{
    int32_t input,b1,b2,result;

    while(cin>>input)
    {
        b1=(input<< 24 &0xFF000000) | (input>> 24 &0x000000FF);
        b2=(input<< 8  &0x00FF0000) | (input>>  8 &0x0000FF00);
        result=b1|b2;
        cout<<input<<" converts to "<<result<<endl;
    }
    return 0;
}
