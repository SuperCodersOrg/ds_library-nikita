#include <iostream>
#include <string>
#include <stdexcept>
#include "DynamicArray.h"
using namespace std;

// 1. Destructor tracking class 
// Issue: Objects allocate heap memory and rely on destructor to free it
// Result: Destructor is NOT called properly for removed/reallocated elements → memory leak
// struct Tracker {
//     int* p;

//     Tracker() {
//         p = new int(42);
//         std::cout << "Constructed\n";
//     }

//     ~Tracker() {
//         std::cout << "Destructor called\n";
//         delete p;
//     }
// };

// int main()
// {
//     // TEST 1: std::string basic usage
//     // Issue: Uses malloc/realloc so std::string constructors/destructors are not properly managed
//     // Result: Works sometimes but causes undefined behavior and possible memory leaks/crashes
//     {
//         DynamicArray<std::string> arr;
//         arr.append("hello");
//         arr.append("world");
//         arr.insert(1, "dynamic");

//         for(int i = 0; i < arr.size(); i++)
//             std::cout << arr.get(i) << "\n";
//     }

//     // TEST 2: long strings (stress realloc)
//     // Issue: realloc moves raw memory ignoring std::string move semantics causing invalid internal pointers
//     // Result: High chance of heap corruption, crashes, or corrupted string output
//     {
//         DynamicArray<std::string> arr;

//         std::string big(5000, 'A');

//         for(int i = 0; i < 200; i++)
//             arr.append(big);

//         arr.insert(50, std::string(10000, 'B'));
//         arr.remove(10);
//     }

//     // TEST 3: destructor tracking
//     // Issue: No proper destructor calls due to malloc/free usage and raw memory handling
//     // Result: Memory leak of dynamically allocated int and missing destructor behavior
//     {
//         DynamicArray<Tracker> arr;
//         arr.append(Tracker());
//         arr.append(Tracker());
//         arr.remove(0);
//     }

//     // TEST 4: copy assignment corruption
//     // Issue: Copy uses raw malloc without placement new leading to uninitialized object storage
//     // Result: Undefined behavior, possible heap corruption and crashes after modifications
//     {
//         DynamicArray<std::string> a;
//         a.append("A");
//         a.append("B");

//         DynamicArray<std::string> b;
//         b = a;

//         b.append("C");

//         a.remove(0);
//         b.remove(0);
//     }

//     // TEST 5: insert-heavy stress
//     // Issue: Frequent shifting of non-trivial objects without move semantics plus unsafe realloc
//     // Result: Gradual memory corruption leading to slowdown, instability, or crash
//     {
//         DynamicArray<std::string> arr;

//         for(int i = 0; i < 500; i++)
//         {
//             arr.append("X");
//             if(i % 3 == 0)
//                 arr.insert(0, "Y");
//         }
//     }

//     return 0;
// }

struct Student {
    string name;
    int rollNo;

    Student() : name(""), rollNo(0) {}
    Student(string n, int r) : name(n), rollNo(r) {}
};


