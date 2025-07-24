/*
*
* Problem description:
* Calculate the correlation.
*
*/

#include <iostream>
#include <string>
#include <vector>
#include <numeric>  // For std::inner_product
#include <algorithm>  // For std::inner_product
#include <cmath>
#include <stdexcept> 


using std::cout     ;
using std::cin      ;
using std::endl     ;
using std::string   ;
using std::vector   ;
using std::istream  ;
using std::ostream  ;
using std::inner_product ;

auto constexpr EXPONENT = 2;

/********************* Function declarations *********************/
/****************************************************************/

double Correl(double argNumerator, double argDemoni1, double argDemoni2);

double CalcNumerColerr( double argN, double argSumX, double argSumY,
                        double argSumXY);

double CalcDemo1Colerr( double argN, double argSumX, double argSumPowX);

double CalcDemo2Colerr( double argN, double argSumY, double argSumPowY);

/*********************** Application ***************************/
/**************************************************************/

int main() 
{
    
    system("cls");

    double EleNum{0}, sumX{0}, sumY{0}, sumPowX{0}, sumPowY{0}, sumXY{0}, 
    numerator{0}, demoni1{0}, demoni2{0}, var1{0}, var2{0};

    vector<double> vecX, vecY;

    cout << "\n'Welcome to the calculation of correlation program'\n";
    cout << "\nEnter the number of elements: ";
    cin >> EleNum;

    cout << "\nEnter the elements of the first variable: ";
    for( int i = 0; i < EleNum; ++i )
    {
        cin >> var1;

        vecX.push_back(var1);

        sumX += var1;

        sumPowX += pow(var1, EXPONENT);
    }

    cout << "\nEnter the elements of the second variable: ";
    for( int i = 0; i < EleNum; ++i )
    {
        cin >> var2;

        vecY.push_back(var2);

        sumY += var2;

        sumPowY += pow(var2, EXPONENT);
    }

    sumXY = inner_product( vecX.begin(), vecX.end(),
    vecY.begin(), 0.0 );

    numerator = CalcNumerColerr(EleNum, sumX, sumY, sumXY);
    demoni1 = CalcDemo1Colerr(EleNum, sumX, sumPowX);
    demoni2 = CalcDemo2Colerr(EleNum, sumY, sumPowY);

    double rXY = Correl(numerator, demoni1, demoni2);

    cout << "\nThe correlation = " << rXY << endl;
    
    

    return 0;

}

/********************* Function definitions *********************/
/****************************************************************/

double Correl(double argNumerator, double argDemoni1, double argDemoni2)
{
    double rXY{0};

    rXY = argNumerator / (argDemoni1 * argDemoni2);

    return rXY;
}
/*---------------------------------------------------------------------------*/
double CalcNumerColerr( double argN, double argSumX, double argSumY,
                        double argSumXY)
{
    double CorrNumr{0};

    CorrNumr = (argN * argSumXY) - (argSumX * argSumY);

    return CorrNumr;
}
/*---------------------------------------------------------------------------*/
double CalcDemo1Colerr( double argN, double argSumX, double argSumPowX)
{
    double CorrDemo1{0};
    
    CorrDemo1 = sqrt((argN * argSumPowX) - pow(argSumX,2));

    return CorrDemo1;
}
/*---------------------------------------------------------------------------*/
double CalcDemo2Colerr( double argN, double argSumY, double argSumPowY)
{
    double CorrDemo2{0};
    
    CorrDemo2 = sqrt((argN * argSumPowY) - pow(argSumY,2));

    return CorrDemo2;
}

/****************************************************************/
/****************************************************************/