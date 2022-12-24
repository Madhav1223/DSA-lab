#include <iostream>
using std::cin;
using std::cout;

int Fab(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return (Fab(n - 1) + Fab(n - 2));
    }
}
class NegErr
{
};
int main()
{
    int num{};
    cout << "Enter the term to be evaluated in Series:\t";
    cin >> num;
    try
    {
        if (num >= 0)
        {
            long int res = Fab(num);
            cout << "The Term is:\t" << res;
        }
        else
        {
            throw NegErr{};
        }
            
        
    }
    catch (...)
    {
        cout<<"Enter Positive Number Next Time";
    }

    return 0;
}