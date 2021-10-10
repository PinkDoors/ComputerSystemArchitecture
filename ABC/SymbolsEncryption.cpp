#include <iostream>
#include "SymbolsEncryption.h"

// Инициализация массива пар [символ, символ]
void Init(SymbolsEncryption &s) {
    s.symbols = new SymbolsEncryption::PairOfCharChar[62];
    int numberOfSymbol = 0;
    for (int i = 0; i < 10; ++i) {
        s.symbols[numberOfSymbol].first = i + 48;
        s.symbols[numberOfSymbol].second = i + 48;
        ++numberOfSymbol;
    }
    for (int i = 17; i < 43; ++i) {
        s.symbols[numberOfSymbol].first = i + 48;
        s.symbols[numberOfSymbol].second = i + 48;
        ++numberOfSymbol;
    }
    for (int i = 49; i < 75; ++i) {
        s.symbols[numberOfSymbol].first = i + 48;
        s.symbols[numberOfSymbol].second = i + 48;
        ++numberOfSymbol;
    }
}

// Ввод параметров шифрования из файла
void In(SymbolsEncryption &s, char sourceString[256],int size, std::ifstream &ifst) {
    Init(s);
    int numberOfSymbols = 0;
    ifst >> numberOfSymbols;
    for (int i = 0; i < numberOfSymbols; ++i) {
        char oldSymbol;
        char newSymbol;
        ifst >> oldSymbol >> newSymbol;
        for (int j = 0; j < 62; ++j) {
            if (s.symbols[j].first == oldSymbol)
            {
                s.symbols[j].second = newSymbol;
            }
        }
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 62; ++j) {
            if (sourceString[i] == s.symbols[j].first)
            {
                s.encryptedString[i] = s.symbols[j].second;
            }
        }
    }
}

// Случайный ввод параметров шифрования
void InRnd(SymbolsEncryption &s, char sourceString[256], int size) {
    Init(s);
    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 62; ++i) {
        int symbol = rand() % 62;
        s.symbols[i].second = alphanum[symbol];
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 62; ++j) {
            if (sourceString[i] == s.symbols[j].first) {
                s.encryptedString[i] = s.symbols[j].second;
            }
        }
    }
}

// Вывод зашифрованной строки
void Out(SymbolsEncryption &s,int size, std::ofstream &ofst) {
    ofst << "Result of the encryption: ";
    for (int i = 0; i < size; ++i) {
        ofst << s.encryptedString[i];
    }
    ofst << ".\n";
}