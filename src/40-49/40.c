#include <stdio.h>
#include <string.h>
#include <math.h>

#define K 6

int ipow(int base, int exp)
{
    int result = 1;
    for (;;)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }

    return result;
}

int main() {
    char *s = malloc(sizeof(char)*(ipow(10, K) + 2));
    char *ptr_s = s;
    char *end = &s[(int)pow(10, K)];

    for (int i = 1;; i++) {
        char buf[K+2];
        snprintf(buf, K+1, "%d", i); // problemetic line
        if (ptr_s >= end) {
            break;
        }
        int len = strlen(buf);
        if (ptr_s + len > end) {
            len = end - ptr_s;
        }
        strncpy(ptr_s, buf, len);
        ptr_s += len;
    }

    int answer = 1;
    for (int i = 0; i <= K; i++) {
        answer *= s[(int)pow(10, i)-1] - '0';
    }
    printf("%d\n", answer);

    return 0;
}
