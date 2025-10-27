#include "CaesarCipher.h"
#include <iostream>
#include <algorithm>
#include <vector>

// Constructor
CaesarCipher::CaesarCipher(const std::string& text) : encryptedText(text) {}

// Private method to find the decryption key
int CaesarCipher::findKey() {
    if (encryptedText.empty()) {
        return 0;
    }

    std::map<char, int> freq;
    for (char c : encryptedText) {
        if (isalpha(c)) {
            freq[tolower(c)]++;
        }
    }

    if (freq.empty()) {
        return 0;
    }

    auto max_it = std::max_element(freq.begin(), freq.end(),
        [](const std::pair<const char, int>& a, const std::pair<const char, int>& b) {
            return a.second < b.second;
        });

    // The most common letter in English is 'e'
    int key = (max_it->first - 'e' + 26) % 26;
    return key;
}

// Public method to decrypt the text
std::string CaesarCipher::decrypt() {
    int key = findKey();
    std::string decryptedText = "";
    for (char c : encryptedText) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            decryptedText += static_cast<char>((c - base - key + 26) % 26 + base);
        } else {
            decryptedText += c;
        }
    }
    return decryptedText;
}
