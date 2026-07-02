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


     
    // INSERTFRONT TEST CASES
    cout << "\n===== INSERT FRONT TESTS =====\n";

    // TC1
    LinkedList<int> f1;
    f1.insertFront(30);
    f1.insertFront(20);
    f1.insertFront(10);

    for(int i=0;i<f1.size();i++)
        cout<<f1.get(i)<<" ";
    cout<<endl;


    // TC2
    LinkedList<double> f2;
    f2.insertFront(3.3);
    f2.insertFront(2.2);
    f2.insertFront(1.1);

    for(int i=0;i<f2.size();i++)
        cout<<f2.get(i)<<" ";
    cout<<endl;


    // TC3
    LinkedList<char> f3;
    f3.insertFront('C');
    f3.insertFront('B');
    f3.insertFront('A');

    for(int i=0;i<f3.size();i++)
        cout<<f3.get(i)<<" ";
    cout<<endl;


    // TC4
    LinkedList<string> f4;
    f4.insertFront("Cherry");
    f4.insertFront("Banana");
    f4.insertFront("Apple");

    for(int i=0;i<f4.size();i++)
        cout<<f4.get(i)<<" ";
    cout<<endl;


    // TC5
    LinkedList<Student> f5;
    f5.insertFront(Student("Sara",3));
    f5.insertFront(Student("Ali",2));
    f5.insertFront(Student("Ahmed",1));

    for(int i=0;i<f5.size();i++)
    {
        cout<<f5.get(i).name<<" ";
    }
    cout<<endl;
    

    // INSERTBACK TEST CASES
    cout << "\n===== INSERT BACK TESTS =====\n";

    // TC1
    LinkedList<int> b1;
    b1.insertBack(10);
    b1.insertBack(20);
    b1.insertBack(30);

    for(int i=0;i<b1.size();i++)
        cout<<b1.get(i)<<" ";
    cout<<endl;


    // TC2
    LinkedList<double> b2;
    b2.insertBack(1.1);
    b2.insertBack(2.2);
    b2.insertBack(3.3);

    for(int i=0;i<b2.size();i++)
        cout<<b2.get(i)<<" ";
    cout<<endl;


    // TC3
    LinkedList<char> b3;
    b3.insertBack('A');
    b3.insertBack('B');
    b3.insertBack('C');

    for(int i=0;i<b3.size();i++)
        cout<<b3.get(i)<<" ";
    cout<<endl;


    // TC4
    LinkedList<string> b4;
    b4.insertBack("Apple");
    b4.insertBack("Banana");
    b4.insertBack("Cherry");

    for(int i=0;i<b4.size();i++)
        cout<<b4.get(i)<<" ";
    cout<<endl;


    // TC5
    LinkedList<Student> b5;
    b5.insertBack(Student("Ali",1));
    b5.insertBack(Student("Sara",2));
    b5.insertBack(Student("Ahmed",3));

    for(int i=0;i<b5.size();i++)
    {
        cout<<b5.get(i).name<<" ";
    }
    cout<<endl;



    return 0;
}