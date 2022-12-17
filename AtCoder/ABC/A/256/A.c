#include<stdio.h>

int n, res=1;

int main(){
    scanf("%d", &n);
    while(n--){
        res *= 2;
    }
    printf("%d\n", res);
}