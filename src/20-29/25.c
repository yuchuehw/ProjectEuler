#include <stdio.h>
#define K 1000

int main() {
    // Write C code here
    int n = 1;
    int i[K] = {0};
    int j[K] = {0};
    i[0] = 1;
    j[0] = 1;
    int *ptr1 = i;
    int *ptr2 = j;
    while(ptr1[K-1] == 0){
        int *temp = ptr1;
        ptr1 = ptr2;
        ptr2 = temp;
        int carry = 0;
        for(int k=0;k<K;k++){
            int new_value = ptr1[k]+ptr2[k]+carry;
            ptr2[k] = new_value%10;
            carry = new_value/10;
        }
        n+=1;
    }
    printf("%d\n",n);
    return 0;
}
