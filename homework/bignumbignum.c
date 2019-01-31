#include <stdio.h>

int main() {
    int a = 0, b = 1, c, i, n = 10;
    int arr1[1000], arr2[1000], arr3[1000];

    for (i = 0; i < 1000; i++) {
        arr1[i] = 0;
        arr2[i] = 0;
        arr3[i] = 0;
    }

    for(i=0; i<n; i++){
        c = a + b;
        a = b;
        b = c;
    }

    printf("The %ith element of the fibonacci sequence is: %i\n", n, c);
}