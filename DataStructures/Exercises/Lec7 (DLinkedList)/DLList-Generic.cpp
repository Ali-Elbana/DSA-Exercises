/*
============================================================
* Project: [Generic Double Linked List Implementation]
* File:    [DLinkedList.cpp]
* Author:  [Ali El-bana]
* Date:    [2025-08-13]
* Version: [v2.0] - Generic template version
------------------------------------------------------------
* Description:
* [Self implementation of a generic double linked list using templates]
------------------------------------------------------------
* Notes:
* [This is for an educational purpose]
============================================================
*/

/* ====================== Includes ====================== */
#include <iostream>
#include <string>


/* =================== Namespace Usage ================== */
using std::cout;
using std::cin;
using std::cerr;
using std::endl;


/* =================== Global Constants ================= */
// const double PI = 3.14159;

/* ====================== Declarations ================== */
// ▼▼▼ Template Class: Node ▼▼▼
template<typename T>
class Node;
// ▲▲▲ End of Node ▲▲▲

// ▼▼▼ Template Class: LinkedList ▼▼▼
template<typename T>
class LinkedList;
// ▲▲▲ End of LinkedList ▲▲▲



/* ===================== Class Definitions =============== */
// ▼▼▼ Template Class: Node ▼▼▼
template<typename T>
class Node
{
public:
	T data;
	Node<T> * next;
	Node<T> * prev;
	
	// Constructor
	Node(const T& val) : data(val), next(nullptr), prev(nullptr){}
};
// ▲▲▲ End of Node ▲▲▲

// ▼▼▼ Template Class: LinkedList ▼▼▼
template<typename T>
class LinkedList
{
private:
	Node<T> * head;
	Node<T> * tail;
	size_t length;
	
public:
	// Constructor
	LinkedList(): head(nullptr), tail(nullptr), length(0){}
	
	// Copy Constructor
	LinkedList(const LinkedList<T>& other) : head(nullptr), tail(nullptr), length(0)
	{
		Node<T> * currNode = other.head;
		while(currNode != nullptr)
		{
			insertLast(currNode->data);
			currNode = currNode->next;
		}
	}
	
	// Copy Assignment Operator
	LinkedList<T>& operator=(const LinkedList<T>& other)
	{
		if(this != &other) // Check for self-assignment
		{
			// Clear current list
			clear();
			
			// Copy from other list
			Node<T> * currNode = other.head;
			while(currNode != nullptr)
			{
				insertLast(currNode->data);
				currNode = currNode->next;
			}
		}
		return *this;
	}
	
	// Destructor
	~LinkedList()
	{
		clear();
	}
	
	// Methods:
	
	// ▼▼▼ Method: clear ▼▼▼
	void clear()
	{
		while(head != nullptr)
		{
			Node<T> * tmp = head;
			head = tmp->next;
			delete tmp;
		}
		tail = nullptr;
		length = 0;
	}
	// ▲▲▲ End of clear ▲▲▲
	
	// ▼▼▼ Method: copyFrom ▼▼▼
	void copyFrom(const LinkedList<T>& other)
	{
		// Clear current list first
		clear();
		
		// Copy all nodes from other list
		Node<T> * currNode = other.head;
		while(currNode != nullptr)
		{
			insertLast(currNode->data);
			currNode = currNode->next;
		}
	}
	// ▲▲▲ End of copyFrom ▲▲▲
	
	// ▼▼▼ Method: clone ▼▼▼
	LinkedList<T> clone() const
	{
		LinkedList<T> newList;
		Node<T> * currNode = head;
		
		while(currNode != nullptr)
		{
			newList.insertLast(currNode->data);
			currNode = currNode->next;
		}
		
		return newList;
	}
	// ▲▲▲ End of clone ▲▲▲
	
	// ▼▼▼ Method: getDataAt ▼▼▼
	T getDataAt(size_t idx) const
	{
		Node<T> * currNode = head;
		
		// Validation
		if(idx >= length)
		{
			cout << "\nIndex out of range.";
			return T(); // Return default constructed value
		}
		else
		{
			size_t i{0};
			
			while(i != idx)
			{
				currNode = currNode->next;
				i++;
			}
		}
		
		return currNode->data;
	}
	// ▲▲▲ End of getDataAt ▲▲▲
	
