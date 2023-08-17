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

	bool Truck::addCargo(double cargo) {
		bool cargoAdded = false;
		if(!*this) {
			if ((m_cargo + cargo) <= m_capacity)
				m_cargo += cargo;
			else m_cargo = m_capacity;

			cargoAdded = true;
		}
		return cargoAdded;
	}
	bool Truck::unloadCargo()
	{
		//bool check = (m_cargo = 0); //to be checked
		bool check{};

		if ((check = (m_cargo > 0)))
			m_cargo = 0;

		return check;
	}

	ostream& Truck::write(ostream& os) const
	{
		return MotorVehicle::write(os) << " | " << m_cargo << "/" << m_capacity;
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
	Truck::operator bool() const
	{
		return m_capacity == m_cargo;
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