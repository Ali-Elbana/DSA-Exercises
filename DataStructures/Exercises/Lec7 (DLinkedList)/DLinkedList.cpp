/*
============================================================
* Project: [Double Linked List Implemnetation]
* File:    [DLinkedList.cpp]
* Author:  [Ali El-bana]
* Date:    [2025-08-13]
* Version: [v1.0]
------------------------------------------------------------
* Description:
* [Self implementation of a double linked list]
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
// ▼▼▼ Class: Node ▼▼▼
class Node;
// ▲▲▲ End of Node ▲▲▲

// ▼▼▼ Class: LinkedList ▼▼▼
class LinkedList;
// ▲▲▲ End of LinkedList ▲▲▲



/* ===================== Class Definitions =============== */
// ▼▼▼ Class: Node ▼▼▼
class Node
{
public:
	int data;
	Node * next;
	Node * prev;
	// Constructor
	Node(int val) : data(val), next(nullptr), prev(nullptr){}
};
// ▲▲▲ End of Node ▲▲▲

// ▼▼▼ Class: LinkedList ▼▼▼
class LinkedList
{
private:
	Node * head;
	Node * tail;
	size_t length;
	
public:
	// Constructor
	LinkedList(): head(nullptr), tail(nullptr), length(0){}
	
	// Destructor
	~LinkedList()
	{
		while(head != nullptr)
		{
			Node * tmp = head;
			head = tmp->next;
			delete tmp;
		}
	}
	
	// Methods:
	// ▼▼▼ Method: getDataAt ▼▼▼
	int getDataAt(size_t idx)
	{
		Node * currNode = head;
		
		// Validation
		if(idx >= length)
		{
			cout << "\nIndex out of range.";
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
	Node * getNodeAt(size_t idx)
	{
		Node * currNode = head;
		
		// Validation
		if(idx >= length)
		{
			cerr << "\nIndex out of range.";
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
	void insertLast(int val)
	{
		Node * newNode = new Node(val);
		
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
	void printList()
	{
		Node * currNode = head;
		
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
	size_t getLength(void)
	{
		return length;
	}
	// ▲▲▲ End of getLength ▲▲▲
	
	// ▼▼▼ Method: inserAfter ▼▼▼
	void inserAfter(size_t idx, int newData)
	{
		// Validation
		if(idx >= length)
		{
			cerr << "\nIndex out of range.";
		}
		else
		{
			Node * currNode = getNodeAt(idx);
			Node * newNode = new Node(newData);
			
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
	void insertBefore(size_t idx, int newData)
	{
		// Validation
		if(idx >= length)
		{
			cerr << "\nIndex out of range.";
		}
		else if(idx == 0) // Insert before head
		{
			Node * currNode = head;
			Node * newNode = new Node(newData);
			
			newNode->prev = nullptr;
			newNode->next = currNode;
			currNode->prev = newNode;
			head = newNode;	
			
			length++; 
		}
		else // Insert in between
		{
			Node * currNode = getNodeAt(idx); 
			Node * newNode = new Node(newData);
			
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
			Node * currNode = getNodeAt(idx);
			head = nullptr;
			tail = nullptr;
			delete currNode;
			length--;
		}
		else if(idx == 0) // Delete head 
		{
			Node * currNode = head;
			currNode->next->prev = nullptr;
			head = currNode->next; // Update head to the next node
			delete currNode; 
			length--; 
		}
		else if(idx == (length - 1)) // Delete tail 
		{
			Node * currNode = tail;
			currNode->prev->next = nullptr;
			tail = currNode->prev;
			delete currNode;
			length--; 
		}
		else // Delete in between node
		{
			Node * currNode = getNodeAt(idx);
			currNode->prev->next = currNode->next;
			currNode->next->prev = currNode->prev;
			delete currNode;
			length--; 
		}
	}
	// ▲▲▲ End of deleteNode ▲▲▲
	
};
// ▲▲▲ End of LinkedList ▲▲▲

/* ==================== Function Prototypes ============== */



/* ==================== Main Application ================= */
int main(void) 
{
    // ----- Initialization ----- //
    system("cls");
    cout << "\nProgram started...\n";
	LinkedList list;
    
    // ----- Logic ----- //
	list.insertLast(10);
	list.insertLast(20);
	list.insertLast(30);
	list.insertLast(40);
	
	list.inserAfter(1, 25);
	
	size_t length = list.getLength();
	
	list.inserAfter(length - 1, 45); // Insert after tail
	
	list.insertBefore(4, 35);
	
	list.printList();
	
	// Delete head:
	cout << "\nDelete the head of the list:";
	list.deleteNode(0);
	list.printList();
	
	length = list.getLength();
	
	// Delete tail:
	cout << "\nDelete the tail of the list:";
	list.deleteNode(length - 1);
	list.printList();
	
	// Delete in between:
	cout << "\nDelete a node from the list:";
	list.deleteNode(1);
	list.printList();
	
	int data = list.getDataAt(1);
	cout << "\nThe Node at index " << 1 << " its data = " << data;
	cout << "\nThe linked list length = " << list.getLength() << '\n';
	
    // ----- End ----- //
    return 0;
}

/* ================== Function/Method Definitions =============== */




/* ======================= End of File =================== */
