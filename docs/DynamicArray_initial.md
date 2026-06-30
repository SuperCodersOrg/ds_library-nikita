SuperCoders Project 01

Design Proposal - Collection library and Redis Lite

Name - Nikita                                    Date - 30-06-2026



Dynamic Array



I needed to store some elements together, but I did not know how many elements would be needed later in the program. Because of this, a fixed-size array was not suitable since its size is decided at the time of creation and it cannot grow when more elements need to be stored.

To solve this problem, I decided to make a collection in which I can add elements whenever needed. Since the number of elements can increase during program execution, I needed memory that could be allocated and expanded at runtime. Therefore, I decided to use heap memory, which allows dynamic memory allocation.

As the array is stored on the heap, I need a pointer to store the address of the allocated memory and access its elements. By keeping track of this address and resizing the allocated memory whenever required, I can store a variable number of elements in the collection.

This collection is what I call a Dynamic Array.

Example:

If user input is unknown:

Input: 10 elements today, 100 elements tomorrow

A fixed array fails, but a dynamic array can grow as needed



Why Dynamic Array is needed

Fixed-size arrays have a limitation that they cannot grow dynamically after creation.

Example :

int arr[5];

If user inserts 10 elements → program fails

If user inserts only 2 elements → memory is wasted

So we need a structure that grows as required.



\# Basic Internal Structure

To implement Dynamic Array we need :



A pointer : that will point to the location where the array is stored in heap



Size : size tells how many elements are present in the array so that we can know where to insert the next element . If i don’t know the size then how will i know where to insert the next element in the collection



Capacity : to know maximum number of elements that can be stored in the collection / array

And if my array is full  size == capacity so i can also make a new array with better capacity that is by resizing so that more elements can be inserted .

Example:

arr = [10, 20, 30, \_, \_]

size = 3

capacity = 5

3 elements are used

2 spaces are free



Class of Dynamic Array :

At first, I thought of implementing the Dynamic Array using int because it was easier to understand and test. However, after thinking about it, I noticed that a Dynamic Array is not limited to storing only integers.

`	`DynamicArray<int>

DynamicArray<double>

DynamicArray<char>

DynamicArray<string>



All of these should be possible using the same implementation.

I did not want to write separate classes for every data type because the logic of storing elements, resizing, inserting, and removing remains exactly the same. Only the data type changes.

To solve this problem, I decided to make the Dynamic Array a template class. A template allows me to replace the data type with a placeholder (T) and use the same implementation for any type of data.



Default Values Decisions:



Size = 0

At first i thought to take the size as 0 because  i am just allocating memory not inserting any element in the dynamic array. If there are no elements in the array then should should be zero

Example:

Before inserting anything:

arr = []

size = 0



Capacity = 4

I have considered this value initially because I thought that if I take a very small value then I will need to resize it again and again in the beginning itself. Since resizing involves allocating new memory and copying all existing elements from the old block to the new block, it increases CPU work and reduces performance.

Eg: At first I consider capacity = 1, then after resize it will increase (I thought to resize it with \*2 factor) this will make it 1 → 2 → 4 → 8. In this process, resizing happens very frequently in the beginning, and copying of elements also happens again and again.

So I noticed that small capacity leads to frequent resizing operations which increases overall overhead.

On the other hand, if the capacity is too large (for example 100) and I have very few elements like 5, then most of the memory will remain unused. This leads to memory wastage.

Eg: If capacity = 100 but only 5 elements are inserted, then 95 spaces remain unused which is wasted memory.

So I decided that instead of fixing a very large or very small value, I will start with a moderate capacity (like 4) and then let it grow dynamically using a growth factor (like 2). This gives a balance between:

avoiding frequent resizing in the beginning

avoiding large memory wastage





Data(Pointer) :

As  i am using heap for the storage of the elements so to access the array i must have its address so i decided to make a pointer in stack and point it to the array .

The data type of this pointer will depend on the type of elements stored in the Dynamic Array. For example, if the array stores integers, the pointer type will be int\*. If the array stores characters, the pointer type will be char\*.

