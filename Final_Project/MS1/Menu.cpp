// Final Project Milestone 1 
// Module: Menu
// File	Menu.cpp
// Version 1.0
// Author	Leonardo de la Mora Caceres
// Revision History
// -----------------------------------------------------------
// Date         Reason
// 2023/July/14  Preliminary release
///////////////////////////////////////////////////////////////
#include "Menu.h"
using namespace std;
namespace sdds {
	MenuItem::MenuItem(const char* content)
	{
			*this = content;
	}
	MenuItem& MenuItem::operator=(const char* content)
	{
		clearContent();

		if (content)
		{
			m_content = new char[strLen(content) + 1];
			strCpy(m_content, content);
		}

		return *this;
	}
	MenuItem::~MenuItem()
	{
		clearContent();
	}
	void MenuItem::clearContent()
	{
		if(m_content)
			delete[] m_content;
		m_content = nullptr;
	}

	MenuItem::operator bool() const
	{
		return m_content && m_content[0] != '\0';
	}
	MenuItem::operator const char* () const
	{
		return m_content;
	}

	ostream& MenuItem::display(ostream& ostr) const
	{
		if (*this)
			ostr << m_content;

		return ostr;
	}
	ostream& operator<<(ostream& os, const MenuItem& menuitem)
	{
		return menuitem.display(os);
	}

	ostream& Menu::display(ostream& ostr) const
	{
		if (m_title)
			ostr << *this << ":\n";

		for (size_t i = 0; i < m_itemArraySz; i++)
		{
			ostr << ' ' << i + 1 << "- ";
			m_itemArray[i]->display(ostr) << '\n';
		}

		ostr << " 0- Exit\n"
				"> ";
		

		return ostr;
	}

	ostream& Menu::displayName(ostream& ostr) const
	{
		return m_title.display(ostr);
	}

	Menu::Menu(const char* title)
	{
		*this = title;

		for (size_t i = 0; i < MAX_MENU_ITEMS; i++)
			m_itemArray[i] = nullptr;
	}
	Menu& Menu::operator=(const char* title)
	{
		m_title.clearContent();

		if (title) 
			m_title = title;

		return *this;
	}
	Menu::~Menu()
	{
		m_title.clearContent();

		for (size_t i = m_itemArraySz; i > 0; i--)
		{
			delete m_itemArray[i - 1];
			m_itemArray[i - 1] = nullptr;
		}
	}

	int Menu::operator~()
	{
		return run();
	}

	int Menu::run()
	{
		int selection = -1;
		bool repeat;

		do{
			repeat = false;
			display(cout); 

			while (!(cin >> selection) || selection < 0 || selection > (int)m_itemArraySz) {
				cout << "Invalid Selection, try again: ";
				cin.clear();
				cin.ignore(999, '\n');
			}

		} while (repeat);

		return selection;
	}
	Menu& Menu::operator<<(const char* menuitemContent)
	{
		if (m_itemArraySz < MAX_MENU_ITEMS)
		{
			m_itemArray[m_itemArraySz] = new MenuItem(menuitemContent);
			m_itemArraySz++;
		}

		return *this;
	}
	const char* Menu::operator[](size_t index) const
	{
		const char* returnVal = nullptr;
		if (m_itemArraySz > 0)
		{
			index %= m_itemArraySz; 
			returnVal = *m_itemArray[index];
		}

		return returnVal;
	}

	Menu::operator int() const
	{
		return (int)m_itemArraySz;
	}
	Menu::operator unsigned int() const
	{
		return (unsigned int)m_itemArraySz;
	}
	Menu::operator bool() const
	{
		return m_itemArraySz > 0;
	}

	ostream& operator<<(ostream& os, const Menu& menu)
	{
		return menu.displayName(os);
	}
}