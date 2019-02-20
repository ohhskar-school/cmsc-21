#include <stdio.h>
#include <string.h>

void intToWord(int);
void intToRoman(int);
void romanToInt(char[]);
int romanToIntMap(char);
int romanToIntChecker(char[]);

int main() {
    int testCasesNumber = 1, i = 0;

    do {
        if (testCasesNumber < 1) {
            printf("You have entered a number less than 1");
        }
        printf("Enter the number of test cases: ");
        scanf("%i", &testCasesNumber);
    } while (testCasesNumber < 1);
    for (i = 0; i < testCasesNumber; i++) {
        int choice = 1;
        int input = 0;
        char inputString[15];
        do {
            if (choice < 1 || choice > 3) {
                printf("Please select a number between 1 and 3\n");
            }
            printf(
                "Select the type of conversion\n"
                "[1] Integer to Words\n"
                "[2] Integer to Roman\n"
                "[3] Roman to Integer\n");
            scanf("%i", &choice);
        } while (choice < 1 || choice > 3);

        switch (choice) {
            case 1:
                printf("Enter the Integer to be converted to words: ");
                scanf("%i", &input);
                intToWord(input);
                break;
            case 2:
                printf("Enter the Integer to be converted to Roman Numerals: ");
                scanf("%i", &input);
                if (input >= 1 || input <= 3000) {
                    intToRoman(input);
                } else {
                    printf("INVALID\n");
                }
                break;
            case 3:
                printf("Enter the Roman Numeral to be converted to an int: ");
                scanf("%s", &inputString);
                if (!romanToIntChecker(inputString)) {
                    romanToInt(inputString);
                } else {
                    printf("INVALID\n");
                }
                break;
            default:
                printf("How did you get here?");
                return 1;
        }
    }

    return 0;
}

void intToWord(int input) {
    char ones[][6] = {"",     "One", "Two",   "Three", "Four",
                      "Five", "Six", "Seven", "Eight", "Nine"};
    char teens[][10] = {
        "",        "Eleven",  "Twelve",    "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen",
    };
    char tens[][8] = {
        "",      "Ten",   "Twenty",  "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety",
    };
    char suffix[][9] = {"", "Thousand", "Million", "Billion"};
    int divisors[] = {0, 1000, 1000000, 1000000000};
    int holder = 0;

    if (input < 0) {
        printf("Negative ");
        input *= -1;
    }

    if (input == 0) {
        printf("Zero\n");
        return;
    }

    for (int i = 3; i >= 0; i--) {
        if (input >= divisors[i]) {
            holder = divisors[i] ? input / divisors[i] : input;

            if (holder >= 100) {
                printf("%s Hundred ", ones[holder / 100]);
                holder %= 100;
            }

            if (holder >= 10) {
                if (holder % 10 != 0) {
                    printf("%s-%s ", tens[holder / 10], ones[holder % 10]);
                } else {
                    printf("%s ", tens[holder / 10]);
                }
                holder %= 10;
            } else if (holder > 0) {
                printf("%s ", ones[holder % 10]);
            }
            printf("%s ", suffix[i]);

            input %= divisors[i] ? divisors[i] : 1;
        }
    }
    printf("\n");
}

void intToRoman(int input) {
    int intMap[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char romanMap[][3] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                          "XL", "X",  "IX", "V",  "IV", "I"};
    for (int i = 0; input != 0; i++) {
        while (input >= intMap[i]) {
            printf("%s", romanMap[i]);
            input -= intMap[i];
        }
    }
    printf("\n");
}

void romanToInt(char input[]) {
    int sum = 0;
    int currentNumber = 0;
    int lastNumber = 5000;

    for (int i = 0; input[i] != 0; i++) {
        currentNumber = romanToIntMap(input[i]);
        sum += currentNumber;
        if (lastNumber < currentNumber) {
            sum -= lastNumber * 2;
        }
        lastNumber = currentNumber;
    }
    printf("%i\n", sum);
}

int romanToIntMap(char roman) {
    switch (roman) {
        case 'M':
            return 1000;
        case 'D':
            return 500;
        case 'C':
            return 100;
        case 'L':
            return 50;
        case 'X':
            return 10;
        case 'V':
            return 5;
        case 'I':
            return 1;
    }
}

int romanToIntChecker(char input[]) {
    char romanMap[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    int error = 1;
    prevRepeat = 0;
    for (int i = 0; input[i] != 0; i++) {
        error = 1;
        for (int j = 0; j < 7; j++) {
            if (input[i] == romanMap[j]) {
                error = 0;
                break;
            }
        }

        if (error) {
            return 1;
        }
    }

    return 0;
}