      				

**Linked List** 

**Part 1**  —  Public API          

# **Linked List**

Class Declaration :

template \<typename T\>

class LinkedList {

private:

    struct Node {

        T data;

        Node\* next;

    };

    Node\* head;

    Node\* tail;

    int currentSize;

public:

    void insertFront(const T& value);

    void insertBack(const T& value);

    void insert(int index, const T& value);

    void deleteFront();

    void deleteBack();

    void remove(int index);

    bool search(const T& value) const;

    T get(int index) const;

    int size() const;

    bool isEmpty() const;

    void clear();

    // Rule of Three

    LinkedList();

    \~LinkedList();

    LinkedList(const LinkedList& other);

    LinkedList& operator=(const LinkedList& other);

};

## **1\. insertFront(value)  : insert value at  start of linked list** 

**Parameter:**

*  **Value →** it is the value that will be inserted in the linked list. Its data type depends on the type of linked list we are making. If it is an integer type then the value will also be of int type .

**Return Type : void** 

* I decided to keep the return type of this method as void because it is just creating a new node and then inserting value and then changing pointers a little . All this process is happening internally as there is nothing to return so the return type of it has been kept void.

## **2\. insertBack(value)  :  Adding an element at the end of linked list**

**Parameter:**

* **Value →** it is the value that will be inserted in the linked list 

**Return Type : void** 

* The reason is the same as the insertFront as all the changes are happening internally no need to return anything from this method. 

## **3\. insert(index, value)  :  Adding an element to a linked list at a particular position**

**Parameters :** 

* **Index →** the value at which I need to insert. If I won't include this value then how will I know where to insert the new value

* **Value →** the value which needs to be inserted in the linked list

**Return Type : void**

* I decided to make its return type as void as according to its functionality it does all the work internally directly with the object and there is no need to return anything to the caller.

## **4\. deleteFront()  :  To remove starting node of the linked list** 

**Return Type : void** 

* I decided to keep the method as void . As what it is doing is removing the first node of the linked list and then pointing the head pointer to the node next to the first node .All this working is happening internally directly with the object . So no need to return anything to the caller of this method 

## **5\. deleteBack()  :  To remove last node of the linked list** 

**Return Type : void** 

* I decided to keep the method as void . As what it is doing is removing the last node of the linked list and then pointing the second last node to null .All this working is happening internally directly with the object . So no need to return anything to the caller of this method 

## 

## **6\. remove(index)  :  To remove an element from a linked list**

**Parameter :** 

* **Index →** this value tells which node to be removed . If it is not provided then the program will not know from where to remove the element.

**Return Type : void**

* I decided to keep the return type of this function as void. What it does is remove elements from the linked list  and then changes pointers according to the requirement . It does not send or return anything to the caller.

## **7\. search(value)  : check value exist or not in linked list**

**Parameter:**

* **Value →** this is the value which needs to be searched in the linked list.

**Return Type : bool**

* I first thought to keep its type as **void** then I thought if I keep it void then it will not return or tell if a value exists or not. Then finally I decided to keep it as bool because this method is like a question : **If this given value exist or not ?**  
  So finally I decided to keep its return type **bool** because if a given value is present in the linked list then it will return true if not then it will return false to the caller .

## **8\. get(index)  :  Access an element by passing index**

**Parameter** : 

* **Index →** This value tells the function which element I want to access. If it is not provided then how will the function know what to access and from where to access.

**Return Type : T**

* At first I thought to keep the return type as void, but then I noticed that this function is returning an element to the caller. Since a value is being returned, the return type cannot be void.

* Then I thought why not keep the return type as int. But another problem arose. What if the Linked List is of string type? In that case the function would return a string, not an integer. Therefore, keeping the return type fixed as int would make the function work only for integer linked lists.

* After thinking about this, I noticed that the element being returned always belongs to the Linked List  itself. So if the Linked List stores integers, the function should return an integer. If the Linked List stores strings, the function should return a string.

* Therefore I decided to align the return type of this function with the type of elements stored in the Linked List.

* So decided it to keep as  **T get(int index) const;**

## **9\. size()  :  To get number of elements currently stored in a linked list**

**Return Type : int**

* At first I thought to make it void then I noticed that it is returning size of the linked list which is integer and cannot be any other data type because the number of elements cannot be in float — there is no chance that 2.6 or 5.5 elements are present in the linked list. So I decided to keep the return type of this function as int.

## **10\. isEmpty()  :  To check linked list is empty or not**

**Return Type : bool**

* I decided to keep its return type as **bool** because this method  is made for checking whether a linked list is empty or not . If it is empty then this will return true other wise it will return false .

