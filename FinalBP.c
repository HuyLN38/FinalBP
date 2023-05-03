<<<<<<< HEAD
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include "birthday.h"
#include <cstring>

int compare(const void* a, const void* b)
{
    Student* sv1 = (Student*)a;
    Student* sv2 = (Student*)b;
    if (sv1->GPA > sv2->GPA)
        return -1;
    else if (sv1->GPA < sv2->GPA)
        return 1;
    return 0;
}

void NhapStudent(Student* sv) {
    fflush(stdin); 
    printf("Input ID : ");
    fgets(sv->ID, 10, stdin);
    sv->ID[strcspn(sv->ID, "\n")] = 0; 
    fflush(stdin);
    printf("Input Name : ");
    fgets(sv->Name, 50, stdin);
    fflush(stdin); 
    sv->Name[strcspn(sv->Name, "\n")] = 0; 
    printf("Input Birthday (dd/mm/yy) : ");
    fgets(sv->Birthday, 15, stdin);
    sv->Birthday[strcspn(sv->Birthday, "\n")] = 0; 
    printf("Input Linear Cal BasicPro Score: ");
    scanf("%f %f %f",&sv->linear, &sv->cal, &sv->basic);
    sv->GPA = (sv->linear + sv->cal + sv->basic)/15;
    printf("GPA : %0.1f\n" ,sv->GPA );
}
void printtitle(){
    printf("| %-10s | %-25s | %-15s | %-8s | %-8s | %-8s | %-8s |", "ID", "Name", "Birthday", "Linear", "Calculus", "BasicP", "GPA");
    printf("\n%s","----------------------------------------------------------------------------------------------------------");
}
void printstudent(int i){
    printf("\n| %-10s | %-25s | %-15s | %-8.1f | %-8.1f | %-8.1f | %-8.1f |", StudentList[i].ID, StudentList[i].Name, StudentList[i].Birthday, StudentList[i].linear, StudentList[i].cal, StudentList[i].basic, StudentList[i].GPA);
    printf("\n%s","----------------------------------------------------------------------------------------------------------");
    return;
}

void Search(char ID[10]) {
    bool temp = false;
    int temp2;
    for (int i = 0; i < AmountofStudent; i++) {
        for (int j = 0; j < 10; j++){
            if (StudentList[i].ID[j] == ID[j]){
                temp=true;
            }else{
                temp = false;
                break;
            }
        }
    if (temp == true){
        temp2 = i;
        break;
    }
    }
        if (temp == true) {
        printf("| %-10s | %-25s | %-15s | %-8s | %-8s | %-8s | %-8s |\n", "ID", "Name", "Birthday", "Linear", "Cal", "BasicP", "GPA");
        printf("%s\n","------------------------------------------------------------------------------------------------------");
        printf("| %-10s | %-25s | %-15s | %-8.1f | %-8.1f | %-8.1f | %-8.1f |\n", StudentList[temp2].ID, StudentList[temp2].Name, StudentList[temp2].Birthday, StudentList[temp2].linear, StudentList[temp2].cal, StudentList[temp2].basic, StudentList[temp2].GPA);
    }
}

char *last_name(char *full_name) {
    char *last_name;
    last_name = strrchr(full_name, ' ');
    if (last_name != NULL) {
        last_name++;
        return last_name;
    }
    return 0;
}

void printoutthelist(int option){
    switch (option){
    case 1 :
        printtitle();
        for (int i = 0; i < AmountofStudent; i++) printstudent(i);
    break;
    case 2 :
    FILE *f = fopen("c:\\file.txt", "w");
    fprintf(f, "| %-10s | %-25s | %-15s | %-8s | %-8s | %-8s | %-8s |\n", "ID", "Name", "Birthday", "Linear", "Calculus", "BasicP", "GPA");
    for (int i = 0; i < AmountofStudent; i++) {
    fprintf(f,"%s\n","----------------------------------------------------------------------------------------------------------");
    fprintf(f,"| %-10s | %-25s | %-15s | %-8.1f | %-8.1f | %-8.1f | %-8.1f |\n", StudentList[i].ID, StudentList[i].Name, StudentList[i].Birthday, StudentList[i].linear, StudentList[i].cal, StudentList[i].basic, StudentList[i].GPA);
    }
    fclose(f);
    }
}

