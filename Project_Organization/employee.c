
#include <stdio.h>

struct Company
{
    char name[50];
    char location[100];
    char director[100];
    int totalStaff;
};

struct Worker
{
    int code;
    char fullName[100];
    char department[50];
    float salary;
};

struct Company myCompany;
struct Worker staff[100];
int staffTotal = 0;

void createProfile()
{
    printf("\n--- CREATE COMPANY PROFILE ---\n");

    printf("Company name       : ");
    scanf(" %[^\n]", myCompany.name);

    printf("Company location   : ");
    scanf(" %[^\n]", myCompany.location);

    printf("Director name      : ");
    scanf(" %[^\n]", myCompany.director);

    printf("Total employees    : ");
    scanf("%d", &myCompany.totalStaff);

    printf("\n[ SUCCESS ] Company profile created.\n");
}

void addNewStaff()
{
    if(staffTotal >= 100)
    {
        printf("\n[ ERROR ] Employee database is full.\n");
        return;
    }

    printf("\n--- EMPLOYEE REGISTRATION FORM ---\n");

    printf("Staff code         : ");
    scanf("%d", &staff[staffTotal].code);

    printf("Full name          : ");
    scanf(" %[^\n]", staff[staffTotal].fullName);

    printf("Working department : ");
    scanf(" %[^\n]", staff[staffTotal].department);

    printf("Monthly salary     : ");
    scanf("%f", &staff[staffTotal].salary);

    staffTotal++;

    printf("\n[ SUCCESS ] New staff member registered.\n");
}

void companyReport()
{
    printf("\n");
    printf("========================================\n");
    printf("          COMPANY INFORMATION          \n");
    printf("========================================\n");

    printf("Business Name      : %s\n", myCompany.name);
    printf("Office Location    : %s\n", myCompany.location);
    printf("Company Director   : %s\n", myCompany.director);
    printf("----------------------------------------\n");
    printf("Declared Staff     : %d\n", myCompany.totalStaff);
    printf("Registered Staff   : %d\n", staffTotal);
    printf("========================================\n");
}

void employeeReport()
{
    int i;

    if(staffTotal == 0)
    {
        printf("\n[ NOTICE ] Employee database is empty.\n");
        return;
    }

    printf("\n");
    printf("************ STAFF DIRECTORY ************\n");

    for(i = 0; i < staffTotal; i++)
    {
        printf("\nEMPLOYEE RECORD #%d\n", i + 1);
        printf("-----------------------------------------\n");

        printf("Employee Code : %d\n", staff[i].code);
        printf("Employee Name : %s\n", staff[i].fullName);
        printf("Department    : %s\n", staff[i].department);
        printf("Salary        : %.2f BDT\n", staff[i].salary);
    }

    printf("\n******** END OF STAFF DIRECTORY *********\n");
}

int main()
{
    int choice;

    printf("\n");
    printf("#########################################\n");
    printf("#                                       #\n");
    printf("#       CORPORATE RECORD SYSTEM         #\n");
    printf("#                                       #\n");
    printf("#########################################\n");

    do
    {
        printf("\n============== CONTROL PANEL ==============\n");
        printf("|  [1]  Create Company Profile             |\n");
        printf("|  [2]  Register Employee                  |\n");
        printf("|  [3]  Generate Company Report            |\n");
        printf("|  [4]  Open Staff Directory               |\n");
        printf("|  [0]  Close Application                  |\n");
        printf("============================================\n");

        printf("Enter command number: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                createProfile();
                break;

            case 2:
                addNewStaff();
                break;

            case 3:
                companyReport();
                break;

            case 4:
                employeeReport();
                break;

            case 0:
                printf("\nApplication closed. Thank you!\n");
                break;

            default:
                printf("\n[ WARNING ] Invalid command. Try again.\n");
        }

    } while(choice != 0);

    return 0;
}
