//------------------------------------------------------------------------------
// shape.cpp - содержит процедуры связанные с обработкой обобщенной фигуры
// и создания произвольной фигуры
//------------------------------------------------------------------------------

#include "Encryption.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из файла
Encryption *In(std::ifstream &ifst) {
    Encryption *sp;
    int key;
    ifst >> key;
    ifst.getline(sp->sourceString, 256);
    switch (key) {
        case 1:
            sp = new Encryption();
            sp->k = Encryption::Cyclic;
            In(sp->c, sp->sourceString, ifst);
            return sp;
        case 2:
            sp = new Encryption();
            sp->k = Encryption::Numbers;
            In(sp->n, sp->sourceString, ifst);
            return sp;
        case 3:
            sp = new Encryption();
            sp->k = Encryption::Symbols;
            In(sp->s, sp->sourceString, ifst);
            return sp;
        default:
            return 0;
    }
}

// Случайный ввод обобщенной фигуры
Encryption *InRnd() {
    Encryption *sp;
    auto k = rand() % 2 + 1;
    switch (k) {
        case 1:
            sp = new Encryption();
            sp->k = Encryption::Cyclic;
            InRnd(sp->c);
            return sp;
        case 2:
            sp = new Encryption();
            sp->k = Encryption::Numbers;
            InRnd(sp->n);
            return sp;
        case 3:
            sp = new Encryption();
            sp->k = Encryption::Symbols;
            InRnd(sp->s);
            return sp;
        default:
            return 0;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущей фигуры в поток
void Out(Encryption &e, std::ofstream &ofst) {
    switch (e.k) {
        case Encryption::Cyclic:
            Out(e.c, ofst);
            break;
        case Encryption::Numbers:
            Out(e.n, ofst);
            break;
        case Encryption::Symbols:
            Out(e.s, ofst);
            break;
        default:
            ofst << "Incorrect Encryption!" << std::endl;
    }
}

//------------------------------------------------------------------------------
// Вычисление периметра фигуры
/**
double EncryptString(shape &s) {
    switch (s.k) {
        case shape::RECTANGLE:
            return EncryptString(s.r);
            break;
        case shape::TRIANGLE:
            return EncryptString(s.t);
            break;
        default:
            return 0.0;
    }
}
 */
