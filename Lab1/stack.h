#include<iostream>
using namespace std;
#pragma once
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
class StackUnderFlow{};
class StackOverFlow{};
template<class T = char>
class Stack
{
private:
    int top;
    T arr[30];
public:
    Stack():top{-1} {}
    void push(T data)
    {
        if(top == 29)
        {
        throw StackOverFlow{};
        }
        arr[++top] = data;
    }
    T pop()
    {
        if(top == -1)
        {
            throw StackUnderFlow{};
            exit(1);
        }
         return arr[top--] ;
    }
    T peek()
    {
        return arr[top];
    }
    bool isEmpty()
    {
        return (top ==-1);
    }
;
    
};

string toPostfix(Stack<char> &st,char exp[] ,bool prefix, int size) {
    string pos = " ";
    int i =0;
    if(prefix)
    {
        int start=0;
        int end = size-1;
        
    while ( start< end)
    {
        int temp = exp[start];
        exp[start] = exp[end];
        exp[end] = temp;
        start++;
        end--;
    }
    
    }
        while(true)
    {
        if(exp[i]=='\0')
        { 
            while(true)
            {
                if (st.isEmpty())
                {
                    break;
                }
                pos+= st.pop();
            }
			break;
        }
        if(st.isEmpty() && exp[i]==')'||prefix && st.isEmpty() && exp[i]=='(')
        {
            cout<<"Invalid Equation ";
            exit(1);
        }
        if(isalpha(exp[i])|| isdigit(exp[i]))
        {
            
            pos+=exp[i];
        }
        else if(exp[i]=='(' || prefix && exp[i]==')')
        {
            st.push(exp[i]);
        }
        else if(!st.isEmpty()&& exp[i]==')'|| prefix && !st.isEmpty()&& exp[i]=='(')
        {
            while (true)
            {
                if(st.peek()=='(' || prefix && st.peek() ==')')
                {
                    st.pop();
                    break;
                }
                pos+=st.pop();
            }
            
        }
        else {
			if(st.isEmpty())
            {
                st.push(exp[i]);
            }
			else
            {
                char StackChar = st.peek();
                if(StackChar =='('|| prefix && StackChar ==')')
                {
                    st.push(exp[i]);
                }
                else {
                    if (prec(exp[i])>prec(StackChar))
                    {
                        st.push(exp[i]);
                    }
                    else{
                    while (prec(exp[i])<= prec(StackChar))
                    {
                        if (st.isEmpty())
                        {
                            break;
                        }
                        pos+= st.pop();
                        StackChar = st.peek();
                    }
                    st.push(exp[i]);
                    }
                    
                }
            }
        }
        i++;
    }

return pos;
}