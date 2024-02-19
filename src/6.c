// The sum of the squares of the first ten natural numbers is,
// 1² + 2² + 3² + ... + 10² = 385
// The square of the sum of the first ten natural numbers is,
// (1 + 2 + 3 + ... + 10)² = 55² = 3025
// Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 
// 3025 - 385 = 2640.
// Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
// 

# include <stdio.h>
# define FIRST_K 100

void main() {

    int s = 0;
    for(int i=0;i<FIRST_K+1;i++)
        s+=i;
    s*=s;
    for(int i=0;i<FIRST_K+1;i++)
        s-=i*i;
    printf("%i\n",s); // 25164150
}
