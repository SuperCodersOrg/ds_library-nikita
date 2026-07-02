#include <iostream>
#include <string>
using namespace std;

#include "LinkedList.h"

struct Student
{
    string name;
    int rollNo;

    Student() : name(""), rollNo(0) {}

    Student(string n, int r) : name(n), rollNo(r) {}

    bool operator==(const Student& other) const
    {
        return name == other.name &&
               rollNo == other.rollNo;
    }
};

int main(){

    // CONSTRUCTOR TEST CASES

    cout << "\n===== CONSTRUCTOR TESTS =====\n";

    LinkedList<int> c1;
    cout << "Size: " << c1.size() << endl;

    LinkedList<double> c2;
    cout << "Size: " << c2.size() << endl;

    LinkedList<char> c3;
    cout << "Size: " << c3.size() << endl;

    LinkedList<string> c4;
    cout << "Size: " << c4.size() << endl;

    LinkedList<Student> c5;
    cout << "Size: " << c5.size() << endl;


     

    
    return 0;
}