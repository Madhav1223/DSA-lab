#include <iostream>
#include "Node.h"
using std::cin;
using std::cout;
// template <class T>
void push(Node *&link, int val)
{
    // cout<<"Creating node of:\t"<<val;
    Node *New = new Node(val);
    if (link == NULL)
    {
        link = New;
        return;
    }
    New->next = link;
    link = New;
}
// template <class T>
int pop(Node *&head)
{
    Node *temp = head;
    head = head->next;
    int data = temp->data;
    delete temp;
    return data;
}
// template <class T>
int peek(Node *head)
{
    return head->data;
}
int main()
{
    Node *head = NULL;
    for (int i = 0; i < 10; i++)
    {
        push(head, i * 30);
    }
    for (int i = 0; i < 10; i++)
    {
        cout << pop(head) << '\n';
    }
    return 0;
}
