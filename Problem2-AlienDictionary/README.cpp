// alien_dictionary.cpp
// Problem 2: Alien Dictionary
// Author: balu, with respect to sir

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

// Function to find alien dictionary order
string alienOrder(vector<string>& words) {
    // Step 1: Create adjacency list and in-degree count
    map<char, set<char>> adj;
    map<char, int> indegree;

    // Initialize indegree for all unique letters
    for (auto& word : words) {
        for (char ch : word) {
            indegree[ch] = 0; // start with 0 indegree
        }
    }

    // Step 2: Build graph by comparing adjacent words
    for (int i = 0; i < words.size() - 1; ++i) {
        string w1 = words[i];
        string w2 = words[i + 1];
        int len = min(w1.size(), w2.size());
        bool found = false;

        for (int j = 0; j < len; ++j) {
            char c1 = w1[j];
            char c2 = w2[j];
            if (c1 != c2) {
                // Add edge c1 -> c2
                if (!adj[c1].count(c2)) {
                    adj[c1].insert(c2);
                    indegree[c2]++;
                }
                found = true;
                break;
            }
        }
        // Sir said: if w1 is longer but a prefix, invalid case
        if (!found && w1.size() > w2.size()) {
            return ""; // invalid dictionary
        }
    }

    // Step 3: Topological sort using BFS (Kahn's algo)
    queue<char> q;
    for (auto& p : indegree) {
        if (p.second == 0) {
            q.push(p.first);
        }
    }

    string order = "";
    while (!q.empty()) {
        char curr = q.front();
        q.pop();
        order += curr;

        for (char nei : adj[curr]) {
            indegree[nei]--;
            if (indegree[nei] == 0) {
                q.push(nei);
            }
        }
    }

    // Sir said: check if we could include all letters
    if (order.size() != indegree.size()) {
        return ""; // cycle detected
    }

    return order;
}

int main() {
    // Sir gave this example words list to test
    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};

    string result = alienOrder(words);

    if (result.empty()) {
        cout << "Sir, the dictionary is invalid (cycle or order issue)." << endl;
    } else {
        cout << "Sir, the alien alphabet order is: " << result << endl;
    }

    return 0;
}
