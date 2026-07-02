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


    // INSERT AT ANY INDEX TEST CASES
    cout << "\n===== INSERT AT INDEX TESTS =====\n";

    // TC1
    LinkedList<int> i1;
    i1.insertBack(10);
    i1.insertBack(30);
    i1.insert(1,20);

    for(int i=0;i<i1.size();i++)
        cout<<i1.get(i)<<" ";
    cout<<endl;


    // TC2
    LinkedList<double> i2;
    i2.insertBack(1.1);
    i2.insertBack(3.3);
    i2.insert(1,2.2);

    for(int i=0;i<i2.size();i++)
        cout<<i2.get(i)<<" ";
    cout<<endl;


    // TC3
    LinkedList<char> i3;
    i3.insertBack('A');
    i3.insertBack('C');
    i3.insert(1,'B');

    for(int i=0;i<i3.size();i++)
        cout<<i3.get(i)<<" ";
    cout<<endl;


    // TC4
    LinkedList<string> i4;
    i4.insertBack("Apple");
    i4.insertBack("Cherry");
    i4.insert(1,"Banana");

    for(int i=0;i<i4.size();i++)
        cout<<i4.get(i)<<" ";
    cout<<endl;


    // TC5
    LinkedList<Student> i5;
    i5.insertBack(Student("Ali",1));
    i5.insertBack(Student("Sara",3));
    i5.insert(1,Student("Ahmed",2));

    for(int i=0;i<i5.size();i++)
    {
        cout<<i5.get(i).name<<" ";
    }
    cout<<endl;



    // DELETE BACK TEST CASES
    cout << "\n===== DELETE FRONT TESTS =====\n";

    // TC1
    LinkedList<int> df1;
    df1.insertBack(10);
    df1.insertBack(20);
    df1.insertBack(30);

    df1.deleteFront();

    for(int i=0;i<df1.size();i++)
        cout << df1.get(i) << " ";
    cout << endl;


    // TC2
    LinkedList<double> df2;
    df2.insertBack(1.1);
    df2.insertBack(2.2);
    df2.insertBack(3.3);

    df2.deleteFront();

    for(int i=0;i<df2.size();i++)
        cout << df2.get(i) << " ";
    cout << endl;


    // TC3
    LinkedList<char> df3;
    df3.insertBack('A');
    df3.insertBack('B');
    df3.insertBack('C');

    df3.deleteFront();

    for(int i=0;i<df3.size();i++)
        cout << df3.get(i) << " ";
    cout << endl;


    // TC4
    LinkedList<string> df4;
    df4.insertBack("Apple");
    df4.insertBack("Banana");
    df4.insertBack("Cherry");

    df4.deleteFront();

    for(int i=0;i<df4.size();i++)
        cout << df4.get(i) << " ";
    cout << endl;


    // TC5
    LinkedList<Student> df5;
    df5.insertBack(Student("Ali",1));
    df5.insertBack(Student("Sara",2));
    df5.insertBack(Student("Ahmed",3));

    df5.deleteFront();

    for(int i=0;i<df5.size();i++)
        cout << df5.get(i).name << " ";
    cout << endl;




    //DELETE BACK TEST CASES 
    cout << "\n===== DELETE BACK TESTS =====\n";

    // TC1
    LinkedList<int> db1;
    db1.insertBack(10);
    db1.insertBack(20);
    db1.insertBack(30);

    db1.deleteBack();

    for(int i=0;i<db1.size();i++)
        cout << db1.get(i) << " ";
    cout << endl;


    // TC2
    LinkedList<double> db2;
    db2.insertBack(1.1);
    db2.insertBack(2.2);
    db2.insertBack(3.3);

    db2.deleteBack();

    for(int i=0;i<db2.size();i++)
        cout << db2.get(i) << " ";
    cout << endl;


    // TC3
    LinkedList<char> db3;
    db3.insertBack('A');
    db3.insertBack('B');
    db3.insertBack('C');

    db3.deleteBack();

    for(int i=0;i<db3.size();i++)
        cout << db3.get(i) << " ";
    cout << endl;


    // TC4
    LinkedList<string> db4;
    db4.insertBack("Apple");
    db4.insertBack("Banana");
    db4.insertBack("Cherry");

    db4.deleteBack();

    for(int i=0;i<db4.size();i++)
        cout << db4.get(i) << " ";
    cout << endl;


    // TC5
    LinkedList<Student> db5;
    db5.insertBack(Student("Ali",1));
    db5.insertBack(Student("Sara",2));
    db5.insertBack(Student("Ahmed",3));

    db5.deleteBack();

    for(int i=0;i<db5.size();i++)
        cout << db5.get(i).name << " ";
    cout << endl;



    //REMOVE TEST CASES
    cout << "\n===== REMOVE TESTS =====\n";

    // TC1
    LinkedList<int> r1;
    r1.insertBack(10);
    r1.insertBack(20);
    r1.insertBack(30);

    r1.remove(1);

    for(int i=0;i<r1.size();i++)
        cout << r1.get(i) << " ";
    cout << endl;


    // TC2
    LinkedList<double> r2;
    r2.insertBack(1.1);
    r2.insertBack(2.2);
    r2.insertBack(3.3);

    r2.remove(0);

    for(int i=0;i<r2.size();i++)
        cout << r2.get(i) << " ";
    cout << endl;


    // TC3
    LinkedList<char> r3;
    r3.insertBack('A');
    r3.insertBack('B');
    r3.insertBack('C');

    r3.remove(2);

    for(int i=0;i<r3.size();i++)
        cout << r3.get(i) << " ";
    cout << endl;


    // TC4
    LinkedList<string> r4;
    r4.insertBack("One");
    r4.insertBack("Two");
    r4.insertBack("Three");

    r4.remove(1);

    for(int i=0;i<r4.size();i++)
        cout << r4.get(i) << " ";
    cout << endl;


    // TC5
    LinkedList<Student> r5;
    r5.insertBack(Student("Ali",1));
    r5.insertBack(Student("Sara",2));
    r5.insertBack(Student("Ahmed",3));

    r5.remove(1);

    for(int i=0;i<r5.size();i++)
        cout << r5.get(i).name << " ";
    cout << endl;



    // SEARCH TEST CASES
    cout << "\n===== SEARCH TESTS =====\n";

    LinkedList<int> s1;
    s1.insertBack(10);
    s1.insertBack(20);
    s1.insertBack(30);
    cout << s1.search(20) << endl;

    LinkedList<double> s2;
    s2.insertBack(1.1);
    s2.insertBack(2.2);
    cout << s2.search(2.2) << endl;

    LinkedList<char> s3;
    s3.insertBack('A');
    s3.insertBack('B');
    cout << s3.search('B') << endl;

    LinkedList<string> s4;
    s4.insertBack("Ali");
    s4.insertBack("Sara");
    cout << s4.search("Sara") << endl;

    LinkedList<Student> s5;
    s5.insertBack(Student("Ali",1));
    s5.insertBack(Student("Sara",2));

    cout << s5.search(Student("Sara",2)) << endl;


    // Get TEST CASES
    cout << "\n===== GET TESTS =====\n";

    LinkedList<int> g1;
    g1.insertBack(100);
    cout << g1.get(0) << endl;

    LinkedList<double> g2;
    g2.insertBack(5.5);
    cout << g2.get(0) << endl;

    LinkedList<char> g3;
    g3.insertBack('X');
    cout << g3.get(0) << endl;

    LinkedList<string> g4;
    g4.insertBack("Hello");
    cout << g4.get(0) << endl;

    LinkedList<Student> g5;
    g5.insertBack(Student("Ali",10));
    cout << g5.get(0).name << " "
        << g5.get(0).rollNo << endl;

    return 0;
}