Example:

data → heap memory address

data[0], data[1], ...

Without a pointer, we cannot access heap array.







Constructor .

DynamicArray() : To create a valid object of the Dynamic Array from the class made

Why is it needed?

Before implementing Dynamic Array  I must have a valid object . If I leave the data members uninitialized then they will have garbage values which may lead to undefined behaviour .

So i decided to make a default constructor which will initialise all the data members with proper and valid values

Example :

DynamicArray<int> arr;

As soon as this object created , this constructor will automatically execute .



How it works:

When the object is created:

I allocate memory on the heap using the initial capacity.

I set currentSize to 0 because no elements have been inserted yet.

I set currentCapacity to the default capacity chosen earlier (4).

I store the address of the allocated memory inside data.

Example :

Before Constructor :

DynamicArray<int> arr;

Memory:

data = garbage

currentSize = garbage

currentCapacity = garbage

After Constructor :

data ───► [ \_ | \_ | \_ | \_ ]

currentSize = 0

currentCapacity = 4



Functions:



1. resize(newCap) :



I thought instead of giving large value to the capacity, why don’t I give a standard value and then alter it as needed . So I decided that I will resize it as per the need . To resize the array I made this function .

Parameter: newCap :

newCapacity → it is the parameter that will decide the new value of the capacity.

And I thought not to use a constant value but make it connected to the previous capacity of the array so that neither it will be too small nor it will be too large  . It is calculated using a growth factor strategy, where the current capacity is multiplied by a constant factor (commonly 2).

The growth factor is used to decide how much the array should grow during resizing. I decided to use a factor of 2 because it provides a balance between performance and memory usage.

At first I decided to use growth factor = 1.5

→ new capacity:

Cn​=Cn−1​⋅1.5

Sequence:  1 → 1.5 → 2.25 → 3.375 → 5.06 → …

Rounded:  1 → 2 → 3 → 4 → 6 → 9 → 13 → …

I noticed that:

resizes happen very frequently

many element copies are required during resizing

amortized cost is higher due to repeated reallocations

→ so this is not efficient in practice



Then I increased the growth factor to 1.75

Sequence:  1 → 1.75 → 3.06 → 5.35 → 9.36 → 16.38 → 28.66 → 50.16 → 87.78 → 153.6 → …

Rounded: 1 → 2 → 3 → 5 → 9 → 16 → 29 → 50 → 88 → 154 → …

I observed that:

resizes reduced compared to 1.5

amortized cost improved

but memory usage started getting worse due to larger jumps

→ still not fully balanced



Next I tried growth factor = 2

Sequence:  1 → 2 → 4 → 8 → 16 → 32 → 64 → …

I noticed that:

number of resizes becomes logarithmic O(log⁡n)O(\log n)O(logn)

total element copying reduces significantly

amortized insertion cost becomes O(1)O(1)O(1)

→ overall best balance between CPU and memory



Then I tried growth factor = 2.25

Sequence:

1. → 2.25 → 5.06 → 11.39 → 25.63 → 57.67 → 129.76 → 291.96 → 657.91 → …

Rounded:

1. → 2 → 5 → 11 → 26 → 58 → 130 → 292 → 658 → …

I observed that:

resizes become very rare → amortized cost improves further

but memory wastage increases significantly

example: if elements = 27, capacity ≈ 58

→ utilization ≈ 27/58 ≈ 0.465

→ inefficient memory usage





Final observation

I concluded that:

increasing growth factor reduces number of resizes

decreases amortized CPU cost

but increases memory overhead due to unused capacity

decreasing growth factor improves memory usage but increases resize cost

So I decided that growth factor = 2 gives the best practical trade-off because:

amortized insertion cost = O(1)

resizes are minimal (logarithmic)

memory usage is acceptable compared to higher growth factors



Time Complexity: O(n)

I noticed that every time resize happens the old elements present in the old block will be copied to the newly allocated block .  That is, I can say that if I have N elements in my old array and then resize happens then each element will be processed once . So the Time Complexity of this function is O(n).

Example:

