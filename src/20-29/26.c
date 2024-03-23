#include <stdio.h>
#include <string.h>

#define STOP 1000

int main() {
    int max_num = -1;
    int max_denominator = -1;

    for (int j = 1; j < STOP; ++j) {
        int i = 1 % j;
        int l[j];
        memset(l,0,sizeof(int)*j);

        while (l[i] == 0) {
            l[i] = 1;
            i *= 10;
            i = (i >= j) ? (i % j) : i;
        }

        int sum_l = 0;
        for (int k = 0; k < j; k++) {
            sum_l += l[k];
        }

        if (sum_l > max_num) {
            max_num = sum_l;
            max_denominator = j;
        }
    }

    printf("%d\n", max_denominator);

    return 0;
}
