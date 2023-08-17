/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: July-23-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#pragma once
#include "LblShape.h"
namespace sdds {
	class Rectangle : public LblShape {
		int m_width;
		int m_height;

	public:
		Rectangle();
		Rectangle(const char* label, int width, int height);

		void getSpecs(std::istream& is) ;
		void draw(std::ostream& os) const ;
	};
}