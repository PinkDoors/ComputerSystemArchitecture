#include <string.h>

//------------------------------------------------------------------------------
// NumbersEncryption.h - содержит описание строки, зашифрованной заменой символов на числа.
//------------------------------------------------------------------------------

#include <fstream>


// Строка, зашифрованная заменой символов.
struct NumbersEncryption {
    int encryptedString[256]; // Зашифрованная строка.
    struct PairOfCharInt {
        char first;
        int second;
    } *symbols;
};

// Ввод исходной строки и параметров шифрования из файла
void In(NumbersEncryption &r, char sourceString[256], int size, std::ifstream &ifst);

// Случайный ввод строки и параметров шифрования.
void InRnd(NumbersEncryption &r, char sourceString[256], int size);

// Вывод зашифрованной строки
void Out(NumbersEncryption &r, int size, std::ofstream &ofst);

