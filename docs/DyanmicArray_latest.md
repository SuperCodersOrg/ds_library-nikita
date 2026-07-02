

			 **Dynamic Array** 

**Part 1**  —  Public API        


# **Dynamic Array**

Class Declaration :

template \<typename T\>

class DynamicArray {

  Private:

    T\* data;

    int currentSize;

    int currentCapacity;

    void resize(newCap);

  public:

    void append(const T& value);

    void insert(int index, const T& value);

    void remove(int index);

    T get(int index) const;

    int size() const;

    int capacity() const;

    // Rule of Three

    DynamicArray();

    \~DynamicArray();

    DynamicArray(const DynamicArray& other);

    DynamicArray& operator=(const DynamicArray& other);

};

## **1\. resize(newCap)  \[private\]**

**Parameter :** 

* **newCap** → it is the parameter that will decide the new value of the capacity

**Return Type : void**

* I decided to keep the return type of this function as void because what it does is allocate new memory, copy elements, and free old block of memory. These processes are directly happening with the object so there is no need to return anything from this function.


## **2\. append(value)  :  Adding an element to a dynamic array**

**Parameter :** 

* **Value →** The value that will be inserted

**Return Type : void**

* I thought to keep the return type of this as void because all it does is internal working like checking whether resize need or where to insert the value. It does not return any value to the caller.


## **3\. insert(index, value)  :  Adding an element to a dynamic array at a particular position**

**Parameters :** 

* **Index →** the value at which I need to insert. If I won't include this value then how will I know where to insert the new value

* **Value →** the value which needs to be inserted in the array

**Return Type : void**

* I decided to make its return type as void as according to its functionality it does all the working internally directly with the object and there is no need to return anything to the caller.


## **4\. remove(index)  :  To remove an element from a dynamic array**

**Parameter :** 

* **Index →** this value tells the method from where to remove the element. If it is not provided then the program will not know from where to remove the element.

**Return Type : void**

* I decided to keep the return type of this function as void. What it does is remove elements from the dynamic array and then decrease size. It does not send or return anything to the caller.


## **5\. get(index)  :  Access an element by passing index**

**Parameter** : 

* **Index →** This value tells the function which element I want to access. If it is not provided then how will the function know what to access and from where to access.

**Return Type : T**

* At first I thought to keep the return type as void, but then I noticed that this function is returning an element to the caller. Since a value is being returned, the return type cannot be void.

* Then I thought why not keep the return type as int. But another problem arose. What if the Dynamic Array is of string type? In that case the function would return a string, not an integer. Therefore, keeping the return type fixed as int would make the function work only for integer arrays.

* After thinking about this, I noticed that the element being returned always belongs to the Dynamic Array itself. So if the Dynamic Array stores integers, the function should return an integer. If the Dynamic Array stores strings, the function should return a string.

* Therefore I decided to align the return type of this function with the type of elements stored in the Dynamic Array.

* So decided it to keep as  **T get(int index) const;**


## **6\. size()  :  To get number of elements currently stored in the array**

**Return Type : int**

* At first I thought to make it void then I noticed that it is returning size of the array which is integer and cannot be any other data type because the number of elements cannot be in float — there is no chance that 2.6 or 5.5 elements are present in the array. So I decided to keep the return type of this function as int.


## **7\. capacity()  :  To get the maximum number of elements that can currently be stored in the array**

**Return Type : int**

* At first I thought to make it void, but then I noticed that this function returns the capacity of the array to the caller. Since a value is being returned, the return type cannot be void.

* Capacity represents the maximum number of elements that can currently be stored in the array, and the number of elements can only be a whole number. There cannot be 4.5 or 10.7 positions available in an array.

* Therefore, I decided to keep the return type of this function as int.


## **8\. shrinkToFit()  :  To reduce the capacity of the Dynamic Array to exactly match its current size**

**Why do we need it :**

* Free up unused memory when the array has excess capacity

* Reduce memory footprint after multiple deletions

* Ensure that the array uses only the exact required memory

* Optimize storage before final usage (e.g., before storing or transferring data)

**How does it work :**

* I implemented this method such that at every call it will first check the size of the array and then allocate a new block of memory equal to the size of the array. After that, it copies all the elements of the array to the new block, then frees the old block, and finally updates the pointer to point to the new block.

**Return Type : void**

* I have decided to keep its return type as void because all the working of this function is happening internally. It is not returning anything to the caller; instead, it directly modifies the internal structure of the array.


  

## **Rule of Three — Three Special Functions**

Because my class manages dynamic memory, I need to define three special member functions:

* Destructor

* Copy Constructor

* Copy Assignment Operator

This concept is known as the **Rule of Three.** If a class defines any one of these, then it usually needs to define all three. This ensures proper memory management and prevents shallow-copy related problems.

### **Destructor  :  \~DynamicArray()**

**Return Type : none**

* At first I thought about whether the destructor should return something after freeing memory. Then I noticed that its only responsibility is to clean up resources owned by the object before the object is destroyed.

* Since no value needs to be returned to the caller, destructors do not have a return type.

* Just like constructors, a destructor cannot have int, void, or any other return type.

* Therefore, I decided to declare it as: \~DynamicArray(); without any return type.


### **Copy Constructor  :  DynamicArray(const DynamicArray& other)**

**Return Type : none**

* At first I thought whether the Copy Constructor should return the newly created object.

