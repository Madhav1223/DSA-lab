#include <iostream>
#include "Node.h"
using namespace std;
void DeleteFromHead(Node *&head)
{
    isEmpty(head);
    readData(head);
    cout << "Deleting the head.....\n";
    Node *tmp = head;
    head = head->next;
    head->prev = NULL;
    delete tmp;
    // readData(head);
    //  delete(link);
}

void deleteAfter(Node *&head)
{
    isEmpty(head);
    readData(head);
    int pos{};
    cout << "Enter the data after which Node is to be deleted:\t";
    cin >> pos;
    Node *link = head;
    bool found = false;
    while (head->next != NULL)
    {
        if (head->data == pos)
        {
            found = true;
            break;
        }
        head = head->next;
    }
    if (!found)
    {
        cout << "No matching data\n";
        return;
    }
    Node *temp = head->next;
    head->next = temp->next;
    temp->next->prev = head;
    head = link;
    // delete (temp);
}
void deletAtTail(Node *&head)
{
    isEmpty(head);
    readData(head);
    Node *link = head;
    while (head->next->next != NULL)
    {
        head = head->next;
    }
    cout << "\nData to be removed:\t" << head->next->data;
    delete (head->next->next);
    head->next = NULL;
    head = link;
    // delete(link);
}
int main()
{
    int choice{0};
    Node *head = NULL;
    for (int i = 0; i < 10; i++)
    {
        insertAtTail(head, rand() % 80);
    }
    while (true)
    {
        cout << "Welcome to Singly Linked List.Here are the set of operation and their command:\n1.Delete at Head\n2>Delete at Tail\n3.Delete After a Position\n4.Delete Before a value\n5.Display Data\n6.Exit\t";
        cin >> choice;
        switch (choice)
        {
        case 1:
            DeleteFromHead(head);
            system("CLS");
            break;
        case 2:
            deletAtTail(head);
            system("CLS");
            break;
        case 3:
            deleteAfter(head);
            system("CLS");
            break;
        case 4:
            readData(head);
            break;
        default:
            return 0;
        }
    }
}