## **11\. clear()  :  To delete all elements from linked list**

**Return Type : void**

* I decided to keep the return type as **void** because this method deletes all the elements of a linked list and this happens internally and there is nothing to return here .

## 

## **Rule of Three — Three Special Functions**

Because my class manages dynamic memory, I need to define three special member functions:

* Destructor

* Copy Constructor

* Copy Assignment Operator

This concept is known as the **Rule of Three.** If a class defines any one of these, then it usually needs to define all three. This ensures proper memory management and prevents shallow-copy related problems.

### **Destructor  :  \~LinkedList()**

**Return Type : none**

* At first I thought about whether the destructor should return something after freeing memory. Then I noticed that its only responsibility is to clean up resources owned by the object before the object is destroyed.

* Since no value needs to be returned to the caller, destructors do not have a return type.

* Just like constructors, a destructor cannot have int, void, or any other return type.

* Therefore, I decided to declare it as: \~LinkedList(); without any return type.


### **Copy Constructor  :  LinkedList(const LinkedList& other)**

**Return Type : none**

* At first I thought whether the Copy Constructor should return the newly created object.

* Then I noticed that constructors automatically initialize objects during creation. Their purpose is to create and initialize an object, not return one.

* Therefore Copy Constructors do not have any return type.

* **LinkedList(const LinkedList& other);**


### **Copy Assignment Operator  :  LinkedList& operator=(const LinkedList& other)**

**Return Type : LinkedList&**

* At first I thought of returning void because the assignment had already been completed.

* Then I noticed that assignment operators in C++ are expected to return the object that received the assignment.

* This allows expressions such as a \= b \= c; to work correctly.

* Therefore, I decided to return a reference to the current object.

* The & means a reference is returned instead of creating another copy of the object.

* Therefore the return type is: LinkedList& which is the standard implementation for a copy assignment operator.

**Part 2**  —  Internal Representation & Memory Diagrams

### **Basic Internal Structure**

To implement Linked List we need :

**Head Pointer :**  
 Head pointer stores the address of the first node of the linked list. If I do not have the head pointer then how will I know from where the linked list starts.

**Tail Pointer :**  
 Tail pointer stores the address of the last node of the linked list. This helps me in inserting elements at the end of the linked list without traversing the whole linked list.

**Size :**  
 Size tells how many nodes are currently present in the linked list. If I do not know the size then how will I know how many elements are present in the collection.

**Node :**  
 A linked list is made up of nodes. Each node contains :

* Data → stores the actual value.  
* Next Pointer → stores the address of the next node.

The next pointer is used to connect one node with another node. If I do not have a next pointer then nodes cannot be connected together and a linked list cannot be formed.

### **Example :**

head  
↓

\[10|•\] ──► \[20|•\] ──► \[30|NULL\]

                         	    ↑  
                                      tail

size \= 3

* 3 nodes are present in the linked list.  
* head points to the first node.  
* tail points to the last node.  
* The last node points to NULL because there is no node after it.

### 

### 

### **Nodes (Heap Memory)**

As I am using heap for storing nodes so I must dynamically allocate memory whenever a new node is inserted.

**Example :**

**my\_new Node**

creates a node in heap memory.

The head pointer stores the address of the first node and through the next pointers all other nodes can be accessed.

## **Constructor — Before and After**

**Before Constructor :**

LinkedList\<int\> list;

Memory:

Head \= garbage 

Tail \= garbage

currentSize \= garbage

**After Constructor :**

Head —-----\> NULL

Tail —-----\> NULL

No nodes exist in heap .

currentSize \=0

## 

## 

## 

## 

## 

## 

## 

## **insertFront(value)**

**Before Insert**

head

 |

 v

\+------+------+    \+------+------+    \+------+------+

| 10   | next | \-\> | 20   | next | \-\> | 30   | NULL |

\+------+------+    \+------+------+    \+------+------+

                                       	      ^

                                      	      |

                                       	    tail

**Step 1: Create New Node**

\+------+------+

|  5   | NULL |

\+------+------+

**Step 2: newNode.next \= head**

\+------+------+    \+------+------+    \+------+------+    \+------+------+

|  5   | next | \-\> | 10   | next | \-\> | 20   | next | \-\> | 30   | NULL |

\+------+------+    \+------+------+    \+------+------+    \+------+------+

**Step 3: Move Head**

head

 |

 v

\+------+------+    \+------+------+    \+------+------+    \+------+------+

|  5   | next | \-\> | 10   | next | \-\> | 20   | next | \-\> | 30   | NULL |

