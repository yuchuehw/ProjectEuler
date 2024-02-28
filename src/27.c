#include <stdio.h>

int is_prime(int num) {
    if (num < 2 || num%2==0) {
        return 0;
    }
    for (int i = 3; i * i <= num; i+=2) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int max_ = -1;
    int pair[2] = {0, 0};

    for (int a = -1000; a <= 1000; a++) {
        for (int b = -1000; b <= 1000; b++) {
            
            int is_prime_val = 1;
            int n = 0;
            
            while (is_prime_val) {
                int num = n * n + a * n + b;
                if (!is_prime(num)) {
                    is_prime_val = 0;
                } else {
                    n++;
                }
            }

            if (n > max_) {
                max_ = n;
                pair[0] = a;
                pair[1] = b;
            }
        }
    }

    printf("%d\n", pair[0] * pair[1]);

    return 0;
}
