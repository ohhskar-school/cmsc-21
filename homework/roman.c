#include <stdio.h>
#include <string.h>

void intToWord(int);
void intToRoman(int);
int romanToInt(char[]);
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
                if (input < 1 || input > 3000) {
                    printf("INVALID\n");
                } else {
                    intToRoman(input);
                }
                break;
            case 3:
                printf("Enter the Roman Numeral to be converted to an int: ");
                scanf("%s", &inputString);
                if (romanToIntChecker(inputString) || romanToInt(inputString)) {
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
    int tensFlag = input > 100 ? 0 : 1;

    // Adds a negative prefix if the number is negative
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
            // Divides input by the divisor if it is not zero
            holder = divisors[i] ? input / divisors[i] : input;

            // Prints the Hundreds digit
            if (holder >= 100) {
                printf("%s Hundred ", ones[holder / 100]);
                holder %= 100;
            }

            // Prints the tens and ones digit
            if (holder >= 10) {
                // Checks if the last digit is not zero
                if (holder % 10 != 0) {
                    // Adds a dash if the input is greater than 100, adds a
                    // space if it is not. this is done through the tensFlag
                    // identifier
                    printf("%s%c%s ", tens[holder / 10], (tensFlag ? ' ' : '-'),
                           ones[holder % 10]);
                } else {
                    printf("%s ", tens[holder / 10]);
                }
                holder %= 10;
            }
            // Handles the printing of the one digit numbers if the tens digit
            // is 0
            else if (holder > 0) {
                printf("%s ", ones[holder % 10]);
            }

            // Prints the suffix
            printf("%s ", suffix[i]);

            // Removes the digits that have already been converted to words
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
        // Prints while the input is still greater than the current value found
        // in the map
        while (input >= intMap[i]) {
            // Prints the corresponding value found in the roman map
            printf("%s", romanMap[i]);
            // Subtracts the used value.
            input -= intMap[i];
        }
    }
    printf("\n");
}

int romanToInt(char input[]) {
    int sum = 0;
    int currentNumber = 0;
    int lastNumber = 5000;

    for (int i = 0; input[i] != 0; i++) {
        // getsthe current value based on the value from the map. A switch was
        // used here as having an array would cost too much memory if it would
        // be mapped like this. as intMap('V') would take 86 * 4bytes to
        // allocate.
        currentNumber = romanToIntMap(input[i]);
        sum += currentNumber;

        // If the two numbers are less than the next number, then that
        // must mean there is an error in the input.
        if (lastNumber + currentNumber < romanToIntMap(input[i + 1])) {
            return 1;
        }

        // If the last number was less than the current number then that must
        // mean subtraction must take place
        if (lastNumber < currentNumber) {
            if (
                // Checks if the lastNumber is I, X, or C. If it is not then
                // that is an error as only these numbers can be used to
                // subtract.
                (lastNumber != 1 && lastNumber != 10 && lastNumber != 100) ||

                // If the lastNumber is I, checks if the current number is X or
                // V, which is the only allowable character combination
                (lastNumber == 1 &&
                 (currentNumber != 10 && currentNumber != 5)) ||

                // If the lastNumber is X, checks if the current number is C or
                // L, which is the only allowable character combination
                (lastNumber == 10 &&
                 (currentNumber != 100 && currentNumber != 50)) ||

                // If the lastNumber is C, checks if the current number is M or
                // D, which is the only allowable character combination
                (lastNumber == 100 &&
                 (currentNumber != 1000 && currentNumber != 500))) {
                return 1;
            }

            // If it passes through the checks, subtracts the last number from
            // the sum twice as this number was added to the sum from the last
            // iteration.
            sum -= lastNumber * 2;
        }
        lastNumber = currentNumber;
    }
    printf("%i\n", sum);
    return 0;
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
    int intMap[] = {1000, 500, 100, 50, 10, 5, 1};

    char nonRepeating[] = {'D', 'L', 'V'};
    int error, j = error = 1;
    int inputLen = strlen(input);
    for (int i = 0; input[i] != 0; i++) {
        // Checks for inputs that are not uppercase or part of the roman
        // numerals
        error = 1;
        for (j = 0; j < 7; j++) {
            if (input[i] == romanMap[j]) {
                error = 0;
                break;
            }
        }
        if (error) {
            return 1;
        }

        // Checks if any non-repeating roman numerals are repeated
        for (j = 0; j < 3; j++) {
            if (input[i] == nonRepeating[j]) {
                if (i + 1 < inputLen) {
                    if (input[i] == input[i + 1]) {
                        return 1;
                    }
                }
            }
        }

        // Checks if there are 4 repeating digits
        if (i + 3 < inputLen) {
            for (j = 0; j < 4; j++) {
                if (input[i] != input[i + j]) {
                    break;
                }
            }
        }
        if (j == 4) {
            return 1;
        }
    }

    return 0;
}