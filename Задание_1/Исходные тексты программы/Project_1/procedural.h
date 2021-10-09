#ifndef PROJECT_1_PROCEDURAL_H
#define PROJECT_1_PROCEDURAL_H

#include <stdbool.h>
#include <stdio.h>

struct procedural {
    char name[20];
    int creation_year;
    float popularity;
    bool has_abstract_data_types;
};

// Ввод данных процедурного языка программирования из файла.
void InProc(struct procedural *p, FILE *input_file);

// Случайная генерация данных процедурного языка программирования.
void InRndProc(struct procedural *p);

// Вывод данных процедурного языка программирования в файл.
void OutProc(struct procedural *p, FILE *output_file);

// Вычисление частного от деления года создания на количество символов в названии.
float QuotientProc(struct procedural *p);

#endif //PROJECT_1_PROCEDURAL_H