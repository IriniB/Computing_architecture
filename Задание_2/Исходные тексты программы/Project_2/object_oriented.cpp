//
// Created by irini on 13.10.2021.
//

#include "object_oriented.h"

void ObjectOriented::In(std::ifstream &input_file) {
    int inher;
    input_file >> name >> creation_year >> popularity >> inher;
    inheritance = GetInherByInt(inher);
}

void ObjectOriented::InRnd() {
    Random random;
    name = random.RandomString();
    creation_year = random.RandomNumber(1900, 2020);
    popularity =  rand() * 1.0 / (RAND_MAX);
    int inher = random.RandomNumber(0, 2);
    inheritance = GetInherByInt(inher);
}

void ObjectOriented::Out(std::ofstream &output_file) {
    std::string inher;
    switch (inheritance) {
        case 0:
            inher = "SINGLE";
            break;
        case 1:
            inher = "PLURAL";
            break;
        case 2:
            inher = "INTERFACE";
            break;
    }
    output_file << "object_oriented\t" << name << " " << creation_year << " " <<
                popularity << " " << inher << "\n";
}

float ObjectOriented::Quotient() {
    return (float)creation_year / name.length();
}

enum Inheritance ObjectOriented::GetInherByInt(int type) {
    switch (type) {
        case 0:
            return SINGLE;
        case 1:
            return PLURAL;
        case 2:
            return INTERFACE;
    }
}
