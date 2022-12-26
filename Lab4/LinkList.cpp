#include<iostream>
using namespace std;
class Node{
    public:
    int data ;
    Node *next;
    Node(int dat)
    {
        data = dat;
        next =NULL;
    }
};
void insertAtTail(Node* &link, int val)
{
    Node *New = new Node(val);
   
    if(link == NULL)
    {
        link = New;
        return ;
    }
     Node *head = link;
    while (head->next!=NULL)
    {
        head = head->next;
    }
    head->next = New;
}
void readData(Node* List)
{
    Node *link = List;
       while (link!=NULL)
    {
        cout<<link->data<<"->";
        link = link->next;
    }
    cout<<"NULL";
}
int main()
{
    Node * head = NULL;
    for (int i = 0; i < 10; i++)
    {
        insertAtTail(head,rand()%50);
    }
    readData(head);
    return 0;
}