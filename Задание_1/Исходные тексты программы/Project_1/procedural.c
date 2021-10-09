#include <stdlib.h>
#include "procedural.h"
#include "programming_language.h"
#include "random.h"

// Ввод данных процедурного языка программирования из файла.
void InProc(struct procedural *p,  FILE *input_file) {
    char name [220];
    int year = 0;
    float popularity = 0;
    int abstract = 0;
    fscanf(input_file, "%s %i %f %i", name, &year, &popularity, &abstract);
    memcpy(p->name, name, 20);
    p->creation_year = year;
    p->popularity = popularity;
    p->has_abstract_data_types = abstract;
}

// Случайная генерация данных процедурного языка программирования.
void InRndProc(struct procedural *p){
    RandomString(p->name);
    p->creation_year = RandomNumber(1900, 2020);
    p->popularity = rand() * 1.0 / (RAND_MAX);
    p->has_abstract_data_types = RandomNumber(0, 1);
}

// Вывод данных процедурного языка программирования в файл.
void OutProc(struct procedural *p, FILE *output_file) {
    fprintf(output_file, "%s %s %i %f %i \n", "procedural\t", p->name, p->creation_year,
    p->popularity, p->has_abstract_data_types);
}

// Вычисление частного от деления года создания на количество символов в названии.
float QuotientProc(struct procedural *p) {
    float result = (float)p->creation_year / sizeof(p->name);
    return result;
}