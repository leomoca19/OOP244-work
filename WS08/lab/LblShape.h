/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: July-23-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#pragma once
#include <cstring>
#include "Shape.h" // Include the base Shape class header if available
namespace sdds {
    class LblShape : public Shape {
        char* m_label{};

    protected:
        const char* label() const;

    public:
        LblShape();
        LblShape(const char*);
        ~LblShape();

        LblShape(LblShape&) = delete;
        LblShape& operator=(LblShape& l) = delete;

        virtual void getSpecs(std::istream&) override;
    };
}