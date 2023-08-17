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
#include "Publication.h"
namespace sdds {
   class LibApp {
       Menu m_mainMenu;
       Menu m_pubMenu;
       Menu m_exitMenu;
       Publication* m_PPA[SDDS_LIBRARY_CAPACITY]{};
       size_t m_noOfLoadedPubs;
       bool m_changed;
       char m_filename[256];
       int m_lastLib;

       void load();  // prints: "Loading Data"<NEWLINE>
       void save();  // prints: "Saving Data"<NEWLINE>
       size_t search(size_t searchType = 1);//1=all|2=loaned|3=avaliable

       void returnPub();  /*  Calls the search() method.
                              prints "Returning publication"<NEWLINE>
                              prints "Publication returned"<NEWLINE>
                              setsx m_changed to true;
                          */

   public:
       LibApp(const char* filename);
       ~LibApp();

       bool confirm(const char* message);
       void newPublication();
       void removePublication();
       void checkOutPub();

       Publication* getPub(int libRef) const;

       void run();
   };
}
#endif // !SDDS_LIBAPP_H
