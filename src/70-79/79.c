#include <stdio.h>
#include <stdlib.h>

typedef struct Tuple {
    int x;
    int y;
} Tuple;

int compareTupleReversed(const void *a, const void *b) {
    Tuple *ta = (Tuple*)a;
    Tuple *tb = (Tuple*)b;
    if (ta->y > tb->y) {
        return -1;
    } else if (ta->y < tb->y) {
        return 1;
    }
    return 0;
}

int main() {
    int data[] = {319, 680, 180, 690, 129, 620, 762, 689, 762, 318, 368, 710, 720, 710, 629, 168, 160, 689, 716, 731, 736, 729, 316, 729, 729, 710, 769, 290, 719, 680, 318, 389, 162, 289, 162, 718, 729, 319, 790, 680, 890, 362, 319, 760, 316, 729, 380, 319, 728, 716};
    int d[10][10] = {{0}};
    int seen[10] = {0};
    int i, j;

    // Process log
    for (i = 0; i < sizeof(data) / sizeof(int); i++) {
        int num = data[i];
        int a = num / 100;
        int b = (num / 10) % 10;
        int c = num % 10;
        d[a][b] = 1;
        d[a][c] = 1;
        d[b][c] = 1;
        
        seen[a] = 1;
        seen[b] = 1;
        seen[c] = 1;
    }

    // Find most occurring digits
    Tuple d_most[10];
    int seen_count = 0;
    for (i = 0; i < 10; i++) {
        if (!seen[i]){
            continue;
        }
        
        int sum = 0;
        for (j = 0; j < 10; j++) {
            sum += d[i][j];
        }
        d_most[seen_count].y = sum;
        d_most[seen_count].x = i;
        seen_count++;
    }
    qsort(d_most, seen_count, sizeof(Tuple), compareTupleReversed);

    // Print most occurring digits
    for (i = 0; i < seen_count; i++) {
        printf("%d", d_most[i].x);
    }
    printf("\n");

    return 0;
}
