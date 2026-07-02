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


     // Insert at Front
    void insertFront(const T& value){
        Node* newNode = my_new<Node>(value);
        newNode->next = head;
        head = newNode;

        if (currentSize == 0){
            tail = newNode;
        }
        currentSize++;
    }


    // Insert at Back
    void insertBack(const T& value){
        Node* newNode = my_new<Node>(value);
        if (currentSize == 0){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        currentSize++;
    }


    // Insert at Index
    void insert(int index , const T& value){
    if(index <0 || index >currentSize ){
        throw std:: out_of_range("Invalid index");
    }
    if(index == 0){
        insertFront(value);
        return;
    }
    if(index == currentSize){
        insertBack(value);
        return;
    }

    Node * previous = head;
    for(int i =0; i< index-1; i++){
        previous = previous ->next;
    }

    Node* newNode = my_new<Node>(value);
    newNode ->next = previous ->next;
    previous -> next = newNode;
    currentSize++;
}



};
#endif
