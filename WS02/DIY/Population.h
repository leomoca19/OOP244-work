/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: 29-May-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
#include "File.h"
#include "cstring.h"
namespace sdds {
	 struct Population {
		 char postalCode[4] = {};
		unsigned popNum = 0;
		
		void load(Population);
	 };

	//Loads data from a file, returns true if data was successfully loaded, 
	//receives the file name
	bool load(const char*);

	void sort();

	//Prints the report header
	void display();

	//deallocate all dynamic memory used by the program
	void deallocateMemory();
}
#endif // SDDS_POPULATION_H_