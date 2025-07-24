/*
*
* Problem description:
* Implement the merge sort algorithm.
*
*/

#include <iostream>
#include <vector>
#include <stdexcept> 

using std::cout     ;
using std::cin      ;
using std::endl     ;
using std::vector   ;

/********************* Function declarations *********************/
/****************************************************************/

vector<int> & get_vectorElements(vector<int> & argVec);

void merge_sort(vector<int> & argVec, int start, int end);

void merge_sort_iterative(vector<int> & argVec);

void merge(vector<int> &argVec, int start, int mid, int end);

void print_vector(vector<int> & argVec);

/*********************** Application ***************************/
/**************************************************************/

int main() 
{
    
    system("cls");

    vector<int> vec;

    vec = get_vectorElements(vec);

    merge_sort(vec, 0, vec.size() - 1);

    cout << "\nThe sorted array: ";
    
    print_vector(vec);
    
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
void merge_sort(vector<int> & argVec, int start, int end)
{

    if(end <= start)
    {
        return;
    }
    else
    {
        int mid = start + (end - start) / 2;

        merge_sort(argVec, start, mid);
        merge_sort(argVec, mid+1, end);
        merge(argVec, start, mid, end);
    }

}
/*---------------------------------------------------------------------------*/
void merge_sort_iterative(vector<int> & argVec)
{
    int n = argVec.size();

    // Start with subarrays of size 1, progressively doubling the size
    for (int current_size = 1; current_size < n; current_size *= 2)
    {
        // Merge subarrays in pairs
        for (int start = 0; start < n - 1; start += 2 * current_size)
        {
            // Calculate mid and end indices
            int mid = std::min(start + current_size - 1, n - 1);
            int end = std::min(start + 2 * current_size - 1, n - 1);

            // Merge the two subarrays
            merge(argVec, start, mid, end);
        }
    }
}
/*---------------------------------------------------------------------------*/
void merge(vector<int> &argVec, int start, int mid, int end)
{

    int left_It{0}, right_It{0}, vec_indx{start};

    vector<int> left_vec(argVec.begin() + start, argVec.begin() + mid + 1);
    vector<int> right_vec(argVec.begin() + mid + 1, argVec.begin() + end + 1);

    while(left_It < left_vec.size() && right_It < right_vec.size())
    {
        if(left_vec[left_It] <= right_vec[right_It])
        {
            argVec[vec_indx++] = left_vec[left_It++];
        }
        else
        {
            argVec[vec_indx++] = right_vec[right_It++];
        }
    }
    
    while(left_It < left_vec.size())
    {
        argVec[vec_indx++] = left_vec[left_It++];
    }

    while(right_It < right_vec.size())
    {
        argVec[vec_indx++] = right_vec[right_It++];
    }

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


