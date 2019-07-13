#include "swap.h"
#include <string.h>
#include <malloc.h>

void merge(int* const list, int* const tmp_list, int left, int center, int right) {
    int left_end = center - 1;
    int tmp_i = left;
    int elem_num = right - left + 1;
    while (left <= left_end && center <= right)
        if (list[left] <= list[center])
            tmp_list[tmp_i++] = list[left++];
        else
            tmp_list[tmp_i++] = list[center++];

    // copy the rest of left half
    while (left <= left_end)
        tmp_list[tmp_i++] = list[left++];

    // copy the rest of right half
    while (center <= right)
        tmp_list[tmp_i++] = list[center++];

    // copy back
    for (int i = 0; i < elem_num && right >= 0; ++i, --right)
        list[right] = tmp_list[right];
}

void msort(int* const list, int* const tmp_list, int left, int right) {
    if (left < right) {
        int center = (left + right) / 2;
        msort(list, tmp_list, left, center);
        msort(list, tmp_list, center + 1, right);
        merge(list, tmp_list, left, center + 1, right);
    }
}

void mergesort(int* const list, int len) {
    int* tmp_list = (int*)malloc(len * sizeof(int));
    if (tmp_list)
        msort(list, tmp_list, 0, len - 1);
    free(tmp_list);
}

int main(int argc, char** argv) {
    int array[10] = {11, 23, 22, 55, 2738, 45, 109, 45, 543, 443};
    print(array, 10);
    mergesort(array, 10);
    print(array, 10);
    return 0;
}
