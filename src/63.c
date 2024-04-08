#include <stdio.h>
#include <math.h>

int main() {
    int count = 0;
    for (int x = 1; x < 100; x++) {
        for (int y = 1; y < 100; y++) {
            double result = pow(x, y);
            int result_length = log10(result)+1;
            count += (result_length == y) ? 1:0;
        }
    }
    printf("%d\n", count);
    return 0;
}
