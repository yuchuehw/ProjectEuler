#include <stdio.h>
#include <math.h>

#define POWER 5

int main() {
    int sum_of_powers(int num);
    int sum = 0;
    for (int i = 2; i < 1000000; i++) {
        if (i == sum_of_powers(i)) {
            sum+=i;
        }
    }
    printf("%d\n", sum);

    return 0;
}

int sum_of_powers(int num) {
    int sum = 0;
    int original = num;

    while (num > 0) {
        int digit = num % 10;
        sum += (int)pow(digit, POWER);
        num /= 10;
    }

    return sum;
}