\+------+------+    \+------+------+    \+------+------+    \+------+------+

                                               	            	        ^

                                                           	        |

                                                          		      tail

**Final List**

head

 |

 v

\+------+------+    \+------+------+    \+------+------+    \+------+------+

|  5   | next | \-\> | 10   | next | \-\> | 20   | next | \-\> | 30   | NULL |

\+------+------+    \+------+------+    \+------+------+    \+------+------+

                                                          		        ^

                                                           	        |

                                                           	      tail

## 

## 

## 

## **insertBack(value)**

**Before Insert**

head  
 |  
 v

\+------+------+    \+------+------+    \+------+------+  
| 10   | next | \-\> | 20   | next | \-\> | 30   | NULL |  
\+------+------+    \+------+------+    \+------+------+  
                                       	  ^  
                                         	  |  
                                                    tail

**Step 1: Create New Node**

\+------+------+  
| 40   | NULL |  
\+------+------+

**Step 2: tail.next \= newNode**

head  
 |  
 v

\+------+------+    \+------+------+    \+------+------+    \+------+------+  
| 10   | next | \-\> | 20   | next | \-\> | 30   | next | \-\> | 40   | NULL |  
\+------+------+    \+------+------+    \+------+------+    \+------+------+

                                			              ^  
                                			              |  
                                			             tail

**Step 3: Move Tail**

head  
 |  
 v

\+------+------+    \+------+------+    \+------+------+    \+------+------+  
| 10   | next | \-\> | 20   | next | \-\> | 30   | next | \-\> | 40   | NULL |  
\+------+------+    \+------+------+    \+------+------+    \+------+------+  
                                                         	             ^  
                                                          	             |  
                                                                            tail

**Final List**

head  
 |  
 v

\+------+------+    \+------+------+    \+------+------+    \+------+------+  
| 10   | next | \-\> | 20   | next | \-\> | 30   | next | \-\> | 40   | NULL |  
\+------+------+    \+------+------+    \+------+------+    \+------+------+  
                                                           		  ^  
                                                           		  |  
                                                          		  tail

## 

## 

## **insert(index,value)**

Insert(25) at index 2

**Before Insert**

head  
 |  
 v

\+------+------+    \+------+------+    \+------+------+    \+------+------+  
| 10   | next | \-\> | 20   | next | \-\> | 30   | next | \-\> | 40   | NULL |  
\+------+------+    \+------+------+    \+------+------+    \+------+------+  
                                                          		   ^  
                                                          		   |  
                                                         		   tail

**Step 1: Traverse to prev node (index 1 \= 20\)**

prev  
 |  
 v

\+------+------+    \+------+------+    \+------+------+    \+------+------+  
| 10   | next | \-\> | 20   | next | \-\> | 30   | next | \-\> | 40   | NULL |  
\+------+------+    \+------+------+    \+------+------+    \+------+------+  
                     ^  
                     |  
                  prev

**Step 2: Create New Node**

\+------+------+  
| 25   | NULL |  
\+------+------+

**Step 3: newNode.next \= prev.next**

(25 points to 30\)

\+------+------+    \+------+------+    \+------+------+    \+------+------+  
| 10   | next | \-\> | 20   | next | \-\> | 25   | next | \-\> | 30   | NULL |  
\+------+------+    \+------+------+    \+------+------+    \+------+------+  
                      |                       ^  
                      |                       |  
                     \+------------------+

**Step 4: prev.next \= newNode**

head  
 |  
 v

\+------+------+    \+------+------+    \+------+------+    \+------+------+    \+------+------+  
| 10   | next | \-\> | 20   | next | \-\> | 25   | next | \-\> | 30   | next | \-\> | 40 | NULL |  
\+------+------+    \+------+------+    \+------+------+    \+------+------+    \+------+------+  
                                                          			            ^  
                                                            			            |  
                                                         			          tail

**Final List**

head  
 |  
 v

\+------+------+    \+------+------+    \+------+------+    \+------+------+    \+------+------+  
| 10   | next | \-\> | 20   | next | \-\> | 25   | next | \-\> | 30   | next | \-\> | 40 | NULL |  
\+------+------+    \+------+------+    \+------+------+    \+------+------+    \+------+------+  
                                                      			            ^  
                                                           			            |  
                                                            			          tail

## 

## **DeleteFront()**

**Before Delete**

head  
|  
v

\+------+------+ \+------+------+ \+------+------+    \+------+------+  
| 10 | next | \-\> | 20 | next | \-\> | 30 | next | \-\> | 40 | NULL |  
\+------+------+ \+------+------+ \+------+------+    \+------+------+  
     ^  
     |  
  Tail

