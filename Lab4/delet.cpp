#include<iostream>
#include "Node.h"
using namespace std;
void DeleteFromHead(Node* &head)
{
    isEmpty(head);
    readData(head);
    cout<<"Deleting the head.....\n";
    Node *link = head->next;
    head = link;
   // readData(head);
  //  delete(link);
    
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
}
void deleteAtPoint(Node* &head)
{
    isEmpty(head);
    readData(head);
    int pos{};
    cout<<"Enter the position that is to be deleted:\t";
    cin>>pos;
    Node *link = head;
    int i{1};
    bool found = false;
    while (head->next!=NULL && pos<i)
    {
        head =head->next;
        i++;
        found = true;
    }
    if(!found)
    {
        cout<<"Position overexceeds\n";
        return;
    }
    Node* temp =head->next;
    head->next = temp->next;
    //delete(temp);
    head = link;
}
void deletAtTail(Node* &head)
{
    isEmpty(head);
    readData(head);
    Node *link = head;
    while (head->next->next !=NULL)
    {
        head=head->next;
    }
    cout<<"\nData to be removed:\t"<<head->next->data ;
    delete(head->next->next);
    head->next = NULL;
    head=link;
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
        cout << "Welcome to Singly Linked List.Here are the set of operation and their command:\n1.Delete at Head\n2>Delete at Tail\n3.Delete at a Position\n4.Display Data\n5.Exit\t";
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
            deleteAtPoint(head);
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