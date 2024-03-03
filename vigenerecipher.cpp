#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    // Initialize variables
    int i, j, k, n;
    const int alphabet_size = 26;
    vector<vector<char>> grid(alphabet_size, vector<char>(alphabet_size));

    // Populate the grid with shifted alphabets
    k = 0;
    n = alphabet_size;
    for (i = 0; i < n; i++) {
        k = i;
        for (j = 0; j < n; j++) {
            grid[i][j] = 'A' + k;
            k++;
            if (k == alphabet_size) k = 0; // Wrap around to the beginning of the alphabet
        }
    }

    // Input the encrypted message and the key
    string encrypted_message, key;
    cout << "Enter the encrypted message: ";
    cin >> encrypted_message;
    cout << "Enter the key: ";
    cin >> key;

    // Extend the key to match the length of the encrypted message
    k = 0;
    for (i = key.size(); i < encrypted_message.size(); i++) {
        key += key[k];
        k++;
    }

    // Decrypt the message
    string decrypted_message;
    for (i = 0; i < encrypted_message.size(); i++) {
        for (j = 0; j < alphabet_size; j++) {
            if (grid[j][key[i] - 'A'] == encrypted_message[i]) {
                decrypted_message += 'A' + j; // Append the decrypted character to the message
                break;
            }
        }
    }

    // Output the decrypted message
    cout << "Decrypted message: " << decrypted_message << '\n';

    return 0;
}
