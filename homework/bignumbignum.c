/*  BIGNUMBIGNUM >>> PRINTING THE 1000th FIBONACCI NUMBER USING ARRAYS
 *   COLLABORATORS:
 *
 *
 */
#include <stdio.h>

int main() {
    int i, j, sum;
    int size = 1000, n = 0;
    int arrA[size], arrB[size], arrC[size];
    int digits = 1;
    int notFit = 0;

    // initializing arrays
    for (i = 0; i < size; i++) {
        arrA[i] = arrB[i] = arrC[i] = 0;
    }

    // initial value for the fibonacci sequence
    arrA[size - 1] = 0;
    arrB[size - 1] = 1;

    do {
        if (n < 0) {
            printf("Please enter a non-negative number\n");
        }
        printf("Enter a number as n to find the nths Fibonacci Number\n");
        scanf("%i", &n);
    } while (n < 0);

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
            if (sum < 10) {
                arrC[j] = sum;
            } else {
                arrC[j] = sum % 10;
                arrA[j - 1] += sum / 10;
                if (j == size - digits) {
                    digits++;
                }
            }
        }

        // loop for the swap
        for (j = size - 1; j >= 0; j--) {
            // a = b
            arrA[j] = arrB[j];
            // b = c
            arrB[j] = arrC[j];
        }
    }

    char suffix[2] = "th";
    if (!(n % 100 > 10 && n % 100 < 20)) {
        switch (n % 10) {
            case 1:
                suffix[0] = 's';
                suffix[1] = 't';
                break;

            case 2:
                suffix[0] = 'n';
                suffix[1] = 'd';
                break;

            case 3:
                suffix[0] = 'r';
                suffix[1] = 'd';
                break;

            default:
                break;
        }
    }

    // print
    if (digits > 1000) {
        printf(
            "The %i%s element in the Fibonacci Sequence will not fit in a 1000 "
            "digit array\n",
            n, suffix);
    } else {
        printf("The %i%s element in the Fibonacci Sequence is: ", n, suffix);

        for (i = size - digits; i < size; i++) {
            printf("%i", arrC[i]);
        }
    }

    printf("\n");
}