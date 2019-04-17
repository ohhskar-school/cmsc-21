#include <stdio.h>
#include <string.h>
#include "linkedlist.h"

student getStudentInfo(list *);
int enroll(list *, student);
int removeStudent(list *, int);
int getStudentNumber();
int displayStudent(list *, int);

int main() {
    int testCasesNumber = 1, c = 0;
    list l;
    init(&l);

    do {
        scanf("%i", &testCasesNumber);
    } while (testCasesNumber < 0);

    for (int i = 0; i < testCasesNumber; i++) {
        scanf("%i", &c);
        switch (c) {
            case 1:
                enroll(&l, getStudentInfo(&l));
                displayAll(l);
                break;
            case 2:
                removeStudent(&l, getStudentNumber(&l));
                displayAll(l);
                break;
            case 3:
                displayStudent(&l, getStudentNumber(&l));
                break;
            default:
                printf("Invalid Input\n");
                i--;
                break;
        }
    }

    return 1;
}

int enroll(list *l, student x) {
    if (l->size <= 15) {
        return append(l, x);
    } else {
        return 0;
    }
}

int removeStudent(list *l, int p) {
    if (p > 0) {
        genRemove(l, p);
        return 1;
    } else {
        return 0;
    }
}

int displayStudent(list *l, int p) {
    if (p > 0) {
        if (displayStudentFromPosition(l, p) == 1) {
            return 1;
        } else {
            printf("Student not found");
            return 0;
        }
    } else {
        return 0;
    }
}

student getStudentInfo(list *l) {
    student x;
    char tmp;
    int check = 0;
    do {
        if (check > 0) {
            printf(
                "You have already entered a student with the same student "
                "number\n");
        }
        printf("Student Number: ");
        scanf(" %[^\n]s", x.studentNumber);
        check = search(l, x.studentNumber);
    } while (check > 0);

    printf("Family Name: ");
    scanf(" %[^\n]s", x.familyName);

    printf("First Name: ");
    scanf(" %[^\n]s", x.firstName);

    printf("Middle Name: ");
    scanf(" %[^\n]s", x.middleName);

    printf("Program: ");
    scanf(" %[^\n]s", x.program);

    printf("Year Level: ");
    scanf(" %i", &x.yearLevel);

    printf("Gender: ");
    scanf(" %[^\n]s", x.gender);

    printf("Final Grade: ");
    scanf(" %f", &x.finalGrade);

    return x;
}

int getStudentNumber(list *l) {
    char x[100];
    printf("Enter a Student Number\n");
    printf("Student Number: ");
    scanf(" %[^\n]s", x);

    int result = search(l, x);
    if (result > 0){
        return result;
    } else {
        printf ("Student Not Found\n");
        return 0;
    }
}