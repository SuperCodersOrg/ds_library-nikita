# **Build Log – DynamicArray (malloc/realloc Implementation)**

**Date:** 30 June 2026

**Timing** : 2:30 \- 4:40

---

## **Objective**

Implemented a generic DynamicArray\<T\> using malloc and realloc to understand low-level memory management and resizing logic.

---

## **What Was Done**

* Implemented DynamicArray with:  
  * append, insert, remove, get  
  * resize and shrinkToFit  
  * copy constructor and assignment operator  
* Memory handled using:  
  * malloc (allocation)  
  * realloc (resizing)  
  * free (cleanup)

Element copying used:  
 data\[i\] \= other.data\[i\]

---

## **Issue Encountered**

No compile-time error, but logical issue found.

Because malloc/realloc:

* Constructors are not called  
* Destructors are not called  
* Objects are not properly initialized

---

## **Result**

* Works for primitive types (int, double, char)  
* Unsafe for complex types (string, custom classes)  
* Causes undefined behavior in real C++ objects

---

## **Fix Plan**

To make it correct for C++ objects:

* Use placement new for construction  
* Call destructors manually  
* Use operator new instead of malloc

