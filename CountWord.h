//---------------------------------------------------
// Purpose:    Header file for the CountWord class
//
// Author:     Cade Courtney
//---------------------------------------------------


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>
using namespace std;

#ifndef COUNTWORD
#define COUNTWORD
class CountWord
{
public:
	CountWord();
	~CountWord();
	void readBook(string name);
	void writeBook(string name);
	void countFreq();
	void sort();
	void hybridSort(int low, int high);
	string editWord(string word);
	void print();
	void printData();

private:
	int index;
	int counter;
	vector<string> data;
	vector<string> array[26];
	vector<string> seen;
	vector<string> word;
	vector<int> count;
};
#endif