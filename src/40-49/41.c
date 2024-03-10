#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPrime(int i){
    for(int j=2;j*j<=i;j++){
        if (i%j == 0){
            return 0;
        }
    }
    return 1;
}

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permuteNfindPrime(char *a, int l, int r, int *max)
{
    int i;
    if (l == r){
        int n = atoi(a);
        if (isPrime(n) && n>*max){
            *max = n;
        }
    }else
    {
        for (i = l; i <= r; i++)
        {
            swap((a + l), (a + i));
            permuteNfindPrime(a, l + 1, r, max);


            swap((a + l), (a + i));
        }
    }
}

int main()
{
    char str[] = "987654321";
    char *str_ptr = str;
    int n = strlen(str_ptr);
    int max = 0;

    for (int i=0;i<=8;i++){
        permuteNfindPrime(str_ptr + i, 0, n-1-i,&max);
        if (max){
            printf("%d\n",max);
            break;
        }
    }


    return 0;
}