* Then I noticed that constructors automatically initialize objects during creation. Their purpose is to create and initialize an object, not return one.

* Therefore Copy Constructors do not have any return type.

* **DynamicArray(const DynamicArray& other);**


### **Copy Assignment Operator  :  DynamicArray& operator=(const DynamicArray& other)**

**Return Type : DynamicArray&**

* At first I thought of returning void because the assignment had already been completed.

* Then I noticed that assignment operators in C++ are expected to return the object that received the assignment.

* This allows expressions such as a \= b \= c; to work correctly.

* Therefore, I decided to return a reference to the current object.

* The & means a reference is returned instead of creating another copy of the object.

* Therefore the return type is: DynamicArray& which is the standard implementation for a copy assignment operator.

**Part 2**  —  Internal Representation & Memory Diagrams

# **Dynamic Array — Memory Diagrams**

## **Basic Internal Structure**

To implement Dynamic Array we need :

* **A pointer :** that will point to the location where the array is stored in heap

* **Size :** size tells how many elements are present in the array so that we can know where to insert the next element. If I don't know the size then how will I know where to insert the next element in the collection

* **Capacity :** to know maximum number of elements that can be stored in the collection / array

* And if my array is full  size \== capacity  so I can also make a new array with better capacity that is by resizing so that more elements can be inserted

Example :

arr \= \[10, 20, 30, \_, \_\]

size \= 3

capacity \= 5

\- 3 elements are used

\- 2 spaces are free

## **Data (Pointer)**

As I am using heap for the storage of the elements so to access the array I must have its address so I decided to make a pointer in stack and point it to the array.

The data type of this pointer will depend on the type of elements stored in the Dynamic Array. For example, if the array stores integers, the pointer type will be int\*. If the array stores characters, the pointer type will be char\*.

Example :

data → heap memory address

data\[0\], data\[1\], ...

Without a pointer, we cannot access heap array.

## **Constructor — Before and After**

Before Constructor :

DynamicArray\<int\> arr;

Memory:

data           \= garbage

currentSize    \= garbage

currentCapacity \= garbage

After Constructor :

data ───► \[ \_ | \_ | \_ | \_ \]

currentSize    \= 0

currentCapacity \= 4

## 

## **resize(newCap) — Memory Movement**

**Step 1: Original Array (Capacity \= 4\)**

\+----+----+----+----+  
| 10 | 20 | 30 | 40 |  
\+----+----+----+----+

**Step 2: Allocate New Larger Memory (Capacity \= 8\)**

Old Memory                    New Memory

\+----+----+----+----+         \+----+----+----+----+----+----+----+----+  
| 10 | 20 | 30 | 40 |         |    |    |    |    |    |    |    |    |  
\+----+----+----+----+         \+----+----+----+----+----+----+----+----+

**Step 3: Copy Elements**

\+----+----+----+----+         \+----+----+----+----+----+----+----+----+  
| 10 | 20 | 30 | 40 | \-----\>  | 10 | 20 | 30 | 40 |    |    |    |    |  
\+----+----+----+----+         \+----+----+----+----+----+----+----+----+

**Step 4: Update Reference Pointer**

      ptr  
       |  
       v  
\+----+----+----+----+----+----+----+----+  
| 10 | 20 | 30 | 40 |    |    |    |    |  
\+----+----+----+----+----+----+----+----+

**Step 5: Free Old Memory**

Old Memory  
\+----+----+----+----+  
| XX | XX | XX | XX |  
\+----+----+----+----+  
   released

Current Array (Capacity \= 8\)

      ptr  
       |  
       v  
\+----+----+----+----+----+----+----+----+  
| 10 | 20 | 30 | 40 |    |    |    |    |  
\+----+----+----+----+----+----+----+----+

Example :

\[10, 20, 30, 40\] → new array

copy all 4 elements → O(n)

## 

## **append(value) — How it works**

* If size \< capacity  →  Insert element at arr\[size\] and increment size

* If size \== capacity  →  Call resize(newCap) (usually newCap \= capacity \* 2\)

  * →  Copy old elements to new memory  →  Free old memory  →  Then insert the new element

**Case: Append(50) when array is full**

**Before Append**

Size \= 4, Capacity \= 4

\+----+----+----+----+

| 10 | 20 | 30 | 40 |

\+----+----+----+----+

Append(50)

      |

      v

Array Full

**Step 1: Allocate Larger Array (Capacity \= 8\)**

Old Array                    New Array

\+----+----+----+----+        \+----+----+----+----+----+----+----+----+

| 10 | 20 | 30 | 40 |        |    |    |    |    |    |    |    |    |

\+----+----+----+----+        \+----+----+----+----+----+----+----+----+

**Step 2: Copy Existing Elements**

\+----+----+----+----+        \+----+----+----+----+----+----+----+----+

| 10 | 20 | 30 | 40 | \-----\> | 10 | 20 | 30 | 40 |    |    |    |    |

\+----+----+----+----+        \+----+----+----+----+----+----+----+----+

**Step 3: Insert New Element (50)**

\+----+----+----+----+----+----+----+----+

| 10 | 20 | 30 | 40 | 50 |    |    |    |

\+----+----+----+----+----+----+----+----+

                          ^

                     inserted here

**Step 4: Update Pointer and Free Old Array**

Old Array

\+----+----+----+----+

| XX | XX | XX | XX |

\+----+----+----+----+

    released

Current Dynamic Array

Size \= 5, Capacity \= 8

      ptr

       |

       v

