#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    string key, origin;
    cout << "Enter the message: ";
    getline(cin, origin);
    cout << "Enter the key: ";
    cin >> key;

    // Remove spaces and non-alphabetic characters from the input message
    string s;
    for (char c : origin) {
        if (isalpha(c))
            s += toupper(c); // Convert to uppercase
    }

    // Remove duplicates from the key
    string cleanedKey;
    map<char, bool> keyMap;
    for (char c : key) {
        if (isalpha(c) && !keyMap[toupper(c)]) {
            cleanedKey += toupper(c);
            keyMap[toupper(c)] = true;
        }
    }

    // Populate the Playfair matrix
    vector<vector<char>> matrix(5, vector<char>(5));
    int row = 0, col = 0;
    for (char c : cleanedKey) {
        matrix[row][col] = c;
        col++;
        if (col == 5) {
            col = 0;
            row++;
        }
    }
    
    // Fill the matrix with remaining characters
    char ch = 'A';
    while (row < 5) {
        while (col < 5) {
            if (!keyMap[ch]) {
                matrix[row][col] = ch;
                keyMap[ch] = true;
                col++;
            }
            ch++;
        }
        col = 0;
        row++;
    }

    // Construct a map to quickly find the position of each character in the matrix
    map<char, pair<int, int>> charPos;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            charPos[matrix[i][j]] = make_pair(i, j);
        }
    }

    // Encryption
    string encrypted;
    for (int i = 0; i < s.size(); i += 2) {
        char a = s[i];
        char b = (i + 1 < s.size()) ? s[i + 1] : 'X'; // Padding if necessary
        if (a == b) b = 'X'; // Handling repeated characters

        int rowA = charPos[a].first;
        int colA = charPos[a].second;
        int rowB = charPos[b].first;
        int colB = charPos[b].second;

        if (rowA == rowB) {
            encrypted += matrix[rowA][(colA + 1) % 5];
            encrypted += matrix[rowB][(colB + 1) % 5];
        } else if (colA == colB) {
            encrypted += matrix[(rowA + 1) % 5][colA];
            encrypted += matrix[(rowB + 1) % 5][colB];
        } else {
            encrypted += matrix[rowA][colB];
            encrypted += matrix[rowB][colA];
        }
    }

    cout << "Encrypted message: " << encrypted << endl;

    return 0;
}
