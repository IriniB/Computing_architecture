#ifndef PROJECT_2_OBJECT_ORIENTED_H
#define PROJECT_2_OBJECT_ORIENTED_H

#include <string>
#include "programming_language.h"
#include "random.h"

enum Inheritance {SINGLE, PLURAL, INTERFACE};

class ObjectOriented: public Language {
private:
    std::string name;
    int creation_year;
    float popularity;
    enum Inheritance inheritance;
public:
    virtual ~ObjectOriented(){}
    // Ввод параметров объектно-ориентированного языка программирования из файла.
    virtual void In(std::ifstream &input_file);

    // Случайная генерация параметров объектно-ориентированного языка программирования.
    virtual void InRnd();

    // Вывод параметров объектно-ориентированного языка программирования в файл.
    virtual void Out(std::ofstream &output_file);

    // Вычисление частного от деления года создания на количество символов в названии.
    virtual float Quotient();

    enum Inheritance GetInherByInt(int type);
};

#endif //PROJECT_2_OBJECT_ORIENTED_H
