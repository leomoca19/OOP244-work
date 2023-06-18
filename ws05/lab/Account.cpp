/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: 13-June-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   void Account::emptyFunds()
   {
       m_balance = 0;
   }
   void Account::resetNumber() {
       m_number = 0;
   }

   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   Account::operator bool() const
   {
       return m_number > 0;
   }
   Account::operator int() const
   {
       return m_number;
   }
   Account::operator double() const
   {
       return m_balance;
   }
   bool Account::operator~()const
   {
       return m_number == 0;
   }

   Account& Account::operator=(int accNumber)
   {
       if (~*this) {
           if (accNumber > 0)
               m_number = accNumber;
           else if (accNumber < 0)
               setEmpty();
       }
       return *this;
   }
   Account& Account::operator=(Account& A)
   {
       if (~*this && A) {
           m_number = int(A);
           m_balance = double(A);
           A.emptyFunds();
           A.resetNumber();
       }
       return  *this;
   }
   Account& Account::operator+=(double balance)
   {
       if (*this && balance > 0) {
           m_balance += balance;
       }
       return *this;
   }
   Account& Account::operator-=(double balance)
   {
       if (*this && balance > 0 && double(*this) >= balance) {
           m_balance -= balance;
       }
       return *this;
   }
   Account& Account::operator<<(Account& A)
   {
       if (this != &A) {
           *this += double(A);
           A.emptyFunds();
       }
       return *this;
   }
   Account& Account::operator>>(Account& A)
   {
       return A << *this;
   }

   double operator+(const Account& l, const Account& r)
   {
       double sum = 0;
       if (l && r)
           sum = double(l) + double(r);
       return sum;
   }
   double operator+=(double& sum, const Account& r)
   {
       return sum += double(r);
   }
}