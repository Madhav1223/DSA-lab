#include <iostream>
#include "Node.h"
using std::cin;
using std::cout;
class UnderFlow
{
};
class Queue
{
public:
    Node *front{};
    Node *rear{};
    Queue()
    {
        front = rear = NULL;
    }
    void enqueue(int data)
    {
        Node *New = new Node(data);
        if (front == NULL && rear == NULL)
        {
            front = rear = New;
            return;
        }
        rear->next = New;
        rear = New;
    }
    int dequeue()
    {
        if (front == NULL)
        {
            throw UnderFlow{};
        }
        Node *tmp = front;
        int data = tmp->data;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
    }
};

int main()
{
    Queue q{};
    for (int i = 0; i < 10; i++)
    {
        q.enqueue(i * 20);
    }
    for (int i = 0; i < 10; i++)
    {
        cout << q.dequeue() << '\n';
    }

    return 0;
}