void PrintListStudent() {
    if (AmountofStudent == 0) {
        return;
    }
    qsort(StudentList, AmountofStudent, sizeof(Student), compare);
    printoutthelist(1);
}

void Score(int option){
    if (AmountofStudent == 0) {
        return;
    }
    float max = 0 ;
    float min = StudentList[0].GPA;
    float maxBP = 0;
    for (int i = 0; i < AmountofStudent; i++) {
        if (max < StudentList[i].GPA) max = StudentList[i].GPA;
        if (min > StudentList[i].GPA) min = StudentList[i].GPA;
        if (maxBP < StudentList[i].basic) maxBP = StudentList[i].basic;
    }
    switch (option)
    {
    case 1: //MAX GPA
    printtitle;
      for (int i = 0; i < AmountofStudent; i++) {
        if (StudentList[i].GPA == max) printstudent(i);
    }
    break;
    case 2: //MIN GPA
    printtitle;
      for (int i = 0; i < AmountofStudent; i++) {
        if (StudentList[i].GPA == min) printstudent(i);
    }
    break;
    case 3: //MAX BP
    printtitle;
      for (int i = 0; i < AmountofStudent; i++) {
        if (StudentList[i].basic == maxBP) printstudent(i);
    }
    break;
    default:
        printf("Wrong option");
        break;
    }
    
} 
int main() {
    int option;
    int choice, n;
    do {
        printf("%s\n","----------------------------------------------------------------------------------------------------------");
        printf("1. Input student's infomations\n2. Search for student by ID\n3. Print out students's last name\n4. Print out the list\n5. Print Youngest or Oldest\n6. Print highest or lowest score\n7. Sort and print student list by GPA in descending order\n8. End\n Input Func : ");
        scanf("%d", &choice);
        printf("%s\n","----------------------------------------------------------------------------------------------------------");
        switch (choice) {
        case 1:
            if (AmountofStudent >= MAX) {
            }
            else {
                printf("Number of Input: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Input student number %d",AmountofStudent+1);
                    NhapStudent(&StudentList[AmountofStudent]);
                    AmountofStudent++;
                }
            }
            break;
        case 2:
            fflush(stdin);
            char ID[10];
            printf("Input ID : ");
            fgets(ID, 10, stdin);
            Search(ID);
            fflush(stdin);
            break;
        case 3:
         char* lastname;
         printf("| %-10s | %-25s |\n","ID","Last name");
         for (int i = 0; i < AmountofStudent; i++) {
            lastname = last_name(StudentList[i].Name);
            printf("%s\n","------------------------------------------");
            printf("| %-10s | %-25s |\n",StudentList[i].ID,lastname);
            printf("%s\n","------------------------------------------");
         }
         break;
        case 4:
         printf("%s\n","----------------------------------------------------------------");
                printf("1. Print out the list to the screen\n2. Print out the list to a file in C:\n Input Option : ");
                scanf("%d",&option);
                printf("%s\n","----------------------------------------------------------------");
            printoutthelist(option);
            break;
        case 5:
             printf("%s\n","----------------------------------------------------------------");
                printf("1. Youngest\n2. Oldest\n Input Func : ");
                scanf("%d",&option);
                printf("%s\n","----------------------------------------------------------------");
            Birthday(option);
            break;
        case 6:
         printf("%s\n","----------------------------------------------------------------");
                printf("1. MAX GPA\n2. MIN GPA\n3. MAX BP\n Input Option : ");
                scanf("%d",&option);
                printf("%s\n","----------------------------------------------------------------");
            Score(option);
            break;
        case 7:
            PrintListStudent();
            break;
        case 8:
            break;
        default:
            printf("Wrong option");
            break;
        }
    } while (choice != 8);

    return 0;
}

