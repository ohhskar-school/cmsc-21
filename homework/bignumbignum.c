/*  BIGNUMBIGNUM >>> PRINTING THE 1000th FIBONACCI NUMBER USING ARRAYS
 *   COLLABORATORS:
 *
 *
 */
#include <stdio.h>

int main() {
    int i, j, sum;
    int size = 1000, n = 1000;
    int arrA[size], arrB[size], arrC[size];
    int indexA, indexB, indexC = indexB = indexA = 0;
    int lastUsedA, lastUsedB, lastUsedC = lastUsedB = lastUsedA = 0;
    int digits = 1;

    // initializing arrays
    for (i = 0; i < size; i++) {
        arrA[i] = arrB[i] = arrC[i] = 0;
    }

    // initial value for the fibonacci sequence
    arrA[size - 1] = 0;
    arrB[size - 1] = 1;
    lastUsedA = size - 2;
    lastUsedB = size - 2;

    // loop for the nth fibonacci
    for (i = 1; i < n; i++) {
        // reset third array
        for (int i = size - 1; i >= 0; i--) {
            arrC[i] = 0;
        }

        // loop for the addition
        for (j = size - 1; j >= size - digits - 1; j--) {
            sum = arrA[j] + arrB[j];
            // checks for possible carry
            if (sum > 10) {
                arrA[j - 1] += sum / 10;
                sum %= 10;
                if (j == size - digits) {
                    digits++;
                }
            }
            arrC[j] = sum;
        }
        
        // loop for the swap
        for (j = size - 1; j >= size - digits - 1; j--) {
            // a = b
            arrA[j] = arrB[j];
            // b = c
            arrB[j] = arrC[j];
        }
    }

    printf("The %i fibonacci number is: ", n);

    // print
    for (i = size - digits; i < size ; i++) {
        printf("%i", arrA[i]);
    }

    printf("\n");
}