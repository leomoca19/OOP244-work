#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
#include <cstdio>
#include <iostream>
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool read(char* pCode);
   bool read(int* popNum);
}
#endif // !SDDS_FILE_H_
