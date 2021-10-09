#ifndef PROJECT_1_OBJECT_ORIENTED_H
#define PROJECT_1_OBJECT_ORIENTED_H
#include <stdio.h>

enum Inheritance {SINGLE, PLURAL, INTERFACE};

struct object_oriented {
    char name[20];
    int creation_year;
    float popularity;
    enum Inheritance inheritance;
};

enum Inheritance GetInherByInt(int type);

// Ввод параметров объектно-ориентированного языка программирования из файла.
void InObj(struct object_oriented *o,  FILE *input_file);

// Случайная генерация параметров объектно-ориентированного языка программирования.
void InRndObj(struct object_oriented *o);

// Вывод параметров объектно-ориентированного языка программирования в файл.
void OutObj(struct object_oriented *o, FILE *output_file);

// Вычисление частного от деления года создания на количество символов в названии.
float QuotientObj(struct object_oriented *o);

#endif //PROJECT_1_OBJECT_ORIENTED_H