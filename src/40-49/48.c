#include <stdio.h>

#define DIGIT_TO_KEEP 11

void multiply_numbers(int *a, int *b, int *c, int digit) {
    int i, j, carry;
    for (i = 0; i < digit; i++)
        c[i] = 0;

    for (i = 0; i < digit; i++) {
        carry = 0;
        for (j = 0; j < digit; j++) {
            if (i + j >= digit)
                continue;
            carry += a[i] * b[j] + c[i + j];
            c[i + j] = carry % 10;
            carry /= 10;
        }
        if (i + j < digit && carry)
            c[i + j] = carry;
    }
}

void add_numbers(int *a, int *b, int digit) {
    int i, carry = 0;
    for (i = 0; i < digit; i++) {
        carry += a[i] + b[i];
        b[i] = carry % 10;
        carry /= 10;
    }
}

int main() {
    int s[DIGIT_TO_KEEP] = {0};
    int a[DIGIT_TO_KEEP], b[DIGIT_TO_KEEP], c[DIGIT_TO_KEEP];
    int i, j, n;

    for (i = 1; i <= 1000; i++) {
        n = i;
        for (j = 0; j < DIGIT_TO_KEEP; j++) {
            a[j] = b[j] = c[j] = n % 10;
            n /= 10;
        }

        for (j = 0; j < i - 1; j++) {
            multiply_numbers(a, b, c, DIGIT_TO_KEEP);
            for (int k = 0; k < DIGIT_TO_KEEP; k++)
                a[k] = c[k];
        }

        add_numbers(c, s, DIGIT_TO_KEEP);
    }

    for (i = DIGIT_TO_KEEP - 2; i >= 0; i--)
        printf("%d", s[i]);
    printf("\n");

    return 0;
}
