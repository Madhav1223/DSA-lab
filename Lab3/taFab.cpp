#include<iostream>
using std::cout;
using std::cin;
class NegErr{};
int fib(int n, int a = 0, int b = 1)
{
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    return fib(n - 1, b, a + b);
}
int main()
{
    int num{};
    cout<<"Enter the term you wish to find:\t";
    cin>>num;
    try
    {
        if(num>=0)
        {
            cout<<"The term is:\t"<<fib(num);
        }
        else {
            throw NegErr{};
        }
    }
    catch(...)
    {
        cout<<"Leave Programming Study Maths.";
    }
    
    return 0;
}