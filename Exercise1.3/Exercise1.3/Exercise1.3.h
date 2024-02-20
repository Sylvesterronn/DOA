#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

;

std::vector<std::vector<int>> createSortedMatrix(int N) {
	std::vector<std::vector<int>> matrix(N, std::vector<int>(N, 0));

	int value = 1;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			matrix[i][j] = value++;
		}
	}

	return matrix;
}

void printMatrix(std::vector<std::vector<int>>& matrix)
{
	for (const auto& row : matrix)
	{
		for (int value : row)
		{
			std::cout << value << "\t";
		}

		std::cout << std::endl;

	}
}

bool SearchValue(const std::vector<std::vector<int>>& matrix, int x)
{

	//Matrix.size is N

	int rows = matrix.size();
	int cols = matrix[0].size();
	int row = 0;
	int col = cols - 1; // Start from the top-right corner

	while (row < rows && col >= 0) {
		int current_value = matrix[row][col];

		if (current_value == x) {
			return true;
		}
		else if (current_value < x) {
			row++; // Move down
		}
		else {
			col--; // Move left
		}
	}


	return false;
}

