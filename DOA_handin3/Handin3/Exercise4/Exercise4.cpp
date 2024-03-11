//#include<iostream>
//
//#define ROWS 5
//#define COLS 5
//
// Function to print the maze
//bool findE(char maze[ROWS][COLS],int rows,int cols, bool validemove=true) 
//{
//
//    if (maze[rows][cols] != 'E')
//    {
//        return true;
//    }
//
//    if (maze[rows][cols] == 'X')
//    {
//        validemove = false;
//    }
//
//    if (rows>0&&rows<ROWS&&cols>0&&cols<COLS&& validemove)
//    {
//
//         Recursive calls for the neighboring cells
//        findE(maze, rows - 1, cols);  // Up
//        findE(maze, rows + 1, cols);  // Down
//        findE(maze, rows, cols - 1);  // Left
//        findE(maze, rows, cols + 1);  // Right
//
//    }
//
//    return false;
//}
//
//
//void printMaze(char maze[ROWS][COLS]) {
//    for (int i = 0; i < ROWS; ++i) {
//        for (int j = 0; j < COLS; ++j) {
//            std::cout << maze[i][j] << ' ';
//        }
//        std::cout << '\n';
//    }
//}
//
//
//int main()
//{
//    char maze[ROWS][COLS] = {
//        {'X', 'X', 'X', 'X', 'X'},
//        {'X', ' ', ' ', ' ', 'X'},
//        {'X', ' ', 'X', ' ', 'X'},
//        {'X', 'X', 'X', ' ', 'X'},
//        {'X', 'E', 'X', 'X', 'X'}
//    };
//
//
//    printMaze(maze);
//    bool E=findE(maze,0,0);
//
//    (E == true) ? std::cout << "E was found " << std::endl : std::cout << "E was not found" << std::endl;
//
//    char maze1[ROWS][COLS] = {
//    {' ', 'X', 'X', 'X', 'X'},
//    {' ', ' ', ' ', ' ', 'X'},
//    {'E', ' ', 'X', ' ', 'X'},
//    {'X', ' ', 'X', ' ', 'X'},
//    {'X', 'X', 'X', 'X', 'X'}
//    };
//
//    printMaze(maze1);
//    bool E1 = findE(maze1, 0, 0);
//
//    (E1 == true) ? std::cout << "E was found " << std::endl : std::cout << "E was not found" << std::endl;
//
//    return 0;
//
//}


#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 5;
const int COLS = 5;

bool solveMazeUtil(int row, int col, vector<vector<char>>& maze) {
    // Base case: If the current position is out of bounds or marked as 'X', return false
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS || maze[row][col] == 'X') {
        return false;
    }

    // Base case: If the current position is the exit ('E'), return true
    if (maze[row][col] == 'E') {
        return true;
    }

    // Mark the current position as visited by changing its value to 'X'
    char original = maze[row][col];
    maze[row][col] = 'X';

    // Recursive calls for exploring all possible directions
    bool foundPath = solveMazeUtil(row + 1, col, maze) || // Down
        solveMazeUtil(row - 1, col, maze) || // Up
        solveMazeUtil(row, col + 1, maze) || // Right
        solveMazeUtil(row, col - 1, maze);   // Left

    // Restore the original value of the current position
    maze[row][col] = original;

    return foundPath;
}

bool solveMaze(vector<vector<char>>& maze) {
    // Start the traversal from position (1, 1)
    return solveMazeUtil(1, 1, maze);
}

int main() {
    vector<vector<char>> maze = {
        {'X','X','X','X','X'},
        {'X',' ',' ',' ','X'},
        {'X',' ','X',' ','X'},
        {'X',' ','X',' ','X'},
        {'X','E','X','X','X'}
    };


    //Printing out the Maze... 
    for (const auto& row : maze) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
        //Printing if there is an exit or not
        if (solveMaze(maze)) {
            cout << "Path to exit exists!" << endl;
        }
        else {
            cout << "No path to exit!" << endl;
        }

        vector<vector<char>> maze1 = {
            {'X','X','X','X','X'},
            {'X',' ',' ',' ','X'},
            {'X',' ','X',' ','X'},
            {'X','X','X',' ','X'},
            {'X','E','X','X','X'}
        };

        //Printing out the other Maze
        for (const auto& row : maze1) {
            for (char cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }

        //Printing if there is an exit or not
        if (solveMaze(maze1)) {
            cout << "Path to exit exists!" << endl;
        }
        else {
            cout << "No path to exit!" << endl;
        }

        return 0;
    
}
