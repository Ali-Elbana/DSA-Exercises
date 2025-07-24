/*
*
* Problem description:
* Implement the merge sort algorithm.
*
*/

#include <iostream>
#include <vector>
#include <limits>
#include <stdexcept> 

using std::cout     ;
using std::cin      ;
using std::endl     ;
using std::vector   ;

/********************* Function declarations *********************/
/****************************************************************/

vector<int> & get_vectorElements(vector<int> & argVec);

int get_searchItem(int & argSearchKey);

int binary_search(vector<int> & argVec, int searchKey);

void print_vector(vector<int> & argVec);

/*********************** Application ***************************/
/**************************************************************/

int main() 
{
    
    system("cls");

    vector<int> vec{1,2,3,4,5,6,7,8,9,10};

    int searchKey{0};

    searchKey = get_searchItem(searchKey);

    int result = binary_search(vec, searchKey);

    if (result != -1) 
    {
        cout << "\nThe searched item is found at index: " << result << endl;
    } else 
    {
        cout << "\nThe searched item is not found in the array." << endl;
    }

    return 0;

}

/********************* Function definitions *********************/
/****************************************************************/
// End the input elements with ctrl+z
vector<int> & get_vectorElements(vector<int> & argVec)
{
    int element{0};

    cout << endl << "Enter the array elements (enter ctrl+z to finish): ";

    while(cin >> element)
    {
        argVec.push_back(element);
    }

    return argVec;
}
/*---------------------------------------------------------------------------*/
int get_searchItem(int & argSearchKey)
{
    cout << endl << "Enter the search key: ";
    cin >> argSearchKey;

    return argSearchKey;
}
/*---------------------------------------------------------------------------*/
int binary_search(vector<int> & argVec, int searchKey)
{
    int start{0}, end{static_cast<int>(argVec.size()) - 1}, mid{0};

    while(start <= end)
    {
        mid = start + (end - start) / 2;

        if(argVec[mid] == searchKey)
        {
            return mid;
        }
        else if(argVec[mid] < searchKey)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
    throw std::invalid_argument("The search key is not found in the array.");
}
/*---------------------------------------------------------------------------*/
void print_vector(vector<int> & argVec)
{
    cout << endl;
    for(auto & ele : argVec)
    {
        cout << ele << ' ';
    }
    cout << endl;
}

/****************************************************************/
/****************************************************************/


