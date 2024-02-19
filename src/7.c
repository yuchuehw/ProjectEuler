// What is the 10001 st prime number?

# include <stdio.h>
# include <math.h>
# define KTH_PRIME 10001

int is_prime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void main() {
    int i = 1;
    int counter = 0;
    while (counter < KTH_PRIME) {
        i += 1;
        if (is_prime(i))
            counter += 1;
    }
    printf("The %ith prime is %d\n",KTH_PRIME, i); // 104743
}
