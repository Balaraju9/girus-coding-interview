
// mini_interpreter.cpp
// Bonus: Mini Interpreter
// Author: Balu (sir, I tried to make it modular and respectful 🙏)

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;

// Map to store variable values
unordered_map<string, int> memory;

// Function to evaluate simple expressions like "x + 3"
int computeValue(const string& input) {
    stringstream stream(input);
    string part;
    int outcome = 0;
    char operation = '+'; // default operator

    while (stream >> part) {
        int num;

        // if token is a variable
        if (isalpha(part[0])) {
            num = memory[part]; // get value from map
        } else {
            num = stoi(part); // convert to int
        }

        // perform operation
        if (operation == '+') outcome += num;
        else if (operation == '-') outcome -= num;
        else if (operation == '*') outcome *= num;
        else if (operation == '/') outcome /= num;

        stream >> operation; // get next operator
    }

    return outcome;
}

// Function to handle if condition
bool checkCondition(const string& expression) {
    string lhs, op, rhs;
    stringstream condStream(expression);
    condStream >> lhs >> op >> rhs;

    int val1 = isalpha(lhs[0]) ? memory[lhs] : stoi(lhs);
    int val2 = isalpha(rhs[0]) ? memory[rhs] : stoi(rhs);

    if (op == "==") return val1 == val2;
    if (op == ">") return val1 > val2;
    if (op == "<") return val1 < val2;

    return false;
}

int main() {
    cout << "Sir, this is the mini interpreter. Type 'exit' to stop." << endl;

    string inputLine;
    while (getline(cin, inputLine)) {
        if (inputLine == "exit") break;

        if (inputLine.substr(0, 3) == "let") {
            // handle let statement
            size_t equals = inputLine.find('=');
            string identifier = inputLine.substr(4, equals - 4);
            string expression = inputLine.substr(equals + 1);
            identifier.erase(remove(identifier.begin(), identifier.end(), ' '), identifier.end()); // trim spaces
            int result = computeValue(expression);
            memory[identifier] = result;
            cout << "Sir, stored " << identifier << " = " << result << endl;
        }
        else if (inputLine.substr(0, 2) == "if") {
            // handle if condition
            string conditionText = inputLine.substr(3);
            bool verdict = checkCondition(conditionText);
            cout << "Sir, condition is " << (verdict ? "true" : "false") << endl;
        }
        else {
            cout << "Sir, invalid command. Please use 'let' or 'if'." << endl;
        }
    }

    return 0;
}
