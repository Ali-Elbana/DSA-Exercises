/*
*
* Problem description:
* Calculate the area of the parallelogram.
*
*/

#include <iostream>
#include <string>
#include <stdexcept> 

using std::cout     ;
using std::cin      ;
using std::endl     ;
using std::string   ;
using std::istream  ;
using std::ostream  ;

/********************* Function declarations *********************/
/****************************************************************/

double CalcParalleloArea( double argBase, double argHeight );

/*********************** Application ***************************/
/**************************************************************/

int main() 
{
    
    system("cls");

    double base{0}, height{0};

    cout << "\n'Welcome to the calculation of parallelogram program'\n";
    cout << "\nEnter the base and height to calculate the area: ";
    cin >> base >> height;

    double area = CalcParalleloArea(base, height);

    cout << "\nThe area = " << area << endl;

    return 0;

}

/********************* Function definitions *********************/
/****************************************************************/

double CalcParalleloArea( double argBase, double argHeight )
{
    double area{0};

    area = argBase * argHeight;

    return area;
}

/****************************************************************/
/****************************************************************/