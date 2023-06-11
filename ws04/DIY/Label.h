/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: 09-June-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#pragma once
#include "cstring.h"
#include <iostream>
namespace sdds {
	class Label {
		unsigned short m_size = 0;
		char m_frame[9]{};
		char* m_content = nullptr;

		void setContent(const char*);
		void setFrame(const char*);

	public:	
		Label();
		Label(const char*);
		Label(const char* frame, const char* content);
		~Label();
		void clear();

		void readLabel();
		std::ostream& printLabel()const;
	};
}

