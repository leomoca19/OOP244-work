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
#include <fstream>
#include <iostream>
#include "LibApp.h"
#include "Book.h"
#include "PublicationSelector.h"
using namespace std;
namespace sdds {
	void LibApp::load()
	{
		ifstream file(m_filename);
		char ch{};
		bool done = 0;

		cout << "Loading Data\n";
		while(file && !done)
		{
			file.get(ch);
			if (ch != '\n')
			{
				if (ch == 'B')
				{
					m_PPA[m_noOfLoadedPubs] = new Book();
				}
				else
				{
					m_PPA[m_noOfLoadedPubs] = new Publication();
				}
				m_PPA[m_noOfLoadedPubs]->read(file);
				file.get(ch);
				m_noOfLoadedPubs++;
			}
			else done = 1;
		}
		m_lastLib = m_noOfLoadedPubs - 1;
	}
	void LibApp::save()
	{
		ofstream file(m_filename);
		size_t i{};
		cout << "Saving Data\n";
		for (i = 0; i < m_noOfLoadedPubs; i++)
		{
			if(m_PPA[i] != nullptr && m_PPA[i]->getRef() != 0)
			{
				m_PPA[i]->write(file) << '\n';
			}
		}
	}
	size_t LibApp::search(size_t searchType)
	{
		PublicationSelector ps("Select one of the following found matches:");
		char title[256 + 1], searchFor{};
		size_t answer{};
		bool abort{};

		switch (m_pubMenu.run())
		{
		case 1:
			searchFor = 'B';
			break;
		case 2:
			searchFor = 'P';
			break;
		default:	
			abort = 1;
			break;
		}

		if(!abort){
			cout << "Publication Title: ";
			cin.ignore();
			cin.getline(title, 256, '\n');

			//Go through all the publications in the PPA
			for (size_t i = 0; i < m_noOfLoadedPubs; i++)
			{
				//if the publication is not deleted
				if (m_PPA[i] 
					//and type matches the selection of the user
					&& m_PPA[i]->type() == searchFor
					//and the title contains the title the user entered
					&& strStr((const char*)*m_PPA[i], title)) 
				{
				//base on the method of search(all the items, on loan items or available ones)
					switch (searchType)
					{ //insert it into the PublicationSelector object
					case 2:
						if(m_PPA[i]->onLoan())
							ps << m_PPA[i];
						break;
					case 3:
						if (!m_PPA[i]->onLoan())
							ps << m_PPA[i];
						break;
					default:
						ps << m_PPA[i];
						break;
					}
				}
			}
			if (ps) {
				ps.sort();
				if ((answer = ps.run()) == 0)
					abort = 1;
			}
			else
				cout << "No matches found!\n";
		}
		if(abort) {
			cout << "Aborted!\n";
		}
		return answer;
	}
	void LibApp::returnPub()
	{
		Date today{};
		size_t answer{}, daysLate{};
		double total{};
		cout << "Return publication to the library\n";
		answer = search(2);
		if (answer > 0) {
			//cout.setf(ios::fixed);
			//cout.setf(ios::left);
			getPub(answer)->write() << '\n';
			//cout.unsetf(ios::left);
			//cout.unsetf(ios::fixed);

			if (confirm("Return Publication?")) {
				daysLate = today - getPub(answer)->checkoutDate();
				if (daysLate > 15)
				{
					daysLate -= 15;
					total = daysLate * .5;

					cout.setf(ios::fixed);
					cout.precision(2);
					cout << "Please pay $"  << total << " penalty for being " << daysLate << " days late!\n";
					cout.unsetf(ios::fixed);
				}
				cout << "Publication returned\n";

				getPub(answer)->set(0);
				m_changed = 1;
			}
			else
				cout << "Aborted!\n"; //tbc if aborted or other message
			
		}
	}
	LibApp::LibApp(const char* filename)
		: 
		m_mainMenu("Seneca Library Application"),
		m_pubMenu("Choose the type of publication:"),
		m_exitMenu("Changes have been made to the data, what would you like to do?"),
		m_noOfLoadedPubs{},
		m_changed{},
		m_lastLib(-1)
	{
		strCpy(m_filename, filename);
				
		m_mainMenu 
			<< "Add New Publication" 
			<< "Remove Publication" 
			<< "Checkout publication from library" 
			<< "Return publication to library";		

		m_exitMenu 
			<< "Save changes and exit" 
			<< "Cancel and go back to the main menu";

		m_pubMenu
			<< "Book"
			<< "Publication";

		load();
	}
	LibApp::~LibApp()
	{
		int i = m_noOfLoadedPubs - 1;
		while(i > -1)
		{
			delete m_PPA[i];
			m_PPA[i] = nullptr;
			i--;
		}
	}
	bool LibApp::confirm(const char* message)
	{
		Menu menu(message);

		menu << "Yes";

		return menu.run();
	}
	void LibApp::newPublication() 
	{
		Publication* pub = nullptr;
		size_t answer{};
		bool exit{};

		if(m_noOfLoadedPubs < SDDS_LIBRARY_CAPACITY){
			cout << "Adding new publication to the library\n";
			answer = m_pubMenu.run();
			if (answer == 1) {
				pub = new Book();
			}
			else if (answer == 2) {
				pub = new Publication();
			}
			else {
				exit = 1;
			}
			if (!exit)
			{
				cin.ignore();
				cin >> *pub;
				if (cin)
				{
					if (!confirm("Add this publication to the library?")) {
						exit = 1;
					}
				}
				else
				{
					cin.clear();
					cin.ignore(1000, '\n');
				}
			}

			if (!exit)
			{
				if (pub)
				{
					//Add one to the LLRN and set the library reference number to the value
					pub->setRef(m_PPA[m_noOfLoadedPubs - 1]->getRef() + 1);

					//	Add the publication object's address to the end of the PPA and add one to the NOLP.
					m_PPA[m_noOfLoadedPubs] = pub;
					m_noOfLoadedPubs++;


					//	set the "changed" flag to true
					m_changed = true;
					//	print: "Publication added"
					cout << "Publication added\n";
				}
				else exit = 1;
			}
			if (exit) {
				cout << "Aborted!\n";
				delete pub;
			}
		}
		else
		{
			cout << "Library is at its maximum capacity!\n";
		}
	}
	void LibApp::removePublication()
	{
		size_t answer{};
		cout << "Removing publication from the library\n";
		if ((answer = search()) > 0)
		{
			getPub(answer)->write() << '\n';
			if (confirm("Remove this publication from the library?")) {
				//Set the library reference of the selected publication to 0
				getPub(answer)->setRef(0);

				m_changed = true;
				cout << "Publication removed\n";
			}
		}
	}
	void LibApp::checkOutPub()
	{
		size_t answer{}, membership{};
		cout << "Checkout publication from the library\n";
		answer = search(3);
		if(answer > 0){
			getPub(answer)->write() << '\n';
			if (confirm("Check out publication?")) {
				cout << "Enter Membership number: ";
				cin >> membership;
				while (!membership || membership / 10000 > 9 ||membership / 10000 < 1) {
					while (cin.get() != '\n');
					cout << "Invalid membership number, try again: ";
					cin >> membership;
				}

				getPub(answer)->set(membership);
				cout << "Publication checked out\n";
				m_changed = true;
			}
		}
	}
	Publication* LibApp::getPub(int libRef) const
	{
		bool check = 0;
		size_t i{};
		Publication* pub = nullptr;

		while (!(check = m_PPA[i]->getRef() == libRef) && i++ < m_noOfLoadedPubs);

		if(check)
			pub = m_PPA[i];

		return pub;
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
