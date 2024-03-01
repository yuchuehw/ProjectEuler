#include <stdio.h>
#include <math.h>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int sum = 0;

    for (int i = 3; i < 50000; i++) {
        int num = i;
        int digitSum = 0;

        while (num > 0) {
            int digit = num % 10;
            digitSum += factorial(digit);
            num /= 10;
        }

        if (digitSum == i) {
            sum += i;
        }
    }

    printf("%d\n", sum);

    return 0;
}