\+----+----+----+----+----+----+----+----+

| 10 | 20 | 30 | 40 | 50 |    |    |    |

\+----+----+----+----+----+----+----+----+

Example :

arr \= \[10, 20, 30, \_\]

size \= 3

capacity \= 4

append(40)

→ \[10, 20, 30, 40\]

## 

## 

## 

## **insert(index, value) — Shift Right**

* I decided that first before insert we must have a space in the array. If there is no space then need to resize and make space.

* After having extra space I thought the place must be vacant. To vacate it I thought to shift the elements to right by one index.

* The reason behind deciding to move the elements to right from that index is because we have extra space present on right side not left. If by any chance I move the element to left then the elements will be overwritten and I will lose data.

\============================================================

**CASE 1: INSERT AT START**

Insert(5) at index 0

\============================================================

**Before Insert**

Index:  0    1    2    3    4

       \+----+----+----+----+----+----+

       | 10 | 20 | 30 | 40 |    |    |

       \+----+----+----+----+----+----+

Shift elements right (from end toward start)

Move 40 : index 3 \-\> index 4

       \+----+----+----+----+----+----+

       | 10 | 20 | 30 | 40 | 40 |    |

       \+----+----+----+----+----+----+

Move 30 : index 2 \-\> index 3

       \+----+----+----+----+----+----+

       | 10 | 20 | 30 | 30 | 40 |    |

       \+----+----+----+----+----+----+

Move 20 : index 1 \-\> index 2

       \+----+----+----+----+----+----+

       | 10 | 20 | 20 | 30 | 40 |    |

       \+----+----+----+----+----+----+

Move 10 : index 0 \-\> index 1

       \+----+----+----+----+----+----+

       | 10 | 10 | 20 | 30 | 40 |    |

       \+----+----+----+----+----+----+

Insert 5 at index 0

       \+----+----+----+----+----+----+

       |  5 | 10 | 20 | 30 | 40 |    |

       \+----+----+----+----+----+----+

\============================================================

**CASE 2: INSERT IN MIDDLE**

Insert(25) at index 2

\============================================================

**Before Insert**

Index:  0    1    2    3    4

       \+----+----+----+----+----+----+

       | 10 | 20 | 30 | 40 |    |    |

       \+----+----+----+----+----+----+

Shift elements right

Move 40 : index 3 \-\> index 4

       \+----+----+----+----+----+----+

       | 10 | 20 | 30 | 40 | 40 |    |

       \+----+----+----+----+----+----+

Move 30 : index 2 \-\> index 3

       \+----+----+----+----+----+----+

       | 10 | 20 | 30 | 30 | 40 |    |

       \+----+----+----+----+----+----+

Insert 25 at index 2

       \+----+----+----+----+----+----+

       | 10 | 20 | 25 | 30 | 40 |    |

       \+----+----+----+----+----+----+

\============================================================

**CASE 3: INSERT AT END**

Insert(50) at index 4

\============================================================

Before Insert

Index:  0    1    2    3    4

       \+----+----+----+----+----+----+

       | 10 | 20 | 30 | 40 |    |    |

       \+----+----+----+----+----+----+

No shifting required

Insert 50 at index 4

       \+----+----+----+----+----+----+

       | 10 | 20 | 30 | 40 | 50 |    |

       \+----+----+----+----+----+----+

Example :

\[10, 20, 30, 40\]

insert(2, 25\)

→ shift right:

\[10, 20, 30, 30, 40\]

→ insert:

\[10, 20, 25, 30, 40\]

## 

## **remove(index) — Shift Left**

* I thought that when I call this function by passing an index, the value present at that index will be removed.

* But I noticed that if I am removing the last element it is working fine but if I remove element from the middle of the array then it will leave an empty space. In an array we have elements present in contiguous memory allocation. So to deal with this I decided that all the elements after the given index will shift by one to the left side — by doing this there will be no empty space left.

Example :

\[10, 20, 30, 40, 50\]

remove(2)

Step: remove 30

shift left

→ \[10, 20, 40, 50\]

\============================================================

**CASE 1: REMOVE FROM START**

Remove element at index 0 (value \= 10\)

\============================================================

**Before Remove**

Index:  0    1    2    3    4

       \+----+----+----+----+----+----+

       | 10 | 20 | 30 | 40 | 50 |    |

       \+----+----+----+----+----+----+

Shift elements left

Move 20 : index 1 \-\> index 0

       \+----+----+----+----+----+----+

       | 20 | 20 | 30 | 40 | 50 |    |

       \+----+----+----+----+----+----+

Move 30 : index 2 \-\> index 1

       \+----+----+----+----+----+----+

       | 20 | 30 | 30 | 40 | 50 |    |

       \+----+----+----+----+----+----+

Move 40 : index 3 \-\> index 2

       \+----+----+----+----+----+----+

       | 20 | 30 | 40 | 40 | 50 |    |

       \+----+----+----+----+----+----+

Move 50 : index 4 \-\> index 3

       \+----+----+----+----+----+----+

       | 20 | 30 | 40 | 50 | 50 |    |

       \+----+----+----+----+----+----+

Size decreases by 1

       \+----+----+----+----+----+----+

       | 20 | 30 | 40 | 50 |    |    |

       \+----+----+----+----+----+----+

\============================================================

**CASE 2: REMOVE FROM MIDDLE**

Remove element at index 2 (value \= 30\)

\============================================================

