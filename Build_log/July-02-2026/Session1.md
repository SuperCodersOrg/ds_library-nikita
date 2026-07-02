# Build Log

**Date:** July 2, 2026  
**Time:** 9:30 AM – 12:30 PM  
**Duration:** 3 Hours

## Goal

Prepare the design proposal for the LinkedList data structure and update the previously submitted DynamicArray proposal and memory diagrams according to the project requirements.

## What I Tried

- Designed the public API for the `LinkedList` data structure.
- Planned the internal node structure and overall memory layout of the LinkedList.
- Prepared the LinkedList design proposal, including the proposed methods, internal representation, and design decisions.
- Drew the memory diagrams for the LinkedList showing:
  - Node structure
  - Heap allocation of individual nodes
  - Pointer relationships between nodes
  - Head and tail references
- Reviewed the DynamicArray design proposal after comparing it with the project requirements.
- Updated the DynamicArray memory diagrams by removing the DynamicArray object from the heap representation, since only the internal data array should reside on the heap while the DynamicArray object itself exists where it is instantiated.
- Revised the DynamicArray proposal and memory diagrams to accurately represent the required memory layout and object ownership.

## Outcome

The LinkedList design proposal was completed along with the corresponding memory diagrams. The proposal now clearly defines the planned API, internal memory representation, and node organization.

The DynamicArray proposal was also updated to comply with the project requirements. The corrected memory diagrams now accurately distinguish between the DynamicArray object and its dynamically allocated data, providing a clearer representation of stack and heap memory usage.

## Learning

This session improved my understanding of how important accurate memory diagrams are during the design phase. While reviewing my previous proposal, I realized that representing the DynamicArray object on the heap was incorrect and could lead to confusion about object ownership. Correcting the diagrams helped reinforce the difference between an object itself and the dynamically allocated memory it manages.

Designing the LinkedList before implementation also helped me think through the node structure, pointer relationships, and memory organization in advance, making the upcoming implementation process clearer.