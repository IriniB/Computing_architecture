#include "container.h"
#include "functional.h"

// Инициализация контейнера.
void Init(struct container *container) {
    container->len = 0;
}

// Очистка контейнера от элементов (освобождение памяти).
void Clear(struct container *container) {
    container->len = 0;
}

// Ввод содержимого контейнера из указанного потока.
void InCont(struct container *container, FILE *input_file) {
    int key = 0;
    while(fscanf(input_file, "%i", &key) != EOF) {
        struct programming_language language;
        if(key == 1) {
            language.key = FUNCTIONAL;
            InFunc(&language.func, input_file);
        }
        else if (key == 2) {
            language.key = OBJECT_ORIENTED;
            InObj(&language.obj, input_file);
        }
        else {
            language.key = PROCEDURAL;
            InProc(&language.proc, input_file);
        }
        container->cont[container->len] = language;
        ++container->len;
        if(container->len == 10000) {
            printf("Загружены не все данные.");
            return;
        }
    }
}
// Случайная генерация данных в контейнере.
void InRndCont(struct container *container, int size) {
    while(container->len < size) {
        if(InRndLang(&container->cont[container->len])) {
            container->len++;
        }
    }
}

// Вывод содержимого контейнера в указанный поток.
void OutCont(struct container *container, FILE *output_file) {
    fprintf(output_file, "%s %i %s \n", "Container contains ", container->len, " elements.");
    for (int i = 0; i < container->len; i++) {
        fprintf(output_file, "%i %s", i, ": ");
        OutLang(&(container->cont[i]), output_file);
    }
}

// Сортировка контейнера методом пузырька по убыванию.
void BubbleSort(struct container *container) {
    for (int i = 0; i < container->len - 1; i++) {
        for (int j = 0; j < container->len - i - 1; j++) {
            if (QuotientLang(&container->cont[j + 1]) > QuotientLang(&container->cont[j])) {
                struct programming_language temp;
                temp = container->cont[j];
                container->cont[j] = container->cont[j + 1];
                container->cont[j + 1] = temp;
            }
        }
    }
}