/*
============================================================
* Project: [Single Linked List Implemnetation]
* File:    [SLinkedList.cpp]
* Author:  [Ali El-bana]
* Date:    [2025-08-11]
* Version: [v1.1]
------------------------------------------------------------
* Description:
* [Self implementation of a single linked list]
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
	
	// Constructor
	Node(int val) : data(val), next(nullptr){}
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
	
	// Methods
	int getDataAt(size_t idx)
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
		
		return currNode->data;
	}
	
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
			tail->next = newNode;
			newNode->next = nullptr;
			tail = newNode;
		}
		
		// Update the list length
		length++; 
	}
	
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
	
	size_t getLength(void)
	{
		return length;
	}
	
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
	list.insertLast(1);
	list.insertLast(2);
	list.insertLast(3);
	list.insertLast(4);
	list.printList();
	
	size_t length = list.getLength();
	int data = list.getDataAt(3);
	cout << "\nThe Node at index " << 3 << " its data = " << data;
	cout << "\nThe linked list length = " << length << '\n';
	
    // ----- End ----- //
    return 0;
}

/* ================== Function/Method Definitions =============== */




/* ======================= End of File =================== */