**Step 1: temp \= head**

temp  
|  
v  
\+------+------+  
| 10 | next |  
\+------+------+  
|  
v  
(rest of list unchanged)

\+------+------+ \+------+------+ \+------+------+    \+------+------+  
| 10 | next | \-\> | 20 | next | \-\> | 30 | next | \-\> | 40 | NULL |  
\+------+------+ \+------+------+ \+------+------+    \+------+------+  
      ^  
      |  
    Tail  
	

**Step 2: head \= head.next**

head  
|  
v

\+------+------+ \+------+------+ \+------+------+   
| 20 | next | \-\> | 30 | next | \-\> | 40 | NULL |  
\+------+------+ \+------+------+ \+------+------+  
          ^  
          |  
         tail

**Step 3: delete temp (old first node)**

(temp removed)

\+------+------+ \+------+------+    \+------+------+   \+------+------+  
| 10     | X    |  | 20   | next | \-\> | 30   | next | \-\> | 40 | NULL |  
\+------+------+ \+------+------+    \+------+------+   \+------+------+

**Final List**

head  
|  
v

\+------+------+ \+------+------+   \+------+------+  
| 20 | next | \-\> | 30 | next | \-\> | 40 | NULL |  
\+------+------+ \+------+------+   \+------+------+  
         ^  
         |  
       Tail  
	

## 

## 

## 

## **deleteBack()**

**Before Delete**

head  
 |  
 v

\+------+------+    \+------+------+    \+------+------+    \+------+------+  
| 10   | next | \-\> | 20   | next | \-\> | 30   | next | \-\> | 40   | NULL |  
\+------+------+    \+------+------+    \+------+------+    \+------+------+  
                                                            		 ^  
                                                            		 |  
                                                          	            tail

**Step 1: Traverse to second last node (prev)**

prev  
 |  
 v

\+------+------+    \+------+------+    \+------+------+    \+------+------+  
| 10   | next | \-\> | 20   | next | \-\> | 30   | next | \-\> | 40   | NULL |  
\+------+------+    \+------+------+    \+------+------+    \+------+------+  
                           ^  
                           |  
                          prev

**Step 2: temp \= tail (last node)**

temp  
 |  
 v  
\+------+------+  
| 40   | NULL |  
\+------+------+

**Step 3: prev.next \= NULL**

head  
 |  
 v

\+------+------+    \+------+------+    \+------+------+  
| 10   | next | \-\> | 20   | next | \-\> | 30   | NULL |  
\+------+------+    \+------+------+    \+------+------+  
                                                     ^  
                                                     |  
                                                 tail (will update)

**Step 4: move tail \= prev**

head  
 |  
 v

\+------+------+    \+------+------+    \+------+------+  
| 10   | next | \-\> | 20   | next | \-\> | 30   | NULL |  
\+------+------+    \+------+------+    \+------+------+  
                                                    ^  
                                                    |  
                                                  tail

**Step 5: delete temp (old last node)**

\+------+------+  
| 40   |  X   |  
\+------+------+

**Final List**

head  
 |  
 v

\+------+------+    \+------+------+    \+------+------+  
| 10   | next | \-\> | 20   | next | \-\> | 30   | NULL |  
\+------+------+    \+------+------+    \+------+------+  
                                                     ^  
                                                     |  
                                                   tail

## **remove(index)**

Delete node at index 2 (value \= 30\)

**Before Delete**

head  
 |  
 v

\+------+------+    \+------+------+    \+------+------+    \+------+------+  
| 10   | next | \-\> | 20   | next | \-\> | 30   | next | \-\> | 40   | NULL |  
\+------+------+    \+------+------+    \+------+------+    \+------+------+  
                                                                ^  
                                                                |  
                                                              Tail

**Step 1: Traverse to prev node (index 1 \= 20\)**

prev  
 |  
 v

\+------+------+    \+------+------+    \+------+------+    \+------+------+  
| 10   | next | \-\> | 20   | next | \-\> | 30   | next | \-\> | 40   | NULL |  
\+------+------+    \+------+------+    \+------+------+    \+------+------+  
                     ^  
                     |  
                  prev

**Step 2: temp \= prev.next (node to delete)**

temp  
 |  
 v  
\+------+------+   
| 30   | next |  
\+------+------+  
   |  
   v  
(30 points to 40\)

**Step 3: prev.next \= temp.next**

Skip node 30

head  
 |  
 v

\+------+------+    \+------+------+    \+------+------+  
| 10   | next | \-\> | 20   | next | \-\> | 40   | NULL |  
\+------+------+    \+------+------+    \+------+------+  
                                                     ^  
                                                     |  
                                                   tail

