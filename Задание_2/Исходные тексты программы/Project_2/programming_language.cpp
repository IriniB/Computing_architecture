//
// Created by irini on 13.10.2021.
//

#include "programming_language.h"
#include "random.h"
#include "functional.h"
#include "object_oriented.h"
#include "procedural.h"

Language* Language::StaticIn(std::ifstream &input_file, int key) {
    Language* language = nullptr;
    switch(key) {
        case 1:
            language = new Functional;
            break;
        case 2:
            language = new ObjectOriented;
            break;
        case 3:
            language = new Procedural;
            break;
    }
    language->In(input_file);
    return language;
}

Language* Language::StaticInRnd() {
    Language* language = nullptr;
    Random random;
    int key = random.RandomNumber(1, 3);
    switch(key) {
        case 1:
            language = new Functional;
            break;
        case 2:
            language = new ObjectOriented;
            break;
        case 3:
            language = new Procedural;
            break;
    }
    language->InRnd();
    return language;
}
