
#include "stack.h"
using namespace std;
int main()
{
    try{
    Stack<char>st{};
     char exp[]="a*b+c/d-e^f";
    string pos = " ";
   pos = toPostfix(st,exp,false,11);
     cout<<"The value is:  "<<pos;
    }
    catch(...)
    {
        cout<<"Error";
    }

    return 0;
}
