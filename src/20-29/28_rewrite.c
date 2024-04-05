#include <stdio.h>

#define K 1001

int main() {
    int i = 1, m = 1, n = 1;
    int answer = K * K;

    for (int x = 0; x < (K - 1) / 2; x++) {
        for (int y = 0; y < 4; y++) {
            i = i + n;
            
            if (y == 0) answer += i - 1;
            else answer += i;

            if (m) m -= 1;
            else {
                m = 1;
                n++;
            }
        }
    }

    printf("%d\n", answer);
    return 0;
}
