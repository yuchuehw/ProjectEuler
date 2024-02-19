# include <stdio.h>
# include <string.h>
void main() {
    const int FIRST_K = 2000000;
    char is_prime[FIRST_K + 1];
    memset(is_prime, 0, sizeof(is_prime));
    is_prime[0] = 1;
    is_prime[1] = 1;
    long sum = 0; 
    for (int i = 2; i * i <= FIRST_K; i++) {
        if (is_prime[i])
            continue;
        for (int j = i * i; j <= FIRST_K; j += i)
            is_prime[j] = 1;
    }
    for (int i = 2; i <= FIRST_K; i++) {
        if (!is_prime[i])
            sum += i;
    }
    printf("%ld\n", sum); // 142913828922
}