=======
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include "birthday.h"
#include <cstring>

int compare(const void* a, const void* b)
{
    Student* sv1 = (Student*)a;
    Student* sv2 = (Student*)b;
    if (sv1->GPA > sv2->GPA)
        return -1;
    else if (sv1->GPA < sv2->GPA)
        return 1;
    return 0;
}

void NhapStudent(Student* sv) {
    fflush(stdin); 
    printf("Input ID : ");
    fgets(sv->ID, 10, stdin);
    sv->ID[strcspn(sv->ID, "\n")] = 0; 
    fflush(stdin);
    printf("Input Name : ");
    fgets(sv->Name, 50, stdin);
    fflush(stdin); 
    sv->Name[strcspn(sv->Name, "\n")] = 0; 
    printf("Input Birthday (dd/mm/yy) : ");
    fgets(sv->Birthday, 15, stdin);
    sv->Birthday[strcspn(sv->Birthday, "\n")] = 0; 
    printf("Input Linear Cal BasicPro Score: ");
    scanf("%f %f %f",&sv->linear, &sv->cal, &sv->basic);
    sv->GPA = (sv->linear + sv->cal + sv->basic)/15;
    printf("GPA : %0.1f\n" ,sv->GPA );
}
void printtitle(){
    printf("| %-10s | %-25s | %-15s | %-8s | %-8s | %-8s | %-8s |", "ID", "Name", "Birthday", "Linear", "Calculus", "BasicP", "GPA");
    printf("\n%s","----------------------------------------------------------------------------------------------------------");
}
void printstudent(int i){
    printf("\n| %-10s | %-25s | %-15s | %-8.1f | %-8.1f | %-8.1f | %-8.1f |", StudentList[i].ID, StudentList[i].Name, StudentList[i].Birthday, StudentList[i].linear, StudentList[i].cal, StudentList[i].basic, StudentList[i].GPA);
    printf("\n%s","----------------------------------------------------------------------------------------------------------");
    return;
}

void Search(char ID[10]) {
    bool temp = false;
    int temp2;
    for (int i = 0; i < AmountofStudent; i++) {
        for (int j = 0; j < 10; j++){
            if (StudentList[i].ID[j] == ID[j]){
                temp=true;
            }else{
                temp = false;
                break;
            }
        }
    if (temp == true){
        temp2 = i;
        break;
    }
    }
        if (temp == true) {
        printf("| %-10s | %-25s | %-15s | %-8s | %-8s | %-8s | %-8s |\n", "ID", "Name", "Birthday", "Linear", "Cal", "BasicP", "GPA");
        printf("%s\n","------------------------------------------------------------------------------------------------------");
        printf("| %-10s | %-25s | %-15s | %-8.1f | %-8.1f | %-8.1f | %-8.1f |\n", StudentList[temp2].ID, StudentList[temp2].Name, StudentList[temp2].Birthday, StudentList[temp2].linear, StudentList[temp2].cal, StudentList[temp2].basic, StudentList[temp2].GPA);
    }
}

char *last_name(char *full_name) {
    char *last_name;
    last_name = strrchr(full_name, ' ');
    if (last_name != NULL) {
        last_name++;
        return last_name;
    }
    return 0;
}

void printoutthelist(int option){
    switch (option){
    case 1 :
        printtitle();
        for (int i = 0; i < AmountofStudent; i++) printstudent(i);
    break;
    case 2 :
    FILE *f = fopen("c:\\file.txt", "w");
    fprintf(f, "| %-10s | %-25s | %-15s | %-8s | %-8s | %-8s | %-8s |\n", "ID", "Name", "Birthday", "Linear", "Calculus", "BasicP", "GPA");
    for (int i = 0; i < AmountofStudent; i++) {
    fprintf(f,"%s\n","----------------------------------------------------------------------------------------------------------");
    fprintf(f,"| %-10s | %-25s | %-15s | %-8.1f | %-8.1f | %-8.1f | %-8.1f |\n", StudentList[i].ID, StudentList[i].Name, StudentList[i].Birthday, StudentList[i].linear, StudentList[i].cal, StudentList[i].basic, StudentList[i].GPA);
    }
    fclose(f);
    }
}

