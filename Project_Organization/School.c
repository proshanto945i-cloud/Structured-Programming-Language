
#include <stdio.h>

struct SchoolInfo
{
    char schoolName[100];
    char address[100];
    char principal[100];
    int establishedYear;
};

struct StudentInfo
{
    int roll;
    char name[100];
    int className;
    char section;
    float marks;
};

struct SchoolInfo school;
struct StudentInfo students[100];

int totalStudents = 0;

void schoolRegistration()
{
    printf("\n========== SCHOOL REGISTRATION ==========\n");

    printf("School Name       : ");
    scanf(" %[^\n]", school.schoolName);

    printf("School Address    : ");
    scanf(" %[^\n]", school.address);

    printf("Principal Name    : ");
    scanf(" %[^\n]", school.principal);

    printf("Established Year  : ");
    scanf("%d", &school.establishedYear);

    printf("\n[SUCCESS] School information recorded!\n");
}

void admitStudent()
{
    if(totalStudents >= 100)
    {
        printf("\nStudent record capacity is full!\n");
        return;
    }

    printf("\n========== STUDENT ADMISSION ==========\n");

    printf("Enter Roll Number : ");
    scanf("%d", &students[totalStudents].roll);

    printf("Student Name      : ");
    scanf(" %[^\n]", students[totalStudents].name);

    printf("Class             : ");
    scanf("%d", &students[totalStudents].className);

    printf("Section           : ");
    scanf(" %c", &students[totalStudents].section);

    printf("Obtained Marks    : ");
    scanf("%f", &students[totalStudents].marks);

    totalStudents++;

    printf("\n[ SUCCESS ] Student admission completed!\n");
}

void schoolProfile()
{
    printf("\n");
    printf("========================================\n");
    printf("             SCHOOL PROFILE             \n");
    printf("========================================\n");

    printf("Institution Name : %s\n", school.schoolName);
    printf("Location         : %s\n", school.address);
    printf("Head Teacher     : %s\n", school.principal);
    printf("Founded In       : %d\n", school.establishedYear);

    printf("----------------------------------------\n");
    printf("Total Admissions: %d\n", totalStudents);
    printf("========================================\n");
}

void studentDirectory()
{
    int i;

    if(totalStudents == 0)
    {
        printf("\nNo student records available!\n");
        return;
    }

    printf("\n========== STUDENT DIRECTORY ==========\n");

    for(i = 0; i < totalStudents; i++)
    {
        printf("\nStudent Record #%d\n", i + 1);
        printf("----------------------------------------\n");

        printf("Roll Number : %d\n", students[i].roll);
        printf("Name        : %s\n", students[i].name);
        printf("Class       : %d\n", students[i].className);
        printf("Section     : %c\n", students[i].section);
        printf("Marks       : %.2f\n", students[i].marks);
    }

    printf("\n========================================\n");
}

void studentResult()
{
    int roll, i, found = 0;

    printf("\n========== RESULT SEARCH ==========\n");
    printf("Enter Student Roll: ");
    scanf("%d", &roll);

    for(i = 0; i < totalStudents; i++)
    {
        if(students[i].roll == roll)
        {
            found = 1;

            printf("\n========== ACADEMIC RESULT ==========\n");

            printf("Student Name : %s\n", students[i].name);
            printf("Roll Number  : %d\n", students[i].roll);
            printf("Class        : %d\n", students[i].className);
            printf("Marks        : %.2f / 100\n", students[i].marks);

            if(students[i].marks >= 80)
                printf("Grade        : A+\n");
            else if(students[i].marks >= 70)
                printf("Grade        : A\n");
            else if(students[i].marks >= 60)
                printf("Grade        : A-\n");
            else if(students[i].marks >= 50)
                printf("Grade        : B\n");
            else if(students[i].marks >= 40)
                printf("Grade        : C\n");
            else if(students[i].marks >= 33)
                printf("Grade        : D\n");
            else
                printf("Grade        : F (Fail)\n");

            printf("====================================\n");
            break;
        }
    }

    if(found == 0)
    {
        printf("\nNo student found with this roll number!\n");
    }
}

int main()
{
    int option;

    printf("\n");
    printf("****************************************\n");
    printf("*                                      *\n");
    printf("*        SCHOOL MANAGEMENT SYSTEM      *\n");
    printf("*                                      *\n");
    printf("****************************************\n");

    do
    {
        printf("\n------------- MAIN DASHBOARD -------------\n");
        printf(" 1. Register School Information\n");
        printf(" 2. Admit New Student\n");
        printf(" 3. View School Profile\n");
        printf(" 4. View Student Directory\n");
        printf(" 5. Search Student Result\n");
        printf(" 0. Exit System\n");
        printf("-------------------------------------------\n");

        printf("Choose an option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                schoolRegistration();
                break;

            case 2:
                admitStudent();
                break;

            case 3:
                schoolProfile();
                break;

            case 4:
                studentDirectory();
                break;

            case 5:
                studentResult();
                break;

            case 0:
                printf("\nSchool Management System Closed.\n");
                break;

            default:
                printf("\nInvalid option! Please select again.\n");
        }

    } while(option != 0);

    return 0;
}
