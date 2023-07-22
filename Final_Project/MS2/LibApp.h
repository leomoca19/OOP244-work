// Final Project Milestone 2 
// Module: Menu
// File	LibApp.h
// Version 1.0
// Author	Leonardo de la Mora Caceres
// Revision History
// -----------------------------------------------------------
// Date         Reason
// 2023/July/17  Preliminary release
///////////////////////////////////////////////////////////////
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
namespace sdds {
   class LibApp {
       bool m_changed;
       Menu m_mainMenu;
       Menu m_exitMenu;

       void load();  // prints: "Loading Data"<NEWLINE>
       void save();  // prints: "Saving Data"<NEWLINE>
       void search();  // prints: "Searching for publication"<NEWLINE>

       void returnPub();  /*  Calls the search() method.
                              prints "Returning publication"<NEWLINE>
                              prints "Publication returned"<NEWLINE>
                              setsx m_changed to true;
                          */

   public:
       LibApp();

       bool confirm(const char* message);
       void newPublication();
       void removePublication();
       void checkOutPub();

       void run();
   };
}
#endif // !SDDS_LIBAPP_H
