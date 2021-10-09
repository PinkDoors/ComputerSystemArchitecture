//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

#include "container.h"

void errMessage1() {
    std::cout << "incorrect command line!\n"
                 "  Waited:\n"
                 "     command -f infile outfile01 outfile02\n"
                 "  Or:\n"
                 "     command -n number outfile01 outfile02\n";
}

void errMessage2() {
    std::cout << "incorrect qualifier value!\n"
                 "  Waited:\n"
                 "     command -f infile outfile01 outfile02\n"
                 "  Or:\n"
                 "     command -n number outfile01 outfile02\n";
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        errMessage1();
        return 1;
    }

    std::cout << "Start of the program" << std::endl;
    container c;
    Init(c);

    // ВВод содержимого из потока (файл).
    if (!strcmp(argv[1], "-f")) {
        std::ifstream ifst(argv[2]);
        In(c, ifst);
    }
        // Ввод случайных элементов.
    else if (!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            std::cout << "incorrect numer of figures = "
                      << size
                      << ". Set 0 < number <= 10000\n";
            return 3;
        }
        // Заполнение контейнера генератором случайных чисел
        InRnd(c, size);
    } else {
        errMessage2();
        return 2;
    }
    // Вывод содержимого контейнера в файл.
    std::ofstream ofst1(argv[3]);
    ofst1 << "Filled container:\n";
    Out(c, ofst1);
    std::cout << "The container is saved to a file " << "\"" << argv[3] << "\"\n";

    // Вывод отсортированного содержимого контейнера в файл.
    HeapSort(c);
    std::ofstream ofst2(argv[4]);
    ofst2 << "Sorted container:\n";
    Out(c, ofst2);
    std::cout << "The sorted container is saved to a file " << "\"" << argv[4] << "\"\n";

    Clear(c);
    std::cout << "The program ended successfully" << std::endl;
    std::cout << "Time: " << clock() / 1000.0 << std::endl;
    return 0;
}
