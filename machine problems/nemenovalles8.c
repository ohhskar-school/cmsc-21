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
        for (int j = 0; j < 2; j++) {
            scanf("%s", &str[j]);
            terms[j] = delimit(str[j]);
        }
        display(multiply(terms[0], terms[1]));
    }
}

// 5x^3;

// term.coefficient = 5
// term.exponent = 3

term delimit(char str[]) {
    int i, ex = 0, convertedCoef = 0, convertedExp = 0;
    int len = strlen(str);
    term delimited;
    init(&delimited, 1);

    for (i = 0; i < len; i++) {
        if (str[i] == 'x') {
            ex = 1;
        }

        if (!convertedCoef && !ex) {
            delimited.coefficient = atoi(&str[i]);
            convertedCoef = 1;
        }
        if (ex && !convertedExp && str[len - 1] != '^' && str[len - 1] != 'x') {
            delimited.exponent = atoi(&str[i + 2]);
            convertedExp = 1;
        }
    }

    if (!ex) {
        delimited.exponent = 0;
    }

    return delimited;
}
term multiply(term first, term second) {
    term product;
    init(&product, 0);

    product.coefficient = first.coefficient * second.coefficient;
    product.exponent = first.exponent + second.exponent;

    return product;
}

void init(term *t, int initValue) {
    t->coefficient = initValue;
    t->exponent = initValue;
}
void display(term t) {
    if (t.exponent == 0) {
        printf("%i\n", t.coefficient);
    } else if (t.coefficient == 1) {
        printf("x^%i\n", t.exponent);
    } else {
        printf("%ix^%i\n", t.coefficient, t.exponent);
    }
}