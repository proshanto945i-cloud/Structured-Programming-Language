// EXAMPLE 6 

#include<stdio.h>
#include<stdbool.h>
int main()
{
    int x=10;
    int y=20;

    bool isGreater = x>y;

    printf("The result is: %d\n", isGreater); // prints 0 because 10 is not greater than 20
    return 0;
}
