#include <iostream>
#include <string>

using namespace std;

string Encrypt(const string& plaintext, const string& key) {
    string ciphertext = "";

    for (size_t i = 0; i < plaintext.length(); ++i) {
        char plainChar = plaintext[i];
        char keyChar = key[i % key.length()]; 

        if (isupper(plainChar)) {
            ciphertext += static_cast<char>((plainChar + keyChar - 2 * 'A') % 26 + 'A');
        }
        else if (islower(plainChar)) {
            ciphertext += static_cast<char>((plainChar + keyChar - 2 * 'a') % 26 + 'a');
        }
        else {
            ciphertext += plainChar;
        }
    }

    return ciphertext;
}

int main() {
    string plaintext;
    string key = "PATAPON";  

    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    string ciphertext = Encrypt(plaintext, key);

    cout << "Encrypted text: " << ciphertext << endl;

    return 0;
}