void PrintListStudent() {
    if (AmountofStudent == 0) {
        return;
    }
    qsort(StudentList, AmountofStudent, sizeof(Student), compare);
    printoutthelist(1);
}

void Score(int option){
    if (AmountofStudent == 0) {
        return;
    }
    float max = 0 ;
    float min = StudentList[0].GPA;
    float maxBP = 0;
    for (int i = 0; i < AmountofStudent; i++) {
        if (max < StudentList[i].GPA) max = StudentList[i].GPA;
        if (min > StudentList[i].GPA) min = StudentList[i].GPA;
        if (maxBP < StudentList[i].basic) maxBP = StudentList[i].basic;
    }
    switch (option)
    {
    case 1: //MAX GPA
    printtitle;
      for (int i = 0; i < AmountofStudent; i++) {
        if (StudentList[i].GPA == max) printstudent(i);
    }
    break;
    case 2: //MIN GPA
    printtitle;
      for (int i = 0; i < AmountofStudent; i++) {
        if (StudentList[i].GPA == min) printstudent(i);
    }
    break;
    case 3: //MAX BP
    printtitle;
      for (int i = 0; i < AmountofStudent; i++) {
        if (StudentList[i].basic == maxBP) printstudent(i);
    }
    break;
    default:
        printf("Wrong option");
        break;
    }
    
} 
int main() {
    int option;
    int choice, n;
    do {
        printf("%s\n","----------------------------------------------------------------------------------------------------------");
        printf("1. Input student's infomations\n2. Search for student by ID\n3. Print out students's last name\n4. Print out the list\n5. Print Youngest or Oldest\n6. Print highest or lowest score\n7. Sort and print student list by GPA in descending order\n8. End\n Input Func : ");
        scanf("%d", &choice);
        printf("%s\n","----------------------------------------------------------------------------------------------------------");
        switch (choice) {
        case 1:
            if (AmountofStudent >= MAX) {
            }
            else {
                printf("Number of Input: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    NhapStudent(&StudentList[AmountofStudent]);
                    AmountofStudent++;
                }
            }
            break;
        case 2:
            fflush(stdin);
            char ID[10];
            printf("Input ID : ");
            fgets(ID, 10, stdin);
            Search(ID);
            fflush(stdin);
            break;
        case 3:
         char* lastname;
         printf("| %-10s | %-25s |\n","ID","Last name");
         for (int i = 0; i < AmountofStudent; i++) {
            lastname = last_name(StudentList[i].Name);
            printf("%s\n","------------------------------------------");
            printf("| %-10s | %-25s |\n",StudentList[i].ID,lastname);
            printf("%s\n","------------------------------------------");
         }
         break;
        case 4:
         printf("%s\n","----------------------------------------------------------------");
                printf("1. Print out the list to the screen\n2. Print out the list to a file in C:\n Input Option : ");
                scanf("%d",&option);
                printf("%s\n","----------------------------------------------------------------");
            printoutthelist(option);
            break;
        case 5:
             printf("%s\n","----------------------------------------------------------------");
                printf("1. Youngest\n2. Oldest\n Input Func : ");
                scanf("%d",&option);
                printf("%s\n","----------------------------------------------------------------");
            Birthday(option);
            break;
        case 6:
         printf("%s\n","----------------------------------------------------------------");
                printf("1. MAX GPA\n2. MIN GPA\n3. MAX BP\n Input Option : ");
                scanf("%d",&option);
                printf("%s\n","----------------------------------------------------------------");
            Score(option);
            break;
        case 7:
            PrintListStudent();
            break;
        case 8:
            break;
        default:
            printf("Wrong option");
            break;
        }
    } while (choice != 8);

    return 0;
}

>>>>>>> bfe9f240f87b74c84ea42d9f02b322edd6d53e7d
