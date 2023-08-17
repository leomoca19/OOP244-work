/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: July-23-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include "Shape.h"
using namespace std;
namespace sdds{
    ostream& operator<<(ostream& os, const Shape& S)
    {
        return S.draw(os);
    }
    istream& operator>>(istream& is, Shape& S)
    {
        return S.getSpecs(is);
    }
}