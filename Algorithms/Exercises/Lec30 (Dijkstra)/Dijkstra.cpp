/*
*
* Problem description:
* Implement the Dijkstra's shortest path algorithm.
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
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::pair;
using std::queue;
using std::priority_queue;
using std::unordered_map;
using std::numeric_limits;

/************************* Declarations **************************/
/****************************************************************/

// Declaration to avoid errors Edge class
class Vertex;
/*---------------------------------------------------------------------------*/
class Edge
{
	public:
	
		Vertex * target;
		double weight;
		
		// Default constructor
		Edge() {}
		
		// Paramatrized Constructor:
		Edge(Vertex * t, double w): target(t), weight(w) {}
};
/*---------------------------------------------------------------------------*/
class Vertex
{
	public:
		
		string name;
		vector<Edge> edges;
		bool isVisited{false};
		double totalDist = numeric_limits<double>::infinity();
		Vertex * prev{nullptr};
		
		// Default constructor
		Vertex() {}
		
		// Paramatrized Constructor:
		Vertex(string n) : name(n) {}	
};
/*---------------------------------------------------------------------------*/
class Graph
{
	private:
		vector<Vertex *> vertices;
	
	public:
		// Constructor - create graph with node names
		Graph(const vector<string> & names)
		{
			for(const auto & name : names)
			{
				vertices.push_back(new Vertex(name));
			}
		}
		/*---------------------------------------------------------------------------*/
		// Add all node edges
		void addEdges(int from, const vector<int> & to, const vector<double> & weights)
		{
			for(size_t i = 0; i < to.size(); ++i)
			{
				
				/*
					to[i] = 2 // index of C
					vertices[2] // pointer to vertex "C"
					So vertices[to[i]] means:
					“Go to the vertices list, find the vertex whose index is to[i], 
					and give me its pointer.”
				*/
				vertices[from]->edges.emplace_back(vertices[to[i]],weights[i]);
			}
		}
		/*---------------------------------------------------------------------------*/
		void Dijkstra(void)
		{
			vertices[0]->totalDist = 0;
			
			for(auto & v : vertices)
			{
				for(const auto & edge : v->edges)
				{
					double newDist = v->totalDist + edge.weight;
					
					if(newDist < edge.target->totalDist)
					{
						edge.target->totalDist = newDist;
						edge.target->prev = v;
					}
				}
			}
			
			cout << endl;
			printPath(vertices.back()); // Start from the last element in the vector
			reset();
		}
		/*---------------------------------------------------------------------------*/
		void printPath(Vertex * v)
		{
			if(v->prev != nullptr)
			{
				printPath(v->prev);
			}
			
			cout << v->name;
			
			if(v != vertices.back())
			{
				cout << " --> ";
			}
			else
			{
				cout << endl;
			}
		}
		/*---------------------------------------------------------------------------*/
		void reset() 
		{
			for(auto & v : vertices)
			{
				v->isVisited = false;
				v->totalDist = numeric_limits<double>::infinity();
				v->prev = nullptr;
			}
		}
		/*---------------------------------------------------------------------------*/
		// Destructor
		~Graph()
		{
			for(auto v : vertices)
			{
				delete v;
			}
		}
	
};

/*********************** Application ***************************/
/**************************************************************/

int main() 
{
    
    system("cls");
	
	vector<string> vertexNames = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
    Graph g(vertexNames);
    
    // Add edges (same structure as original)
    g.addEdges(0, {1, 2, 3}, {2, 4, 3});        // A -> B(2), C(4), D(3)
    g.addEdges(1, {4, 5, 6}, {7, 4, 6});        // B -> E(7), F(4), G(6)
    g.addEdges(2, {4, 5, 6}, {3, 2, 4});        // C -> E(3), F(2), G(4)
    g.addEdges(3, {4, 5, 6}, {4, 1, 5});        // D -> E(4), F(1), G(5)
    g.addEdges(4, {7, 8}, {1, 4});              // E -> H(1), I(4)
    g.addEdges(5, {7, 8}, {6, 3});              // F -> H(6), I(3)
    g.addEdges(6, {7, 8}, {3, 3});              // G -> H(3), I(3)
    g.addEdges(7, {9}, {3});                    // H -> J(3)
    g.addEdges(8, {9}, {4});                    // I -> J(4)
    
    // Run algorithm
    g.Dijkstra();  // Find shortest paths from A
    cout << endl;

    return 0;

}
/********************* Function definitions *********************/
/****************************************************************/

/****************************************************************/
/****************************************************************/








