/*
*
* Problem description:
* Implement the Depth First Search algorithm using recursion.
*
*/
#include <iostream>
#include <vector>
#include <stdexcept> 
#include <unordered_map>
#include <queue>
#include <string>
#include <algorithm>
#include <iomanip>
#include <climits>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::pair;
using std::queue;
using std::priority_queue;
using std::unordered_map;

/************************* Declarations **************************/
/****************************************************************/

class Graph
{
	private:
	vector<string> nodeNames;
	vector<vector<int>> adjacencyList;
	vector<bool> isVisited;  // <- MOVED: Make visited array a class member
	
	// <- ADD: Private recursive helper function
	void DFS_Recursive(int currentNode)
	{
		// Mark current node as visited
		isVisited[currentNode] = true;
		
		// Visit all unvisited neighbors
		for(int neighbor : adjacencyList[currentNode])
		{
			if(isVisited[neighbor] == false)
			{
				// Print the edge being traversed
				cout << ' ' << nodeNames[currentNode] << " - " << nodeNames[neighbor] << endl;
				
				// Recursively visit the neighbor
				DFS_Recursive(neighbor);  // <- RECURSIVE CALL
			}
		}
	}
	
	public:
	// Constructor - create graph with node names
	Graph(vector<string> & nNames)
	{
		nodeNames = nNames;
		adjacencyList.resize(nodeNames.size());
	}
	
	// Add edges for a node
	void addEdges(int nodeIdx, vector<int> connections)
	{
		adjacencyList[nodeIdx] = connections;
	}
	
	// <- SIMPLIFIED: Public DFS method (no loops, no stacks!)
    void DFS() 
	{
        cout << "\n DFS Traversal (Recursive):\n";
		
		int numNodes = nodeNames.size();
		
		// Initialize visited array
		isVisited.assign(numNodes, false);
		
		// Start recursive DFS from node 0
		DFS_Recursive(0);  // <- SINGLE FUNCTION CALL!
	}
};

/*********************** Application ***************************/
/**************************************************************/

int main() 
{
    
    system("cls");
	
	// Create graph with same nodes as original
    vector<string> names{"A", "B", "C", "D", "E", "F", "G", "H", "I"};
	
	Graph g(names);
	
	// Add same edges as original
    g.addEdges(0, {1, 2});        // A connects to B, C
    g.addEdges(1, {0, 3, 4});     // B connects to A, D, E
    g.addEdges(2, {0, 3, 5});     // C connects to A, D, F
    g.addEdges(3, {1, 2, 4});     // D connects to B, C, E
    g.addEdges(4, {1, 5});        // E connects to B, F
    g.addEdges(5, {2, 3, 4, 7});  // F connects to C, D, E, H
    g.addEdges(6, {7, 8});        // G connects to H, I
    g.addEdges(7, {5, 6, 8});     // H connects to F, G, I
    g.addEdges(8, {6, 7});        // I connects to G, H
	
	g.DFS();
	
    return 0;
}

/********************* Function definitions *********************/
/****************************************************************/
/****************************************************************/
/****************************************************************/