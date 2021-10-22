#include <fstream>
#include <cstdlib> // для функций rand() и srand()
#include <cstring>
#include "container.h"

void ErrMessage() {
    printf( "incorrect command line!\n"
            "  Waited:\n"
            "     command file InputFile.txt OutputContainerFile.txt\n"
            "   or   command rand OutputContainerFile.txt array_sise\n");
}


int main(int argc, char* argv[]) {
    if (argc != 4) {
        ErrMessage();
        return 0;
    }

    bool random = false;
    if (!strcmp(argv[1], "rand")) {
        random = true;
    }

    printf("Start\n");
    Container* container = new Container(10000);
    srand(static_cast<unsigned int>(time(0)));

    std::string output_file_name;
    if (!random) {
        std::ifstream input_file(argv[2]);
        container->In(input_file);
        output_file_name = argv[3];
    } else {
        int size = atoi(argv[3]);
        if(size > 10000 || size < 0) {
            printf("Not appropriate size of container\n");
            return 0;
        }
        container->InRnd(size);
        output_file_name = argv[2];
    }
    std::ofstream output_file(output_file_name);
    container->Out(output_file);

    container->BubbleSort();

    output_file << "\n\n\n--------------------------After sorting--------------------------\n";
    container->Out(output_file);

    printf("The process is completed\n");
    return 0;
}
