#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHAR_ARRAY_SIZE 1000

int add(char *addent, char const *adder, int const size) {
    // return if the resultant addent has more digit than adder
    char carry = 0;
    int addent_digit = 0;
    int adder_digit = 0;
    for (int i = 0; i < size; i++) {
        int temp = (addent[i] + adder[i] + carry) % 10;
        carry = (addent[i] + adder[i] + carry) / 10;
        addent[i] = temp;
        if (temp) addent_digit = i + 1;
        if (adder[i]) adder_digit = i + 1;
    }
    return (addent_digit>adder_digit) ? 1 : 0;
}

int main() {
    int answer = 0;
    char *numerator = calloc(CHAR_ARRAY_SIZE, sizeof(char));
    char *denominator = calloc(CHAR_ARRAY_SIZE, sizeof(char));
    numerator[0] = 1;
    denominator[0] = 2;
    char *numerator_ptr = numerator;
    char *denominator_ptr = denominator;
    for (int i = 0; i < 1000; i++) {
        add(numerator_ptr, denominator_ptr, CHAR_ARRAY_SIZE);
        add(numerator_ptr, denominator_ptr, CHAR_ARRAY_SIZE);
        char *temp_ptr = numerator_ptr;
        numerator_ptr = denominator_ptr;
        denominator_ptr = temp_ptr;
        temp_ptr = calloc(CHAR_ARRAY_SIZE, sizeof(char));
        memcpy(temp_ptr, numerator_ptr, CHAR_ARRAY_SIZE * sizeof(char));
        answer += add(temp_ptr, denominator_ptr, CHAR_ARRAY_SIZE);
        free(temp_ptr);
    }
    printf("%d\n", answer);//153
    free(numerator);
    free(denominator);
    return 0;
}
