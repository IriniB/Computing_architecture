#include <stdlib.h>
#include "object_oriented.h"
#include "programming_language.h"
#include "random.h"

enum Inheritance GetInherByInt(int type){
    switch (type) {
        case 0:
            return SINGLE;
        case 1:
            return PLURAL;
        case 2:
            return INTERFACE;
    }
}

// Ввод параметров объектно-ориентированного языка программирования из файла.
void InObj(struct object_oriented *o,  FILE *input_file) {
    char name [20];
    int year = 0;
    float popularity = 0;
    int type = 0;
    fscanf(input_file, "%s %i %f %i", name, &year, &popularity, &type);
    memcpy(o->name, name, 20);
    o->creation_year = year;
    o->popularity = popularity;
    o->inheritance = GetInherByInt(type);
}
// Случайная генерация параметров объектно-ориентированного языка программирования.
void InRndObj(struct object_oriented *o){
    RandomString(o->name);
    o->creation_year = RandomNumber(1900, 2020);
    o->popularity = rand() * 1.0 / (RAND_MAX);
    int type = RandomNumber(0, 2);
    o->inheritance = GetInherByInt(type);
}

// Вывод параметров объектно-ориентированного языка программирования в файл.
void OutObj(struct object_oriented *o, FILE *output_file) {
    char type[9];
    switch (o->inheritance) {
        case 0:
            memcpy(type, "SINGLE", 6);
            break;
        case 1:
            memcpy(type, "PLURAL", 6);
            break;
        case 2:
            memcpy(type, "INTERFACE", 9);
            break;
    }
    fprintf(output_file, "%s %s %i %f %s \n", "object_oriented\t", o->name, o->creation_year,
    o->popularity, type);
}

// Вычисление частного от деления года создания на количество символов в названии.
float QuotientObj(struct object_oriented *o) {
    float result = (float)o->creation_year / sizeof(o->name);
    return result;
}