#include <iostream>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;
pthread_cond_t condc, condp; // Используется для сигнализации.
int honey_pot = 0; // Буфер, используемый между производителем и потребителем.
int sips_count;

void *bee(void *ptr) {
    int pNum = *((int*)ptr);
    for (int i = 0; i < 10000; ++i) {
        pthread_mutex_lock(&mutex); // Получение исключительного доступа к буферу.
        while (honey_pot >= sips_count) {
            pthread_cond_wait(&condp, &mutex);
        }
        ++honey_pot;
        pthread_cond_signal(&condc); // Аактивизация потребителя.
        pthread_mutex_unlock(&mutex); // Освобождение доступа к буферу.
        std::cout << "Bee " << pNum << " added a sip of honey to the pot" << std::endl;
        sleep(5);
    }
    pthread_exit(nullptr);
}

void *bear(void *ptr) {
    for (int i = 0; i < 10000; ++i) {
        pthread_mutex_lock(&mutex); // Получение исключительного доступа к буферу.
        while (honey_pot != sips_count) {
            pthread_cond_wait(&condc, &mutex);
        }
        honey_pot = 0; // Извлечение записи из буфера.
        pthread_cond_signal(&condp); // Активизация производителя.
        pthread_mutex_unlock(&mutex); // Освобождение доступа к буферу.
        std::cout << "The bear ate all the honey" << std::endl;
        sleep(5);
    }
    pthread_exit(nullptr);
}

void errMessage() {
    printf( "incorrect command line!\n"
            "  Waited:\n"
            "     command bee_count sips_count\n"
            "where numbers are integer and not 0\n");
}

bool argsCheck(char* argv[]) {
    std::string bee_string = argv[1];
    std::string sips_string = argv[2];
    if (bee_string.find_first_not_of("0123456789") != std::string::npos) {
        return false;
    }
    if (sips_string.find_first_not_of("0123456789") != std::string::npos) {
        return false;
    }
    return true;
}
int main(int argc, char* argv[]) {
    // Если ввели не то количество аргкментов.
    if (argc != 3) {
        errMessage();
        return 1;
    }
    // Проверка, являются ли аргументы целыми числами.
    if (!argsCheck(argv)) {
        errMessage();
        return 2;
    }

    int bee_count;
    bee_count = atoi(argv[1]);
    sips_count = atoi(argv[2]);

    if (bee_count == 0 || sips_count == 0) {
        errMessage();
        return 3;
    }

    pthread_mutex_init(&mutex, nullptr);
    pthread_cond_init(&condc, nullptr);
    pthread_cond_init(&condp, nullptr);

    // Запуск производителей.
    pthread_t correct_bees[bee_count];
    int producers[bee_count];
    for (int i = 0; i < bee_count; i++) {
        producers[i] = i + 1;
        pthread_create(&correct_bees[i], nullptr, bee, (void*)(producers + i));
    }
    // Запуск потребителя.
    pthread_t winnie_pooh;
    pthread_create(&winnie_pooh, nullptr, bear, nullptr);


    for (int i = 0; i < bee_count; i++) {
       pthread_join(correct_bees[i], nullptr);
    }
    pthread_join(winnie_pooh, nullptr);
    pthread_cond_destroy(&condc);
    pthread_cond_destroy(&condp);
    pthread_mutex_destroy(&mutex);
    return 0;
}
