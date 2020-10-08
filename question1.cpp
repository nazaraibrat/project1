/*
* 1. Test whether a vector or a list is faster by timing them via:
* a. Filling them with random numbers
* b. Filling them with random strings (use ascii)
* c. Doing the above with move semantics when filling with random strings
*/
#include<string>
#include<iterator>
#include<list>
#include<chrono>
#include<vector>
#include<iostream>
#include<ctime>
using namespace std;
using namespace std::chrono;

int main() {
	srand(time(NULL));
	int size = 20000;
	vector<int> foo;

	// time when the integer vector starts populating
	auto int_vector_begins = high_resolution_clock::now();

	// populating the vector with random integers between 1 to 100
	for (int i = 1; i < size + 1; i++) {
		foo.push_back(rand() % 100 + 1);
	}

	// time when the populating is over
	auto int_vector_ends = high_resolution_clock::now();

	// time taken to populate
	auto time_for_int_vector = duration_cast<microseconds>(int_vector_ends - int_vector_begins);
	//printing the elapsed time taken by using vectors
	cout << "Elapsed time for populating vector with random integers: " << time_for_int_vector.count() << " micro seconds!" << endl;

	//printing the vector
	/*for (int i = 0; i < foo.size(); i++) {
		cout << "element " << (i + 1) << ": " << foo[i] << endl;
	}*/


	//populating integers with lists
	list<int> myIntList;

	// time when the integer list starts populating
	auto intList_begins = high_resolution_clock::now();
	//populating the list
	for (int i = 0; i < size; i++) {
		myIntList.push_back(rand() % 100 + 1);
	}
	// time when the integer list ends populating
	auto intList_ends = high_resolution_clock::now();

	//printing the list
	//int index = 1;
	//list<int> ::iterator iter;
	/*for (iter = myIntList.begin(); iter != myIntList.end(); iter++) {
		cout << index <<"->\t"<<*iter << endl;
		index += 1;
	}*/

	// time taken to populate
	auto time_for_int_list = duration_cast<microseconds>(intList_ends - intList_begins);
	//printing the elapsed time taken by using list with integers
	cout << "Elapsed time for populating list with integers: " << time_for_int_list.count() << " micro seconds!" << endl;

	cout << "\nAns for 1A ->";

	if (time_for_int_list < time_for_int_vector)
		cout << "\nUsing list is better for random integers!" << endl;
	else
		cout << "\nUsing vector is better for random integers!" << endl;


	cout << "\n";
	/*
	* REMARKS:
	* for smaller sized set of random ints, list is faster.
	* for big sized set of numbers vector is faster.
	*/

	//vector to hold randmly generated strings
	vector<string> myStrings;

	//time when the populating begins
	auto str_vec_starts = high_resolution_clock::now();

	//populating the vector with random strings
	for (int i = 0; i < size + 1; i++) {
		char temp = char(33 + rand() % 96);	//for getting between char(33) and char(127)
		string x;
		x.push_back(temp);
		myStrings.push_back(x);
	}

	//time when the populating ends
	auto str_vec_ends = high_resolution_clock::now();

	//to print the string vector
	/*for (int i = 0; i < size; i++) {
		cout << "vector string element " << i + 1 << ": " << myStrings[i] << endl;
	}*/

	auto time_for_str_vec = duration_cast<microseconds>(str_vec_ends - str_vec_starts);

	cout << "Elapsed time for populating the vector with random strings: " << time_for_str_vec.count() << " micro sceconds!" << endl;

	list<string> stringList;
	// time when the string list starts populating
	auto str_List_begins = high_resolution_clock::now();
	//populating the list
	for (int i = 0; i < size; i++) {
		char x = char((int)33 + rand() % (int)96);
		string y;
		y.push_back(x);
		stringList.push_back(y);
	}
	// time when the string list finishes populating
	auto str_List_ends = high_resolution_clock::now();

	// printing the list
	/*int index = 1;
	list<string> ::iterator iterStr;
	for (iterStr = stringList.begin(); iterStr != stringList.end(); iterStr++) {
		cout << index << "->\t" << *iterStr << endl;
		index += 1;
	}*/

	// time taken
	auto time_for_str_list = duration_cast<microseconds>(str_List_ends - str_List_begins);

	cout << "Elapsed time for populating the list with random strings: " << time_for_str_list.count() << " micro sceconds!" << endl;

	cout << "\nAns for 1B ->";

	if (time_for_str_list < time_for_str_vec)
		cout << "\nUsing list is better for random strings!" << endl;
	else
		cout << "\nUsing vector is better for random strings!" << endl;

	//1c
	//vector<int> intVector;
	//for (int i = 0; i < 10; i++) {
	//	int y = rand() % 100 + 1;
	//	intVector.push_back(move(y));
	//}

	////print the vector
	//for (int i = 0; i < 10; i++) {
	//	cout << intVector[i] << endl;
	//}
}
