/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: July-20-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include "Truck.h"
using namespace std;
namespace sdds {
	Truck::Truck(
		const char* plate,
		const size_t year,
		const double capacity,
		const char* address
	): MotorVehicle(plate, year), m_capacity(capacity), m_cargo(0)
	{
		moveTo(address);
	}

	bool Truck::addCargo(double cargo)
	{
		//bool check{};
		bool check = (cargo + m_cargo <= m_capacity) ? 1 : 0;

		/*if (check = (cargo + m_cargo <= m_capacity))
			m_cargo += cargo;*/
		(check) ? m_cargo += cargo : 0;

		//return (check) ? m_cargo += cargo : 0;
		return check;

	}

	bool Truck::unloadCargo()
	{
		bool check = (m_cargo = 0); //to be checked
		return check;
	}

	ostream& Truck::write(ostream& os) const
	{
		MotorVehicle::write(os);

		os	<< " | [" << m_cargo << "]/[" << m_capacity << "]\n";

		return os;
	}
	istream& Truck::read(istream& in)
	{
		MotorVehicle::read(in);
			
		cout << "Capacity: ";
		in >> m_capacity;

		cout << "Cargo: ";
		in >> m_cargo;

		return in;
	}
	std::ostream& operator<<(std::ostream& os, const Truck& T)
	{
		return T.write(os);
	}
	std::istream& operator>>(std::istream& in, Truck& T)
	{
		return T.read(in);
	}
}