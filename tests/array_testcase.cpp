#include <iostream>
#include <string>
#include <stdexcept>
#include "DynamicArray.h"

// 1. Destructor tracking class 
// Issue: Objects allocate heap memory and rely on destructor to free it
// Result: Destructor is NOT called properly for removed/reallocated elements → memory leak
struct Tracker {
    int* p;

    Tracker() {
        p = new int(42);
        std::cout << "Constructed\n";
    }

    ~Tracker() {
        std::cout << "Destructor called\n";
        delete p;
    }
};

int main()
{
    // TEST 1: std::string basic usage
    // Issue: Uses malloc/realloc so std::string constructors/destructors are not properly managed
    // Result: Works sometimes but causes undefined behavior and possible memory leaks/crashes
    {
        DynamicArray<std::string> arr;
        arr.append("hello");
        arr.append("world");
        arr.insert(1, "dynamic");

        for(int i = 0; i < arr.size(); i++)
            std::cout << arr.get(i) << "\n";
    }

    // TEST 2: long strings (stress realloc)
    // Issue: realloc moves raw memory ignoring std::string move semantics causing invalid internal pointers
    // Result: High chance of heap corruption, crashes, or corrupted string output
    {
        DynamicArray<std::string> arr;

        std::string big(5000, 'A');

        for(int i = 0; i < 200; i++)
            arr.append(big);

        arr.insert(50, std::string(10000, 'B'));
        arr.remove(10);
    }

    // TEST 3: destructor tracking
    // Issue: No proper destructor calls due to malloc/free usage and raw memory handling
    // Result: Memory leak of dynamically allocated int and missing destructor behavior
    {
        DynamicArray<Tracker> arr;
        arr.append(Tracker());
        arr.append(Tracker());
        arr.remove(0);
    }

    // TEST 4: copy assignment corruption
    // Issue: Copy uses raw malloc without placement new leading to uninitialized object storage
    // Result: Undefined behavior, possible heap corruption and crashes after modifications
    {
        DynamicArray<std::string> a;
        a.append("A");
        a.append("B");

        DynamicArray<std::string> b;
        b = a;

        b.append("C");

        a.remove(0);
        b.remove(0);
    }

    // TEST 5: insert-heavy stress
    // Issue: Frequent shifting of non-trivial objects without move semantics plus unsafe realloc
    // Result: Gradual memory corruption leading to slowdown, instability, or crash
    {
        DynamicArray<std::string> arr;

        for(int i = 0; i < 500; i++)
        {
            arr.append("X");
            if(i % 3 == 0)
                arr.insert(0, "Y");
        }
    }

    return 0;
}