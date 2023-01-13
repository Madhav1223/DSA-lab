#pragma once
#include <iostream>
// template <class T>
class Node
{
public:
    Node *next{};
    // T data;
    int data{};
    Node(int dat)
    {
        data = dat;
        next = NULL;
    }
};
