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

/*********************** Application ***************************/
/**************************************************************/

int main() 
{
    
    system("cls");
	
	int n = graph.size();
	int new_cost{-1};
	int indx{-1};
	
	vector<int> cost(n, INT_MAX);
	vector<string> path(n, "");
	
	cost[n-1] = 0;
	path[n-1] = labels[n-1];
	
	for(int i = n - 2; i >= 0; --i)
	{
		for(int j = i + 1; j < n; ++j)
		{
			if((graph[i][j] != 0) && (cost[j] != INT_MAX))
			{
				new_cost = graph[i][j] + cost[j];
				
				if(new_cost < cost[i])
				{
					cost[i] = new_cost;
					
					if(path[i] != path[i+1])
					{
						path[i] = labels[j];
					}
				}
				
			}
		}
	}
    
	cout<< "Path: ";
    for(auto & str : path)
    {
        cout << str << " --> " ;
    }
    cout << endl;
	
	indx = std::count(path.begin(), path.end(), labels[n-1]);
	
	cout << "\nMinimum Cost: " << cost[0] << endl;
	
	cout << "Minimum Path: " << labels[0] << " --> " << path[0] << " --> ";
	
	for(int i = 1; i < n; ++i)
	{
		
		if(path[i] == path[i-1])
		{
			continue;
		}
		else
		{
			cout << path[i];
		}
		
		if(i < (n - indx))
		{
			cout << " --> ";
		}
		
	}
	
    return 0;

}

/********************* Function definitions *********************/
/****************************************************************/


/****************************************************************/
/****************************************************************/