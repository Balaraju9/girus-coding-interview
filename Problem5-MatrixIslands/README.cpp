
// matrix_islands_diagonal.cpp
// Problem 5: Matrix Islands with Diagonals
// Author: Balu 

#include <iostream>
#include <vector>
using namespace std;

// Directions: 8-way (horizontal, vertical, diagonal)
int dirX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dirY[] = {-1,  0,  1, -1, 1, -1, 0, 1};

// Sir, this function does DFS to mark visited 1s
void exploreIsland(int row, int col, vector<vector<int>>& landMap, vector<vector<bool>>& seen) {
    int rows = landMap.size();
    int cols = landMap[0].size();
    seen[row][col] = true;

    for (int d = 0; d < 8; d++) {
        int newRow = row + dirX[d];
        int newCol = col + dirY[d];
        if (newRow >= 0 && newCol >= 0 && newRow < rows && newCol < cols &&
            landMap[newRow][newCol] == 1 && !seen[newRow][newCol]) {
            exploreIsland(newRow, newCol, landMap, seen); // visit connected cell
        }
    }
}

int main() {
    // Sir, this is our input grid (1 = land, 0 = water)
    vector<vector<int>> landMap = {
        {1, 1, 0, 0},
        {0, 1, 0, 0},
        {1, 0, 0, 1},
        {0, 0, 1, 1}
    };

    int rows = landMap.size();
    int cols = landMap[0].size();
    vector<vector<bool>> seen(rows, vector<bool>(cols, false));

    int totalIslands = 0;

    // Going through every cell
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (landMap[r][c] == 1 && !seen[r][c]) {
                totalIslands++;
                exploreIsland(r, c, landMap, seen); // explore the whole island
            }
        }
    }

    cout << "Sir, total number of islands (with diagonals) is: " << totalIslands << endl;
    return 0;
}
