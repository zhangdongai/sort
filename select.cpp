#include "swap.h"

#include <iostream>

void select(int* const list, int len) {
    for (int i = 0; i <= len - 1; ++i) {
        int min_i = i;
        for (int j = i + 1; j <= len - 1; ++j) {
            if (list[j] < list[min_i]) {
                min_i = j;
            }
        }
        if (i != min_i)
            swap(&list[i], &list[min_i]);
    }
}

int main(int argc, char** argv) {
    int array[10] = {1, 23, 22, 5, 278, 45, 109, 45, 543, 443};
    print(array, 10);
    select(array, 10);
    print(array, 10);
    return 0;
}
