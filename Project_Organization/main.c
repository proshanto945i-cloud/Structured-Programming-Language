#include<stdio.h>
#include<stdlib.h>

    struct school_class{
        int class;
        int student_no;
        struct student *students;
    };
    struct student{
        char name[100];
        int roll;
        float GPA;
    };
    struct teacher{
        char name[100];
        int age;
        char subject[100];
    };
        struct staff{
        char name[100];
        int age;
        int exp;
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
int main(){
    int s;
    printf("Enter the number of schools: \n");
    scanf("%d", &s);

    struct school sch [s];

    for(int i=0; i<s; i++){
        printf("Enter the name of school %d: \n", i+1);
        scanf(" %[^\n]", sch[i].name);
        printf("Enter the number of classes: \n");
        scanf("%d", &sch[i].class_no);
        printf("Enter the number of teachers: \n");
        scanf("%d", &sch[i].teacher_no);
        printf("Enter the number of staffs: \n");
        scanf("%d", &sch[i].staff_no);
        printf("Enter the number of branches: \n");
        scanf("%d", &sch[i].branch_no); 
        sch[i].classes = malloc(sch[i].class_no*sizeof(struct student));
        sch[i].teachers = malloc(sch[i].teacher_no*sizeof(struct teacher));
        sch[i].staffs = malloc(sch[i].staff_no*sizeof(struct staff));
        sch[i].branches = malloc(sch[i].branch_no*sizeof(struct branch));

        printf("Enter the information of students: \n");
        for(int j=0; j<sch[i].class_no; j++){
            printf("Enter class: \n");
            scanf("%d", &sch[i].classes[j].class);
            printf("Enter number of students in class %d: \n", j+1);
            scanf("%d", &sch[i].classes[j].student_no);
                for(int k=0; k<sch[i].classes[j].student_no; k++){
                    printf("Enter name: \n");
                    scanf(" %[^\n]", sch[i].classes[j].students[k].name);
                    printf("Enter roll: \n");
                    scanf("%d", &sch[i].classes[j].students[k].roll);
                    printf("Enter GPA: \n");
                    scanf("%f", &sch[i].classes[j].students[k].GPA);
                }
        }
        printf("Enter the information of teachers: \n");
        for(int j=0; j<sch[i].teacher_no; j++){
            printf("Enter name: \n");
            scanf(" %[^\n]", sch[i].teachers[j].name);
            printf("Enter age: \n");
            scanf("%d", &sch[i].teachers[j].age);
            printf("Enter subject: \n");
            scanf(" %[^\n]", sch[i].teachers[j].subject);

        }
        printf("Enter the information of staffs: \n");
        for(int j=0; j<sch[i].staff_no; j++){
            printf("Enter name: \n");
            scanf(" %[^\n]", sch[i].staffs[j].name);
            printf("Enter age: \n");
            scanf("%d", &sch[i].staffs[j].age);
            printf("Enter experience: \n");
            scanf("%d", &sch[i].staffs[j].exp);
        }
        printf("Enter the information of branches: \n");
        for(int j=0; j<sch[i].branch_no; j++){
            printf("Enter location: \n");
            scanf(" %[^\n]", sch[i].branches[j].location);
        }

    }
    for(int i = 0; i < s; i++) {
        free(sch[i].classes);
        free(sch[i].teachers);
        free(sch[i].staffs);
        free(sch[i].branches);
    }
    return 0;
}
