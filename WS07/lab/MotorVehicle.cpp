/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: July-20-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include "MotorVehicle.h"
using namespace std;
namespace sdds{
	MotorVehicle::MotorVehicle(const char* plate, const size_t year) : m_yearBuilt(year)
	{
		strCpy(m_plate, plate);
		strCpy(m_address, "Factory");
	}

	void MotorVehicle::moveTo(const char* address)
	{
		if (strCmp(m_address, address)) {//check if != 0 is needed
			
			cout.setf(ios::fixed);
			cout.setf(ios::right);

			cout << "|";
			cout.width(8);
			cout << m_plate << "| |";

			cout.width(20);
			cout << m_address << " ---> ";

			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout.width(20);
			cout << address << "|\n";

			strCpy(m_address, address);

			cout.unsetf(ios::fixed);
		}
	}

	ostream& MotorVehicle::write(ostream & os) const
	{
		return os << "| " << m_yearBuilt << " | " << m_plate << " | " << m_address/* << "\n"*/;
	}
	istream& MotorVehicle::read(istream& in) {
		cout << "Built year: ";
		in >> m_yearBuilt;
		cout << "License plate: ";
		in >> m_plate;
		cout << "Current location: ";
		in >> m_address;

		return in;
	}

	std::ostream& operator<<(std::ostream& os, const MotorVehicle& M)
	{
		return M.write(os);
	}
	std::istream& operator>>(std::istream& in, MotorVehicle& M)
	{
		return M.read(in);
	}

}
