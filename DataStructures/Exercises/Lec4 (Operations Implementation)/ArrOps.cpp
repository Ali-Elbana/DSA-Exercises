/*
============================================================
* Project: [Make Resize & GetAt methods for arrays]
* File:    [ArrOps.cpp]
* Author:  [Ali El-bana]
* Date:    [2025-08-10]
* Version: [v1.0]
------------------------------------------------------------
* Description:
* [Create Resize and GetAt methods for arrays with yourself to 
 understand more what's happened]
------------------------------------------------------------
* Notes:
* [This is for educational purpose]
============================================================
*/

/* ====================== Includes ====================== */
#include <iostream>
#include <algorithm>



/* =================== Namespace Usage ================== */
using std::cout;
using std::cin;
using std::endl;


/* =================== Global Constants ================= */
// const double PI = 3.14159;

/* ====================== Declarations ================== */
// ▼▼▼ Class: OurArray ▼▼▼
class OurArray;
// ▲▲▲ End of OurArray ▲▲▲


/* ===================== Class Definitions =============== */
// ▼▼▼ Class: OurArray ▼▼▼
class OurArray 
{
    // members & methods
	public:
	// ▼▼▼ Method: Resize ▼▼▼
	template<typename T>
	void Resize(T *& sourcePtr, int oldSize, int newSize)
	{
		// Validations:
		if(newSize < 1 || sourcePtr == nullptr || newSize == oldSize)
		{
			return;
		}
		else
		{
			// Create new array
			T * newArr = new T[newSize]{}; // Initialize all elements with default typedef
			
			// Copy elements from the old array to the new one
			std::copy(sourcePtr, sourcePtr + std::min(oldSize, newSize), newArr);
			
			// Delete the old chunks that sourcePtr points to
			delete[] sourcePtr;
			
			// Assign the new array to the sourcePtr
			sourcePtr = newArr;
		}
	}
	// ▲▲▲ End of Resize ▲▲▲
	
	// ▼▼▼ Method: GetAt ▼▼▼
	template<typename T>
	T GetAt(T * ArrPtr, int size, int idx)
	{
		T result{-1};
		
		// Validations:
		if(idx < 0 || idx >= size || ArrPtr == nullptr)
		{
			return T();
		}
		else
		{
			result = *(ArrPtr + idx);
		}
		
		return result;
	}
	// ▲▲▲ End of GetAt ▲▲▲
	
};
// ▲▲▲ End of OurArray ▲▲▲


/* ==================== Function Prototypes ============== */
// ▼▼▼ Function: exampleFunction ▼▼▼
// void exampleFunction(int param);
// ▲▲▲ End of exampleFunction ▲▲▲


/* ==================== Main Application ================= */
int main(void) 
{
    // ----- Initialization -----
    system("cls");
    cout << "Program started...\n";
	int * arr = new int[3]{1,2,3};
	OurArray newArr;
	
    // ----- Logic -----
    // [Your code here]
	newArr.Resize(arr, 3, 5);
	
	cout << "\nThe array after resizing: ";
	for(int i = 0; i < 5; i++) 
	{
		cout << arr[i] << " ";
    }
	
	int item = newArr.GetAt(arr, 5, 2);
	
	cout << "\nItem = " << item << '\n';
	
    // ----- End -----
    return 0;
}

/* ================== Function/Method Definitions =============== */
// ▼▼▼ exampleFunction Definition ▼▼▼

// ▲▲▲ End of exampleFunction ▲▲▲



/* ======================= End of File =================== */
