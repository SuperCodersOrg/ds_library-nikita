**SuperCoders Project 01**  
**Design Proposal \- Collection Library and Redis Lite**  
**Name \- Nikita                                    Date \- 01-07-2026**

This project focuses on the implementation of three fundamental data structures: **DynamicArray, LinkedList, and HashMap**, using C++. The objective is to build these structures from scratch while understanding how memory is allocated and managed on the heap, how operations affect performance, and how different design choices influence efficiency.

Throughout the project, the time complexity and memory behavior of each operation will be analyzed and documented. The completed data structures will then be integrated to develop Redis Lite, a simple in-memory key-value storage system that demonstrates how these structures work together in a real-world application.

---

**Dynamic Array:**

* It is an array that can **change its size during runtime**.  
* It uses **contiguous memory allocation** like a normal array.  
* When full, it **creates a larger array and copies elements** to it.  
* It provides **efficient indexing and flexible storage** compared to static arrays.

---

**Linked List:**

* A linear data structure where elements are called **nodes**.  
* Each node contains **data and a pointer/reference to the next node**.  
* Memory is **not stored in continuous locations**.  
* Easy to **insert and delete elements** by changing links.

---

**Hash Table :** 

* A data structure that stores data in **key–value pairs**.  
* Uses a **hash function** to compute an index for storing values.  
* Provides **fast searching, insertion, and deletion on average**.  
* Handles **collisions** when two keys map to the same index.

---

**Internal Working of Memory Allocation**

While implementing a Dynamic Array, I initially used `malloc()` and `realloc()` for memory management. This worked correctly for primitive data types such as `int`, `char`, and `double` because these types do not require constructors or destructors.

However, when I tried to use the same approach with `std::string`, I discovered that it did not work correctly. The reason is that `malloc()` only allocates raw memory; it does not create objects. A `std::string` object has internal data members that must be initialized by its constructor. Since `malloc()` does not call constructors, the memory contains only uninitialized bytes rather than valid `std::string` objects.

This led me to learn about **placement new**.

### **How Placement New Works with malloc()**

The process is divided into two separate steps:

#### **Step 1: Allocate Raw Memory**

First, `malloc()` reserves a block of memory large enough to hold the required number of objects.

void\* memory \= malloc(10 \* sizeof(std::string));

At this point, only raw storage exists. No `std::string` objects have been created yet.

#### **Step 2: Construct Objects Using Placement New**

Placement new constructs objects in the already allocated memory.

std::string\* arr \= static\_cast\<std::string\*\>(memory);

for (int i \= 0; i \< 10; i++) {  
    new (\&arr\[i\]) std::string();  
}

Here, placement new does not allocate memory. Instead, it takes an existing memory address and calls the constructor at that location. After this step, valid `std::string` objects exist inside the memory block allocated by `malloc()`.

#### **Step 3: Use the Objects Normally**

Now the strings can be used safely because their constructors have been executed.

arr\[0\] \= "Hello";  
arr\[1\] \= "World";

#### **Step 4: Manually Destroy the Objects**

Since placement new was used, destructors must also be called manually.

for (int i \= 0; i \< 10; i++) {  
    arr\[i\].\~basic\_string();  
}

This releases any resources owned by each `std::string`.

#### **Step 5: Free the Raw Memory**

Finally, the memory allocated by `malloc()` is returned to the system.

free(memory);

### **Complete Flow**

malloc()  
    ↓  
Raw memory allocated  
    ↓  
Placement new  
    ↓  
Constructors called  
    ↓  
Valid objects created  
    ↓  
Use the objects  
    ↓  
Manual destructor calls  
    ↓  
Object lifetime ends  
    ↓  
free()  
    ↓  
Memory released

The important idea is that `malloc()` manages only memory, while placement new manages object construction. Together, they allow complex C++ objects such as `std::string` to be stored in manually allocated memory.