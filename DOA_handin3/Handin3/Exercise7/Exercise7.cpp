#include <iostream>
#include"quick_sort.h"
#include <chrono>


using namespace std::chrono;

int main()
{
	vector<int> v = { 7, 42, 15, 91, 0, 8, 17, 99, -5 };
	vector<int> v1 = { 7, 42, 15, 91, 0, 8, 17, 99, -5 ,1,100,87,223,14,15,16,17,20};
	
	cout << "Original array: ";

	for (const auto& element : v) {
		cout << element << " ";
	}
	cout << endl;

	auto start = high_resolution_clock::now();
	quickSort(v);
	auto stop = high_resolution_clock::now();

	cout << "Sorted array: ";

	for (const auto& element : v) {
		cout << element << " ";
	}
	cout << endl;

	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by function: "
		<< duration.count() << " microseconds" << endl;

	cout << "Original array 1: ";

	for (const auto& element : v1) {
		cout << element << " ";
	}
	cout << endl;
	auto start1 = high_resolution_clock::now();
	quickSort(v1);
	auto stop1 = high_resolution_clock::now();

	cout << "Sorted array 1: ";

	for (const auto& element : v1) {
		cout << element << " ";
	}
	cout << endl;

	auto duration1 = duration_cast<microseconds>(stop1 - start1);
	cout << "Time taken by function: "
		<< duration1.count() << " microseconds" << endl;


	// Include stlsort.cpp
	cout << "Using std::sort:" << endl;
	system("g++ stlsort.cpp -o stlsort -std=c++11 && ./stlsort");
	double time4 = measureTime(std::sort<std::vector<int>::iterator>, smallInput.begin(), smallInput.end());
	double time5 = measureTime(std::sort<std::vector<int>::iterator>, mediumInput.begin(), mediumInput.end());
	double time6 = measureTime(std::sort<std::vector<int>::iterator>, largeInput.begin(), largeInput.end());

	std::cout << "Time taken for STL sort with small input: " << time4 << " seconds\n";
	std::cout << "Time taken for STL sort with medium input: " << time5 << " seconds\n";
	std::cout << "Time taken for STL sort with large input: " << time6 << " seconds\n";

}