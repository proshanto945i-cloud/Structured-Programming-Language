#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "School.h"


    struct student{
        char name[100];
        int roll;
        float GPA;
    };
    struct school_class{
        int class;
        int student_no;
        struct student *students;
    };
    struct teacher{
        char name[100];
        int age;
        char subject[100];
    };
    struct staff{
        char name[100];
        int age;
        char position[100];
    };
    struct branch{
        char location[100];
    };
    struct school{
        char name[100];
        int class_no;
        int teacher_no;
        int staff_no;
        int branch_no;
        struct school_class *classes;
        struct teacher *teachers;
        struct staff *staffs;
        struct branch *branches;
    };
    void add_school(struct school **sch, int *s);
    void display_schools(struct school *sch, int s);
    void search_school(struct school *sch, int s);
    void free_schools(struct school *sch, int s);

void school(){
    struct school *sch = NULL;
    int s=0;
    int choice;
    do{
        printf("****** ");
        printf("School");
        printf(" ******\n");
        printf("1. Add School\n");
        printf("2. Display Schools\n");
        printf("3. Search School\n");
        printf("0. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d",&choice);
        if(choice==1){
            add_school(&sch, &s);
        }
        else if(choice==2){
            display_schools(sch,s);
        }
        else if(choice==3){
            search_school(sch,s);
        }
        else if(choice==0){
            free_schools(sch,s);
            printf("Exiting....\n");
        }
        else{
            printf("Invalid choice\n");
        }
    } while(choice!=0);
}

    void add_school(struct school **sch, int *s){
    printf("Enter the number of schools: \n");
    scanf("%d", s);
    *sch=malloc(*s*sizeof(struct school));
    for(int i=0; i<*s; i++){
        printf("Enter the name of school %d: \n", i+1);
        scanf(" %[^\n]", (*sch)[i].name);
        printf("Enter the number of classes: \n");
        scanf("%d", &(*sch)[i].class_no);  
        (*sch)[i].classes= malloc((*sch)[i].class_no*sizeof(struct school_class));
        printf("Enter the information of students: \n");
        for(int j=0; j<(*sch)[i].class_no; j++){
            printf("Enter class number: \n");
            scanf("%d", &(*sch)[i].classes[j].class);
            printf("Enter number of students in class %d: \n", j+1);
            scanf(" %d", &(*sch)[i].classes[j].student_no);
            (*sch)[i].classes[j].students = malloc((*sch)[i].classes[j].student_no*sizeof(struct student));
            for(int k=0; k<(*sch)[i].classes[j].student_no; k++){
            printf("Enter name: \n");
            scanf(" %[^\n]", (*sch)[i].classes[j].students[k].name);
            printf("Enter roll: \n");
            scanf("%d", &(*sch)[i].classes[j].students[k].roll);
            printf("Enter GPA: \n");
            scanf("%f", &(*sch)[i].classes[j].students[k].GPA);
            }
        }
        printf("Enter the number of teachers: \n");
        scanf("%d", &(*sch)[i].teacher_no);
        (*sch)[i].teachers = malloc((*sch)[i].teacher_no*sizeof(struct teacher));
        printf("Enter the information of teachers: \n");
        for(int j=0; j<(*sch)[i].teacher_no; j++){
            printf("Enter name: \n");
            scanf(" %[^\n]", (*sch)[i].teachers[j].name);
            printf("Enter age: \n");
            scanf("%d", &(*sch)[i].teachers[j].age);
            printf("Enter subject: \n");
            scanf(" %[^\n]", (*sch)[i].teachers[j].subject);

        }
        printf("Enter the number of staffs: \n");
        scanf("%d", &(*sch)[i].staff_no);
        (*sch)[i].staffs = malloc((*sch)[i].staff_no*sizeof(struct staff));
        printf("Enter the information of staffs: \n");
        for(int j=0; j<(*sch)[i].staff_no; j++){
            printf("Enter name: \n");
            scanf(" %[^\n]", (*sch)[i].staffs[j].name);
            printf("Enter age: \n");
            scanf("%d", &(*sch)[i].staffs[j].age);
            printf("Enter the position of staff: \n");
            scanf(" %[^\n]", (*sch)[i].staffs[j].position);
        }
        printf("Enter the number of branches: \n");
        scanf("%d", &(*sch)[i].branch_no);
        printf("Enter the information of branches: \n");
        (*sch)[i].branches = malloc((*sch)[i].branch_no*sizeof(struct branch));
        for(int j=0; j<(*sch)[i].branch_no; j++){
            printf("Enter location: \n");
            scanf(" %[^\n]", (*sch)[i].branches[j].location);
        }

    }
    }

    
void display_schools(struct school *sch, int s){
    printf("\n");
    printf("****** ");
    printf("School");
    printf(" ******\n");
    printf("\n");
    if(s==0){
        printf("No schools to display\n");
    }
    for(int i=0; i<s; i++){
        printf("%d. %s\n",i+1,sch[i].name);
    }
    printf("\n");    
}  
    

void search_school(struct school *sch,int s){
    printf("\n");
    printf("****** ");
    printf("School");
    printf(" ******\n");
    printf("\n");
    char search_name[100];
    printf("Enter the name of school: \n");
    scanf(" %[^\n]", search_name);
    if(s==0){
        printf("There is no such school\n");
    }
    for(int i=0; i<s; i++){
        if(strcmp(search_name,sch[i].name)==0){
            printf("Name of school= %s\n",sch[i].name);
            printf("Number of class= %d\n",sch[i].class_no);
            printf("Number of teachers= %d\n",sch[i].teacher_no);
            printf("Number of staffs= %d\n",sch[i].staff_no);
            printf("Number of branches= %d\n",sch[i].branch_no);
        }
    }
    printf("\n");
    
}
    
void free_schools(struct school *sch, int s){
    for(int i = 0; i < s; i++) {
        for(int j=0; j<sch[i].class_no; j++){
            free(sch[i].classes[j].students);
        }
        free(sch[i].classes);
        free(sch[i].teachers);
        free(sch[i].staffs);
        free(sch[i].branches);
    }
    free(sch);
}
