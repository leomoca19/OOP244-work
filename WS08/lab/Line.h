/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: July-25-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#pragma once
#include "LblShape.h"
namespace sdds {
	class Line : public LblShape
	{
		int m_length;

	public:
		Line();
		Line(const char*, int );

		void getSpecs(std::istream&) ;
		virtual void draw(std::ostream&) const ;

	};

}