#include<stdio.h>
#include<string.h>
#define SIZE 26

int main(){
    int n, x, index=0;
    scanf("%d %d", &n, &x);
    char c[n * SIZE];
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<n; j++){
            c[index] = i + 'A';
            index++;
        }
    }
    printf("%c\n", c[x - 1]);
}