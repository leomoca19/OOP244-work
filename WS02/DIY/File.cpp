#define _CRT_SECURE_NO_WARNINGS
#include "File.h"
namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }

   bool read(char* pCode) {
       int i = 0;
       while (i += fscanf(fptr, "%c", &pCode[i]));
       return i == 3;
   }
   bool read(int* popNum) {
       return fscanf(fptr, "%d\n", popNum) == 1;
   }
}