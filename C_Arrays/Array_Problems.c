#include<stdio.h>

// End of array:

void end_array(char *arr){
    char flag = '\0';
    for(int i=0; i<=flag;i++){
        if(arr[i]==flag){
            printf("End of array at index number %d\n", i);
            break;
        }        
    }
    return;
}

// Finding memory of any character:

void memory_1(char *arr){
    char memory;
    printf("Enter the character whose memory you'd like to find out: \n");
    scanf(" %c", &memory);
    for(int i=0; i<'\0';i++){
        if(arr[i]==memory){
            printf("Memory address of %c character is %p\n", memory, &arr[i]);
            return;
        }
    }
}

// Finding memory of any index:

void memory_2(char *arr){
    int n;
    printf("Enter the index whose memory you'd like to find out: \n");
    scanf(" %d",&n);
    for(int i=0; i<'\0';i++){
        if(i==n){
            printf("Memory address of %d index is %p\n", n, &arr[i]);
        }     
    }
    return;
}

int main(){
    char arr[100];
    printf("Enter the name of your college\n");
    scanf(" %[^\n]", arr);
    end_array(arr);
    memory_1(arr);
    memory_2(arr);
    return 0;
}
