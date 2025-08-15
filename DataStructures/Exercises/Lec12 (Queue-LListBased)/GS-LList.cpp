/*
============================================================
* Project: [Generic Single Linked List Implementation]
* File:    [GS-LList.cpp]
* Author:  [Ali El-bana]
* Date:    [2025-08-14]
* Version: [v2.0] - Generic template version with enhanced methods
------------------------------------------------------------
* Description:
* [Self implementation of a generic single linked list using templates]
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
	
	// Constructor
	Node(const T& val);
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
	LinkedList();
	
	// Copy Constructor
	LinkedList(const LinkedList<T>& other);
	
	// Copy Assignment Operator
	LinkedList<T>& operator=(const LinkedList<T>& other);
	
	// Destructor
	~LinkedList();
	
	// Method Declarations:
	
	// ▼▼▼ Utility Methods ▼▼▼
	void clear();                              // Clear all nodes from the list
	size_t getLength() const;                  // Get the number of nodes in the list
	bool isEmpty() const;                      // Check if the list is empty
	void printList() const;                    // Print all elements in the list
	// ▲▲▲ End of Utility Methods ▲▲▲
	
	// ▼▼▼ Access Methods ▼▼▼
	T getDataAt(size_t idx) const;             // Get data at specific index
	Node<T> * getNodeAt(size_t idx) const;     // Get node pointer at specific index
	T getFirst() const;                        // Get first element data
	// ▲▲▲ End of Access Methods ▲▲▲
	
	// ▼▼▼ Insertion Methods ▼▼▼
	void insertFirst(const T& val);            // Insert node at the beginning
	void insertLast(const T& val);             // Insert node at the end
	void insertAt(size_t idx, const T& val);   // Insert node at specific index
	// ▲▲▲ End of Insertion Methods ▲▲▲
	
	// ▼▼▼ Deletion Methods ▼▼▼
	bool deleteHead();                         // Delete the first node
	bool deleteTail();                         // Delete the last node
	bool deleteAt(size_t idx);                 // Delete node at specific index
	// ▲▲▲ End of Deletion Methods ▲▲▲
	
	// ▼▼▼ Search Methods ▼▼▼
	bool contains(const T& value) const;       // Check if value exists in the list
	int indexOf(const T& value) const;         // Find index of first occurrence of value
	// ▲▲▲ End of Search Methods ▲▲▲
	
	// ▼▼▼ Copy Methods ▼▼▼
	void copyFrom(const LinkedList<T>& other); // Copy from another list
	LinkedList<T> clone() const;               // Create an independent copy of the list
	// ▲▲▲ End of Copy Methods ▲▲▲
	
};
// ▲▲▲ End of LinkedList ▲▲▲

/* ==================== Function Prototypes ============== */

