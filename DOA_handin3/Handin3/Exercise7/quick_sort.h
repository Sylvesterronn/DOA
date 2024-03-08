#pragma once
#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_

#include<assert.h>
#include<vector>


/**
 * Order left, center, and right and hide the pivot.
 * Then compute partition, restore the pivot and return its position.
 */
#include <vector>
using namespace std;

static int insertionSort = 16;

template <typename Comparable>
int partition(vector<Comparable>& a, int left, int right) {
	assert(left >= 0 && right < a.size() && left <= right); //assert to make sure we get proper values
	int center = (left + right) / 2;

	if (a[center] < a[left])
		std::swap(a[left], a[center]);
	if (a[right] < a[left])
		std::swap(a[left], a[right]);
	if (a[right] < a[center])
		std::swap(a[center], a[right]);

	// Place pivot at position right - 1
	std::swap(a[center], a[right - 1]);

	// Now the partitioning
	Comparable& pivot = a[right - 1];
	int i = left, j = right - 1;
	do {
		while (a[++i] < pivot);
		while (pivot < a[--j]);
		if (i < j) {
			std::swap(a[i], a[j]);
		}
	} while (i < j);

	std::swap(a[i], a[right - 1]);	// Restore pivot
	return i;
}
//Insertion Function
template <typename Comparable>
void InsertionSort(vector<Comparable>& a, int left, int right)
{
	cout << "sorted with insertionSort" << endl;

	assert(left >= 0 && right < a.size() && left <= right);
	for (int i = left + 1; i <= right; i++)
	{
		int key = a[i];
		int j = i - 1;

		/* Move elemtens that are
		greater than key, to one position ahead
		of their current position */
		while (j >= left && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}

	return;
}
/**
 * Internal quicksort method that makes recursive calls.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template <typename Comparable>
void quickSort(vector<Comparable>& a, int left, int right) {
	assert(left >= 0 && right < a.size() && left <= right);

	if (right - left < insertionSort) {
		// Use InsertionSort for small subarrays
		InsertionSort(a, left, right);
		
	}
	else {
		int i = partition(a, left, right);
		quickSort(a, left, i - 1);
		quickSort(a, i + 1, right);
		cout << "sorted with quicksort" << endl;
	}
}


/**
 * Quicksort algorithm (driver).
 */
template <typename Comparable> void quickSort(vector < Comparable >& a) {
	quickSort(a, 0, a.size() - 1);
}

#endif
