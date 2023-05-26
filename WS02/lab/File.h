/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: 25-May-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
#include <cstdio>
#include "cstring.h" // implemented in workshop 1 part 2 (DIY)

namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   // TODO: Declare read prototypes
   bool read(char*);
   bool read(int*);
   bool read(double*);
}
#endif // !SDDS_FILE_H_
