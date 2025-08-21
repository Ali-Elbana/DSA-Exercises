/*
============================================================
* Project: Binary Tree Implementation
* File:    main.cpp
* Author:  [Ali El-bana]
* Date:    [2025-08-20]
* Version: v1.0
------------------------------------------------------------
* Description:
* Main application to demonstrate binary tree functionality
* with visual tree representation
------------------------------------------------------------
* Notes:
* - Demonstrates insertion and printing of binary tree
* - Uses template-based implementation for flexibility
============================================================
*/

/* ====================== Includes ====================== */
#include "BinaryTree.cpp"
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
    cout << "Binary Tree Demonstration Program" << endl;
    cout << "=================================" << endl;
    
    // ----- Create and populate binary tree -----
    BinaryTree<char> tree_char;
    
    cout << "\nInserting elements: A, B, C, D, E, F, G, H, I" << endl;
    
    tree_char.Insert('A');
    tree_char.Insert('B');
    tree_char.Insert('C');
    tree_char.Insert('D');
    tree_char.Insert('E');
    tree_char.Insert('F');
    tree_char.Insert('G');
    tree_char.Insert('H');
    tree_char.Insert('I');
    
    // ----- Display the tree -----
    cout << "\nTree structure:" << endl;
    tree_char.Print();
	
	// ----- Traverse in different orders -----
    tree_char.preOrder();
	tree_char.inOrder();
	tree_char.postOrder();
	
	// ----- Find node in the tree -----
	tree_char.find('I');
	tree_char.find('J');
	
	// ----- Find node from the tree -----
	tree_char.deleteNode('D');
	tree_char.deleteNode('K');
	
	// ----- Display the tree after deletion -----
    cout << "\nTree structure:" << endl;
    tree_char.Print();
	
    // ----- End -----
    cout << "Program completed successfully!" << endl;
    return 0;
}

/* ======================= End of File =================== */