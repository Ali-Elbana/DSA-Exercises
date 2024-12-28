/*
*
* Problem description:
* Implement the insertion sort algorithm.
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

vector<int> & SegregateNeg_insertion_sort(vector<int> & argVec);

void SegregateNeg_merge_sort(vector<int> & argVec, int start, int end);

void SegregateNeg_merge(vector<int> &argVec, int start, int mid, int end);

void print_vector(vector<int> & argVec);

/*********************** Application ***************************/
/**************************************************************/

int main() 
{
    
    system("cls");

    vector<int> vec;

    vec = get_vectorElements(vec);

    // vec = SegregateNeg_insertion_sort(vec);

    SegregateNeg_merge_sort(vec, 0, vec.size() - 1);

    cout << "\nThe segregated array: ";
    
    print_vector(vec);
    
    return 0;

}

/********************* Function definitions *********************/
/****************************************************************/

vector<int> & get_vectorElements(vector<int> & argVec)
{
    int element{0};

    cout << endl << "Enter the array elements: ";

    while(cin >> element)
    {
        argVec.push_back(element);
    }

    return argVec;
}
/*---------------------------------------------------------------------------*/
vector<int> & SegregateNeg_insertion_sort(vector<int> & argVec)
{

    int key{0}, j{0};

    for(int i = 1; i < argVec.size(); ++i)
    {

        if(argVec[i] >= 0)
        {
            continue;
        }

        else
        {
            key = argVec[i];

            for(j = i - 1; j >= 0; --j)
            {
                if(argVec[j] >= 0)
                {
                    argVec[j+1] = argVec[j]; 
                }
                else
                {
                    break;
                }
            }

            argVec[j+1] = key;
        }
    }

    return argVec;

}
/*---------------------------------------------------------------------------*/
void SegregateNeg_merge_sort(vector<int> & argVec, int start, int end)
{

    if(end <= start)
    {
        return;
    }
    else
    {
        int mid = start + (end - start) / 2;

        SegregateNeg_merge_sort(argVec, start, mid);
        SegregateNeg_merge_sort(argVec, mid+1, end);
        SegregateNeg_merge(argVec, start, mid, end);
    }

}
/*---------------------------------------------------------------------------*/
void SegregateNeg_merge(vector<int> &argVec, int start, int mid, int end)
{

    int left_It{0}, right_It{0}, vec_indx{start};

    vector<int> left_vec(argVec.begin() + start, argVec.begin() + mid + 1);
    vector<int> right_vec(argVec.begin() + mid + 1, argVec.begin() + end + 1);

    while(left_It < left_vec.size() && left_vec[left_It] < 0)
    {
        argVec[vec_indx++] = left_vec[left_It++];
    }
    
    while(right_It < right_vec.size() && right_vec[right_It] < 0)
    {
        argVec[vec_indx++] = right_vec[right_It++];
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