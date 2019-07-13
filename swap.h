#include <iostream>

void swap(int* const a, int* const b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print(const int* const list, int len) {
    for (int i = 0; i < len; ++i)
        std::cout << list[i] << " ";
    std::cout << std::endl;
}
