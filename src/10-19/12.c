#include <stdio.h>
#include <math.h>

#define TARGET 500

int main() {
    int i = 0;
    int j = 0;
    while (1) {
        j += 1;
        i += j;
        int num = i;
        int count = 1;
        for (int p = 2; p <= sqrt(i); p++) {
            int exponent = 1;
            while (num % p == 0) {
                exponent += 1;
                num /= p;
            }
            count *= exponent;
        }
        if (count > TARGET) {
            printf("%d\n", i); // 76576500
            break;
        }
    }
    return 0;
}
