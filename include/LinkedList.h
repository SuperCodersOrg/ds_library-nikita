#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>
#include "Memory.h"

template<typename T>
class LinkedList
{
private:

    struct Node
    {
        T data;
        Node* next;

        Node(const T& value)
            : data(value), next(nullptr)
        {
        }
    };

    Node* head;
    Node* tail;
    int currentSize;

public:

    // Constructor
    LinkedList(){
        head = nullptr;
        tail = nullptr;
        currentSize = 0;
    }

};
#endif
