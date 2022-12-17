#include<stdio.h>
#define SIZE 100

int n, cnt=0, a[100];

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);

    for(int i=0; i<n; i++){
        int pos=0;
        for(int j=i; j<n; j++){
            pos += a[j];
            if(pos >= 4){
                cnt++;
                break;
            }
        }
    }
    printf("%d\n", cnt);
}