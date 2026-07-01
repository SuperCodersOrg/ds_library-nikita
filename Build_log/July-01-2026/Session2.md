# Build Log -  Implementation of Dynamic Array and Testing of methods of Dynamic Array

**Date:** July 1, 2026  
**Time:** 3:00 PM – 6:00 PM  
**Duration:** 3 Hours

## Goal

Implement the DynamicArray based on the updated design using placement `new`, complete the Rule of Three, implement custom memory allocation utilities in `Memory.h`, and thoroughly test the implementation.

## What I Tried

- Implemented all the DynamicArray methods based on the revised design.
- Completed the Rule of Three by implementing:
  - Destructor
  - Copy Constructor
  - Copy Assignment Operator
- Implemented custom memory allocation utilities in `Memory.h` using `malloc()` together with placement `new`.
- Ensured that objects were properly constructed using placement `new` and destroyed before memory was released.
- Verified that memory allocation and deallocation worked correctly for different object types.
- Wrote five test cases for each DynamicArray method, covering both normal and edge cases.
- Executed all test cases to verify the correctness of every implemented operation.

## Outcome

The DynamicArray implementation was completed successfully using the updated memory management approach. The Rule of Three was implemented correctly, and object lifetime was managed through placement `new` and explicit destructor calls.

The custom memory allocation utilities in `Memory.h` worked as expected and can now be reused by other data structures in the Collections Library. All implemented methods passed the test cases, confirming that the updated implementation behaves correctly.

## Learning

This session helped me understand how placement `new` separates memory allocation from object construction. I also gained a better understanding of the Rule of Three and why proper copy construction, assignment, and destruction are essential when managing dynamic memory manually. Writing multiple test cases for every method also reinforced the importance of testing each operation thoroughly before moving on to the next implementation stage.