/*  BIGNUMBIGNUM >>> PRINTING THE 1000th FIBONACCI NUMBER USING ARRAYS
*   COLLABORATORS:  
*
*
*/
#include<stdio.h>

int main()
{
    int i, j, sum, index;
    int size = 1000, n = 1000;
    int arrA[size], arrB[size], arrC[size];

    // initializing arrays
    for(i = 0; i < size; i++)
    {
        /* code */
        arrA[i] = arrB[i] = arrC[i] = 0;
    }

    // initial value for the fibonacci sequence
    arrB[size-1] = 1;

    // loop for the nth fibonacci
    for(i = 1; i < n; i++)
    {
        /* code */
        // reset third array
        arrC[i] = 0;

        // loop for the addition
        for(j = size-1; j >= 0; j--)
        {
            /* code */
            sum = arrA[j] + arrB[j];
            // checks for possible carry
            if (sum < 10) {
                /* code */
                arrC[j] = sum;
            }
            else {
                /* code */
                // getting the least sig digit
                arrC[j] = sum % 10;
                // getting the carry
                arrA[j-1] += sum / 10;
            }
        }

        // lastUsedC = j;

        // loop for the swap
        for(j = size-1; j >= 0; j--)
        {
            /* code */
            // a = b
            arrA[j] = arrB[j];
            // b = c
            arrB[j] = arrC[j];
        }
    }
    
    // printing
    // for(i = 0; i < size; i++)
    // {
    //     /* code */
    //     // checks for trailing 6 zeroes
    //     if (arrA[i] == 0 && arrA[i+1] == 0 && arrA[i+2] == 0 && arrA[i+3] == 0 && arrA[i+4] == 0 && arrA[i+5])
    //         index = i + 5;
    //     // printf("%i", arrA[i]);
    // }

    printf("The %i fibonacci number is: ", n);

    // print
    for(i = 0; i < size; i++)
    {
        /* code */
        printf("%i", arrA[i]);
    }
    
    printf("\n");
}