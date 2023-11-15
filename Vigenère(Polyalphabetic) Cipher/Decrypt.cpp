#include <iostream>
#include <string>

using namespace std;

string Decrypt(const string& ciphertext, const string& key) {
    string plaintext = "";

    for (size_t i = 0; i < ciphertext.length(); ++i) {
        char cipherChar = ciphertext[i];
        char keyChar = key[i % key.length()]; 

        if (isupper(cipherChar)) {
            int decryptedChar = (cipherChar - keyChar + 26) % 26 + 'A';
            plaintext += static_cast<char>(decryptedChar);
        }
        else if (islower(cipherChar)) {
            int decryptedChar = (cipherChar - keyChar + 26) % 26 + 'a';
            plaintext += static_cast<char>(decryptedChar);
        }

        else {
            plaintext += cipherChar;
        }
    }

    return plaintext;
}

int main() {
    string ciphertext;
    string key = "PATAPON";  

    cout << "Enter ciphertext: ";
    getline(cin, ciphertext);

    string plaintext = Decrypt(ciphertext, key);

    cout << "Decrypted text: " << plaintext << endl;

    return 0;
}