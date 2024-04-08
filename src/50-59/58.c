#include <stdio.h>
#include <stdbool.h>

#define RUN 10000
#define TARGET 0.1

bool isprime(long n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    long i = 1;
    long m = 1;
    long n = 1;

    int prime_count = 0;
    int total_count = 0;

    int x = -1;
    while (1) {
        x++;
        for (int y = 0; y < 4; y++) {
            i += n;

            total_count++;
            if (y == 0) {
                prime_count += isprime(i - 1) ? 1 : 0;
                if (prime_count && (double)prime_count / total_count < TARGET) {
                    printf("%d\n", x * 2 + 1);
                    return 0;
                }
            } else {
                prime_count += isprime(i) ? 1 : 0;
            }
            if (m) {
                m--;
            } else {
                m = 1;
                n = n + 1;
            }
        }
    }
    return 0;
}