[10, 20, 30, 40] → new array

copy all 4 elements → O(n)





Return Type :

I decided to keep the return type of this function as void because what it does is allocate new memory , copy elements , and free old block of memory. These processes are directly happening with the object so there is no need to return anything from this function .















\### 2. append(value) : Adding an element to a dynamic array



This function will be adding new elements at the end of the dynamic array that I have.

Also , at first I kept the capacity 4 if the elements exceed 4 then need to resize the array so i attached the resize function with this function.

\### Parameter:

Value  -> The value that will be inserted

\### How it works:

If size < capacity

→ Insert element at arr[size] and increment size.

If size == capacity

→ Call resize(newCap) (usually newCap = capacity \* 2)

→ Copy old elements to new memory

→ Free old memory

→ Then insert the new element

Example:

arr = [10, 20, 30, \_]

size = 3

capacity = 4

append(40)

→ [10, 20, 30, 40]



\### Time Complexity:

\####  Best / Most cases: O(1)

At first I took an array with size 2 and capacity 4 then i tried to append an element inside the array as it has already the size so the element gets inserted at the end directly

Hence size =3 , capacity =4

Then I again tried to append one more element inside the array. It still has one element space to insert at one so the new element gets inserted at the end.

Size =4 , capacity =4

While doing this i noticed that the element gets inserted directly at the place as i have already size in the stack so the element gets inserted with constant time complexity

So its time complexity is O(1)



\####  Worst case: O(n)

Then I again tried to append another element inside the same array here. I noticed that the size and capacity are equal so the resize function will be triggered . So elements get copied from the old block to the new block leading to processing of each element present in the array .

Then I thought if I had N elements in the array and the size and capacity are equal then resizing would happen before inserting the element . This will lead to the Time Complexity being O(n) . For this insertion at end and the time complexity for this cannot be more worse then this so It is considered Worst case



\### Amortized Time Complexity: O(1)

Here I have taken overall time complexity of the append operation as amortized O(1)

That is the average cost of the append per operation will nearly  be constant even if resizing is happening I came to this conclusion by appending elements one by one and calculating cost

Size =0  capacity =4

Append(10) -> size =1 and cost =1

Append(20) -> size =2 and cost =1

Append(30) -> size = 3 and cost =1

Append (40) -> size =4 and cost =1

Append(50) -> size = 5 and cost =5 capacity =8

Append (60) -> size =6 and cost 1  capacity =8

Append (70) -> size =7 and cost 1   capacity =8

Append (80) -> size =8 and cost 1   capacity =8



Total cost =  1+1+1+1+5+1+1+1 = 12

For each operation its average is nearly 1.5



As we know in normal insertion for n elements cost is n

And the resizing also cost is less than  n for n insertions

We have a total less than 2n cost  for n elements . then for each element we have cost less than 2 which is a constant . Hence the time complexity here is considered Amortized O(1)





Return Type :

I thought to keep the return type of this as void because all it does is internal working like checking whether resize need or where to insert the value it does not return any value to the caller













\### 3. insert(index, value) : Adding an element to a dynamic array at a particular position

After adding the elements at the end I thought what if I need to add the element somewhere in the middle or any particular position Then I decided to make a function by which I can insert an element at any index in the array.



\### Parameters:

Index :  the value at which I need to insert if i won’t include this value then how will i know where to insert the new value

Value : the value which needs to be inserted in the array



\### How it works:

I decided that first I should think what will be happening when this type of insertion will happen So i decided that first before insert we must have a space in the array if there is no space then need to resize and make space

After having extra space I thought first the place must be vacant if i have to insert value at that index  to vacant it i thought to shift the elements to right by one index .

The reason behind deciding to move the elements to right from that index is because we have extra space present on right side not left and if by any chance I move the element to left then the elements will be overwritten and I will loose data

So after moving the elements to right by one index I will then insert the value at the given index

Example

[10, 20, 30, 40]

insert(2, 25)

→ shift right:

[10, 20, 30, 30, 40]

→ insert:

[10, 20, 25, 30, 40]



