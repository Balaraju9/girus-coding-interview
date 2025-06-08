
// bitwise_matching_pattern.cpp
// Problem 4: Bitwise Matching Pattern
// Author: Balu  

#include <iostream>
using namespace std;

// Function to count number of 1s in binary
int countBits(int value) {
    int ones = 0;
    while (value > 0) {
        if (value & 1) ones++; // if last bit is 1
        value = value >> 1; // right shift
    }
    return ones;
}

int main() {
    int number;
    cout << "Sir, please enter a number: ";
    cin >> number;

    int bitsInOriginal = countBits(number); // how many 1s in number
    int candidate = number + 1;

    while (true) {
        if (countBits(candidate) == bitsInOriginal) {
            cout << "Sir, the next number with same 1s in binary is: " << candidate << endl;
            break;
        }
        candidate++;
    }

    return 0;
}
