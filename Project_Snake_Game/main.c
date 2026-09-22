#include<stdio.h>

#define WIDTH 40
#define HEIGHT 20
#define MAX_SNAKE_LENGTH 100

struct position{
    int x;
    int y;
};

void draw(struct position snake[], int snakelength){
    for(int i=0; i<=HEIGHT; i++){
        for(int j=0; j<=WIDTH; j++){
            if(i==0 || i==HEIGHT || j==0 || j==WIDTH){
                printf("#");
            }
            else{
            int issnake=0;
            for(int k=0; k<snakelength;k++){
                if(snake[k].x==j && snake[k].y==i){
                    issnake=1;
                }
            }
            if(issnake==1){
                printf("@");
            }
            else{
                printf(" ");
            }
            }
                
        }
        printf("\n");
    }
}

int main(){
    struct position snake [MAX_SNAKE_LENGTH];
    int snakelength = 3;
    printf("Snake length= %d\n", snakelength);
    snake[0].x=20;
    snake[0].y=10;

    snake[1].x=19;
    snake[1].y=10;

    snake[2].x=18;
    snake[2].y=10;

    draw(snake,snakelength);
    return 0;


}
