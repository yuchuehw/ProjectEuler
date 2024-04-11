#include <stdio.h>
#include <stdlib.h>
#define K 10000001
#define LINKSIZE 100

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
    int *seen = calloc(K, sizeof(int));
    seen[1] = 1;
    seen[89] = 89;
    int answer = 0;
    for (int n = 1; n <= K; n++) {
        int i = n;
        int j = 1;
        int link[LINKSIZE] = {0};
        link[0] = i;
        while (!seen[i]) {
            i = sumOfSquares(i);
            link[j] = i;
            j++;
            j %= LINKSIZE;
        }
        if (seen[i] == 89) {
            seen[n] = 89;
            for (int k = 0; k < j; k++) {
                seen[link[k]] = 89;
            }
            answer++;
        } else {
            seen[n] = 1;
            for (int k = 0; k < j; k++) {
                seen[link[k]] = 1;
            }
        }
    }
    printf("%d\n", answer);
    free(seen);  // Free dynamically allocated memory
    return 0;
}
