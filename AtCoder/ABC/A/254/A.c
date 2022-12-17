#include<stdio.h>

int n;

int main(){
    scanf("%d", &n);
    n %= 100;
    if(n < 10) printf("0%d\n", n);
    else printf("%d\n", n);
}