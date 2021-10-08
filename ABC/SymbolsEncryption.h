#include <string.h>

//------------------------------------------------------------------------------
// SubstitutionWithSymbolsEncryption.h - содержит описание строки, зашифрованной заменой символов на числа.
//------------------------------------------------------------------------------

#include <fstream>


// Строка, зашифрованная заменой символов.
struct SymbolsEncryption {
    std::pair<char, char> symbols[62]; // Символы, на которые заменяются исходные при шифровании.
    char encryptedString[10000]; // Зашифрованная строка.
};

// Ввод исходной строки и параметров шифрования из файла
void In(SymbolsEncryption &s, char sourceString[256], std::ifstream &ifst);

// Случайный ввод строки и параметров шифрования.
void InRnd(SymbolsEncryption &r);

// Вывод зашифрованной строки
void Out(SymbolsEncryption &r, std::ofstream &ofst);

// Вычисление периметра прямоугольника
double EncryptString(SymbolsEncryption &s);