Time Complexity Analysis :

While inserting and observing  the ways in which i am inserting elements i have three cases first one is when i insert element at the end and i have space left in the array then  the time complexity will be





Best Case : O(1)

Why is it O(1) so i noticed when this type of insertion is that it is the same as append in which we have capacity still vacant . The cost of this insertion is 1 which is constant. Hence its Time Complexity is O(1)



The next one i noticed is i need to insert elements somewhere in the middle with the condition that i have capacity to store new element  then i need to shift the elements

Average Case : O(n)

Why  is it O(n) . While doing this type of insertion I noticed that I need to shift almost or nearly half of the elements of the array so if I have N elements then I need to shift nearly N/2 elements . So it will be O(N) . Because we know that Big-O ignores constant values so it will be O(n)



The next case is when I was trying to insert the elements at the beginning then I needed to shift all the elements to the right for inserting . Along with this when i don’t have capacity vacant also then resizing is also needed along with resizing shift will also happen.

Worst Case: O(n)

First i considered the case where i need to insert at beginning then i noticed that all the elements are shifted to the right that is all the elements are processed one time This leads to the Time Complexity becoming O(n)

In the second case , during resizing as we have discussed its cost is N and for the shifting it will again be N So the total cost will be 2N . Leading to Time Complexity being O(2N) but since Big-O ignores constant so it will be O(n)



Return Type :

I decided to make is return type as void as according to the its functionality it does all the working internally directly with the object and there is no need to  return anything to the caller















\### 4. remove(index) : To remove an element from a dynamic array

I thought that as I have made methods to add elements when needed so I should also make method to remove elements when they are no longer of use . This function does the work of removing elements from the dynamic array.



Parameter:

Index : this value tells the method from where to remove the element if it is not provided then the program will not know from where to remove the element



How it Works:

I thought that when i call this function by passing an index to this function then that index in the should become empty that is the value present at that index will be removed

But i noticed that if i am removing the last element it is working fine but if i remove element from the middle of the array then it will leave an empty space but in array we have elements present in contiguous memory allocation. So to deal with this i decided that all the elements are the given index will shift by one to the left side by doing this there will be no empty space left

Eg :

[10, 20, 30, 40, 50]

remove(2)

Step: remove 30

shift left

→ [10, 20, 40, 50]





Time Complexity Analysis :

I have analysed Time Complexity in three different Cases . I divided these according to the value of the index. The first one is when I remove an element at the end of the array I call it best case.



Best Case:  O(1)

The reason behind saying it is  constant is that when i remove an element at the end of the array then in this case not even a single shift of element is happening due to which no extra work is done . Just a single update is happening and this happens in constant time so its Time Complexity is O(1).



Eg : [ 10,20,30,40] , size =4 ,

remove(size -1)

It will remove the last element which 40 and then update size that  is  array will be [10,20,30]  size =3





The second case is when I removed elements near middle and the middle one



Average Case : O(n)

While removing elements near the mid of the array and around it I noticed that I need to shift almost half of the elements to the left because of space being empty . So almost n/2 elements are processed in this case due to which the Time Complexity of this becomes

O(n) as Big-O  ignores constants due to which it becomes O(n)



The last case is when I removed elements from the beginning . I consider this one as Worst Case



Worst Case : O(n)

While removing elements from the beginning I noticed that I have to shift all the elements to the left to fill up the empty space . Due to which all elements are processed once in this function which leads to Time Complexity being O(n) directly.



Return Type:

I decided to keep the return type of this function as void. The reason behind this is the working of this function. What it does is remove elements from the dynamic array and then decrease size it does not send or return anything to the caller .









5\. get(index) : Access an element by passing index

After adding and removing elements from the array I thought there should be a way to access element from the element randomly like if i say I want to access element from 4th index then i can access it directly . So I decided to make this function in which I will be passing just an index and it will give value present at that index .



Parameter :

Index : This value tells the function which element I want to access. If it is not provided then how will the function know what to access and from where to access



How it Works :

When I made the Dynamic Array, I stored all its elements in contiguous memory locations. Because of this, every element can be accessed directly using its index.

