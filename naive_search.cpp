#include <iostream>
#include <vector>
#include <string>

/*
#include <cctype>  // For std::tolower
// Inside the naiveSearch function, modify the comparison:
if (std::tolower(text[i + j]) != std::tolower(pattern[j])) {
    matchFound = false;
    break;
}
*/

using namespace std;

vector<int> naiveSearch(const string& text, const string& pattern) {
    vector<int> matches;
    int n = text.length();
    int m = pattern.length();

    // Loop through the text
    for (int i = 0; i <= n - m; i++) {
        bool matchFound = true;

        // Check for pattern match at current position
        for (int j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                matchFound = false;
                break;  // Mismatch found, break out of inner loop
            }
        }

        // If match is found, record the index
        if (matchFound) {
            matches.push_back(i);
        }
    }

    return matches;
}

int main() {
    string text = "THIS IS A SIMPLE EXAMPLE";
    string pattern = "EXAMPLE";

    vector<int> result = naiveSearch(text, pattern);

    if (result.empty()) {
        cout << "Pattern not found in the text." << endl;
    } else {
        for (int index : result) {
            cout << "Pattern found at index: " << index << endl;
        }
    }

    return 0;
}
