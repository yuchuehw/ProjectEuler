// Online C compiler to run C program online
#include <stdio.h>
#define LIMIT 28123
int main() {
    int array[LIMIT] = {0};
    for(int i=0;i<LIMIT;i++){
        int sum_divisor = 0;
        for(int j=1;j<i;j++){
            if(i%j ==0)
                sum_divisor += j;
        }
        if(sum_divisor > i)
            array[i] = 1;
    }
    int sum = 0;
    for(int i=0;i<LIMIT;i++){
        int flag = 0;
        for(int j = 0;j<i;j++){
            if(array[j] && array[i-j]){
                flag = 1;
                break;
            }
        }
        if(!flag){
            sum += i;
        }
    }
    printf("%d\n",sum);
    return 0;
}
