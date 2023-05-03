<<<<<<< HEAD
#ifndef DEFIND_H
#define DEFIND_H
struct Student {
    char ID[10];
    char Name[25];
    char Birthday[15];
    float linear,cal,basic;
    float GPA;
};

const int MAX = 1000;
Student StudentList[MAX];
int AmountofStudent = 0;
=======
#ifndef DEFIND_H
#define DEFIND_H
struct Student {
    char ID[10];
    char Name[25];
    char Birthday[15];
    float linear,cal,basic;
    float GPA;
};

const int MAX = 1000;
Student StudentList[MAX];
int AmountofStudent = 0;
>>>>>>> bfe9f240f87b74c84ea42d9f02b322edd6d53e7d
#endif