Step 4: delete temp

\+------+------+  
| 30   |  X   |  
\+------+------+

Final List

head  
 |  
 v

\+------+------+    \+------+------+    \+------+------+  
| 10   | next | \-\> | 20   | next | \-\> | 40   | NULL |  
\+------+------+    \+------+------+    \+------+------+  
                                                     ^  
                                                     |  
                                                   tail

## **search(value) and get(index)**

Search(30) → then Get node/value

Linked List

head  
 |  
 v

\+------+------+    \+------+------+    \+------+------+    \+------+------+  
| 10   | next | \-\> | 20   | next | \-\> | 30   | next | \-\> | 40   | NULL |  
\+------+------+    \+------+------+    \+------+------+    \+------+------+  
                                                             ^  
                                                             |  
                                                            tail

\============================================================  
**STEP 1: SEARCH PHASE**  
\============================================================

**Start traversal**

current  
 |  
 v  
\+------+------+   
| 10   | next |  
\+------+------+

Compare: 10 \!= 30 → move next

\+------+------+   
| 20   | next |  
\+------+------+

Compare: 20 \!= 30 → move next

\+------+------+   
| 30   | next |  
\+------+------+

Compare: 30 \== 30 → FOUND

**Result of Search:**  
current pointer now points to target node (Node 30\)

\============================================================  
**STEP 2: GET PHASE**  
\============================================================

Get value from found node

current  
 |  
 v  
\+------+------+   
| 30   | next |  
\+------+------+

GET → return 30 (data field)

or  
GET → return node reference (depends on implementation)

\============================================================  
**FINAL RESULT**  
\============================================================

Found Node:  
Value \= 30  
Address \= current pointer

## **size() — How it works**

* I implemented this function by simply returning currentSize, which is a private variable of the class. Since I already maintain the count of how many elements are present in the linked list, I decided not to traverse the linked list again. Instead, I just return the value of currentSize.

Example :

LinkedList\<int\> list;

list.insertBack(10);

list.insertBack(20);

list.insertBack(30);

size(); // Returns 3

## **Destructor — Memory Diagram**

### **Before Destructor**

                                  Stack

                                ┌─────────────────────┐

		       │ LinkedList Object                         │

		       │ head ────────────┐          │

		       │ tail ────────┐           │           │

		       │ size \= 3              │           │           │

		      └───────────│──── │─ ──┘

				           │           │   

				          ▼          ▼ 

		Heap		        \[10|•\] ─► \[20|•\]──► \[30|NULL\]

						                 ▲

							     │

							   tail			

### **Destructor Executes**

delete all nodes;

head \= nullptr;

tail \= nullptr;							     

### 

### 

### **After Destructor**

                                  Stack

                                ┌──────────────────── ─┐

                                 │ LinkedList Object                          │

		       │ head ──	nullptr		            │

		       │ tail    ──  nullptr    	            │

		       │ size \= 0                                         │

		      └─────────────────────┘

All nodes Released

Heap Memory Released so now memory can be reused.

## **Copy Constructor — Memory Diagram**

### **Default Shallow Copy (Problem)**

head1 ──┐

        ├──► \[10|•\] ──► \[20|•\] ──► \[30|NULL\]

head2 ──┘

Both objects point to the same linked list.

If one object deletes the nodes, the other object will contain invalid pointers.

---

### **Deep Copy (Solution) — Before Copy**

                          Stack

                     ┌────────────────────—---------─┐

                     │ LinkedList Object             │

                     │ head ────────────────┐   │

                     │ tail ────────────┐      |   │

                     │ size \= 3 		  |	|   │

                     └──────────────────—--─│—---|--─┘ 

                                            ▼    ▼

                              Heap       \[10|•\] ─► \[20|•\] ──► \[30|NULL\]

### **During Copy Constructor**

                        Stack

                     ┌────────────────────—---------─┐

                     │ LinkedList Object             │

                     │ head ────────────────┐   │

                     │ tail ────────────┐      |   │

                     │ size \= 3 		  |	|   │

                     └──────────────────—--─│—---|--─┘ 

                                            ▼    ▼

                     Heap                   \[ |•\]─► \[ |•\] ──► \[ |NULL\]

    Copy Data:

					Stack

                     ┌────────────────────—---------─┐

                     │ LinkedList Object             │

                     │ head ────────────────┐   │

                     │ tail ────────────┐      |   │

                     │ size \= 3 		  |	|   │

                     └──────────────────—--─│—---|--─┘ 

                                            ▼    ▼

                     Heap                 \[10|•\] ─► \[20|•\] ──► \[30|NULL\]

