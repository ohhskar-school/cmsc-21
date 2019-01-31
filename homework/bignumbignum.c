#include <stdio.h>

int main() {
    int a = 0, b = 1, c, n = 10, arraySize = 20, carry = 0, initNumber = 0;
    int arrayA[arraySize], arrayB[arraySize], arrayC[arraySize];
    int index = 0;

    do {
        scanf("%i", &initNumber);
    } while (initNumber < 0 && initNumber > 1000);

    for (int i = 0; i < arraySize; i++) {
        arrayA[i] = 0;
        arrayB[i] = 0;
        arrayC[i] = 0;
    }

    index = arraySize - 1;
    while(initNumber != 0){
        arrayA[index--] = initNumber % 10;
        initNumber /= 10;
    }

    for (int x = 0; x < arraySize; x++) {
        printf("%i", arrayA[x]);
    }
    printf("\n");

    // for (int i = 0; i < n; i++) {
    //     c = a + b;
    //     a = b;
    //     b = c;
    // }
}