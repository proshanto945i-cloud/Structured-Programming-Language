#include<stdio.h>
#include "school.h"
#include "university.h"

int main(){
    int choice;
    printf("*********************** ");
    printf("Bangladesh Institutions");
    printf(" **********************\n");
    printf("1. School\n");
    printf("2. University\n");
    printf("0. Exit\n");
    printf("Enter your choice: \n");
    scanf("%d",&choice);
    if(choice==1){
        school();
    }
    else if(choice==2){
        university();
    }
    else if(choice==0){
        printf("Exiting....\n");
    }
    else{
        printf("Invalid choice\n");
    }
    return 0;
}
