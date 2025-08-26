/*
============================================================
* Project: Binary Search Tree Implementation with Parent Pointers
* File:    BSTree.cpp
* Author:  [Ali El-bana]
* Date:    [2025-08-25]
* Version: v2.0
------------------------------------------------------------
* Description:
* Template-based binary search tree implementation with parent pointers
* for simplified deletion and enhanced tree operations
------------------------------------------------------------
* Notes:
* - Uses parent pointers for easier tree manipulation
* - Simple recursive deletion algorithm
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
// ▼▼▼ Class: TreeNode (Enhanced with Parent Pointer) ▼▼▼
template<typename Tdata>
class TreeNode
{
public:
	Tdata Data;
	TreeNode<Tdata> * Left;
	TreeNode<Tdata> * Right;
	TreeNode<Tdata> * Parent;  // Parent pointer for easier manipulation
	
	// Constructor
	TreeNode(Tdata _data) : Data(_data), Left(nullptr), Right(nullptr), Parent(nullptr) {}
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
    TreeNode<Tdata>* findMin(TreeNode<Tdata>* node);
    void deleteNodeHelper(TreeNode<Tdata>* nodeToDelete);
    void collectInOrder(TreeNode<Tdata>* node, vector<Tdata>& sortedData);
	TreeNode<Tdata>* buildBalancedTree(vector<Tdata>& sortedData, int start, int end, TreeNode<Tdata>* parent);
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
	void balance();
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

// ▼▼▼ Insert Definition (Enhanced with Parent Pointer) ▼▼▼
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
		TreeNode<Tdata> * parentNode = nullptr;
		
		while(currNode != nullptr)
		{
			parentNode = currNode;  // Keep track of parent
			
			if(_data < currNode->Data)
			{
				currNode = currNode->Left;
			}
			else // if(_data >= currNode->data)
			{
				currNode = currNode->Right;
			}
		}
		
		// Set parent for new node
		newNode->Parent = parentNode;
		
		// Insert as left or right child
		if(_data < parentNode->Data)
		{
			parentNode->Left = newNode;
		}
		else
		{
			parentNode->Right = newNode;
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

// ▼▼▼ findMin Definition ▼▼▼
template <typename Tdata>
TreeNode<Tdata>* BinaryTree<Tdata>::findMin(TreeNode<Tdata>* node)
{
    while(node != nullptr && node->Left != nullptr)
    {
        node = node->Left;
    }
    return node;
}
// ▲▲▲ End of findMin ▲▲▲

// ▼▼▼ SIMPLE deleteNodeHelper with Parent Pointers ▼▼▼
template <typename Tdata>
void BinaryTree<Tdata>::deleteNodeHelper(TreeNode<Tdata>* nodeToDelete)
{
    if(nodeToDelete == nullptr)
    {
        return;
    }
    
    // Case 1: Node has no children (leaf node)
    if(nodeToDelete->Left == nullptr && nodeToDelete->Right == nullptr)
    {
        // Simply disconnect from parent
        if(nodeToDelete->Parent == nullptr)
        {
            // This is the root node
            root = nullptr;
        }
        else if(nodeToDelete->Parent->Left == nodeToDelete)
        {
            // This node is left child of its parent
            nodeToDelete->Parent->Left = nullptr;
        }
        else
        {
            // This node is right child of its parent
            nodeToDelete->Parent->Right = nullptr;
        }
        
        delete nodeToDelete;
    }
    
    // Case 2: Node has only right child
    else if(nodeToDelete->Left == nullptr)
    {
        TreeNode<Tdata>* rightChild = nodeToDelete->Right;
        
        // Connect right child to nodeToDelete's parent
        if(nodeToDelete->Parent == nullptr)
        {
            // nodeToDelete is root
            root = rightChild;
            rightChild->Parent = nullptr;
        }
        else if(nodeToDelete->Parent->Left == nodeToDelete)
        {
            // nodeToDelete is left child
            nodeToDelete->Parent->Left = rightChild;
            rightChild->Parent = nodeToDelete->Parent;
        }
        else
        {
            // nodeToDelete is right child
            nodeToDelete->Parent->Right = rightChild;
            rightChild->Parent = nodeToDelete->Parent;
        }
        
        delete nodeToDelete;
    }
    
    // Case 3: Node has only left child
    else if(nodeToDelete->Right == nullptr)
    {
        TreeNode<Tdata>* leftChild = nodeToDelete->Left;
        
        // Connect left child to nodeToDelete's parent
        if(nodeToDelete->Parent == nullptr)
        {
            // nodeToDelete is root
            root = leftChild;
            leftChild->Parent = nullptr;
        }
        else if(nodeToDelete->Parent->Left == nodeToDelete)
        {
            // nodeToDelete is left child
            nodeToDelete->Parent->Left = leftChild;
            leftChild->Parent = nodeToDelete->Parent;
        }
        else
        {
            // nodeToDelete is right child
            nodeToDelete->Parent->Right = leftChild;
            leftChild->Parent = nodeToDelete->Parent;
        }
        
        delete nodeToDelete;
    }
    
    // Case 4: Node has both children
    else
    {
        // Find the inorder successor (smallest in right subtree)
        TreeNode<Tdata>* successor = findMin(nodeToDelete->Right);
        
        // Copy successor's data to nodeToDelete
        nodeToDelete->Data = successor->Data;
        
        // Now delete the successor (recursive call)
        // This will only be Case 1 or Case 2, never Case 4 again!
        deleteNodeHelper(successor);
    }
}
// ▲▲▲ End of deleteNodeHelper ▲▲▲

// ▼▼▼ Simple deleteNode Method ▼▼▼
template <typename Tdata>
void BinaryTree<Tdata>::deleteNode(Tdata _data)
{
    if(root == nullptr)
    {
        cout << "Tree is empty! Cannot delete element " << _data << endl;
        return;
    }
    
    // Find the node to delete using existing find method
    TreeNode<Tdata>* nodeToDelete = find(_data);
    if(nodeToDelete == nullptr)
    {
        // find method already prints "not found" message
        return;
    }
    
    // Use the simple helper method
    deleteNodeHelper(nodeToDelete);
    cout << "Element " << _data << " deleted from the tree." << endl;
}
// ▲▲▲ End of deleteNode ▲▲▲

// ▼▼▼ collectInOrder Definition ▼▼▼
template <typename Tdata>
void BinaryTree<Tdata>::collectInOrder(TreeNode<Tdata>* node, vector<Tdata>& sortedData)
{
    if(node != nullptr)
    {
        collectInOrder(node->Left, sortedData);
        sortedData.push_back(node->Data);
        collectInOrder(node->Right, sortedData);
    }
}
// ▲▲▲ End of collectInOrder ▲▲▲

// ▼▼▼ buildBalancedTree Definition ▼▼▼
template <typename Tdata>
TreeNode<Tdata>* BinaryTree<Tdata>::buildBalancedTree(vector<Tdata>& sortedData, int start, int end, TreeNode<Tdata>* parent)
{
    if(start > end)
    {
        return nullptr;
    }
    
    // Find the middle element
    int mid = start + (end - start) / 2;
    
    // Create new node with middle element
    TreeNode<Tdata>* newNode = new TreeNode<Tdata>(sortedData[mid]);
    newNode->Parent = parent;
    
    // Recursively build left and right subtrees
    newNode->Left = buildBalancedTree(sortedData, start, mid - 1, newNode);
    newNode->Right = buildBalancedTree(sortedData, mid + 1, end, newNode);
    
    return newNode;
}
// ▲▲▲ End of buildBalancedTree ▲▲▲

// ▼▼▼ balance Definition ▼▼▼
template <typename Tdata>
void BinaryTree<Tdata>::balance()
{
    if(root == nullptr)
    {
        cout << "Tree is already empty (balanced)!" << endl;
        return;
    }
    
    cout << "Balancing the tree..." << endl;
    
    // Step 1: Collect all data in sorted order
    vector<Tdata> sortedData;
    collectInOrder(root, sortedData);
    
    // Step 2: Destroy the old tree
    destroyTree(root);
    
    // Step 3: Build a new balanced tree
    root = buildBalancedTree(sortedData, 0, sortedData.size() - 1, nullptr);
    
    cout << "Tree has been balanced successfully!" << endl;
}
// ▲▲▲ End of balance ▲▲▲


/* ======================= End of File =================== */