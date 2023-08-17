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
#pragma once
#include "Streamable.h"
#include "Date.h"
#include "Lib.h"
#include "Utils.h"
namespace sdds {
	class Publication : public Streamable {
        char* m_title;
        char m_shelfId[SDDS_SHELF_ID_LEN + 1];
        int m_membership;
        int m_libRef;
        Date m_date;

        void setEmpty();
    public:
        Publication();
        Publication(const Publication& other);
        Publication& operator=(const Publication& other);
        virtual ~Publication();

        virtual void set(int member_id);
        void setRef(int value);
        void resetDate();

        virtual char type() const;
        bool onLoan() const;
        Date checkoutDate() const;
        bool operator==(const char* title) const;
        operator const char* () const;
        int getRef() const;

        virtual std::ostream& write(std::ostream& os = std::cout) const override;
        virtual std::istream& read(std::istream& is = std::cin) override ;
        virtual bool conIO(std::ios& io) const override ;
        virtual operator bool() const override ;
	};
    std::ostream& operator<<(std::ostream& os, const Publication& pub);
    std::istream& operator>>(std::istream& istr, Publication& pub);
}