#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "container.h"

void ErrMessage() {
    printf( "incorrect command line!\n"
            "  Waited:\n"
            "     command file InputFile.txt OutputContainerFile.txt\n"
            "   or   command rand OutputContainerFile.txt array_sise\n");
}

//------------------------------------------------------------------------------
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
    struct container container;
    Init(&container);

    srand(time(NULL));

    FILE *output_file;
    if (!random) {
        FILE *input_file = fopen(argv[2], "r");
        InCont(&container, input_file);
        fclose(input_file);
        output_file = fopen(argv[3], "w");
    } else {
        int size = atoi(argv[3]);
        if(size > 10000) {
            printf("Too big array size\n");
            return 0;
        }
        InRndCont(&container, size);
        output_file = fopen(argv[2], "w");
    }

    OutCont(&container, output_file);

    BubbleSort(&container);

    fprintf(output_file, "\n\n\n %s", "--------------------------After sorting--------------------------\n");
    OutCont(&container, output_file);

    fclose(output_file);

    Clear(&container);
    printf("The process is completed\n");
    return 0;
}