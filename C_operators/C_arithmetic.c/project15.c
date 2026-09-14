// EXAMPLE 1 : All arithmetic operators in C

#include<stdio.h>
int main()
{
    int x=10;
    int y = 3; 

    printf("%d\n",x+y); // addition operator 13
    printf("%d\n",x-y); // subtraction operator 7
    printf("%d\n",x*y); // multiplication operator 30
    printf("%d\n",x/y); // division operator 3
    printf("%d\n",x%y); // modulo operator 1

    int z=6;
    ++z; // increment operator 7
    printf("%d\n",z);
    --z; // decrement operator 6
    printf("%d\n",z);
    return 0;
}
