// EXAMPLE 2 

#include<stdio.h>
#include<stdbool.h>
int main ()
{
    int time = 16;
    bool isTime_1 = time < 10;
    bool isTime_2 = time < 16;

    if(isTime_1)
    {
        printf("good morning");
    }
    else if(isTime_2)
    {
        printf("good evening");
    }
    else 
    {
        printf("good afternoon");
    }

    return 0;
}

// prints good afternoon
