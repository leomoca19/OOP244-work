/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: 25-May-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/

#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_

#include <iostream>
#include "File.h"


#define DATAFILE "employees.csv"
namespace sdds {
    struct Employee {
        char* m_name = nullptr;
        int m_empNo = 0;
        double m_salary = 0;
    };
    //sorts the dynamic array of employees based on the GPA of the employees.
    void sort();
    // loads a employee structue with its values from the file
    bool load(Employee* emp);
    // allocates the dyanmic array of employees and loads all the file
    // recoreds into the array
    bool load();

    // TODO: Declare the prototype for the display function that
    // displays a employee record on the screen:
    void display(const Employee*);

    // TODO: Declare the prototype for the display function that 
    // first sorts the employees then displays all the employees on the screen
    void display();

    // TODO: Declare the prototype for the deallocateMemory function that
    // first will deallocate all the names in the employee elements
    // then it will deallocate the employee array 
    void deallocateMemory();

    //deallocates argument name and sets to nullptr
    void clearName(char* name);
}
#endif // SDDS_EMPLOYEE_H_