/*
============================================================
* Project: Min-Heap Implementation
* File:    main.cpp
* Author:  [Ali El-bana]
* Date:    [2025-08-28]
* Version: v1.0
------------------------------------------------------------
* Description:
* Complete min-heap implementation with insertion, deletion,
* and visual tree representation capabilities
------------------------------------------------------------
* Notes:
* - Implements min-heap property (parent ≤ children)
* - Dynamic array-based storage using std::vector
* - Includes tree visualization functionality
============================================================
*/

/* ====================== Includes ====================== */
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>

/* =================== Namespace Usage ================== */
using std::cout;
using std::endl;
using std::vector;
using std::string;

/* ===================== Class Definition =============== */
// ▼▼▼ Class: Heap (Min-Heap Implementation) ▼▼▼
class Heap {
private:
    // ▼▼▼ Private Data Members ▼▼▼
    std::vector<int> data_list;  // Dynamic array to store heap elements
    size_t heap_size;            // Current number of elements in heap
    // ▲▲▲ End of Private Data Members ▲▲▲

public:
    // ▼▼▼ Constructor ▼▼▼
    /**
     * @brief Default constructor - initializes empty heap
     * @complexity O(1)
     */
    Heap() : heap_size(0) {}
    // ▲▲▲ End of Constructor ▲▲▲

    // ▼▼▼ Insert Method ▼▼▼
    /**
     * @brief Inserts a new element into the min-heap
     * @param data The integer value to insert
     * @complexity O(log n) - due to upward bubbling
     */
    void insert(int data) 
	{
        // Get insertion position (end of heap)
        size_t i = heap_size;
        
        // Add element to vector (resize if necessary)
        if(i < data_list.size()) 
		{
            data_list[i] = data;        // Reuse existing space
        } 
		else 
		{
            data_list.push_back(data);  // Extend vector
        }
		
        heap_size++;  // Increment heap size
        
        // ▼▼▼ Bubble Up Process (Maintain Min-Heap Property) ▼▼▼
        size_t parent_index = (i - 1) / 2;  // Calculate parent index
        
        // Continue bubbling up while not at root and parent > current
        while(i != 0 && data_list[i] < data_list[parent_index]) 
		{
            // Swap with parent
            std::swap(data_list[i], data_list[parent_index]);
            
            // Move up to parent position
            i = parent_index;
            parent_index = (i - 1) / 2;
        }
        // ▲▲▲ End of Bubble Up Process ▲▲▲
    }
    // ▲▲▲ End of Insert Method ▲▲▲

    // ▼▼▼ Pop Method (Extract Minimum) ▼▼▼
    /**
     * @brief Removes and returns the minimum element (root)
     * @return The minimum element in the heap
     * @throws std::out_of_range if heap is empty
     * @complexity O(log n) - due to downward bubbling
     */
    int pop() 
	{
        // Check if heap is empty
        if(heap_size == 0) 
		{
            throw std::out_of_range("Heap is empty");
        }
        
        // Store minimum value (root) to return
        int data = data_list[0];
        
        // Move last element to root position
        data_list[0] = data_list[heap_size - 1];
        heap_size--;  // Decrease heap size
        
        // ▼▼▼ Bubble Down Process (Restore Min-Heap Property) ▼▼▼
        size_t i = 0;                    // Start from root
        size_t left_index = 2 * i + 1;   // Left child index
        
        // Continue while left child exists
        while(left_index < heap_size) 
		{
            size_t right_index = 2 * i + 2;   // Right child index
            size_t smaller_index = left_index; // Assume left is smaller
            
            // Check if right child exists and is smaller than left
            if(right_index < heap_size && data_list[right_index] < data_list[left_index]) 
			{
                smaller_index = right_index;
            }
            
            // If current element is already smaller than both children, stop
            if(data_list[smaller_index] >= data_list[i]) 
			{
                break;
            }
            
            // Swap with smaller child
            std::swap(data_list[i], data_list[smaller_index]);
            
            // Move down to child position
            i = smaller_index;
            left_index = 2 * i + 1;
        }
        // ▲▲▲ End of Bubble Down Process ▲▲▲
        
        return data;  // Return extracted minimum
    }
    // ▲▲▲ End of Pop Method ▲▲▲

