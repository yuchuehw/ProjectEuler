#include <stdio.h>

#define K 60000

int main() {
  unsigned long long Pentagonal[K], Hexagonal[K], Pen_Hex_intersection[K];
  int pentagonal_count = 0, hexagonal_count = 0, intersection_count = 0;

  // Generate Pentagonal numbers
  for (int n = 1; n < K; n++) {
    Pentagonal[pentagonal_count] = (unsigned long long)n * (3 * n - 1) / 2;
    pentagonal_count++;
  }

  // Generate Hexagonal numbers
  for (int n = 1; n < K; n++) {
    Hexagonal[hexagonal_count] = (unsigned long long)n * (2 * n - 1);
    hexagonal_count++;
  }
  
  // Find intersection
  for (int i = 0; i < pentagonal_count; i++) {
    for (int j = 0; j < hexagonal_count; j++) {
      if (Pentagonal[i] == Hexagonal[j]) {
        Pen_Hex_intersection[intersection_count] = Pentagonal[i];
        intersection_count++;
        break; // Early exit from inner loop if found
      }
    }
  }

  // Check for triangular numbers in the intersection
  for (int n = 1; n < K; n++) {
    unsigned long long triangular_number = (unsigned long long)n * (n + 1) / 2;
    for (int i = 0; i < intersection_count; i++) {
      if (Pen_Hex_intersection[i] == triangular_number) {
        printf("%llu\n", triangular_number);
        break; // Early exit from inner loop if a match is found
      }
    }
  }

  return 0;
}
