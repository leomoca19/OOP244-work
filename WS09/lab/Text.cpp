/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: 31-July-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include <fstream>
#include "Text.h"
using namespace std;
namespace sdds {
    void Text::setEmpty() {
        delete[] m_filename;
        delete[] m_content;
        m_filename = m_content = nullptr;
    }

    Text::Text(const char* filename) : m_filename(nullptr), m_content(nullptr) {
        if (filename) {
            m_filename = new char[strLen(filename) + 1];
            strCpy(m_filename, filename);
            read();
        }
    }
    Text::Text(const Text& other) : m_filename(nullptr), m_content(nullptr) {
        *this = other;
    }
    Text& Text::operator=(const Text& other) {
        if (this != &other) {
            setEmpty();

            if (other.m_filename) {
                m_filename = new char[strLen(other.m_filename) + 1];
                strCpy(m_filename, other.m_filename);
            }

            if (other.m_content) {
                m_content = new char[strLen(other.m_content) + 1];
                strCpy(m_content, other.m_content);
            }
        }
        return *this;
    }
    Text::~Text() {
        delete[] m_filename;
        delete[] m_content;
    }

    void Text::read() {
        std::ifstream file(m_filename);
        if (file.is_open()) {
            int length = getFileLength();
            if (length > 0) {
                m_content = new char[length + 1];
                int i = 0;
                char ch;
                while (file.get(ch)) {
                    m_content[i++] = ch;
                }
                m_content[i] = '\0';
            }
        }
    }

    void Text::write(std::ostream& os) const {
        if (m_content) {
            os << m_content;
        }
    }

    const char& Text::operator[](int index) const {
        return m_content[index];
    }


   int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
   }

   std::ostream& operator<<(std::ostream& os, const Text& text) {
       text.write(os);
       return os;
   }
}