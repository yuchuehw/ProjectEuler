#include <math.h>

int is_prime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void main() {
    const int TARGET = 10001;
    int i = 1;
    int counter = 0;
    while (counter < TARGET) {
        i += 1;
        if (is_prime(i))
            counter += 1;
    }
    printf("%d\n", i); // 104743
}
