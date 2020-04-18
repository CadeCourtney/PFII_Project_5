//---------------------------------------------------
// Purpose:     Implementation of the Frequency class
//
// Author:      Cade Courtney
//---------------------------------------------------
#include "Frequency.h"

//---------------------------------------------------
// Constructor 
//---------------------------------------------------
Frequency::Frequency() {
	int index = 0;
	int counter = 0;
}

//---------------------------------------------------
// Destructor 
//---------------------------------------------------
Frequency::~Frequency() {

}

//---------------------------------------------------
// readBook method 
//---------------------------------------------------
void Frequency::readBook(string name) {
	int charIndex = 0;
	string bookName = name + ".txt";
	cout << "Reading Book: " << bookName << endl;
	// Open input file
	ifstream din;
	din.open(bookName.c_str());
	if (din.fail()) {
		cout << "Error:No file by that name\n";
		return;
	}
	// Read words into vector
	string str;
	din >> str;
	// Place book into vector
	while (!din.eof()) {
		if (str != " ") {
			str = editWord(str); // place in array of vectors
			if (str.length() > 0) {
				if (str[0] == '\'') {
					charIndex = 1;
				}
				index = str[charIndex] - 'a';
				array[index].push_back(str);
			}
		}
		din >> str;
		charIndex = 0;
//		cout << str << endl;
	}
}
//---------------------------------------------------
// writeBook method 
//---------------------------------------------------
void Frequency::writeBook(string name) {
	string bookName = name + ".count";
	ofstream myBook;
	myBook.open(bookName.c_str());
	for (map<string, int>::iterator freqIter = freqMap.begin(); freqIter != freqMap.end(); freqIter++) {
		myBook << freqIter->second << " " << freqIter->first << endl;
	}
	myBook.close();
}

//---------------------------------------------------
// count Freqeuncy method 
//---------------------------------------------------
void Frequency::countFreq() {
//	int total = 0;
	map<string, int>::iterator freqIter;
	for (int ii = 0; ii < 26; ii++) {
		for (vector<string>::iterator iter = array[ii].begin(); iter != array[ii].end() && !array[ii].empty(); iter++) {
			freqIter = freqMap.find(*iter);
			if (freqIter != freqMap.end()) {
				freqMap.at(*iter) = freqIter->second + 1;
			} else {
				freqMap.insert(pair<string, int>(*iter, 1));
			}
		}
	}
/*	for (map<string, int>::iterator freqIter = freqMap.begin(); freqIter != freqMap.end(); freqIter++) {
		cout << freqIter->second << " " << freqIter->first << ", " << endl;
		total += freqIter->second;
	}
	cout << endl;
	cout << total;*/
}

//---------------------------------------------------
// editWord method 
//---------------------------------------------------
string Frequency::editWord(string word) {
	string alpha = "abcdefghijklmnopqrstuvwxyz\'";
	string str = word;
	string good = "";
	int len = str.length();
	for (int i = 0; i < len; i++) {
		str[i] = (char)tolower(str[i]); // input strings to lower case strings
	}
//	cout << str << endl;
	for (int i = 0; i < len; i++) {
		if (alpha.find_first_of(str[i]) != string::npos) {
			good += str[i];
		}
	}
//	cout << good << endl;
	return good;
}
	/*for (int i = 0; i < len; i++) {
		if (((str[i] >= 'a') && (str[i] <= 'z')) || (str[i] == '\'')) {
			if ((str[i] >= 'A') && (str[i] <= 'Z'))
				str[i] += 32; // assuming dictionary contains small letters only.
		}
		else {
			str.erase(i, 1);
			--len;
		}
	}
	//	   cout << "Word: " << str << endl; // debug
	return str;
}*/

//---------------------------------------------------
// Sort method 
//---------------------------------------------------
void Frequency::sort() {
	for (int ii = 0; ii < 26; ii++) {
		data.clear();
		// move array[ii] vector contents to data vector
		for (vector<string>::iterator iter = array[ii].begin(); iter != array[ii].end() && !array[ii].empty(); iter++) {
			data.push_back(*iter);
		}
		//		printData();
				// clear array[ii] contents
		array[ii].clear();
		// sort data
		hybridSort(0, (data.size() - 1));
		// move data contents to array[ii] 
		for (vector<string>::iterator iter = data.begin(); iter != data.end() && !data.empty(); iter++) {
			array[ii].push_back(*iter);
		}
	}
}

//----------------------------------------------------------------
// Insertion sort algorithm
//----------------------------------------------------------------
void Frequency::insertion_sort(int low, int high){
	// Insert each element of unsorted list into sorted list
	for (int unsorted = low + 1; unsorted <= high; unsorted++)
	{
		// Select unsorted value to be inserted
		string value = data[unsorted];
		int posn = unsorted;

		// Make room for new data value
		while ((posn > 0) && (data[posn - 1] > value))
		{
			data[posn] = data[posn - 1];
			posn--;
		}
		// Put new value into array
		data[posn] = value;

	}
}

//---------------------------------------------------
// hybridSort method 
//---------------------------------------------------
void Frequency::hybridSort(int low, int high) {
	if (high < 25) {
		insertion_sort(low, high);
		return;
	}
	// Check terminating condition
	int range = high - low + 1;
	if (range > 1)
	{
		// Divide the array and sort both halves
		int mid = (low + high) / 2;
		hybridSort(low, mid);
		hybridSort(mid + 1, high);

		// Create temporary array for merged data
		string* copy = new string[range];

		// Initialize array indices
		int index1 = low;
		int index2 = mid + 1;
		int index = 0;

		// Merge smallest data elements into copy array
		while (index1 <= mid && index2 <= high)
		{
			if (data[index1] < data[index2])
				copy[index++] = data[index1++];
			else
				copy[index++] = data[index2++];
		}

		// Copy any remaining entries from the first half
		while (index1 <= mid)
			copy[index++] = data[index1++];

		// Copy any remaining entries from the second half
		while (index2 <= high)
			copy[index++] = data[index2++];

		// Copy data back from the temporary array
		for (index = 0; index < range; index++)
			data[low + index] = copy[index];
		delete[]copy;
	}
}

//---------------------------------------------------
// print method 
//---------------------------------------------------
void Frequency::print() {
	for (int ii = 0; ii < 26; ii++) {
		for (vector<string>::iterator iter = array[ii].begin(); iter != array[ii].end() && !array[ii].empty(); iter++) {
			//	if (*iter != NULL) {
			cout << *iter << " ";
			//		}
		}
	}
	cout << endl;
}

//---------------------------------------------------
// print Data method 
//---------------------------------------------------
void Frequency::printData() {
	for (int ii = 0; ii < 26; ii++) {
		for (vector<string>::iterator iter = data.begin(); iter != data.end() && !data.empty(); iter++) {
			//	if (*iter != NULL) {
			cout << *iter << " ";
			//		}
		}
	}
	cout << endl;
}