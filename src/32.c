#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define TARGET 9
#define MAXSIZE 100

int check_seen(bool seen[], int n) {
    while (n) {
        if (seen[n % 10]) {
            return 1;  // True
        }
        seen[n % 10] = true;
        n /= 10;
    }
    return 0;  // False
}

bool all(bool *arr,int len){
    for(int i=0;i<len;i++){
        if (!arr[i]){
            return false;
        }
    }
    return true;
}

void arr_cpy(void *dest, void *origin, int len, size_t size) {
    // Use size parameter to correctly calculate the byte size
    memcpy(dest, origin, len * size);
}

int main() {
    int l[MAXSIZE] = {0};

    for (int i = 1; i < 10000; ++i) {
        bool seen[TARGET + 1] = {false};
        seen[0] = true;

        if (check_seen(seen, i)) {
            continue;
        }

        for (int j = 1; j < 10000; ++j) {
            bool seen_copy[TARGET + 1];
            arr_cpy(seen_copy,seen,TARGET + 1,sizeof(bool));

            if (check_seen(seen_copy, j))continue;
            int product = i * j;
            if (check_seen(seen_copy, i * j))continue;

            if (all(seen_copy, TARGET + 1)){
                for (int i=0;i<MAXSIZE;i++){
                    if(! l[i]){
                        l[i] = product;
                        break;
                    }else if(l[i] == product){
                        break;
                    }
                }
            }

        }
    }

    int sum = 0;
    for (int i = 0; i < MAXSIZE; ++i) {
        sum += l[i];
    }

    printf("%d\n", sum);

    return 0;
}
