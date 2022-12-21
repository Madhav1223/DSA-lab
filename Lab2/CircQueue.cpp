#include <iostream>
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
    T arr[30];

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    void enqueue(T data)
    {
        if (front == rear == -1)
        {
            front++;
            arr[++rear] = data;
        }
        else if (rear == 29)
        {
            if(arr[0]!=NULL)
            {
            throw QueueOverFlow{};
            }
            rear =0;
        }
        else
        {
            arr[++rear] = data;
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
        temp = arr[front];
        arr[front] = NULL;

        return temp;;
    }

};
int main()
{
    CircQueue<int>qt{};
    try{
    for (int i = 0; i < 5; i++)
    {
       qt.enqueue(rand()%15);
    }
    for (int i = 0; i < 7; i++)
    {
      cout<< qt.dequeue()<<endl;
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