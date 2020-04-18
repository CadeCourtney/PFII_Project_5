//---------------------------------------------------
// Purpose:    Header file for the Frequency class
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

#ifndef FREQUENCY
#define FREQUENCY
class Frequency
{
public:
	Frequency();
	~Frequency();;
	void readBook(string name);
	void writeBook(string name);
	void countFreq();
	void sort();
	void hybridSort(int low, int high);
	void insertion_sort(int low, int high);
	string editWord(string word);
	void print();
	void printData();

private:
	int index;
	int counter;
	vector<string> data;
	vector<string> array[26];
	map<string, int> freqMap;
};
#endif