### **After Copy**

#### **Object 1**

 list1 ─────►   \[10|•\] ─► \[20|•\] ──► \[30|NULL\]

#### **Object 2**

list2 ─────►   \[10|•\] ─► \[20|•\] ──► \[30|NULL\]

Now both objects have separate linked lists.

If I modify list2, list1 remains unchanged.

## **Copy Assignment Operator — Memory Diagram**

### **Before Assignment**

 list1.head ─────►   \[10|•\] ─► \[20|•\] ──► \[30|NULL\]

 list2.head ─────►   \[5|•\]  ──► \[6|NULL\]

### **During Assignment**

Delete list2 Nodes

list2.head ─────► released

Allocate New Nodes

list2.head ─────► \[  |•\] ──► \[  |•\] ──► \[  |NULL\]

Copy Data

list2.head ─────►\[10|•\] ─► \[20|•\] ──► \[30|NULL\]

### **After Assignment**

list1.head ─────►\[10|•\] ─► \[20|•\] ──► \[30|NULL\]

list2.head ─────►\[10|•\] ─► \[20|•\] ──► \[30|NULL\]

Both objects contain the same values but own different linked lists and different memory blocks.

**Part 3**  —  Complexity Estimates

# **Linked List — Time Complexity**

## **1\. insertFront(value)**

**Time Complexity : O(1)**

While implementing this function I noticed that I only need to create one new node and make it point to the current first node. After that I update the head pointer to point to the newly created node.

No traversal of the linked list is required. Regardless of whether the linked list contains 10 nodes or 1000 nodes, the amount of work remains the same.

Example :

Before:

Head

 ↓

 \[20\] → \[30\] → \[40\]

insertFront(10)

After:

Head

 ↓

 \[10\] → \[20\] → \[30\] → \[40\]

Only one node creation and one pointer update happens → O(1)

---

## **2\. insertBack(value)**

**Time Complexity : O(1)**

I decided to maintain a tail pointer in my linked list. Because of this I can directly access the last node.

While implementing this function I noticed that I only need to create a new node, connect the current tail node to it and then move the tail pointer to the new node.

No traversal is required.

Example :

Before:

Head

 ↓

 \[10\] → \[20\] → \[30\]

		        ↑   

		   tail

After:

Head

 ↓

\[10\] → \[20\] → \[30\] → \[40\]

		                   ↑   

		        tail

Only a few pointer updates happen → O(1)

---

## **3\. insert(value)**

### **Best Case : O(1)**

I noticed that when index \= 0, insertion happens at the beginning of the linked list. This is exactly the same as insertFront() and only requires a few pointer updates.

Therefore Time Complexity \= O(1)

### **Average Case : O(n)**

While inserting near the middle of the linked list I noticed that I must first traverse the linked list to reach the required position.

If there are N nodes then almost N/2 nodes may need to be visited.

Since Big-O ignores constants:

Time Complexity \= O(n)

### **Worst Case : O(n)**

While inserting near the end of the linked list using an index, I may have to traverse almost the entire linked list before reaching the required position.

If there are N nodes then almost N nodes may be visited.

Therefore:

Time Complexity \= O(n)

---

## **4\. deleteFront(value)**

### **Time Complexity : O(1)**

While implementing this function I noticed that I only need to move the head pointer to the second node and delete the first node.

No traversal is required.

Example :

Before:

Head

 ↓

 \[10\] → \[20\] → \[30\]

After:

\[20\] → \[30\] 

Only one node is deleted and one pointer is updated.

Time Complexity \= O(1)

---

## **5\. deleteBack(value)**

### **Time Complexity : O(n)**

While implementing this function I noticed that before deleting the last node I must first reach the second last node.

Since my linked list is singly linked, there is no pointer that directly tells me where the previous node is.

Therefore I must traverse the linked list.

Example :

\[10\] → \[20\] → \[30\] → \[40\]

To delete 40 I first need to find 30\.

If there are N nodes then almost N nodes may be visited.

Time Complexity \= O(n)

---

## 

## **6\. remove(index)**

### **Best Case : O(1)**

If index \= 0 then removal happens from the beginning of the linked list.

This is exactly the same as deleteFront().

Time Complexity \= O(1)

### **Average Case : O(n)**

While removing a node near the middle I noticed that I first need to reach the node before the required position.

Almost N/2 nodes may be visited.

Therefore:  Time Complexity \= O(n)

### **Worst Case : O(n)**

When removing a node near the end of the linked list I may need to traverse almost the entire linked list.

Therefore: Time Complexity \= O(n)

