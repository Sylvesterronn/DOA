#include <iostream>
#include <algorithm>


bool  recusArray(int* ar,int size, int element, int index=0)
{

	if (size <= 0)
	{
		return false;
	}

	if (ar[index]==element)
	{
		return true;
	}

	return recusArray(ar, size - 1, element, index + 1);
	
}

void findMinMax(int* ar, int size, int index, int& maxVal, int& minVal)
{
	if (index >= size)
	{
		return;
	}

	minVal = std::min(minVal, ar[index]);
	maxVal = std::max(maxVal, ar[index]);

	findMinMax(ar, size, index +1, maxVal, minVal);


}

int main()
{
	
	int array[] = { 1,2,3,4,5 };

	int size = sizeof(array) / sizeof(array[0]);
	int element = 8;
	int element2 = 3;



	bool search =recusArray(array, size, element);
	bool search2 = recusArray(array, size, element2);
	
	search?std::cout <<  "Element " << element << " Was found!" << std::endl: std::cout << "Element " << element << " Was NOT found!" << std::endl;
	search2 ? std::cout << "Element " << element2 << " Was found!" << std::endl : std::cout << "Element " << element << " Was NOT found!" << std::endl;

	int maxVal = array[0], minVal = array[0];

	findMinMax(array, size, 0, maxVal, minVal);

	std::cout << "Max value: " << maxVal << std::endl;
	std::cout << "Min value: " << minVal << std::endl;
	

	

	return 0;
}