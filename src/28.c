#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define SIZE 1001

int calc_diag(int *start, int width, int height){
    long sum = *start;
    sum -= *(start+width/2+(height/2)*width); // uncount the center because it will be double counted
    for (int i=1;i<height;i++){
        sum += *(start+(width+1)*i);
    }
    start += width -= 1;
    sum += *start;
    for (int i=1;i<height;i++){
        sum += *(start+(width)*i);
    }
    
    return sum;
}

int main() {
    assert(SIZE % 2);

    int (*g)[SIZE] = calloc(sizeof(int)*SIZE*SIZE,sizeof(int));
    int p_x = (SIZE / 2);
    int p_y = (SIZE / 2);
    int dy_dx[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int m = 1;
    int n = 1;
    g[p_y][p_x] = 1;
    int k = 2;
    for (int i = 0; n<SIZE;i = (i + 1) % 4) {
        int dy = dy_dx[i][0];
        int dx = dy_dx[i][1];
        for (int j = 0; j < n; j++) {
            p_x += dx;
            p_y += dy;
            g[p_y][p_x] = k;
            k++;
        }
        if (m) {
            m--;
        } else {
            m = 1;
            n += 1;
        }
    }
    k = SIZE*SIZE;
    for (int i = SIZE-1;i > -1;i--){
        g[0][i] = k;
        k--;
    }
    printf("%d\n",calc_diag(g[0],SIZE,SIZE));
    free(g);

    return 0;
}
