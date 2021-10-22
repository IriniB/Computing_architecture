#ifndef PROJECT_2_CONTAINER_H
#define PROJECT_2_CONTAINER_H

#include "programming_language.h"

// Простейший контейнер на основе одномерного массива.
class Container {
private:
    int len; // текущая длина.
    Language** cont;
    int size;
    void Clear();

public:
    explicit Container(int length);
    ~Container();

    // Ввод содержимого контейнера из указанного потока.
    void In(std::ifstream &input_file);

    // Случайная генерация данных в контейнере.
    void InRnd(int s);

    // Вывод содержимого контейнера в указанный поток.
    void Out(std::ofstream &output_file);

    // Сортировка контейнера методом пузырька по убывания.
    void BubbleSort();
};
#endif //PROJECT_2_CONTAINER_H
