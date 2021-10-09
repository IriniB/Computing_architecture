#include "programming_language.h"
#include "random.h"

// Случайный генерация данных обобщенного языка программирования.
bool InRndLang(struct programming_language *language){
    int key = RandomNumber(1, 3);
    switch(key) {
        case 1:
            language->key = FUNCTIONAL;
            InRndFunc(&language->func);
            return true;
        case 2:
            language->key = OBJECT_ORIENTED;
            InRndObj(&language->obj);
            return true;
        case 3:
            language->key = PROCEDURAL;
            InRndProc(&language->proc);
            return true;
        default:
            return false;
    }
}

// Вывод данных обобщенного языка программирования в файл.
void OutLang(struct programming_language *language, FILE *output_file) {
    switch(language->key) {
        case FUNCTIONAL:
            return OutFunc(&language->func, output_file);
        case OBJECT_ORIENTED:
            return OutObj(&language->obj, output_file);
        case PROCEDURAL:
            return OutProc(&language->proc, output_file);
        default:
            fprintf(output_file, "%s", "Incorrect language!");
    }
}

// Вычисление частного от деления года создания на количество символов в названии языка программирования.
float QuotientLang(struct programming_language *language) {
    switch(language->key) {
        case FUNCTIONAL:
            return QuotientFunc(&language->func);
        case OBJECT_ORIENTED:
            return QuotientObj(&language->obj);
        case PROCEDURAL:
            return QuotientProc(&language->proc);
        default:
            return 0.0;
    }
}