---

## **6\. search(value)**

### **Best Case : O(1)**

I noticed that if the value is present in the first node then the search stops immediately.

Example :

\[10\] → \[20\] → \[30\] → \[40\]

search(10)

Value found in first node.

Time Complexity \= O(1)

### 

### **Average Case : O(n)**

While searching for values near the middle of the linked list I noticed that almost half of the nodes may need to be visited.

Therefore: Time Complexity \= O(n)

### **Worst Case : O(n)**

If the value is present in the last node or does not exist at all then every node must be checked.

Example :

\[10\] → \[20\] → \[30\] → \[40\]

search(40)

All nodes are visited.

Time Complexity \= O(n)

---

## 

## **8\. get(index)**

### **Best Case : O(1)**

When index \= 0, the required element is already present at the head node.

No traversal is needed.

Time Complexity \= O(1)

### **Average Case : O(n)**

For an index near the middle, almost N/2 nodes may need to be visited.

Since Big-O ignores constants:

Time Complexity \= O(n)

### **Worst Case : O(n)**

When accessing the last node, almost all nodes must be visited one by one.

Unlike arrays, linked lists cannot directly jump to an index.

Therefore: Time Complexity \= O(n)

---

## 

## 

## 

## **9\. size()**

### **Time Complexity : O(1)**

While implementing this function I simply return the value of currentSize.

I already maintain the number of nodes in the linked list, therefore there is no need to traverse the linked list again.

Example :

 LinkedList\<int\> list;

 list.insertBack(10);

 list.insertBack(20);

 list.insertBack(30);

 size(); // Returns 3

Time Complexity \= O(1)

---

## 

## **10\. isEmpty()**

### **Time Complexity : O(1)**

While implementing this function I simply check whether currentSize is equal to zero.

Only a single comparison is performed.

Example :

currentSize \== 0

Time Complexity \= O(1)

## 

## **11.clear()**

### **Time Complexity : O(n)**

While implementing this function I noticed that every node must be deleted individually.

If there are N nodes then all N nodes must be visited and deleted.

Example :

\[10\] → \[20\] → \[30\] → \[40\]

All four nodes are deleted one by one.

Therefore:

Time Complexity \= O(n)

---

## 

## **12.Copy Constructor**

### **Time Complexity : O(n)**

While implementing the Copy Constructor I noticed that a new node must be created for every node present in the source linked list.

If there are N nodes then N new nodes are allocated and N values are copied.

Therefore:

Time Complexity \= O(n)

---

## 

## **13.Copy Assignment Operator**

### **Time Complexity : O(n)**

While implementing the assignment operator I first delete the nodes currently owned by the destination linked list and then create new nodes by copying values from the source linked list.

If there are N nodes then all N nodes are processed once.

Therefore: Time Complexity \= O(n)

---

## 

## **14.Destructor**

### **Time Complexity : O(n)**

While implementing the destructor I noticed that every node stored in the linked list must be deleted before the object is destroyed.

If there are N nodes then N delete operations are performed.

Therefore: Time Complexity \= O(n)

**Part 4**  —  Design Decisions

# **Linked List — Design Decisions**

## **Why Linked List is needed**

At first I thought about storing all elements in a Dynamic Array. Then I noticed that whenever an element is inserted at the beginning or in the middle of the collection, all the elements after that position need to be shifted. Similarly, when an element is removed, many elements may again need to be shifted.

I wanted a collection where insertion and deletion can be performed without shifting all existing elements. Therefore I decided to use a Linked List.

In a Linked List, elements are stored inside separate nodes and each node is connected to the next node using a pointer. Because of this structure, insertion and deletion can be performed by changing pointers instead of shifting elements.

Example :

 Dynamic Array:

 \[10\]\[20\]\[30\]\[40\]

 Insert 15 at index 1

 \[10\]\[15\]\[20\]\[30\]\[40\]

  20,30,40 need to be shifted

 Linked List:

 \[10\] → \[20\] → \[30\] → \[40\]

 Insert 15

 \[10\] → \[15\] → \[20\] → \[30\] → \[40\]

Only pointers are changed.

Therefore I decided to use a Linked List for this project.

---

## 

## 

## 

## 

## 

## **Class Invariants** 

| currentSize ≥ 0 |
| :---- |
| head \= nullptr ⇔ currentSize \= 0 |
| tail \= nullptr ⇔ currentSize \= 0 |
| tail-\>next \= nullptr (when currentSize \> 0\) |
| 0 ≤ index \< currentSize  |

## **2.Decision : Template Class**

At first I thought about making the Linked List store only integers.

