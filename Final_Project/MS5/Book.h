// Final Project Milestone 4
// Module: Book
// File	Date.h
// Version 1.0
// Author	Leonardo de la Mora Caceres
// Revision History
// -----------------------------------------------------------
// Date         Reason
// 2023/August/9  Preliminary release
///////////////////////////////////////////////////////////////
#pragma once
#include "Publication.h"
namespace sdds {
	class Book : public Publication {
		char* m_author;

	public:
		Book();
		Book(const Book& src);
		Book& operator=(const Book& src);
		~Book();

		virtual char type() const;
		virtual std::ostream& write(std::ostream& os = std::cout) const;
		virtual std::istream& read(std::istream& is = std::cin);
		virtual void set(int member_id);
		virtual operator bool() const;


		/*char recID() const;
		void checkIn();
		void checkOut();
		bool operator==(const char* title) const;
		bool operator==(const Book& src) const;
		std::istream& read(std::istream& is = std::cin);
		std::ostream& write(std::ostream& os = std::cout) const;*/
	};
}