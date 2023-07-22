/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: July-20-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#pragma once
#include "MotorVehicle.h"
namespace sdds {
	class Truck: public MotorVehicle{
		double m_capacity;
		double m_cargo;

		public:

		Truck(const char* plate, const size_t year, const double capacity, const char* address);
		
		bool addCargo(double cargo);
		bool unloadCargo();

		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const Truck&);
	std::istream& operator>>(std::istream& in, Truck&);
}