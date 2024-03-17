#include <stdio.h>
#include <stdbool.h>
#define MULT 6

int main() {
    for (int x=1;x<1000000;x++){
        bool target[10] = {false};
        int n = x;
        while (n){
            target[n%10] = true;
            n/=10;
        }
        bool flag = false;
        for (int multiplier = 2;multiplier<MULT;multiplier++){
            n = x*multiplier;
            while (n){
                if (!target[n%10]){
                    flag = true;
                    break;
                }
                n/=10;
            }
            if (flag){
                break;
            }
        }
        if (!flag){
            printf("%d",x);
            break;
        }
    }
}
