#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mystudent {
    char studentNumber[100];
    char familyName[100];
    char firstName[100];
    char middleName[100];
    char program[100];
    char gender[100];
    int yearLevel;
    int age;
    float finalGrade;
} student;

typedef struct mynode {
    student item;
    struct mynode *next;
} node;

typedef struct {
    int size;
    node *head;
} list;

void init(list *l) {
    l->size = 0;
    l->head = NULL;
}

void display(student x) {
    printf("Student Number: %s\n", x.studentNumber);
    printf("Name:           %s, ", x.familyName);
    printf("%s ", x.firstName);
    printf("%s\n", x.middleName);
    printf("Program:        %s\n", x.program);
    printf("Year Level:     %i\n", x.yearLevel);
    printf("Gender:         %s\n", x.gender);
    printf("Final Grade:    %.2f%%\n", x.finalGrade);
}

void displayAll(list l) {
    node *curr = l.head;

    printf("\n");

    while (curr != NULL) {
        display(curr->item);
        printf("\n");

        curr = curr->next;
    }
}

int append(list *l, student x) {
    node *n = malloc(sizeof(node));
    if (n == NULL)
        return 0;
    else {
        n->item = x;
        n->next = NULL;

        if (l->head == NULL) {
            l->head = n;
        } else {
            node *tmp = l->head;
            while (tmp->next != NULL) {
                tmp = tmp->next;
            }
            tmp->next = n;
        }
        l->size++;
        return 1;
    }
}

int insertFront(list *l, student x) {
    node *n = malloc(sizeof(node));
    if (n == NULL)
        return 0;
    else {
        n->item = x;
        n->next = NULL;

        if (l->head == NULL)
            l->head = n;
        else {
            n->next = l->head;
            l->head = n;
        }
        l->size++;
        return 1;
    }
}

int removeFirst(list *l) {
    if (l->head == NULL)
        return 0;
    else {
        node *del = l->head;
        l->head = del->next;
        del->next = NULL;
        l->size--;
        free(del);
        return 1;
    }
}

int genRemove(list *l, int p) {
    if (l->head == NULL || p < 1 || p > l->size) {
        printf("An error has occured while removing item\n");
        return 0;
    } else {
        // Creates a temporary node for traversing
        node *tmp = l->head;
        char name[100];
        strcpy(name,tmp->item.studentNumber);

        // If position to be deleted is the first, l->head must be modified
        // accordingly
        if (p == 1) {
            // Handles for both cases where size is 1 or when size is greater
            // than 1
            l->head = tmp->next;

            // Graceful Exit
            tmp->next = NULL;

            // Modify size and free tmp;
            l->size--;
            free(tmp);
            printf("Successfully removed item with Student Number %s\n", name);
            return 1;
        }

        // Traverses until the node BEFORE the position we want to remove the
        // new node
        int cur = 1;
        while (cur < p - 1) {
            tmp = tmp->next;
            cur++;
        }

        // assigns del to the node to be deleted

        node *del = tmp->next;
        strcpy(name,del->item.studentNumber);

        // Handles both cases where del is the last or not the last item in the
        // list
        tmp->next = del->next;

        // Graceful Exit
        del->next = NULL;
        free(del);

        // Decreases the size and returns a success
        l->size--;
        printf("Successfully removed item with Student Number %s\n", name);
        return 1;
    }
}

int displayStudentFromPosition(list *l, int p) {
    if (p > l->size || p < 0 || l->head == NULL) {
        return 0;
    }
    int count = 1;
    node *tmp = l->head;
    while (tmp != NULL) {
        if (count == p) {
            display(tmp->item);
            return 1;
        }
        tmp = tmp->next;
        count++;
    }
}

int search(list *l, char *x) {
    if (l->head == NULL) {
        return 0;
    } else {
        node *tmp = l->head;
        int count = 1;
        while (tmp != NULL) {
            if (strcmp(tmp->item.studentNumber, x) == 0) {
                return count;
            }
            tmp = tmp->next;
            count++;
        }
        return 0;
    }
}