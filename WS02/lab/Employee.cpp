/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: 25-May-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/#define  _CRT_SECURE_NO_WARNINGS
#include "Employee.h"
using namespace std;
namespace sdds {

   int noOfEmployees;
   Employee* employees = nullptr;

   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   // TODO: Finish the implementation of the 1 arg load function which
   // reads one employee record from the file and loads it into the employee reference
   // argument
   bool load(Employee* emp) {
      bool ok = false;
      char name[128] = {};
      double salary = 0;
      int empNo = 0;

      if (read(&empNo) && read(&salary) && read(name)) {
          clearName(emp->m_name);
          emp->m_name = new char[strLen(name) + 1];
          strCpy(emp->m_name, name);

          emp->m_salary = salary;
          emp->m_empNo = empNo;

          ok = true;
      }
      return ok;
   }
   // TODO: Finish the implementation of the 0 arg load function 
   bool load() {
      bool ok = false;
      int i = 0;
      if (openFile(DATAFILE)) {
          noOfEmployees = noOfRecords();
          employees = new Employee[noOfEmployees];
          while (i < noOfEmployees) {
              load(&employees[i]);
              i++;
          }

          if (i != noOfEmployees)
              cout << "Error: incorrect number of records read; the data is possibly corrupted";
          else ok = true;

          closeFile();
      }
      else {
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      return ok;
   }

   // TODO: Implementation for the display functions go here
   void display() {
       cout << "Employee Salary report, sorted by employee number\n"
           << "no- Empno, Name, Salary\n"
           << "------------------------------------------------\n";

       sort();
       for (int i = 0; i < noOfEmployees; i++){
           cout << i + 1 << "- ";
           display(&employees[i]);
       }
   }

   void display(const Employee* emp) {
       cout << emp->m_empNo << ": ";
       cout << emp->m_name << ", ";
       cout << emp->m_salary << '\n';
   }

   // TODO: Implementation for the deallocateMemory function goes here
   void deallocateMemory() {
       for(int i = noOfEmployees - 1; i > -1; i--) 
           clearName(employees[i].m_name);
       
       delete[] employees;
   }

   void clearName(char* name) {
        if (name)
            delete[] name;
        name = nullptr;
   }
}