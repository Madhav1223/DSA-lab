#include<iostream>
using std::cout;
int Fact(int n)
{
    if(n<=1)
    {
        return 1;
    }
    else
    {
        return (n*Fact(n-1));
    }
    
}
class NegErr{};
int main()
{
    int num{};
    cout<<"Enter the number whose Factrorial is to be evaluated:\t";
    std::cin>>num;
    try
    {
        if (num>=0)
        {
            
            cout<<"The Factorial is:\t"<<Fact(num);
        }
        else
        {
            throw NegErr{};
        }
        
        
    }
    catch(...)
    {
        cout<<"Cannot Evaluate Factorial Of Negative number";
    }
    
    return 0;
}