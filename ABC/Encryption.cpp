#include <iostream>

//------------------------------------------------------------------------------
// Encryption.cpp - содержит процедуры связанные с шифрованием поступившей строки
//------------------------------------------------------------------------------

#include "Encryption.h"

// Ввод параметров обобщенной фигуры из файла
Encryption *In(std::ifstream &ifst) {
    Encryption *sp = new Encryption();
    int key;
    ifst >> key;
    int size;
    ifst >> size;
    if (size > 256 || size < 0) {
        std::cout << "Incorrect size of the input string, the size is set to 0" << "\n";
        size = 0;
        delete sp;
        return 0;
    }
    sp->size = size;
    if (size != 0) {
        ifst >> sp->sourceString;
    }
    switch (key) {
        case 1:
            sp->k = Encryption::Cyclic;
            In(sp->c, sp->sourceString, size, ifst);
            std::cout << "String " << "\"" << sp->sourceString << "\" was encrypted" << "\n";
            return sp;
        case 2:
            sp->k = Encryption::Numbers;
            In(sp->n, sp->sourceString, size, ifst);
            std::cout << "String " << "\"" << sp->sourceString << "\" was encrypted" << "\n";
            return sp;
        case 3:
            sp->k = Encryption::Symbols;
            In(sp->s, sp->sourceString, size, ifst);
            std::cout << "String " << "\"" << sp->sourceString << "\" was encrypted" << "\n";
            return sp;
        default:
            std::cout << "Invalid input encryption type." << "\n";
            exit(-1);
    }
}


// Случайный ввод строки и типа шифрования
Encryption *InRnd() {
    Encryption *sp = new Encryption();
    sp->size = rand() % 255;
    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < sp->size; ++i) {
        int symbol = rand() % 62;
        sp->sourceString[i] = alphanum[symbol];
    }
    auto k = rand() % 3 + 1;
    switch (k) {
        case 1:
            sp->k = Encryption::Cyclic;
            InRnd(sp->c, sp->sourceString, sp->size);
            return sp;
        case 2:
            sp->k = Encryption::Numbers;
            InRnd(sp->n, sp->sourceString, sp->size);
            return sp;
        case 3:
            sp->k = Encryption::Symbols;
            InRnd(sp->s, sp->sourceString, sp->size);
            return sp;
        default:
            return 0;
    }
}

// Вывод исходной строки, результата общей функции и зашифрованной строки в поток
void Out(Encryption &e, std::ofstream &ofst) {
    ofst << "Input string = " << e.sourceString << ".\n" << "\n";
    ofst << "The quotient of dividing the sum of "
            "the codes of an unencrypted "
            "string by the number of characters in "
            "this string = " << QuotientOfDivision(e) << ".\n" << "\n";
    switch (e.k) {
        case Encryption::Cyclic:
            Out(e.c, e.size, ofst);
            break;
        case Encryption::Numbers:
            Out(e.n, e.size, ofst);
            break;
        case Encryption::Symbols:
            Out(e.s, e.size, ofst);
            break;
        default:
            ofst << "Incorrect Encryption!" << std::endl;
    }
}

// Частное от деления суммы
//кодов незашифрованной
//строки на число символов в
//этой строке
double QuotientOfDivision(Encryption &e) {
    double sum = 0;
    for (int i = 0; i < e.size; ++i) {
        sum += e.sourceString[i];
    }
    if (e.size == 0) {
        return 0;
    }
    return sum / e.size;
}
