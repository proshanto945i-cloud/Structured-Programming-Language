// EXAMPLE 2 

#include<stdio.h>
int main()
{
    int isLoggedIn = 1; // 1 means true and 0 means false
    int isAdmin = 0; 

    printf("regular user: %d\n", isLoggedIn && !isAdmin); 
    printf("admin user: %d\n", isLoggedIn && isAdmin);
    printf("not logged in: %d\n", !isLoggedIn && !isAdmin);
    return 0;
}
