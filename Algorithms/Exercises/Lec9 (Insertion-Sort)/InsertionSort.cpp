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

vector<int> & insertion_sort(vector<int> & argVec);

void print_vector(vector<int> & argVec);

/*********************** Application ***************************/
/**************************************************************/

int main() 
{
    
    system("cls");

    vector<int> vec;

    vec = get_vectorElements(vec);

    vec = insertion_sort(vec);

    cout << "\nThe sorted array: ";
    
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
vector<int> & insertion_sort(vector<int> & argVec)
{

    int key{0}, j{0};

    for(int i = 1; i < argVec.size(); ++i)
    {

        key = argVec[i];

        for(j = i - 1; j >= 0; --j)
        {
            if(argVec[j] > key)
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

    return argVec;

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