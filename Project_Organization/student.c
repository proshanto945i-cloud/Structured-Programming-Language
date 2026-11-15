
#include <stdio.h>

struct Student {
    int id, semester;
    char name[100], department[50];
    float cgpa;
};

struct Student st[100];
int total = 0;

void addStudent() {
    if(total >= 100) {
        printf("\nDatabase Full!\n");
        return;
    }

    printf("\nEnter ID: ");
    scanf("%d", &st[total].id);

    printf("Enter Name: ");
    scanf(" %[^\n]", st[total].name);

    printf("Enter Department: ");
    scanf(" %[^\n]", st[total].department);

    printf("Enter Semester: ");
    scanf("%d", &st[total].semester);

    printf("Enter CGPA: ");
    scanf("%f", &st[total].cgpa);

    total++;
    printf("\nStudent Added Successfully!\n");
}

void showStudents() {
    int i;

    if(total == 0) {
        printf("\nNo Records Found!\n");
        return;
    }

    for(i = 0; i < total; i++) {
        printf("\n--- Student %d ---\n", i + 1);
        printf("ID: %d\nName: %s\nDepartment: %s\nSemester: %d\nCGPA: %.2f\n",
        st[i].id, st[i].name, st[i].department,
        st[i].semester, st[i].cgpa);
    }
}

void searchStudent() {
    int id, i, found = 0;

    printf("\nEnter Student ID: ");
    scanf("%d", &id);

    for(i = 0; i < total; i++) {
        if(st[i].id == id) {
            printf("\nName: %s\nDepartment: %s\nSemester: %d\nCGPA: %.2f\n",
            st[i].name, st[i].department,
            st[i].semester, st[i].cgpa);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("\nStudent Not Found!\n");
}

void updateCGPA() {
    int id, i, found = 0;

    printf("\nEnter Student ID: ");
    scanf("%d", &id);

    for(i = 0; i < total; i++) {
        if(st[i].id == id) {
            printf("Enter New CGPA: ");
            scanf("%f", &st[i].cgpa);
            printf("\nCGPA Updated Successfully!\n");
            found = 1;
            break;
        }
    }

    if(!found)
        printf("\nStudent Not Found!\n");
}

int main() {
    int choice;

    do {
        printf("\n===== STUDENT MANAGEMENT =====\n");
        printf("1. Add Student\n");
        printf("2. Show Students\n");
        printf("3. Search Student\n");
        printf("4. Update CGPA\n");
        printf("0. Exit\n");

        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: showStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateCGPA(); break;
            case 0: printf("\nProgram Closed!\n"); break;
            default: printf("\nInvalid Choice!\n");
        }

    } while(choice != 0);

    return 0;
}
