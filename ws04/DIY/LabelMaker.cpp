#include "LabelMaker.h"
using namespace std;
namespace sdds {
	LabelMaker::LabelMaker(int noOfLabels)
	{
		m_size = noOfLabels;
		m_labels = new Label[noOfLabels];
	}
	LabelMaker::~LabelMaker()
	{
		if (m_labels)
			delete[] m_labels;
		m_labels = nullptr;
	}

	void LabelMaker::readLabels()
	{
		cout << "Enter " << m_size << " labels:\n";
		for (size_t i = 0; i < m_size; i++) {
			cout << "Enter label number " << i + 1 << "\n> ";
			m_labels[i].readLabel();
		}
	}
	void LabelMaker::printLabels()
	{
		for (size_t i = 0; i < m_size; i++)
		{
			m_labels[i].printLabel();
			cout << '\n';
		}
	}


}