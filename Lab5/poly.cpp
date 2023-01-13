#include <iostream>
// template <class T>
using std::cin;
using std::cout;
class Node
{
public:
    Node *next{};
    // T data;
    int power{};
    float data{};
    Node()
    {
        next = nullptr;
    }
    Node(float dat, int POW)
    {
        data = dat;
        power = POW;
        next = nullptr;
    }
};
void insertAtTail(Node *&link, float val, int power)
{
    Node *New = new Node(val, power);

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
void readData(Node *List)
{

    std::cout << "\nDisplaying the data:\n";
    Node *link = List;
    while (link != NULL)
    {
        std::cout << link->data << "X^" << link->power << "+";
        link = link->next;
    }
    std::cout << "0\n";
}
// void orderList(Node *&list)
// {
//     while (list->next != nullptr)
//     {
//         if (list->power > list->next->power)
//         {
//             list = list->next;
//         }
//         else if (list->power == list->next->power)
//         {
//             list->data += list->next->data;
//             Node *temp = list->next;
//             list->next = list->next->next;
//             delete temp;
//             list = list->next;
//         }
//         else
//         {
//             Node *temp = list->next;
//         }
//     }
// }
void addition(Node *first, Node *second, Node *&res)
{
    Node *temp = nullptr;
    while (first->next != nullptr)
    {
        if (first->power > second->power)
        {
            insertAtTail(res, first->data, first->power);
            temp = first;
            first = first->next;
            delete temp;
        }
        else if (first->power < second->power)
        {
            insertAtTail(res, second->data, second->power);
            temp = second;
            second = second->next;
            delete temp;
        }
        else
        {
            insertAtTail(res, first->data + second->data, first->power);
            temp = first;
            first = first->next;
            delete temp;
            temp = second;
            second = second->next;
            delete second;
        }
    }
}
void inputData(Node *&link, int limit)
{
    float temp{};
    for (int i = limit; i >= 0; i--)
    {
        cout << "Enter the data to be inserted at  " << i << " Power\t";
        cin >> temp;
        insertAtTail(link, temp, i);
    }
}
int main()
{
    int pow1{}, pow2{};
    Node *firstEXP = NULL;
    Node *SecondEXP = NULL;
    Node *res = NULL;
    cout << "Enter the highest power of the first polynomial equation:\t";
    cin >> pow1;
    inputData(firstEXP, pow1);
    cout << "Enter the highest power of the Second polynomial equation:\t";
    cin >> pow2;
    inputData(SecondEXP, pow2);
    cout << "First Equation:\t";
    readData(firstEXP);
    cout << "Second Equation:\t";
    readData(SecondEXP);

    if (pow1 >= pow2)
    {
        addition(firstEXP, SecondEXP, res);
    }
    else
    {
        addition(SecondEXP, firstEXP, res);
    }
    cout << "Result:\t";
    readData(res);
    return 0;
}
