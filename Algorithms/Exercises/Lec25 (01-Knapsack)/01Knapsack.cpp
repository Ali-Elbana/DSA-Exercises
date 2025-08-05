/*
*
* Problem description:
* Implement the 0/1 Knapsack problem algorithm.
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

struct Item
{
	string name;
	int weight;
	int profit;
	
	// Constructor
	Item(string str, int w, int p): name(str), weight(w), profit(p) {}
	
};
/////////////////////////////////////////////////////////////////////

int knapsack(vector<Item> &items, int max_weight, vector<vector<int>> &dp,
             vector<string> &solution);
/*********************** Application ***************************/
/**************************************************************/

int main() 
{
    
    system("cls");
	
	int maxWeight{8};
	vector<string> solution;
	int maxProfit{-1};
	
	vector<Item> items =
	{
		Item("#1", 1, 4),
        Item("#2", 3, 9),
        Item("#3", 5, 12),
        Item("#4", 4, 11)
	};
	
	// Add dummy item at the beginning
	items.insert(items.begin(), Item("#0", 0, 0));
	
	// Initialize DP table
	vector<vector<int>> table(items.size(), vector<int>(maxWeight + 1, 0));
	
	maxProfit = knapsack(items, maxWeight, table, solution);
	
	cout << "\n The max profit is: " <<  maxProfit;
	cout << "\n The picked items are: [ ";
	
	for(auto & str : solution)
	{
		cout << str << " ";
	}
	
	cout << "]\n";
	
    return 0;

}
/********************* Function definitions *********************/
/****************************************************************/

int knapsack(vector<Item> &items, int max_weight, vector<vector<int>> &dp,
             vector<string> &solution)
{

	int size = items.size();
	int max_profit{-1};
	
	// To establish the table:
	/* if item weight <= current weight (j weight)
		-- max(top cell, profit + table[top cell][diff of weights])
		--> == max(table[i-1][j], profit + table[i-1][j-w])

	   else
		-- top cell == table[i-1][j]
	*/
	for(int i = 1; i < size; ++i)
	{
		for(int j = 1; j <= max_weight; ++j)
		{
			if(items[i].weight <= j)
			{
				dp[i][j] = std::max(dp[i-1][j], items[i].profit + 
												dp[i-1][j - items[i].weight]);
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
			
		}
	}
	
	max_profit = dp[size - 1][max_weight];
	
	// Get the items:
	// Start from the bottom right
	int i = size - 1;
	int j = max_weight;
	int remain = max_weight;
	
	while(remain >= 0 && j > 0 && i > 0)
	{
		if(dp[i][j] > dp[i-1][j]) // current value > profit
		{
			solution.push_back(items[i].name);
			remain -= items[i].weight;
			i--;
			j = remain;
		}
		else
		{
			i--;
		}
	}
	
	return max_profit;

}	 
/****************************************************************/
/****************************************************************/








