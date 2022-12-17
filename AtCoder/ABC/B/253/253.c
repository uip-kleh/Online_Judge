#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

int h, w, pos[2][2];

int main(){
    scanf("%d %d", &h, &w);
    int index=0;
    for(int j=0; j<h; j++){
        char str[SIZE];
        scanf("%s", str);
        for(int i=0; i<w; i++){
            if(str[i] == 'o'){
                pos[index][0] = i;
                pos[index][1] = j;
                index++;
            }
        }
    }
    int len=0;
    for(int i=0; i<2; i++){
        len += abs(pos[0][i] - pos[1][i]);
    }
    printf("%d\n", len);

    return 0;
}