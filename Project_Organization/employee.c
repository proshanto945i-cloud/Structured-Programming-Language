#include<stdio.h>
#include<string.h>
struct Employee {
    char name[50];
    char Location[50];
    float salary;
    int age;
    char blood_group[10];
};
int main(){
    int num_employees;
    printf("Welcome to RealTech Organisation!\n");
    printf("How many employees' data do you want to input?");
    scanf("%d",&num_employees);
    while(getchar() !='\n');
    struct Employee emplist[num_employees];
    for(int i=0;i<num_employees;i++){
        printf("Enter Details for Employee %d\n",i+1);
        printf("Enter Employee Name: ");
        fgets(emplist[i].name,sizeof(emplist[i].name), stdin);
        emplist[i].name[strcspn(emplist[i].name, "\n")] = '\0';
        printf("Enter Home Location: ");
        fgets(emplist[i].Location,sizeof(emplist[i].Location), stdin);
        emplist[i].Location[strcspn(emplist[i].Location, "\n")] = '\0';
        printf("Enter Salary: ");
        scanf("%.2f",&emplist[i].salary);
        while(getchar() != '\n');
        printf("Enter Age: ");
        scanf("%d",&emplist[i].age);
        while(getchar() != '\n');
        printf("Enter Blood Group: ");
        fgets(emplist[i].blood_group,sizeof(emplist[i].blood_group), stdin);
        emplist[i].blood_group[strcspn(emplist[i].blood_group, "\n")] = '\0';
    }
int searchID;
int found =0;
printf("\n\n");
printf("Enter Employee Id: ");
scanf("%d",&searchID);
for(int i=0;i<num_employees;i++){
if( (i+101)== searchID ){
printf("Employee Found!\n");
printf("Name: %s\n",emplist[i].name);
printf("Location: %s\n",emplist[i].Location);
printf("Salary: %.2f\n",emplist[i].salary);
printf("Age: %d\n",emplist[i].age);
printf("Blood Group: %s\n",emplist[i].blood_group);
found=1;
break;
}
}
if(!found){
printf("Employee with ID %d not found\n",searchID);
}
return 0;
}
