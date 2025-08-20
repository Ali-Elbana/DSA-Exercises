/*
============================================================
* Project: Binary Tree Implementation
* File:    BinaryTree.cpp
* Author:  [Ali El-bana]
* Date:    [2025-08-20]
* Version: v1.0
------------------------------------------------------------
* Description:
* Template-based binary tree implementation with level-order
* insertion and visual tree printing functionality
------------------------------------------------------------
* Notes:
* - Uses level-order (breadth-first) insertion strategy
* - Includes visual tree representation in console output
* - Template class supports any comparable data type
============================================================
*/

/* ====================== Includes ====================== */
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>

/* =================== Namespace Usage ================== */
using std::cout;
using std::endl;
using std::queue;
using std::vector;
using std::string;
using std::setw;
using std::setfill;

/* ====================== Declarations ================== */
// ▼▼▼ Class: TreeNode ▼▼▼
template <typename Tdata>
class TreeNode;
// ▲▲▲ End of TreeNode ▲▲▲

// ▼▼▼ Class: BinaryTree ▼▼▼
template <typename Tdata>
class BinaryTree;
// ▲▲▲ End of BinaryTree ▲▲▲

/* ===================== Class Definitions =============== */
// ▼▼▼ Class: TreeNode ▼▼▼
template<typename Tdata>
class TreeNode
{
public:
	Tdata Data;
	TreeNode<Tdata> * Left;
	TreeNode<Tdata> * Right;
	
	// Constructor
	TreeNode(Tdata _data) : Data(_data), Left(nullptr), Right(nullptr) {}
};
// ▲▲▲ End of TreeNode ▲▲▲

// ▼▼▼ Class: BinaryTree ▼▼▼
template<typename Tdata>
class BinaryTree
{
	
private:
	TreeNode<Tdata> * root;
	
	// ▼▼▼ Private Helper Methods ▼▼▼
    void destroyTree(TreeNode<Tdata>* node);
    int getHeight(TreeNode<Tdata>* node);
    void printTree(TreeNode<Tdata>* node, string prefix, bool isLast);
    // ▲▲▲ End of Private Helper Methods ▲▲▲
	
public:
	
	// ▼▼▼ Constructor and Destructor ▼▼▼
    BinaryTree();
    ~BinaryTree();
    // ▲▲▲ End of Constructor and Destructor ▲▲▲
    
    // ▼▼▼ Public Methods ▼▼▼
    void Insert(Tdata _data);
    void Print();
    // ▲▲▲ End of Public Methods ▲▲▲

};
// ▲▲▲ End of BinaryTree ▲▲▲

/* ================== Method Definitions =============== */
// ▼▼▼ BinaryTree Constructor Definition ▼▼▼
template<typename Tdata>
BinaryTree<Tdata>::BinaryTree()
{
	root = nullptr;
}
// ▲▲▲ End of BinaryTree Constructor ▲▲▲

// ▼▼▼ BinaryTree Destructor Definition ▼▼▼
template<typename Tdata>
BinaryTree<Tdata>::~BinaryTree()
{
	destroyTree(root);
}
// ▲▲▲ End of BinaryTree Destructor ▲▲▲

// ▼▼▼ destroyTree Definition ▼▼▼
template <typename Tdata>
void BinaryTree<Tdata>::destroyTree(TreeNode<Tdata>* node) 
{
    if(node != nullptr) 
	{
        destroyTree(node->Left);
        destroyTree(node->Right);
        delete node;
    }
}
// ▲▲▲ End of destroyTree ▲▲▲

// ▼▼▼ Insert Definition ▼▼▼
template <typename Tdata>
void BinaryTree<Tdata>::Insert(Tdata _data) 
{
	TreeNode<Tdata> * newNode = new TreeNode<Tdata>(_data);
	
	if(root == nullptr)
	{
		root = newNode;
		return;
	}
	else
	{
		
		queue<TreeNode<Tdata> *> q;
		q.push(root);
		
		while(q.empty() == false)
		{
			TreeNode<Tdata> * currNode = q.front();
			q.pop();
			
			if(currNode->Left == nullptr)
			{
				currNode->Left = newNode;
				break;
			}
			else
			{
				q.push(currNode->Left);
			}
			
			if(currNode->Right == nullptr)
			{
				currNode->Right = newNode;
				break;
			}
			else
			{
				q.push(currNode->Right);
			}
		}
	}
}
// ▲▲▲ End of Insert ▲▲▲

// ▼▼▼ getHeight Definition ▼▼▼
template <typename Tdata>
int BinaryTree<Tdata>::getHeight(TreeNode<Tdata>* node) 
{
    if(node == nullptr) 
	{
        return 0;
    }
    
    int leftHeight = getHeight(node->Left);
    int rightHeight = getHeight(node->Right);
    
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}
// ▲▲▲ End of getHeight ▲▲▲

// ▼▼▼ printTree Definition ▼▼▼
template <typename Tdata>
void BinaryTree<Tdata>::printTree(TreeNode<Tdata>* node, string prefix, bool isLast) 
{
    if(node != nullptr) 
	{
        cout << prefix;
        cout << (isLast ? "|____ " : "|---- ");
        cout << node->Data << endl;
        
        // Count children to determine the connector
        bool hasLeft = (node->Left != nullptr);
        bool hasRight = (node->Right != nullptr);
        
        if(hasLeft || hasRight) 
		{
            if(hasLeft) 
			{
                printTree(node->Left, prefix + (isLast ? "    " : "|   "), !hasRight);
            }
            if(hasRight) 
			{
                printTree(node->Right, prefix + (isLast ? "    " : "|   "), true);
            }
        }
    }
}
// ▲▲▲ End of printTree ▲▲▲

// ▼▼▼ Print Definition ▼▼▼
template <typename Tdata>
void BinaryTree<Tdata>::Print() 
{
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return;
    }
    
    cout << "\n" << string(50, '=') << endl;
    cout << "         BINARY TREE VISUALIZATION" << endl;
    cout << string(50, '=') << endl << endl;
    
    // Simple approach: print using the actual tree structure
    printTree(root, "", false);
    
    cout << endl << string(50, '=') << endl << endl;
}
// ▲▲▲ End of Print ▲▲▲

/* ======================= End of File =================== */

