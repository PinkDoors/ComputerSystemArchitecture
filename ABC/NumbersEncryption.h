#include <string.h>

//------------------------------------------------------------------------------
// SubstitutionWithNumberEncryption.h - содержит описание строки, зашифрованной заменой символов на числа.
//------------------------------------------------------------------------------

#include <fstream>


// Строка, зашифрованная заменой символов.
struct NumbersEncryption {
    std::pair<char, int> symbols[62]; // Символы, на которые заменяются исходные при шифровании.
    char encryptedString[10000]; // Зашифрованная строка.
};

// Инициализация массива пар
void Init();

// Ввод исходной строки и параметров шифрования из файла
void In(NumbersEncryption &r, char sourceString[256], std::ifstream &ifst);

// Случайный ввод строки и параметров шифрования.
void InRnd(NumbersEncryption &r);

// Вывод зашифрованной строки
void Out(NumbersEncryption &r, std::ofstream &ofst);

// Вычисление периметра прямоугольника
double EncryptString(NumbersEncryption &n);
