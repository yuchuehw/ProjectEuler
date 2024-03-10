#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "Q11CONST.h"

#define GROUPSIZE 4
// for bigger group size edit line 6 from int --> long 
//                          & line 7 from INT_MAX --> LONG_MAX
//                          & line 7 from "%d\n" --> "%ld\n"
#define PRODTYPE long
#define PRODTYPE_MAX LONG_MAX
#define FORMATTER "%ld\n"

struct GridSize {
    int rows;
    int cols;
};

struct GridSize calc_grid_size(char *s) {
    struct GridSize size;
    size.rows = 0;
    size.cols = 0;

    char *token = strtok(s, "\n");
    char first_row[strlen(GRID_STRING)];
    first_row[0] = '\0';

    while (token != NULL) {
        if (first_row[0] == '\0') {
            strcpy(first_row, token);
        }
        size.rows++;
        token = strtok(NULL, "\n");
    }

    char *token2 = strtok(first_row, " ");
    while (token2 != NULL) {
        size.cols++;
        token2 = strtok(NULL, " ");
    }

    return size;
}

void initGrid(int* grid, char *s) {
    char *ptr = s;  // Use a separate pointer for iteration
    char *endptr;
    while (*ptr != '\0') {
        *grid = strtol(ptr, &endptr, 10);
        grid++;
        ptr = endptr;
    }
}

PRODTYPE max_in_one_dir(int *pos_ptr, int group_size, int jump, int depth){
    long max = -1;
    for(int i=0;i<=depth;i++){
        PRODTYPE prod = 1;
        int *ptr_cpy = pos_ptr;
        for(int j=0;j<group_size;j++){
            if (*ptr_cpy!=0 && prod > PRODTYPE_MAX / *ptr_cpy) {
                printf("an overflow occurs when performing max_in_one_dir(). consider changing the PRODTYPE.\n");
                exit(1);
            }
            prod *= *ptr_cpy;
            ptr_cpy += jump;
        }
        if(prod>max)
            max=prod;
        pos_ptr += jump;
    }
    return max;
}

int main() {
    char grid_string_copy[strlen(GRID_STRING) + 1];
    strcpy(grid_string_copy, GRID_STRING);
    struct GridSize size = calc_grid_size(grid_string_copy);

    int grid[size.rows][size.cols];
    initGrid(grid[0], GRID_STRING);
    PRODTYPE max = -1;
    // row
    for(int i=0;i<size.rows;i++){
        PRODTYPE m = max_in_one_dir(
            grid[i],GROUPSIZE,1,size.cols-GROUPSIZE);
        if(m > max)
            max=m;
    }
    // col
    for(int i=0;i<size.cols;i++){
        PRODTYPE m = max_in_one_dir(
            &grid[0][i],GROUPSIZE,size.cols,size.rows-GROUPSIZE);

        if(m > max)
            max=m;
    }
    // diag/anti-diag 1
    for(int i=0;i<size.rows-GROUPSIZE;i++){
        PRODTYPE m = max_in_one_dir(
            grid[size.rows-i-GROUPSIZE],GROUPSIZE,size.cols+1,i);

        if(m > max)
            max=m;

        m = max_in_one_dir(
            &grid[size.rows-i-GROUPSIZE][size.cols-1],GROUPSIZE,size.cols-1,i);
        
        if(m > max)
            max=m;
    }
    // diag/anti-diag 2
    for(int i=0;i<size.cols-GROUPSIZE;i++){
        PRODTYPE m = max_in_one_dir(
            &grid[0][size.cols-i-GROUPSIZE],GROUPSIZE,size.cols+1,i);
        
        if(m > max)
            max=m;
        
        m = max_in_one_dir(
            &grid[0][i+GROUPSIZE-1],GROUPSIZE,size.cols-1,i);
        
        if(m > max)
            max=m;
    }
    
    printf(FORMATTER,max); // 70600674

    return 0;
}
