#ifndef PROJECT_2_RANDOM_H
#define PROJECT_2_RANDOM_H


#include <string>
#include <cstdlib>
#include <ctime>

class Random {
private:
    char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                        'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                        'u', 'v', 'w', 'x', 'y', 'z'};
public:
    int RandomNumber(int from, int to) {
        return rand() % (to - from + 1) + from;
    }

    std::string RandomString() {
        std::string new_string = "";
        int length = RandomNumber(1, 10);
        for (int i = 0; i < length; i++) {
            new_string += letters[RandomNumber(1, 25)];
        }
        return new_string;
    }
};

#endif //PROJECT_2_RANDOM_H
