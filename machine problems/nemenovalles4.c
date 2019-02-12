#include <stdio.h>

void printDayOfTheWeek(int, int, int);
void printNthDay(int, int, int);
void case2(int, int);
int checkInputs(int day, int month, int year, int testCaseType);
int checkLeapYear(int);
int roundOwn(float);

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
        int day, month, year = month = day = 1;

        do {
            if (testCaseType < 1 || testCaseType > 2) {
                printf("You have entered an invalid input\n");
            }
            printf(
                "Enter the type of output that you want\n"
                "[1]Day of the week, nth day in the year\n"
                "[2]Day of the week, Month and Day\n");
            scanf("%i", &testCaseType);
        } while (testCaseType < 1 || testCaseType > 2);

        // TestCaseType == 1
        if (testCaseType == 1) {
            printf("\nEnter the Day of the Month\n");
            scanf("%i", &day);

            printf("\nEnter the Month\n");
            scanf("%i", &month);

            printf("\nEnter the Year\n");
            scanf("%i", &year);

            if (!checkInputs(day, month, year, testCaseType)) {
                printDayOfTheWeek(day, month, year);
                printNthDay(day, month, year);
            } else {
                printf("INVALID\n");
            }
        }

        // TestCaseType == 2
        else {
            printf("\nEnter the nth Day\n");
            scanf("%i", &day);

            printf("\nEnter the Year\n");
            scanf("%i", &year);

            if (!checkInputs(day, 1, year, testCaseType)) {
                case2(day, year);
            } else {
                printf("INVALID\n");
            }
        }
    }

    return 0;
}

void printDayOfTheWeek(int day, int month, int year) {
    char days[][10] = {"MONDAY", "TUESDAY",  "WEDNESDAY", "THURSDAY",
                       "FRIDAY", "SATURDAY", "SUNDAY"};

    if (month <= 2) {
        year--;
        month += 12;
    }

    int A = year / 100;
    int B = A / 4;
    int C = 2 - A + B;
    int E = 365.25 * (year + 4716);
    int F = 30.6001 * (month + 1);
    float JD = C + day + E + F - 1524.5;

    printf("%s, ", days[roundOwn(JD) % 7]);
}

void printNthDay(int day, int month, int year) {
    int table[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    // There is a zeroth month so that when accessing the table 1 corresponds to
    // january, which is what is the common way to represent the month in
    // numbers.

    // leapYear is a flag that states if the year given is a leap year through
    // the check leap year function
    int leapYear = checkLeapYear(year), nthDay = 0;

    // Loops through the loop until it reaches the month BEFORE the indicated
    // test case
    for (int i = 0; i < month; i++) {
        nthDay += table[leapYear][i];
    }

    // Adds the day given in the test case to the days that was accumulated from
    // the previous months
    nthDay += day;

    // Creates the suffix based on the last 2 digits
    char suffix[] = "th";

    // Runs this switch if the last two digits are within 00 - 09 and 20 - 99
    if (!(nthDay % 100 > 10 && nthDay % 100 < 20)) {
        // Checks the last two digits if it is 1,2, or 3
        switch (nthDay % 10) {
            case 1:
                suffix[0] = 's';
                suffix[1] = 't';
                break;
            case 2:
                suffix[0] = 'n';
                suffix[1] = 'd';
                break;
            case 3:
                suffix[0] = 'r';
                suffix[1] = 'd';
                break;
            default:
                break;
        }
    }

    printf("%i%s day\n", nthDay, suffix);
}

void case2(int day, int year) {
    int table[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    char months[][10] = {"",        "January",   "February", "March",
                         "April",   "May",       "June",     "July",
                         "August",  "September", "October",  "November",
                         "December"};
    int leapYear = checkLeapYear(year), iterator = 1;

    // Runs the loop while day is greater than the months in the table. This
    // means that it stops when the day is found within the month. The iterator
    // will be the month.
    while (day - table[leapYear][iterator] > 0) {
        day -= table[leapYear][iterator];
        iterator++;
    }

    printDayOfTheWeek(day, iterator, year);
    printf("%s %i\n", months[iterator], day);
}

int checkInputs(int day, int month, int year, int testCaseType) {
    int table[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    int leapYear = checkLeapYear(year);

    // Determines the number of days to check depending on the leap year

    // If year is negative return an error
    if (year < 0) {
        return 1;
    }

    // Checks the test case type to know what to check.
    if (testCaseType == 1) {
        // Checks if the day given is greater than the month that it should
        // have, depending if it is a leap year or not
        if (day > table[leapYear][month]) {
            return 1;
        }
    } else {
        int dayCheck = leapYear ? 366 : 365;

        // Checks if month is less than 0 or greater than 12
        if (month < 0 || month > 12) {
            return 1;
        }

        // Checks if day is greater than the number of days in a year
        if (day > dayCheck) {
            return 1;
        }
    }

    return 0;
}

int checkLeapYear(int year) {
    int leapYear = 0;

    // Checks if the year is divisible by 4
    if (year % 4 == 0) {
        // Checks if the year is divisible by 100
        if (year % 100 == 0) {
            // If it is divisible by 100, check if it is divisible by 400
            if (year % 400 == 0) {
                leapYear = 1;
            }
        }

        // If it is not divisible by 100, then it must be a leap year
        else {
            leapYear = 1;
        }
    }

    return leapYear;
}

int roundOwn(float input) {

    // Round offs the input. if the input + 0.5 when round down is greater than
    // input when round down, then that means that the decimal is >=0.5, which
    // means it should be round up, otherwise it isn't
    if ((int)(input + 0.5) > (int)input) {
        input += 0.5;
    }

    return input;
}