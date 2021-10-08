#include "CyclicShiftEncryption.h"

//------------------------------------------------------------------------------
// Ввод параметров прямоугольника из файла
void In(CyclicShiftEncryption &c,char sourceString[256], std::ifstream &ifst) {
    ifst >> c.shift;
    for (int i = 0; i < 256; ++i) {
        c.encryptedString[i] = sourceString[i] + c.shift;
    }
}

// Случайный ввод параметров прямоугольника
void InRnd(CyclicShiftEncryption &c) {
    //r.x = Random();
    //r.y = Random();
}

//------------------------------------------------------------------------------
// Вывод параметров прямоугольника в форматируемый поток
void Out(CyclicShiftEncryption &c, std::ofstream &ofst) {
    /**
    ofst << "It is Rectangle: x = " << r.x << ", y = " << r.y
         << ". EncryptString = " << Perimeter(r) << "\n";
         */
}

//------------------------------------------------------------------------------
// Вычисление периметра прямоугольника
double EncryptString(char sourceString[256]) {
    return 0;
}
