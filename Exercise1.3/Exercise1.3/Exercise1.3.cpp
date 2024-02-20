#include"Exercise1.3.h"

int main()
{

	int N;

	std::cout << "Skriv et N tal: " << std::endl;
	std::cin >> N;

	std::vector<std::vector<int>> sortedMatrix=createSortedMatrix(N);
	printMatrix(sortedMatrix);


	std::cout << "Value 2 2:" << sortedMatrix[2][2];

	int x = 10;
	bool find=SearchValue(sortedMatrix, x);
	
	std::cout << "Is " << x << " present in the matrix? " << (find ? "Yes" : "No") << std::endl;

	return 0;
}