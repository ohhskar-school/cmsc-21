#include <stdio.h>
#include <string.h>

void intToWord(int);
char helperIntToRoman(int);
int helperRomanToInt(char);

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
            case 1: {
                int input;
                printf("Enter the Integer to be converted to words: ");
                scanf("%i", &input);
                intToWord(input);
            }
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

    if(input < 0){
        printf("Negative ");
        input *= -1;
    }

    if (input == 0){
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
            }
            else if (holder > 0) {
                printf("%s ", ones[holder % 10]);
            }
            printf("%s ", suffix[i]);

            input %= divisors[i] ? divisors[i]: 1;
        }
    }
    printf("\n");
}


int helperRomanToInt(char roman) {
    switch (roman) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return -1;
    }
}

char helperIntToRoman(int num) {
    switch (num) {
        case 1:
            return 'I';
        case 5:
            return 'V';
        case 10:
            return 'X';
        case 50:
            return 'L';
        case 100:
            return 'C';
        case 500:
            return 'D';
        case 1000:
            return 'M';
        default:
            return '!';
            break;
    }
}