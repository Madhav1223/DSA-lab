#include <iostream>
#include "stack.h"
#include <cmath>
using namespace std;

int main()
{
    Stack<float> st{};
    char exp[] = "65*43/+21^-";
    int i = 0;
    try
    {
        while (true)
        {
            if (exp[i] == '\0')
            {
                cout << st.pop();
                break;
            }

            if (isdigit(exp[i])==1)
            {
                cout<<exp[i]<<endl;
                st.push(exp[i]-'0');
            }
            else
            {
                float x = static_cast<float> (st.pop());
                float y = static_cast<float> (st.pop());
                char c = exp[i];
                if (c == '+')
                {
                   
                    cout<<x<<"+"<<y<<endl;
                    st.push(y+x);
                }
                else if (c == '-')
                {
                    st.push(y - x);
                }
                else if (c == '*')
                {
                    st.push(y * x);
                }
                else if (c == '/')
                {
                    st.push(y / x);
                }
                else
                {
                    st.push(pow(y, x));
                }
            }
            i++;
        }
    }
    catch(StackOverFlow)
{
    cout<<"Stack Full";
}
    catch(StackUnderFlow)
{
    cout<<"Stack Empty";
}

    return 0;
}