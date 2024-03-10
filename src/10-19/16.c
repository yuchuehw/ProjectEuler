#include <stdio.h>
#include <math.h>

int main() {
    // Calculate 2^1000
    double result = pow(2, 1000);

    char str[1000];
    sprintf(str, "%f", result);

    int i = 0;
    int sum = 0;
    while(1){
        if(str[i] == '.'){
            break;
        }
        sum += str[i]-'0';
        i++;
    }
    printf("%i\n",sum);
    return 0;
}
