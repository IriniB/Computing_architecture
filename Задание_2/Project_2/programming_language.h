#ifndef PROJECT_2_PROGRAMMING_LANGUAGE_H
#define PROJECT_2_PROGRAMMING_LANGUAGE_H

#include <fstream>
#include "random.h"

class Language {
public:
    virtual ~Language(){};

    // Ввод параметров языка програмирования.
    static Language *StaticIn(std::ifstream &input_file, int key);

    virtual void In(std::ifstream &input_file) = 0;

    static Language *StaticInRnd();
    // Случайный генерация данных обобщенного языка программирования.
    virtual void InRnd() = 0;

    // Вывод данных обобщенного языка программирования в файл.
    virtual void Out(std::ofstream &output_file) = 0;

    // Вычисление частного от деления года создания на количество символов в названии языка программирования.
    virtual float Quotient() = 0;

};

#endif //PROJECT_2_PROGRAMMING_LANGUAGE_H
