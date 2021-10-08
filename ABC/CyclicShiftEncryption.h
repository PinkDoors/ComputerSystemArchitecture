#include <string.h>

//------------------------------------------------------------------------------
// CyclicShiftEncryption.h - содержит описание строки, зашифрованной циклическим сдвигом кода каждого символа на n.
//------------------------------------------------------------------------------

#include <fstream>


// Строка, зашифрованная циклическим сдвигом кода каждого символа.
struct CyclicShiftEncryption {
    char encryptedString[256]; // Зашифрованная строка.
    int shift;
};

// Ввод исходной строки и параметров шифрования из файла
void In(CyclicShiftEncryption &r, char sourceString[256], std::ifstream &ifst);

// Случайный ввод строки и параметров шифрования.
void InRnd(CyclicShiftEncryption &r);

// Вывод зашифрованной строки
void Out(CyclicShiftEncryption &r, std::ofstream &ofst);

// Вычисление периметра прямоугольника
double EncryptString(CyclicShiftEncryption &c);