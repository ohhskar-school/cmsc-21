#include <stdio.h>
#include <string.h>

// function to convert a decimal number (a number in base 10 to any base)
// the first argument is the number in base 10, and the the second argument is
// the desired base
int decimal(unsigned int, int);
// the two succeeding functions accept the numbers in string format with the int
// as the base
void addition(char[], char[], int);
// subtract the second argument from the first with the int as the base
void subtraction(char[], char[], int);

int main() {
    int decError = 0, choice = 1, base = 2, decAnswer, error,
        differenceError = error = decAnswer = 0;
    int leave = 0;
    unsigned int dec = 0;
    char decHolder[200], first[200], second[200];

    do {
        do {
            if (choice < 1 || choice > 3) {
                printf("\nYou have entered an incorrect input\n");
            }
            printf(
                "\nSelect from the functions presented below to you wish to "
                "execute\n");

            printf(
                "1. Decimal to Other Bases\n"
                "2. Arithmetic\n"
                "3. Exit\n");

            scanf("%i", &choice);
        } while (choice < 1 || choice > 3);

        switch (choice) {
            case 1:
                // NEEDS ERROR CHECKING
                // do {
                //     switch (decError) {
                //         case 1:
                //             printf(
                //                 "You have entered a value that is greater
                //                 than an " "unsigned int\n");
                //             break;
                //         case 2:
                //             printf("You have entered a negative value\n");
                //             break;
                //         default:
                //             break;
                //     }
                //     decError = 0;

                //     printf(
                //         "\nEnter a positive integer in decimal that you want
                //         to " "convert: ");
                // print the sum on the console
                //     scanf("%s", &decHolder);

                // 	decLen = strlen(decHolder);
                //     if (decLen >= 11) {
                //         decError = 1;
                //     }

                // } while (decError > 0);
                // dec = decHolder;

                printf(
                    "\nEnter a positive integer in decimal that you want to "
                    "convert: ");
                scanf("%u", &dec);

                do {
                    if (base < 2 || base > 9) {
                        printf(
                            "You have entered a base that is not within the "
                            "specified range\n");
                    }
                    printf(
                        "\nEnter the base between 2 - 9 you want to convert it "
                        "into: ");
                    scanf("%i", &base);
                } while (base < 2 || base > 9);

                decAnswer = decimal(dec, base);
                if (decAnswer < 0) {
                    printf(
                        "\nThe value entered cannot be represented in an "
                        "int\n");
                } else {
                    printf("\n%u in base %i is %i\n", dec, base, decAnswer);
                }
                break;

            case 2:
                do {
                    if (base < 2 || base > 30) {
                        printf(
                            "You have entered a base that is not within the "
                            "specified range\n");
                    }
                    printf(
                        "\nEnter a base between 2 - 30 that you want to work "
                        "with\n");
                    scanf("%i", &base);
                } while (base < 2 || base > 30);

                do {
                    if (differenceError) {
                        printf(
                            "\nThe second value is greater than the first "
                            "value\n");
                    }

                    // Gets the First Input
                    do {
                        switch (error) {
                            case 1:
                                printf("\nYou have entered a negative value\n");
                                break;
                            case 2:
                                printf(
                                    "\nYou have entered characters that are "
                                    "not Uppercase or Numbers\n");
                                break;
                            case 3:
                                printf(
                                    "\nYou have entered a character that is "
                                    "greater than the allowed characters in "
                                    "the selected base\n");
                                break;
                            default:
                                break;
                        }

                        printf(
                            "\nEnter a positive integer in the base that you "
                            "have selected\n");
                        scanf("%s", first);

                        error = 0;
                        for (int i = 0; i < strlen(first); i++) {
                            if (first[i] == '-') {
                                error = 1;
                                break;
                            }

                            if (!((first[i] >= 'A' && first[i] <= 'Z') ||
                                  (first[i] >= '0' && first[i] <= '9'))) {
                                error = 2;
                                break;
                            }

                            if (((first[i] >= 'A' && first[i] <= 'Z') &&
                                 (first[i] >= base + 'A' - 10)) ||
                                ((first[i] >= '0' && first[i] <= '9') &&
                                 (first[i] >= base + '0'))) {
                                error = 3;
                                break;
                            }
                        }

                    } while (error > 0);

                    // Gets the second input
                    do {
                        switch (error) {
                            case 1:
                                printf("\nYou have entered a negative value\n");
                                break;
                            case 2:
                                printf(
                                    "\nYou have entered characters that are "
                                    "not Uppercase or Numbers\n");
                                break;
                            case 3:
                                printf(
                                    "\nYou have entered a character that is "
                                    "greater than the allowed characters in "
                                    "the selected base\n");
                                break;
                            default:
                                break;
                        }

                        printf(
                            "\nEnter a positive integer in the same base as "
                            "the first one\n");
                        scanf("%s", second);

                        error = 0;
                        for (int i = 0; i < strlen(second); i++) {
                            if (second[i] == '-') {
                                error = 1;
                                break;
                            }

                            if (!((second[i] >= 'A' && second[i] <= 'Z') ||
                                  (second[i] >= '0' && second[i] <= '9'))) {
                                error = 2;
                                break;
                            }

                            if (((second[i] >= 'A' && second[i] <= 'Z') &&
                                 (second[i] >= base + 'A' - 10)) ||
                                ((second[i] >= '0' && second[i] <= '9') &&
                                 (second[i] >= base + '0'))) {
                                error = 3;
                                break;
                            }
                        }

                    } while (error > 0);

                    differenceError = 0;
                    if (strlen(first) < strlen(second)) {
                        differenceError = 1;
                    }

                    if (strlen(first) == strlen(second)) {
                        for (int i = 0; i < strlen(first); i++) {
                            if (first[i] > second[i]) {
                                break;
                            }
                            if (first[i] < second[i]) {
                                differenceError = 1;
                                break;
                            }
                        }
                    }
                } while (differenceError);

                do {
                    if (choice < 1 || choice > 2) {
                        printf("\nYou have entered an incorrect input\n");
                    }
                    printf("\nDo you want to add or subtract these numbers?\n");

                    printf(
                        "1. Addition\n"
                        "2. Subtraction\n");

                    scanf("%i", &choice);
                } while (choice < 1 || choice > 3);

                switch (choice) {
                    case 1:
                        addition(first, second, base);
                        break;
                    case 2:
                        subtraction(first, second, base);
                        break;
                    default:
                        printf("How did you get here?");
                        leave = 1;
                        break;
                }
                break;

            case 3:
                printf("Goodbye!\n");
                leave = 1;
                break;
            default:
                printf("How did you get here?");
                leave = 1;
                break;
        }
    } while (!leave);
    return 0;
}

