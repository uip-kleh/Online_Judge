#include<stdio.h>
#define SIZE 26

int main(){
    int cnt[SIZE];
    for(int i=0; i<SIZE; i++) cnt[i] = 0;
    char s[3];
    scanf("%s", s);
    for(int i=0; i<3; i++){
        int index = s[i] - 'a';
        cnt[index]++;
    }
    char ans='\0';
    for(int i=0; i<SIZE; i++){
        if(cnt[i] == 1){
            ans = i + 'a';
            break;
        }
    }
    if(ans == '\0') printf("%d\n", -1);
    else printf("%c\n", ans);

    return 0;
}