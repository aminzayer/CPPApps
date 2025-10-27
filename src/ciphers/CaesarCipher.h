#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

#include <string>
#include <map>

class CaesarCipher {
public:
    CaesarCipher(const std::string& encryptedText);
    std::string decrypt();

private:
    std::string encryptedText;
    int findKey();
};

#endif // CAESAR_CIPHER_H
