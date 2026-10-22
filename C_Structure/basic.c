#include<stdio.h>
int main(){
    struct student
    {
        int roll;
        char nam[10];
        float GPA;
    };

    struct student S1 = {1,"Rahim",3.5};
    struct student S2 = {2,"Karim",4.0};
   
    printf("%d\n",S1.roll);
    printf("%s",S1.nam);
    return 0;
    
}
