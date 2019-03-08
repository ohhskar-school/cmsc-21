#include <stdio.h>

void display(int[100][100], int, int);
void label(int image[100][100], int, int, int, int, int);

int main() {
    int testCasesNumber = 1, testCaseType = 1, i, j, k, cols, rows, holder;
    holder = rows = cols = k = j = i = 0;
    int image[100][100];

    do {
        scanf("%i", &testCasesNumber);
    } while (testCasesNumber < 0);

    for (i = 0; i < testCasesNumber; i++) {
        scanf("%i", &rows);
        scanf("%i", &cols);
        if (rows < 1 || cols < 1) {
            printf("INVALID INPUT");
        } else {
            for (j = 0; j < rows; j++) {
                for (k = 0; k < cols; k++) {
                    scanf("%i", &holder);
                    image[j][k] = holder;
                }
            }
            label(image, rows, cols, 0, 0, 1);
            display(image, rows, cols);
        }
    }

    return 0;
}

void label(int image[100][100], int rows, int cols, int i, int j,
           int labelNum) {
    int breakIf = 0;

    if (image[i][j] == 1) {
        if (i - 1 >= 0) {
            if (!breakIf && j - 1 >= 0 && image[i - 1][j - 1] > 1) {
                image[i][j] = image[i - 1][j - 1];
                breakIf = 1;
            }
            if (!breakIf && image[i - 1][j] > 1) {
                image[i][j] = image[i - 1][j];
                breakIf = 1;
            }
            if (!breakIf && j + 1 < cols && image[i - 1][j + 1] > 1) {
                image[i][j] = image[i - 1][j + 1];
                breakIf = 1;
            }
        }
        if (!breakIf && j - 1 >= 0 && image[i][j - 1] > 1) {
            image[i][j] = image[i][j - 1];
            breakIf = 1;
        }
        if (!breakIf) {
            image[i][j] = ++labelNum;
        }
    }

    if (j == cols - 1) {
        if (i + 1 < rows) {
            return label(image, rows, cols, i + 1, 0, labelNum);
        } else {
            return;
        }
    } else {
        return label(image, rows, cols, i, ++j, labelNum);
    }
}
void display(int image[100][100], int rows, int cols) {
    int j, k;
    for (j = 0; j < rows; j++) {
        for (k = 0; k < cols; k++) {
            printf("%i ", image[j][k]);
        }
        printf("\n");
    }
}