    // ▼▼▼ Print Method (Linear Display) ▼▼▼
    /**
     * @brief Prints all heap elements in linear order
     * @complexity O(n)
     */
    void print() const 
	{
        for(size_t i = 0; i < heap_size; i++) 
		{
            std::cout << data_list[i] << " - ";
        }
        std::cout << "\n";
    }
    // ▲▲▲ End of Print Method ▲▲▲

    // ▼▼▼ Size Method ▼▼▼
    /**
     * @brief Returns the number of elements in the heap
     * @return Current heap size
     * @complexity O(1)
     */
    size_t size() const 
	{
        return heap_size;
    }
    // ▲▲▲ End of Size Method ▲▲▲

    // ▼▼▼ Empty Method ▼▼▼
    /**
     * @brief Checks if the heap is empty
     * @return true if heap is empty, false otherwise
     * @complexity O(1)
     */
    bool empty() const 
	{
        return heap_size == 0;
    }
    // ▲▲▲ End of Empty Method ▲▲▲

    // ▼▼▼ Draw Method (Tree Visualization) ▼▼▼
    /**
     * @brief Draws a visual representation of the heap as a binary tree
     * @complexity O(n)
     * @note Uses level-order traversal for tree representation
     */
    void draw() const 
	{
        // Return if heap is empty
        if (heap_size == 0) return;
        
        // Calculate tree dimensions
        int levels_count = static_cast<int>(std::log2(heap_size)) + 1;  // Number of levels
        int line_width = static_cast<int>(std::pow(2, levels_count - 1)); // Max width needed
        
        size_t j = 0;  // Element index tracker
        
        // ▼▼▼ Level-by-Level Tree Drawing ▼▼▼
        for(int i = 0; i < levels_count; i++) 
		{
            // Calculate nodes at current level
            int nodes_count = static_cast<int>(std::pow(2, i));
            
            // Calculate spacing for centering
            int space = static_cast<int>(std::ceil(line_width - nodes_count / 2.0));
            int space_between = static_cast<int>(std::ceil(levels_count / static_cast<double>(nodes_count)));
            space_between = space_between < 1 ? 1 : space_between;  // Minimum spacing
            
            // Build output string for current level
            std::ostringstream str;
            str << std::string(space + space_between, ' ');  // Leading spaces
            
            size_t k = j;  // Save starting position
            
            // Print all nodes at current level
            for(; j < k + nodes_count; j++) 
			{
                if(j == heap_size) 
				{  // Stop if no more elements
                    break;
                }
                str << data_list[j] << std::string(space_between, ' ');
            }
            
            str << std::string(space, ' ') << "\n";  // Trailing spaces and newline
            std::cout << str.str();  // Output the level
        }
        // ▲▲▲ End of Level-by-Level Tree Drawing ▲▲▲
    }
    // ▲▲▲ End of Draw Method ▲▲▲
};
// ▲▲▲ End of Heap Class ▲▲▲

/* ==================== Main Application ================= */
/**
 * @brief Demonstration program for min-heap functionality
 * @return 0 on successful execution
 */
int main() {
    // ▼▼▼ Heap Creation and Population ▼▼▼
    std::cout << "Min-Heap Demonstration Program" << std::endl;
    std::cout << "===============================" << std::endl;
    
    Heap heap;  // Create empty heap
    
    // Insert sample data
    std::cout << "\nInserting elements: 5, 3, 8, 1, 6" << std::endl;
    heap.insert(5);
    heap.insert(3);
    heap.insert(8);
    heap.insert(1);
    heap.insert(6);
    // ▲▲▲ End of Heap Creation and Population ▲▲▲
    
    // ▼▼▼ Display Heap Contents ▼▼▼
    std::cout << "\nHeap elements (array representation): ";
    heap.print();
    
    std::cout << "\nHeap tree structure:" << std::endl;
    heap.draw();
    // ▲▲▲ End of Display Heap Contents ▲▲▲
    
    // ▼▼▼ Extract All Elements (Heap Sort) ▼▼▼
    std::cout << "\nExtracting elements in sorted order (min to max):" << std::endl;
    while(heap.empty() == false) 
	{
        std::cout << heap.pop() << " ";
    }
    std::cout << std::endl;
    // ▲▲▲ End of Extract All Elements ▲▲▲
    
    std::cout << "\nProgram completed successfully!" << std::endl;
    return 0;
}

/* ======================= End of File =================== */