int main()
{

// Constructor Test Cases 

    // Test Case 1 : Integer
    DynamicArray<int> intArray;

    std::cout << "Integer Array\n";
    std::cout << "Size: " << intArray.size() << '\n';
    std::cout << "Capacity: " << intArray.capacity() << "\n\n";


    // Test Case 2 : Double
    DynamicArray<double> doubleArray;

    std::cout << "Double Array\n";
    std::cout << "Size: " << doubleArray.size() << '\n';
    std::cout << "Capacity: " << doubleArray.capacity() << "\n\n";


    // Test Case 3 : Character
    DynamicArray<char> charArray;

    std::cout << "Character Array\n";
    std::cout << "Size: " << charArray.size() << '\n';
    std::cout << "Capacity: " << charArray.capacity() << "\n\n";


    // Test Case 4 : String
    DynamicArray<std::string> stringArray;

    std::cout << "String Array\n";
    std::cout << "Size: " << stringArray.size() << '\n';
    std::cout << "Capacity: " << stringArray.capacity() << "\n\n";


    // Test Case 5 : Float
    DynamicArray<float> floatArray;

    std::cout << "Float Array\n";
    std::cout << "Size: " << floatArray.size() << '\n';
    std::cout << "Capacity: " << floatArray.capacity() << '\n';


// APPEND METHOD TEST CASES

    std::cout << "\n===== APPEND TESTS =====\n";

    DynamicArray<int> a1;
    a1.append(10);
    a1.append(20);
    std::cout << a1.get(0) << " " << a1.get(1) << endl;

    DynamicArray<double> a2;
    a2.append(2.5);
    a2.append(5.8);
    std::cout << a2.get(0) << " " << a2.get(1) << endl;

    DynamicArray<char> a3;
    a3.append('A');
    a3.append('B');
    std::cout << a3.get(0) << " " << a3.get(1) << endl;

    DynamicArray<string> a4;
    a4.append("Ali");
    a4.append("Sara");
    std::cout << a4.get(0) << " " << a4.get(1) << endl;

    DynamicArray<Student> a5;
    a5.append(Student("Ali",101));
    a5.append(Student("Sara",102));
    std::cout << a5.get(0).name << " " << a5.get(1).name << endl;


// DESTRUCTOR TEST CASES
    cout << "\n===== DESTRUCTOR TEST 1 =====\n";
    {
        DynamicArray<int> arr;

        for(int i = 1; i <= 10; i++)
        {
            arr.append(i);
        }

        cout << "Size before destruction: " << arr.size() << endl;
    }
    cout << "DynamicArray Destructor Called\n";


    cout << "\n===== DESTRUCTOR TEST 2 =====\n";
    {
        DynamicArray<double> arr;

        for(int i = 1; i <= 10; i++)
        {
            arr.append(i * 1.5);
        }

        cout << "Size before destruction: " << arr.size() << endl;
    }
    cout << "DynamicArray Destructor Called\n";


    cout << "\n===== DESTRUCTOR TEST 3 =====\n";
    {
        DynamicArray<char> arr;

        for(char ch = 'A'; ch <= 'J'; ch++)
        {
            arr.append(ch);
        }

        cout << "Size before destruction: " << arr.size() << endl;
    }
    cout << "DynamicArray Destructor Called\n";


    cout << "\n===== DESTRUCTOR TEST 4 =====\n";
    {
        DynamicArray<string> arr;

        for(int i = 1; i <= 5; i++)
        {
            arr.append("Student");
        }

        cout << "Size before destruction: " << arr.size() << endl;
    }
    cout << "DynamicArray Destructor Called\n";


    cout << "\n===== DESTRUCTOR TEST 5 =====\n";
    {
        DynamicArray<Student> arr;

        for(int i = 1; i <= 5; i++)
        {
            arr.append(Student("Student", i));
        }

        cout << "Size before destruction: " << arr.size() << endl;
    }
    cout << "DynamicArray Destructor Called\n";




// COPY CONSTRUCTOR TEST CASES 

cout << "\n===== COPY CONSTRUCTOR TESTS =====\n";

    DynamicArray<int> cc1;
    cc1.append(10);
    DynamicArray<int> cc2(cc1);
    cout << cc2.get(0) << endl;

    DynamicArray<double> cc3;
    cc3.append(2.5);
    DynamicArray<double> cc4(cc3);
    cout << cc4.get(0) << endl;

    DynamicArray<char> cc5;
    cc5.append('A');
    DynamicArray<char> cc6(cc5);
    cout << cc6.get(0) << endl;

    DynamicArray<string> cc7;
    cc7.append("Ali");
    DynamicArray<string> cc8(cc7);
    cout << cc8.get(0) << endl;

    DynamicArray<Student> cc9;
    cc9.append(Student("Ali",1));
    DynamicArray<Student> cc10(cc9);
    cout << cc10.get(0).name << endl;



// Copy Assignment Operator 
    cout << "\n===== ASSIGNMENT OPERATOR TESTS =====\n";

    DynamicArray<int> o1,o2;
    o1.append(10);
    o2=o1;
    cout<<o2.get(0)<<endl;

    DynamicArray<double> o3,o4;
    o3.append(5.5);
    o4=o3;
    cout<<o4.get(0)<<endl;

    DynamicArray<char> o5,o6;
    o5.append('Z');
    o6=o5;
    cout<<o6.get(0)<<endl;

    DynamicArray<string> o7,o8;
    o7.append("Hello");
    o8=o7;
    cout<<o8.get(0)<<endl;

    DynamicArray<Student> o9,o10;
    o9.append(Student("Sara",2));
    o10=o9;
    cout<<o10.get(0).name<<endl;

    return 0;
}