#ifndef PROJECT_1_PROGRAMMING_LANGUAGE_H
#define PROJECT_1_PROGRAMMING_LANGUAGE_H

#include "procedural.h"
#include "object_oriented.h"
#include "functional.h"

enum key {PROCEDURAL, OBJECT_ORIENTED, FUNCTIONAL};

struct programming_language {
    enum key key;
    union { // используем простейшую реализацию
        struct procedural proc;
        struct object_oriented obj;
        struct functional func;
    };
};

// Случайный генерация данных обобщенного языка программирования.
bool InRndLang(struct programming_language *language);

// Вывод данных обобщенного языка программирования в файл.
void OutLang(struct programming_language *language, FILE *output_file);

// Вычисление частного от деления года создания на количество символов в названии языка программирования.
float QuotientLang(struct programming_language *language);

#endif //PROJECT_1_PROGRAMMING_LANGUAGE_H