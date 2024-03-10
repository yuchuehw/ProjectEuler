#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TARGET 100

/**
 * Multiply two arrays of integers and store the result in a third array.
 * Note the ordering of numbers is left to right.
 * For example, to calculate 17 * 17, use:
 *     mul_array({7, 1}, {7, 1}, {0, 0, 0, 0}, 2, 2);
 * The output is also right to left: {9, 8, 2, 0}.
 */
void mul_array(int *a1, int *a2, int *a3, int len_a1, int len_a2) {
    memset(a3, 0, (len_a1 + len_a2) * sizeof(int));

    for (int i = 0; i < len_a1; i++) {
        int carry = 0;
        for (int j = 0; j < len_a2; j++) {
            int k = a2[j] * a1[i] + a3[i + j] + carry;
            a3[i + j] = k % 10;
            carry = k / 10;
        }
        a3[i + len_a2] += carry;
    }
}

int main() {
    int *arr_pointer = malloc(sizeof(int));
    arr_pointer[0] = 1;
    int arr_len = 1;
    for (int i = 1; i < TARGET+1; i++) {
        int n = i;
        int digits = 0;

        while (n) {
            n /= 10;
            digits += 1;
        }

        n = i;
        int array2[digits];
        memset(array2, 0, digits * sizeof(int));

        int counter = 0;
        while (n) {
            array2[counter] = n % 10;
            n /= 10;
            counter += 1;
        }

        int *array3 = malloc((arr_len + digits) * sizeof(int));
        mul_array(arr_pointer, array2, array3, arr_len, digits);

        
        free(arr_pointer);
        
        arr_len += digits;
        arr_pointer = array3;
    }

    int s = 0;
    for (int i = 0; i < arr_len; i++) {
        s += arr_pointer[i];
    }

    printf("%d\n", s);
    free(arr_pointer);
    return 0;
}

// python equivlent
// def mul_list(m1: [int], m2: [int]) -> list:
//     """
//     Multiply m1 by m2.
    
//     Note the ordering of numbers is left to right.
//     For example, to calculate 17 * 17, use:
//         mul_list([7, 1], [7, 1])
    
//     The output is also right to left:
//          [9,8,2,0]
//     """
//     len_m1, len_m2 = len(m1), len(m2)
//     m3 = [0] * (len_m1 + len_m2)

//     for i in range(len_m1):
//         carry = 0
//         for j in range(len_m2):
//             k = m2[j] * m1[i] + m3[i + j] + carry
//             m3[i + j] = k % 10
//             carry = k // 10

//         m3[i + len_m2] += carry


//     return m3

// l = [1]
// for i in range(1,101):
//     m = []
//     n = i
//     while n:
//         m.append(n%10)
//         n//=10
//     l = mul_list(l,m)

// s = 0
// for i in l:
//     s+=i
// print(s)
