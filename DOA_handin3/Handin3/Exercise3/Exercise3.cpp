
#include <iostream>
#include <vector>

// Function to print out the page arrangement for booklet printing.
void bookletPrint(int startPage, int endPage) {
    // Calculate total pages and total sheets required.
    int totalPages = endPage - startPage + 1; // Total number of pages to print.
    int totalSheets = totalPages / 4; // Total number of sheets needed, assuming 4 pages per sheet.

    // Iterate through each sheet to calculate and print page positions.
    for (int sheet = 1; sheet <= totalSheets; ++sheet) {
        // Calculate page numbers for the front and back of the sheet.
        int frontLeft = startPage + 2 * (sheet - 1); // Page number on the front left.
        int frontRight = endPage - 2 * (sheet - 1); // Page number on the front right.
        int backLeft = frontRight - 1; // Page number on the back left (one less than front right).
        int backRight = frontLeft + 1; // Page number on the back right (one more than front left).

        // Output the arrangement of pages for the current sheet.
        std::cout << "Sheet " << sheet << " contains pages " << frontLeft << ", " << backRight << ", " << backLeft << ", " << frontRight << std::endl;
    }
}

int main() {
    // Example call to bookletPrint function.
    bookletPrint(1, 12); // Prints the booklet page arrangement for pages 1 through 8.
    return 0;
}
