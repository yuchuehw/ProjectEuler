#include <stdio.h>

#define LIMIT 1000000

long long collatz(long long n, long long *cache) {
    if (n == 1) {
        return 1;
    }
    if (n < LIMIT && cache[n] != 0) {
        return cache[n];
    }
    long long result;
    if (n % 2) {
        result = 1 + collatz(3 * n + 1, cache);
    } else {
        result = 1 + collatz(n / 2, cache);
    }
    if (n < LIMIT) {
        cache[n] = result;
    }
    return result;
}

int main() {
    long long max_length = 0;
    long long max_starting_number = 0;
    long long cache[LIMIT] = {0};

    for (long long x = LIMIT / 2; x < LIMIT; x++) {
        long long length = collatz(x, cache);
        if (length > max_length) {
            max_length = length;
            max_starting_number = x;
        }
    }

    printf("%lld\n", max_starting_number); // 837799

    return 0;
}
