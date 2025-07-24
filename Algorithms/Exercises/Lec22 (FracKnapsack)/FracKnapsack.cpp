/*
*
* Problem description:
* Implement the Fractional knapsack problem algorithm.
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

// Struct item
struct Item
{
	int index;
	double profit;
	double weight;
	double ratio;
};
/////////////////////////////////////////////////////////////////////
void getItemsFromUser(vector<Item> & items);
/////////////////////////////////////////////////////////////////////
bool compare(const Item &a, const Item &b);
/////////////////////////////////////////////////////////////////////
void fractionalKnapsack(vector<Item> &items, double capacity);

/*********************** Application ***************************/
/**************************************************************/

int main() 
{
    
    system("cls");
	
	double capacity;
	vector<Item> items;
	
	cout << "\nEnter knapsack capacity (kg): ";
    cin >> capacity;
	cout << '\n';
	
	getItemsFromUser(items);
	
	fractionalKnapsack(items, capacity);
    
    return 0;

}

/********************* Function definitions *********************/
/****************************************************************/

// Function to get item data from user
void getItemsFromUser(vector<Item> & items)
{
    int numItems{0};
    
    cout << "Enter number of items: ";
    cin >> numItems;
    cout << '\n';
	cout << "-------------------------------------------------" << '\n';
    for (int i = 0; i < numItems; i++) {
        Item item;
        item.index = i;
        
        cout << "Enter profit for item #" << i << ": ";
        cin >> item.profit;
        
        cout << "Enter weight for item #" << i << ": ";
        cin >> item.weight;
        
        item.ratio = 0; // Will be calculated later
        items.push_back(item);
		cout << "-------------------------------------------------" << '\n';
    }
	cout << '\n';
}
/*---------------------------------------------------------------------------*/
bool compare(const Item &a, const Item &b)
{
	return a.ratio > b.ratio;
};
/*---------------------------------------------------------------------------*/
void fractionalKnapsack(vector<Item> & items, double capacity)
{
	double totalProfit{0.0};
    double remainingCapacity = capacity;
	double fraction{1.0};
	
	vector<pair<Item, double>> storedItems;
	
	// Calculate the ratio of each item:
	for(auto & item : items)
	{
		item.ratio = item.profit / item.weight;
	}
	
	// Sort items according to their ratio in decreasing order:
	std::sort(items.begin(), items.end(), compare);
	
	for(auto & item : items)
	{
		if(remainingCapacity <= 0)
		{
			break;
		}
		else if(item.weight > remainingCapacity)
		{
			fraction = remainingCapacity / item.weight;
		}
		else
		{
			// Do Nothing
		}
		
		storedItems.emplace_back(item, fraction);
		
		totalProfit += (fraction * item.profit);
		remainingCapacity -= (fraction * item.weight);
	}
	
	// Output results
    cout << "Maximum profit: $" << totalProfit << endl << endl;
    cout << "Selected items:" << endl;
    cout << std::left // Left-align all fields
         << std::setw(8) << "Item #" << " | "
         << std::setw(10) << "Profit ($)" << " | "
         << std::setw(11) << "Weight (kg)" << " | "
         << "Fraction Taken" << endl;
    cout << "-------------------------------------------------" << endl;
    
    for (const auto &pair : storedItems) 
	{
		const Item & item = pair.first;
		double fraction = pair.second;
		
        cout << std::left
             << std::setw(8) << "  #" + std::to_string(item.index) << " | "
             << std::setw(10) << item.profit << " | "
             << std::setw(11) << item.weight << " | "
             << std::fixed << std::setprecision(1) << fraction * 100 << "%" << endl;
    }
}
/*---------------------------------------------------------------------------*/


/****************************************************************/
/****************************************************************/