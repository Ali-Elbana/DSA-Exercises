/*
============================================================
* Project: Array-Based Stack Data Structure
* File:    main.cpp
* Author:  [Ali El-bana]
* Date:    2025-08-15
* Version: v1.0
------------------------------------------------------------
* Description:
* Demonstration program showing Stack implementation usage
* with various data types and comprehensive testing
------------------------------------------------------------
* Notes:
* - Includes error handling demonstrations
* - Tests dynamic resizing functionality
* - Shows usage with different data types
============================================================
*/

/* ====================== Includes ====================== */
#include "Stack-Array.hpp"
#include <iostream>
#include <string>
#include <exception>

/* =================== Namespace Usage ================== */
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::exception;

/* =================== Global Constants ================= */
// Demo configuration constants
const int INITIAL_SMALL_CAPACITY = 3;

/* ==================== Function Prototypes ============== */
// ▼▼▼ Function: demonstrateIntStack ▼▼▼
void demonstrateIntStack();
// ▲▲▲ End of demonstrateIntStack ▲▲▲

// ▼▼▼ Function: demonstrateStringStack ▼▼▼
void demonstrateStringStack();
// ▲▲▲ End of demonstrateStringStack ▲▲▲

// ▼▼▼ Function: demonstrateErrorHandling ▼▼▼
void demonstrateErrorHandling();
// ▲▲▲ End of demonstrateErrorHandling ▲▲▲

// ▼▼▼ Function: printSectionHeader ▼▼▼
void printSectionHeader(const string& title);
// ▲▲▲ End of printSectionHeader ▲▲▲

/* ==================== Main Application ================= */
int main(void) {
    // ----- Initialization -----
    system("cls"); // Clear console (Windows)
    // system("clear"); // Uncomment for Linux/Mac
    
    cout << "Stack Data Structure Implementation Demo" << endl;
    cout << "=======================================" << endl << endl;
    
    // ----- Demo Logic -----
    demonstrateIntStack();
    demonstrateStringStack(); 
    demonstrateErrorHandling();
    
    // ----- Program End -----
    cout << "Demo completed successfully!" << endl;
    return 0;
}

/* ================== Function/Method Definitions =============== */

// ▼▼▼ demonstrateIntStack Definition ▼▼▼
void demonstrateIntStack() {
    printSectionHeader("Integer Stack Demo");
    
    // ----- Create Stack with Small Initial Capacity -----
    Stack<int> intStack(INITIAL_SMALL_CAPACITY);
    
    // ----- Test Push Operations -----
    cout << "Pushing elements: 10, 20, 30, 40, 50" << endl;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    intStack.push(40);
    intStack.push(50);
    
    // ----- Display Stack Information -----
    intStack.print();
    cout << "Size: " << intStack.size() << endl;
    cout << "Capacity: " << intStack.getCapacity() << endl;
    
    // ----- Test Peek Operation -----
    cout << "Top element (peek): " << intStack.peek() << endl;
    
    // ----- Test Pop Operations -----
    cout << "\nPopping elements:" << endl;
    while (!intStack.isEmpty()) {
        cout << "Popped: " << intStack.pop() << endl;
        cout << "Remaining size: " << intStack.size() << endl;
    }
    
    // ----- Final State Check -----
    cout << "Is empty: " << (intStack.isEmpty() ? "Yes" : "No") << endl;
    intStack.print();
    cout << endl;
}
// ▲▲▲ End of demonstrateIntStack ▲▲▲

// ▼▼▼ demonstrateStringStack Definition ▼▼▼
void demonstrateStringStack() {
    printSectionHeader("String Stack Demo");
    
    // ----- Create String Stack -----
    Stack<string> stringStack;
    
    // ----- Add String Elements -----
    stringStack.push("First");
    stringStack.push("Second");
    stringStack.push("Third");
    
    // ----- Display and Test Operations -----
    stringStack.print();
    
    cout << "Peek: " << stringStack.peek() << endl;
    cout << "Pop: " << stringStack.pop() << endl;
    
    stringStack.print();
    cout << endl;
}
// ▲▲▲ End of demonstrateStringStack ▲▲▲

// ▼▼▼ demonstrateErrorHandling Definition ▼▼▼
void demonstrateErrorHandling() {
    printSectionHeader("Error Handling Demo");
    
    // ----- Create Empty Stack -----
    Stack<int> emptyStack;
    
    // ----- Test Peek on Empty Stack -----
    try {
        cout << "Trying to peek empty stack..." << endl;
        emptyStack.peek();
    } catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    
    // ----- Test Pop on Empty Stack -----
    try {
        cout << "Trying to pop from empty stack..." << endl;
        emptyStack.pop();
    } catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    
    cout << endl;
}
// ▲▲▲ End of demonstrateErrorHandling ▲▲▲

// ▼▼▼ printSectionHeader Definition ▼▼▼
void printSectionHeader(const string& title) {
    // ----- Print Formatted Section Header -----
    cout << "=== " << title << " ===" << endl;
}
// ▲▲▲ End of printSectionHeader ▲▲▲

/* ======================= End of File =================== */