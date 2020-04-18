//----------------------------------------------------------
//Program: Project 5
//Author: Cade Courtney 010863285
//---------------------------------------------------------
#include "CountWord.h"

int main() {
	vector<string> books;
	books.push_back("sample1");
//	books.push_back("Frankenstein");
//	books.push_back("The_Works_of_Edgar_Allan_Poe");
//	books.push_back("Moby_Dick");
	for (vector<string>::iterator iter = books.begin(); iter != books.end(); iter++) {
		CountWord book;
		book.readBook(*iter);
//					book.print();
		book.sort();
//					book.print();
		book.countFreq();
		//			book.printData();
		book.writeBook(*iter);
	}
}


