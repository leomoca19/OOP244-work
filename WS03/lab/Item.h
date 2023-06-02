/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: 02-June-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
#include <iostream>
#include "cstring.h"
namespace sdds {
   const double TAX = 0.13;
   class Item {
      char m_itemName[21] = {};
      double m_price = 0;
      bool m_taxed = false;
      void setName(const char* name);
   public:
      void setEmpty();
      void set(const char* name, double price, bool taxed);
      void display()const;
      bool isValid()const;
      double price()const;
      double tax()const;
      bool taxed();
   };
}

#endif // !SDDS_SUBJECT_H
