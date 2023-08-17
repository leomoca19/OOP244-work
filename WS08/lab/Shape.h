/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: July-23-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#pragma once
#include <iostream>
namespace sdds {
	class Shape {
	public:
		virtual void draw(std::ostream&) const = 0;
		virtual void getSpecs(std::istream&) = 0;
		virtual ~Shape() = default;
	};
	std::ostream& operator<<(std::ostream&, const Shape&);
	std::istream& operator>>(std::istream&, Shape&);
}