// EXAMPLE 1 

#include<stdio.h>
int main()
{
    int time = 16;

    if(time<12)
    {
        printf("good morning");
    }
    else if(time<18)
    {
        printf("good evening");
    }
    else 
    {
        printf("good afternoon");
    }

    return 0;
}
