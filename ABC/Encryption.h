#ifndef __shape__
#define __shape__

//------------------------------------------------------------------------------
// Encryption.h - содержит описание обобщающей зашифрованной строки,
//------------------------------------------------------------------------------

#include "CyclicShiftEncryption.h"
#include "NumbersEncryption.h"
#include "SymbolsEncryption.h"

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся фигуры
struct Encryption {
    // значения ключей для каждой из фигур
    enum key {Cyclic, Numbers, Symbols};
    key k; // ключ
    // используемые альтернативы
    union { // используем простейшую реализацию
        CyclicShiftEncryption c;
        NumbersEncryption n;
        SymbolsEncryption s;
    };
    char sourceString[256]; // Исходная строка.
};

// Ввод обобщенной фигуры
Encryption *In(std::ifstream &ifdt);

// Случайный ввод обобщенной фигуры
Encryption *InRnd();

// Вывод обобщенной фигуры
void Out(Encryption &e, std::ofstream &ofst);

// Вычисление периметра обобщенной фигуры
//double EncryptString(&s);

#endif
