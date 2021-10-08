#include "SymbolsEncryption.h"

void Init(SymbolsEncryption &s) {
    for (int i = 0; i < 10; ++i) {
        s.symbols[0] = std::pair<char, char>(i + 48, i + 48);
    }
    for (int i = 17; i < 43; ++i) {
        s.symbols[0] = std::pair<char, char>(i + 48, i + 48);
    }
    for (int i = 49; i < 75; ++i) {
        s.symbols[0] = std::pair<char, char>(i + 48, i + 48);
    }
}

//------------------------------------------------------------------------------
// Ввод параметров прямоугольника из файла
void In(SymbolsEncryption &s, char sourceString[256], std::ifstream &ifst) {
    Init(s);
    char newSymbols[62];
    ifst.getline(newSymbols, 62);
    for (int i = 0; i < 62; ++i) {
        s.symbols[i] = std::pair<char, char>(s.symbols[i].first, newSymbols[i]);
    }
    for (int i = 0; i < 62; ++i) {
        for (int j = 0; j < 256; ++j) {
            if (sourceString[j] == s.symbols->first)
            {
                s.encryptedString[j] = s.symbols->second;
            }
        }
    }
}

// Случайный ввод параметров прямоугольника
void InRnd(SymbolsEncryption &s) {
    //r.x = Random();
    //r.y = Random();
}

//------------------------------------------------------------------------------
// Вывод параметров прямоугольника в форматируемый поток
void Out(SymbolsEncryption &s, std::ofstream &ofst) {
    /**
    ofst << "It is Rectangle: x = " << r.x << ", y = " << r.y
         << ". EncryptString = " << Perimeter(r) << "\n";
         */
}

//------------------------------------------------------------------------------
// Вычисление периметра прямоугольника
double EncryptString(SymbolsEncryption &s) {
    return 0;
}
