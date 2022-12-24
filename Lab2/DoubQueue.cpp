// operations in Deque( Double ended queue)
#include <iostream>
using namespace std;
#define stacksize 10
class Full
{
};
class Empty
{
};
template <class T>
class dqueue
{
private:
    T q[stacksize]{};
    int front{}, rear{};

public:
    dqueue()
    {
        front = rear = -1;
    }
    bool isempty()
    {
        return (rear == -1 && front == -1);
    }
    bool isfull()
    {
        return ((front == rear + 1) || ((front == 0) && (rear == stacksize - 1)));
    }
    void enqrear(T item)
    {
        if (isfull())
            throw Full();
        if (front == -1 && rear == -1) // initial case
        {
            front = 0;
            rear = 0;
        }
        else if (rear == stacksize - 1)
            rear = 0;
        else
            rear++;
        q[rear] = item;
    }
    void enqfront(T item)
    {
        if (isfull())
            throw Full();
        if (front == -1 && rear == -1) // initial case
            front = rear = 0;
        else if (front == 0)
            front = stacksize - 1;
        else
            front--;
        q[front] = item;
    }
    void deqfront()
    {
        if (isempty())
            throw Empty();
        T item = q[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == stacksize - 1)
            front = 0;
        else
            front++;
        cout << "Deleted: " << item << endl;
    }
    void deqrear()
    {
        if (isempty())
            throw Empty();
        T item = q[rear];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
            rear = stacksize - 1;
        else
            rear--;
        cout << "Deleted: " << item << endl;
    }
    void display()
    {
        int i = front;
        for (i; i != rear; i = (i + 1) % stacksize)
        {
            cout << q[i] << " ";
        }
        cout << q[i] << endl;
    }
};
int main()
{
    dqueue<int> dq;
    try
    {
        dq.enqrear(26);
        dq.enqrear(68);
        dq.deqfront();
        dq.enqrear(100);
        dq.enqfront(34);
        dq.display();
        dq.deqrear();
        dq.enqrear(90);
        dq.deqfront();
        dq.enqfront(99);
        dq.display();
    }
    catch (Full)
    {
        cout << "Exception: Stack Overflow.\n";
    }
    catch (Empty)
    {
        cout << "Exception: Stack Underflow.\n";
    }
    return 0;
}