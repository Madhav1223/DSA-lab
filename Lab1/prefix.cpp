#include<iostream>
#include<cmath>
#include "stack.h"
using namespace std;
int main()
{
    try{
    Stack<char>st{};
     char exp[]="a*b+c/d-e^f";
    string pos = " ";
    string pre=" ";
   pos = toPostfix(st,exp,true,11);
       for(int i=pos.length()-1; i>=0; i--){
        //concatenate characters to the reverse
        pre += pos[i];  
    }
     cout<<"The value is:  "<<pre;
    }
    catch(...)
    {
        cout<<"Error";
    }

    return 0;
}