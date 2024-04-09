#include <stdio.h>
#include <float.h>

int main() {
    double minDist = DBL_MAX;
    int bestNum = 0;
    int bestDenom = 1;

    // Get the reduced fraction with the corresponding denominator
    // that is closest to the left of 3/7. Calculate distance for each one...
    for (int denom = 3; denom <= 1000000; denom++) {
        // Skip multiples of 7
        if (denom % 7 == 0) continue;

        // Calculate closest numerator
        int num = (3 * denom) / 7;
        
        // Calculate distance
        double dist = 3.0 / 7.0 - (double)num / denom;

        if (dist < minDist) {
            minDist = dist;
            bestNum = num;
            bestDenom = denom;
        }
    }

    printf("%d / %d\n", bestNum, bestDenom);

    return 0;
}