Example :

Class LinkedList

{

int data;

};

Then I noticed that if later I want to store strings, characters, doubles or some custom objects then I would need to create another Linked List implementation.

Instead of creating multiple Linked List classes for different data types, I decided to use templates.

Example :

LinkedList\<int\>

LinkedList\<double\>

LinkedList\<char\>

LinkedList\<string\>

This allows the same implementation to work with multiple data types.

Therefore I decided to make Linked List a template class.

---

## 

## **3\. Why I Decided to Maintain a Head pointer**

At first I thought about how I would access the linked list after nodes are created in heap memory.

Then I noticed that if I do not store the address of the first node somewhere, then I will not know where the linked list starts.

Therefore I decided to maintain a Head Pointer.

The Head Pointer stores the address of the first node of the linked list.

Example :

 Head

 ↓

 \[10\] → \[20\] → \[30\]

Using the head pointer I can access every node in the linked list.

---

## 

## **4\. Why I Decided to Maintain a Tail pointer**

At first I thought about keeping only the head pointer.

Then I noticed that whenever I need to insert an element at the end of the linked list, I would first need to traverse the entire linked list to reach the last node.

Example :

\[10\] → \[20\] → \[30\] → \[40\]

To insert a new element after 40, I would first have to visit every node.

I realized that this would make insertion at the end slower.

Therefore I decided to maintain a Tail Pointer.

The Tail Pointer stores the address of the last node of the linked list.

Example :

Head

 ↓

\[10\] → \[20\] → \[30\] → \[40\]

		                   ↑   

		        tail

Now insertion at the end can happen directly without traversing the whole linked list.

---

## **4\. Why I Decided to Maintain currentSize**

At first I thought about calculating the size of the linked list every time the size() function is called.

Then I noticed that to calculate the size I would have to traverse the entire linked list and count all nodes.

Example :

\[10\] → \[20\] → \[30\] → \[40\]

To know the size, all four nodes would need to be visited.

If the linked list contains N nodes then N nodes would have to be processed every time size() is called.

Therefore I decided to maintain a variable called currentSize.

Whenever a node is inserted, currentSize is increased.

Whenever a node is deleted, currentSize is decreased.

This allows the size() function to simply return currentSize directly.

---

## **4\. Why I Decided to use a Singly Linked List**

At first I thought about implementing a Doubly Linked List.

Example :

Struct Node

{

T data;

Node \* next;

Node \* prev;

};

Then I noticed that every node would contain an additional pointer.

This would increase memory consumption because every node now stores two pointers instead of one.

The operations required in my project can be implemented using only a next pointer.

Therefore I decided to use a Singly Linked List.

Example :

Struct Node

{

T data;

Node \* next;

};

This reduces memory usage while still supporting all required operations.

---

## 

## 

## **7\. Why I Decided to Store Nodes in Heap Memory**

At first I thought about creating nodes inside stack memory.

Then I noticed that the linked list can grow and shrink during program execution.

Because I do not know beforehand how many nodes will be needed, I cannot allocate all nodes at compile time.

Therefore I decided to allocate nodes dynamically in heap memory.

Example :

my\_new Node;

Whenever a new element is inserted, a new node is created in heap memory.

Whenever an element is removed, the node is deleted from heap memory.

This allows the linked list to grow and shrink according to the requirements of the program.

---

## **8\. Why I Decided to follow Rule of Three**

Since my linked list allocates nodes dynamically using new, I noticed that the default copy behavior provided by C++ would simply copy pointer values.

Example :

 list1.head ──┐

 		        ├──► \[10\] → \[20\] → \[30\]

 list2.head  ──┘

Now both objects point to the same nodes.

If one object deletes the nodes, the other object will contain invalid pointers.

This can lead to double deletion and program crashes.

Therefore I decided to implement:

**\~LinkedList();**

**LinkedList(const LinkedList& other);**

**LinkedList& operator=(const LinkedList& other);**

This is known as the **Rule Of Three.**

By implementing these functions, every Linked List object manages its own memory safely.

## **9\. Exception Handling**

| Operation | Condition | Exception |
| :---- | :---- | :---- |
| get(index) | index \< 0 OR index \>= currentSize | std::out\_of\_range |
| remove(index) | index \< 0 OR index \>= currentSize | std::out\_of\_range |
| insert(index,value) | index \< 0 OR index \> currentSize | std::out\_of\_range |
| deleteFront() | currentSize \== 0 | std::out\_of\_range |
| deleteBack() | currentSize \== 0 | std::out\_of\_range |
| Memory Allocation | my\_new Node fails | std::bad\_alloc |