And in this function i used this concept that is I provided if this function is provided with valid index then it will return element present at that index.

Example :

[10,20,30,40]

get(2) -> 30



Also if it has been provided with an invalid index then it will raise an exception stating that Index is out of range it will be done by checking if the index is valid or not

If  index < 0 or index >= currentSize then it is invalid index

Example :

[10,20,30,\_]

get(-1) and get(4)  here both indexes are invalid because this array has only 3 elements at 0,1,2 indexes .



Time Complexity Analysis:

The Time complexity of this function is O(1) . The reason behind is that when i say i want element at 5th index then it does not traverse to 5th element one by one . But what it does is

It has address base address from where the storage of element start so the CPU internally calculates the address of the 5th index element and directly jumps to that location/address instead of visiting every element one by one.

`	`address = base\_address + index \* sizeof(T)

Example :

Assume:

Base Address = 1000

sizeof(int) = 4 bytes



Array:

10	 20	 30	 40

│	 │ 	│	 │

1000  1004    1008     1012

Now suppose I call:

get(2)

Address Calculation

address = base\_address + index × sizeof(int)

address = 1000 + 2 × 4

address = 1008

So the CPU directly accesses address 1008 and returns 30.



Return Type :

At first I thought to keep the return type of this function as void, but then I noticed that this function is returning an element to the caller. Since a value is being returned, the return type cannot be void.

Then I thought why not keep the return type as int. But another problem arose. What if the Dynamic Array is of string type? In that case the function would return a string, not an integer. Therefore, keeping the return type fixed as int would make the function work only for integer arrays.

After thinking about this, I noticed that the element being returned always belongs to the Dynamic Array itself. So if the Dynamic Array stores integers, the function should return an integer. If the Dynamic Array stores strings, the function should return a string.

Therefore, I decided to align the return type of this function with the type of elements stored in the Dynamic Array.

So decided it to keep as  T get(int index) const;





5\. size() : To get number of elements currently stored in the array

After adding, removing, and accessing elements from the array, I thought that there should be a way to know how many elements are currently stored in the Dynamic Array. Since the size is stored as a private data member of the class, it cannot be accessed directly from outside the class. Therefore, I decided to create a function that returns the current number of elements present in the array.

Why is this function useful?

The user of the Dynamic Array may need to know:

How many elements are currently stored.

Whether the array is empty (size() == 0).

How many elements can be accessed safely using indexes.

How many times a loop should run when traversing the array.

Example :

DynamicArray<int> arr;

arr.append(10);

arr.append(20);

arr.append(30);

size(); // Returns 3



How it works:

I implemented this function by simply returning currentSize, which is a private variable of the class. Since I already maintain the count of how many elements are present in the array, I decided not to traverse the array again. Instead, I just return the value of currentSize.



Time Complexity :

While implementing this function, I was simply returning the value of currentSize, which is stored as a private variable of the class. Since this operation only returns a single value and does not process any elements of the array, it happens in constant time.

Therefore, the Time Complexity of this function is O(1).



Return Type:

At first i thought to make it void then i noticed that it is returning size of the array which is integer and cannot be any other data type because the number of elements cannot be in float that is there is not chance that  2.6 or 5.5 elements are present in the array So I decided to keep the return type of this function as int

.6. capacity() : To get the maximum number of elements that can currently be stored in the array

After implementing functions for adding, removing, accessing elements, and getting the current size of the array, I thought that there should also be a way to know how much storage space is currently available in the Dynamic Array before resizing becomes necessary. Since the capacity is stored as a private data member of the class, it cannot be accessed directly from outside the class. Therefore, I decided to create a function that returns the current capacity of the array.

Why is this function useful?

The user of the Dynamic Array may need to know:

How many elements can currently be stored before resizing is required.

How much extra space is available in the array.

Whether the array is close to becoming full.

How much memory has been allocated for the Dynamic Array.

Example:

DynamicArray<int> arr;

arr.append(10);

arr.append(20);

arr.append(30);

