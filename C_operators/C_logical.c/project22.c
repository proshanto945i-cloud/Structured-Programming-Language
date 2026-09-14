// EXAMPLE : all logical operators in C

#include<stdio.h> 
int main()
{
    int x=10;
    int y=5;

    printf("%d\n",x>y && x!=y); // logical AND operator 1
    printf("%d\n",x>y || x==y); // logical OR operator 1
    printf("%d\n",!(x>y)); // logical NOT operator 0

    return 0;
}
