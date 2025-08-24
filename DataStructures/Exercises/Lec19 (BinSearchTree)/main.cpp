/*
============================================================
* Project: Binary Search Tree Implementation
* File:    main.cpp
* Author:  [Ali El-bana]
* Date:    [2025-08-24]
* Version: v1.0
------------------------------------------------------------
* Description:
* Main application to demonstrate binary search tree functionality
* with visual tree representation
------------------------------------------------------------
* Notes:
* - Demonstrates insertion and printing of binary search tree
* - Uses template-based implementation for flexibility
============================================================
*/

/* ====================== Includes ====================== */
#include "BSTree.cpp"
#include <iostream>

/* =================== Namespace Usage ================== */
using std::cout;
using std::endl;

/* ==================== Main Application ================= */
int main()
{
    // ----- Initialization -----
    system("cls"); // Clear console (Windows)
    // system("clear"); // Uncomment for Linux/Mac
    cout << "Binary Search Tree Demonstration Program" << endl;
    cout << "=================================" << endl;

    // ----- Create and populate binary search tree -----
    BinaryTree<int> tree_int;

    cout << "\nInserting elements: 4, 2, 1, 3, 5, 6" << endl;

    tree_int.Insert(4);
    tree_int.Insert(2);
    tree_int.Insert(1);
    tree_int.Insert(3);
    tree_int.Insert(5);
    tree_int.Insert(6);


    // ----- Display the tree -----
    cout << "\nTree structure:" << endl;
    tree_int.Print();

	// ----- Find node in the tree -----
	tree_int.find(3);
	tree_int.find(7);


	/*
	// ----- Traverse in different orders -----
    tree_int.preOrder();
	tree_int.inOrder();
	tree_int.postOrder();

	// ----- Find node from the tree -----
	tree_int.deleteNode('D');
	tree_int.deleteNode('K');

	// ----- Display the tree after deletion -----
    cout << "\nTree structure:" << endl;
    tree_int.Print();
	*/

    // ----- End -----
    cout << "Program completed successfully!" << endl;
    return 0;
}

/* ======================= End of File =================== */