// Final Project Milestone 1 
// Module: Menu
// File	Menu.h
// Version 1.0
// Author	Leonardo de la Mora Caceres
// Revision History
// -----------------------------------------------------------
// Date         Reason
// 2023/July/14  Preliminary release
///////////////////////////////////////////////////////////////
#pragma once
#include "Utils.h"
namespace sdds {
	const size_t MAX_MENU_ITEMS = 20;

	class MenuItem {
		char* m_content{};
		friend class Menu;

		MenuItem(const char* = nullptr);
		MenuItem& operator=(const char*);
		~MenuItem();
		void clearContent();

		MenuItem(const MenuItem&) = delete;
		MenuItem& operator=(const MenuItem&) = delete;

		operator bool()const;
		operator const char* ()const;

	public:
		std::ostream& display(std::ostream&)const;
	};
	std::ostream& operator<<(std::ostream&, const MenuItem&);

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

		std::ostream& display(std::ostream& = std::cout)const;
		std::ostream& displayName(std::ostream& = std::cout)const;

		int operator~();
		int run();
		Menu& operator<<(const char*);
		const char* operator[](size_t index) const;

		operator int() const;
		operator unsigned int() const;
		operator bool() const;

		
	};
	std::ostream& operator<<(std::ostream& os, const Menu& menu);
}
