#include <stdio.h>
#define WIDTH 20
#define HEIGHT 20

long long lattice_path(int x, int y, int width, int height, long long *cache) {
    if(x==width || y==height)
        return 1;
    if(x >width || y>height)
        return 0;
    long long *cell = cache+x+y*height;
    if(*cell == 0)
        *cell = lattice_path(x+1,y,width,height,cache) + 
                lattice_path(x,y+1,width,height,cache);
    return *cell;
}

int main() {
    long long grid[WIDTH][HEIGHT] = {0};
    printf("%lld\n",lattice_path(0,0,WIDTH,HEIGHT,&grid[0][0]));
    return 0;
}
