#include <stdio.h>
#include <stdbool.h>

#define K 1000000

int main() {
    bool p[K + 1];
    int primes_l[K + 1];
    int answer = -1;
    int min_ = 0;
    int len_;

    // Sieve of Eratosthenes to generate primes
    for (int i = 0; i <= K; i++)
        p[i] = true;
    p[0] = p[1] = false;
    for (int i = 0; i < K; i++) {
        if (p[i]) {
            for (int j = i * 2; j < K; j += i)
                p[j] = false;
        }
    }

    // Store prime numbers in primes_l
    int idx = 0;
    for (int i = 0; i <= K; i++) {
        if (p[i]) {
            primes_l[idx++] = i;
        }
    }
    len_ = idx;

    // Finding the longest sum of consecutive primes below K
    for (int i = 0; i < len_; i++) {
        for (int j = i + min_; j < len_; j++) {
            int sum = 0;
            for (int k = i; k < j; k++) {
                sum += primes_l[k];
                if (sum >= K)
                    break;
            }
            if (sum >= K)
                break;
            if (p[sum]) {
                min_ = j - i;
                answer = sum;
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}
