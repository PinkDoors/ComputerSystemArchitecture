//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include <iostream>
#include "container.h"

// Инициализация контейнера
void Init(container &c) {
    c.len = 0;
}

// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c) {
    for (int i = 0; i < c.len; i++) {
        delete c.cont[i];
    }
    c.len = 0;
}

// Ввод содержимого контейнера из указанного потока
void In(container &c, std::ifstream &ifst) {
    int numberOfElements;
    ifst >> numberOfElements;
    if (numberOfElements > 10000 || numberOfElements < 0) {
        std::cout << "Incorrect number of strings" << "\n";
        return;
    }
    for (int i = 0; i < numberOfElements; ++i) {
        if ((c.cont[c.len] = In(ifst)) != 0) {
            c.len++;
        }
    }
}

// Случайный ввод содержимого контейнера
void InRnd(container &c, int size) {
    for (int i = 0; i < size; ++i) {
        if ((c.cont[c.len] = InRnd()) != 0) {
            c.len++;
        }
    }
}

// Вывод содержимого контейнера в указанный поток
void Out(container &c, std::ofstream &ofst) {
    ofst << "Container contains " << c.len << " elements." << "\n";
    for (int i = 0; i < c.len; i++) {
        ofst << "----------------------------------------------------" << "\n";
        ofst << i << ": ";
        Out(*(c.cont[i]), ofst);
    }
}

// Рекурсивная функция для сортировки контейнера
void Heapify(Encryption *arr[10000], int n, int i) {
    // Инициализируем наименьший элемент как корень.
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && QuotientOfDivision(*arr[left]) < QuotientOfDivision(*arr[smallest]))
        smallest = left;
    if (right < n && QuotientOfDivision(*arr[right]) < QuotientOfDivision(*arr[smallest]))
        smallest = right;

    // Если самый маленький элемент не является корнем, то меняем местами.
    if (smallest != i) {
        std::swap(arr[i], arr[smallest]);
        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        Heapify(arr, n, smallest);
    }
}

// Сортировка элементов в контейнере по убыванию через "дерево"
void HeapSort(container &c) {
    // Построение кучи (перегруппируем массив)
    for (int i = c.len / 2 - 1; i >= 0; i--)
        Heapify(c.cont, c.len, i);
    // Один за другим извлекаем элементы из кучи.
    for (int j = c.len - 1; j >= 0; j--) {
        // Перемещаем текущий корень в конец.
        std::swap(c.cont[0], c.cont[j]);
        // вызываем процедуру Heapify на уменьшенной куче.
        Heapify(c.cont, j, 0);
    }
}


