//
// Created by irini on 13.10.2021.
//

#include "procedural.h"

void Procedural::In(std::ifstream &input_file) {
    input_file >> name >> creation_year >> popularity >> has_abstract_data_types;
}

void Procedural::InRnd() {
    Random random;
    name = random.RandomString();
    creation_year = random.RandomNumber(1900, 2020);
    popularity =  rand() * 1.0 / (RAND_MAX);
    has_abstract_data_types = random.RandomNumber(0, 1);
}

void Procedural::Out(std::ofstream &output_file) {
    output_file << "procedural\t" << name << " " << creation_year << " " <<
                popularity << " " << has_abstract_data_types << "\n";
}

float Procedural::Quotient() {
    return (float)creation_year / name.length();
}
