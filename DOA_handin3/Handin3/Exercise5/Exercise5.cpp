#include <iostream>
#include <vector>
#include "../../../../Week6Code/sort.h"
#include <time.h>

using namespace std;


//OUR SELECTION SORT ALGORITHM
#include <iostream>
#include <vector>

template <typename T>
void selectionSort(std::vector<T>& a) 
{
	for (int i = 0; i < a.size(); i++) 
	{
		int minIndex = i;  
		for (int j = i + 1; j < a.size(); j++) 
		{  
			if (a[j] < a[minIndex]) 
			{
				std::cout << "a[j] = " << a[j] << " < a[minIndex] = " << a[minIndex] << std::endl;
				std::swap(a[j], a[minIndex]);
			}
		}
	}
}

//print funktion to test final.
template <typename T>
void printSorted(const vector<T>& a)
{
	for (auto it = a.begin(); it != a.end(); it++)
	{
		cout << *it << " " << endl;

	}
}


void checkSort(const vector<int>& a) {
	for (int i = 0; i < a.size() - 1; ++i) {
		if (a[i] > a[i + 1]) {
			cout << "Error at " << i << endl;
		}
	}
	cout << "Finished checksort" << endl;
}


template <typename AnyType>
void permute(vector<AnyType>& a) {
	for (int j = 1; j < a.size(); ++j) {
		swap(a[j], a[rand() % j]);
	}
}

int main() {
	const int NUM_ITEMS = 10;

	vector<int>a(NUM_ITEMS);
	for (int i = 1; i < a.size(); ++i) {
		a[i] = a[i - 1] + 'a';
	}

	for (int theSeed = 0; theSeed < 10; ++theSeed) {
		srand(time(0) + theSeed);

		//permute(a);
		//insertionSort(a);
		//checkSort(a);

		//permute(a);
		//insertionSort(begin(a), end(a));
		//checkSort(a);

		//permute(a);
		//mergeSort(a);
		//checkSort(a);

		//permute(a);
		//quickSort(a);
		//checkSort(a);
		
		permute(a);
		selectionSort(a);
		checkSort(a);
		printSorted(a);
	}

	return 0;
}
