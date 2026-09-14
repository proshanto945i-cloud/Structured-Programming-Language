// EXAMPLE 1 

#include<stdio.h>
int main ()
{
    int year;
    printf("Enter your year :");
    scanf("%d", &year);

    if(year % 4 ==0)
    {
        if(year % 100 != 0)
        {
            printf("this is a leap year");
        }
        else
        {
            printf("this is not a leap year");
        }
        if(year % 400 == 0)
        {
            printf("this is a leap year");
        }
       
    }
    else 
    {
        printf("this is not a leap year");
    }

    return 0;
}
