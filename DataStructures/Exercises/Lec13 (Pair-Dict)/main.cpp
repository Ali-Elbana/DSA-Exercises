/*
============================================================
* Project: Dictionary with Custom Pair Implementation
* File:    main.cpp
* Author:  [Ali El-bana]
* Date:    [2025-08-18]
* Version: [v1.0]
------------------------------------------------------------
* Description:
* Main application file demonstrating the usage of custom
* Dictionary class with Pair implementation. Shows various
* operations including set, get, remove, and print.
------------------------------------------------------------
* Notes:
* - Demonstrates usage with different data types
* - Includes error handling examples
* - Shows both successful and failed operations
============================================================
*/

/* ====================== Includes ====================== */
#include <iostream>
#include <string>
#include "Dict-Pair.hpp"

/* =================== Namespace Usage ================== */
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::exception;

/* =================== Global Constants ================= */
// const int MAX_SIZE = 100;

/* ==================== Function Prototypes ============== */
// ▼▼▼ Function: demonstrateStringIntDict ▼▼▼
void demonstrateStringIntDict();
// ▲▲▲ End of demonstrateStringIntDict ▲▲▲

// ▼▼▼ Function: demonstrateIntStringDict ▼▼▼
void demonstrateIntStringDict();
// ▲▲▲ End of demonstrateIntStringDict ▲▲▲

// ▼▼▼ Function: demonstratePairFunctionality ▼▼▼
void demonstratePairFunctionality();
// ▲▲▲ End of demonstratePairFunctionality ▲▲▲

/* ==================== Main Application ================= */
int main(void) 
{
    // ----- Initialization -----
    system("cls");
    cout << "=== Dictionary with Custom Pair Implementation ===" << endl;
    cout << "Program started..." << endl << endl;
    
    // ----- Logic -----
    
    // Demonstrate Pair functionality
    cout << "=== Testing Custom Pair Class ===" << endl;
    demonstratePairFunctionality();
    cout << endl;
    
    // Demonstrate Dictionary with string keys and int values
    cout << "=== Testing Dictionary<string, int> ===" << endl;
    demonstrateStringIntDict();
    cout << endl;
    
    // Demonstrate Dictionary with int keys and string values
    cout << "=== Testing Dictionary<int, string> ===" << endl;
    demonstrateIntStringDict();
    cout << endl;

    // ----- End -----
    cout << "Program completed successfully!" << endl;
    return 0;
}

/* ================== Function/Method Definitions =============== */

// ▼▼▼ demonstratePairFunctionality Definition ▼▼▼
void demonstratePairFunctionality() 
{
    cout << "Creating pairs and testing functionality:" << endl;
    
    // Create different types of pairs
    Pair<string, int> pair1("apple", 5);
    Pair<int, string> pair2(42, "answer");
    Pair<string, int> pair3;  // Default constructor
    
    cout << "Pair 1: " << pair1.first << " -> " << pair1.second << endl;
    cout << "Pair 2: " << pair2.first << " -> " << pair2.second << endl;
    cout << "Pair 3 (default): " << pair3.first << " -> " << pair3.second << endl;
    
    // Test copy constructor
    Pair<string, int> pair4(pair1);
    cout << "Pair 4 (copy of pair1): " << pair4.first << " -> " << pair4.second << endl;
    
    // Test assignment operator
    pair3 = pair1;
    cout << "Pair 3 (after assignment): " << pair3.first << " -> " << pair3.second << endl;
}
// ▲▲▲ End of demonstratePairFunctionality ▲▲▲

// ▼▼▼ demonstrateStringIntDict Definition ▼▼▼
void demonstrateStringIntDict() 
{
    Dictionary<string, int> dict;
    
    // Add some key-value pairs
    cout << "Adding items to dictionary..." << endl;
    dict.set("apple", 5);
    dict.set("banana", 3);
    dict.set("orange", 8);
    dict.set("grape", 12);
    
    cout << "After adding items:" << endl;
    dict.print();
    cout << "Size: " << dict.size() << endl << endl;
    
    // Get values
    cout << "Getting values:" << endl;
    try {
        cout << "apple: " << dict.get("apple") << endl;
        cout << "banana: " << dict.get("banana") << endl;
        cout << "orange: " << dict.get("orange") << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    cout << endl;
    
    // Update existing key
    cout << "Updating apple from 5 to 10..." << endl;
    dict.set("apple", 10);
    dict.print();
    cout << endl;
    
    // Remove a key
    cout << "Removing banana..." << endl;
    if (dict.remove("banana")) {
        cout << "Successfully removed banana" << endl;
        dict.print();
        cout << "Size: " << dict.size() << endl;
    } else {
        cout << "Failed to remove banana" << endl;
    }
    cout << endl;
    
    // Try to get non-existent key
    cout << "Trying to get removed key 'banana':" << endl;
    try {
        cout << "banana: " << dict.get("banana") << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
}
// ▲▲▲ End of demonstrateStringIntDict ▲▲▲

// ▼▼▼ demonstrateIntStringDict Definition ▼▼▼
void demonstrateIntStringDict() 
{
    Dictionary<int, string> numDict;
    
    // Add some number-word pairs
    cout << "Adding number-word pairs..." << endl;
    numDict.set(1, "one");
    numDict.set(2, "two");
    numDict.set(3, "three");
    numDict.set(4, "four");
    numDict.set(5, "five");
    
    numDict.print();
    cout << "Size: " << numDict.size() << endl << endl;
    
    // Get some values
    cout << "Getting values:" << endl;
    try {
        cout << "Key 2: " << numDict.get(2) << endl;
        cout << "Key 4: " << numDict.get(4) << endl;
        cout << "Key 1: " << numDict.get(1) << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    cout << endl;
    
    // Remove some keys
    cout << "Removing keys 2 and 4..." << endl;
    numDict.remove(2);
    numDict.remove(4);
    numDict.print();
    cout << "Size: " << numDict.size() << endl << endl;
    
    // Clear all
    cout << "Clearing all entries..." << endl;
    numDict.clear();
    numDict.print();
    cout << "Size: " << numDict.size() << endl;
}
// ▲▲▲ End of demonstrateIntStringDict ▲▲▲

/* ======================= End of File =================== */