**Before Remove**

Index:  0    1    2    3    4

       \+----+----+----+----+----+----+

       | 10 | 20 | 30 | 40 | 50 |    |

       \+----+----+----+----+----+----+

Shift elements left

Move 40 : index 3 \-\> index 2

       \+----+----+----+----+----+----+

       | 10 | 20 | 40 | 40 | 50 |    |

       \+----+----+----+----+----+----+

Move 50 : index 4 \-\> index 3

       \+----+----+----+----+----+----+

       | 10 | 20 | 40 | 50 | 50 |    |

       \+----+----+----+----+----+----+

Size decreases by 1

       \+----+----+----+----+----+----+

       | 10 | 20 | 40 | 50 |    |    |

       \+----+----+----+----+----+----+

\============================================================

**CASE 3: REMOVE FROM END**

Remove element at index 4 (value \= 50\)

\============================================================

**Before Remove**

Index:  0    1    2    3    4

       \+----+----+----+----+----+----+

       | 10 | 20 | 30 | 40 | 50 |    |

       \+----+----+----+----+----+----+

No shifting required

Simply decrease size

       \+----+----+----+----+----+----+

       | 10 | 20 | 30 | 40 |    |    |

       \+----+----+----+----+----+----+

## **get(index) — Direct Address Calculation**

* When I made the Dynamic Array, I stored all its elements in contiguous memory locations. Because of this, every element can be accessed directly using its index.

* The CPU internally calculates the address of the element and directly jumps to that location instead of visiting every element one by one.

* address \= base\_address \+ index \* sizeof(T)

Example :

Assume:

Base Address \= 1000

sizeof(int)  \= 4 bytes

 10    20    30    40

  │     │     │     │

1000  1004  1008  1012

get(2)

address \= base\_address \+ index × sizeof(int)

address \= 1000 \+ 2 × 4

address \= 1008

So the CPU directly accesses address 1008 and returns 30.

\============================================================

**CASE 1: GET FIRST ELEMENT**

get(0)

\============================================================

Index:  0    1    2    3    4

       \+----+----+----+----+----+

       | 10 | 20 | 30 | 40 | 50 |

       \+----+----+----+----+----+

         ^

         |

      index 0

Return: 10

\============================================================

**CASE 2: GET MIDDLE ELEMENT**

get(2)

\============================================================

Index:  0    1    2    3    4

       \+----+----+----+----+----+

       | 10 | 20 | 30 | 40 | 50 |

       \+----+----+----+----+----+

                   ^

                   |

                index 2

Return: 30

\============================================================

**CASE 3: GET LAST ELEMENT**

get(4)

\============================================================

Index:  0    1    2    3    4

       \+----+----+----+----+----+

       | 10 | 20 | 30 | 40 | 50 |

       \+----+----+----+----+----+

                             ^

                             |

                          index 4

Return: 50

\============================================================

**HOW GET WORKS INTERNALLY**

\============================================================

Base Address \= 1000

Element Size \= 4 bytes (int)

Index:        0       1       2       3       4

Address:    1000    1004    1008    1012    1016

             \+----+----+----+----+----+

             | 10 | 20 | 30 | 40 | 50 |

             \+----+----+----+----+----+

               |     |     |     |     |

             1000  1004  1008  1012  1016

Example: get(2)

Address \= Base \+ (Index × Element Size)

        \= 1000 \+ (2 × 4\)

        \= 1008

Read value at address 1008

Return: 30

## **ShrinkToFit()** 

**Current State**

Size \= 4, Capacity \= 8

**Step 1: Allocate New Smaller Array**

Old Array (Capacity \= 8\)                       New Array (Capacity \= 4\)

\+----+----+----+----+----+----+----+----+      \+----+----+----+----+

| 10 | 20 | 30 | 40 |      |      |       |     |      |        |      |     |      |

\+----+----+----+----+----+----+----+----+      \+----+----+----+----+

**Step 2: Copy Elements**

Old Array (Capacity \= 8\)                        New Array (Capacity \= 4\)

\+----+----+----+----+----+----+----+----+      \+----+----+----+----+

| 10 | 20 | 30 | 40 |       |     |      |      | \----\>| 10 | 20 | 30 | 40 |

\+----+----+----+----+----+----+----+----+      \+----+----+----+----+

**Step 3: Update Pointer**

Old Array (Capacity \= 8\)                         New Array (Capacity \= 4\)

\+----+----+----+----+----+----+----+----+      \+----+----+----+----+

| 10 | 20 | 30 | 40 |      |      |      |      |       | 10 | 20 | 30 | 40 |

\+----+----+----+----+----+----+----+----+      \+----+----+----+----+

                                             		          ^

                                               		          |

                                              		        ptr

**Step 4: Free Old Array**

Old Array (released)                                 New Array (Current)

\+----+----+----+----+----+----+----+----+            \+----+----+----+----+

| XX | XX | XX | XX | XX | XX | XX | XX |      | 10 | 20 | 30 | 40 |

\+----+----+----+----+----+----+----+----+           \+----+----+----+----+

 released                                                        ^

                                                                       |

                                                                     ptr

**Final State**

Size \= 4

Capacity \= 4

              


                    ptr

                      |

                      v

                \+----+----+----+----+

                | 10 | 20 | 30 | 40 |

                \+----+----+----+----+

## **size() — How it works**

