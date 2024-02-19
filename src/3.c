// The prime factors of 13195 are 5, 7, 13, and 29.
// 
// What is the largest prime factor of the number 600851475143?
# include <stdio.h>

int isPrime(long number){
    for(long i = 2; i < number; i++){
        if(number % i == 0){
            return 0;
        }
    }
    return 1;
}

void main() {
    const long C = 600851475143;
    long c = C;
    for(long i = 2; i < C; i++){
        if(c % i == 0 && isPrime(i)) {
            c /= i;
            if(c == 1){
                printf("%ld\n", i);//6857
                break;
            }
        }
    }
}
