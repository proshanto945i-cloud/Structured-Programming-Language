// EXAMPLE 1 

#include<stdio.h>
int main()
{
    const int myNum=5; // myNum will always be 5

    myNum = 10; // error: assignment of read-only variable 'myNum'
    return 0;
}
