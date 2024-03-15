#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define K 1000000
#define WINDOW 4
#define TARGET 4

int main() {
    bool *prime = malloc((K + 1) * sizeof(bool));  // Allocate memory for K+1 elements
    if (prime == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    int *prime_num = malloc(K * sizeof(int));
    if (prime_num == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    int count = 0;

    // Initializing prime array
    for (int i = 0; i <= K; i++)
        prime[i] = true;

    // Sieve of Eratosthenes algorithm
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= K; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= K; j += i)
                prime[j] = false;
        }
    }

    // Generating prime_num array
    for (int i = 0; i <= K; i++) {
        if (prime[i])
            prime_num[count++] = i;
    }

    // Finding consecutive numbers
    for (int i = 0; i < K; i++) {
        bool invalid = false;
        for (int j = i; j < i + WINDOW; j++) {
            if (prime[j]){
                invalid = true;
                break;
            }
        }

        if (invalid) {
            continue;
        }
        
        int c;
        for (int j = i; j < i + WINDOW; j++) {
            c = 0;
            int n = j;
            for (int k = 0; k < count; k++) {
                if (n % prime_num[k] == 0) {
                    c++;
                }
                while (n % prime_num[k] == 0) {
                    n /= prime_num[k];
                }
                if (n == 1) {
                    break;
                }
            }
            if (c != TARGET) {
                break;
            }
        }
        if (c == TARGET) {
            printf("%d\n", i);
            break;
        }
    }

    free(prime);
    free(prime_num);

    return 0;
}
