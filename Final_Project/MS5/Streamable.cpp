// Final Project Milestone 3 
// Module: Publication
// File	Publication.h
// Version 1.0
// Author	Leonardo de la Mora Caceres
// Revision History
// -----------------------------------------------------------
// Date         Reason
// 2023/August/1  Preliminary release
///////////////////////////////////////////////////////////////
#include "Streamable.h"
using namespace std;
namespace sdds {
	std::ostream& operator<<(std::ostream& os, const Streamable& obj) {
		if(obj)
		{
			obj.write(os);
		}
		return os;
	}
	std::istream& operator>>(std::istream& is, Streamable& obj) {
		return obj.read(is);
	}
}