capacity();   // Returns 4

Here:

arr = [10, 20, 30, \_]

size = 3

capacity = 4

The array currently contains 3 elements, but space for 4 elements has been allocated.



How it works:

I implemented this function by simply returning currentCapacity, which is a private variable of the class. Since I already maintain the maximum number of elements that can be stored in the array, I decided not to calculate it again. Instead, I just return the value of currentCapacity.







Time Complexity:

While implementing this function, I was simply returning the value of currentCapacity, which is stored as a private variable of the class. Since this operation only returns a single value and does not process any elements of the array, it happens in constant time.

Therefore, the Time Complexity of this function is O(1).



Return Type:

At first I thought to make it void, but then I noticed that this function returns the capacity of the array to the caller. Since a value is being returned, the return type cannot be void.

Then I thought about what data type should be returned. Capacity represents the maximum number of elements that can currently be stored in the array, and the number of elements can only be a whole number. There cannot be 4.5 or 10.7 positions available in an array.

Therefore, I decided to keep the return type of this function as int.



\# Rule of Three

While implementing the Dynamic Array, I noticed that the class is managing memory manually using a pointer (data) and dynamic memory allocation (new and delete[]).

Because of this, I started thinking about what would happen if:

DynamicArray<int> arr1;

arr1.append(10);

arr1.append(20);

DynamicArray<int> arr2 = arr1;

At first, I expected that arr2 would get its own copy of the array. However, I noticed that C++ provides a default copy mechanism which only copies the values of data members.

So after copying:

arr1.data ──┐

├──► [10][20][ ]

arr2.data ──┘

Both objects point to the same heap memory.

This creates several problems:

\### Problem 1: Unwanted Shared Data

If one object modifies the array:

arr2.insert(1, 50);

then the changes also affect arr1 because both objects are using the same memory block.



\### Problem 2: Double Deletion

When both objects are destroyed:

arr1 goes out of scope

arr2 goes out of scope

both destructors try to free the same heap memory.

delete[] data;

delete[] data;   // same memory again

This causes undefined behavior and may crash the program.



\### Solution

To solve this problem, I decided that every Dynamic Array object should have its own separate copy of the data.

Whenever copying happens:

New memory should be allocated.

Elements should be copied individually.

Each object should own its own memory block.

Because my class manages dynamic memory, I need to define three special member functions:

Destructor

Copy Constructor

Copy Assignment Operator

This concept is known as the Rule of Three.

If a class defines any one of:

1. Destructor

1. Copy Constructor

1. Copy Assignment Operator

then it usually needs to define all three.

This ensures proper memory management and prevents shallow-copy related problems.

\# Destructor (~DynamicArray())

\## Why is it Needed?

While implementing the Dynamic Array, I decided to store elements in heap memory because the array needs to grow dynamically during program execution.

However, I noticed that memory allocated on the heap is not released automatically when an object goes out of scope. If I keep allocating memory and never release it, the program will keep consuming memory unnecessarily. This problem is known as a memory leak.

Example:

{

DynamicArray<int> arr;

arr.append(10);

arr.append(20);

} // arr goes out of scope

If the heap memory allocated for arr is not released here, that memory remains occupied even though the object no longer exists.

To solve this problem, I decided to implement a Destructor.









\## How it Works

I noticed that all elements of the Dynamic Array are stored in heap memory and the address of that memory is stored in the data pointer.

Therefore, when the object is destroyed:

Free the heap memory pointed to by data.

Prevent the object from holding a dangling pointer.

Example:

Before Destructor:

Stack                         				  Heap

data ───────────────────────► [10][20][30][40]

currentSize = 4

currentCapacity = 4

Destructor Executes:

delete[] data;

data = nullptr;

After Destructor:

Stack                           Heap

data ─────►	 nullptr

Heap Memory Released

Now the memory can be reused by the system.













\## Memory Diagram

\### Before Destructor

Object (Stack)

data ───────┐

currentSize = 3  │

capacity = 4       │

`	              `│

`	             `▼

Heap Memory

+----+----+----+----+

