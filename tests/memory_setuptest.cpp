#include <iostream>
#include <string>
#include "Memory.h"

using namespace std;

class Test
{
public:
    int value;

    Test() : value(100) {}
};

struct Node
{
    int value;
    Node* next;
};

int main()
{
    cout << "Testing custom allocator..." << endl;

    // int
    int* pInt = my_new<int>(42);

    if(*pInt != 42)
    {
        cout << "FAIL: int allocation" << endl;
        return 1;
    }

    my_delete(pInt);

    cout << "int allocation: OK" << endl;

    // double
    double* pDouble = my_new<double>(3.14);

    if(*pDouble != 3.14)
    {
        cout << "FAIL: double allocation" << endl;
        return 1;
    }

    my_delete(pDouble);

    cout << "double allocation: OK" << endl;

    // char
    char* pChar = my_new<char>('A');

    if(*pChar != 'A')
    {
        cout << "FAIL: char allocation" << endl;
        return 1;
    }

    my_delete(pChar);

    cout << "char allocation: OK" << endl;

    // string
    string* pString = my_new<string>("Hello");

    if(*pString != "Hello")
    {
        cout << "FAIL: string allocation" << endl;
        return 1;
    }

    my_delete(pString);

    cout << "string allocation: OK" << endl;

    // class
    Test* obj = my_new<Test>();

    if(obj->value != 100)
    {
        cout << "FAIL: class allocation" << endl;
        return 1;
    }

    my_delete(obj);

    cout << "class allocation: OK" << endl;

    // int array
    int* intArr = my_new_array<int>(5);

    for(int i = 0; i < 5; i++)
    {
        intArr[i] = i * 10;
    }

    if(intArr[3] != 30)
    {
        cout << "FAIL: int array" << endl;
        return 1;
    }

    my_delete_array(intArr, 5);

    cout << "int array: OK" << endl;

    // double array
    double* doubleArr = my_new_array<double>(3);

    doubleArr[0] = 1.1;
    doubleArr[1] = 2.2;
    doubleArr[2] = 3.3;

    if(doubleArr[2] != 3.3)
    {
        cout << "FAIL: double array" << endl;
        return 1;
    }

    my_delete_array(doubleArr, 3);

    cout << "double array: OK" << endl;

    // class array
    Test* testArr = my_new_array<Test>(4);

    if(testArr[2].value != 100)
    {
        cout << "FAIL: class array" << endl;
        return 1;
    }

    my_delete_array(testArr, 4);

    cout << "class array: OK" << endl;

    // linked nodes
    Node* n1 = my_new<Node>();
    Node* n2 = my_new<Node>();

    n1->value = 10;
    n2->value = 20;

    n1->next = n2;
    n2->next = nullptr;

    if(n1->next->value != 20)
    {
        cout << "FAIL: linked nodes" << endl;
        return 1;
    }

    my_delete(n2);
    my_delete(n1);

    cout << "linked nodes: OK" << endl;

    cout << endl;
    cout << "SUCCESS: all allocator tests passed." << endl;

    return 0;
}