/***********************************************************************
Author: Leonardo Caceres
Student number: 152877205
Email: lde-la-mora-canceres@myseneca.ca
Date of completion: 09-June-2023

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
***********************************************************************/
#include "Label.h"
using namespace std;
namespace sdds {
	const short MAX_SZ = 70;

	void Label::setContent(const char* content){
		clear();
		if (content) {
			if ((m_size = strLen(content)) > MAX_SZ)
				m_size = MAX_SZ;
			m_content = new char[m_size + 1];
			strCpy(m_content, content);
		}
	}

	void Label::setFrame(const char* frame)
	{
		if (frame && frame[0] != '\0')
			strCpy(m_frame, frame);
	}

	Label::Label() {
		strCpy(m_frame, "+-+|+-+|");
	}
	Label::Label(const char* frame){
		setFrame(frame);
	}
	Label::Label(const char* frame, const char* content) {
		setFrame(frame); 
		setContent(content);
	}
	Label::~Label() {
		clear();
	}

	void Label::clear()
	{
		if (m_content)
			delete[] m_content;
		m_content = nullptr;
	}

	void Label::readLabel(){
		char buffer[MAX_SZ + 1]{};
		cin.getline(buffer, MAX_SZ + 1, '\n');
		setContent(buffer);
	}
	ostream& Label::printLabel()const {
		unsigned short i = 0;
		if (m_content) {
			//top line
			cout << m_frame[0];
			for (i = 0; i < m_size + 2; i++) cout << m_frame[1];
			cout << m_frame[2] << '\n';

			//content and spacing
			for (i = 1; i < 4; i++) {
				cout << m_frame[3] << ' ';
				if (i == 2)
					cout << m_content;
				else for (unsigned short j = 0; j < m_size; j++) cout << ' ';
					
				cout << ' ' << m_frame[3] << '\n';
			}

			//bottom line
			cout << m_frame[6];
			for (i = 0; i < m_size + 2; i++) cout << m_frame[5];
			cout << m_frame[4];
		}
		return cout;
	}
}
