#ifndef PROJECT_1_FUNCTIONAL_H
#define PROJECT_1_FUNCTIONAL_H

// functional.h - содержит описание параметров функционалго языка программирования и его интерфейса.

#include <string.h>
#include <stdbool.h>
#include <stdio.h>

enum Typing {STRICT, DYNAMIC};

struct functional {
    char name[20];
    int creation_year;
    float popularity;
    enum Typing typing;
    bool lazy_evaluation_support;

};

enum Typing GetTypeByInt(int type);

// Ввод параметров функционалго языка программирования из файла.
void InFunc(struct functional *f,  FILE *input_file);

// Случайная генерация параметров функционалго языка программирования.
void InRndFunc(struct functional *f);

// Вывод параметров функционалго языка программирования в файл.
void OutFunc(struct functional *f, FILE *output_file);

// Вычисление частного от деления года создания на количество символов в названии.
float QuotientFunc(struct functional *f);
#endif //PROJECT_1_FUNCTIONAL_H