/* ==================== Main Application ================= */
/*
int main(void) 
{
    // ----- Initialization ----- //
    system("cls");
    cout << "\nProgram started...\n";
    
    // ----- Testing with Integer Type ----- //
    cout << "\n========== Testing with Integer Type ==========";
    LinkedList<int> intList;
    
    // ----- Original Logic with integers ----- //
    intList.insertLast(1);
    intList.insertLast(2);
    intList.insertLast(3);
    intList.insertLast(4);
    intList.printList();
    
    size_t length = intList.getLength();
    int data = intList.getDataAt(3);
    cout << "\nThe Node at index " << 3 << " its data = " << data;
    cout << "\nThe linked list length = " << length << '\n';
    
    // ----- Testing new methods ----- //
    cout << "\n=== Testing insertFirst method ===";
    intList.insertFirst(0);
    cout << "\nAfter inserting 0 at the beginning:";
    intList.printList();
    
    cout << "\n=== Testing deleteHead method ===";
    intList.deleteHead();
    cout << "\nAfter deleting head:";
    intList.printList();
    
    cout << "\n=== Testing insertAt method ===";
    intList.insertAt(2, 25);
    cout << "\nAfter inserting 25 at index 2:";
    intList.printList();
    
    cout << "\n=== Testing deleteAt method ===";
    intList.deleteAt(1);
    cout << "\nAfter deleting node at index 1:";
    intList.printList();
    
    // ----- Testing with String Type ----- //
    cout << "\n\n========== Testing with String Type ==========";
    LinkedList<std::string> stringList;
    
    stringList.insertLast("World");
    stringList.insertLast("C++");
    stringList.insertFirst("Hello");
    stringList.insertAt(2, "Amazing");
    
    cout << "\nString list:";
    stringList.printList();
    
    cout << "\nIndex of 'C++': " << stringList.indexOf("C++");
    cout << "\nContains 'Hello': " << (stringList.contains("Hello") ? "Yes" : "No");
    cout << "\nContains 'Java': " << (stringList.contains("Java") ? "Yes" : "No");
    
    // ----- Testing with Double Type ----- //
    cout << "\n\n========== Testing with Double Type ==========";
    LinkedList<double> doubleList;
    
    doubleList.insertFirst(3.14);
    doubleList.insertLast(2.718);
    doubleList.insertLast(1.414);
    doubleList.insertFirst(1.732);
    
    cout << "\nDouble list:";
    doubleList.printList();
    
    doubleList.deleteHead();
    cout << "\nAfter deleting head:";
    doubleList.printList();
    
    doubleList.deleteTail();
    cout << "\nAfter deleting tail:";
    doubleList.printList();
    
    // ----- Testing Copy Functionality ----- //
    cout << "\n\n========== Testing Copy Functionality ==========";
    
    // Test clone method
    LinkedList<double> clonedList = doubleList.clone();
    cout << "\nOriginal double list:";
    doubleList.printList();
    cout << "\nCloned double list:";
    clonedList.printList();
    
    // Modify original to test independence
    doubleList.insertFirst(99.99);
    cout << "\nAfter modifying original (added 99.99):";
    cout << "\nOriginal:";
    doubleList.printList();
    cout << "\nCloned (should be unchanged):";
    clonedList.printList();
    
    // ----- Testing with Character Type ----- //
    cout << "\n\n========== Testing with Character Type ==========";
    LinkedList<char> charList;
    
    charList.insertLast('B');
    charList.insertLast('C');
    charList.insertFirst('A');
    charList.insertLast('D');
    
    cout << "\nCharacter list:";
    charList.printList();
    
    cout << "\nIs list empty? " << (charList.isEmpty() ? "Yes" : "No");
    cout << "\nList length: " << charList.getLength();
    
    // Clear the list
    charList.clear();
    cout << "\nAfter clearing the list:";
    charList.printList();
    cout << "\nIs list empty now? " << (charList.isEmpty() ? "Yes" : "No");
    
    // ----- End ----- //
    return 0;
}
*/
/* ================== Function/Method Definitions =============== */

// ▼▼▼ Node Constructor ▼▼▼
template<typename T>
Node<T>::Node(const T& val) : data(val), next(nullptr)
{
}
// ▲▲▲ End of Node Constructor ▲▲▲

// ▼▼▼ LinkedList Constructor ▼▼▼
template<typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), length(0)
{
}
// ▲▲▲ End of LinkedList Constructor ▲▲▲

// ▼▼▼ LinkedList Copy Constructor ▼▼▼
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) : head(nullptr), tail(nullptr), length(0)
{
	Node<T> * currNode = other.head;
	while(currNode != nullptr)
	{
		insertLast(currNode->data);
		currNode = currNode->next;
	}
}
// ▲▲▲ End of LinkedList Copy Constructor ▲▲▲

// ▼▼▼ LinkedList Copy Assignment Operator ▼▼▼
template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
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
// ▲▲▲ End of LinkedList Copy Assignment Operator ▲▲▲

// ▼▼▼ LinkedList Destructor ▼▼▼
template<typename T>
LinkedList<T>::~LinkedList()
{
	clear();
}
// ▲▲▲ End of LinkedList Destructor ▲▲▲

// ▼▼▼ Method: clear ▼▼▼
template<typename T>
void LinkedList<T>::clear()
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

// ▼▼▼ Method: getDataAt ▼▼▼
template<typename T>
T LinkedList<T>::getDataAt(size_t idx) const
{
	Node<T> * currNode = head;
	
	// Validation
	if(idx >= length)
	{
		cerr << "\nIndex out of range.";
		return T(); // Return default constructed value
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
	
	return currNode->data;
}
// ▲▲▲ End of getDataAt ▲▲▲

// ▼▼▼ Method: getNodeAt ▼▼▼
template<typename T>
Node<T> * LinkedList<T>::getNodeAt(size_t idx) const
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

// ▼▼▼ Method: getFirst ▼▼▼
template<typename T>
T LinkedList<T>::getFirst() const
{
	if(head == nullptr)
	{
		cout << "\nList is empty.";
		return T();
	}
	
	return head->data;
}
// ▲▲▲ End of getFirst ▲▲▲

// ▼▼▼ Method: insertFirst ▼▼▼
template<typename T>
void LinkedList<T>::insertFirst(const T& val)
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
		newNode->next = head;
		head = newNode;
	}
	
	// Update the list length
	length++;
}
// ▲▲▲ End of insertFirst ▲▲▲

