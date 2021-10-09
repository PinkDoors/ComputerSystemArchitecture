#include <string.h>

//------------------------------------------------------------------------------
// SymbolsEncryption.h - содержит описание строки, зашифрованной заменой символов на другие символы.
//------------------------------------------------------------------------------

#include <fstream>


// Строка, зашифрованная заменой символов.
struct SymbolsEncryption {
    char encryptedString[256]; // Зашифрованная строка.
    struct PairOfCharChar {
        char first;
        char second;
    } *symbols;
};

// Ввод исходной строки и параметров шифрования из файла
void In(SymbolsEncryption &s, char sourceString[256], int size, std::ifstream &ifst);

// Случайный ввод строки и параметров шифрования.
void InRnd(SymbolsEncryption &r, char sourceString[256], int size);

// Вывод зашифрованной строки
void Out(SymbolsEncryption &r, int size, std::ofstream &ofst);
