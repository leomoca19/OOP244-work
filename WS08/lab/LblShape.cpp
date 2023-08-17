/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: July-25-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"
using namespace std;
namespace sdds {
	const char* LblShape::label() const
	{
		return m_label;
	}

	LblShape::LblShape() : m_label(nullptr){}
	LblShape::LblShape(const char* label) : m_label(nullptr) {
		if (label) {
			m_label = new char[strlen(label) + 1];
			strcpy(m_label, label);
		}
	}
	LblShape::~LblShape()
	{
		delete[] m_label;
		m_label = nullptr;
	}

	istream& LblShape::getSpecs(std::istream& is) {
		char buffer[256];
		is.getline(buffer, 256, ',');
		if (m_label) {
			delete[] m_label;
			m_label = nullptr;
		}
		m_label = new char[strlen(buffer) + 1];
		strcpy(m_label, buffer);
	return is;
	}

	
}