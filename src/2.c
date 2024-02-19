// Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
// 1,2,3,5,8,13,21,34,55,89,...
// By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
# include <stdio.h>

void main(){
    int sum = 0, i = 1, j = 2;
    while(i<4e6){
        sum = i%2 ? sum : sum+i;
        int temp = i+j;
        i = j;
        j = temp;
    }
    printf("%i\n",sum); // 4613732
}
