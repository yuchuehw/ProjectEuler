#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIMIT 1000000

int main() {
    bool *not_primes = calloc((LIMIT + 1), sizeof(bool));
    not_primes[0] = true;
    not_primes[1] = true;

    for (int i = 0; i * i <= LIMIT; i++) {
        if (!not_primes[i]) {
            for (int j = 2 * i; j <= LIMIT; j += i) {
                not_primes[j] = true;
            }
        }
    }
    int answer = 0;
    int multiplier = 10;
    for (int i=0;i<=LIMIT;i++){
        if (i==multiplier*10){
            multiplier*=10;
        }
        if (not_primes[i]){
            continue;
        }

        if (i/10==0){
            answer+=1;
            continue;
        }
        int n = (i%10)*multiplier + i/10;
        bool flag = true;
        while (n!=i){
            if(not_primes[n]){
                flag = false;
                break;
            }
            n = (n%10)*multiplier + n/10;
        }
        if (flag){
            answer ++;
        }
    }
    printf("%d\n",answer);

}