// ▼▼▼ Method: insertLast ▼▼▼
template<typename T>
void LinkedList<T>::insertLast(const T& val)
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
		tail->next = newNode;
		newNode->next = nullptr;
		tail = newNode;
	}
	
	// Update the list length
	length++; 
}
// ▲▲▲ End of insertLast ▲▲▲

// ▼▼▼ Method: insertAt ▼▼▼
template<typename T>
void LinkedList<T>::insertAt(size_t idx, const T& val)
{
	// Validation
	if(idx > length)
	{
		cerr << "\nIndex out of range.";
		return;
	}
	
	if(idx == 0) // Insert at beginning
	{
		insertFirst(val);
	}
	else if(idx == length) // Insert at end
	{
		insertLast(val);
	}
	else // Insert in middle
	{
		Node<T> * newNode = new Node<T>(val);
		Node<T> * prevNode = getNodeAt(idx - 1);
		
		newNode->next = prevNode->next;
		prevNode->next = newNode;
		
		length++;
	}
}
// ▲▲▲ End of insertAt ▲▲▲

// ▼▼▼ Method: deleteHead ▼▼▼
template<typename T>
bool LinkedList<T>::deleteHead()
{
	// Validation
	if(head == nullptr)
	{
		cerr << "\nList is empty, cannot delete head.";
		return false;
	}
	
	Node<T> * nodeToDelete = head;
	
	if(head == tail) // Only one node in the list
	{
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		head = head->next;
	}
	
	delete nodeToDelete;
	length--;
	return true;
}
// ▲▲▲ End of deleteHead ▲▲▲

// ▼▼▼ Method: deleteTail ▼▼▼
template<typename T>
bool LinkedList<T>::deleteTail()
{
	// Validation
	if(head == nullptr)
	{
		cerr << "\nList is empty, cannot delete tail.";
		return false;
	}
	
	if(head == tail) // Only one node in the list
	{
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		// Find the node before tail
		Node<T> * currNode = head;
		while(currNode->next != tail)
		{
			currNode = currNode->next;
		}
		
		delete tail;
		tail = currNode;
		tail->next = nullptr;
	}
	
	length--;
	return true;
}
// ▲▲▲ End of deleteTail ▲▲▲

// ▼▼▼ Method: deleteAt ▼▼▼
template<typename T>
bool LinkedList<T>::deleteAt(size_t idx)
{
	// Validation
	if(idx >= length)
	{
		cerr << "\nIndex out of range.";
		return false;
	}
	
	if(idx == 0) // Delete head
	{
		return deleteHead();
	}
	else if(idx == length - 1) // Delete tail
	{
		return deleteTail();
	}
	else // Delete in middle
	{
		Node<T> * prevNode = getNodeAt(idx - 1);
		Node<T> * nodeToDelete = prevNode->next;
		
		prevNode->next = nodeToDelete->next;
		delete nodeToDelete;
		length--;
		return true;
	}
}
// ▲▲▲ End of deleteAt ▲▲▲

// ▼▼▼ Method: printList ▼▼▼
template<typename T>
void LinkedList<T>::printList() const
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
template<typename T>
size_t LinkedList<T>::getLength() const
{
	return length;
}
// ▲▲▲ End of getLength ▲▲▲

// ▼▼▼ Method: isEmpty ▼▼▼
template<typename T>
bool LinkedList<T>::isEmpty() const
{
	return length == 0;
}
// ▲▲▲ End of isEmpty ▲▲▲

// ▼▼▼ Method: contains ▼▼▼
template<typename T>
bool LinkedList<T>::contains(const T& value) const
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

// ▼▼▼ Method: indexOf ▼▼▼
template<typename T>
int LinkedList<T>::indexOf(const T& value) const
{
	Node<T> * currNode = head;
	size_t index = 0;
	
	while(currNode != nullptr)
	{
		if(currNode->data == value)
		{
			return static_cast<int>(index);
		}
		currNode = currNode->next;
		index++;
	}
	
	return -1; // Not found
}
// ▲▲▲ End of indexOf ▲▲▲

// ▼▼▼ Method: copyFrom ▼▼▼
template<typename T>
void LinkedList<T>::copyFrom(const LinkedList<T>& other)
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
template<typename T>
LinkedList<T> LinkedList<T>::clone() const
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

/* ======================= End of File =================== */