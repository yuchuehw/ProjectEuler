// A Pythagorean triplet is a set of three natural numbers a < b < c for which,
// a² + b² = c²
// For example, 3² + 4² = 9 +16 =25 = 5²
// There exists exactly one Pythagorean triplet for which a+b+c=1000.
// Find the product abc.
# include <stdio.h>
# include <math.h>

int my_func() {
    for (int a = 1; a < 1000; a++) {
        for (int b = 1; b < 1000; b++) {
            int c_square = (a * a + b * b);
            int c = sqrt(c_square);
            if (c * c == c_square && a + b + c == 1000)
                return a * b * c;
        }
    }
    return -1;
}

void main() {
    printf("%d\n", my_func()); // 31875000
}
