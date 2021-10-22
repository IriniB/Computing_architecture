#ifndef PROJECT_2_FUNCTIONAL_H
#define PROJECT_2_FUNCTIONAL_H

#include <string>
#include "programming_language.h"
#include "random.h"

enum Typing {STRICT, DYNAMIC};

class Functional: public Language {
private:
    std::string name;
    int creation_year;
    float popularity;
    enum Typing typing;
    bool lazy_evaluation_support;
public:
    virtual ~Functional(){}

    // Ввод параметров функционального языка програмирования.
    virtual void In(std::ifstream &input_file);

    // Случайная генерация параметров функционального языка програмирования.
    virtual void InRnd();

    virtual void Out(std::ofstream &output_file);
    // Вычисление частного от деления года создания на количество символов в названии.
    virtual float Quotient();

    enum Typing GetTypeByInt(int type);
};

#endif //PROJECT_2_FUNCTIONAL_H
