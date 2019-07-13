#include "swap.h"

#include <iostream>

void bubble(int* const list, int len) {
    for (int i = 0; i <= len - 1; ++i) {
        for (int j = len - 1; j > i; --j) {
            if (list[j] < list[j - 1]) {
                swap(&list[j], &list[j - 1]);
            }
        }
    }
}

int main(int argc, char** argv) {
    int array[10] = {1, 23, 22, 5, 278, 45, 109, 45, 543, 443};
    print(array, 10);
    bubble(array, 10);
    print(array, 10);
    return 0;
}