| 10 | 20 | 30 |    |

+----+----+----+----+

\### During Destructor

delete[] data;

Heap memory is released.

\### After Destructor

Object Destroyed

data = nullptr

Heap Memory Released



Return Type

At first I thought about whether the destructor should return something after freeing memory. Then I noticed that its only responsibility is to clean up resources owned by the object before the object is destroyed.

Since no value needs to be returned to the caller, destructors do not have a return type.

Just like constructors, a destructor cannot have int, void, or any other return type.

Therefore, I decided to declare it as: ~DynamicArray(); without any return type.





\# Copy Constructor

\## Why is it Needed?

While implementing the Dynamic Array, I noticed that one object can be created from another object.

Example:

DynamicArray<int> arr1;

arr1.append(10);

arr1.append(20);

DynamicArray<int> arr2 = arr1;

At first, I thought this would automatically create a completely independent copy of the array. However, I discovered that the default copy constructor provided by C++ performs a shallow copy.

That means only the values of the data members are copied.

Example:

arr1.data ──┐

├──► [10][20][ ]

arr2.data ──┘

Both objects point to the same heap memory.

This creates problems:

Modifying one object affects the other.

Both destructors try to free the same memory.

This can lead to crashes and undefined behavior.

To solve this problem, I decided to implement my own Copy Constructor that performs a deep copy.



\## How it Works

When a new Dynamic Array is created from an existing one:

Copy the size.

Copy the capacity.

Allocate a new heap array of the same capacity.

Copy each element individually into the new array.

Example:

Before Copy:

arr1

data ─────► [10][20][30][ ]

size = 3

capacity = 4

Creating Copy:

DynamicArray<int> arr2 = arr1;

\### During Copy Constructor

Allocate New Memory

newData ──► [ ][ ][ ][ ]

Copy Elements

newData ──► [10][20][30][ ]

After Copy:

arr1

data ─────► [10][20][30][ ]

arr2

data ─────► [10][20][30][ ]

Now both objects have separate memory blocks.

If I modify arr2, arr1 remains unchanged.



\## Return Type

At first I thought whether the Copy Constructor should return the newly created object.

Then I noticed that constructors automatically initialize objects during creation. Their purpose is to create and initialize an object, not return one.

Therefore Copy Constructors do not have any return type.

DynamicArray(const DynamicArray& other);



\# Copy Assignment Operator

\## Why is it Needed?

After implementing the Copy Constructor, I noticed another way copying can happen.

Example:

DynamicArray<int> arr1;

DynamicArray<int> arr2;

arr2 = arr1;

Here arr2 already exists.

So a constructor cannot be called because constructors only execute during object creation.

Instead, the assignment operator is called.

If I rely on the default assignment operator provided by C++, it will again perform a shallow copy.

Example:

arr1.data ──┐

├──► [10][20][30]

arr2.data ──┘

This causes the same problems discussed earlier:

Shared memory

Unexpected modifications

Double deletion

Therefore, I decided to implement my own Copy Assignment Operator.



\## How it Works

When assignment happens: arr2 = arr1;

I decided to perform the following steps:

Check for self-assignment.

Free old memory owned by arr2.

Copy size and capacity.

Allocate new memory.

Copy all elements individually.

Return the current object.



\## Self Assignment Check

While implementing this operator, I noticed a special case: arr1 = arr1;

If I directly delete memory before checking this case, I will destroy my own data and then attempt to copy from it.

To avoid this problem, I first check:

if (this == &other)

{

return \*this;

}

If both objects are the same, no work is needed.



\## Memory Diagram

\### Before Assignment

arr1.data ─────► [10][20][30]

arr2.data ─────► [5][6]

\### During Assignment

Delete arr2 Memory

arr2.data ─────► released

Allocate New Memory

arr2.data ─────► [ ][ ][ ]

Copy Elements

arr2.data ─────► [10][20][30]

\### After Assignment

arr1.data ─────► [10][20][30]

arr2.data ─────► [10][20][30]

Both objects contain the same values but own different memory blocks.



\## Time Complexity

