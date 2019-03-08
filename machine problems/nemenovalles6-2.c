#include <stdio.h>

void display(int[100][100], int, int);
int label(int[100][100], int, int, int, int, int, int);
int labelExplode(int[100][100], int, int, int, int, int);
int main() {
    int testCasesNumber = 1, testCaseType = 1, i, j, k, cols, rows, holder,
        output;
    output = holder = rows = cols = k = j = i = 0;
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
            output = label(image, rows, cols, 0, 0, 2, 0);
            if (output == 1) {
                printf("%i Object Found\n", output);

            } else {
                printf("%i Objects Found\n", output);
            }
        }
    }

    return 0;
}

int label(int image[100][100], int rows, int cols, int i, int j, int labelNum,
          int count) {
    if (image[i][j] == 1) {
        count += labelExplode(image, rows, cols, i, j, labelNum);
        labelNum++;
    }

    if (j == cols - 1) {
        if (i + 1 < rows) {
            return label(image, rows, cols, i + 1, 0, labelNum, count);
        } else {
            return count;
        }
    } else {
        return label(image, rows, cols, i, ++j, labelNum, count);
    }
}

int labelExplode(int image[100][100], int rows, int cols, int i, int j,
                 int labelNum) {
    image[i][j] = labelNum;

    if (j - 1 >= 0 && image[i][j - 1] == 1) {
        labelExplode(image, rows, cols, i, j - 1, labelNum);
    }
    if (j + 1 < cols && image[i][j + 1] == 1) {
        labelExplode(image, rows, cols, i, j + 1, labelNum);
    }
    if (i + 1 < rows) {
        if (j - 1 >= 0 && image[i + 1][j - 1] == 1) {
            labelExplode(image, rows, cols, i + 1, j - 1, labelNum);
        }
        if (image[i + 1][j] == 1) {
            labelExplode(image, rows, cols, i + 1, j, labelNum);
        }
        if (j + 1 < cols && image[i + 1][j + 1] == 1) {
            labelExplode(image, rows, cols, i + 1, j + 1, labelNum);
        }
    }

    return 1;
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