* I implemented this function by simply returning currentSize, which is a private variable of the class. Since I already maintain the count of how many elements are present in the array, I decided not to traverse the array again. Instead, I just return the value of currentSize.

Example :

DynamicArray\<int\> arr;

arr.append(10);

arr.append(20);

arr.append(30);

size(); // Returns 3

## **capacity() — How it works**

* I implemented this function by simply returning currentCapacity, which is a private variable of the class. Since I already maintain the maximum number of elements that can be stored in the array, I decided not to calculate it again. Instead, I just return the value of currentCapacity.

Example :

DynamicArray\<int\> arr;

arr.append(10);

arr.append(20);

arr.append(30);

capacity();   // Returns 4

arr \= \[10, 20, 30, \_\]

size \= 3

capacity \= 4

The array currently contains 3 elements, but space for 4 elements has been allocated.

## **Destructor — Memory Diagram**

### **Before Destructor**

 Stack              Heap                             Heap

arr —------\> data ───────────────────────► \[10\]\[20\]\[30\]\[40\]

               currentSize    \= 4

               currentCapacity \= 4

### **Destructor Executes**

delete\[\] data;

data \= nullptr;

### **After Destructor**

Stack         Heap                     Heap

Arr ─────►    Data   ─────►           nullptr

Heap Memory Released

Now the memory can be reused by the system.

### **Full Diagram**

   Object (Stack)

     Data    —-───────┐

     currentSize \= 3  │

     capacity \= 4     │

                      │

                      ▼

                   Heap Memory

               \+----+----+----+----+

               | 10 | 20 | 30 |    |

               \+----+----+----+----+

During Destructor :

delete\[\] data;

Heap memory is released.

After Destructor :

Object Destroyed

data \= nullptr

Heap Memory Released

## **Copy Constructor — Memory Diagram**

### **Default Shallow Copy (Problem)**

arr1.data ──┐

            ├──► \[10\]\[20\]\[ \]

arr2.data ──┘

Both objects point to the same heap memory.

### **Deep Copy (Solution) — Before Copy**

                        Stack

                     ┌─────────────────────┐

                     │ DynamicArray Object │

                     │ size \= 3            │

                     │ capacity \= 4        │

                     │ data ─────────────┐ │

                     └───────────────────│─┘ 

                                         ▼

          Heap                          \[10\]\[20\]\[30\]\[ \] 

### **During Copy Constructor**

                         Stack

                     ┌─────────────────────┐

                     │ DynamicArray Object │

                     │ size \= 3            │

                     │ capacity \= 4        │

                     │ data ─────────────┐ │

                     └───────────────────│─┘ 

                                         ▼

                Heap                    \[  \]\[  \]\[  \]\[  \]

                        

                     ┌─────────────────────┐

                     │ DynamicArray Object │

                     │ size \= 3            │

                     │ capacity \= 4        │

                     │ data ─────────────┐ │

                     └───────────────────│─┘ 

                                         ▼

                 Heap                   \[10\]\[20\]\[30\]\[ \] 

### **After Copy**

                        Stack

				Object 1

                     ┌─────────────────────┐

                     │ DynamicArray Object │

                     │ size \= 3            │

                     │ capacity \= 4        │

                     │ data ─────────────┐ │

                     └───────────────────│─┘ 

                                         ▼

                  Heap                 \[10\]\[20\]\[30\]\[ \]

				Object 2

                     ┌─────────────────────┐

                     │ DynamicArray Object │

                     │ size \= 3            │

                     │ capacity \= 4        │

                     │ data ─────────────┐ │

                     └───────────────────│─┘ 

                                         ▼

                    Heap               \[10\]\[20\]\[30\]\[ \] 

Now both objects have separate memory blocks.

If I modify arr2, arr1 remains unchanged.

## 

## **Copy Assignment Operator — Memory Diagram**

### **Before Assignment**

arr1.data ─────► \[10\]\[20\]\[30\]

arr2.data ─────► \[5\]\[6\]

### **During Assignment**

Delete arr2 Memory

arr2.data ─────► released

Allocate New Memory

arr2.data ─────► \[ \]\[ \]\[ \]

Copy Elements

arr2.data ─────► \[10\]\[20\]\[30\]

### **After Assignment**

arr1.data ─────► \[10\]\[20\]\[30\]

arr2.data ─────► \[10\]\[20\]\[30\]

Both objects contain the same values but own different memory blocks.

**Part 3**  —  Complexity Estimates

# **Dynamic Array — Time Complexity**

## **1\. resize(newCap)**

**Time Complexity : O(n)**

* I noticed that every time resize happens the old elements present in the old block will be copied to the newly allocated block. That is, if I have N elements in my old array and then resize happens then each element will be processed once. So the Time Complexity of this function is **O(n).**

Example :

\[10, 20, 30, 40\] → new array

copy all 4 elements → O(n)

## **2\. append(value)**

### **Best / Most cases : O(1)**

* At first I took an array with size 2 and capacity 4 then I tried to append an element inside the array. As it already has space the element gets inserted at the end directly. Hence size=3, capacity=4.

* Then I again tried to append one more element inside the array. It still has one element space so the new element gets inserted at the end. Size=4, capacity=4.

* While doing this I noticed that the element gets inserted directly at the place as I have already the space. So the element gets inserted with constant time complexity. So its time complexity is O(1).

### **Worst Case : O(n)**

* Then I again tried to append another element inside the same array. I noticed that the size and capacity are equal so the resize function will be triggered. So elements get copied from the old block to the new block leading to processing of each element present in the array.

