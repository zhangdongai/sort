#include "swap.h"

#include <iostream>

#define left_child(i) (2 * (i) + 1)

void percdown(int* const list, int i, int len) {
    int child = left_child(i);
    int tmp = list[i];
    for (; left_child(i) < len; i = child) {
        child = left_child(i);
        if (child != len - 1 && list[child + 1] > list[child])
            ++child;
        if (tmp < list[child])
            list[i] = list[child];
        else
            break;
    }
    list[i] = tmp;
}

void heapsort(int* const list, int len) {
    for (int i = len / 2; i >= 0; --i)
        percdown(list, i, len);
    for (int i = len - 1; i > 0; --i) {
        swap(&list[0], &list[i]);
        percdown(list, 0, i);
    }
}

int main(int argc, char** argv) {
    int array[10] = {11, 23, 22, 55, 2738, 45, 109, 45, 543, 443};
    print(array, 10);
    heapsort(array, 10);
    print(array, 10);
    return 0;
}
