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
#include "Publication.h"
using namespace std;
namespace sdds {
    void Publication::setEmpty()
    {
        delete[] m_title;
        m_title = nullptr;

        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        m_date.setToToday();
    }
    Publication::Publication() : m_title(nullptr), m_membership(0), m_libRef(-1), m_date() {
        m_shelfId[0] = '\0';
    }

    Publication::Publication(const Publication& other) : Publication() {
        *this = other;
    }
    Publication& Publication::operator=(const Publication& other) {
        if (this != &other) {
            delete[] m_title;
            m_title = nullptr;
            if (other.m_title) {
                m_title = new char[strLen(other.m_title) + 1];
                strCpy(m_title, other.m_title);
            }
            strCpy(m_shelfId, other.m_shelfId);
            m_membership = other.m_membership;
            m_libRef = other.m_libRef;
            m_date = other.m_date;
        }
        return *this;
    }

    Publication::~Publication() {
        delete[] m_title;
    }

    void Publication::set(int member_id) {
        m_membership = member_id; //check if enough
    }
    void Publication::setRef(int value) {
        m_libRef = value;
    }
    void Publication::resetDate() {
        m_date.setToToday();
    }

    char Publication::type() const {
        return 'P';
    }
    bool Publication::onLoan() const {
        return m_membership != 0;
    }
    Date Publication::checkoutDate() const {
        return m_date;
    }
    bool Publication::operator==(const char* title) const {
        return strStr(m_title, title) != nullptr;
    }
    Publication::operator const char* () const {
        return m_title;
    }
    int Publication::getRef() const {
        return m_libRef;
    }

    ostream& Publication::write(ostream& os) const {
        if (conIO(os)) {
            os << "| "  << m_shelfId << " | ";

            if (strLen(m_title) > SDDS_TITLE_WIDTH) {
                for (size_t i = 0; i < SDDS_TITLE_WIDTH; i++)
                    os << m_title[i];
            }
            else
                os << setfill('.') << left << setw(SDDS_TITLE_WIDTH)
                    << m_title;
            
            os << " | " << setfill(' ');

            if (m_membership) 
                os  << m_membership;
            else os << " N/A ";
            
            os << " | " << m_date << " |";
        }
        else {
            os << type() << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t" << m_membership << "\t" << m_date;
        }
        return os;
    }
    istream& Publication::read(istream& is) {
        Date date;
        char shelfId[256]{}, title[256]{};
        int membership{}, libRef = -1;

        setEmpty();

        if (conIO(is)) {
            cout << "Shelf No: ";
            is.getline(shelfId, SDDS_SHELF_ID_LEN + 1, '\n');
            if (strLen(shelfId) != SDDS_SHELF_ID_LEN) {
                is.setstate(ios::failbit);
            }

            cout << "Title: ";
            if (is) {
                is.getline(title, 255, '\n');
            }

            cout << "Date: ";
            if (is)
            {
                is >> date;
            }
        }
        else {
            is >> libRef;
            is.ignore();
            is.getline(shelfId, SDDS_SHELF_ID_LEN + 1, '\t');
            is.getline(title, 255, '\t');
            is >> membership;
            is.ignore();
            is >> date;
        }

        if (!date) {
            is.setstate(ios::failbit);
        }

        if (is) {
            m_title = new char[strLen(title) + 1];
            strCpy(m_title, title);

            strCpy(m_shelfId, shelfId);
            m_membership = membership;
            m_date = date;
            m_libRef = libRef;
        }

        return is;
    }
    bool Publication::conIO(ios& io) const {
        return (&io == &cin || &io == &cout);
    }
    Publication::operator bool() const {
        return m_title && m_title[0] != '\0' && m_shelfId[0] != '\0';
    }

    ostream& operator<<(ostream& os, const Publication& pub) {
        if(pub)
            pub.write(os);
        return os;
	}
	istream& operator>>(istream& istr, Publication& pub) {
		return pub.read(istr);
	}
}
