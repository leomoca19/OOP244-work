/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: 31-July-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
#include "cstring.h"
#include <iostream>
namespace sdds {
    class Text {
        char* m_filename;
        char* m_content;
        int getFileLength() const; 
        void setEmpty();
    protected:
        const char& operator[](int index) const;
    public:
        Text(const char* filename = nullptr);
        Text(const Text& other); 
        Text& operator=(const Text& other); 
        ~Text(); 

        void read();
        virtual void write(std::ostream& os) const;

    };
    std::ostream& operator<<(std::ostream& os, const Text& text);
}
#endif // !SDDS_PERSON_H__

