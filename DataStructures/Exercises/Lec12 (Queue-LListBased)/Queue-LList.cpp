/*
============================================================
* Project: [Queue Linked List based]
* File:    [Queue-LList.cpp]
* Author:  [Ali El-bana]
* Date:    [2025-08-15]
* Version: [v1.0]
------------------------------------------------------------
* Description:
* [Self implementation of a queue based linked list]
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
// ▼▼▼ Template Class: Queue ▼▼▼
template<typename T>
class Queue ;
// ▲▲▲ End of Queue ▲▲▲

/* ===================== Class Definitions =============== */
// ▼▼▼ Template Class: Queue ▼▼▼
template<typename T>
class Queue 
{
private:
    LinkedList<T> list; // Using our generic linked list as the underlying data structure
    
public:
    // Constructor
    Queue();
    
    // Copy Constructor
    Queue(const Queue<T>& other);
    
    // Copy Assignment Operator
    Queue<T>& operator=(const Queue<T>& other);
    
    // Destructor
    ~Queue();
    
    // Method Declarations:
    
    // ▼▼▼ Core Queue Operations ▼▼▼
    void enqueue(const T& value);                 // enqueue element onto the Queue
    T dequeue();                                 // dequeue element from the Queue
    T peek() const;                             // Get top element without removing it
    // ▲▲▲ End of Core Queue Operations ▲▲▲
    
    // ▼▼▼ Utility Methods ▼▼▼
    bool isEmpty() const;                      // Check if Queue is empty
    size_t size() const;                       // Get number of elements in Queue
    void print() const;                        // Print all elements in the Queue
    void clear();                              // Clear all elements from Queue
    // ▲▲▲ End of Utility Methods ▲▲▲
};
// ▲▲▲ End of Queue ▲▲▲


/* ==================== Function Prototypes ============== */
// ▼▼▼ Function: testQueueOperations ▼▼▼
template<typename T>
void testQueueOperations();
// ▲▲▲ End of testQueueOperations ▲▲▲


/* ==================== Main Application ================= */
int main(void) 
{
    // ----- Initialization -----
    system("cls");
    cout << "Program started...\n";
    
    // ----- Logic -----
    
    // Test with integers
    cout << "\n========== Testing Queue with Integers ==========\n";
    testQueueOperations<int>();
    
    // Test with strings
    cout << "\n========== Testing Queue with Strings ==========\n";
    testQueueOperations<std::string>();
    
    // Test with characters
    cout << "\n========== Testing Queue with Characters ==========\n";
    testQueueOperations<char>();
	
    // ----- End -----
    return 0;
}

/* ================== Function/Method Definitions =============== */

// ▼▼▼ Queue Constructor ▼▼▼
template<typename T>
Queue<T>::Queue() : list()
{
}
// ▲▲▲ End of Queue Constructor ▲▲▲

// ▼▼▼ Queue Copy Constructor ▼▼▼
template<typename T>
Queue<T>::Queue(const Queue<T>& other) : list(other.list)
{
}
// ▲▲▲ End of Queue Copy Constructor ▲▲▲

// ▼▼▼ Queue Copy Assignment Operator ▼▼▼
template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
    if(this != &other)
    {
        list = other.list;
    }
    return *this;
}
// ▲▲▲ End of Queue Copy Assignment Operator ▲▲▲

// ▼▼▼ Queue Destructor ▼▼▼
template<typename T>
Queue<T>::~Queue()
{
    // LinkedList destructor will handle cleanup automatically
}
// ▲▲▲ End of Queue Destructor ▲▲▲

// ▼▼▼ Method: enqueue ▼▼▼
template<typename T>
void Queue<T>::enqueue(const T& value)
{
	list.insertLast(value);
}
// ▲▲▲ End of enqueue ▲▲▲

// ▼▼▼ Method: dequeue ▼▼▼
template<typename T>
T Queue<T>::dequeue()
{
	T result = T();
	
	if(list.isEmpty() == true)
	{
		cout << "\nQueue is empty, cannot dequeue.";
		result = T();
	}
	else
	{
		result = list.getFirst(); // Get the first element (top of Queue)
		list.deleteHead();
	}
	
	return result;
}
// ▲▲▲ End of dequeue ▲▲▲

