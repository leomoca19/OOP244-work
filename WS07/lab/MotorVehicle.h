/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: July-20-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#pragma once
#include <iostream>
#include "cstring.h"
namespace sdds{
	class MotorVehicle
	{
		char m_plate[8 + 1]{};
		char m_address[64 + 1]{};
		size_t m_yearBuilt;

	public:
		MotorVehicle(const char* plate, const size_t year);

		void moveTo(const char* address);

		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const MotorVehicle&);
	std::istream& operator>>(std::istream& in, MotorVehicle&);
}
