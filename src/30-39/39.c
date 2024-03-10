#include <stdio.h>
#include <math.h>
#define K 1000

int main() {
    int l[K+1] = {0};
    for (int i=1;i<=K/2;i++){
        for (int j=1;j<=K/2;j++){
            int k2 = i*i + j*j;
            int k = sqrt(k2);
            if (fmod(sqrt(k2),1) == 0 && i+j+k<=K){
                l[i+j+k]+=1;
            }
        }    
    }
    int max1 = -1;
    int max2 = -1;
    for(int i=0;i<=K;i++){
        if (l[i] > max1){
            max1 = l[i];
            max2 = i;
        }
    }
    printf("%d\n",max2);
    return 0;
}
