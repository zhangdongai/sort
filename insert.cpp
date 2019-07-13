#include "swap.h"

#include <iostream>

void insert(int* const list, int len) {
    for (int i = 1; i <= len - 1; ++i) {
        int tmp = list[i];
        int j = i;
        for (; j > 0 && list[j - 1] > tmp; --j) {
            list[j] = list[j - 1];
        }
        list[j] = tmp;
    }
}

int main(int argc, char** argv) {
    int array[10] = {1, 23, 22, 5, 278, 45, 109, 45, 543, 443};
    print(array, 10);
    insert(array, 10);
    print(array, 10);
    return 0;
}
