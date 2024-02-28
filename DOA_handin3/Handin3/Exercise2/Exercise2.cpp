#include <iostream>


void print(int number)
{
	for (int i = 0; i < number; i++)
	{
		std::cout << " * ";
	}
	
}

void triangle(int m, int n,bool ascending=true,int counter=0)
{
	if (ascending)
	{
		if (m>n)
		{
			triangle(m-counter,n, false,0);
			return;
		}

		print(m);
		std::cout << std::endl;
		triangle(m + 1, n, true, counter +1);
	}
	
	else
	{
		if (n<m)
		{
			return;
		}

		print(n);
		std::cout << std::endl;
		triangle(m, n-1, false);

	}

}


int main()
{

	triangle(4, 6);

	return 0;
}