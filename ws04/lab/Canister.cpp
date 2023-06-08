/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: 07-June-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
using namespace std;
namespace sdds {
    const double PI = 3.14159265;

    void Canister::setToDefault(){
        m_height = 13;
        m_diameter = 10;
        clear();
    }
    void Canister::setName(const char* Cstr){ 
        if (Cstr && m_usable) {
            clear();
            m_contentName = new char[strLen(Cstr) + 1];
            strCpy(m_contentName, Cstr);
        }
    }
    bool Canister::isEmpty()const{ return m_contentVolume < 0.00001; }
    bool Canister::hasSameContent(const Canister& C)const {
        bool check = false;
        if(m_contentName && C.m_contentName);
            check = strCmp(m_contentName, C.m_contentName);
        return check;
    }

    Canister::Canister(){ setToDefault(); }
    Canister::Canister(const char* contentName) {
        setToDefault();
        setName(contentName);
    }
    Canister::Canister(double height, double diameter,
        const char* contentName) {
        setToDefault();
        if (height >= 10 && height <= 40 &&
            diameter >= 10 && diameter <= 30) {
            m_height = height;
            m_diameter = diameter;
            setName(contentName);
        }
        else m_usable = false;
    }
    Canister::~Canister(){ clear(); }

    Canister& Canister::setContent(const char* contentName) {
        if (!contentName)
            m_usable = false;
        else if (isEmpty())
            setName(contentName);
        else if(strCmp(m_contentName, contentName))
            m_usable = false;
        return *this;
    }
    Canister& Canister::pour(double quantity) {
        if (m_usable && quantity > 0 &&
            (quantity + volume()) <= capacity())
            m_contentVolume += quantity;
        else m_usable = false;

        return *this;
    }
    Canister& Canister::pour(Canister& C) {
        setContent(C.m_contentName);
        if (C.volume() > capacity() - volume()) {//check if capacity and volume are of the argument
            C.m_contentVolume -= capacity() - volume();
            m_contentVolume = capacity();
        }
        else {
            pour(C.m_contentVolume);
            C.m_contentVolume = 0;
        }
        return *this;
    }
    double Canister::volume()const { return m_contentVolume; }
    std::ostream& Canister::display()const{
        cout.setf(ios::fixed);
        cout.setf(ios::right);

        cout.width(7);
        cout.precision(1);
        cout << capacity();

        cout << "cc (";
        cout.precision(1);
        cout << m_height;

        cout << 'x';

        cout.precision(1);
        cout << m_diameter;

        cout << ") Canister";

        if (!m_usable)
            cout << " of Unusable content, discard!"; 
        else if(m_contentName) {
            cout << " of ";

            cout.width(7);
            cout.precision(1);
            cout << volume();

            cout << "cc   ";

            cout << m_contentName;
        }
            

        cout.unsetf(ios::right);
        cout.unsetf(ios::fixed);
        return cout;
    }
    double Canister::capacity()const{ 
        return PI * (m_height - .267) * (m_diameter / 2) * (m_diameter / 2);
    }
    void Canister::clear(){
        if (m_contentName)
            delete[] m_contentName;
        m_contentName = nullptr;
        m_contentVolume = 0;
        m_usable = true;
    }
}