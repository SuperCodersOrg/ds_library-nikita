# Build Log - Update in Dynamic Array Proposal

**Date:** July 1, 2026  
**Time:** 10:00 AM – 12:00 PM  
**Duration:** 2 Hours

## Goal

Revise the DynamicArray design after identifying the limitations of the previous implementation and prepare a new design proposal using `operator new` and placement `new` instead of `malloc()` and `realloc()`.

## Problem Encountered

While reviewing yesterday's implementation, I realized that using `malloc()` and `realloc()` was not a suitable approach for a generic C++ container. Although the implementation worked for primitive data types, it could not safely handle objects such as `std::string` because constructors and destructors were never called.

Additionally, `realloc()` cannot safely resize memory containing constructed C++ objects since it moves raw memory without invoking copy or move constructors.

## What I Tried

- Reviewed the previous DynamicArray design and identified all functions that depended on `malloc()` and `realloc()`.
- Prepared a new design proposal using `operator new` for raw memory allocation.
- Planned to construct objects using placement `new`.
- Updated the implementation strategy for all DynamicArray operations to remove the dependency on `realloc()`.
- Redesigned the memory resizing process so that a new memory block is allocated, existing elements are copy-constructed into the new block, old objects are destroyed, and the previous memory block is released using `operator delete`.
- Updated the design proposal to reflect the new memory management strategy and object lifetime handling.

## Outcome

The DynamicArray design was successfully updated to use C++ object construction instead of C-style memory allocation. All major operations were revised according to the new memory management approach, including insertion, deletion, resizing, copy construction, assignment, and destruction.

The new proposal now supports generic C++ objects correctly and avoids the object lifetime issues identified in the previous implementation.

## Learning

This session helped me understand that resizing a container holding C++ objects cannot be done using `realloc()`. Instead, each object must be explicitly constructed in the new memory block using placement `new`, and the old objects must be destroyed before releasing the previous memory. Updating the design before continuing the implementation will make the DynamicArray safer and fully compatible with generic C++ types.