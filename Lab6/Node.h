#pragma once
#include <iostream>
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int dat)
    {
        data = dat;
        next = NULL;
        prev = NULL;
    }
    ~Node()
    {
        delete (next);
        delete (prev);
    }
};
void isEmpty(Node *&head)
{
    if (head == NULL)
    {
        std::cout << "List is empty";
        exit(1);
    }
}
void readData(Node *List)
{

    std::cout << "\nDisplaying the data:\n";
    Node *link = List;
    while (link != NULL)
    {
        std::cout << link->data << "->";
        link = link->next;
    }
    std::cout << "NULL\n";
}
void insertAtTail(Node *&link, int val)
{
    Node *New = new Node(val);
    if (link == NULL)
    {
        link = New;
        return;
    }
    Node *head = link;
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = New;
    New->prev = head;
}
