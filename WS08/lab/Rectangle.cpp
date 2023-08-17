/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: July-23-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include "Rectangle.h"
using namespace std;
namespace sdds {
	Rectangle::Rectangle(): m_width(0), m_height(0) {}
	Rectangle::Rectangle(const char* label, int width, int height)
		: LblShape(label), m_width(0), m_height(0)
	{
        int comp = strlen(this->label()) + 2;
        if (m_height < 3 || m_width < comp)
			m_width = m_height = 0;
	}

    void Rectangle::getSpecs(std::istream& is) {
        LblShape::getSpecs(is);
        is.ignore(); // Ignore the comma
        is >> m_width;
        is.ignore(); // Ignore the comma
        is >> m_height;
        is.ignore(99, '\n');
    }

    void Rectangle::draw(std::ostream& os) const {
        if (m_width > 0 && m_height > 0 && label() != nullptr) {
            // First line
            os << '+';
            for (int i = 0; i < m_width - 2; i++) {
                os << '-';
            }
            os << '+' << std::endl;

            // Second line
            os << '|';
            os.width(m_width - 2);
            os << std::left << label();
            os << '|' << std::endl;

            // Next lines
            for (int i = 0; i < m_height - 3; i++) {
                os << '|';
                os.width(m_width - 2);
                os << std::right << ' ';
                os << '|' << std::endl;
            }

            // Last line
            os << '+';
            for (int i = 0; i < m_width - 2; i++) {
                os << '-';
            }
            os << '+' << std::endl;
        }
    }
}