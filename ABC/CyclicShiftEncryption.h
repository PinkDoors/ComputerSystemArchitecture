#include <string.h>

//------------------------------------------------------------------------------
// CyclicShiftEncryption.h - содержит описание строки, зашифрованной циклическим сдвигом кода каждого символа на n.
//------------------------------------------------------------------------------

#include <fstream>

// Строка, зашифрованная циклическим сдвигом кода каждого символа.
struct CyclicShiftEncryption {
    char encryptedString[256]; // Зашифрованная строка.
    short shift;
};

// Ввод исходной строки и параметров шифрования из файла
void In(CyclicShiftEncryption &r, char sourceString[256], int size, std::ifstream &ifst);

// Случайный ввод строки и параметров шифрования.
void InRnd(CyclicShiftEncryption &r,char sourceString[256], int size);

// Вывод зашифрованной строки
void Out(CyclicShiftEncryption &r, int size, std::ofstream &ofst);
