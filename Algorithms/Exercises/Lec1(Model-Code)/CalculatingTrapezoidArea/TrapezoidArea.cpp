/*
*
* Problem description:
* Calculate the area of the trapezoid.
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

double CalcTrapezoidArea(double argBaseA, double argBaseB, double argHeight);

/*********************** Application ***************************/
/**************************************************************/

int main() 
{
    
    system("cls");

    double baseA{0}, baseB{0}, height{0};

    cout << "\n'Welcome to the calculation of trapezoid program'\n";
    cout << "\nEnter the base a,b and height to calculate the area: ";
    cin >> baseA >> baseB >> height;

    double area = CalcTrapezoidArea(baseA, baseB, height);

    cout << "\nThe area = " << area << endl;

    return 0;

}

/********************* Function definitions *********************/
/****************************************************************/

double CalcTrapezoidArea(double argBaseA, double argBaseB, double argHeight)
{
    double area{0};

    area = ((argBaseA + argBaseB) / 2.0) * argHeight;

    return area;
}

/****************************************************************/
/****************************************************************/