#include "container.h"

Container::Container(int length): len{0}, size{length} {
    cont = new Language*[length];
}

Container::~Container() {
    Clear();
    delete[] cont;
}

void Container::Clear() {
    for(int i = 0; i < len; i++) {
        delete cont[i];
    }
    len = 0;
}

void Container::In(std::ifstream &input_file) {
    int key;
    while(input_file >> key) {
        cont[len] = Language::StaticIn(input_file, key);
        if(cont[len] != nullptr) {
            len++;
        }
    }
}

void Container::InRnd(int s) {
    if(s > size) {
        s = size;
    }
    while(len < s) {
        if((cont[len] = Language::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}

void Container::Out(std::ofstream &output_file) {
    output_file << "Container contains " << len << " elements.\n";
    for (int i = 0; i < len; i++) {
        output_file << i << ": ";
        cont[i]->Out(output_file);
    }
}

void Container::BubbleSort() {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (cont[j + 1]->Quotient() > cont[j]->Quotient()) {
                Language* temp = nullptr;
                temp = cont[j];
                cont[j] = cont[j + 1];
                cont[j + 1] = temp;
            }
        }
    }
}
