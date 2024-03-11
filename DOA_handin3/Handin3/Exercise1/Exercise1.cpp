#include <iostream>
#include <algorithm> // Includes the standard library function for finding minimum and maximum of two values.

// Function for recursively searching for an element in an array.
bool recusArray(int* ar, int size, int element, int index = 0)
{
    if (size <= 0) // If the size is less than or equal to 0, the array is empty, and the element is not found.
    {
        return false;
    }

    if (ar[index] == element) // If the element is found in the array.
    {
        return true;
    }

    return recusArray(ar, size - 1, element, index + 1); // Recursively call the function with reduced size and increased index.
}

// Function to find minimum and maximum values in an array.
void findMinMax(int* ar, int size, int index, int& maxVal, int& minVal)
{
    if (index >= size) // If the index reaches or exceeds the size of the array, stop the function.
    {
        return;
    }

    minVal = std::min(minVal, ar[index]); // Finds the minimum value between the current minimum and the value at the current index.
    maxVal = std::max(maxVal, ar[index]); // Finds the maximum value between the current maximum and the value at the current index.

    findMinMax(ar, size, index + 1, maxVal, minVal); // Recursively call the function with an increased index.
}

int main()
{
    int array[] = { 1,2,3,4,5 }; // An example array.

    int size = sizeof(array) / sizeof(array[0]); // Computes the size of the array.
    int element = 8; // The element to be searched for in the array.
    int element2 = 3; // Another element to be searched for in the array.

    // Search for the elements in the array and store the result.
    bool search = recusArray(array, size, element);
    bool search2 = recusArray(array, size, element2);

    // Print whether the elements were found in the array or not.
    search ? std::cout << "Element " << element << " was found!" << std::endl : std::cout << "Element " << element << " was NOT found!" << std::endl;
    search2 ? std::cout << "Element " << element2 << " was found!" << std::endl : std::cout << "Element " << element << " was NOT found!" << std::endl;

    int maxVal = array[0], minVal = array[0]; // Initialize maximum and minimum values to the first element in the array.

    // Find minimum and maximum values in the array.
    findMinMax(array, size, 0, maxVal, minVal);

    // Print minimum and maximum values.
    std::cout << "Maximum value: " << maxVal << std::endl;
    std::cout << "Minimum value: " << minVal << std::endl;

    return 0;
}
