#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LONGEST_NAME 20
// Comparison function for qsort
int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    char name_list[][LONGEST_NAME] = {"MARY","PATRICIA","LINDA","BARBARA","ELIZABETH", ...};

    // Calculate the actual length of the array
    size_t array_length = sizeof(name_list) / sizeof(name_list[0]);

    // Convert the array of strings to an array of pointers
    const char *name_ptrs[array_length];
    for (size_t i = 0; i < array_length; i++) {
        name_ptrs[i] = name_list[i];
    }

    // Sort the array of pointers using qsort
    qsort(name_ptrs, array_length, sizeof(char *), compareStrings);

    // Print the sorted array
    long sum = 0;
    for (size_t i = 0; i < array_length; i++) {
        long name_sum = 0;
        for (int j = 0; j < LONGEST_NAME; j++){
            if(name_ptrs[i][j] == '\0')
                break;
            name_sum += name_ptrs[i][j] - 'A' + 1;
        }
        sum += name_sum * (i + 1);
    }
    printf("%ld\n", sum);

    return 0;
}
