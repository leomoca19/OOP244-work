// Final Project Milestone 1 
// Module: Menu
// File	Menu.cpp
// Version 1.0
// Author	Leonardo de la Mora Caceres
// Revision History
// -----------------------------------------------------------
// Date         Reason
// 2023/July/8  Preliminary release
///////////////////////////////////////////////////////////////
#include "Menu.h"
namespace sdds {
	MenuItem::MenuItem(const char* content)
	{
			*this = content;
	}
	MenuItem& MenuItem::operator=(const char* content)
	{
		~*this;

		if (content)
		{
			m_content = new char[strlen(content) + 1];
			strCpy(m_content, content);
		}

		return *this;
	}
	MenuItem::~MenuItem()
	{
		~*this;
	}
	void MenuItem::operator~()
	{
		delete[]m_content;
	}

	MenuItem::operator bool() const
	{
		return m_content && m_content[0] != '\0';
	}
	MenuItem::operator const char* () const
	{
		return m_content;
	}
	std::ostream& MenuItem::display(std::ostream& ostr) const
	{
		if (*this)
			ostr << m_content;

		return ostr;
	}


	Menu::Menu(const char* title)
	{
		*this = title;
	}

	Menu& Menu::operator=(const char* title)
	{
		delete[] m_title;
		if (title) 
			m_title = title;

		return *this;
	}

	Menu::~Menu()
	{
		~*this;
	}

	void Menu::operator~()
	{
		delete[] m_title;

		for (size_t i = m_itemArraySz; i > 0; i--)
			delete m_itemArray[i - 1];
	}

}