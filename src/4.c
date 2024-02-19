// A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is
// 9009 = 91 x 99.
// 
// Find the largest palindrome made from the product of two 3-digit numbers.
# include <stdio.h>
#include <string.h>
#include <math.h>

int is_palindrom(char *c){
    int length_c = strlen(c);
    for(int i = 0; i < length_c; i++){
        if(c[i] != c[length_c - 1 - i]){
            return 0;
        }
    }
    return 1;
}

int find_largest_palindromic_product_of_n_digits(long digits){
    int max = -1;
    const int LOW_BOUND = pow(10,digits) - 1;
    const int UP_BOUND = pow(10,digits - 1) - 1;
    char str[2*digits+1];
    for(int i = LOW_BOUND; i > UP_BOUND; i--){
        for(int j = LOW_BOUND; j > UP_BOUND; j--){
            int ij = i * j;
            if(ij < max){
                continue;
            }
            sprintf(str, "%d", ij);
            if(is_palindrom(str)){
                max = ij;
            }
        }   
    }
    return max;
}


void main() {
    printf("%d\n", find_largest_palindromic_product_of_n_digits(3));// 906609
}
