#include <iostream>
#define N 9
using namespace std;

/* A utility function to print grid */
void print(int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

// Checks whether it will be legal to assign num to the given row, col
bool isSafe(int grid[N][N], int row, int col, int num)
{
    // Check if we find the same num in the similar row , we  return false
    for (int x = 0; x < N; x++){
        if (grid[row][x] == num){
            return false;
        }
    }

    // Check if we find the same num in the similar column , we return false
    for (int x = 0; x < N; x++){
        if (grid[x][col] == num){
            return false;
        }
    }

    // Check if we find the same num in the particular 3*3 matrix, we return false
    int startRow = row - row % 3, startCol = col - col % 3;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (grid[i+startRow][j+startCol] == num){
                return false;
            }
        }
    }

    return true;
}

/* Takes a partially filled-in grid and attempts to assign values to all unassigned locations in such a way to meet the requirements for Sudoku solution (non-duplication across rows, columns, and boxes) */
bool solveSuduko(int grid[N][N], int row, int col)
{
    // Check if we have reached the 9th row i.e. end/out of 0-indexed matrix 
    if (row == N){ return true; }

    // Check if column value becomes 9 , we move to next row and column start from 0
    int next_row = 0;
    int next_col = 0;
    if (col == N-1)
    {
        next_row= row+1;
        next_col = 0;
    }
    else{
        next_row = row;
        next_col = col+1;
    }

    // Check if the current position of the grid already contains value != 0, we iterate for next column
    if (grid[row][col] !=  0){
        return solveSuduko(grid, next_row, next_col);
    }
    else{
        for (int num = 1; num <= N; num++)
        {
            // Check if it is safe to place the num (1-9) in the given row ,col ->we move to next column
            if (isSafe(grid, row, col, num))
            {
                /* Assigning the num in the current (row,col) position of the grid and assuming our assined num in the position is correct */
                grid[row][col] = num;

                // Checking for next possibility with next column
                if (solveSuduko(grid, next_row, next_col)){
                    return true;
                }

                // Removing the assigned num , since our assumption was wrong , and we go for next assumption with diff num value
                grid[row][col] = 0;
            }
        }
    }
    return false;
}

// Driver Code
int main()
{
    // 0 means unassigned cells
    // int grid[N][N] = {
    //     {3, 0, 6, 5, 0, 8, 4, 0, 0},
    //     {5, 2, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 8, 7, 0, 0, 0, 0, 3, 1},
    //     {0, 0, 3, 0, 1, 0, 0, 8, 0},
    //     {9, 0, 0, 8, 6, 3, 0, 0, 5},
    //     {0, 5, 0, 0, 9, 0, 6, 0, 0},
    //     {1, 3, 0, 0, 0, 0, 2, 5, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 7, 4},
    //     {0, 0, 5, 2, 0, 6, 3, 0, 0}
    // };

    int grid[N][N] = {
        {4, 0, 8, 0, 7, 0, 0, 5, 2},
        {0, 0, 0, 9, 0, 0, 1, 0, 7},
        {0, 0, 6, 0, 0, 0, 8, 0, 0},
        {0, 0, 0, 0, 5, 0, 0, 0, 6},
        {5, 0, 4, 0, 0, 0, 0, 0, 8},
        {0, 8, 0, 2, 0, 7, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {9, 0, 0, 0, 0, 0, 3, 0, 0},
        {0, 2, 1, 3, 0, 5, 9, 0, 0}
    };

    if (solveSuduko(grid, 0, 0)){
        print(grid);
    }
    else{
        cout << "No solution possible!" << endl;
    }

    return 0;
}
