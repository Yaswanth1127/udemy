#include <iostream>
#include <cmath>
using namespace std;

// Function to generate the key matrix from the key string
void getKeyMatrix(const string &key, int keyMatrix[][3], int size) {
    int k = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 3; j++) {
            keyMatrix[i][j] = (key[k]) % 65; // Convert ASCII to 0-25 range
            k++;
            if (k == key.length())
                break;
        }
        if (k == key.length())
            break;
    }
    if (k < size * 3) {
        for (int i = k; i < size * 3; i++)
            keyMatrix[k / 3][i % 3] = 0;
    }
}

// Function to perform matrix multiplication for encryption
void multiplyMatrix(int cipherMatrix[][1], const int keyMatrix[][3], const int messageVector[][1], int size) {
    for (int i = 0; i < size; i++) {
        cipherMatrix[i][0] = 0;
        for (int x = 0; x < 3; x++) {
            cipherMatrix[i][0] += keyMatrix[i][x] * messageVector[x][0];
        }
        cipherMatrix[i][0] %= 26; // Take modulo 26 for each element
    }
}

// Function to implement Hill Cipher
void HillCipher(const string &message, const string &key) {
    int keySize = ceil(key.length() / 3.0);

    // Get key matrix from the key string
    int keyMatrix[keySize][3];
    getKeyMatrix(key, keyMatrix, keySize);

    // Generate vector for the message
    int messageVector[3][1];
    for (size_t i = 0; i < message.size(); i++)
        messageVector[i % 3][0] = (message[i]) % 65; // Convert ASCII to 0-25 range

    // Create cipher matrix
    int cipherMatrix[keySize][1];

    // Perform matrix multiplication for encryption
    multiplyMatrix(cipherMatrix, keyMatrix, messageVector, keySize);

    // Generate the encrypted text from the encrypted vector
    string cipherText;
    for (int i = 0; i < keySize; i++)
        cipherText += cipherMatrix[i][0] + 65; // Convert back to ASCII

    // Print the ciphertext
    cout << "Ciphertext: " << cipherText << endl;
}

int main() {
    // Get the message to be encrypted
    string message;
    cout << "Enter the message: ";
    getline(cin, message);

    // Get the key
    string key;
    cout << "Enter the key: ";
    getline(cin, key);

    // Call HillCipher function
    HillCipher(message, key);

    return 0;
}
