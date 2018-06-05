#include <iostream>
#include <vector>
#include <stdlib.h>
#include "mergesortImproved.cpp"       
using namespace std;




// array printing
void printArray(vector<int> &array) {
	int size = array.size();

	for (int i = 0; i < size; i++)
		cout << "items" << "[" << i << "] = " << array[i] << endl;
}



int main() {
	

	// array generation
	vector<int> items;
	int myints[] = { 5, 8, 9, 36, 2, 48, 6, 15, 55, 99, 67, 14, 78 };
	items.assign(myints, myints + 13);   // assigning from array.


	cout << "initial:" << endl;   // comment out when evaluating performance only
	printArray(items); // comment out when evaluating performance only

	// mergesort
	mergesortImproved(items);

	cout << "sorted:" << endl;    // comment out when evaluating performance only
	printArray(items); // comment out when evaluating performance only

	return 0;
}