* Then I thought if I had N elements in the array and the size and capacity are equal then resizing would happen before inserting the element. This will lead to the Time Complexity being O(n). For insertion at end this is the worst case.

### **Amortized Time Complexity : O(1)**

* Here I have taken overall time complexity of the append operation as amortized O(1). That is the average cost of the append per operation will nearly be constant even if resizing is happening. I came to this conclusion by appending elements one by one and calculating cost:

Size=0  capacity=4

Append(10) → size=1 and cost=1

Append(20) → size=2 and cost=1

Append(30) → size=3 and cost=1

Append(40) → size=4 and cost=1

Append(50) → size=5 and cost=5  capacity=8

Append(60) → size=6 and cost=1  capacity=8

Append(70) → size=7 and cost=1  capacity=8

Append(80) → size=8 and cost=1  capacity=8

Total cost \= 1+1+1+1+5+1+1+1 \= 12

For each operation its average is nearly 1.5

* As we know in normal insertion for n elements cost is n.

* And the resizing also costs less than n for n insertions.

* We have a total less than 2n cost for n elements. Then for each element we have cost less than 2 which is a constant. Hence the time complexity here is considered Amortized O(1).

## **3\. insert(index, value)**

### **Best Case : O(1)**

* I noticed when this type of insertion happens it is the same as append in which we have **index \== currentSize** . The cost of this insertion is 1 which is constant. Hence its Time Complexity is O(1).

### **Average Case : O(n)**

* While doing this type of insertion I noticed that I need to shift almost or nearly half of the elements of the array. So if I have N elements then I need to shift nearly N/2 elements. So it will be O(N). Because we know that Big-O ignores constant values so it will be O(n).

### **Worst Case : O(n)**

* First I considered the case where I need to insert at beginning. Then I noticed that all the elements are shifted to the right — all elements are processed one time. This leads to the Time Complexity becoming O(n).

* In the second case, during resizing the cost is N and for the shifting it will again be N. So the total cost will be 2N. Leading to Time Complexity being O(2N) but since Big-O ignores constants so it will be O(n).

## **4\. remove(index)**

### **Best Case : O(1)**

* When I remove an element at the end of the array, not even a single shift of element is happening due to which no extra work is done. Just a single update is happening and this happens in constant time so its Time Complexity is O(1).

\[ 10,20,30,40 \]  size=4

remove(size-1)

It will remove the last element which is 40 and then update size.

Array will be \[10,20,30\]  size=3

### **Average Case : O(n)**

* While removing elements near the mid of the array and around it I noticed that I need to shift almost half of the elements to the left because of the empty space. So almost n/2 elements are processed in this case. The Time Complexity becomes O(n) as Big-O ignores constants.

### **Worst Case : O(n)**

* While removing elements from the beginning I noticed that I have to shift all the elements to the left to fill up the empty space. Due to which all elements are processed once in this function which leads to Time Complexity being O(n) directly.

## **5\. get(index)**

**Time Complexity : O(1)**

* The Time complexity of this function is O(1). The reason is that when I say I want element at 5th index then it does not traverse to the 5th element one by one. It has a base address from where the storage of elements starts so the CPU internally calculates the address of the element and directly jumps to that location instead of visiting every element one by one.

* address \= base\_address \+ index \* sizeof(T)

## **6\. size()**

**Time Complexity : O(1)**

* While implementing this function, I was simply returning the value of currentSize, which is stored as a private variable of the class. Since this operation only returns a single value and does not process any elements of the array, it happens in constant time.

## **7\. capacity()**

**Time Complexity : O(1)**

* While implementing this function, I was simply returning the value of currentCapacity, which is stored as a private variable of the class. Since this operation only returns a single value and does not process any elements of the array, it happens in constant time.

## **8\. Copy Assignment Operator**

**Time Complexity : O(n)**

* While implementing the assignment operator, I noticed that every element must be copied from the source array into the destination array.

* If there are N elements: old memory is released, N elements are copied. Since each element is processed once: Time Complexity \= O(n).


## **9\. shrinkToFit()**

**Time Complexity : O(n)**

* In implementation, what I have done is allocating a new block of memory and then copying each element to the new block. By doing this I have processed each element once. If the array has n elements then its cost will be n leading to the Time Complexity being O(n).

**Part 4**  —  Design Decisions

# **Dynamic Array — Design Decisions**

## **Why Dynamic Array is needed**

* I needed to store some elements together, but I did not know how many elements would be needed later in the program. Because of this, a fixed-size array was not suitable since its size is decided at the time of creation and it cannot grow when more elements need to be stored.

* To solve this problem, I decided to make a collection in which I can add elements whenever needed. Since the number of elements can increase during program execution, I needed memory that could be allocated and expanded at runtime. Therefore, I decided to use heap memory, which allows dynamic memory allocation.

* As the array is stored on the heap, I need a pointer to store the address of the allocated memory and access its elements. By keeping track of this address and resizing the allocated memory whenever required, I can store a variable number of elements in the collection.

* Fixed-size arrays have a limitation that they cannot grow dynamically after creation.

int arr\[5\];

\- If user inserts 10 elements → program fails

\- If user inserts only 2 elements → memory is wasted

## **Decision : Template Class instead of int-only**

* At first, I thought of implementing the Dynamic Array using int because it was easier to understand and test. However, after thinking about it, I noticed that a Dynamic Array is not limited to storing only integers.


