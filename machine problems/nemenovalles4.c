#include <stdio.h>

void printDayOfTheWeek(int, int, int);
void printNthDay(int, int, int);
void case2(int, int);
void printDayOfTheWeekFromNth(int, int);
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

            printDayOfTheWeek(day, month, year);
            printNthDay(day, month, year);
        }

        // TestCaseType == 2
        else {
            printf("\nEnter the nth Day\n");
            scanf("%i", &day);

            printf("\nEnter the Year\n");
            scanf("%i", &year);

            case2(day, year);
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
    int leapYear = checkLeapYear(year), nthDay = 0;

    for (int i = 0; i < month; i++) {
        nthDay += table[leapYear][i];
    }
    nthDay += day;
    char suffix[] = "th";
    if (!(nthDay % 100 > 10 && nthDay % 100 < 20)) {
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

    int leapYear = checkLeapYear(year), iterator = 0;

    while (day - table[leapYear][iterator] > 0) {
        day -= table[leapYear][iterator];
        iterator++;
    }

    printDayOfTheWeek(day, iterator, year);
    printf("%s %i\n", months[iterator], day);
}

int checkLeapYear(int year) {
    int leapYear = 0;
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                leapYear = 1;
            }
        } else {
            leapYear = 1;
        }
    }

    return leapYear;
}

int roundOwn(float input) {
    if ((int)(input + 0.5) > (int)input) {
        input += 0.5;
    }

    return input;
}