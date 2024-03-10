#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

bool is_palindrome(int n) {
    char str[(int)log10(n)+2];
    sprintf(str, "%d", n);

    int len = strlen(str);

    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return false;
        }
    }

    return true;
}

bool is_binary_palindrome(int n) {
    char binary[(int)(log(n)/log(2))+2];
    int index = 0;

    while (n > 0) {
        binary[index++] = (n % 2) + '0';
        n /= 2;
    }

    for (int i = 0; i < index / 2; i++) {
        if (binary[i] != binary[index - 1 - i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int sum = 0;

    for (int i = 1; i < 1000000; i++) {
        if (is_palindrome(i) && is_binary_palindrome(i)) {
            sum += i;
        }
    }

    printf("%d\n", sum);

    return 0;
}