While implementing the assignment operator, I noticed that every element must be copied from the source array into the destination array.

If there are N elements:

Old memory is released.

N elements are copied.

Since each element is processed once:

Time Complexity = O(n)



\## Return Type

At first I thought of returning void because the assignment had already been completed.

Then I noticed that assignment operators in C++ are expected to return the object that received the assignment.

This allows expressions such as:   a = b = c;  to work correctly.

Therefore, I decided to return a reference to the current object.

DynamicArray& operator=(const DynamicArray& other);

The & means a reference is returned instead of creating another copy of the object.

Example:

a = b = c;

First b = c returns b, then a = b executes successfully.

Therefore the return type is: DynamicArray& which is the standard implementation for a copy assignment operator.





Shrink Strategy :

Regarding the question given in the context document I thought about it and concluded that the capacity does not shrink when I delete an element because I am deleting elements and then updating size not the capacity so the capacity will be the same.

Then a question came to my mind that if the capacity is very large and the elements present in the array are very less then one way it is typically memory wastage.

Then I thought if capacity can increase as per need then why can’t it shrink according to the requirement.

So like in resize by giving a condition I was allocating a new block of memory greater than the current one then why can’t I allocate a new block of memory smaller than the current and copy the element there.

But then another question came to my mind: when to shrink the capacity?

Should I decrease it with every delete operation? In this new memory allocation will happen after every element deletion and elements will be copied frequently. This is not a good practice.

Then I thought why not shrink it if the size is very smaller than the capacity of the array. I thought of considering if size <= capacity/4 then it is comparatively very small than the capacity.

Then I also thought that if my size = 1 and capacity = 4 then here size <= capacity/4 but here the initial capacity that I decided has been reduced and if I decided to add more elements then frequent resizing will happen which I don’t want. So I decided that the capacity/2 should be greater than or equal to the minimum capacity that I took in initialization. The reason is that after reducing it, if it goes below mincap then it would break the lower bound of my design.

So I decided to keep the condition as size <= capacity/4 and capacity/2 >= mincap(4).

Eg: Consider that the size of an array is 8 and its capacity is 64. Then the unused memory of that array is not in use causing memory wastage. Here 8 <= 64/4 and 32 >= 4.

So I decided to shrink the array by ½. The reason behind decreasing it by half is that it reduces the capacity while still leaving enough space for future insertions. This will help in avoiding frequent shrink and resizing of the array.

I decided to attach this condition while deleting the elements from the array to automate this process as removal of elements is only happening through the remove() method, so I will attach this condition in the remove method.

Then again a question came to my mind: what if I know that I don’t need to insert any element in the array, then if the array has unused space in it then it will go waste.

So if I already know that I don’t need to insert more elements in the array then I decided why not make a method in which I will allocate the memory only according to the size of the array .

shrinkToFit() : To reduce the capacity of the Dynamic Array to exactly match its current size

\### Why do we need it ?

I have mentioned it above but still some points are :

Free up unused memory when the array has excess capacity

Reduce memory footprint after multiple deletions

Ensure that the array uses only the exact required memory

Optimize storage before final usage (e.g., before storing or transferring data)



\### How does it work?

I implemented this method such that at every call it will first check the size of the array and then allocate a new block of memory equal to the size of the array. After that, it copies all the elements of the array to the new block, then frees the old block, and finally updates the pointer to point to the new block.



\### Time Complexity:

In implementation, what I have done is allocating a new block of memory and then copying each element to the new block. By doing this I have processed each element once. If the array has n elements then its cost will be n leading to the Time Complexity being O(n).



\### Return Type :

I have decided to keep its return type as void because all the working of this function is happening internally. It is not returning anything to the caller; instead, it directly modifies the internal structure of the array.










\# Extracted Images


![](images/image1.jpg)

![](images/image10.jpg)

![](images/image2.jpg)

![](images/image3.jpg)

![](images/image4.jpg)

![](images/image5.jpg)

![](images/image6.png)

![](images/image7.jpg)

![](images/image8.jpg)

![](images/image9.jpg)