DynamicArray\<int\>

DynamicArray\<double\>

DynamicArray\<char\>

DynamicArray\<string\>

All of these should be possible using the same implementation.

* I did not want to write separate classes for every data type because the logic of storing elements, resizing, inserting, and removing remains exactly the same. Only the data type changes.

* To solve this problem, I decided to make the Dynamic Array a template class. A template allows me to replace the data type with a placeholder (T) and use the same implementation for any type of data.


## **Class Invariants** 

| 0 ≤ currentSize ≤ currentCapacity  |
| :---- |
| currentCapacity ≥ minCapacity  |
| data ≠ nullptr , if currentCapacity \> 0  |
| Valid indices: `0 ≤ i < currentSize`  |
| Allocated memory size \= `currentCapacity` elements  |
| Stored elements occupy indices `[0, currentSize - 1]`  |

## **Decision : Default Values — Size \= 0 and Capacity \= 4**

### **Size \= 0**

* At first I thought to take the size as 0 because I am just allocating memory not inserting any element in the dynamic array. If there are no elements in the array then size should be zero.

Before inserting anything:

arr \= \[\]

size \= 0

### 

### **Capacity \= 4**

* I have considered this value initially because I thought that if I take a very small value then I will need to resize it again and again in the beginning itself. Since resizing involves allocating new memory and copying all existing elements from the old block to the new block, it increases CPU work and reduces performance.

* At first I considered capacity=1, then after resize it will increase (I thought to resize it with \*2 factor) this will make it 1→2→4→8. In this process, resizing happens very frequently in the beginning, and copying of elements also happens again and again. So I noticed that small capacity leads to frequent resizing operations which increases overall overhead.

* On the other hand, if the capacity is too large (for example 100\) and I have very few elements like 5, then most of the memory will remain unused. This leads to memory wastage. If capacity=100 but only 5 elements are inserted, then 95 spaces remain unused which is wasted memory.

* So I decided that instead of fixing a very large or very small value, I will start with a moderate capacity (like 4\) and then let it grow dynamically using a growth factor (like 2). This gives a balance between:

  * avoiding frequent resizing in the beginning

  * avoiding large memory wastage

## **Decision : Growth Factor \= 2 for resize()**

* I thought not to use a constant value but make it connected to the previous capacity of the array so that neither it will be too small nor it will be too large. It is calculated using a growth factor strategy, where the current capacity is multiplied by a constant factor (commonly 2).

* At first I decided to use growth factor \= 1.5

  Sequence: 1→1.5→2.25→3.375→5.06…

  Rounded:  1→2→3→4→6→9→13…

      I noticed that:

* resizes happen very frequently

  * many element copies are required during resizing

  * amortized cost is higher due to repeated reallocations → so this is not efficient in practice


* Then I increased the growth factor to 1.75

  Sequence: 1→1.75→3.06→5.35→9.36→16.38…

  Rounded:  1→2→3→5→9→16→29→50→88→154…

       I observed that:

* resizes reduced compared to 1.5

  * amortized cost improved

  * but memory usage started getting worse due to larger jumps → still not fully balanced


* Next I tried growth factor \= 2

  Sequence: 1→2→4→8→16→32→64…

       I noticed that:

* number of resizes becomes logarithmic O(log n)

  * total element copying reduces significantly

  * amortized insertion cost becomes O(1) → overall best balance between CPU and memory


* Then I tried growth factor \= 2.25

  Sequence: 1→2.25→5.06→11.39→25.63→57.67…

  Rounded:  1→2→5→11→26→58→130→292→658…

       I observed that:

* resizes become very rare → amortized cost improves further

  * but memory wastage increases significantly

  * example: if elements=27, capacity≈58 → utilization≈27/58≈0.465 → inefficient memory usage

* Final observation — I concluded that:

  * increasing growth factor reduces number of resizes

  * decreases amortized CPU cost

  * but increases memory overhead due to unused capacity

  * decreasing growth factor improves memory usage but increases resize cost

  * So I decided that growth factor \= 2 gives the best practical trade-off because:

  * amortized insertion cost \= O(1)

  * resizes are minimal (logarithmic)

  * memory usage is acceptable compared to higher growth factors


## **Decision : Shrink Strategy in remove()**

* Regarding the question given in the context document I thought about it and concluded that the capacity does not shrink when I delete an element because I am deleting elements and then updating size not the capacity so the capacity will be the same.

* Then a question came to my mind that **if the capacity is very large and the elements present in the array are very less then it is typically memory wastage.**

* Then I thought if capacity can increase as per need then why can't it shrink according to the requirement. So like in resize by giving a condition I was allocating a new block of memory greater than the current one then why can't I allocate a new block of memory smaller than the current and copy the element there.

* But then another question came to my mind: **when to shrink the capacity?**

* **Should I decrease it with every delete operation?** In this case new memory allocation will happen after every element deletion and elements will be copied frequently. This is not a good practice.

* Then I thought why not shrink it if the size is very smaller than the capacity of the array. I thought of considering if **size \<= capacity/4** then it is comparatively very small than the capacity.

* Then I also thought that if my **size=1** and **capacity=4** then here **size\<=capacity/4** but here the initial capacity that I decided has been reduced and if I decided to add more elements then frequent resizing will happen which I don't want. So I decided that the **capacity/2** should be greater than or equal to the minimum capacity that I took in initialization. The reason is that after reducing it, if it goes below **mincap** then it would break the lower bound of my design.

