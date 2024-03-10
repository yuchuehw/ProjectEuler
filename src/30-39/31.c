#include <stdio.h>

#define TOTAL 200
#define COINS_COUNT 8

int main() {
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
    long long ways[TOTAL + 1] = {0};
    
    ways[0] = 1;

    for (int i = 0; i < COINS_COUNT; ++i) {
        for (int j = coins[i]; j <= TOTAL; ++j) {
            ways[j] += ways[j - coins[i]];
        }
    }

    printf("%lld\n", ways[TOTAL]);

    return 0;
}
