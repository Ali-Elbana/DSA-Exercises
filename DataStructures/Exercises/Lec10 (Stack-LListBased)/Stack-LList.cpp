/*
============================================================
* Project: [Stack Linked List based]
* File:    [Stack-LList.cpp]
* Author:  [Ali El-bana]
* Date:    [2025-08-14]
* Version: [v1.0]
------------------------------------------------------------
* Description:
* [Self implementation of a stack based linked list]
------------------------------------------------------------
* Notes:
* [This is for an educational purpose]
============================================================
*/

/* ====================== Includes ====================== */
#include <iostream>
#include <vector>
#include <string>
#include "GS-LList.cpp"

/* =================== Namespace Usage ================== */
using std::cout;
using std::cin;
using std::endl;


/* =================== Global Constants ================= */
// const double PI = 3.14159;

/* ====================== Declarations ================== */
// ▼▼▼ Template Class: Stack ▼▼▼
template<typename T>
class Stack ;
// ▲▲▲ End of Stack ▲▲▲

/* ===================== Class Definitions =============== */
// ▼▼▼ Template Class: Stack ▼▼▼
template<typename T>
class Stack 
{
private:
    LinkedList<T> list; // Using our generic linked list as the underlying data structure
    
public:
    // Constructor
    Stack();
    
    // Copy Constructor
    Stack(const Stack<T>& other);
    
    // Copy Assignment Operator
    Stack<T>& operator=(const Stack<T>& other);
    
    // Destructor
    ~Stack();
    
    // Method Declarations:
    
    // ▼▼▼ Core Stack Operations ▼▼▼
    void push(const T& value);                 // Push element onto the stack
    bool pop();                                // Pop element from the stack
    T peek() const;                            // Get top element without removing it
    // ▲▲▲ End of Core Stack Operations ▲▲▲
    
    // ▼▼▼ Utility Methods ▼▼▼
    bool isEmpty() const;                      // Check if stack is empty
    size_t size() const;                       // Get number of elements in stack
    void print() const;                        // Print all elements in the stack
    void clear();                              // Clear all elements from stack
    // ▲▲▲ End of Utility Methods ▲▲▲
};
// ▲▲▲ End of Stack ▲▲▲


/* ==================== Function Prototypes ============== */
// ▼▼▼ Function: testStackOperations ▼▼▼
template<typename T>
void testStackOperations();
// ▲▲▲ End of testStackOperations ▲▲▲


/* ==================== Main Application ================= */
int main(void) 
{
    // ----- Initialization -----
    system("cls");
    cout << "Program started...\n";
    
    // ----- Logic -----
    
    // Test with integers
    cout << "\n========== Testing Stack with Integers ==========\n";
    testStackOperations<int>();
    
    // Test with strings
    cout << "\n========== Testing Stack with Strings ==========\n";
    testStackOperations<std::string>();
    
    // Test with characters
    cout << "\n========== Testing Stack with Characters ==========\n";
    testStackOperations<char>();
	
    // ----- End -----
    return 0;
}

/* ================== Function/Method Definitions =============== */

// ▼▼▼ Stack Constructor ▼▼▼
template<typename T>
Stack<T>::Stack() : list()
{
}
// ▲▲▲ End of Stack Constructor ▲▲▲

// ▼▼▼ Stack Copy Constructor ▼▼▼
template<typename T>
Stack<T>::Stack(const Stack<T>& other) : list(other.list)
{
}
// ▲▲▲ End of Stack Copy Constructor ▲▲▲

// ▼▼▼ Stack Copy Assignment Operator ▼▼▼
template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
    if(this != &other)
    {
        list = other.list;
    }
    return *this;
}
// ▲▲▲ End of Stack Copy Assignment Operator ▲▲▲

// ▼▼▼ Stack Destructor ▼▼▼
template<typename T>
Stack<T>::~Stack()
{
    // LinkedList destructor will handle cleanup automatically
}
// ▲▲▲ End of Stack Destructor ▲▲▲

// ▼▼▼ Method: push ▼▼▼
template<typename T>
void Stack<T>::push(const T& value)
{
	list.insertFirst(value);
}
// ▲▲▲ End of push ▲▲▲

