#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int coefficient;
    int exponent;
} term;

term delimit(char[]);
void display(term);
term multiply(term, term);
void init(term *, int);

int main() {
    int testCasesNumber = 1;
    char str[2][1000];
    term terms[2];

    do {
        scanf("%i", &testCasesNumber);
    } while (testCasesNumber < 0);

    for (int i = 0; i < testCasesNumber; i++) {
        // Gets the input
        for (int j = 0; j < 2; j++) {
            scanf("%s", &str[j]);
            terms[j] = delimit(str[j]);
        }
        display(multiply(terms[0], terms[1]));
    }
}

term delimit(char str[]) {
    int i, ex = 0, convertedCoef = 0, convertedExp = 0;
    int len = strlen(str);
    term delimited;

    // initializes both values of delimited to 1
    init(&delimited, 1);

    for (i = 0; i < len; i++) {
        // Sets a flag if x is found
        if (str[i] == 'x') {
            ex = 1;
        }

        // converts the values to the coefficient if ex is not yet found.
        if (!convertedCoef && !ex) {
            delimited.coefficient = atoi(&str[i]);
            convertedCoef = 1;
        }

        // converts the value if ex is found and if the last characters are not
        // x or ^. This takes care of inputs like 20x.
        if (ex && !convertedExp && str[len - 1] != '^' && str[len - 1] != 'x') {
            delimited.exponent = atoi(&str[i + 2]);
            convertedExp = 1;
        }
    }

    // If x is not in the string, sets the exponent to 0
    if (!ex) {
        delimited.exponent = 0;
    }

    return delimited;
}
term multiply(term first, term second) {
    term product;

    // Initializes the product coefficient and exponent to 0
    init(&product, 0);

    // Calculates the values of the products
    product.coefficient = first.coefficient * second.coefficient;
    product.exponent = first.exponent + second.exponent;

    return product;
}

void init(term *t, int initValue) {
    // Initializes the values depending on the passed initValue argument
    t->coefficient = initValue;
    t->exponent = initValue;
}
void display(term t) {
    // if the coefficient is 0, do not show the x
    if (t.exponent == 0) {
        printf("%i\n", t.coefficient);
    }

    // if exponent is one do not show the exponent
    else if (t.exponent == 1) {
        // if coefficient is one do not show the coefficient
        if (t.coefficient != 1) {
            printf("%ix\n", t.coefficient);
        } else {
            printf("x\n");
        }
    }

    // if coefficient is one do not show the coefficient
    else if (t.coefficient == 1) {
        printf("x^%i\n", t.exponent);
    } else {
        printf("%ix^%i\n", t.coefficient, t.exponent);
    }
}