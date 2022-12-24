#include<iostream>
using std::cout;
using std::cin;
using std::string;
void TOH(int n, char src,char helper,char dest)
{
    if(n==1)
    {
        cout<<"Transfering Block "<<n<<"From "<<src<<" to  "<<dest<<std::endl;
        return;
    }
    TOH(n-1,src,dest,helper);
    cout<<"Transfering Block "<<n<<"From "<<src<<" to "<<dest<<std::endl;
    TOH(n-1,helper,src,dest);
}
int main()
{
    int num{};
    cout<<"Enter the number of Disk \t";
    cin>>num;
    TOH(num,'a','b','c');
    return 0;
}