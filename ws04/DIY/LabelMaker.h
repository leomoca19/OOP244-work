/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: 09-June-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#pragma once
#include "Label.h"
namespace sdds {
	class LabelMaker
	{
		Label* m_labels = nullptr;
		unsigned short m_size = 0;

	public:
		LabelMaker(int noOfLabels);
		~LabelMaker();

		void readLabels();
		void printLabels();

	};
}