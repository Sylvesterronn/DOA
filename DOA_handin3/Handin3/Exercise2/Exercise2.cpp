#include <iostream>

// Function to print a line of asterisks based on the given number.
void print(int number)
{
    for (int i = 0; i < number; i++)
    {
        std::cout << " * ";
    }
}

// Function to print a triangle pattern.
// m: Starting number of asterisks in a line.
// n: Ending number of asterisks in a line.
// ascending: Flag to indicate whether the pattern is being printed in ascending or descending order (default is true).
// counter: Counter to keep track of the current line being printed (default is 0).
void triangle(int m, int n, bool ascending = true, int counter = 0)
{
    if (ascending)
    {
        if (m > n)
        {
            // If m becomes greater than n, switch to descending pattern.
            triangle(m - counter, n, false, 0);
            return;
        }

        // Print a line with m number of asterisks.
        print(m);
        std::cout << std::endl;

        // Recursively call the function to print the next line with increased number of asterisks.
        triangle(m + 1, n, true, counter + 1);
    }
    else
    {
        if (n < m)
        {
            // If n becomes less than m, terminate the function.
            return;
        }

        // Print a line with n number of asterisks.
        print(n);
        std::cout << std::endl;

        // Recursively call the function to print the next line with decreased number of asterisks.
        triangle(m, n - 1, false);
    }
}

int main()
{
    // Print a triangle pattern with 4 asterisks in the first line and 6 asterisks in the last line.
    triangle(4, 6);

    return 0;
}
