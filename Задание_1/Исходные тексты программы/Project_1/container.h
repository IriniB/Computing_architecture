#ifndef PROJECT_1_CONTAINER_H
#define PROJECT_1_CONTAINER_H

// container.h - содержит тип данных, представляющий простейший контейнер.

#include <stdio.h>
#include "programming_language.h"

// Простейший контейнер на основе одномерного массива.
struct container {
    enum {max_len = 10000}; // максимальная длина.
    int len; // текущая длина.
    struct programming_language cont[max_len];
};

// Инициализация контейнера.
void Init(struct container *container);

// Очистка контейнера от элементов (освобождение памяти).
void Clear(struct container *container);

// Ввод содержимого контейнера из указанного потока.
void InCont(struct container *container, FILE *input_file);

// Случайная генерация данных в контейнере.
void InRndCont(struct container *container, int size);

// Вывод содержимого контейнера в указанный поток.
void OutCont(struct container *container, FILE *output_file);

// Сортировка контейнера методом пузырька по убывания.
void BubbleSort(struct container *container);

#endif //PROJECT_1_CONTAINER_H