/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: 31-July-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include "HtmlText.h"
namespace sdds {
	HtmlText::HtmlText(const char* filename, const char* title) : Text(filename), m_title(nullptr) {
		if (title && title[0] != '\0') {
			m_title = new char[strLen(title) + 1];
			strCpy(m_title, title);
		}
	}
    HtmlText::HtmlText(const HtmlText& other) : Text(other), m_title(nullptr) {
        if (other.m_title) {
            m_title = new char[strLen(other.m_title) + 1];
            strCpy(m_title, other.m_title);
        }
    }
    HtmlText& HtmlText::operator=(const HtmlText& other) {
        if (this != &other) {
            Text::operator=(other);

            delete[] m_title;
            m_title = nullptr;

            if (other.m_title) {
                m_title = new char[strLen(other.m_title) + 1];
                strCpy(m_title, other.m_title);
            }
        }
        return *this;
    }
	HtmlText::~HtmlText() {
		delete[] m_title;
	}

	void HtmlText::write(std::ostream& os)const {
		bool MS = false;

		os << "<html><head><title>";

		if ((MS = m_title && m_title[0] != '\0')) 
			os << m_title;
		else os << "No Title";
		
		os << "</title></head>\n<body>\n";

		if (MS)
			os << "<h1>" << m_title << "</h1>\n";

        for (int i = 0; (*this)[i]; i++) {
            char ch = (*this)[i];
            switch (ch) {
            case ' ':
                if (MS) os << "&nbsp;";
                else {
                    MS = true;
                    os << " ";
                }
                break;
            case '<':
                os << "&lt;";
                MS = false;
                break;
            case '>':
                os << "&gt;";
                MS = false;
                break;
            case '\n':
                os << "<br />\n";
                MS = false;
                break;
            default:
                os << ch;
                MS = false;
            }
        }

		os << "</body>\n</html>";
	}
}