// BIGNUM BIGNUM
// Collaborators:      Justin Andre Po
//                     Gabriel John Manzanares
//                     Oscar Vian Valles
//                     Seth Nemeño
#include <stdio.h>
int main() {
    int sum, i, j, k, n = 0, size = 1000, digits = 1, mod = 1;
    int arrA[size], arrB[size], arrC[size];
    char suffix[2] = "th";

    for (i = 0; i < size; i++)
        arrA[i] = arrB[i] = arrC[i] = 0;  // initialize the arrays

    arrB[size - 1] = 1;  // initialization for the fibonacci sequence

    do {
        if (n < 0) printf("Please enter a non-negative number.\n");
        printf("Enter a number as n to find the nths Fibonaccin Number.\n");
        scanf("%i", &n);
    } while (n < 0);  // checks for negative input

    if (n != 2) {
        n--;
        mod = 0;
    }

    for (i = 1; i < n; i++) {
        for (k = size - 1; k >= 0; k--) arrC[k] = 0;  // resets the third array
        // add values of the arrays
        for (j = size - 1; j >= size - digits - 1; j--) {
            sum = arrA[j] + arrB[j];
            // checks for possible carry
            if (sum < 10)
                arrC[j] = sum;
            else {
                arrC[j] = sum % 10;
                arrA[j - 1] += sum / 10;
                if ((j == size - digits))
                    digits++;  // counts the number of digits
            }
        }
        // swap values of arrays
        for (j = size - 1; j >= 0; j--) {
            arrA[j] = arrB[j];
            arrB[j] = arrC[j];
        }
    }
    // suffix
    n++;
    if (mod){
        n = 2;
    }
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
        }
    }
    // printing
    printf("The %i%s element in the Fibonacci Sequence ", n, suffix);
    if (digits > 1000)
        printf("will not fit in a 1000-digit array.\n");
    else {
        printf("is: ");
        for (i = size - digits; i < size; i++) printf("%i", arrC[i]);
    }
    printf("\n");
}