// ▼▼▼ Method: pop ▼▼▼
template<typename T>
bool Stack<T>::pop()
{
	bool isDeleted{false};
	
	if(list.isEmpty() == true)
	{
		cout << "\nStack is empty, cannot pop.";
		isDeleted = false;
	}
	else
	{
		list.deleteHead();
		isDeleted = true;
	}
	
	return isDeleted;
}
// ▲▲▲ End of pop ▲▲▲

// ▼▼▼ Method: peek ▼▼▼
template<typename T>
T Stack<T>::peek() const
{
	T result = T(); // default constructed value
	
    if(list.isEmpty() == true)
    {
        cout << "\nStack is empty, cannot peek.";
        result = T(); // Return default constructed value
    }
    else
	{
		result = list.getFirst(); // Get the first element (top of stack)
	}
    return result;
}
// ▲▲▲ End of peek ▲▲▲

// ▼▼▼ Method: isEmpty ▼▼▼
template<typename T>
bool Stack<T>::isEmpty() const
{
	return list.isEmpty();
}
// ▲▲▲ End of isEmpty ▲▲▲

// ▼▼▼ Method: size ▼▼▼
template<typename T>
size_t Stack<T>::size() const
{
    return list.getLength();
}
// ▲▲▲ End of size ▲▲▲

// ▼▼▼ Method: print ▼▼▼
template<typename T>
void Stack<T>::print() const
{
    if(list.isEmpty() == true)
    {
        cout << "\nStack is empty.\n";
        return;
    }
    else
	{
		cout << "\nStack (top to bottom): ";
		list.printList();
	}
}
// ▲▲▲ End of print ▲▲▲

// ▼▼▼ Method: clear ▼▼▼
template<typename T>
void Stack<T>::clear()
{
    list.clear();
}
// ▲▲▲ End of clear ▲▲▲

// ▼▼▼ testStackOperations Definition ▼▼▼
template<typename T>
void testStackOperations()
{
    if constexpr (std::is_same_v<T, int>)
    {
        Stack<int> stack;
        
        cout << "\n=== Testing Integer Stack ===";
        cout << "\nPushing elements: 10, 20, 30, 40";
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.push(40);
        
        cout << "\nStack contents:";
        stack.print();
        
        cout << "\nStack size: " << stack.size();
        cout << "\nTop element (peek): " << stack.peek();
        
        cout << "\n\nPopping one element...";
        stack.pop();
        cout << "\nStack after pop:";
        stack.print();
        cout << "\nNew top element: " << stack.peek();
        
        cout << "\n\nPopping all remaining elements:";
        while(!stack.isEmpty())
        {
            cout << "\nPopped: " << stack.peek();
            stack.pop();
        }
        
        cout << "\nStack is now empty: " << (stack.isEmpty() ? "Yes" : "No");
        stack.print();
    }
    else if constexpr (std::is_same_v<T, std::string>)
    {
        Stack<std::string> stack;
        
        cout << "\n=== Testing String Stack ===";
        cout << "\nPushing elements: \"Hello\", \"World\", \"Stack\", \"Test\"";
        stack.push("Hello");
        stack.push("World");
        stack.push("Stack");
        stack.push("Test");
        
        cout << "\nStack contents:";
        stack.print();
        
        cout << "\nStack size: " << stack.size();
        cout << "\nTop element (peek): " << stack.peek();
        
        cout << "\n\nPopping two elements:";
        cout << "\nPopped: " << stack.peek();
        stack.pop();
        cout << "\nPopped: " << stack.peek();
        stack.pop();
        
        cout << "\nRemaining stack:";
        stack.print();
    }
    else if constexpr (std::is_same_v<T, char>)
    {
        Stack<char> stack;
        
        cout << "\n=== Testing Character Stack ===";
        cout << "\nPushing elements: 'A', 'B', 'C', 'D'";
        stack.push('A');
        stack.push('B');
        stack.push('C');
        stack.push('D');
        
        cout << "\nStack contents:";
        stack.print();
        
        cout << "\nStack size: " << stack.size();
        cout << "\nTop element (peek): " << stack.peek();
        
        cout << "\n\nTesting stack reversal:";
        cout << "\nPopping all elements: ";
        while(!stack.isEmpty())
        {
            cout << stack.peek() << " ";
            stack.pop();
        }
        cout << "\n";
        
        cout << "\nStack is now empty: " << (stack.isEmpty() ? "Yes" : "No");
    }
}
// ▲▲▲ End of testStackOperations ▲▲▲


/* ======================= End of File =================== */
