#include <stdio.h>
#include <string.h>

char *ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char *tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

int main() {
    int answer = 0;
    for (int i = 1; i < 1000; i++) {
        int hundred = i / 100;
        int ten = (i % 100) / 10;
        int one = i % 10;

        if (hundred) {
            answer += strlen(ones[hundred]);
            answer += strlen("hundred");
            if (ten || one)
                answer += strlen("and");
        }

        if (ten == 1) {
            answer += strlen(teens[one]);
            continue;
        }

        answer += strlen(tens[ten]);
        answer += strlen(ones[one]);
    }

    answer += strlen("onethousand");
    printf("%d\n", answer);

    return 0;
}
