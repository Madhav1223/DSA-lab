#include <iostream>
using namespace std;
class QueueOverFlow
{
};
class QueueUnderFlow
{
};
template <class T = char>
class Queue
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
            throw QueueOverFlow{};
        }
        else
        {
            arr[++rear] = data;
        }
    }
    T dequeue()
    {
        if(front>rear|| rear ==-1)
        {
            throw QueueUnderFlow{};
        }
        return (arr[front++]);
    }

};
int main()
{
    Queue<int>qt{};
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