// ▼▼▼ Method: peek ▼▼▼
template<typename T>
T Queue<T>::peek() const
{
	T result = T(); // default constructed value
	
    if(list.isEmpty() == true)
    {
        cout << "\nQueue is empty, cannot peek.";
        result = T(); // Return default constructed value
    }
    else
	{
		result = list.getFirst(); // Get the first element (top of Queue)
	}
    return result;
}
// ▲▲▲ End of peek ▲▲▲

// ▼▼▼ Method: isEmpty ▼▼▼
template<typename T>
bool Queue<T>::isEmpty() const
{
	return list.isEmpty();
}
// ▲▲▲ End of isEmpty ▲▲▲

// ▼▼▼ Method: size ▼▼▼
template<typename T>
size_t Queue<T>::size() const
{
    return list.getLength();
}
// ▲▲▲ End of size ▲▲▲

// ▼▼▼ Method: print ▼▼▼
template<typename T>
void Queue<T>::print() const
{
    if(list.isEmpty() == true)
    {
        cout << "\nQueue is empty.\n";
        return;
    }
    else
	{
		cout << "\nQueue (top to bottom): ";
		list.printList();
	}
}
// ▲▲▲ End of print ▲▲▲

// ▼▼▼ Method: clear ▼▼▼
template<typename T>
void Queue<T>::clear()
{
    list.clear();
}
// ▲▲▲ End of clear ▲▲▲

// ▼▼▼ testQueueOperations Definition ▼▼▼
template<typename T>
void testQueueOperations()
{
    if constexpr (std::is_same_v<T, int>)
    {
        Queue<int> Queue;
        
        cout << "\n=== Testing Integer Queue ===";
        cout << "\nenqueueing elements: 10, 20, 30, 40";
        Queue.enqueue(10);
        Queue.enqueue(20);
        Queue.enqueue(30);
        Queue.enqueue(40);
        
        cout << "\nQueue contents:";
        Queue.print();
        
        cout << "\nQueue size: " << Queue.size();
        cout << "\nTop element (peek): " << Queue.peek();
        
        cout << "\n\ndequeueping one element...";
        Queue.dequeue();
        cout << "\nQueue after dequeue:";
        Queue.print();
        cout << "\nNew top element: " << Queue.peek();
        
        cout << "\n\ndequeueping all remaining elements:";
        while(!Queue.isEmpty())
        {
            cout << "\ndequeueped: " << Queue.peek();
            Queue.dequeue();
        }
        
        cout << "\nQueue is now empty: " << (Queue.isEmpty() ? "Yes" : "No");
        Queue.print();
    }
    else if constexpr (std::is_same_v<T, std::string>)
    {
        Queue<std::string> Queue;
        
        cout << "\n=== Testing String Queue ===";
        cout << "\nenqueueing elements: \"Hello\", \"World\", \"Queue\", \"Test\"";
        Queue.enqueue("Hello");
        Queue.enqueue("World");
        Queue.enqueue("Queue");
        Queue.enqueue("Test");
        
        cout << "\nQueue contents:";
        Queue.print();
        
        cout << "\nQueue size: " << Queue.size();
        cout << "\nTop element (peek): " << Queue.peek();
        
        cout << "\n\ndequeueping two elements:";
        cout << "\ndequeueped: " << Queue.peek();
        Queue.dequeue();
        cout << "\ndequeueped: " << Queue.peek();
        Queue.dequeue();
        
        cout << "\nRemaining Queue:";
        Queue.print();
    }
    else if constexpr (std::is_same_v<T, char>)
    {
        Queue<char> Queue;
        
        cout << "\n=== Testing Character Queue ===";
        cout << "\nenqueueing elements: 'A', 'B', 'C', 'D'";
        Queue.enqueue('A');
        Queue.enqueue('B');
        Queue.enqueue('C');
        Queue.enqueue('D');
        
        cout << "\nQueue contents:";
        Queue.print();
        
        cout << "\nQueue size: " << Queue.size();
        cout << "\nTop element (peek): " << Queue.peek();
        
        cout << "\n\nTesting Queue reversal:";
        cout << "\ndequeueping all elements: ";
        while(!Queue.isEmpty())
        {
            cout << Queue.peek() << " ";
            Queue.dequeue();
        }
        cout << "\n";
        
        cout << "\nQueue is now empty: " << (Queue.isEmpty() ? "Yes" : "No");
    }
}
// ▲▲▲ End of testQueueOperations ▲▲▲


/* ======================= End of File =================== */
