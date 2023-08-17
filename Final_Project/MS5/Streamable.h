// Final Project Milestone 3 
// Module: Streamable
// File	Streamable.h
// Version 1.0
// Author	Leonardo de la Mora Caceres
// Revision History
// -----------------------------------------------------------
// Date         Reason
// 2023/August/1  Preliminary release
///////////////////////////////////////////////////////////////
#pragma once
#include <iostream>
namespace sdds {
    class Streamable {
    public:
        virtual bool conIO(std::ios& io) const = 0;
        virtual std::ostream& write(std::ostream& os) const = 0;
        virtual std::istream& read(std::istream& istr) = 0;
        virtual operator bool() const = 0;
        virtual ~Streamable() {}
    };

    std::ostream& operator<<(std::ostream& os, const Streamable& obj);
    std::istream& operator>>(std::istream& is, Streamable& obj);
}