/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: 18-June-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#pragma once
#include <iostream>
namespace sdds {
	class Mark {
		size_t grade;
		bool valid;

		void setValid(int);
		void setInvalid();
	public:
		Mark();
		Mark(size_t);
		Mark& operator=(int);

		operator bool()const;
		operator char()const;
		operator int()const;
		operator double()const;

		Mark& operator+=(int);
	};
	int operator+=(int&, const Mark&);
	std::ostream& operator<<(const Mark&, std::ostream&);
}