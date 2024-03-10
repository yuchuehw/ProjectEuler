#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRIANGLE "\
75\n\
95 64\n\
17 47 82\n\
18 35 87 10\n\
20 04 82 47 65\n\
19 01 23 75 03 34\n\
88 02 77 73 07 63 67\n\
99 65 04 28 06 16 70 92\n\
41 41 26 56 83 40 80 70 33\n\
41 48 72 33 47 32 37 16 94 29\n\
53 71 44 65 25 43 91 52 97 51 14\n\
70 11 33 28 77 73 17 78 39 68 17 57\n\
91 71 52 38 17 14 91 43 58 50 27 29 48\n\
63 66 04 68 89 53 67 30 73 16 69 87 40 31\n\
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23"

int main() {
    int height = 1;
    for(int i=0;i < strlen(TRIANGLE);i++){
        if(TRIANGLE[i] == '\n')
            height += 1;
    }
    int grid[height][height];
    char triangle_copy[strlen(TRIANGLE) + 1];
    strcpy(triangle_copy, TRIANGLE);

    char *token = strtok(triangle_copy, "\n");
    int i = 0;

    while (token != NULL) {
        char token_copy[strlen(TRIANGLE)];
        strcpy(token_copy,token);
        char *ptr = token_copy;
        char *endptr;
        int j = 0;
        while (*ptr != '\0') {
            grid[i][j] = (int)strtol(ptr, &endptr, 10);
            j++;
            ptr = endptr;
        }
        i++;
        token = strtok(NULL, "\n");
    }
    for(int row=height-1;row>0;row--){
        for(int col=0;col<height-1;col++){
            grid[row-1][col] += grid[row][col] > grid[row][col+1] ? grid[row][col]: grid[row][col+1];
        }
             
    }
    printf("%d\n",grid[0][0]); // 1074 
}
