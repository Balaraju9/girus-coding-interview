
code for the problem 

// sudoku_validator.cpp
// Problem 1: Sudoku Validator With Custom Zones
// Author: Balu 

// Including required headers
#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Function to check if numbers in a vector are unique (1–9, ignoring 0)
// I added this because sir said unique checking is important for Sudoku
bool checkUnique(vector<int> nums) {
    set<int> st; // to store seen numbers
    for (int num : nums) {
        if (num == 0) continue; // 0 means empty, so ignore
        if (num < 1 || num > 9 || st.count(num)) {
            // sir said numbers should be between 1-9 and no repeats
            return false;
        }
        st.insert(num); // add to set
    }
    return true; // all good
}

int main() {
    // Sudoku board – 0 means empty
    vector<vector<int>> board = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    // Custom zone mapping (sir told us to handle custom zones)
    vector<vector<int>> zones = {
        {1,1,1,2,2,2,3,3,3},
        {1,1,1,2,2,2,3,3,3},
        {1,1,1,2,2,2,3,3,3},
        {4,4,4,5,5,5,6,6,6},
        {4,4,4,5,5,5,6,6,6},
        {4,4,4,5,5,5,6,6,6},
        {7,7,7,8,8,8,9,9,9},
        {7,7,7,8,8,8,9,9,9},
        {7,7,7,8,8,8,9,9,9}
    };

    // Checking rows
    for (int i = 0; i < 9; ++i) {
        if (!checkUnique(board[i])) {
            cout << "Sir, Row " << i+1 << " is invalid!" << endl;
            return 0;
        }
    }

    // Checking columns
    for (int j = 0; j < 9; ++j) {
        vector<int> col;
        for (int i = 0; i < 9; ++i) {
            col.push_back(board[i][j]);
        }
        if (!checkUnique(col)) {
            cout << "Sir, Column " << j+1 << " is invalid!" << endl;
            return 0;
        }
    }

    // Checking 3x3 boxes (sir told us these are the classic boxes)
    for (int r = 0; r < 9; r += 3) {
        for (int c = 0; c < 9; c += 3) {
            vector<int> box;
            for (int i = r; i < r + 3; ++i) {
                for (int j = c; j < c + 3; ++j) {
                    box.push_back(board[i][j]);
                }
            }
            if (!checkUnique(box)) {
                cout << "Sir, 3x3 box starting at (" << r+1 << "," << c+1 << ") is invalid!" << endl;
                return 0;
            }
        }
    }

    // Checking custom zones (sir told us these can be different shapes too)
    for (int zone = 1; zone <= 9; ++zone) {
        vector<int> zoneCells;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (zones[i][j] == zone) {
                    zoneCells.push_back(board[i][j]);
                }
            }
        }
        if (!checkUnique(zoneCells)) {
            cout << "Sir, Custom zone " << zone << " is invalid!" << endl;
            return 0;
        }
    }

    // If everything is valid
    cout << "Sir, the Sudoku board is valid!" << endl;
    return 0;
}



 How to Compile and Run
   g++ sudoku_validator.cpp -o sudoku_validator
   ./sudoku_validator
