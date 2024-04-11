#include <stdio.h>

int sumOfSquares(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

int main() {
    int answer = 0;
    for (int n = 1; n <= 10000000; ++n) {
        int i = n;
        while (i != 1 && i != 89) {
            i = sumOfSquares(i);
        }
        if (i == 89) {
            answer++;
        }
    }
    printf("%d\n", answer);
    return 0;
}
