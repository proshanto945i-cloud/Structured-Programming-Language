/* EXAMPLE 1 : Logical operators

&& (AND) - all condition must be true
|| (OR) - atleast one condition must be true
! (NOT) - reserves a condition  */

#include<stdio.h>
int main()
{
    int a = 200;
    int b = 50;
    int c = 100;

    if(a>b && a>c)
    {
        printf("a is greater");
    }
    else if (a>b || a>c)
    {
        printf("a is either greater than b or c");
    }
    else if (!(b>a))
    {
        printf("b is not greater than a");
    }
    else 
    {
        printf("a is not greater");
    }
    return 0;
}
