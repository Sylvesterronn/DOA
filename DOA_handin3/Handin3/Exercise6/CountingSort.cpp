#include <iostream>

void countingSort(int arr[], int n, int k) {
    int* count = new int[k + 1](); // Initialize count array with zeros

    // Count occurrences of each element in arr
    for (int i = 0; i < n; ++i) {
        count[arr[i]]++;
    }

    // Build the sorted array
    int index = 0;
    for (int i = 0; i <= k; ++i) {
        while (count[i]-- > 0) {
            arr[index++] = i;
        }
    }

    // Free dynamically allocated memory
    delete[] count;
}

int main() {
    // Example usage
    int arr[] = { 3, 1, 4, 1, 5, 3, 6, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 9; // Range of integers [0, k]

    //Output unsorted array
    std::cout << "Sorted array before Counting sort: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    countingSort(arr, n, k);

    // Output sorted array
    std::cout << "Sorted array after Counting sort: " << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
