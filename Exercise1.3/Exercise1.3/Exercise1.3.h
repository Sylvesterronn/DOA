#pragma once
#include <iostream>
#include <vector>
#include <algorithm>


// Function to create a sorted matrix of size N x N
std::vector<std::vector<int>> createSortedMatrix(int N) {
    // Create a 2D vector (matrix) of size N x N and initialize all elements to 0
    std::vector<std::vector<int>> matrix(N, std::vector<int>(N, 0));

    int value = 1;

    // Loop through each row and column to fill the matrix with incrementing values
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = value++;
        }
    }

    return matrix; 
}

// Function to print a matrix to the console
void printMatrix(std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int value : row) {
            std::cout << value << "\t"; 
        }
        std::cout << std::endl; 
    }
}

// Function to search for a value (x) in a sorted matrix
bool SearchValue(const std::vector<std::vector<int>>& matrix, int x) {
    int rows = matrix.size(); // Get the number of rows in the matrix
    int cols = matrix[0].size(); // Get the number of columns in the matrix
    int row = 0;
    int col = cols - 1; // Start the search from the top-right corner of the matrix

    while (row < rows && col >= 0) {
        int current_value = matrix[row][col]; // Get the current value in the matrix

        if (current_value == x) {
            return true; // If the current value is equal to the target value, return true
        }
        else if (current_value < x) {
            row++; // Move down in the matrix if the current value is less than the target value
        }
        else {
            col--; // Move left in the matrix if the current value is greater than the target value
        }
    }

    return false; // If the target value is not found in the matrix, return false
}