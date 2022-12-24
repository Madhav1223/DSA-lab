#include <iostream>
#include<cstdlib>
using namespace std;
class QueueOverFlow
{
};
class QueueUnderFlow
{
};
template <class T = char>
class CircQueue
{
private:
    int front{}, rear{};
    T arr[30]{};

public:
    CircQueue()
    {
        front = -1;
        rear = -1;
    }
    void enqueue(T data)
    {
        if (front ==-1 &&rear == -1)
        {
            front = 0;
            rear =0;
            arr[rear] = data;
            cout<<arr[rear]<<endl;
        }
        else if (rear == 29)
        {
            if(front!=0)
            {
            rear =0;
            arr[rear] = data;
            cout<<arr[rear]<<endl;
            }
            else{
            throw QueueOverFlow{};

        }
        }
        else
        {
            rear++;
            arr[rear] = data;
            cout<<arr[rear]<<endl;
        }
    }
    T dequeue()
    {   if (front ==29)
    {
        front =0;
        
    }
    
        if(front>rear|| rear ==-1)
        {
            throw QueueUnderFlow{};
        }
        
     return arr[front++];
    }

};
int main()
{
    CircQueue<int>qt{};
    cout<<"Insertation Phase\n";
    try{
    for (int i = 0; i < 28; i++)
    {
       qt.enqueue(rand()%20);
    }
    
    cout<<"Deque Started\n";
    for (int i = 0; i < 27; i++)
    {
      cout<< qt.dequeue()<<endl;
    }
     cout<<"Insertation Phase\n";
    for (int i = 0; i < 27; i++)
    {
       qt.enqueue(rand()%15);
    }}
    catch(QueueOverFlow)
    {
        cout<<"Queue Full";
    }
    catch(QueueUnderFlow)
    {
        cout<<"Queue Empty";
    }
     return 0;
}