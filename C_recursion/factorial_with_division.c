#include<stdio.h>
int fac(int y){
    if(y==1||y==0){
        return 1;
    }
    else{
        return y*fac(y-1);
    }
}
int fact(int x){
if(x==1){
      return 1;
    }
    else{
        return (fac(x)/x)+fact(x-1);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",fact(n));

}
