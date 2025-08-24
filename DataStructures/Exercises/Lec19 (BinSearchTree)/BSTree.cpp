/*
============================================================
* Project: Binary Search Tree Implementation
* File:    BSTree.cpp
* Author:  [Ali El-bana]
* Date:    [2025-08-24]
* Version: v1.0
------------------------------------------------------------
* Description:
* Template-based binary search tree implementation with level-order
* insertion, find and visual tree printing functionality
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
	void preOrderHelper(TreeNode<Tdata>* node);
    void inOrderHelper(TreeNode<Tdata>* node);
    void postOrderHelper(TreeNode<Tdata>* node);
	TreeNode<Tdata>* findHelper(TreeNode<Tdata>* node, const Tdata & _data);
    TreeNode<Tdata>* findDeepestRightmost(TreeNode<Tdata>* node);
    void deleteNodeHelper(TreeNode<Tdata>*& root, Tdata _data);
    // ▲▲▲ End of Private Helper Methods ▲▲▲
	
public:
	
	// ▼▼▼ Constructor and Destructor ▼▼▼
    BinaryTree();
    ~BinaryTree();
    // ▲▲▲ End of Constructor and Destructor ▲▲▲
    
    // ▼▼▼ Public Methods ▼▼▼
    void Insert(Tdata _data);
    void Print();
	void preOrder();
    void inOrder();
    void postOrder();
	TreeNode<Tdata>* find(const Tdata & _data);
    void deleteNode(Tdata _data);
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
		
		TreeNode<Tdata> * currNode = root;
		
		while(currNode != nullptr)
		{
			if(_data < currNode->Data)
			{
				if(currNode->Left == nullptr)
				{
					currNode->Left = newNode;
					break;
				}
				else
				{
					currNode = currNode->Left;
				}
			}
			else // if(_data >= currNode->data)
			{
				if(currNode->Right == nullptr)
				{
					currNode->Right = newNode;
					break;
				}
				else
				{
					currNode = currNode->Right;
				}
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

        // Count children
        bool hasLeft = (node->Left != nullptr);
        bool hasRight = (node->Right != nullptr);

        if(hasLeft == true || hasRight == true) 
        {
            // Print RIGHT child first (so it appears on the right side visually)
            if(hasRight == true) 
            {
                printTree(node->Right, prefix + (isLast ? "    " : "|   "), !hasLeft);
            }
            // Then print LEFT child
            if(hasLeft == true) 
            {
                printTree(node->Left, prefix + (isLast ? "    " : "|   "), true);
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

// ▼▼▼ preOrderHelper Definition ▼▼▼
template <typename Tdata>
void BinaryTree<Tdata>::preOrderHelper(TreeNode<Tdata>* node)
{
    if(node != nullptr)
    {
        cout << node->Data << " ";
        preOrderHelper(node->Left);
        preOrderHelper(node->Right);
    }
}
// ▲▲▲ End of preOrderHelper ▲▲▲

// ▼▼▼ preOrder Definition ▼▼▼
template <typename Tdata>
void BinaryTree<Tdata>::preOrder()
{
    if(root == nullptr)
    {
        cout << "Tree is empty!" << endl;
        return;
    }
    
    cout << "\nPre-Order Traversal (Root -> Left -> Right): ";
    preOrderHelper(root);
    cout << endl;
}
// ▲▲▲ End of preOrder ▲▲▲

// ▼▼▼ inOrderHelper Definition ▼▼▼
template <typename Tdata>
void BinaryTree<Tdata>::inOrderHelper(TreeNode<Tdata>* node)
{
    if(node != nullptr)
    {
        inOrderHelper(node->Left);
        cout << node->Data << " ";
        inOrderHelper(node->Right);
    }
}
// ▲▲▲ End of inOrderHelper ▲▲▲

// ▼▼▼ inOrder Definition ▼▼▼
template <typename Tdata>
void BinaryTree<Tdata>::inOrder()
{
    if(root == nullptr)
    {
        cout << "Tree is empty!" << endl;
        return;
    }
    
    cout << "\nIn-Order Traversal (Left -> Root -> Right): ";
    inOrderHelper(root);
    cout << endl;
}
// ▲▲▲ End of inOrder ▲▲▲

// ▼▼▼ postOrderHelper Definition ▼▼▼
template <typename Tdata>
void BinaryTree<Tdata>::postOrderHelper(TreeNode<Tdata>* node)
{
    if(node != nullptr)
    {
        postOrderHelper(node->Left);
        postOrderHelper(node->Right);
        cout << node->Data << " ";
    }
}
// ▲▲▲ End of postOrderHelper ▲▲▲

// ▼▼▼ postOrder Definition ▼▼▼
template <typename Tdata>
void BinaryTree<Tdata>::postOrder()
{
    if(root == nullptr)
    {
        cout << "Tree is empty!" << endl;
        return;
    }
    
    cout << "\nPost-Order Traversal (Left -> Right -> Root): ";
    postOrderHelper(root);
    cout << endl;
}
// ▲▲▲ End of postOrder ▲▲▲

// ▼▼▼ findHelper Definition ▼▼▼
template <typename Tdata>
TreeNode<Tdata>* BinaryTree<Tdata>::findHelper(TreeNode<Tdata>* node, const Tdata& _data)
{
    if(node == nullptr)
    {
        return nullptr; // not found
    }

    if(node->Data == _data)
    {
        return node; // found
    }

    if(_data < node->Data)
    {
        // Search in the left subtree
        return findHelper(node->Left, _data);
    }
    else
    {
        // Search in the right subtree
        return findHelper(node->Right, _data);
    }
}
// ▲▲▲ End of findHelper ▲▲▲

// ▼▼▼ find Definition ▼▼▼
template <typename Tdata>
TreeNode<Tdata>* BinaryTree<Tdata>::find(const Tdata& _data)
{
    if(root == nullptr)
    {
        cout << "Tree is empty!" << endl;
        return nullptr;
    }

    TreeNode<Tdata>* result = findHelper(root, _data);

    if(result != nullptr)
    {
        cout << "Element " << _data << " found in the tree." << endl;
    }
    else
    {
        cout << "Element " << _data << " not found in the tree." << endl;
    }

    return result;
}
// ▲▲▲ End of find ▲▲▲

// ▼▼▼ findDeepestRightmost Definition ▼▼▼
template <typename Tdata>
TreeNode<Tdata>* BinaryTree<Tdata>::findDeepestRightmost(TreeNode<Tdata>* node)
{
    if(node == nullptr)
    {
        return nullptr;
    }
    
    queue<TreeNode<Tdata>*> q;
    q.push(node);
    TreeNode<Tdata>* deepest = nullptr;
    
    // Level order traversal to find the deepest rightmost node
    while(!q.empty())
    {
        deepest = q.front();
        q.pop();
        
        if(deepest->Left != nullptr)
        {
            q.push(deepest->Left);
        }
        
        if(deepest->Right != nullptr)
        {
            q.push(deepest->Right);
        }
    }
    
    return deepest;
}
// ▲▲▲ End of findDeepestRightmost ▲▲▲

// ▼▼▼ deleteNodeHelper Definition ▼▼▼
template <typename Tdata>
void BinaryTree<Tdata>::deleteNodeHelper(TreeNode<Tdata>*& root, Tdata _data)
{
    if(root == nullptr)
    {
        return;
    }
    
    // If only one node exists and it's the target
    if(root->Left == nullptr && root->Right == nullptr)
    {
        if(root->Data == _data)
        {
            delete root;
            root = nullptr;
        }
        return;
    }
    
    // Find the node to delete using level order traversal
    queue<TreeNode<Tdata>*> q;
    q.push(root);
    TreeNode<Tdata>* nodeToDelete = nullptr;
    TreeNode<Tdata>* lastNode = nullptr;
    
    // Find the target node and keep track of all nodes (lastNode will be the deepest rightmost)
    while(!q.empty())
    {
        lastNode = q.front();
        q.pop();
        
        if(lastNode->Data == _data)
        {
            nodeToDelete = lastNode;
        }
        
        if(lastNode->Left != nullptr)
        {
            q.push(lastNode->Left);
        }
        
        if(lastNode->Right != nullptr)
        {
            q.push(lastNode->Right);
        }
    }
    
    if(nodeToDelete == nullptr)
    {
        return; // Node not found
    }
    
    // Replace the data of nodeToDelete with the deepest rightmost node's data
    nodeToDelete->Data = lastNode->Data;
    
    // Now we need to delete the lastNode (deepest rightmost)
    // Find parent of lastNode using another level order traversal
    queue<TreeNode<Tdata>*> q2;
    q2.push(root);
    
    while(!q2.empty())
    {
        TreeNode<Tdata>* current = q2.front();
        q2.pop();
        
        // Check if current node is parent of lastNode
        if(current->Left == lastNode)
        {
            current->Left = nullptr;
            delete lastNode;
            return;
        }
        
        if(current->Right == lastNode)
        {
            current->Right = nullptr;
            delete lastNode;
            return;
        }
        
        if(current->Left != nullptr)
        {
            q2.push(current->Left);
        }
        
        if(current->Right != nullptr)
        {
            q2.push(current->Right);
        }
    }
    
}
// ▲▲▲ End of deleteNodeHelper ▲▲▲

// ▼▼▼ deleteNode Definition ▼▼▼
template <typename Tdata>
void BinaryTree<Tdata>::deleteNode(Tdata _data)
{
    if(root == nullptr)
    {
        cout << "Tree is empty! Cannot delete element " << _data << endl;
        return;
    }
    
    // Check if element exists first
    if(!findHelper(root, _data))
    {
        cout << "Element " << _data << " not found in the tree. Cannot delete." << endl;
        return;
    }
    
    deleteNodeHelper(root, _data);
    cout << "Element " << _data << " deleted from the tree." << endl;
}
// ▲▲▲ End of deleteNode ▲▲▲


/* ======================= End of File =================== */

