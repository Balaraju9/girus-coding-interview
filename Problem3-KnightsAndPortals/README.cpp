
// knights_and_portals.cpp
// Problem 3: Knights and Portals
// Author: Balu  

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> Position; // to store coordinates

// Directions: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Sir, this function checks if the cell is inside the grid and not a wall
bool isAllowed(int row, int col, int rows, int cols, vector<vector<int>>& matrix) {
    return row >= 0 && col >= 0 && row < rows && col < cols && matrix[row][col] == 0;
}

// Standard BFS function to find shortest distances from a point
vector<vector<int>> performBFS(int startX, int startY, vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX));
    queue<Position> q;
    q.push({startX, startY});
    distance[startX][startY] = 0;

    while (!q.empty()) {
        Position current = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nextX = current.first + dx[dir];
            int nextY = current.second + dy[dir];
            if (isAllowed(nextX, nextY, rows, cols, matrix) && distance[nextX][nextY] == INT_MAX) {
                distance[nextX][nextY] = distance[current.first][current.second] + 1;
                q.push({nextX, nextY});
            }
        }
    }
    return distance;
}

int main() {
    // Sir, this is our grid (0 = empty cell, 1 = wall)
    vector<vector<int>> matrix = {
        {0, 1, 0, 0},
        {0, 1, 0, 1},
        {0, 0, 0, 0},
        {1, 1, 1, 0}
    };

    int rows = matrix.size();
    int cols = matrix[0].size();

    // BFS from start (0,0) and end (rows-1,cols-1)
    vector<vector<int>> fromStart = performBFS(0, 0, matrix);
    vector<vector<int>> fromEnd = performBFS(rows - 1, cols - 1, matrix);

    int result = fromStart[rows - 1][cols - 1]; // direct path without teleport
    if (result == INT_MAX) result = -1; // no path without teleport

    // Sir, let's now try teleporting between every pair of empty cells
    for (int x1 = 0; x1 < rows; ++x1) {
        for (int y1 = 0; y1 < cols; ++y1) {
            if (matrix[x1][y1] != 0 || fromStart[x1][y1] == INT_MAX) continue;
            for (int x2 = 0; x2 < rows; ++x2) {
                for (int y2 = 0; y2 < cols; ++y2) {
                    if (matrix[x2][y2] != 0 || fromEnd[x2][y2] == INT_MAX) continue;
                    if (x1 == x2 && y1 == y2) continue; // same cell, skip
                    int totalSteps = fromStart[x1][y1] + 1 + fromEnd[x2][y2]; // teleport costs 1 move
                    result = min(result, totalSteps); // update minimum
                }
            }
        }
    }

    if (result == -1 || result == INT_MAX) {
        cout << "Sir, no path is possible even with teleport." << endl;
    } else {
        cout << "Sir, shortest path length (with at most 1 teleport) is: " << result << endl;
    }

    return 0;
}
