#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define K 5000

int l[K];

void generateList() {
    for (int n = 1; n <= K; n++) {
        l[n-1] = n * (3 * n - 1) / 2;
    }
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

bool include(int *arr_start, int *end, int el) {
    int *ptr = arr_start;
    while (ptr != end) {
        if (*ptr == el) {
            return true;
        }
        ptr++;
    }
    return false;
}

int main() {
    generateList();
    int answer = INT_MAX;
    for (int m = K - 2; m >= 0; m--) {
        for (int n = 0; n < m; n++) {
            int l_n = l[n];
            int l_m = l[m];
            if (include(&l[0], &l[m], l_m - l_n) && include(&l[m+1], &l[K-1], l_m + l_n)) {
                answer = min(answer, l_m - l_n);
            }
        }
    }
    printf("%d\n", answer);

    return 0;
}
