#include <stdlib.h>
#include "functional.h"
#include "string.h"
#include "random.h"

enum Typing GetTypeByInt(int type){
    switch (type) {
        case 0:
            return STRICT;
        case 1:
            return DYNAMIC;
    }
}

// Ввод параметров функционалго языка программирования из файла.
void InFunc(struct functional *f,  FILE *input_file) {
    char name [20];
    int year = 0;
    float popularity = 0;
    int type = 0;
    int support = 0;
    fscanf(input_file, "%s %i %f %i %i", name, &year, &popularity, &support, &type);
    memcpy(f->name, name, 20);
    f->creation_year = year;
    f->popularity = popularity;
    f->lazy_evaluation_support = support;
    f->typing = GetTypeByInt(type);
}

// Слуяайная генерация параметров функционалго языка программирования.
void InRndFunc(struct functional *f){
    RandomString(f->name);
    f->creation_year = RandomNumber(1900, 2020);
    f->popularity =  rand() * 1.0 / (RAND_MAX);
    f->lazy_evaluation_support = RandomNumber(0, 1);
    int type = RandomNumber(0, 1);
    f->typing = GetTypeByInt(type);
}

// Вывод параметров функционалго языка программирования в файл.
void OutFunc(struct functional *f, FILE *output_file) {
    char type[7];
    switch (f->typing) {
        case 0:
            memcpy(type, "STRICT", 6);
            break;
        case 1:
            memcpy(type, "DYNAMIC", 7);
            break;
    }
    fprintf(output_file, "%s %s %i %f %i %s \n", "functional\t", f->name, f->creation_year, f->popularity,
    f->lazy_evaluation_support, type);
}

// Вычисление частного от деления года создания на количество символов в названии.
float QuotientFunc(struct functional *f) {
    float result = (float)f->creation_year / sizeof(f->name);
    return result;
}