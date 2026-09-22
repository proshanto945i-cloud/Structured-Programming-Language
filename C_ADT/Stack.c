#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    return 0;
}
int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;        
    }
    return 0;
}

void push(struct stack *ptr, int value){
    if(isFull(ptr)){
        printf("Stack Overflow\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}
int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow\n");
        return -1;
    }
    else{
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}
int main(){
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->size=4;
    s->top=-1;
    s->arr = (int*)malloc(s->size*sizeof(int));
    printf("Before pushing, Full: %d\n", isFull(s));
    printf("Before pushing, Empty: %d\n", isEmpty(s));
    push(s,4);
    push(s,3);
    push(s,2);
    push(s,1);
    // checking overflow;
    push(s,0);
    printf("After pushing, Full: %d\n", isFull(s));
    printf("After pushing, Empty: %d\n", isEmpty(s));
    printf("Popped value is : %d\n",pop(s));
    printf("Popped value is : %d\n",pop(s));
    printf("Popped value is : %d\n",pop(s));
    printf("Popped value is : %d\n",pop(s));
    return 0;
}
