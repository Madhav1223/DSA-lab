#include <iostream>
using std::cout;
int Fact(int n, long int res)
{
    if (n <= 1)
    {
        return res;
    }
    else
    {
        Fact(n - 1, n * res);
        
    }
}
class NegErr
{
};
int main()
{
    int num{};
    long int res{1};
    cout << "Enter the number whose Factrorial is to be evaluated:\t";
    std::cin >> num;
    try
    {
        if (num >= 0)
        {

            cout << "The Factorial is:\t" << Fact(num, res);
        }
        else
        {
            throw NegErr{};
        }
    }
    catch (...)
    {
        cout << "Cannot Evaluate Factorial Of Negative number";
    }

    return 0;
}