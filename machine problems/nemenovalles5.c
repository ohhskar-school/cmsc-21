#include <stdio.h>

int division(int, int);
int primeornot(int, int);
int binarysearch(int, int[], int, int);
int positiveCheck(int, int);
int main() {
    int testCasesNumber = 1, testCaseType = 1;
    do {
        if (testCasesNumber < 0) {
            printf("You have entered an invalid input");
        }
        printf("\nEnter the number of test cases you want to test\n");
        scanf("%i", &testCasesNumber);
    } while (testCasesNumber < 0);

    for (int i = 0; i < testCasesNumber; i++) {
        int a = 1, b = 1, quotient = 0, n, m, k, l;

        printf(
            "Enter the type of output that you want\n"
            "[1]Division\n"
            "[2]Relatively Prime or not\n"
            "[3]Binary Search\n");
        scanf("%i", &testCaseType);

        if (testCaseType < 1 || testCaseType > 3) {
            printf("INVALID");
            break;
        }

        if (testCaseType == 1) {
            printf("\nEnter the Dividend\n");
            scanf("%i", &a);

            printf("\nEnter the Divisor\n");
            scanf("%i", &b);

            if (positiveCheck(a, b)) {
                printf("The quotient is %i\n", division(a, b));
            } else {
                printf("INVALID");
            }
        }
        if (testCaseType == 2) {
            printf("\nEnter the first number\n");
            scanf("%i", &n);
            printf("\nEnter the second number\n");
            scanf("%i", &m);

            if (positiveCheck(n, m)) {
                if (primeornot(n, m))
                    printf("RELATIVELY PRIME\n");
                else
                    printf("NOT RELATIVELY PRIME\n");
            } else {
                printf("INVALID\n");
            }
        }
        if (testCaseType == 3) {
            printf("\nEnter the number of arrays\n");
            scanf("%i", &k);
            printf("\n");
            int array[k];
            for (int m = 0; m < k; m++) {
                scanf("%i", &array[m]);
            }
            printf("\nEnter the number to be searched\n");
            scanf("%i", &l);
            printf("\n");
            if (k < 2 || k > 20) {
                printf("INVALID\n");
            } else {
                if (binarysearch(l, array, 0, k - 1))
                    printf("%i IS IN THE SET\n", l);
                else
                    printf("%i IS NOT IN THE SET\n", l);
            }
        }
    }

    return 0;
}
int division(int a, int b) {
    int n = 0;
    if (a < b)
        return n;
    else
        return ++n + division(a - b, b);
}
int primeornot(int n, int m) {
    if (n % m == 0) {
        if (m == 1) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return primeornot(m, n % m);
    }
}
int binarysearch(int j, int array[], int lb, int ub) {
    int mid = (lb + ub) / 2;
    if (array[mid] == j) {
        return 1;
    } else if (ub == lb || ub < lb) {
        return 0;
    } else {
        if (array[mid] < j)
            return binarysearch(j, array, mid + 1, ub);
        else
            return binarysearch(j, array, lb, mid - 1);
    }
};

int positiveCheck(int a, int b) {
    if (a < 1 || b < 1) {
        return 0;
    } else {
        return 1;
    }
}