	// ▼▼▼ Method: getNodeAt ▼▼▼
	Node<T> * getNodeAt(size_t idx) const
	{
		Node<T> * currNode = head;
		
		// Validation
		if(idx >= length)
		{
			cerr << "\nIndex out of range.";
			return nullptr;
		}
		else
		{
			size_t i{0};
			
			while(i < idx)
			{
				currNode = currNode->next;
				i++;
			}
		}
		
		return currNode;
	}
	// ▲▲▲ End of getNodeAt ▲▲▲
	
	// ▼▼▼ Method: insertLast ▼▼▼
	void insertLast(const T& val)
	{
		Node<T> * newNode = new Node<T>(val);
		
		// Validation
		if(head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode; // prevNode->next points to newNode
			newNode->prev = tail;
			newNode->next = nullptr;
			tail = newNode;
		}
		
		// Update the list length
		length++; 
	}
	// ▲▲▲ End of insertLast ▲▲▲
	
	// ▼▼▼ Method: printList ▼▼▼
	void printList() const
	{
		Node<T> * currNode = head;
		
		cout << '\n';
		while(currNode != nullptr)
		{
			cout << currNode->data << " --> ";
			currNode = currNode->next;
		}
		cout << "NULL\n";
	}
	// ▲▲▲ End of printList ▲▲▲
	
	// ▼▼▼ Method: getLength ▼▼▼
	size_t getLength() const
	{
		return length;
	}
	// ▲▲▲ End of getLength ▲▲▲
	
	// ▼▼▼ Method: inserAfter ▼▼▼
	void inserAfter(size_t idx, const T& newData)
	{
		// Validation
		if(idx >= length)
		{
			cerr << "\nIndex out of range.";
		}
		else
		{
			Node<T> * currNode = getNodeAt(idx);
			Node<T> * newNode = new Node<T>(newData);
			
			newNode->prev = currNode;
			newNode->next = currNode->next;
			currNode->next = newNode;
			
			if(currNode == tail) // Adding node after the tail
			{
				// Update tail pointer
				tail = newNode;
			}
			else
			{
				newNode->next->prev = newNode;
			}
			
			length++; 
		}
		
	}
	// ▲▲▲ End of inserAfter ▲▲▲
	
	// ▼▼▼ Method: insertBefore ▼▼▼
	void insertBefore(size_t idx, const T& newData)
	{
		// Validation
		if(idx >= length)
		{
			cerr << "\nIndex out of range.";
		}
		else if(idx == 0) // Insert before head
		{
			Node<T> * currNode = head;
			Node<T> * newNode = new Node<T>(newData);
			
			newNode->prev = nullptr;
			newNode->next = currNode;
			currNode->prev = newNode;
			head = newNode;	
			
			length++; 
		}
		else // Insert in between
		{
			Node<T> * currNode = getNodeAt(idx); 
			Node<T> * newNode = new Node<T>(newData);
			
			newNode->next = currNode;
			newNode->prev = currNode->prev;
			currNode->prev = newNode;
			newNode->prev->next = newNode;
			
			length++; 
		}
		
	}
	// ▲▲▲ End of insertBefore ▲▲▲
	
	// ▼▼▼ Method: deleteNode ▼▼▼
	void deleteNode(size_t idx)
	{
		// Validation
		if(idx >= length)
		{
			cerr << "\nIndex out of range.";
		}
		else if(idx == 0 && length == 1 ) // Only one node in the list, head == tail
		{
			Node<T> * currNode = getNodeAt(idx);
			head = nullptr;
			tail = nullptr;
			delete currNode;
			length--;
		}
		else if(idx == 0) // Delete head 
		{
			Node<T> * currNode = head;
			currNode->next->prev = nullptr;
			head = currNode->next; // Update head to the next node
			delete currNode; 
			length--; 
		}
		else if(idx == (length - 1)) // Delete tail 
		{
			Node<T> * currNode = tail;
			currNode->prev->next = nullptr;
			tail = currNode->prev;
			delete currNode;
			length--; 
		}
		else // Delete in between node
		{
			Node<T> * currNode = getNodeAt(idx);
			currNode->prev->next = currNode->next;
			currNode->next->prev = currNode->prev;
			delete currNode;
			length--; 
		}
	}
	// ▲▲▲ End of deleteNode ▲▲▲
	
	// ▼▼▼ Method: isEmpty ▼▼▼
	bool isEmpty() const
	{
		return length == 0;
	}
	// ▲▲▲ End of isEmpty ▲▲▲
	
