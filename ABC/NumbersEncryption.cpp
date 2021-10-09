#include <iostream>
#include "NumbersEncryption.h"

// Инициализация массива пар [символ, число]
void Init(NumbersEncryption &n) {
    n.symbols = new NumbersEncryption::PairOfCharInt[62];
    int numberOfSymbol = 0;
    for (int i = 0; i < 10; ++i) {
        n.symbols[numberOfSymbol].first = i + 48;
        n.symbols[numberOfSymbol].second = 0;
        ++numberOfSymbol;
    }
    for (int i = 17; i < 43; ++i) {
        n.symbols[numberOfSymbol].first = i + 48;
        n.symbols[numberOfSymbol].second = 0;
        ++numberOfSymbol;
    }
    for (int i = 49; i < 75; ++i) {
        n.symbols[numberOfSymbol].first = i + 48;
        n.symbols[numberOfSymbol].second = 0;
        ++numberOfSymbol;
    }
}

// Ввод параметров шифрования из файла
void In(NumbersEncryption &n, char sourceString[256], int size, std::ifstream &ifst) {
    Init(n);
    int numberOfSymbols;
    ifst >> numberOfSymbols;
    for (int i = 0; i < numberOfSymbols; ++i) {
        char oldSymbol;
        int newInteger;
        ifst >> oldSymbol >> newInteger;
        for (int j = 0; j < 62; ++j) {
            if (n.symbols[j].first == oldSymbol) {
                n.symbols[j].second = newInteger;
            }
        }
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 62; ++j) {
            if (sourceString[i] == n.symbols[j].first) {
                n.encryptedString[i] = n.symbols[j].second;
            }
        }
    }
}

// Случайный ввод параметров шифрования
void InRnd(NumbersEncryption &n, char sourceString[256], int size) {
    Init(n);
    for (int j = 0; j < 62; ++j) {
        int newInteger = rand() % 1000;
        n.symbols[j].second = newInteger;
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 62; ++j) {
            if (sourceString[i] == n.symbols[j].first) {
                n.encryptedString[i] = n.symbols[j].second;
            }
        }
    }
}

// Вывод зашифрованной строки
void Out(NumbersEncryption &n, int size, std::ofstream &ofst) {
    ofst << "Result of the encryption: ";
    for (int i = 0; i < size; ++i) {
        ofst << n.encryptedString[i];
    }
    ofst << ".\n";
}

