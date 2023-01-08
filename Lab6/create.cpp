#include <iostream>
using namespace std;
#include "Node.h"
void insertAfter(Node *&head, int data)
{
    int val{};

    cout << "Enter the value to be inserted:\t";
    cin >> val;
    Node *New = new Node(val);
    Node *link = head;
    bool found = false;
    while (head->next != NULL)
    {
        if (head->data == data)
        {
            found = true;
            break;
        }
        head = head->next;
    }
    if (!found)
    {
        cout << "Choose a data that is there";
        exit(1);
    }
    New->next = head->next;
    head->next->prev = New;
    head->next = New;
    New->prev = head;
    head = link;
}
void insertBefore(Node *head, int data)
{
    int val{};
    bool found{false};
    cout << "Enter the value to be inserted:\t";
    cin >> val;
    Node *link = head;
    Node *New = new Node(val);
    while (head->next != NULL)
    {
        if (head->next->data == data)
        {
            found = true;
            break;
        }
        head = head->next;
    }
    if (!found)
    {
        cout << "Choose a data that is there";
        exit(1);
    }
    New->next = head->next;
    head->next->prev = New;
    New->prev = head;
    head->next = New;
    head = link;
}
void insertAtHead(Node *&head, int val)
{
    Node *New = new Node(val);
    if (head == NULL)
    {
        head = New;
        return;
    }
    Node *tmp = head;
    New->next = tmp;
    tmp->prev = New;
    head = New;
}
int main()
{
    Node *head = NULL;
    for (int i = 0; i < 10; i++)
    {
        insertAtTail(head, rand() % 80);
    }
    int choice{}, data{};
    char c{};
    while (true)
    {
        cout << "Welcome to Doubly Linked List.Here are the set of operation and their command:\n1.Insert at Head\n2>Insert at Tail\n3.Insert after node with certain values.\n4Insert before Certain values\n5.Display the data\n6.Exit\t";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the data to be inserted at head:\t";
            cin >> data;
            insertAtHead(head, data);
            system("CLS");
            break;
        case 2:
            cout << "Enter the data  be inserted at tail:\t";
            cin >> data;
            insertAtTail(head, data);
            system("CLS");
            break;
        case 3:
            readData(head);
            cout << "Enter the data after which data is to be inserted:\t";
            cin >> data;
            insertAfter(head, data);
            system("CLS");
            break;
        case 4:
            readData(head);
            cout << "Enter the data before which  is to to be inserted:\t";
            cin >> data;
            insertBefore(head, data);
            system("CLS");
            break;
        case 5:

            readData(head);
            std::cout << "Press q to exit\t";
            std::cin >> c;
            break;
        default:
            // cout << "Invalid OPeration";
            exit(1);
        }
        system("CLS");
    }
    return 0;
}