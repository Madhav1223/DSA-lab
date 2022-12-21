#include<iostream>
#include "stack.h"
using namespace std;

int main()
{
  Stack<char> st{};
  char exp[] = "(mm(jgh(shs)))";
  int i{0};
  try{
    while(true)
    {
        char tmp = exp[i];
        if(st.isEmpty()&&  tmp == ')')
        {
            cout<<"No Matching Parenthesis found";
            exit(1);
        }
        if(!st.isEmpty()&&  tmp == ')')
        {
            st.pop();
           
        }
        if(tmp =='(')
        {
            st.push(tmp);
        }
        if(tmp == '\0')
        {
            if(st.isEmpty())
            {
                break;
            }
            if(!st.isEmpty())
            {
                cout<<"No Matching Parenthesis Found";
                exit(1);
            }
        }

i++;
    }
    cout<<"Parenthesis Matched";}
    catch(...)
    {
        cout<<"Error";
    }
    return 0;
}