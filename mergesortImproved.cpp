#include <vector>
#include <math.h>
using namespace std;

//---------------------------------------------------- (NonRecursive Mergesort) ----------------------------------------------------------
template <class Comparable>
void mergesortImproved( vector<Comparable> &a ) { //Nonrecursive mergesort

  int size = a.size();
  vector<Comparable> b(size); //Temporary array.     

  int right; 
  int rend;
  int i,j,k;//index(s)

  for (int z = 1; z < size;  z*= 2) { // 1, 2, 4, 8, 16... Size

	  for (int left = 0; left + z < size; left += z* 2) { 
		  
		  right = left + z;
		  rend = right + z;

		  if (rend > size) rend = size; //Keeps rend inbounds 

		  k = left; i = left; j = right;
		  
		  while (i < right && j < rend) {
			  
			  if (a[i] <= a[j]) {//if they are in order 
				  b[k] = a[i]; i++; //then copy to temporary array 
			  }
			  else {//else they are NOT in order
				  b[k] = a[j]; j++;//then copy other to temporary array
			  }
			  k++;//increase index for vector b
		  }
		  while (i < right) {// until i index hits right 
			  b[k] = a[i];//copy vector a value to vector b
			  i++; k++; 
		  }
		  while (j < rend) {//until j index hits rend
			  b[k] = a[j];//copy vector a value to vector b
			  j++; k++;
		  }
		  for (k = left; k < rend; k++) {
			  a[k] = b[k];////copy vector a values to vector b
		  }
	  }
  }
}


//------------------------------------------------------ (Original Mergesort)-----------------------------------------------------------
template <class Comparable>
void merge(vector<Comparable> &a, int first, int mid, int last) {
	vector<Comparable> tempArray(a.size());
	int first1 = first; int last1 = mid;         // the left array[first1..last1]
	int first2 = mid + 1; int last2 = last;     // the right array[first2..last2]

	int index = first1;
	for (; first1 <= last1 && first2 <= last2; ++index) // choose a smaller
		tempArray[index] = (a[first1] < a[first2]) ? a[first1++] : a[first2++];

	for (; first1 <= last1; ++first1, ++index)      // exhaust the left array
		tempArray[index] = a[first1];

	for (; first2 <= last2; ++first2, ++index)      // exhaust the right array
		tempArray[index] = a[first2];

	for (index = first; index <= last; ++index)  // write them back to original
		a[index] = tempArray[index];
}

template <class Comparable>
void mergesort(vector<Comparable> &a, int first, int last) {

	if (first < last) {
		int mid = (first + last) / 2;              // divide the array into two
		mergesort(a, first, mid);                  // sort the left array
		mergesort(a, mid + 1, last);               // sort the right array
		merge(a, first, mid, last);                // merge them into one
	}
}

template <class Comparable>
void mergesort(vector<Comparable> &a) {        // the driver
	mergesort(a, 0, a.size() - 1);
}


//------------------------------------------------------------------ (Quicksort) --------------------------------------------------------
template <class Comparable>
void objectSwap(Comparable &lhs, Comparable &rhs) {
	Comparable tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

template <class Comparable>
void choosePivot(vector<Comparable> &a, int first, int last) {
	int middle = (first + last) / 2;
	objectSwap(a[first], a[middle]);
}

template <class Comparable>
void partition(vector<Comparable> &a, int first, int last, int &pivotIndex){
	// place the pivot in a[first]
	choosePivot(a, first, last);
	Comparable pivot = a[first];
	int lastS1 = first;
	int firstUnknown = first + 1;

	for (; firstUnknown <= last; ++firstUnknown) {
		if (a[firstUnknown] < pivot) {
			++lastS1;
			objectSwap(a[firstUnknown], a[lastS1]);
		}
		// else item from unknown belongs in S2
	}
	// decide a new pivot
	objectSwap(a[first], a[lastS1]);
	pivotIndex = lastS1;
}

template <class Comparable>
void quicksort(vector<Comparable> &a, int first, int last) {
	int pivotIndex;

	if (first < last) {
		partition(a, first, last, pivotIndex);
		quicksort(a, first, pivotIndex - 1);
		quicksort(a, pivotIndex + 1, last);
	}
}

template <class Comparable>
void quicksort(vector<Comparable> &a) {
	quicksort(a, 0, a.size() - 1);
}
