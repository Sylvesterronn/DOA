#include<iostream>

#define ROWS 5
#define COLS 5

// Function to print the maze
bool findE(char maze[ROWS][COLS],int rows,int cols, bool validemove=true) 
{

    if (maze[rows][cols] != 'E')
    {
        return true;
    }

    if (maze[rows][cols] == 'X')
    {
        validemove = false;
    }

    if (rows>0&&rows<ROWS&&cols>0&&cols<COLS&& validemove)
    {

        // Recursive calls for the neighboring cells
        findE(maze, rows - 1, cols);  // Up
        findE(maze, rows + 1, cols);  // Down
        findE(maze, rows, cols - 1);  // Left
        findE(maze, rows, cols + 1);  // Right

    }

    return false;
}


void printMaze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << maze[i][j] << ' ';
        }
        std::cout << '\n';
    }
}


int main()
{
    char maze[ROWS][COLS] = {
        {'X', 'X', 'X', 'X', 'X'},
        {'X', ' ', ' ', ' ', 'X'},
        {'X', ' ', 'X', ' ', 'X'},
        {'X', ' ', 'X', ' ', 'X'},
        {'X', 'E', 'X', 'X', 'X'}
    };


    printMaze(maze);
    bool E=findE(maze,0,0);

    (E == true) ? std::cout << "E was found " << std::endl : std::cout << "E was not found" << std::endl;

    char maze1[ROWS][COLS] = {
    {' ', 'X', 'X', 'X', 'X'},
    {' ', ' ', ' ', ' ', 'X'},
    {'E', ' ', 'X', ' ', 'X'},
    {'X', ' ', 'X', ' ', 'X'},
    {'X', 'X', 'X', 'X', 'X'}
    };

    printMaze(maze1);
    bool E1 = findE(maze1, 0, 0);

    (E1 == true) ? std::cout << "E was found " << std::endl : std::cout << "E was not found" << std::endl;

    return 0;

}
