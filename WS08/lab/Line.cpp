/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: July-25-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include "Line.h"
using namespace std;
namespace sdds {
	Line::Line() : LblShape(), m_length(0) {}
	Line::Line(const char* label, int length) : LblShape(label), m_length(length) {}

	std::istream& Line::getSpecs(std::istream& is)
	{
		LblShape::getSpecs(is);
		is >> m_length;
		is.ignore(999, '\n');
		return is;
	}
	ostream& Line::draw(std::ostream& os) const
	{
		if (m_length > 0 && label()) {
			os << label() << '\n';
			for (int i = 0; i < m_length; i++)
				os << '=';
			os << '\n';
		}
		return os;
	}
}