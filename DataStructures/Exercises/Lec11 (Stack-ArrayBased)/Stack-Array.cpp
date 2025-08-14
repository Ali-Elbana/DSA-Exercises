/*
============================================================
* Project: Array-Based Stack Data Structure
* File:    Stack-Array.cpp
* Author:  [Ali El-bana]
* Date:    2025-08-15
* Version: v1.0
------------------------------------------------------------
* Description:
* Implementation file for template-based Stack class with
* dynamic array storage and automatic memory management
------------------------------------------------------------
* Notes:
* - All methods include proper exception handling
* - Memory is automatically managed through RAII principles
* - Template instantiations provided at end of file
============================================================
*/

/* ====================== Includes ====================== */
#include "Stack-Array.hpp"
#include <string>

/* =================== Namespace Usage ================== */
using std::invalid_argument;
using std::underflow_error;
using std::cout;
using std::endl;
using std::string;

/* ================== Method Definitions ================ */

// ▼▼▼ Constructor Definition ▼▼▼
template <typename T>
Stack<T>::Stack(int initialCapacity) : capacity(initialCapacity), topIndex(-1) 
{
    // ----- Input Validation -----
    if(initialCapacity <= 0) 
	{
        throw invalid_argument("Initial capacity must be positive");
    }
    
    // ----- Memory Allocation -----
    arr = new T[capacity];
}
// ▲▲▲ End of Constructor ▲▲▲

// ▼▼▼ Destructor Definition ▼▼▼
template <typename T>
Stack<T>::~Stack() 
{
    // ----- Memory Deallocation -----
    delete[] arr;
}
// ▲▲▲ End of Destructor ▲▲▲

// ▼▼▼ Copy Constructor Definition ▼▼▼
template <typename T>
Stack<T>::Stack(const Stack& other) : capacity(other.capacity), topIndex(other.topIndex) 
{
    // ----- Memory Allocation -----
    arr = new T[capacity];
    
    // ----- Deep Copy Elements -----
    for(int i = 0; i <= topIndex; ++i) 
	{
        arr[i] = other.arr[i];
    }
}
// ▲▲▲ End of Copy Constructor ▲▲▲

// ▼▼▼ Assignment Operator Definition ▼▼▼
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) 
{
    // ----- Self-Assignment Check -----
    if(this != &other) 
	{
        // ----- Cleanup Current Resources -----
        delete[] arr;
        
        // ----- Copy New Data -----
        capacity = other.capacity;
        topIndex = other.topIndex;
        arr = new T[capacity];
        
        // ----- Deep Copy Elements -----
        for(int i = 0; i <= topIndex; ++i) 
		{
            arr[i] = other.arr[i];
        }
    }
    return *this;
}
// ▲▲▲ End of Assignment Operator ▲▲▲

// ▼▼▼ Resize Helper Method Definition ▼▼▼
template <typename T>
void Stack<T>::resize() 
{
    // ----- Calculate New Capacity -----
    int newCapacity = capacity * GROWTH_FACTOR;
    T* newArr = new T[newCapacity];
    
    // ----- Copy Existing Elements -----
    for(int i = 0; i <= topIndex; ++i) 
	{
        newArr[i] = arr[i];
    }
    
    // ----- Update Array and Capacity -----
    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
}
// ▲▲▲ End of Resize Helper Method ▲▲▲

// ▼▼▼ Push Method Definition ▼▼▼
template <typename T>
void Stack<T>::push(const T& element) 
{
    // ----- Check if Resize Needed -----
    if(topIndex + 1 >= capacity) 
	{
        resize();
    }
    
    // ----- Add Element to Stack -----
    arr[++topIndex] = element;
}
// ▲▲▲ End of Push Method ▲▲▲

// ▼▼▼ Pop Method Definition ▼▼▼
template <typename T>
T Stack<T>::pop() 
{
    // ----- Validate Stack State -----
    if(isEmpty() == true) 
	{
        throw underflow_error("Stack is empty - cannot pop");
    }
    
    // ----- Return and Remove Top Element -----
    return arr[topIndex--];
}
// ▲▲▲ End of Pop Method ▲▲▲

// ▼▼▼ Peek Method Definition ▼▼▼
template <typename T>
T Stack<T>::peek() const 
{
    // ----- Validate Stack State -----
    if(isEmpty() == true) 
	{
        throw underflow_error("Stack is empty - cannot peek");
    }
    
    // ----- Return Top Element -----
    return arr[topIndex];
}
// ▲▲▲ End of Peek Method ▲▲▲

// ▼▼▼ isEmpty Method Definition ▼▼▼
template <typename T>
bool Stack<T>::isEmpty() const 
{
    // ----- Check if Stack is Empty -----
    return topIndex == -1;
}
// ▲▲▲ End of isEmpty Method ▲▲▲

// ▼▼▼ Size Method Definition ▼▼▼
template <typename T>
int Stack<T>::size() const 
{
    // ----- Return Current Size -----
    return topIndex + 1;
}
// ▲▲▲ End of Size Method ▲▲▲

// ▼▼▼ Print Method Definition ▼▼▼
template <typename T>
void Stack<T>::print() const 
{
    // ----- Handle Empty Stack -----
    if(isEmpty() == true) 
	{
        cout << "Stack is empty" << endl;
        return;
    }
    
    // ----- Display Stack Contents -----
    cout << "Stack contents (top to bottom): ";
    for(int i = topIndex; i >= 0; --i) 
	{
        cout << arr[i];
        if (i > 0) cout << " -> ";
    }
    cout << endl;
}
// ▲▲▲ End of Print Method ▲▲▲

// ▼▼▼ GetCapacity Method Definition ▼▼▼
template <typename T>
int Stack<T>::getCapacity() const 
{
    // ----- Return Current Capacity -----
    return capacity;
}
// ▲▲▲ End of GetCapacity Method ▲▲▲

/* ============== Template Instantiations =============== */
// ----- Explicit Template Instantiations for Common Types -----
template class Stack<int>;
template class Stack<double>;
template class Stack<char>;
template class Stack<string>;

/* ======================= End of File =================== */