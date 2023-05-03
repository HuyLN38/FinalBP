#ifndef BIRTHDAY_H
#define BIRTHDAY_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <cstring>
#include "defind.h"

int compare_dates(const void* a, const void* b) {

    const char* sa = *(const char**) a;
    const char* sb = *(const char**) b;

    if (strcmp(sa + 6, sb + 6) != 0) {
        return strcmp(sa + 6, sb + 6);
    }

    if (strcmp(sa + 3, sb + 3) != 0) {
        return strcmp(sa + 3, sb + 3);
    }

    return strcmp(sa, sb);
}

void sort_birthdays(char** birthdays, int size) {
    qsort(birthdays, size, sizeof(char*), compare_dates);
}
void Birthday(int option) {
    int Display;
    if (AmountofStudent == 0) {
        return;
    }
    char* BirthdayCompare[MAX];
    for (int i = 0; i < AmountofStudent; i++) {
        BirthdayCompare[i] = StudentList[i].Birthday;
    }
    sort_birthdays(BirthdayCompare, AmountofStudent);
    printf("| %-10s | %-25s | %-15s |\n", "ID", "Name", "Birthday");
    if (option == 1) {
        Display = AmountofStudent -1;
    }
    if (option == 2) {
        Display = 0;
    }
        for (int j = 0; j < AmountofStudent; j++) {
            if (strcmp(BirthdayCompare[Display], StudentList[j].Birthday) == 0) {
                printf("| %-10s | %-25s | %-15s |\n", StudentList[j].ID, StudentList[j].Name, StudentList[j].Birthday);
            }
        }
}
#endif