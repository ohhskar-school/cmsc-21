#include <stdio.h>

int main() {
    int a = 0, b = 1, c, n = 10, arraySize = 20;
    int arrayA[arraySize], arrayB[arraySize], arrayC[arraySize];
    int index[4] = {0, 0, 0, 0}, indexLimit = 0, end = 0;
    int sum = 0, carry = 0;
    int initNumber = 123;

    // Initializing Numbers
    for (int i = 0; i < arraySize; i++) {
        arrayA[i] = 0;
        arrayB[i] = 0;
        arrayC[i] = 0;
    }

    // Adding numbers to the array
    index[0] = arraySize - 1;
    while (initNumber != 0) {
        arrayA[index[0]--] = initNumber % 10;
        initNumber /= 10;
    }

    initNumber = 1234;
    index[1] = arraySize - 1;
    while (initNumber != 0) {
        arrayB[index[1]--] = initNumber % 10;
        initNumber /= 10;
    }

    if (index[0] < index[1]) {
        indexLimit = index[0];
    } else {
        indexLimit = index[1];
    }

    for (int i = 0; i < n; i++) {
        // Reset arrayC

        /*----------------------*
         *       c = a + b      *
         * ---------------------*/

        for (int i = 0; i < arraySize; i++) {
            arrayC[i] = 0;
        }

        // Reset Index
        index[2] = arraySize - 1;
        index[3] = arraySize - 1;

        do {
            // Sums the two index,
            sum = arrayA[index[2]] + arrayB[index[2]];
            index[2]--;

            while (sum != 0) {
                if (sum > 10) {
                    carry = 1;
                }
                arrayC[index[3]--] += sum % 10;
                sum /= 10;
            }

            if (carry) {
                index[3]++;
                carry = 0;
            }

            if (index[2] == indexLimit) {
                end = 1;
            }
        } while (!end);

        /*----------------------*
         *         a = b        *
         * ---------------------*/

        // Reset Index & copy arrayB
        for (int i = 0; i < arraySize; i++) {
            arrayA[i] = arrayB[i];
        }

        /*----------------------*
         *         b = c        *
         * ---------------------*/

        // Reset Index & copy arrayB
        for (int i = 0; i < arraySize; i++) {
            arrayB[i] = arrayC[i];
        }
    }

    for (int x = 0; x < arraySize; x++) {
        printf("%i", arrayA[x]);
    }
    printf("\n");

    for (int x = 0; x < arraySize; x++) {
        printf("%i", arrayB[x]);
    }
    printf("\n");

    for (int x = 0; x < arraySize; x++) {
        printf("%i", arrayC[x]);
    }
    printf("\n");
}