#include "Population.h"
using namespace std;
namespace sdds {
	int recs = 0;
	Population* reports = nullptr;

	bool load(const char* fname){
		bool open = false;
		Population rep;
		if (openFile(fname)) {
			recs = noOfRecords();
			if (recs && !reports) {
				reports = new Population[recs];
				for (int i = 0; i < recs; i++)
					if (read(rep.postalCode) && read(&rep.popNum))
						reports[i].load(rep);
				open = true;
			}
			closeFile();
		}
		return open;
	}
	void Population::load(Population pop) {
		for (int i = 0; i < 3; i++)
			postalCode[i] = pop.postalCode[i];
		popNum = pop.popNum;
	}

	void display(){
		cout << "Postal Code: population\n"
			"-------------------------\n";

		for (int i = 0; i < recs; i++) 
			cout << i + 1 << "- " << reports[i].postalCode << ":  " <<
				reports[i].popNum << '\n';
		
		cout << "-------------------------\n";
	}

	void deallocateMemory() {
		if (reports)
			delete[] reports;
		reports = nullptr;
	}
}