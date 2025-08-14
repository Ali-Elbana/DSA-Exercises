/*
============================================================
* Project: Array-Based Stack Data Structure
* File:    Stack-Array.hpp
* Author:  [Ali El-bana]
* Date:    2025-08-15
* Version: v1.0
------------------------------------------------------------
* Description:
* Template-based Stack implementation using dynamic arrays
* with automatic resizing capability and full RAII support
------------------------------------------------------------
* Notes:
* - Uses dynamic memory allocation with automatic expansion
* - Thread-safe operations not guaranteed (single-threaded use)
* - Explicit template instantiations provided for common types
============================================================
*/

#ifndef STACK_H
#define STACK_H

/* ====================== Includes ====================== */
#include <iostream>
#include <stdexcept>

/* =================== Namespace Usage ================== */
using std::cout;
using std::endl;

/* =================== Global Constants ================= */
// Default initial capacity for new stacks
const int DEFAULT_CAPACITY = 10;
const int GROWTH_FACTOR = 2;

/* ====================== Declarations ================== */
// ▼▼▼ Class: Stack ▼▼▼
template <typename T>
class Stack;
// ▲▲▲ End of Stack ▲▲▲

/* ===================== Class Definitions =============== */
// ▼▼▼ Class: Stack ▼▼▼
template <typename T>
class Stack {
private:
    // ----- Private Data Members -----
    T* arr;           // Dynamic array to store stack elements
    int capacity;     // Maximum capacity of the stack
    int topIndex;     // Index of the top element (-1 if empty)
    
    // ----- Private Helper Methods -----
    void resize();    // Helper function to resize the array when needed

public:
    // ----- Constructors & Destructor -----
    explicit Stack(int initialCapacity = DEFAULT_CAPACITY);
    ~Stack();
    Stack(const Stack& other);                    // Copy constructor
    Stack& operator=(const Stack& other);         // Assignment operator
    
    // ----- Core Stack Operations -----
    void push(const T& element);                  // Add element to top
    T pop();                                      // Remove and return top element
    T peek() const;                               // Get top element without removal
    
    // ----- Utility Functions -----
    bool isEmpty() const;                         // Check if stack is empty
    int size() const;                             // Get current number of elements
    void print() const;                           // Display all stack elements
    
    // ----- Additional Utilities -----
    int getCapacity() const;                      // Get current capacity
};
// ▲▲▲ End of Stack ▲▲▲

#endif // STACK_H

/* ======================= End of File =================== */