* So I decided to keep the condition as: **size \<= capacity/4  AND  capacity/2 \>= mincap(4)**

Eg: size=8, capacity=64 → 8\<=64/4 ✓  and  32\>=4 ✓

So shrink the array by 1/2 →  new capacity \= 32

* The reason behind decreasing it by half is that it reduces the capacity while still leaving enough space for future insertions. This will help in avoiding frequent shrink and resizing of the array.

* I decided to attach this condition while deleting the elements from the array to automate this process as removal of elements is only happening through the remove() method, so I will attach this condition in the remove method.

* Then again a question came to my mind: **what if I know that I don't need to insert any element in the array, then if the array has unused space in it then it will go waste**. So if I already know that I don't need to insert more elements in the array then I decided why not make a method — **shrinkToFit()** — in which I will allocate the memory only according to the size of the array.

## **Rule of Three — Why all three are needed**

* While implementing the Dynamic Array, I noticed that the class is managing memory manually using a pointer (data) and dynamic memory allocation (new and delete\[\]).

* Because of this, I started thinking about what would happen if:


DynamicArray\<int\> arr1;

arr1.append(10);

arr1.append(20);

DynamicArray\<int\> arr2 \= arr1;

* At first, I expected that arr2 would get its own copy of the array. However, I noticed that C++ provides a default copy mechanism which only copies the values of data members.

* So after copying:

arr1.data ──┐

            ├──► \[10\]\[20\]\[ \]

arr2.data ──┘

Both objects point to the same heap memory.

### **Problem 1 : Unwanted Shared Data**

* If one object modifies the array: arr2.insert(1, 50); then the changes also affect arr1 because both objects are using the same memory block.

### **Problem 2 : Double Deletion**

* When both objects are destroyed: arr1 goes out of scope, arr2 goes out of scope. Both destructors try to free the same heap memory.

delete\[\] data;

delete\[\] data;   // same memory again

This causes undefined behavior and may crash the program.

### **Solution**

* To solve this problem, I decided that every Dynamic Array object should have its own separate copy of the data. Whenever copying happens:

  * New memory should be allocated

  * Elements should be copied individually

  * Each object should own its own memory block

* Because my class manages dynamic memory, I need to define three special member functions: **Destructor, Copy Constructor, Copy Assignment Operator.** This concept is known as the **Rule of Three.**

* If a class defines any one of: **Destructor, Copy Constructor, or Copy Assignment Operator** — then it usually needs to define all three. This ensures proper memory management and prevents shallow-copy related problems.

## 

## 

## **Copy Constructor — Why deep copy instead of shallow copy**

* At first, I thought this would automatically create a completely independent copy of the array. However, I discovered that the default copy constructor provided by C++ performs a shallow copy. That means only the values of the data members are copied.

* Both objects point to the same heap memory. This creates problems:

  * Modifying one object affects the other

  * Both destructors try to free the same memory

  * This can lead to crashes and undefined behavior

* To solve this problem, I decided to implement my own Copy Constructor that performs a deep copy. When a new Dynamic Array is created from an existing one:

  * Copy the size

  * Copy the capacity

  * Allocate a new heap array of the same capacity

  * Copy each element individually into the new array


## **Copy Assignment Operator — Self Assignment Check**

* After implementing the Copy Constructor, I noticed another way copying can happen:


DynamicArray\<int\> arr1;

DynamicArray\<int\> arr2;

arr2 \= arr1;

* Here arr2 already exists. So a constructor cannot be called because constructors only execute during object creation. Instead, the assignment operator is called.

* If I rely on the default assignment operator provided by C++, it will again perform a shallow copy. This causes the same problems: shared memory, unexpected modifications, double deletion. Therefore, I decided to implement my own **Copy Assignment Operator.**

* When assignment happens: arr2 \= arr1; I decided to perform the following steps:

  * Check for self-assignment

  * Free old memory owned by arr2

  * Copy size and capacity

  * Allocate new memory

  * Copy all elements individually

  * Return the current object

* While implementing this operator, I noticed a special case: arr1 \= arr1; If I directly delete memory before checking this case, I will destroy my own data and then attempt to copy from it. To avoid this problem, I first check:


if (this \== \&other)

{

   return \*this;

}

If both objects are the same, no work is needed.

## **Exception Handling**

| Operation  | Condition | Exception Thrown | Handling |
| :---- | :---- | :---- | :---- |
|   get(index) | `index < 0 ∨ index ≥ currentSize` | `std::out_of_range` | Exception is thrown to prevent access to an invalid index |
|  insert(index, value)  | `index < 0 ∨ index > currentSize` | `std::out_of_range` | Exception is thrown because insertion outside the valid range is not allowed |
|  remove(index)  | `index < 0 ∨ index ≥ currentSize` | `std::out_of_range` | Exception is thrown because there is no element at the specified index. |
|  Memory Allocation   | `Memory allocation fails`  | `std::bad_alloc`  | Automatically thrown by `my_new` if memory cannot be allocated.  |

I have included the `<stdexcept>` header and used standard C++ exceptions to handle invalid operations. Whenever a user attempts to access an invalid index, insert at an invalid position, remove from an invalid position, or provide an invalid capacity, an appropriate exception such as `std::out_of_range` or `std::invalid_argument` is thrown. Memory allocation failures are handled automatically by the C++ runtime through `std::bad_alloc`.

