#include <math.h>

int lcm_of_first_n_int(int FIRST_N){
    int factorization_all[FIRST_N+1];
    memset(factorization_all, 0x00, sizeof(factorization_all));
    for(int i = 2; i < FIRST_N + 1; i++){
        int factorization_i[FIRST_N + 1];
        memset(factorization_i, 0x00, sizeof(factorization_all));
        int num = i;
        for(int j = 2; j < i + 1; j++){
            while(num % j == 0){
                num /= j;
                factorization_i[j] += 1;
            }
        }
        for(int j = 2; j < FIRST_N + 1; j++){
            if(factorization_i[j] > factorization_all[j]){
                factorization_all[j] = factorization_i[j];
            }
        }
    }
    int prod = 1;
    for(int i = 2; i < FIRST_N + 1; i++){
        int j = pow(i, factorization_all[i]);
        prod *= j;
    }
    return prod;
}

void main(){
    printf("%d", lcm_of_first_n_int(20));// 232792560
}
