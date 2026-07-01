#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Testing environment..." << endl;

    // Heap allocation

    int* heapInt = new int(42);

    if(*heapInt != 42)
    {
        cout << "FAIL: heap allocation" << endl;
        return 1;
    }

    delete heapInt;

    cout << "Heap allocation: OK" << endl;

    // Heap array

    int* heapArr = new int[5];

    for(int i=0;i<5;i++)
    {
        heapArr[i] = i * 10;
    }

    if(heapArr[3] != 30)
    {
        cout << "FAIL: heap array" << endl;
        return 1;
    }

    delete[] heapArr;

    cout << "Heap array: OK" << endl;

    // Linked Nodes

    struct Node
    {
        int value;
        Node* next;
    };

    Node* n1 = new Node{10,nullptr};
    Node* n2 = new Node{20,nullptr};

    n1->next = n2;

    if(n1->next->value != 20)
    {
        cout << "FAIL: linked nodes" << endl;
        return 1;
    }

    delete n2;
    delete n1;

    cout << "Linked nodes: OK" << endl;

    // String

    string key = "name";
    string value = "Arun";

    if(key.length() != 4)
    {
        cout << "FAIL: string operations" << endl;
        return 1;
    }

    cout << "String operations: OK" << endl;

    cout << endl;
    cout << "SUCCESS: environment fully ready." << endl;

    return 0;
}