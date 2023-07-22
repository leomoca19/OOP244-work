// Final Project Milestone 2 
// Module: Menu
// File	LibApp.cpp
// Version 1.0
// Author	Leonardo de la Mora Caceres
// Revision History
// -----------------------------------------------------------
// Date         Reason
// 2023/July/17  Preliminary release
///////////////////////////////////////////////////////////////
#include "LibApp.h"
using namespace std;
namespace sdds {
	void LibApp::load()
	{
		cout << "Loading Data\n";
	}
	void LibApp::save()
	{
		cout << "Saving Data\n";
	}
	void LibApp::search()
	{
		cout << "Searching for publication\n";
	}
	void LibApp::returnPub()
	{
		search();
		cout << "Returning publication\n" << "Publication returned\n";
		m_changed = 1;
	}
	LibApp::LibApp()
	{
		m_changed = false;
		load();

		m_mainMenu = "Seneca Library Application";
		m_mainMenu 
			<< "Add New Publication" 
			<< "Remove Publication" 
			<< "Checkout publication from library" 
			<< "Return publication to library";		

		m_exitMenu = "Changes have been made to the data, what would you like to do?";
		m_exitMenu 
			<< "Save changes and exit" 
			<< "Cancel and go back to the main menu";
	}
	bool LibApp::confirm(const char* message)
	{
		Menu menu(message);

		menu << "Yes";

		return menu.run();
	}
	void LibApp::newPublication()
	{
		cout << "Adding new publication to library\n";
		if (confirm("Add this publication to library?")) {
			cout << "Publication added\n";
			m_changed = true;
		}
	}
	void LibApp::removePublication()
	{
		cout << "Removing publication from library\n";
		search();
		if (confirm("Remove this publication from the library?")) {
			cout << "Publication removed\n";
			m_changed = true;
		}
	}
	void LibApp::checkOutPub()
	{
		search();
		if (confirm("Check out publication?")) {
			cout << "Publication checked out\n";
			m_changed = true;
		}

	}
	void LibApp::run()
	{
		size_t answer{};
		bool done{};

		while (!done){
			done = 0;
			answer = m_mainMenu.run();

			switch (answer)
			{
			case 0:
				if (m_changed)
				{
					answer = m_exitMenu.run();
					if (answer == 1) {
						save();
						done = 1;
					}
					else if (answer == 2) done = 0;
					else done = confirm("This will discard all the changes are you sure?");
					
				}
				else done = 1; 
				break;
			case 1: newPublication(); break;
			case 2: removePublication(); break;
			case 3: checkOutPub(); break;
			case 4: returnPub(); break;
			default: cout << "\nAnswer is corrupted\n"; break;
			}

			cout << '\n';
		}

		cout << "-------------------------------------------\n"
			<< "Thanks for using Seneca Library Application\n";
	}
}
