#include "NumbersEncryption.h"


void Init(NumbersEncryption &n) {
    for (int i = 0; i < 10; ++i) {
        n.symbols[0] = std::pair<char, int>(i + 48, 0);
    }
    for (int i = 17; i < 43; ++i) {
        n.symbols[0] = std::pair<char, int>(i + 48, 0);
    }
    for (int i = 49; i < 75; ++i) {
        n.symbols[0] = std::pair<char, int>(i + 48, 0);
    }
}

//------------------------------------------------------------------------------
// Ввод параметров прямоугольника из файла
void In(NumbersEncryption &n, char sourceString[256], std::ifstream &ifst) {
    int numberOfSymbols;
    char newSymbols[62];
    ifst.getline(newSymbols, 62);
    for (int i = 0; i < 62; ++i) {
        n.symbols[i] = std::pair<char, int>(n.symbols[i].first, newSymbols[i]);
    }
    for (int i = 0; i < 62; ++i) {
        for (int j = 0; j < 256; ++j) {
            if (sourceString[j] == n.symbols->first)
            {
                n.encryptedString[j] = n.symbols->second;
            }
        }
    }
}

// Случайный ввод параметров прямоугольника
void InRnd(NumbersEncryption &n) {
    //r.x = Random();
    //r.y = Random();
}

//------------------------------------------------------------------------------
// Вывод параметров прямоугольника в форматируемый поток
void Out(NumbersEncryption &n, std::ofstream &ofst) {
    //ofst << "It is Rectangle: x = " << r.x << ", y = " << r.y
    //    << ". EncryptString = " << Perimeter(r) << "\n";
}

//------------------------------------------------------------------------------
// Вычисление периметра прямоугольника
double EncryptString(NumbersEncryption &n) {
    return 0;
}
