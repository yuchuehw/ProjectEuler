#include <stdio.h>

int count_permutation(int m) {
    int aux(int n, int max_num) {
        if (max_num < 1) {
            return 0;
        }
        if (n <= 1) {
            return 1;
        }
        if (n < max_num) {
            return aux(n, n);
        }
        return aux(n - max_num, max_num) + aux(n, max_num - 1);
    }

    return aux(m, m - 1);
}

int main() {
    printf("%d\n", count_permutation(5));
    return 0;
}
