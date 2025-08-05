/*
*
* Problem description:
* Implement the stagecoach problem algorithm.
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
using std::priority_queue;
using std::unordered_map;

/************************* Declarations **************************/
/****************************************************************/

vector<string> labels = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};

vector<vector<int>> graph = {
    {0, 2, 4, 3, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 7, 4, 6, 0, 0, 0},
    {0, 0, 0, 0, 3, 2, 4, 0, 0, 0},
    {0, 0, 0, 0, 4, 1, 5, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 4, 0},
    {0, 0, 0, 0, 0, 0, 0, 6, 3, 0},
    {0, 0, 0, 0, 0, 0, 0, 3, 3, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

struct States
{
	string from;
	string to;
	int cost;
};


/*********************** Application ***************************/
/**************************************************************/

int main() 
{
    
    system("cls");
	
	int n = graph.size();
	int new_cost{-1};

	vector<States> vStates(n);
	vector<string> path(1, labels[0]);
	
	vStates[n-1] = {"", "", 0};
	
	for(int i = n - 2; i >= 0; --i)
	{
		vStates[i] = {labels[i], "", INT_MAX};
		
		for(int j = i + 1; j < n; ++j)
		{
			if(graph[i][j] != 0)
			{
				new_cost = graph[i][j] + vStates[j].cost;
				
				if(new_cost < vStates[i].cost)
				{
					vStates[i].cost = new_cost;
					vStates[i].to = labels[j];
				}
			}
		}
	}
    
	// Get shortest path:
	int i{0}, j{0};
	
	while(i < n)
	{
		if(path[j] == vStates[i].from)
		{
			path.push_back(vStates[i].to);
			j++;
		}
		
		i++;
	}
	
	cout << "\nMinimum Cost: " << vStates[0].cost << endl;
	
	cout << "Minimum Path: ";
	
	for(int i = 0; i < path.size(); ++i)
	{
		cout << path[i];
		
		if(i <= (path.size() - 2))
		{
			cout << " --> ";
		}
	}
	
    return 0;

}

/****************************************************************/
/****************************************************************/