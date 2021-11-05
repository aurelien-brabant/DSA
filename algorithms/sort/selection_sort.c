#include <stdio.h>

void selection_sort(int* arr, size_t n) {
    int min, tmp;

    for (size_t i = 0; i != n; ++i) {
        min = i;
        for (size_t j = i + 1; j != n; ++j) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
    }
}

int main(void) {
    int t[] = {-4, 8, -7, 2, 12, 4, 22, 3};

    selection_sort(t, sizeof(t) / sizeof(*t));

    for (int i = 0; i != sizeof(t) / sizeof(*t); ++i) {
        printf("%d ", t[i]);
    }

    return 0;
}
