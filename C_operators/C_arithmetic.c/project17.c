// EXAMPLE 3 : real life case

#include<stdio.h>
int main()
{
    int peopleInRoom = 0;

    // 3 people enter the room

    peopleInRoom++ ;
    peopleInRoom++ ;
    peopleInRoom++ ;

    // 1 person leaves the room

    peopleInRoom -- ; 

    printf("The number of people in the room is: %d\n", peopleInRoom); // prints 2
    return 0;
}
