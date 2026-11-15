
#include <stdio.h>
#include <string.h>

struct University {
    char name[100], location[100], vc[100];
    int departments;
};

struct Student {
    int id, semester;
    char name[100], department[50];
    float cgpa;
};

struct University uni;
struct Student st[100];
int count = 0;

void registerUniversity() {
    printf("\n--- UNIVERSITY REGISTRATION ---\n");

    printf("University Name: ");
    scanf(" %[^\n]", uni.name);

    printf("Location: ");
    scanf(" %[^\n]", uni.location);

    printf("Vice Chancellor: ");
    scanf(" %[^\n]", uni.vc);

    printf("Total Departments: ");
    scanf("%d", &uni.departments);

    printf("\nUniversity registered successfully!\n");
}

void addStudent() {
    if(count >= 100) {
        printf("\nStudent database is full!\n");
        return;
    }

    printf("\n--- STUDENT ADMISSION ---\n");

    printf("Student ID: ");
    scanf("%d", &st[count].id);

    printf("Student Name: ");
    scanf(" %[^\n]", st[count].name);

    printf("Department: ");
    scanf(" %[^\n]", st[count].department);

    printf("Semester: ");
    scanf("%d", &st[count].semester);

    printf("CGPA: ");
    scanf("%f", &st[count].cgpa);

    count++;
    printf("\nStudent added successfully!\n");
}

void showUniversity() {
    printf("\n========== UNIVERSITY PROFILE ==========\n");

    printf("Name          : %s\n", uni.name);
    printf("Location      : %s\n", uni.location);
    printf("Vice Chancellor: %s\n", uni.vc);
    printf("Departments   : %d\n", uni.departments);
    printf("Total Students: %d\n", count);
}

void showStudents() {
    int i;

    if(count == 0) {
        printf("\nNo student records found!\n");
        return;
    }

    printf("\n========== STUDENT DIRECTORY ==========\n");

    for(i = 0; i < count; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("ID         : %d\n", st[i].id);
        printf("Name       : %s\n", st[i].name);
        printf("Department : %s\n", st[i].department);
        printf("Semester   : %d\n", st[i].semester);
        printf("CGPA       : %.2f\n", st[i].cgpa);
    }
}

void searchStudent() {
    int id, i, found = 0;

    printf("\nEnter Student ID: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++) {
        if(st[i].id == id) {
            printf("\n--- STUDENT RECORD ---\n");
            printf("Name       : %s\n", st[i].name);
            printf("Department : %s\n", st[i].department);
            printf("Semester   : %d\n", st[i].semester);
            printf("CGPA       : %.2f\n", st[i].cgpa);

            if(st[i].cgpa >= 3.75)
                printf("Status     : Excellent\n");
            else if(st[i].cgpa >= 3.00)
                printf("Status     : Good\n");
            else if(st[i].cgpa >= 2.00)
                printf("Status     : Satisfactory\n");
            else
                printf("Status     : Needs Improvement\n");

            found = 1;
            break;
        }
    }

    if(!found)
        printf("\nStudent not found!\n");
}

void searchDepartment() {
    char dept[50];
    int i, found = 0;

    printf("\nEnter Department Name: ");
    scanf(" %[^\n]", dept);

    for(i = 0; i < count; i++) {
        if(strcmp(st[i].department, dept) == 0) {
            printf("\nID: %d | Name: %s | Semester: %d | CGPA: %.2f\n",
                   st[i].id, st[i].name,
                   st[i].semester, st[i].cgpa);
            found = 1;
        }
    }

    if(!found)
        printf("\nNo student found in this department!\n");
}

int main() {
    int choice;

    printf("\n====================================\n");
    printf("     UNIVERSITY MANAGEMENT SYSTEM  \n");
    printf("====================================\n");

    do {
        printf("\n---------- MAIN MENU ----------\n");
        printf("1. Register University\n");
        printf("2. Add Student\n");
        printf("3. University Profile\n");
        printf("4. Student Directory\n");
        printf("5. Search Student\n");
        printf("6. Department Search\n");
        printf("0. Exit\n");
        printf("-------------------------------\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: registerUniversity(); break;
            case 2: addStudent(); break;
            case 3: showUniversity(); break;
            case 4: showStudents(); break;
            case 5: searchStudent(); break;
            case 6: searchDepartment(); break;
            case 0: printf("\nSystem Closed!\n"); break;
            default: printf("\nInvalid Choice!\n");
        }

    } while(choice != 0);

    return 0;
}
