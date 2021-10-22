#ifndef PROJECT_2_PROCEDURAL_H
#define PROJECT_2_PROCEDURAL_H

#include <string>
#include "programming_language.h"
#include "random.h"

class Procedural: public Language {
private:
    std::string name;
    int creation_year;
    float popularity;
    bool has_abstract_data_types;
public:
    virtual ~Procedural() {}
    // Ввод данных процедурного языка программирования из файла.
    virtual void In(std::ifstream &input_file);

    // Случайная генерация данных процедурного языка программирования.
    virtual void InRnd();

    // Вывод данных процедурного языка программирования в файл.
    virtual void Out(std::ofstream &output_file);

    // Вычисление частного от деления года создания на количество символов в названии.
    virtual float Quotient();
};
#endif //PROJECT_2_PROCEDURAL_H
