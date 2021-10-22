#include "functional.h"

void Functional::In(std::ifstream &input_file) {
    int type;
    input_file >> name >> creation_year >> popularity >>
    lazy_evaluation_support >> type;
    typing = GetTypeByInt(type);
}

void Functional::InRnd() {
    Random random;
    name = random.RandomString();
    creation_year = random.RandomNumber(1900, 2020);
    popularity =  rand() * 1.0 / (RAND_MAX);
    lazy_evaluation_support = random.RandomNumber(0, 1);
    int type = random.RandomNumber(0, 1);
    typing = GetTypeByInt(type);
}

void Functional::Out(std::ofstream &output_file) {
    std::string type;
    switch (typing) {
        case 0:
            type = "STRICT";
            break;
        case 1:
            type = "DYNAMIC";
            break;
    }
    output_file << "functional\t" << name << " " << creation_year << " " <<
    popularity << " " << lazy_evaluation_support << " " << type << "\n";
}

float Functional::Quotient() {
    return (float)creation_year / name.length();
}

enum Typing Functional::GetTypeByInt(int type) {
    switch (type) {
        case 0:
            return STRICT;
        case 1:
            return DYNAMIC;
    }
}
