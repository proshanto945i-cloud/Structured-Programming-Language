#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "University.h"

struct student{
    char name[100];
    int roll;
    float GPA;
};
struct teacher{
    char name[100];
    int age;
    char designation[100];
};
struct staff{
    char name[100];
    int age;
    char position[100];
};
struct club{
    char name[100];
    char start_date[50];
    int student_no;
};
struct department{
    char name[100];
    char department_head[100];
    int student_no;
    int teacher_no;
    struct student *students;
    struct teacher *teachers;
};
struct university{
    char name[100];
    char address[100];
    int department_no;
    int staff_no;
    int club_no;
    char affiliated_college[100];
    
    struct department *departments;
    struct club *clubs;
    struct staff *staffs;
};

void add_uni(struct university **uni, int *u);
void display_unis(struct university *uni, int u);
void search_uni(struct university *uni,int u);
void free_unis(struct university *uni, int u);


void university(){
    int u=0;
    struct university *uni = NULL;
    int choice;
    do{
        printf("****** ");
        printf("University");
        printf(" ******\n");
        printf("1. Add University\n");
        printf("2. Display Universities\n");
        printf("3. Search University\n");
        printf("0. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d",&choice);
        if(choice==1){
            add_uni(&uni, &u);
        }
        else if(choice==2){
            display_unis(uni,u);
        }
        else if(choice==3){
            search_uni(uni,u);
        }
        else if(choice==0){
            free_unis(uni,u);
            printf("Exiting....\n");
        }
        else{
            printf("Invalid choice\n");
        }
    } while(choice!=0);

}

void add_uni(struct university **uni, int *u){
    
    printf("Enter the number of universities: \n");
    scanf("%d", u);
    *uni=malloc(*u*sizeof(struct university));
    for(int i=0; i<*u; i++){
        printf("Enter the information of university %d: \n", i+1);
        printf("Enter name: \n");
        scanf(" %[^\n]", (*uni)[i].name);
        printf("Enter address: \n");
        scanf(" %[^\n]", (*uni)[i].address);
        printf("Enter the number of departments: \n");
        scanf("%d", &(*uni)[i].department_no);

        (*uni)[i].departments = malloc((*uni)[i].department_no * sizeof(struct department));
        
        for(int j=0; j<(*uni)[i].department_no; j++){
            printf("Enter department name: \n");
            scanf(" %[^\n]",(*uni)[i].departments[j].name);
            printf("Enter the name of department head of %s: \n", (*uni)[i].departments[j].name);
            scanf(" %[^\n]",(*uni)[i].departments[j].department_head);
            printf("Enter the number of students in %s: \n", (*uni)[i].departments[j].name);
            scanf("%d", &(*uni)[i].departments[j].student_no);
            (*uni)[i].departments[j].students = malloc((*uni)[i].departments[j].student_no * sizeof(struct student));
            for(int k=0; k < (*uni)[i].departments[j].student_no; k++){
                printf("Enter the name of student: \n");
                scanf(" %[^\n]", (*uni)[i].departments[j].students[k].name);
                printf("Enter the roll of student: \n");
                scanf("%d", &(*uni)[i].departments[j].students[k].roll);
                printf("Enter the GPA of student: \n");
                scanf("%f", &(*uni)[i].departments[j].students[k].GPA);
            }
            printf("Enter the number of teachers: \n");
            scanf("%d", &(*uni)[i].departments[j].teacher_no);
            (*uni)[i].departments[j].teachers = malloc((*uni)[i].departments[j].teacher_no * sizeof(struct teacher));
            for(int k=0; k < (*uni)[i].departments[j].teacher_no; k++){
                printf("Enter the name of teacher: \n");
                scanf(" %[^\n]", (*uni)[i].departments[j].teachers[k].name);
                printf("Enter the age of teacher: \n");
                scanf("%d", &(*uni)[i].departments[j].teachers[k].age);
                printf("Enter the designation of teacher: \n");
                scanf(" %[^\n]", (*uni)[i].departments[j].teachers[k].designation);
            }
        }
        printf("Enter the number of staffs: \n");
        scanf("%d", &(*uni)[i].staff_no);
        (*uni)[i].staffs = malloc((*uni)[i].staff_no * sizeof(struct staff));
        for(int j=0; j<(*uni)[i].staff_no; j++){
            printf("Enter the name of staff: \n");
            scanf(" %[^\n]", (*uni)[i].staffs[j].name);
            printf("Enter the age of staff: \n");
            scanf("%d", &(*uni)[i].staffs[j].age);
            printf("Enter the position of staff: \n");
            scanf(" %[^\n]", (*uni)[i].staffs[j].position);
        }
        printf("Enter the number of clubs: \n");
        scanf("%d", &(*uni)[i].club_no);
        (*uni)[i].clubs = malloc((*uni)[i].club_no * sizeof(struct club));

        for(int j=0; j<(*uni)[i].club_no; j++){
            printf("Enter the name of club: \n");
            scanf(" %[^\n]", (*uni)[i].clubs[j].name);
            printf("Enter the establishment date of club %s: \n");
            scanf("%s", (*uni)[i].clubs[j].start_date);
            printf("Enter the number of students: \n");
            scanf("%d", &(*uni)[i].clubs[j].student_no);
        }
        printf("Enter the name of affiliated college: \n");
        scanf(" %[^\n]", (*uni)[i].affiliated_college);
    }
}


void display_unis(struct university *uni, int u){
    printf("\n");
    printf("****** ");
    printf("University");
    printf(" ******\n");
    printf("\n");
    if(u==0){
        printf("No universities to display\n");
    }
    for(int i=0; i<u; i++){
        printf("%d. %s\n",i+1,uni[i].name);
    }
    printf("\n");
    
}  
    

void search_uni(struct university *uni,int u){
    printf("\n");
    printf("****** ");
    printf("University");
    printf(" ******\n");
    printf("\n");
    char search_name[100];
    printf("Enter the name of university: \n");
    scanf(" %[^\n]", search_name);
    if(u==0){
        printf("There is no such university\n");
    }
    
    for(int i=0; i<u; i++){
        if(strcmp(search_name,uni[i].name)==0){
            printf("Name of university= %s\n",uni[i].name);
            printf("Address of university= %s\n",uni[i].address);
            printf("Number of departments= %d\n",uni[i].department_no);
            printf("Number of staffs= %d\n",uni[i].staff_no);
            printf("Number of clubs= %d\n",uni[i].club_no);
            printf("Name of affiliated college= %s\n",uni[i].affiliated_college);
        }
    }
    printf("\n");
}

void free_unis(struct university *uni, int u){
    for(int i=0; i<u; i++){
        for(int j=0; j<uni[i].department_no; j++){
            free(uni[i].departments[j].students);
            free(uni[i].departments[j].teachers);
        }
        free(uni[i].departments);
        free(uni[i].clubs);
        free(uni[i].staffs);
    }
    free(uni);
}
