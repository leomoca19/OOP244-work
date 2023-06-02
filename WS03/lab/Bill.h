/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: 02-June-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/

#ifndef SDDS_BILL_H_
#define SDDS_BILL_H_
#include "Item.h"
namespace sdds {
   class Bill {
      char m_title[37] = {};
      Item* m_items = nullptr;
      int m_noOfItems = 0;
      int m_itemsAdded = 0;
      double totalTax()const;
      double totalPrice()const;
      void Title()const;
      void footer()const;
      void setEmpty();
      bool isValid()const;
   public:
      void init(const char* title, int noOfItems);
      bool add(const char* item_name, double price, bool taxed);
      void display()const;
      void deallocate();
   };
}
#endif // !SDDS_TRANSCRIPT_H
