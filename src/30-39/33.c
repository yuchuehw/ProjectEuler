#include <stdio.h>

// Function to check if two numbers share a common digit
int share_common_digit(int num1, int num2) {
    int digits1[10] = {0}; // Array to store digits of num1
    int digits2[10] = {0}; // Array to store digits of num2

    // Extract digits of num1 and num2
    while (num1 > 0) {
        digits1[num1 % 10] = 1;
        num1 /= 10;
    }

    while (num2 > 0) {
        digits2[num2 % 10] = 1;
        num2 /= 10;
    }

    // Check if any digit is common
    for (int i = 0; i < 10; ++i) {
        if (digits1[i] && digits2[i]) {
            return 1; // Common digit found
        }
    }
    return 0; // No common digit found
}

// Function to find the greatest common divisor (GCD)
int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to simplify fractions
void simplify_fraction(int *numerator, int *denominator) {
    int common_divisor = gcd(*numerator, *denominator);
    *numerator /= common_divisor;
    *denominator /= common_divisor;
}

int main() {
    int numerator_product = 1;
    int denominator_product = 1;

    // Iterate through possible fractions
    for (int numerator = 10; numerator < 100; ++numerator) {
        for (int denominator = numerator + 1; denominator < 100; ++denominator) {
            if (numerator % 10 == 0 && denominator % 10 == 0) {
                continue; // Skip fractions where both numerator and denominator end in 0
            }
            if ((float)numerator / denominator >= 1) {
                continue; // Skip fractions where numerator is greater than or equal to denominator
            }
            if (share_common_digit(numerator, denominator)) {
                // Remove common digits
                int temp_numerator = numerator;
                int temp_denominator = denominator;
                int numerator_digits[10] = {0};
                int denominator_digits[10] = {0};

                while (temp_numerator > 0) {
                    numerator_digits[temp_numerator % 10] = 1;
                    temp_numerator /= 10;
                }

                while (temp_denominator > 0) {
                    denominator_digits[temp_denominator % 10] = 1;
                    temp_denominator /= 10;
                }

                int new_numerator = 0, new_denominator = 0;

                for (int i = 0; i < 10; ++i) {
                    if (numerator_digits[i] && !denominator_digits[i]) {
                        new_numerator = new_numerator * 10 + i;
                    }
                    if (!numerator_digits[i] && denominator_digits[i]) {
                        new_denominator = new_denominator * 10 + i;
                    }
                }

                if (new_numerator == 0 || new_denominator == 0) {
                    continue;
                }

                // Check if the simplified fraction is equal to the original fraction
                if (new_denominator != 0 && (float)new_numerator / new_denominator == (float)numerator / denominator) {
                    printf("found: %d / %d\n", numerator, denominator);
                    numerator_product *= numerator;
                    denominator_product *= denominator;
                }
            }
        }
    }

    // Simplify the final product
    simplify_fraction(&numerator_product, &denominator_product);
    printf("prod: %d / %d\n", numerator_product, denominator_product);

    return 0;
}
