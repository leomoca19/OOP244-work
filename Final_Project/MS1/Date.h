// Final Project Milestone 1 
// Module: Date
// File	Date.h
// Version 1.0
// Author	Leonardo de la Mora Caceres
// Revision History
// -----------------------------------------------------------
// Date         Reason
// 2023/July/3  Preliminary release
///////////////////////////////////////////////////////////////
#ifndef SDDS_DATE_H__
#define SDDS_DATE_H__
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Utils.h"
namespace sdds {
   const int NO_ERROR = 0;
   const int CIN_FAILED = 1;
   const int YEAR_ERROR = 2;
   const int MON_ERROR = 3;
   const int  DAY_ERROR = 4;
   const char DATE_ERROR[5][16] = {
      "No Error",
      "cin Failed",
      "Bad Year Value",
      "Bad Month Value",
      "Bad Day Value"
   };
   const int  MIN_YEAR = 1500;

   class Date {
   private:
      int m_year;
      int m_mon;
      int m_day;
      int m_ErrorCode;
      int m_CUR_YEAR;

      // returns number of days passed since the date 0001/1/1
      int daysSince0001_1_1()const; 

      /* validates the date setting the error code and then returning the result true, if valid, and false if invalid.*/
      bool validate();

      // sets the error code
      void errCode(int);

      // returns the current system year
      int systemYear()const;

      // return true if the Date is in an erroneous state
      bool bad()const;

      // returns the number of days in current month
      int mdays()const;

      // sets the date to the current date (system date)
      void setToToday();
   public:
      // creates a date with current date
      Date();

      /* create a date with assigned values then validates the date and sets the error code accordingly */
      Date(int year, int mon, int day);

      // returns the error code or zero if date is valid
      int errCode()const;

      // returns a string corresponding the current status of the date
      const char* dateStatus()const;

      // returns the m_CUR_YEAR value;
      int currentYear()const;

      //reads a date from the console YYYY/MM/DD
      std::istream& read(std::istream& is = std::cin);

      //write the date or error status
      std::ostream& write(std::ostream& os = std::cout)const;

      bool operator==(const Date)const;
      bool operator!=(const Date)const;
      bool operator>=(const Date)const;
      bool operator<=(const Date)const;
      bool operator<(const Date)const;
      bool operator>(const Date)const;

      int operator-(const Date)const;

      operator bool()const;
   };
   std::ostream& operator<<(std::ostream& os, const Date& RO);
   std::istream& operator>>(std::istream& is, Date& RO);
}
#endif