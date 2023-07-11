// Final Project Milestone 1 
// Module: Menu
// File	Menu.h
// Version 1.0
// Author	Leonardo de la Mora Caceres
// Revision History
// -----------------------------------------------------------
// Date         Reason
// 2023/July/8  Preliminary release
///////////////////////////////////////////////////////////////
#ifndef SDDS_DATE_H__
#define SDDS_DATE_H__
#include <iostream>
#include "Utils.h"
namespace sdds {
	const size_t MAX_MENU_ITEMS = 20;

	class MenuItem {
		char* m_content{};
		friend class Menu;

		MenuItem(const char* = nullptr);
		MenuItem& operator=(const char*);
		~MenuItem();
		void operator~();

		MenuItem(const MenuItem&) = delete;
		Menu& operator=(const MenuItem&) = delete;

		operator bool()const;
		operator const char* ()const;

		std::ostream& display(std::ostream& )const;
	};

	class Menu {
		MenuItem m_title{};
		MenuItem* m_itemArray[MAX_MENU_ITEMS]{};
		size_t m_itemArraySz{};
		
		Menu(const Menu&) = delete;
		Menu& operator=(const Menu&) = delete;

	public:

		Menu(const char* = nullptr);
		Menu& operator=(const char*);
		~Menu();
		void operator~();
	};
}
#endif