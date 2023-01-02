#pragma once
#include<iostream>
class Node{
    public:
    int data ;
    Node *next;
    Node(int dat)
    {
        data = dat;
        next =NULL;
    }
    ~Node()
    {
        delete(next);
    }
};
void isEmpty(Node* &head)
{
        if(head ==NULL)
    {
        std::cout<<"List is empty";
        exit(1);
    }
}
void readData(Node* List)
{

   
    std::cout<<"\nDisplaying the data:\n";
    Node *link = List;
       while (link!=NULL)
    {
        std::cout<<link->data<<"->";
        link = link->next;
    }
    std::cout<<"NULL\n";
}