#include <stdio.h>
#define N 10000
int main() {
    int l[N] = {1};
    int s = 0;
    for(int i=0;i<N;i++){
        int j =1;
        for(int k=2;k<i;k++){
            if(i%k == 0)
                j+=k;
        }
        if(j<i && l[j] == i)
            s+=i+j;
        l[i] = j;
    }
    printf("%d\n",s);
}
