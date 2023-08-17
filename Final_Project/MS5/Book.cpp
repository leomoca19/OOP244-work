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
#include "Book.h"
#include "Utils.h"
using namespace std;
namespace sdds{
	Book::Book() : Publication(), m_author{} {}

	Book::Book(const Book& src)
	{
		*this = src;
	}

	Book& Book::operator=(const Book& src) 
	{
		if (this != &src) {
			Publication::operator=(src);

			delete[] m_author;
			m_author = nullptr;
			if (src) {
				m_author = new char[strLen(src.m_author) + 1];
				strCpy(m_author, src.m_author);
			}
		}
		return *this;
	}

	Book::~Book()
	{
		delete[] m_author;
	}

	char Book::type() const
	{
		return 'B';
	}

	std::ostream& Book::write(std::ostream& os) const
	{
		Publication::write(os);
		if (conIO(os)) {
			os << ' ';
			if (strLen(m_author) > SDDS_AUTHOR_WIDTH) {
				for (size_t i = 0; i < SDDS_AUTHOR_WIDTH; i++)
					cout << m_author[i];
			}
			else {
				os << left<< setw(SDDS_AUTHOR_WIDTH) << setfill(' ') << m_author;
			}
			os << " |";
		}
		else {
			os << '\t' << m_author;
		}

		return os;
	}

	std::istream& Book::read(std::istream& is)
	{
		char author[255 + 1]{};
		delete[] m_author;
		m_author = nullptr;

		Publication::read(is);
		if (conIO(is)) {
			cout << "Author: ";
			if(is){
				is.ignore(1, '\n'); 
				is.getline(author, 255, '\n');
			}
		}
		else {
			is.ignore(1, '\t');
			is.getline(author, 255, '\n');
			is.putback('\n');
		}

		if (is) {
			m_author = new char[strLen(author) + 1];
			strCpy(m_author, author);
		}

		return is;
	}

	void Book::set(int member_id)
	{
		Publication::set(member_id);
		resetDate();
	}

	Book::operator bool() const
	{
		return Publication::operator bool() && m_author != nullptr && m_author[0] != '\0';
	}


}