	// ▼▼▼ Method: contains ▼▼▼
	bool contains(const T& value) const
	{
		Node<T> * currNode = head;
		while(currNode != nullptr)
		{
			if(currNode->data == value)
			{
				return true;
			}
			currNode = currNode->next;
		}
		return false;
	}
	// ▲▲▲ End of contains ▲▲▲
	
};
// ▲▲▲ End of LinkedList ▲▲▲

/* ==================== Function Prototypes ============== */



/* ==================== Main Application ================= */
int main(void) 
{
    // ----- Initialization ----- //
    system("cls");
    cout << "\nProgram started...\n";
    
    // ----- Testing with Integer Type ----- //
    cout << "\n========== Testing with Integer Type ==========";
	LinkedList<int> intList;
    
    // ----- Original Logic with integers ----- //
	intList.insertLast(10);
	intList.insertLast(20);
	intList.insertLast(30);
	intList.insertLast(40);
	
	intList.inserAfter(1, 25);
	
	size_t length = intList.getLength();
	
	intList.inserAfter(length - 1, 45); // Insert after tail
	
	intList.insertBefore(4, 35);
	
	cout << "\nOriginal integer list:";
	intList.printList();
	
	// ----- Testing Copy Functionality with integers ----- //
	
	// Test 1: Copy constructor
	cout << "\n=== Testing Copy Constructor (int) ===";
	LinkedList<int> copiedIntList1(intList);
	cout << "\nCopied integer list using copy constructor:";
	copiedIntList1.printList();
	
	// Test 2: Clone method
	cout << "\n=== Testing clone Method (int) ===";
	LinkedList<int> copiedIntList2 = intList.clone();
	cout << "\nCloned integer list:";
	copiedIntList2.printList();
	
	// ----- Testing with String Type ----- //
	cout << "\n========== Testing with String Type ==========";
	LinkedList<std::string> stringList;
	
	stringList.insertLast("Hello");
	stringList.insertLast("World");
	stringList.insertLast("C++");
	stringList.insertLast("Templates");
	
	cout << "\nString list:";
	stringList.printList();
	
	stringList.inserAfter(1, "Beautiful");
	stringList.insertBefore(0, "Hi");
	
	cout << "\nString list after insertions:";
	stringList.printList();
	
	cout << "\nString at index 2: " << stringList.getDataAt(2);
	cout << "\nString list length: " << stringList.getLength();
	cout << "\nContains 'C++': " << (stringList.contains("C++") ? "Yes" : "No");
	cout << "\nContains 'Java': " << (stringList.contains("Java") ? "Yes" : "No");
	
	// ----- Testing with Double Type ----- //
	cout << "\n\n========== Testing with Double Type ==========";
	LinkedList<double> doubleList;
	
	doubleList.insertLast(3.14);
	doubleList.insertLast(2.718);
	doubleList.insertLast(1.414);
	doubleList.insertLast(1.732);
	
	cout << "\nDouble list:";
	doubleList.printList();
	
	doubleList.deleteNode(1);
	cout << "\nDouble list after deleting index 1:";
	doubleList.printList();
	
	// ----- Testing with Character Type ----- //
	cout << "\n\n========== Testing with Character Type ==========";
	LinkedList<char> charList;
	
	charList.insertLast('A');
	charList.insertLast('B');
	charList.insertLast('C');
	charList.insertLast('D');
	
	cout << "\nCharacter list:";
	charList.printList();
	
	// Copy character list
	LinkedList<char> copiedCharList = charList.clone();
	cout << "\nCloned character list:";
	copiedCharList.printList();
	
	// Modify original and show independence
	charList.deleteNode(0);
	cout << "\nOriginal character list after deleting first element:";
	charList.printList();
	cout << "\nCloned character list (unchanged):";
	copiedCharList.printList();
	
	// ----- Continue with original integer list operations ----- //
	cout << "\n========== Continuing Integer List Operations ==========";
	
	// Delete head:
	cout << "\nDelete the head of the integer list:";
	intList.deleteNode(0);
	intList.printList();
	
	length = intList.getLength();
	
	// Delete tail:
	cout << "\nDelete the tail of the integer list:";
	intList.deleteNode(length - 1);
	intList.printList();
	
	// Delete in between:
	cout << "\nDelete a node from the integer list:";
	intList.deleteNode(1);
	intList.printList();
	
	int data = intList.getDataAt(1);
	cout << "\nThe Node at index " << 1 << " its data = " << data;
	cout << "\nThe integer linked list length = " << intList.getLength() << '\n';
	
    // ----- End ----- //
    return 0;
}

/* ================== Function/Method Definitions =============== */




/* ======================= End of File =================== */