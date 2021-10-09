#include "CyclicShiftEncryption.h"

// Ввод параметров шифровния из файла
void In(CyclicShiftEncryption &c, char sourceString[256], int size, std::ifstream &ifst) {
    ifst >> c.shift;
    for (int i = 0; i < size; ++i) {
        c.encryptedString[i] = sourceString[i] + c.shift;
    }
}

// Случайный ввод параметров шифрованя
void InRnd(CyclicShiftEncryption &c, char sourceString[256], int size) {
    c.shift = rand() % 1000;
    for (int i = 0; i < size; ++i) {
        c.encryptedString[i] = sourceString[i] + c.shift;
    }
}

// Вывод зашифрованной строки
void Out(CyclicShiftEncryption &c, int size, std::ofstream &ofst) {
    ofst << "Result of the encryption: ";
    for (int i = 0; i < size; ++i) {
        ofst << c.encryptedString[i];
    }
    ofst << ".\n";
}
