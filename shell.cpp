#include "swap.h"

#include <iostream>

void shell(int* const list, int len) {
    for (int incre = len / 2; incre > 0; incre /= 2) {
        for (int i = incre; i < len; ++i) {
            int tmp = list[i];
            int j = i;
            for (; j >= incre && tmp < list[j - incre]; j -= incre) {
                list[j] = list[j - incre];
            }
            list[j] = tmp;
        }
    }
}

int main(int argc, char** argv) {
    int array[10] = {111, 23, 22, 55, 2738, 45, 109, 45, 543, 443};
    print(array, 10);
    shell(array, 10);
    print(array, 10);
    return 0;
}
