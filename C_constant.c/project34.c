// EXAMPLE 2 

#include<stdio.h>
int main()
{
    const int minutesPerHour ; // const int minutesPerHour = 60; 

    minutesPerHour = 60; // error , when we declare a variable as const it must be initialized at the time of declaration


    printf("The value of minutesPerHour is %d\n",minutesPerHour);
    return 0;
}
