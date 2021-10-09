#include "random.h"

// Получение случайного числа.
int RandomNumber(int from, int to) {
    int r = rand() % (to - from + 1) + from;
    return r;
}

// Получение случайной строки.
void RandomString(char *new_string) {
    char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                        'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                        'u', 'v', 'w', 'x', 'y', 'z'};

    int length = RandomNumber(1, 10);
    for (int i = 0; i < length; i++) {
        new_string[i] = letters[RandomNumber(0, 25)];
    }
}