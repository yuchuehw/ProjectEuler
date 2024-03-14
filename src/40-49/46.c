#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define K 10000

int main() {
    int *primes = calloc(K, sizeof(int));
    int *odd_composite = calloc(K, sizeof(int));
    primes[0] = 2;
    int prime_count = 1;
    int composite_count = 0;
    
    // Find primes and odd composites
    for (int i = 3; i < K; i += 2) {
        bool is_prime = true;
        for (int j = 3; j * j <= i && is_prime; j += 2) {
            if (i % j == 0)
                is_prime = false;
        }
        if (is_prime) {
            primes[prime_count++] = i;
        } else {
            odd_composite[composite_count++] = i;
        }
    }
    
    // Check for Goldbach's conjecture
    for (int i = 0; i < composite_count; i++) {
        int composite = odd_composite[i];
        bool flag = true; // initialize to false
        for (int j = 0; j < prime_count; j++) {
            int prime = primes[j];
            if (prime >= composite)
                break;
            int diff = composite - prime;
            int k = sqrt(diff / 2);
            if (2 * k * k == diff) {
                flag = false;
                break;
            }
        }
        if (flag) {
            printf("%d\n", composite);
            break;
        }
    }
    
    free(primes);
    free(odd_composite);
    return 0;
}
