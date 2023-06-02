/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: 02-June-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include "Bill.h"
using namespace std;
namespace sdds {
    double Bill::totalTax()const{ 
        double total = 0;
        for (int i = 0; i < m_itemsAdded; i++)
            if (m_items[i].taxed())
                total += m_items[i].price();
        return total * TAX;
    }
    double Bill::totalPrice()const{
        double total = 0;
        for (int i = 0; i < m_itemsAdded; i++)
             total += m_items[i].price();
        return total;
    }
    void Bill::Title()const{
        cout << "+--------------------------------------+\n";
        if (isValid()) {
            cout.setf(ios::fixed);
            cout.setf(ios::left);

            cout << "| ";
            cout.width(36);
            cout << m_title << " |";

            cout.unsetf(ios::fixed);
        }
        else cout << "| Invalid Bill                         |";
        cout << '\n';

        cout << "+----------------------+---------+-----+\n"
            << "| Item Name            | Price   + Tax |\n"
            << "+----------------------+---------+-----+\n";
    }
    void Bill::footer()const{
        cout << "+----------------------+---------+-----+\n";
        if (isValid()) {
            cout.setf(ios::fixed);
            cout.setf(ios::right);

            cout << "|                Total Tax: ";
            cout.width(10); cout.precision(2);
            cout << totalTax() << " |\n";
            
            cout << "|              Total Price: ";
            cout.width(10); cout.precision(2);
            cout << totalPrice() << " |\n";

            cout << "|          Total After Tax: ";
            cout.width(10); cout.precision(2);
            cout << totalTax() + totalPrice() << " |";

            cout.unsetf(ios::right);
            cout.unsetf(ios::fixed);
        }
        else cout << "| Invalid Bill                         |";

        cout << "\n+--------------------------------------+\n";
    }
    void Bill::setEmpty(){
        deallocate();
        m_title[0] = '\0';
        m_noOfItems = 0;
        m_itemsAdded = 0;
    }
    bool Bill::isValid()const{
        bool valid = false;
        if ((valid = (m_title && m_title[0] != '\0' && m_items)))
            for (int i = 0; i < m_noOfItems && valid; i++)
                valid = m_items[i].isValid();
        return valid;
    }
    void Bill::init(const char* title, int noOfItems){
        setEmpty();
        if (title[0] != '\0' && noOfItems > 0) {
            strnCpy(m_title, title, 36);
            m_noOfItems = noOfItems;
            m_items = new Item[m_noOfItems];
        }
        else setEmpty();
    }
    bool Bill::add(const char* item_name, double price, bool taxed){
        bool check = false;
        if ((check = (m_itemsAdded < m_noOfItems))) {
            m_items[m_itemsAdded].set(item_name, price, taxed);
            m_itemsAdded++;
        }
        return check;
    }
    void Bill::display()const{
        Title();
        for (int i = 0; i < m_noOfItems; i++)
            m_items[i].display();
        footer();
    }
    void Bill::deallocate(){
        if (m_items)
            delete[] m_items;
        m_items = nullptr;
    }
}