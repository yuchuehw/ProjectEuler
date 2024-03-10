#include <stdio.h>
#define K 10
#define N 1000000

int main() {
    int pool[K];
    for(int i=0;i<K;i++){
        pool[i] = i;
    }
    int n = K;
    int r = K;
    int indices[n];
    int cycles[r];
    for(int i=0;i<n;i++){
        indices[i] = i;
    }
    for(int i=0,j=n;j>n-r;i++,j--){
        cycles[i] = j;
    }
    int j = 1;
    int break_flag;
    while(j<N){
        break_flag = 0;
        for(int i=r-1;i>-1;i--){
            cycles[i]-=1;
            if(cycles[i] == 0){
                int temp = indices[i];
                for(int k=i;k<n-1;k++){
                    indices[k]=indices[k+1];
                }
                indices[n-1] = temp;
                cycles[i] = n-i;
            }else{
                int k = cycles[i];
                int temp = indices[i];
                indices[i] = indices[n-k];
                indices[n-k] = temp;
                j+=1;
                break_flag = 1;
                break;
            }
        }
        if(break_flag == 0){
            printf("N is bigger than all permuations\n");
            break;
        }
    }
    if(break_flag == 1){
        for(int z=0;z<r;z++){
            printf("%d",indices[z]);
        }
        printf("\n");
    }
    
}
