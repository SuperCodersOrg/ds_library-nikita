# Build Log

**Date:** 30 June 2026

**Duration:** 2:30 PM – 4:40 PM (2 hours 10 minutes)

## Goal

Implement a generic `DynamicArray<T>` using `malloc()` and `realloc()` instead of `new` and `delete` so I could understand how dynamic memory allocation and resizing work at a lower level.

---

## Problem Encountered

The code compiled successfully and all the functions were working correctly for primitive data types like `int` and `char`. However, while testing and reading about memory management, I found that using `malloc()` and `realloc()` is not suitable for storing C++ objects like `std::string`.

The main problem is that `malloc()` only allocates raw memory. It does not call constructors, and `free()` does not call destructors. Because of this, objects are not properly created or destroyed, which can lead to undefined behaviour.

---

## What I Tried

- Created a template-based `DynamicArray<T>`.
- Used `malloc()` to allocate memory for the array.
- Used `realloc()` whenever the array became full.
- Implemented the following functions:
  - `append()`
  - `insert()`
  - `remove()`
  - `get()`
  - `resize()`
  - `shrinkToFit()`
- Implemented the copy constructor and assignment operator by allocating new memory and copying all the elements.
- Tested all operations using integer values to verify that resizing and insertion were working correctly.
- Compared the behaviour of `malloc()` with C++ object creation to understand why it was unsafe for complex objects.

---

## Outcome

The DynamicArray implementation works correctly for primitive data types and helped me understand how dynamic resizing works internally.

However, I learned that this approach cannot safely handle C++ objects because constructors and destructors are never called. In the next implementation, I plan to replace `malloc()` with `operator new`, use placement `new` to construct objects, manually call destructors, and finally release the memory using `operator delete`.