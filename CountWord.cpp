//---------------------------------------------------
// Purpose:     Implementation of the CountWord class
//
// Author:      Cade Courtney
//---------------------------------------------------
#include "CountWord.h"


//---------------------------------------------------
// Constructor 
//---------------------------------------------------
CountWord::CountWord() {

}

//---------------------------------------------------
// Destructor 
//---------------------------------------------------
CountWord::~CountWord() {

}

//---------------------------------------------------
// readBook method 
//---------------------------------------------------
void CountWord::readBook(string name) {
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
void CountWord::writeBook(string name) {
	string bookName = name + ".count";
	ofstream myBook;
	myBook.open(bookName.c_str());
	for (int ii = 0; ii < word.size(); ii++) {
		myBook << count[ii] << " " << word[ii] << endl;
	}
	myBook.close();
}

////---------------------------------------------------
//// count Freqeuncy method 
////---------------------------------------------------
void CountWord::countFreq() {
//	int total = 0;
	int in = 0;
	for (int ii = 0; ii < 26; ii++) {
		data.clear();
		for (vector<string>::iterator iter = array[ii].begin(); iter != array[ii].end() && !array[ii].empty(); iter++) {
			data.push_back(*iter);
		}
		seen.push_back(" ");
			for (int cc = 0; cc < data.size(); cc++) {
				if (seen[in] == data[cc])
					continue;
				else {
					for (int tt = 1; tt < data.size(); tt++) {
						if (data[cc] == data[tt])
							counter++;
					}
				}
				seen[in] = data[cc];
				count.push_back(counter);
				word.push_back(data[cc]);
				counter = 0;
		}
	}
//	for (int ii = 0; ii < word.size(); ii++)
//		cout << count[ii] << " " << word[ii] << endl;
	cout << endl;
//	cout << total;
}

//---------------------------------------------------
// editWord method 
//---------------------------------------------------
string CountWord::editWord(string word) {
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

//---------------------------------------------------
// Sort method 
//---------------------------------------------------
void CountWord::sort() {
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

//---------------------------------------------------
// hybridSort method 
//---------------------------------------------------
void CountWord::hybridSort(int low, int high) {
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
void CountWord::print() {
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
void CountWord::printData() {
	for (int ii = 0; ii < 26; ii++) {
		for (vector<string>::iterator iter = data.begin(); iter != data.end() && !data.empty(); iter++) {
			//	if (*iter != NULL) {
			cout << *iter << " ";
			//		}
		}
	}
	cout << endl;
}