/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: 13-June-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
      void emptyFunds();
      void resetNumber();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;

      operator bool()const;
      operator int()const;
      operator double()const;
      bool operator~()const;

      Account& operator=(int);
      Account& operator=(Account&);
      Account& operator+=(double);
      Account& operator-=(double);
      Account& operator<<(Account&);
      Account& operator>>(Account&);
   };
   double operator+(const Account& l, const Account& r);
   double operator+=(double&, const Account&);
}
#endif // SDDS_ACCOUNT_H_