int decimal(unsigned int dec, int base) {
    int i, ans, counter = ans = 0, tens = 1;
    unsigned int decHolder = dec;

    for (i = 0; i < 10; i++, tens *= 10) {
        ans += (decHolder % base) * tens;
        if (decHolder / base == 0) {
            break;
        } else {
            decHolder /= base;
        }
    }
    if (i == 10) {
        ans = -1;
    }

    return ans;
}

void addition(char first[], char second[], int base) {
    int firstLen = strlen(first), secondLen = strlen(second),
        answerLen = firstLen + 1, carry, holder, check = holder = carry = 0, i,
        j, k;
    char answer[answerLen];

    for (i = answerLen - 1, j = firstLen - 1, k = secondLen - 1; i >= 0;
         i--, j--, k--) {
        // Reset Holder
        holder = 0;

        // Adds the carry from the previous loop
        if (carry) {
            holder++;
            carry = 0;
        }

        // Adds the value in the first number into the holder
        if (first[j] >= '0' && first[j] <= '9') {
            holder += (first[j] - '0');
        } else if (first[j] >= 'A' && first[j] <= 'Z') {
            holder += ((first[j] - 'A') + 10);
        }

        // If the second value still exists, adds it to the holder
        if (k >= 0) {
            if (second[k] >= '0' && second[k] <= '9') {
                holder += second[k] - '0';
            } else if (second[k] >= 'A' && second[k] <= 'Z') {
                holder += (second[k] - 'A') + 10;
            }
        }

        // Handles the carry
        if (holder >= base) {
            carry = 1;
            holder -= base;
        }

        // Converts the int values to characters
        if (holder > 9) {
            holder += 'A' - 10;
        } else {
            holder += '0';
        }

        answer[i] = holder;
    }

    // Prints the answer
    check = 1;
    for (int i = 0; i < answerLen; i++) {
        if (check && answer[i] != '0') {
            check = 0;
        }
        if (!check) {
            printf("%c", answer[i]);
        }
    }
    printf("\n");
}

void subtraction(char first[], char second[], int base) {
    int firstLen = strlen(first), secondLen = strlen(second),
        answerLen = firstLen + 1, carry, carryNext, holder,
        check = holder = carryNext = carry = 0, i, j, k;
    char answer[answerLen];

    for (i = answerLen - 1, j = firstLen - 1, k = secondLen - 1; i >= 0;
         i--, j--, k--) {
        // Reset Holder
        holder = 0;
        carry = carryNext;

        // Handles the carry from the previous loop

        // Adds the value in the first number into the holder
        if (first[j] >= '0' && first[j] <= '9') {
            holder += (first[j] - '0');
        } else if (first[j] >= 'A' && first[j] <= 'Z') {
            holder += ((first[j] - 'A') + 10);
        }

        // If the second value still exists, subtracts it from the holder
        if (k >= 0) {
            // Checks if the second value is greater than the first value and
            // handles the borrowing
            if (first[j] < second[k]) {
                carryNext = 1;
                holder += base;
            }
            printf("holder after carry: %i\t", holder);
            if (second[k] >= '0' && second[k] <= '9') {
                holder -= second[k] - '0';
            } else if (second[k] >= 'A' && second[k] <= 'Z') {
                holder -= (second[k] - 'A') + 10;
            }
        }

        if (carry) {
            if (holder == 0) {
                holder = base - 1;
            } else {
                holder--;
                carryNext = 0;
            }
        }

        // Converts values greater than 9 to its alphabet equivalent and values
        // less than 10 to its char equivalent
        if (holder > 9) {
            holder += 'A' - 10;
        } else {
            holder += '0';
        }

        answer[i] = holder;
    }

    // Prints the answer
    check = 1;
    for (int i = 0; i < answerLen; i++) {
        if (check && answer[i] != '0') {
            check = 0;
        }
        if (!check) {
            printf("%c", answer[i]);
        }
    }
    printf("\n");
}