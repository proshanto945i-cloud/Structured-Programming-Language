#include <stdio.h>
int main()
{
    int i;
    int n = 5;
    struct student
    {
        int roll;
        float GPA;
    };

    struct student S[5];

    for (i = 0; i <= 2; i++)
    {
        printf("Enter information for student %d\n", i + 1);
        printf("Enter Roll:");
        scanf("%d", &S[i].roll);
        printf("Enter GPA:");
        scanf("%f", &S[i].GPA);
    }

    for (i = 0; i <= 2; i++)
    {
        printf("Details of student %d\n", i + 1);
        printf("Roll %d GPA: %.2f\n", S[i].roll, S[i].GPA);
    }

    return 0;
}
