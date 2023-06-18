/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: 18-June-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include "Mark.h"
using namespace std;
namespace sdds {
	void Mark::setValid(int val)
	{
		grade = val;
		valid = true;
	}
	void Mark::setInvalid()
	{
		grade = 0;
		valid = false;
	}

	Mark::Mark() : Mark(0) {}
	Mark::Mark(size_t val) {
		if (val >= 0 && val <= 100)
			setValid(val);
		else setInvalid();
	}
	Mark& Mark::operator=(int val)
	{
		if (val >= 0 && val <= 100)
			setValid(val);
		else setInvalid();
		return *this;
	}

	Mark::operator bool() const
	{
		return valid;
	}
	Mark::operator char() const
	{
		char returnChar;
		size_t _grade = int(*this);

		if (!*this)
			returnChar = 'X';
		else if (_grade < 50)
			returnChar = 'F';
		else if (_grade < 60)
			returnChar = 'D';
		else if (_grade < 70)
			returnChar = 'C';
		else if (_grade < 80)
			returnChar = 'B';
		else
			returnChar = 'A';
		return returnChar;
	}
	Mark::operator int() const
	{
		size_t returnVal = 0;
		if (*this)
			returnVal = grade;
		return returnVal;
	}
	Mark::operator double() const
	{
		size_t gpa, _grade = int(*this);
		if (_grade < 50)
			gpa = 0;
		else if (_grade < 60)
			gpa = 1;
		else if (_grade < 70)
			gpa = 2;
		else if (_grade < 80)
			gpa = 3;
		else gpa = 4;
		return gpa;
	}

	Mark& Mark::operator+=(int val)
	{
		if (*this && grade + val <= 100)
			grade += val;
		else setInvalid();
		return *this;
	}

	int operator+=(int& val, const Mark& M)
	{
		if (M)
			val += int(M);
		return val;
	}
	ostream& operator<<(const Mark& M, ostream& O)
	{
		O << int(M);
		return O;
	}
}